cmake_minimum_required(VERSION 3.28)

project(MealPlanApp
  VERSION 1.0.0
  DESCRIPTION "Weekly Meal Plan Generator - a Qt6 desktop application"
  LANGUAGES CXX
)

# Qt requires AUTOMOC to process Q_OBJECT macros in headers
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Widgets)

add_executable(MealPlanApp
  src/main.cpp
  src/meal_database.cpp
  src/meal_selector.cpp
  src/grocery_aggregator.cpp
  src/history_manager.cpp
  src/main_window.cpp
  src/meal_plan_panel.cpp
  src/recipe_panel.cpp
  src/grocery_panel.cpp
)

target_compile_features(MealPlanApp PRIVATE cxx_std_17)

target_include_directories(MealPlanApp
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(MealPlanApp
  PRIVATE
    Qt6::Widgets
)

target_compile_options(MealPlanApp PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# ---------------------------------------------------------------------------
# Library target for testable source files (excludes main.cpp and UI files)
# ---------------------------------------------------------------------------
add_library(MealPlanCore STATIC
  src/meal_database.cpp
  src/meal_selector.cpp
  src/grocery_aggregator.cpp
  src/history_manager.cpp
)

target_compile_features(MealPlanCore PUBLIC cxx_std_17)

target_include_directories(MealPlanCore
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(MealPlanCore
  PUBLIC
    Qt6::Widgets
)

# ---------------------------------------------------------------------------
# Unit tests (Qt Test framework)
# ---------------------------------------------------------------------------
enable_testing()

find_package(Qt6 6.4 REQUIRED COMPONENTS Test)
