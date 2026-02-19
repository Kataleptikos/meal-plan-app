# Weekly Meal Plan Generator

A Qt6 desktop app that generates randomized weekly meal plans from a built-in database of 43 recipes, complete with step-by-step instructions and an auto-generated grocery list grouped by supermarket aisle.

<!-- screenshot -->

## Features

- **43 meals** across 4 diet categories and 25 cuisines
- **Customizable meal count** (1--7 per week) with category filters
- **Grocery list** automatically merged and sorted by aisle
- **Repeat avoidance** -- recently used meals are excluded for 3 weeks
- **Recipe detail view** -- ingredients, steps, protein info
- **System theme support** -- follows OS dark/light mode

## Prerequisites

| Dependency | Minimum version |
|---|---|
| Qt | 6.4 |
| CMake | 3.28 |
| Ninja | (any recent) |
| C++ compiler | C++17 support required |

## Build

**Using CMake presets (recommended):**

```bash
cmake --preset release
cmake --build --preset release
```

**Manual fallback:**

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Run

```bash
# Preset build
./build/release/MealPlanApp

# Manual build
./build/MealPlanApp
```

## Usage

1. Select how many meals you want (1--7) with the spinner
2. Check/uncheck diet categories (Meat, Pescatarian, Vegetarian, Vegan)
3. Click **Generate New Week**
4. Click any meal card to view the full recipe
5. Switch to the **Grocery List** tab for a consolidated shopping list

## Meal Categories

| Category | Meals | ID range |
|---|---|---|
| Meat | 13 | 1--13 |
| Pescatarian | 10 | 14--23 |
| Vegetarian | 10 | 24--33 |
| Vegan | 10 | 34--43 |

## Project Structure

```
src/
  types.h                 Shared data types, enums, and constants
  meal_database.h/.cpp    Immutable in-memory database of all 43 meals
  meal_selector.h/.cpp    Constrained random picker with history avoidance
  history_manager.h/.cpp  Recent meal ID persistence (3-week window)
  grocery_aggregator.h/.cpp  Merges ingredients into a grouped grocery list
  main_window.h/.cpp      Main application window and UI coordination
  meal_plan_panel.h/.cpp  Compact card widget for a single meal summary
  recipe_panel.h/.cpp     Detailed recipe view (ingredients + steps)
  grocery_panel.h/.cpp    Grocery list organized by supermarket aisle
```

## License

No license file yet.
