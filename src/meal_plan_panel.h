#pragma once

#include "types.h"

#include <QFrame>

class QLabel;
class QVBoxLayout;

namespace mealplan {

/// @brief A compact panel displaying a single meal's summary information.
///
/// Shows the meal name, dietary category badge, cuisine, cooking method,
/// and protein content per serving. Used inside the left-side meal list
/// of the main window.
class MealPlanPanel : public QFrame {
    Q_OBJECT

public:
    /// @brief Construct a meal plan panel for the given meal.
    /// @param meal The meal whose summary information to display.
    /// @param parent Optional parent widget (ownership is transferred to parent).
    explicit MealPlanPanel(const Meal& meal, QWidget* parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    /// @brief Set up the internal layout and populate labels from the meal data.
    /// @param meal The meal to display.
    void setup_ui(const Meal& meal);
};

} // namespace mealplan
