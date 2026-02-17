#include "main_window.h"

#include "grocery_aggregator.h"
#include "grocery_panel.h"
#include "meal_plan_panel.h"
#include "recipe_panel.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QSplitter>
#include <QTabWidget>
#include <QVBoxLayout>

namespace mealplan {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_selector(m_database, m_history)
{
    setup_ui();
}

void MainWindow::setup_ui()
{
    // Create the main horizontal splitter
    m_main_splitter = new QSplitter(Qt::Horizontal, this);
    setCentralWidget(m_main_splitter);

    // --- LEFT PANE: Scroll area with generate button and meal cards ---
    auto* left_container = new QWidget(m_main_splitter);
    auto* left_layout = new QVBoxLayout(left_container);
    left_layout->setContentsMargins(10, 10, 10, 10);

    // Title label
    m_title_label = new QLabel("Weekly Meal Plan", left_container);
    m_title_label->setStyleSheet(
        "font-size: 20px; font-weight: bold; color: palette(text); "
        "margin-bottom: 8px;");
    m_title_label->setAlignment(Qt::AlignCenter);
    left_layout->addWidget(m_title_label);

    // Generate button
    m_generate_btn = new QPushButton("Generate New Week", left_container);
    m_generate_btn->setStyleSheet(
        "QPushButton {"
        "  background-color: #2d7d46;"
        "  color: white;"
        "  font-size: 14px;"
        "  padding: 10px 20px;"
        "  border-radius: 6px;"
        "  border: none;"
        "}"
        "QPushButton:hover {"
        "  background-color: #236b38;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #1a5a2d;"
        "}");
    m_generate_btn->setCursor(Qt::PointingHandCursor);
    left_layout->addWidget(m_generate_btn);

    // --- Options group: meal count + diet checkboxes ---
    auto* options_layout = new QVBoxLayout;
    options_layout->setSpacing(4);
    options_layout->setContentsMargins(0, 6, 0, 6);

    // Top row: "Meals per week:" label + spin box
    auto* count_row = new QHBoxLayout;
    auto* count_label = new QLabel("Meals per week:", left_container);
    count_label->setStyleSheet("font-size: 12px; color: palette(link);");
    count_row->addWidget(count_label);

    m_meal_count_spin = new QSpinBox(left_container);
    m_meal_count_spin->setRange(1, 7);
    m_meal_count_spin->setValue(3);
    m_meal_count_spin->setFixedWidth(60);
    m_meal_count_spin->setStyleSheet("font-size: 12px;");
    count_row->addWidget(m_meal_count_spin);
    count_row->addStretch();
    options_layout->addLayout(count_row);

    // Bottom row: diet checkboxes
    auto* diet_row = new QHBoxLayout;
    auto* diet_label = new QLabel("Include diets:", left_container);
    diet_label->setStyleSheet("font-size: 12px; color: palette(link);");
    diet_row->addWidget(diet_label);

    const QString cb_style = "font-size: 12px; color: palette(text);";
    m_check_meat = new QCheckBox("Meat", left_container);
    m_check_meat->setChecked(true);
    m_check_meat->setStyleSheet(cb_style);
    diet_row->addWidget(m_check_meat);

    m_check_pescatarian = new QCheckBox("Pescatarian", left_container);
    m_check_pescatarian->setChecked(true);
    m_check_pescatarian->setStyleSheet(cb_style);
    diet_row->addWidget(m_check_pescatarian);

    m_check_vegetarian = new QCheckBox("Vegetarian", left_container);
    m_check_vegetarian->setChecked(true);
    m_check_vegetarian->setStyleSheet(cb_style);
    diet_row->addWidget(m_check_vegetarian);

    m_check_vegan = new QCheckBox("Vegan", left_container);
    m_check_vegan->setChecked(true);
    m_check_vegan->setStyleSheet(cb_style);
    diet_row->addWidget(m_check_vegan);

    diet_row->addStretch();
    options_layout->addLayout(diet_row);

    left_layout->addLayout(options_layout);

    // Scroll area for meal cards
    m_scroll_area = new QScrollArea(left_container);
    m_scroll_area->setWidgetResizable(true);
    m_scroll_area->setFrameShape(QFrame::NoFrame);

    auto* scroll_content = new QWidget(m_scroll_area);
    m_meal_list_layout = new QVBoxLayout(scroll_content);
    m_meal_list_layout->setAlignment(Qt::AlignTop);
    m_meal_list_layout->setSpacing(8);
    m_scroll_area->setWidget(scroll_content);

    left_layout->addWidget(m_scroll_area);

    m_main_splitter->addWidget(left_container);

    // --- RIGHT PANE: Tab widget for recipe and grocery panels ---
    m_right_tabs = new QTabWidget(m_main_splitter);
    m_main_splitter->addWidget(m_right_tabs);

    // Set initial splitter sizes (left:right = 1:2)
    m_main_splitter->setSizes({350, 750});

    // Connect signals
    connect(m_generate_btn, &QPushButton::clicked,
            this, &MainWindow::on_generate_clicked);
}

void MainWindow::on_generate_clicked()
{
    clear_previous_plan();

    int count = m_meal_count_spin->value();
    QVector<MealCategory> cats;
    if (m_check_meat->isChecked())        cats.append(MealCategory::Meat);
    if (m_check_pescatarian->isChecked()) cats.append(MealCategory::Pescatarian);
    if (m_check_vegetarian->isChecked())  cats.append(MealCategory::Vegetarian);
    if (m_check_vegan->isChecked())       cats.append(MealCategory::Vegan);

    if (cats.isEmpty()) {
        m_check_meat->setChecked(true);
        m_check_pescatarian->setChecked(true);
        m_check_vegetarian->setChecked(true);
        m_check_vegan->setChecked(true);
        cats = {MealCategory::Meat, MealCategory::Pescatarian,
                MealCategory::Vegetarian, MealCategory::Vegan};
    }

    QVector<const Meal*> meals = m_selector.select_weekly_meals(count, cats);

    // Create meal plan panels on the left
    for (int i = 0; i < meals.size(); ++i) {
        auto* panel = new MealPlanPanel(*meals[i]);
        m_meal_list_layout->addWidget(panel);
        m_current_widgets.append(panel);

        // Connect click to switch to corresponding recipe tab
        const int tab_index = i;
        panel->setCursor(Qt::PointingHandCursor);
        connect(panel, &MealPlanPanel::clicked, this,
                [this, tab_index]() {
                    if (tab_index < m_right_tabs->count()) {
                        m_right_tabs->setCurrentIndex(tab_index);
                    }
                });
    }

    // Create recipe tabs on the right
    for (int i = 0; i < meals.size(); ++i) {
        auto* recipe = new RecipePanel(*meals[i]);
        auto* recipe_scroll = new QScrollArea;
        recipe_scroll->setWidgetResizable(true);
        recipe_scroll->setWidget(recipe);
        recipe_scroll->setFrameShape(QFrame::NoFrame);
        m_right_tabs->addTab(recipe_scroll, meals[i]->name);
        m_current_widgets.append(recipe_scroll);
    }

    // Create grocery list tab
    auto grocery_data = GroceryAggregator::aggregate(meals);
    auto* grocery = new GroceryPanel(grocery_data);
    auto* grocery_scroll = new QScrollArea;
    grocery_scroll->setWidgetResizable(true);
    grocery_scroll->setWidget(grocery);
    grocery_scroll->setFrameShape(QFrame::NoFrame);
    m_right_tabs->addTab(grocery_scroll, "Grocery List");
    m_current_widgets.append(grocery_scroll);

    // Show the first recipe tab by default
    m_right_tabs->setCurrentIndex(0);
}

void MainWindow::clear_previous_plan()
{
    // Remove all tabs
    while (m_right_tabs->count() > 0) {
        m_right_tabs->removeTab(0);
    }

    // Delete all tracked widgets
    for (auto* widget : m_current_widgets) {
        if (widget) {
            widget->setParent(nullptr);
            delete widget;
        }
    }
    m_current_widgets.clear();
}

}  // namespace mealplan
