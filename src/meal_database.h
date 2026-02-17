#pragma once

#include "types.h"

#include <QVector>

namespace mealplan {

/// @brief In-memory database of all 43 hardcoded meals.
///
/// All meals are constructed once in the constructor and never modified
/// afterwards. The database is therefore immutable after construction and
/// safe to share across read-only consumers without synchronization.
class MealDatabase {
public:
    /// @brief Construct the database and populate all 43 meals internally.
    MealDatabase();

    /// @brief Return a const reference to the full list of meals.
    /// @return A reference to the internal QVector containing all meals.
    const QVector<Meal>& all_meals() const;

    /// @brief Look up a single meal by its unique identifier.
    /// @param id The meal ID to search for (expected range: 1-43).
    /// @return A pointer to the matching Meal, or nullptr if not found.
    const Meal* meal_by_id(int id) const;

    /// @brief Return pointers to all meals whose category is in the given set.
    /// @param categories A vector of MealCategory values to filter by.
    /// @return A vector of non-owning pointers into the internal meal storage.
    QVector<const Meal*> meals_in_categories(const QVector<MealCategory>& categories) const;

private:
    QVector<Meal> m_meals;  ///< Storage for all 43 meals
};

} // namespace mealplan
