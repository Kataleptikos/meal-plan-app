#pragma once

#include "meal_database.h"
#include "history_manager.h"
#include "meal_selector.h"
#include "types.h"

#include <QMainWindow>
#include <QVector>

class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;
class QPushButton;
class QLabel;
class QSplitter;
class QTabWidget;
class QSpinBox;
class QCheckBox;

namespace mealplan {

// Forward declarations for UI panels
class MealPlanPanel;
class RecipePanel;
class GroceryPanel;

/// @brief Main application window for the Weekly Meal Plan Generator.
///
/// Owns the data layer objects (MealDatabase, HistoryManager, MealSelector)
/// by value and creates the three UI panels as child widgets. Coordinates
/// generation requests, recipe display, and grocery list updates.
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /// @brief Construct the main window and initialize all components.
    /// @param parent Optional parent widget (typically nullptr for top-level windows).
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    /// @brief Handle the "Generate New Week" button click.
    ///
    /// Triggers meal selection, updates all panels with the new plan,
    /// records the selected meal IDs in history, and displays the first
    /// meal's recipe in the recipe panel.
    void on_generate_clicked();

private:
    /// @brief Create and lay out all child widgets and connect signals/slots.
    void setup_ui();

    /// @brief Remove and delete all dynamically created plan widgets from a previous generation.
    void clear_previous_plan();

    // --- Data layer (owned by value, construction order matters) ---
    MealDatabase  m_database;   ///< All 43 meals
    HistoryManager m_history;   ///< Recent meal ID persistence
    MealSelector  m_selector;   ///< Constrained random meal picker

    // --- UI widget pointers (owned by Qt parent-child tree) ---
    QScrollArea*  m_scroll_area    = nullptr;  ///< Scrollable container for the left panel
    QPushButton*  m_generate_btn   = nullptr;  ///< "Generate New Week" button
    QLabel*       m_title_label    = nullptr;  ///< Application title label
    QSplitter*    m_main_splitter  = nullptr;  ///< Horizontal splitter for left/right panes
    QTabWidget*   m_right_tabs     = nullptr;  ///< Tab widget for recipe and grocery panels
    QVBoxLayout*  m_meal_list_layout = nullptr; ///< Layout holding the meal plan cards

    // --- Options widgets ---
    QSpinBox*   m_meal_count_spin   = nullptr;
    QCheckBox*  m_check_meat        = nullptr;
    QCheckBox*  m_check_pescatarian = nullptr;
    QCheckBox*  m_check_vegetarian  = nullptr;
    QCheckBox*  m_check_vegan       = nullptr;

    // --- Dynamically managed widgets from the current plan ---
    QVector<QWidget*> m_current_widgets;  ///< Widgets to delete on next generation
};

} // namespace mealplan
