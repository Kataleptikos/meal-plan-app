#pragma once

#include <QString>
#include <QStringList>
#include <QVector>

namespace mealplan {

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

constexpr int TOTAL_MEALS       = 43;
constexpr int MEALS_PER_WEEK    = 3;
constexpr int HISTORY_WEEKS     = 3;
constexpr int MAX_HISTORY_SIZE  = MEALS_PER_WEEK * HISTORY_WEEKS;  // 9

constexpr int MEAT_FIRST        = 1;
constexpr int MEAT_LAST         = 13;
constexpr int PESCATARIAN_FIRST = 14;
constexpr int PESCATARIAN_LAST  = 23;
constexpr int VEGETARIAN_FIRST  = 24;
constexpr int VEGETARIAN_LAST   = 33;
constexpr int VEGAN_FIRST       = 34;
constexpr int VEGAN_LAST        = 43;

// ---------------------------------------------------------------------------
// Enumerations
// ---------------------------------------------------------------------------

/// @brief Dietary category of a meal.
enum class MealCategory {
    Meat,
    Pescatarian,
    Vegetarian,
    Vegan
};

/// @brief Supermarket aisle grouping for grocery items.
enum class AisleCategory {
    Produce,       ///< Fresh fruits, vegetables, herbs
    Proteins,      ///< Meat, fish, tofu, tempeh, seitan, TVP
    Dairy,         ///< Cheese, yogurt, eggs, cottage cheese
    Grains,        ///< Rice, pasta, bread, quinoa, tortillas
    Canned,        ///< Canned beans, tomatoes, coconut milk
    PantrySpices,  ///< Oils, spices, sauces, vinegars, nuts
    Frozen,        ///< Frozen edamame, frozen vegetables
    Other          ///< Anything that does not fit above
};

// ---------------------------------------------------------------------------
// Data structs
// ---------------------------------------------------------------------------

/// @brief A single ingredient with its quantity and store aisle.
struct Ingredient {
    QString       name;      ///< e.g. "chicken breast"
    double        quantity;  ///< Numeric amount (for 2 portions)
    QString       unit;      ///< e.g. "oz", "cup", "cloves"
    AisleCategory aisle;     ///< Supermarket aisle for this item
};

/// @brief A complete meal with recipe details and nutritional info.
struct Meal {
    int                  id;              ///< Unique identifier (1-43)
    QString              name;            ///< e.g. "Chicken Shawarma Bowl"
    QString              description;     ///< One-line summary
    MealCategory         category;        ///< Dietary category
    QString              cuisine;         ///< e.g. "Middle Eastern"
    QString              method;          ///< e.g. "Baked"
    int                  protein_grams;   ///< Approximate per serving
    int                  servings = 2;    ///< Number of portions (always 2)
    QVector<Ingredient>  ingredients;     ///< Ingredient list for 2 portions
    QStringList          steps;           ///< Step-by-step cooking instructions
};

/// @brief A consolidated grocery list entry produced by aggregation.
struct GroceryItem {
    QString name;      ///< Normalized ingredient name
    double  quantity;  ///< Merged numeric quantity
    QString unit;      ///< Unit of measure
};

// ---------------------------------------------------------------------------
// Free functions (inline, header-only)
// ---------------------------------------------------------------------------

/// @brief Return a human-readable display name for a meal category.
/// @param cat The meal category to format.
/// @return A QString such as "Meat", "Pescatarian", "Vegetarian", or "Vegan".
inline QString category_display_name(MealCategory cat)
{
    switch (cat) {
    case MealCategory::Meat:        return QStringLiteral("Meat");
    case MealCategory::Pescatarian: return QStringLiteral("Pescatarian");
    case MealCategory::Vegetarian:  return QStringLiteral("Vegetarian");
    case MealCategory::Vegan:       return QStringLiteral("Vegan");
    }
    return QStringLiteral("Unknown");
}

/// @brief Return a human-readable display name for a supermarket aisle.
/// @param aisle The aisle category to format.
/// @return A QString such as "Produce", "Pantry & Spices", etc.
inline QString aisle_display_name(AisleCategory aisle)
{
    switch (aisle) {
    case AisleCategory::Produce:      return QStringLiteral("Produce");
    case AisleCategory::Proteins:     return QStringLiteral("Proteins");
    case AisleCategory::Dairy:        return QStringLiteral("Dairy");
    case AisleCategory::Grains:       return QStringLiteral("Grains");
    case AisleCategory::Canned:       return QStringLiteral("Canned Goods");
    case AisleCategory::PantrySpices: return QStringLiteral("Pantry & Spices");
    case AisleCategory::Frozen:       return QStringLiteral("Frozen");
    case AisleCategory::Other:        return QStringLiteral("Other");
    }
    return QStringLiteral("Unknown");
}

/// @brief Format a numeric quantity for display, removing trailing zeros.
///
/// Whole numbers are displayed without a decimal point (e.g. 2.0 becomes "2").
/// Fractional values keep up to two decimal places (e.g. 0.5 becomes "0.5").
///
/// @param quantity The numeric value to format.
/// @return A formatted QString.
inline QString format_quantity(double quantity)
{
    if (quantity == static_cast<int>(quantity)) {
        return QString::number(static_cast<int>(quantity));
    }
    // Remove trailing zeros from fractional representation
    QString result = QString::number(quantity, 'f', 2);
    while (result.endsWith('0')) {
        result.chop(1);
    }
    if (result.endsWith('.')) {
        result.chop(1);
    }
    return result;
}

} // namespace mealplan
