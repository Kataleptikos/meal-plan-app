#include "meal_selector.h"

#include "history_manager.h"
#include "meal_database.h"

#include <QRandomGenerator>

namespace mealplan {

MealSelector::MealSelector(const MealDatabase& database,
                           HistoryManager& history)
    : m_database(database)
    , m_history(history)
{
}

QVector<const Meal*> MealSelector::select_weekly_meals(
    int count,
    const QVector<MealCategory>& allowed_categories)
{
    QSet<int> excluded = m_history.recent_ids();

    // Build one pool from the allowed categories
    QVector<const Meal*> pool = m_database.meals_in_categories(allowed_categories);

    // Remove excluded meals
    pool.erase(
        std::remove_if(pool.begin(), pool.end(),
                       [&excluded](const Meal* m) {
                           return excluded.contains(m->id);
                       }),
        pool.end());

    // If pool too small, clear history and retry
    if (pool.size() < count) {
        m_history.clear();
        return select_weekly_meals(count, allowed_categories);
    }

    // Fisher-Yates shuffle
    auto* rng = QRandomGenerator::global();
    for (int i = pool.size() - 1; i > 0; --i) {
        int j = rng->bounded(i + 1);
        pool.swapItemsAt(i, j);
    }

    // Take first `count` meals
    QVector<const Meal*> selected = pool.mid(0, count);

    // Record selected IDs in history
    QVector<int> selected_ids;
    selected_ids.reserve(count);
    for (const Meal* m : selected) {
        selected_ids.append(m->id);
    }
    m_history.record(selected_ids);

    return selected;
}

}  // namespace mealplan
