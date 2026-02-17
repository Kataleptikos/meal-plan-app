#pragma once

#include "types.h"

#include <QWidget>

class QLabel;
class QListWidget;
class QVBoxLayout;

namespace mealplan {

/// @brief A detailed panel displaying a single meal's full recipe.
///
/// Shows the meal name, metadata (cuisine, cooking method, protein content),
/// a list of ingredients with quantities, and numbered step-by-step
/// cooking instructions.
class RecipePanel : public QWidget {
    Q_OBJECT

public:
    /// @brief Construct a recipe panel for the given meal.
    /// @param meal The meal whose full recipe to display.
    /// @param parent Optional parent widget (ownership is transferred to parent).
    explicit RecipePanel(const Meal& meal, QWidget* parent = nullptr);

private:
    /// @brief Set up the internal layout and populate all recipe details.
    /// @param meal The meal to display.
    void setup_ui(const Meal& meal);
};

} // namespace mealplan
