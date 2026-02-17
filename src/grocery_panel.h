#pragma once

#include "types.h"

#include <QWidget>
#include <QMap>
#include <QVector>

class QVBoxLayout;
class QTreeWidget;

namespace mealplan {

/// @brief A panel displaying the consolidated grocery list grouped by store aisle.
///
/// Each aisle category is shown as a collapsible section header, with
/// individual grocery items listed beneath showing their aggregated
/// quantities and units.
class GroceryPanel : public QWidget {
    Q_OBJECT

public:
    /// @brief Construct a grocery panel from pre-aggregated grocery data.
    /// @param groceries A map from aisle category to the list of grocery items in that aisle.
    /// @param parent Optional parent widget (ownership is transferred to parent).
    explicit GroceryPanel(const QMap<AisleCategory, QVector<GroceryItem>>& groceries,
                          QWidget* parent = nullptr);

private:
    /// @brief Set up the internal layout and populate the grocery tree.
    /// @param groceries The aggregated grocery data to display.
    void setup_ui(const QMap<AisleCategory, QVector<GroceryItem>>& groceries);
};

} // namespace mealplan
