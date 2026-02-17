#include "history_manager.h"

#include "types.h"

#include <QSettings>
#include <QVariantList>

namespace mealplan {

namespace {

const QString SETTINGS_KEY = QStringLiteral("history/recent_ids");

QSettings app_settings()
{
    return QSettings(QStringLiteral("MealPlanApp"),
                     QStringLiteral("MealPlanner"));
}

}  // anonymous namespace

HistoryManager::HistoryManager()
{
    // QSettings handles persistence; nothing to initialize here.
}

QSet<int> HistoryManager::recent_ids() const
{
    QSettings settings = app_settings();
    QVariantList stored = settings.value(SETTINGS_KEY).toList();
    QSet<int> ids;
    for (const QVariant& v : stored) {
        bool ok = false;
        int id = v.toInt(&ok);
        if (ok && id >= 1 && id <= TOTAL_MEALS) {
            ids.insert(id);
        }
    }
    return ids;
}

void HistoryManager::record(const QVector<int>& meal_ids)
{
    QSettings settings = app_settings();
    QVariantList stored = settings.value(SETTINGS_KEY).toList();

    // Prepend new IDs to the front of the list
    QVariantList updated;
    for (int id : meal_ids) {
        updated.append(id);
    }
    for (const QVariant& v : stored) {
        updated.append(v);
    }

    // Trim to MAX_HISTORY_SIZE
    while (updated.size() > MAX_HISTORY_SIZE) {
        updated.removeLast();
    }

    settings.setValue(SETTINGS_KEY, updated);
}

void HistoryManager::clear()
{
    QSettings settings = app_settings();
    settings.remove(SETTINGS_KEY);
}

}  // namespace mealplan
