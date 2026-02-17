#include "grocery_aggregator.h"

#include <QPair>
#include <algorithm>

namespace mealplan {

QMap<AisleCategory, QVector<GroceryItem>> GroceryAggregator::aggregate(
    const QVector<const Meal*>& meals)
{
    // Key: (normalized_name, normalized_unit) -> (summed_quantity, aisle)
    struct AggEntry {
        double quantity = 0.0;
        AisleCategory aisle = AisleCategory::Other;
    };

    QMap<QPair<QString, QString>, AggEntry> merged;

    for (const Meal* meal : meals) {
        if (!meal) {
            continue;
        }
        for (const Ingredient& ing : meal->ingredients) {
            QString norm_name = ing.name.toLower().trimmed();
            QString norm_unit = ing.unit.toLower().trimmed();
            auto key = qMakePair(norm_name, norm_unit);

            auto it = merged.find(key);
            if (it != merged.end()) {
                it->quantity += ing.quantity;
            } else {
                AggEntry entry;
                entry.quantity = ing.quantity;
                entry.aisle = ing.aisle;
                merged.insert(key, entry);
            }
        }
    }

    // Group by aisle category
    QMap<AisleCategory, QVector<GroceryItem>> result;

    for (auto it = merged.constBegin(); it != merged.constEnd(); ++it) {
        GroceryItem item;
        item.name = it.key().first;
        item.quantity = it.value().quantity;
        item.unit = it.key().second;
        result[it.value().aisle].append(item);
    }

    // Sort items alphabetically within each aisle group
    for (auto it = result.begin(); it != result.end(); ++it) {
        std::sort(it.value().begin(), it.value().end(),
                  [](const GroceryItem& a, const GroceryItem& b) {
                      return a.name < b.name;
                  });
    }

    return result;
}

}  // namespace mealplan
