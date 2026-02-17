#pragma once

#include "types.h"

#include <QVector>

namespace mealplan {

// Forward declarations
class MealDatabase;
class HistoryManager;

/// @brief Selects meals for the week from user-chosen categories.
///
/// Builds a filtered pool from the allowed categories, excludes recently
/// used meals via HistoryManager, then shuffles and picks `count` meals.
/// Uses QRandomGenerator::global() for randomness.
class MealSelector {
public:
    MealSelector(const MealDatabase& database, HistoryManager& history);

    /// @brief Select `count` meals from the given categories.
    /// @param count              Number of meals to select (1–7).
    /// @param allowed_categories Which dietary categories to draw from.
    /// @return Non-owning pointers to meals in the database.
    QVector<const Meal*> select_weekly_meals(
        int count,
        const QVector<MealCategory>& allowed_categories);

private:
    const MealDatabase& m_database;
    HistoryManager&     m_history;
};

} // namespace mealplan
