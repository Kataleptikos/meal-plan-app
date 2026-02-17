#pragma once

#include "types.h"

#include <QMap>
#include <QVector>

namespace mealplan {

/// @brief Aggregates ingredients from multiple meals into a consolidated grocery list.
///
/// This is a stateless utility class with only static methods. It merges
/// duplicate ingredients across meals by normalizing names (lowercase,
/// trimmed) and summing quantities for matching units.
class GroceryAggregator {
public:
    GroceryAggregator() = delete;  // Prevent instantiation

    /// @brief Aggregate ingredients from the given meals into a grocery list grouped by aisle.
    ///
    /// Ingredients with the same normalized name and unit are merged by
    /// summing their quantities. The result is organized as a map from
    /// aisle category to a sorted vector of grocery items.
    ///
    /// @param meals A vector of non-owning pointers to the meals to aggregate.
    /// @return A map from AisleCategory to a vector of consolidated GroceryItems.
    static QMap<AisleCategory, QVector<GroceryItem>> aggregate(const QVector<const Meal*>& meals);
};

} // namespace mealplan
