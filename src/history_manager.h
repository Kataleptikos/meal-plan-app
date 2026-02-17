#pragma once

#include <QSet>
#include <QVector>

namespace mealplan {

/// @brief Manages the history of recently generated meal IDs using QSettings.
///
/// Persists the last 9 meal IDs (3 weeks of 3 meals each) in
/// ~/.config/mealplan/ as an INI file. This history is used by MealSelector
/// to avoid repeating meals across consecutive weeks.
class HistoryManager {
public:
    /// @brief Construct the history manager and initialize QSettings.
    HistoryManager();

    /// @brief Retrieve the set of recently used meal IDs.
    ///
    /// Reads from QSettings and returns up to 9 IDs covering the
    /// last 3 generated weeks. Invalid or out-of-range entries are
    /// silently discarded.
    ///
    /// @return A set of meal IDs that were recently generated.
    QSet<int> recent_ids() const;

    /// @brief Record a new batch of meal IDs into the history.
    ///
    /// Prepends the given IDs to the stored history and trims the
    /// list to keep only the most recent MAX_HISTORY_SIZE entries.
    /// Writes to disk immediately via QSettings.
    ///
    /// @param meal_ids The meal IDs to record (typically 3 per week).
    void record(const QVector<int>& meal_ids);

    /// @brief Clear all stored history.
    ///
    /// Removes the history key from QSettings so the next generation
    /// will have no exclusion constraints.
    void clear();
};

} // namespace mealplan
