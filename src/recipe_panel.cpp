#include "recipe_panel.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QVBoxLayout>

namespace mealplan {

RecipePanel::RecipePanel(const Meal& meal, QWidget* parent)
    : QWidget(parent)
{
    setup_ui(meal);
}

void RecipePanel::setup_ui(const Meal& meal)
{
    auto* main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(5, 5, 5, 5);
    main_layout->setSpacing(10);

    // Meal name header
    auto* name_label = new QLabel(meal.name, this);
    name_label->setStyleSheet(
        "font-size: 18px; font-weight: bold; color: palette(text);");
    name_label->setWordWrap(true);
    main_layout->addWidget(name_label);

    // Metadata line
    auto* meta_label = new QLabel(
        QString("%1  |  %2  |  %3  |  %4g protein per serving")
            .arg(category_display_name(meal.category),
                 meal.cuisine,
                 meal.method,
                 QString::number(meal.protein_grams)),
        this);
    meta_label->setStyleSheet(
        "font-size: 12px; color: palette(link); margin-bottom: 8px;");
    meta_label->setWordWrap(true);
    main_layout->addWidget(meta_label);

    // Description
    auto* desc_label = new QLabel(meal.description, this);
    desc_label->setStyleSheet(
        "font-size: 12px; font-style: italic; color: palette(link); "
        "margin-bottom: 10px;");
    desc_label->setWordWrap(true);
    main_layout->addWidget(desc_label);

    // Two-column layout for ingredients and instructions
    auto* columns_layout = new QHBoxLayout;
    columns_layout->setSpacing(20);

    // --- LEFT COLUMN: Ingredients ---
    auto* ing_layout = new QVBoxLayout;

    auto* ing_header = new QLabel("Ingredients", this);
    ing_header->setStyleSheet(
        "font-size: 14px; font-weight: bold; color: #2d7d46; "
        "border-bottom: 2px solid #2d7d46; padding-bottom: 4px;");
    ing_layout->addWidget(ing_header);

    for (const Ingredient& ing : meal.ingredients) {
        QString text = QString("  %1 %2 %3")
                           .arg(format_quantity(ing.quantity),
                                ing.unit,
                                ing.name);
        auto* ing_label = new QLabel(text, this);
        ing_label->setStyleSheet("font-size: 12px; color: palette(text);");
        ing_label->setWordWrap(true);
        ing_layout->addWidget(ing_label);
    }
    ing_layout->addStretch();

    columns_layout->addLayout(ing_layout, 1);

    // --- RIGHT COLUMN: Instructions ---
    auto* steps_layout = new QVBoxLayout;

    auto* steps_header = new QLabel("Instructions", this);
    steps_header->setStyleSheet(
        "font-size: 14px; font-weight: bold; color: #2d7d46; "
        "border-bottom: 2px solid #2d7d46; padding-bottom: 4px;");
    steps_layout->addWidget(steps_header);

    for (int i = 0; i < meal.steps.size(); ++i) {
        QString text = QString("%1.  %2").arg(i + 1).arg(meal.steps[i]);
        auto* step_label = new QLabel(text, this);
        step_label->setStyleSheet(
            "font-size: 12px; color: palette(text); margin-bottom: 6px;");
        step_label->setWordWrap(true);
        steps_layout->addWidget(step_label);
    }
    steps_layout->addStretch();

    columns_layout->addLayout(steps_layout, 2);

    main_layout->addLayout(columns_layout);

    // Servings note at bottom
    auto* servings_label = new QLabel(
        QString("Serves %1").arg(meal.servings), this);
    servings_label->setStyleSheet(
        "font-size: 11px; color: palette(link); font-style: italic; "
        "margin-top: 10px;");
    servings_label->setAlignment(Qt::AlignRight);
    main_layout->addWidget(servings_label);
}

}  // namespace mealplan
