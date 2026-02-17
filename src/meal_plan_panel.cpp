#include "meal_plan_panel.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QVBoxLayout>

namespace mealplan {

MealPlanPanel::MealPlanPanel(const Meal& meal, QWidget* parent)
    : QFrame(parent)
{
    setup_ui(meal);
}

void MealPlanPanel::setup_ui(const Meal& meal)
{
    setStyleSheet(
        "MealPlanPanel {"
        "  border: 1px solid palette(mid);"
        "  border-radius: 8px;"
        "  padding: 10px;"
        "  background-color: palette(base);"
        "}"
        "MealPlanPanel:hover {"
        "  border-color: #2d7d46;"
        "  background-color: palette(midlight);"
        "}");

    auto* layout = new QVBoxLayout(this);
    layout->setSpacing(6);

    // Meal name (bold, 14pt)
    auto* name_label = new QLabel(meal.name, this);
    name_label->setStyleSheet(
        "font-size: 14px; font-weight: bold; color: palette(text);");
    name_label->setWordWrap(true);
    layout->addWidget(name_label);

    // Info row: category badge, cuisine, method, protein
    auto* info_layout = new QHBoxLayout;
    info_layout->setSpacing(8);

    // Category badge with color
    auto* category_badge = new QLabel(
        category_display_name(meal.category), this);
    QString badge_color;
    switch (meal.category) {
    case MealCategory::Meat:        badge_color = "#e8d5c4"; break;
    case MealCategory::Pescatarian: badge_color = "#c4dde8"; break;
    case MealCategory::Vegetarian:  badge_color = "#d4e8c4"; break;
    case MealCategory::Vegan:       badge_color = "#c4e8c4"; break;
    }
    category_badge->setStyleSheet(
        QString("background-color: %1; color: #111; padding: 2px 8px; "
                "border-radius: 4px; font-size: 11px; font-weight: bold;")
            .arg(badge_color));
    info_layout->addWidget(category_badge);

    // Cuisine
    auto* cuisine_label = new QLabel(meal.cuisine, this);
    cuisine_label->setStyleSheet("font-size: 11px; color: palette(link);");
    info_layout->addWidget(cuisine_label);

    // Method
    auto* method_label = new QLabel(meal.method, this);
    method_label->setStyleSheet("font-size: 11px; color: palette(link);");
    info_layout->addWidget(method_label);

    // Protein
    auto* protein_label = new QLabel(
        QString("%1g protein").arg(meal.protein_grams), this);
    protein_label->setStyleSheet(
        "font-size: 11px; color: #2d7d46; font-weight: bold;");
    info_layout->addWidget(protein_label);

    info_layout->addStretch();
    layout->addLayout(info_layout);

    // Description (smaller, italic)
    auto* desc_label = new QLabel(meal.description, this);
    desc_label->setStyleSheet(
        "font-size: 11px; font-style: italic; color: palette(link);");
    desc_label->setWordWrap(true);
    layout->addWidget(desc_label);
}

void MealPlanPanel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
    QFrame::mousePressEvent(event);
}

}  // namespace mealplan
