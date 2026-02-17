#include "meal_database.h"

#include <QVector>

namespace mealplan {

namespace {

Meal build_meal_01()
{
    Meal m;
    m.id = 1;
    m.name = "Chicken Shawarma Bowl";
    m.description = "Yogurt-marinated chicken breast with rice, cucumber-tomato salad, hummus, and tzatziki";
    m.category = MealCategory::Meat;
    m.cuisine = "Middle Eastern";
    m.method = "Baked";
    m.protein_grams = 43;
    m.servings = 2;
    m.ingredients = {
        {"chicken breast", 340.0, "g", AisleCategory::Proteins},
        {"Greek yogurt", 120.0, "ml", AisleCategory::Dairy},
        {"jasmine rice", 240.0, "ml", AisleCategory::Grains},
        {"cucumber", 1.0, "whole", AisleCategory::Produce},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"paprika", 1.0, "tsp", AisleCategory::PantrySpices},
        {"turmeric", 0.5, "tsp", AisleCategory::PantrySpices},
        {"hummus", 120.0, "ml", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"red onion", 0.5, "whole", AisleCategory::Produce},
        {"fresh parsley", 2.0, "tbsp", AisleCategory::Produce}
    };
    m.steps = {
        "Mix yogurt, cumin, paprika, turmeric, minced garlic, lemon juice, salt, and pepper in a bowl. Add sliced chicken breast and marinate for at least 30 minutes.",
        "Cook jasmine rice according to package directions and set aside.",
        "Preheat oven to 425 F (220 C). Spread marinated chicken on a lined baking sheet.",
        "Bake chicken for 20-25 minutes until internal temperature reaches 165 F (74 C).",
        "Dice cucumber, tomatoes, and red onion. Toss with olive oil, lemon juice, salt, and parsley to make the salad.",
        "Slice baked chicken into strips.",
        "Assemble bowls: rice on the bottom, topped with chicken, cucumber-tomato salad, a dollop of hummus, and extra yogurt as tzatziki."
    };
    return m;
}

Meal build_meal_02()
{
    Meal m;
    m.id = 2;
    m.name = "Korean Beef Bulgogi Lettuce Wraps";
    m.description = "Thin-sliced sirloin in soy-garlic-pear marinade, served in butter lettuce with pickled veg";
    m.category = MealCategory::Meat;
    m.cuisine = "Korean";
    m.method = "Pan-seared";
    m.protein_grams = 48;
    m.servings = 2;
    m.ingredients = {
        {"sirloin steak", 395.0, "g", AisleCategory::Proteins},
        {"soy sauce", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 2.0, "tsp", AisleCategory::PantrySpices},
        {"Asian pear", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"brown sugar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"butter lettuce", 1.0, "head", AisleCategory::Produce},
        {"carrot", 1.0, "whole", AisleCategory::Produce},
        {"rice vinegar", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"green onion", 3.0, "whole", AisleCategory::Produce},
        {"sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Grate the Asian pear and mix with soy sauce, sesame oil, minced garlic, grated ginger, and brown sugar to make the marinade.",
        "Slice sirloin very thinly against the grain. Toss with marinade and refrigerate for 20-30 minutes.",
        "Julienne the carrot and toss with rice vinegar and a pinch of salt. Set aside to quick-pickle.",
        "Heat olive oil in a large skillet over high heat. Sear marinated beef in batches for 2-3 minutes until caramelized.",
        "Wash and separate butter lettuce leaves into cups.",
        "Slice green onions for garnish.",
        "Serve beef in lettuce cups topped with pickled carrots, green onions, and sesame seeds."
    };
    return m;
}

Meal build_meal_03()
{
    Meal m;
    m.id = 3;
    m.name = "Slow-Cooker Pork Carnitas Burrito Bowl";
    m.description = "Citrus-braised pork shoulder crisped under the broiler, over brown rice with black beans and pico de gallo";
    m.category = MealCategory::Meat;
    m.cuisine = "Mexican";
    m.method = "Slow-cooked";
    m.protein_grams = 42;
    m.servings = 2;
    m.ingredients = {
        {"pork shoulder", 395.0, "g", AisleCategory::Proteins},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"black beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"orange", 1.0, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"cumin", 1.5, "tsp", AisleCategory::PantrySpices},
        {"oregano", 1.0, "tsp", AisleCategory::PantrySpices},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"jalapeno", 1.0, "whole", AisleCategory::Produce},
        {"fresh cilantro", 3.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Season pork shoulder with cumin, oregano, salt, and pepper. Place in slow cooker with halved onion and garlic cloves.",
        "Squeeze orange and lime juice over the pork. Cook on low for 6-8 hours until fork-tender.",
        "Cook brown rice according to package directions.",
        "Dice tomatoes, jalapeno, and cilantro. Mix with lime juice and salt to make pico de gallo.",
        "Warm and drain black beans in a small saucepan.",
        "Shred the pork with two forks. Spread on a baking sheet, drizzle with olive oil, and broil for 3-4 minutes until edges crisp.",
        "Assemble bowls with brown rice, black beans, crisped carnitas, and pico de gallo."
    };
    return m;
}

Meal build_meal_04()
{
    Meal m;
    m.id = 4;
    m.name = "Grilled Lamb Kofta Plate";
    m.description = "Spiced ground lamb kebabs with tabbouleh, roasted red peppers, and lemon-tahini sauce";
    m.category = MealCategory::Meat;
    m.cuisine = "Mediterranean";
    m.method = "Grilled";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"ground lamb", 340.0, "g", AisleCategory::Proteins},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"coriander", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cinnamon", 0.25, "tsp", AisleCategory::PantrySpices},
        {"bulgur wheat", 120.0, "ml", AisleCategory::Grains},
        {"fresh parsley", 120.0, "ml", AisleCategory::Produce},
        {"fresh mint", 2.0, "tbsp", AisleCategory::Produce},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"red bell pepper", 2.0, "whole", AisleCategory::Produce},
        {"tahini", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Soak bulgur wheat in boiling water for 15 minutes, then drain and fluff.",
        "Mix ground lamb with grated onion, minced garlic, cumin, coriander, cinnamon, salt, and pepper. Form into small oval kebabs.",
        "Grill kofta over medium-high heat for 4-5 minutes per side until cooked through.",
        "Halve red bell peppers, brush with olive oil, and grill until charred and tender.",
        "Chop parsley, mint, and tomatoes. Toss with drained bulgur, lemon juice, and olive oil to make tabbouleh.",
        "Whisk tahini with lemon juice, a splash of water, and salt to make the sauce.",
        "Plate the kofta with tabbouleh, roasted peppers, and a drizzle of lemon-tahini sauce."
    };
    return m;
}

Meal build_meal_05()
{
    Meal m;
    m.id = 5;
    m.name = "Thai Basil Beef Stir-Fry (Pad Kra Pao)";
    m.description = "Flank steak with Thai chilies, garlic, and basil in light soy-fish sauce over jasmine rice";
    m.category = MealCategory::Meat;
    m.cuisine = "Thai";
    m.method = "Stir-fried";
    m.protein_grams = 36;
    m.servings = 2;
    m.ingredients = {
        {"flank steak", 340.0, "g", AisleCategory::Proteins},
        {"jasmine rice", 240.0, "ml", AisleCategory::Grains},
        {"garlic cloves", 6.0, "whole", AisleCategory::Produce},
        {"Thai chili", 3.0, "whole", AisleCategory::Produce},
        {"fresh Thai basil", 240.0, "ml", AisleCategory::Produce},
        {"soy sauce", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"fish sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"oyster sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"brown sugar", 1.0, "tsp", AisleCategory::PantrySpices},
        {"vegetable oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"green beans", 240.0, "ml", AisleCategory::Produce},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook jasmine rice according to package directions and set aside.",
        "Slice flank steak thinly against the grain. Season lightly with salt and pepper.",
        "Mince garlic and slice Thai chilies. Slice onion into thin wedges.",
        "Heat vegetable oil in a wok over high heat until smoking. Stir-fry beef in batches for 1-2 minutes until browned. Remove and set aside.",
        "In the same wok, stir-fry garlic, chilies, and onion for 30 seconds until fragrant.",
        "Add green beans and cook for 2 minutes. Return beef to the wok. Add soy sauce, fish sauce, oyster sauce, and brown sugar. Toss to coat.",
        "Remove from heat and fold in fresh Thai basil leaves until wilted.",
        "Serve immediately over jasmine rice."
    };
    return m;
}

Meal build_meal_06()
{
    Meal m;
    m.id = 6;
    m.name = "Herb-Grilled Chicken Thighs with Quinoa";
    m.description = "Lemon-oregano chicken thighs over quinoa with roasted vegetables and olive relish";
    m.category = MealCategory::Meat;
    m.cuisine = "Mediterranean";
    m.method = "Grilled";
    m.protein_grams = 44;
    m.servings = 2;
    m.ingredients = {
        {"chicken thighs", 395.0, "g", AisleCategory::Proteins},
        {"quinoa", 240.0, "ml", AisleCategory::Grains},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"dried oregano", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"zucchini", 1.0, "whole", AisleCategory::Produce},
        {"red bell pepper", 1.0, "whole", AisleCategory::Produce},
        {"red onion", 0.5, "whole", AisleCategory::Produce},
        {"kalamata olives", 60.0, "ml", AisleCategory::PantrySpices},
        {"capers", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh parsley", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Marinate chicken thighs in olive oil, lemon juice, minced garlic, oregano, salt, and pepper for at least 20 minutes.",
        "Cook quinoa according to package directions and fluff with a fork.",
        "Cut zucchini, red bell pepper, and red onion into chunks. Toss with olive oil, salt, and pepper.",
        "Grill vegetables over medium heat for 8-10 minutes, turning occasionally, until charred and tender.",
        "Grill chicken thighs over medium-high heat for 6-7 minutes per side until internal temp reaches 165 F (74 C).",
        "Chop olives and mix with capers and parsley to make the olive relish.",
        "Serve chicken over quinoa with grilled vegetables and olive relish."
    };
    return m;
}

Meal build_meal_07()
{
    Meal m;
    m.id = 7;
    m.name = "Italian Turkey Meatball & White Bean Soup";
    m.description = "Lean turkey meatballs simmered in tomato-herb broth with cannellini beans and kale";
    m.category = MealCategory::Meat;
    m.cuisine = "Italian";
    m.method = "Simmered";
    m.protein_grams = 41;
    m.servings = 2;
    m.ingredients = {
        {"ground turkey", 285.0, "g", AisleCategory::Proteins},
        {"cannellini beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"crushed tomatoes, canned", 240.0, "ml", AisleCategory::Canned},
        {"kale", 480.0, "ml", AisleCategory::Produce},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"Italian seasoning", 1.0, "tsp", AisleCategory::PantrySpices},
        {"breadcrumbs", 60.0, "ml", AisleCategory::Grains},
        {"egg", 1.0, "whole", AisleCategory::Dairy},
        {"chicken broth", 720.0, "ml", AisleCategory::Canned},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"parmesan cheese", 2.0, "tbsp", AisleCategory::Dairy},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"red pepper flakes", 0.25, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Mix ground turkey with breadcrumbs, egg, half the minced garlic, parmesan, Italian seasoning, salt, and pepper. Form into small meatballs.",
        "Heat olive oil in a large pot over medium heat. Brown meatballs on all sides, about 5 minutes. Remove and set aside.",
        "In the same pot, saute diced onion and remaining garlic for 3 minutes until softened.",
        "Add crushed tomatoes, chicken broth, and red pepper flakes. Bring to a simmer.",
        "Return meatballs to the pot and simmer for 15 minutes until cooked through.",
        "Add drained cannellini beans and torn kale. Cook for 5 more minutes until kale is wilted.",
        "Serve hot, garnished with extra parmesan cheese."
    };
    return m;
}

Meal build_meal_08()
{
    Meal m;
    m.id = 8;
    m.name = "Herb-Crusted Bison Burger";
    m.description = "Rosemary-garlic bison patty served bunless on arugula with roasted sweet potato and Dijon-yogurt sauce";
    m.category = MealCategory::Meat;
    m.cuisine = "American";
    m.method = "Grilled";
    m.protein_grams = 36;
    m.servings = 2;
    m.ingredients = {
        {"ground bison", 285.0, "g", AisleCategory::Proteins},
        {"sweet potato", 2.0, "whole", AisleCategory::Produce},
        {"arugula", 720.0, "ml", AisleCategory::Produce},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"fresh rosemary", 1.0, "tbsp", AisleCategory::Produce},
        {"Greek yogurt", 60.0, "ml", AisleCategory::Dairy},
        {"Dijon mustard", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"smoked paprika", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Preheat oven to 400 F (200 C). Cube sweet potatoes, toss with olive oil, smoked paprika, salt, and pepper. Roast for 25-30 minutes until tender.",
        "Mix ground bison with minced garlic, chopped rosemary, salt, and pepper. Form into two patties.",
        "Grill or pan-sear patties over medium-high heat for 4-5 minutes per side for medium doneness.",
        "Whisk Greek yogurt with Dijon mustard, a squeeze of lemon, and salt to make the sauce.",
        "Thinly slice red onion for topping.",
        "Arrange arugula on plates, top with bison patties and sliced onion.",
        "Serve with roasted sweet potatoes and a drizzle of Dijon-yogurt sauce."
    };
    return m;
}

Meal build_meal_09()
{
    Meal m;
    m.id = 9;
    m.name = "Chimichurri Grilled Flank Steak";
    m.description = "Medium-rare flank steak with parsley-oregano chimichurri and charred zucchini";
    m.category = MealCategory::Meat;
    m.cuisine = "Argentine";
    m.method = "Grilled";
    m.protein_grams = 48;
    m.servings = 2;
    m.ingredients = {
        {"flank steak", 395.0, "g", AisleCategory::Proteins},
        {"fresh parsley", 240.0, "ml", AisleCategory::Produce},
        {"fresh oregano", 2.0, "tbsp", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"red wine vinegar", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"red pepper flakes", 0.5, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"zucchini", 2.0, "whole", AisleCategory::Produce},
        {"lemon", 0.5, "whole", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Finely chop parsley, oregano, and garlic. Mix with olive oil, red wine vinegar, red pepper flakes, salt, and pepper to make chimichurri.",
        "Season flank steak generously with salt and pepper on both sides.",
        "Preheat grill to high heat. Grill steak for 4-5 minutes per side for medium-rare.",
        "Slice zucchini lengthwise into thick planks. Brush with olive oil and season with salt.",
        "Grill zucchini for 3-4 minutes per side until charred and tender.",
        "Let steak rest for 5 minutes, then slice thinly against the grain.",
        "Serve sliced steak with charred zucchini and generous spoonfuls of chimichurri."
    };
    return m;
}

Meal build_meal_10()
{
    Meal m;
    m.id = 10;
    m.name = "Baked Lemon-Herb Turkey Breast";
    m.description = "Roasted boneless turkey breast with thyme, rosemary, and root vegetables";
    m.category = MealCategory::Meat;
    m.cuisine = "American";
    m.method = "Roasted";
    m.protein_grams = 49;
    m.servings = 2;
    m.ingredients = {
        {"boneless turkey breast", 395.0, "g", AisleCategory::Proteins},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"fresh thyme", 1.0, "tbsp", AisleCategory::Produce},
        {"fresh rosemary", 1.0, "tbsp", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"carrot", 2.0, "whole", AisleCategory::Produce},
        {"parsnip", 1.0, "whole", AisleCategory::Produce},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"butter", 1.0, "tbsp", AisleCategory::Dairy},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Preheat oven to 375 F (190 C). Pat turkey breast dry with paper towels.",
        "Mix softened butter with chopped thyme, rosemary, minced garlic, lemon zest, salt, and pepper. Rub evenly over the turkey breast.",
        "Peel and chop carrots, parsnip, and onion into chunks. Toss with olive oil, salt, and pepper.",
        "Spread root vegetables in a roasting pan and place turkey breast on top.",
        "Roast for 35-45 minutes until internal temperature reaches 165 F (74 C), basting once with pan juices.",
        "Let turkey rest for 10 minutes before slicing.",
        "Serve sliced turkey over the roasted root vegetables with a squeeze of lemon."
    };
    return m;
}

Meal build_meal_11()
{
    Meal m;
    m.id = 11;
    m.name = "Pan-Seared Pork Tenderloin Medallions";
    m.description = "Sage-seasoned medallions with apple-fennel-arugula slaw";
    m.category = MealCategory::Meat;
    m.cuisine = "French-inspired";
    m.method = "Pan-seared";
    m.protein_grams = 38;
    m.servings = 2;
    m.ingredients = {
        {"pork tenderloin", 340.0, "g", AisleCategory::Proteins},
        {"fresh sage", 1.0, "tbsp", AisleCategory::Produce},
        {"apple", 1.0, "whole", AisleCategory::Produce},
        {"fennel bulb", 0.5, "whole", AisleCategory::Produce},
        {"arugula", 480.0, "ml", AisleCategory::Produce},
        {"lemon", 0.5, "whole", AisleCategory::Produce},
        {"apple cider vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"honey", 1.0, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Slice pork tenderloin into 1-inch thick medallions. Season with chopped sage, salt, and pepper.",
        "Heat olive oil in a skillet over medium-high heat. Sear medallions for 3-4 minutes per side until golden and cooked to 145 F (63 C).",
        "Remove pork and let rest for 5 minutes.",
        "Thinly slice apple and fennel using a mandoline or sharp knife.",
        "Toss apple and fennel with arugula, lemon juice, apple cider vinegar, a drizzle of olive oil, and honey.",
        "Season slaw with salt and pepper to taste.",
        "Serve medallions alongside the apple-fennel-arugula slaw."
    };
    return m;
}

Meal build_meal_12()
{
    Meal m;
    m.id = 12;
    m.name = "Japanese Chicken Teriyaki Bowl";
    m.description = "Homemade low-sugar teriyaki chicken over brown rice with broccoli and edamame";
    m.category = MealCategory::Meat;
    m.cuisine = "Japanese";
    m.method = "Grilled";
    m.protein_grams = 50;
    m.servings = 2;
    m.ingredients = {
        {"chicken breast", 395.0, "g", AisleCategory::Proteins},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"soy sauce", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"mirin", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"honey", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh ginger", 1.0, "tsp", AisleCategory::Produce},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"cornstarch", 1.0, "tsp", AisleCategory::PantrySpices},
        {"broccoli", 480.0, "ml", AisleCategory::Produce},
        {"edamame, frozen", 120.0, "ml", AisleCategory::Frozen},
        {"sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 1.0, "tsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"vegetable oil", 1.0, "tbsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Whisk soy sauce, mirin, honey, grated ginger, minced garlic, sesame oil, and cornstarch in a small saucepan. Simmer for 5 minutes until thickened.",
        "Season chicken breast with salt and pepper. Grill or pan-sear for 6-7 minutes per side until cooked through.",
        "Steam broccoli florets for 4-5 minutes until tender-crisp.",
        "Cook frozen edamame according to package directions and drain.",
        "Slice grilled chicken and toss with half the teriyaki sauce.",
        "Assemble bowls with brown rice, chicken, broccoli, and edamame. Drizzle remaining sauce and sprinkle sesame seeds."
    };
    return m;
}

Meal build_meal_13()
{
    Meal m;
    m.id = 13;
    m.name = "Cuban Mojo-Roasted Pork Loin";
    m.description = "Citrus-garlic mojo pork with seasoned black beans and baked plantains";
    m.category = MealCategory::Meat;
    m.cuisine = "Cuban";
    m.method = "Roasted";
    m.protein_grams = 44;
    m.servings = 2;
    m.ingredients = {
        {"pork loin", 395.0, "g", AisleCategory::Proteins},
        {"orange", 1.0, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 6.0, "whole", AisleCategory::Produce},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"dried oregano", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"black beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"plantain", 2.0, "whole", AisleCategory::Produce},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"bay leaf", 1.0, "whole", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Blend orange juice, lime juice, minced garlic, cumin, oregano, olive oil, salt, and pepper to make the mojo marinade.",
        "Score the pork loin and pour marinade over it. Refrigerate for at least 1 hour.",
        "Preheat oven to 375 F (190 C). Place pork in a roasting pan and roast for 30-40 minutes until internal temp reaches 145 F (63 C).",
        "Heat olive oil in a saucepan. Saute diced onion and garlic, then add drained black beans, bay leaf, cumin, salt, and pepper. Simmer for 10 minutes.",
        "Peel and slice plantains diagonally. Brush with olive oil and bake alongside the pork for 15-20 minutes until golden.",
        "Let pork rest for 10 minutes, then slice.",
        "Serve sliced mojo pork with seasoned black beans and baked plantains."
    };
    return m;
}

Meal build_meal_14()
{
    Meal m;
    m.id = 14;
    m.name = "Grilled Mediterranean Salmon with Quinoa";
    m.description = "Wild salmon with lemon-garlic-oregano over herbed quinoa and roasted vegetables";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Mediterranean";
    m.method = "Grilled";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"wild salmon fillet", 340.0, "g", AisleCategory::Proteins},
        {"quinoa", 240.0, "ml", AisleCategory::Grains},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"dried oregano", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"cherry tomatoes", 240.0, "ml", AisleCategory::Produce},
        {"zucchini", 1.0, "whole", AisleCategory::Produce},
        {"red bell pepper", 1.0, "whole", AisleCategory::Produce},
        {"fresh dill", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions. Fluff and stir in chopped dill and a drizzle of olive oil.",
        "Mix olive oil, lemon juice, minced garlic, oregano, salt, and pepper. Brush over salmon fillets.",
        "Cut zucchini and red bell pepper into chunks. Halve cherry tomatoes. Toss with olive oil, salt, and pepper.",
        "Preheat grill to medium-high. Grill vegetables in a grill basket for 8-10 minutes.",
        "Grill salmon skin-side down for 4-5 minutes, flip, and cook for another 3-4 minutes until flaky.",
        "Serve salmon over herbed quinoa with grilled vegetables and a squeeze of lemon."
    };
    return m;
}

Meal build_meal_15()
{
    Meal m;
    m.id = 15;
    m.name = "Sesame-Crusted Seared Ahi Tuna";
    m.description = "Yellowfin tuna in sesame crust with wakame salad, pickled ginger, and soy-wasabi dip";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Japanese";
    m.method = "Pan-seared";
    m.protein_grams = 41;
    m.servings = 2;
    m.ingredients = {
        {"ahi tuna steak", 340.0, "g", AisleCategory::Proteins},
        {"sesame seeds", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"black sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"dried wakame seaweed", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"soy sauce", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"wasabi paste", 1.0, "tsp", AisleCategory::PantrySpices},
        {"pickled ginger", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"rice vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 2.0, "tsp", AisleCategory::PantrySpices},
        {"cucumber", 1.0, "whole", AisleCategory::Produce},
        {"vegetable oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Soak dried wakame in cold water for 5 minutes, then drain and toss with rice vinegar and sesame oil.",
        "Slice cucumber thinly and add to the wakame salad.",
        "Mix soy sauce and wasabi paste in a small dipping bowl.",
        "Pat tuna steaks dry and season with salt and pepper.",
        "Press both sides of tuna into a mixture of white and black sesame seeds to form a crust.",
        "Heat vegetable oil in a skillet over high heat. Sear tuna for 1-2 minutes per side, keeping the center rare.",
        "Slice tuna against the grain and serve with wakame salad, pickled ginger, and soy-wasabi dip."
    };
    return m;
}

Meal build_meal_16()
{
    Meal m;
    m.id = 16;
    m.name = "Cajun Blackened Shrimp with Red Beans";
    m.description = "8 oz shrimp in blackening spice with stewed red beans and cauliflower rice";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Cajun";
    m.method = "Blackened";
    m.protein_grams = 48;
    m.servings = 2;
    m.ingredients = {
        {"large shrimp", 455.0, "g", AisleCategory::Proteins},
        {"red kidney beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"cauliflower rice", 720.0, "ml", AisleCategory::Produce},
        {"paprika", 1.0, "tsp", AisleCategory::PantrySpices},
        {"cayenne pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"garlic powder", 1.0, "tsp", AisleCategory::PantrySpices},
        {"onion powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"dried thyme", 0.5, "tsp", AisleCategory::PantrySpices},
        {"dried oregano", 0.5, "tsp", AisleCategory::PantrySpices},
        {"celery", 1.0, "stalk", AisleCategory::Produce},
        {"green bell pepper", 1.0, "whole", AisleCategory::Produce},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Mix paprika, cayenne, garlic powder, onion powder, thyme, oregano, salt, and pepper to make the blackening spice.",
        "Pat shrimp dry and toss with half the spice mixture.",
        "Dice celery, green bell pepper, and onion. Saute in olive oil for 5 minutes with minced garlic.",
        "Add drained kidney beans and remaining spice mixture. Simmer with a splash of water for 10 minutes.",
        "Heat a cast iron skillet over high heat. Sear shrimp for 2 minutes per side until blackened and cooked through.",
        "Saute cauliflower rice in a separate pan with a little olive oil for 3-4 minutes until tender.",
        "Serve blackened shrimp over cauliflower rice alongside the stewed red beans."
    };
    return m;
}

Meal build_meal_17()
{
    Meal m;
    m.id = 17;
    m.name = "Baked Cod with Cannellini Beans & Tomatoes";
    m.description = "7 oz cod baked over white beans, San Marzano tomatoes, and olives";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Italian";
    m.method = "Baked";
    m.protein_grams = 46;
    m.servings = 2;
    m.ingredients = {
        {"cod fillet", 395.0, "g", AisleCategory::Proteins},
        {"cannellini beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"San Marzano tomatoes, canned", 240.0, "ml", AisleCategory::Canned},
        {"kalamata olives", 60.0, "ml", AisleCategory::PantrySpices},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"fresh basil", 60.0, "ml", AisleCategory::Produce},
        {"capers", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"red pepper flakes", 0.25, "tsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Preheat oven to 400 F (200 C).",
        "Spread drained cannellini beans in a baking dish. Top with crushed San Marzano tomatoes, sliced garlic, olives, and capers.",
        "Drizzle bean mixture with olive oil, red pepper flakes, salt, and pepper. Bake for 10 minutes.",
        "Season cod fillets with salt, pepper, and lemon juice. Place on top of the bean mixture.",
        "Return to oven and bake for 15-18 minutes until cod flakes easily with a fork.",
        "Garnish with fresh basil leaves and a drizzle of olive oil.",
        "Serve directly from the baking dish with lemon wedges on the side."
    };
    return m;
}

Meal build_meal_18()
{
    Meal m;
    m.id = 18;
    m.name = "Thai Red Curry Mahi-Mahi";
    m.description = "Mahi-mahi simmered in coconut-red curry with Thai basil, bamboo shoots, and snap peas";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Thai";
    m.method = "Poached";
    m.protein_grams = 42;
    m.servings = 2;
    m.ingredients = {
        {"mahi-mahi fillet", 340.0, "g", AisleCategory::Proteins},
        {"coconut milk, canned", 240.0, "ml", AisleCategory::Canned},
        {"red curry paste", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"bamboo shoots, canned", 120.0, "ml", AisleCategory::Canned},
        {"snap peas", 240.0, "ml", AisleCategory::Produce},
        {"fresh Thai basil", 120.0, "ml", AisleCategory::Produce},
        {"fish sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"brown sugar", 1.0, "tsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"jasmine rice", 240.0, "ml", AisleCategory::Grains},
        {"vegetable oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook jasmine rice according to package directions.",
        "Heat vegetable oil in a deep skillet. Saute minced garlic and ginger for 30 seconds, then stir in red curry paste for 1 minute.",
        "Pour in coconut milk and stir until smooth. Add fish sauce and brown sugar. Bring to a gentle simmer.",
        "Add snap peas and drained bamboo shoots. Cook for 3 minutes.",
        "Cut mahi-mahi into large chunks and gently nestle into the curry. Cover and poach for 8-10 minutes until fish is opaque.",
        "Stir in Thai basil and squeeze in lime juice.",
        "Serve curry over jasmine rice."
    };
    return m;
}

Meal build_meal_19()
{
    Meal m;
    m.id = 19;
    m.name = "Jerk-Spiced Tilapia with Black Bean-Mango Salsa";
    m.description = "Tilapia pan-seared in jerk seasoning topped with fresh mango-bean salsa";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Caribbean";
    m.method = "Pan-seared";
    m.protein_grams = 48;
    m.servings = 2;
    m.ingredients = {
        {"tilapia fillet", 395.0, "g", AisleCategory::Proteins},
        {"allspice", 0.5, "tsp", AisleCategory::PantrySpices},
        {"dried thyme", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cayenne pepper", 0.25, "tsp", AisleCategory::PantrySpices},
        {"garlic powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"onion powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cinnamon", 0.25, "tsp", AisleCategory::PantrySpices},
        {"mango", 1.0, "whole", AisleCategory::Produce},
        {"black beans, canned", 120.0, "ml", AisleCategory::Canned},
        {"red bell pepper", 0.5, "whole", AisleCategory::Produce},
        {"red onion", 0.25, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Mix allspice, thyme, cayenne, garlic powder, onion powder, cinnamon, salt, and pepper to make the jerk spice blend.",
        "Pat tilapia fillets dry and coat both sides with the jerk spice mixture.",
        "Dice mango, red bell pepper, and red onion. Combine with drained black beans, chopped cilantro, and lime juice to make the salsa.",
        "Heat olive oil in a skillet over medium-high heat.",
        "Pan-sear tilapia for 3-4 minutes per side until the spice crust is crisp and fish is cooked through.",
        "Serve tilapia topped generously with the mango-black bean salsa."
    };
    return m;
}

Meal build_meal_20()
{
    Meal m;
    m.id = 20;
    m.name = "Pan-Seared Scallops with French Green Lentils";
    m.description = "Golden scallops over warm Puy lentils with shallots and sherry vinaigrette";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "French bistro";
    m.method = "Pan-seared";
    m.protein_grams = 45;
    m.servings = 2;
    m.ingredients = {
        {"sea scallops", 340.0, "g", AisleCategory::Proteins},
        {"French green lentils", 180.0, "ml", AisleCategory::Grains},
        {"shallot", 2.0, "whole", AisleCategory::Produce},
        {"carrot", 1.0, "whole", AisleCategory::Produce},
        {"celery", 1.0, "stalk", AisleCategory::Produce},
        {"sherry vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"Dijon mustard", 1.0, "tsp", AisleCategory::PantrySpices},
        {"fresh thyme", 1.0, "tsp", AisleCategory::Produce},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"butter", 1.0, "tbsp", AisleCategory::Dairy},
        {"fresh parsley", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Rinse lentils. Simmer in salted water with diced carrot, celery, and thyme for 20-25 minutes until tender but not mushy. Drain.",
        "Dice shallots. Saute half in olive oil until softened. Toss with warm lentils.",
        "Whisk olive oil, sherry vinegar, Dijon mustard, remaining diced shallot, salt, and pepper to make the vinaigrette. Toss with lentils.",
        "Pat scallops very dry with paper towels. Season with salt and pepper.",
        "Heat olive oil and butter in a skillet over high heat. Sear scallops for 2 minutes per side until golden brown crust forms.",
        "Stir chopped parsley into the lentils.",
        "Serve scallops on a bed of warm dressed lentils."
    };
    return m;
}

Meal build_meal_21()
{
    Meal m;
    m.id = 21;
    m.name = "Poached Salmon Nicoise Salad";
    m.description = "Court-bouillon salmon with haricots verts, olives, hard-boiled egg, and Dijon vinaigrette";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Provencal";
    m.method = "Poached";
    m.protein_grams = 38;
    m.servings = 2;
    m.ingredients = {
        {"salmon fillet", 285.0, "g", AisleCategory::Proteins},
        {"eggs", 2.0, "whole", AisleCategory::Dairy},
        {"haricots verts", 240.0, "ml", AisleCategory::Produce},
        {"small potatoes", 170.0, "g", AisleCategory::Produce},
        {"cherry tomatoes", 240.0, "ml", AisleCategory::Produce},
        {"nicoise olives", 60.0, "ml", AisleCategory::PantrySpices},
        {"Dijon mustard", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"red wine vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"lemon", 0.5, "whole", AisleCategory::Produce},
        {"capers", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"bay leaf", 1.0, "whole", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Bring a pot of salted water with bay leaf and lemon slices to a gentle simmer for the court-bouillon.",
        "Gently lower salmon into the simmering water. Poach for 10-12 minutes until just cooked through. Remove and let cool slightly.",
        "Boil small potatoes until tender, about 12-15 minutes. Drain, cool, and halve.",
        "Blanch haricots verts in boiling salted water for 3 minutes, then shock in ice water.",
        "Hard-boil eggs for 10 minutes, cool, peel, and halve.",
        "Whisk Dijon mustard, red wine vinegar, olive oil, salt, and pepper to make the vinaigrette.",
        "Arrange potatoes, haricots verts, tomatoes, olives, capers, and egg halves on a platter. Flake salmon over the top.",
        "Drizzle with Dijon vinaigrette and serve."
    };
    return m;
}

Meal build_meal_22()
{
    Meal m;
    m.id = 22;
    m.name = "Grilled Shrimp Tacos with Pinto Beans";
    m.description = "Chipotle-lime shrimp in corn tortillas with cabbage slaw and seasoned pinto beans";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Mexican";
    m.method = "Grilled";
    m.protein_grams = 48;
    m.servings = 2;
    m.ingredients = {
        {"large shrimp", 395.0, "g", AisleCategory::Proteins},
        {"pinto beans, canned", 240.0, "ml", AisleCategory::Canned},
        {"corn tortillas", 6.0, "whole", AisleCategory::Grains},
        {"chipotle in adobo", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"lime", 2.0, "whole", AisleCategory::Produce},
        {"green cabbage", 480.0, "ml", AisleCategory::Produce},
        {"red onion", 0.25, "whole", AisleCategory::Produce},
        {"fresh cilantro", 3.0, "tbsp", AisleCategory::Produce},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"cumin", 0.5, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sour cream", 2.0, "tbsp", AisleCategory::Dairy},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Mix chipotle in adobo, lime juice, minced garlic, olive oil, salt, and pepper. Toss with peeled shrimp and marinate for 15 minutes.",
        "Shred cabbage and toss with lime juice, a drizzle of olive oil, and salt for the slaw.",
        "Heat pinto beans in a small saucepan with cumin, salt, and a splash of water. Mash slightly.",
        "Thread shrimp on skewers and grill over medium-high heat for 2-3 minutes per side until pink and charred.",
        "Warm corn tortillas on the grill for 30 seconds per side.",
        "Assemble tacos with grilled shrimp, cabbage slaw, cilantro, diced red onion, and a dollop of sour cream.",
        "Serve with seasoned pinto beans on the side and lime wedges."
    };
    return m;
}

Meal build_meal_23()
{
    Meal m;
    m.id = 23;
    m.name = "Gochujang-Glazed Broiled Cod with Edamame";
    m.description = "Sweet-spicy gochujang cod with brown rice, edamame, and pickled cucumbers";
    m.category = MealCategory::Pescatarian;
    m.cuisine = "Korean";
    m.method = "Broiled";
    m.protein_grams = 44;
    m.servings = 2;
    m.ingredients = {
        {"cod fillet", 395.0, "g", AisleCategory::Proteins},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"gochujang", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"soy sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 1.0, "tsp", AisleCategory::PantrySpices},
        {"honey", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tsp", AisleCategory::Produce},
        {"edamame, frozen", 240.0, "ml", AisleCategory::Frozen},
        {"cucumber", 1.0, "whole", AisleCategory::Produce},
        {"rice vinegar", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Whisk gochujang, soy sauce, sesame oil, honey, minced garlic, and grated ginger to make the glaze.",
        "Thinly slice cucumber, toss with rice vinegar and a pinch of salt. Refrigerate to quick-pickle.",
        "Cook frozen edamame according to package directions. Drain.",
        "Place cod fillets on a foil-lined baking sheet. Brush generously with the gochujang glaze.",
        "Broil on high for 8-10 minutes until the glaze caramelizes and fish flakes easily.",
        "Serve cod over brown rice with edamame and pickled cucumbers. Garnish with sesame seeds."
    };
    return m;
}

Meal build_meal_24()
{
    Meal m;
    m.id = 24;
    m.name = "Mediterranean Shakshuka with White Beans";
    m.description = "Eggs poached in spiced tomato-pepper sauce with cannellini beans and feta";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Middle Eastern";
    m.method = "Simmered";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"eggs", 6.0, "whole", AisleCategory::Dairy},
        {"cannellini beans, canned", 480.0, "ml", AisleCategory::Canned},
        {"feta cheese", 85.0, "g", AisleCategory::Dairy},
        {"crushed tomatoes, canned", 360.0, "ml", AisleCategory::Canned},
        {"red bell pepper", 1.0, "whole", AisleCategory::Produce},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"paprika", 1.0, "tsp", AisleCategory::PantrySpices},
        {"cayenne pepper", 0.25, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh parsley", 2.0, "tbsp", AisleCategory::Produce},
        {"crusty bread", 4.0, "slice", AisleCategory::Grains},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Heat olive oil in a large skillet over medium heat. Saute diced onion and red bell pepper for 5 minutes until softened.",
        "Add minced garlic, cumin, paprika, and cayenne. Cook for 1 minute until fragrant.",
        "Pour in crushed tomatoes, season with salt and pepper, and simmer for 10 minutes until thickened.",
        "Stir in drained cannellini beans and heat through for 3 minutes.",
        "Make 3 wells in the sauce and crack an egg into each. Cover and cook for 5-7 minutes until whites are set but yolks are still runny.",
        "Crumble feta cheese over the top and garnish with fresh parsley.",
        "Serve immediately with crusty bread for dipping."
    };
    return m;
}

Meal build_meal_25()
{
    Meal m;
    m.id = 25;
    m.name = "Crispy Tofu & Edamame Stir-Fry over Quinoa";
    m.description = "Pan-fried tofu with edamame, broccoli, and snap peas in garlic-ginger-soy glaze";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "East Asian";
    m.method = "Stir-fried";
    m.protein_grams = 37;
    m.servings = 2;
    m.ingredients = {
        {"firm tofu", 395.0, "g", AisleCategory::Proteins},
        {"edamame, frozen", 240.0, "ml", AisleCategory::Frozen},
        {"quinoa", 480.0, "ml", AisleCategory::Grains},
        {"broccoli", 480.0, "ml", AisleCategory::Produce},
        {"snap peas", 240.0, "ml", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"soy sauce", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 1.0, "tsp", AisleCategory::PantrySpices},
        {"rice vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"cornstarch", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"vegetable oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sriracha", 1.0, "tsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions and set aside.",
        "Press tofu for 15 minutes to remove excess moisture. Cut into cubes and toss with cornstarch, salt, and pepper.",
        "Heat vegetable oil in a large skillet over medium-high heat. Pan-fry tofu cubes for 3-4 minutes per side until golden and crispy. Remove.",
        "In the same pan, stir-fry minced garlic and ginger for 30 seconds.",
        "Add broccoli florets, snap peas, and edamame. Stir-fry for 4-5 minutes until tender-crisp.",
        "Return tofu to the pan. Add soy sauce, sesame oil, rice vinegar, and sriracha. Toss to coat.",
        "Serve stir-fry over quinoa."
    };
    return m;
}

Meal build_meal_26()
{
    Meal m;
    m.id = 26;
    m.name = "Loaded Black Bean & Egg Burrito Bowl";
    m.description = "Scrambled eggs with seasoned black beans over brown rice, cheddar, pico de gallo, and avocado";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Mexican";
    m.method = "Pan-cooked";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"eggs", 6.0, "whole", AisleCategory::Dairy},
        {"black beans, canned", 480.0, "ml", AisleCategory::Canned},
        {"cheddar cheese", 55.0, "g", AisleCategory::Dairy},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"avocado", 1.0, "whole", AisleCategory::Produce},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"red onion", 0.25, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"chili powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Heat drained black beans in a saucepan with minced garlic, cumin, chili powder, and salt. Mash slightly and keep warm.",
        "Dice tomatoes and red onion. Mix with chopped cilantro and lime juice to make pico de gallo.",
        "Whisk eggs with a pinch of salt and pepper. Scramble in olive oil over medium heat until just set.",
        "Slice avocado and shred cheddar cheese.",
        "Assemble bowls: brown rice, seasoned black beans, scrambled eggs, pico de gallo, sliced avocado, and shredded cheddar.",
        "Serve with lime wedges on the side."
    };
    return m;
}

Meal build_meal_27()
{
    Meal m;
    m.id = 27;
    m.name = "Palak Paneer with Chickpeas";
    m.description = "Pan-seared paneer and chickpeas in creamy spinach sauce with garam masala";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Indian";
    m.method = "Simmered";
    m.protein_grams = 37;
    m.servings = 2;
    m.ingredients = {
        {"paneer", 225.0, "g", AisleCategory::Dairy},
        {"chickpeas, canned", 480.0, "ml", AisleCategory::Canned},
        {"baby spinach", 1440.0, "ml", AisleCategory::Produce},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"garam masala", 1.0, "tsp", AisleCategory::PantrySpices},
        {"turmeric", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"heavy cream", 60.0, "ml", AisleCategory::Dairy},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"naan bread", 2.0, "whole", AisleCategory::Grains},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cut paneer into cubes and pan-sear in olive oil until golden on all sides. Remove and set aside.",
        "In the same pan, saute diced onion for 5 minutes until golden. Add minced garlic and ginger, cook for 1 minute.",
        "Add spinach in batches, cooking until fully wilted. Let cool slightly then blend into a smooth puree.",
        "Return spinach puree to the pan. Stir in garam masala, turmeric, cumin, salt, and pepper.",
        "Add drained chickpeas and heavy cream. Simmer for 10 minutes.",
        "Fold in seared paneer cubes and heat through for 2-3 minutes.",
        "Serve with warm naan bread."
    };
    return m;
}

Meal build_meal_28()
{
    Meal m;
    m.id = 28;
    m.name = "Tempeh Teriyaki Bowl with Edamame";
    m.description = "Grilled teriyaki tempeh with edamame, pickled cucumber, and brown rice";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Japanese";
    m.method = "Grilled";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"tempeh", 225.0, "g", AisleCategory::Proteins},
        {"edamame, frozen", 480.0, "ml", AisleCategory::Frozen},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"soy sauce", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"mirin", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"honey", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 1.0, "tsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tsp", AisleCategory::Produce},
        {"cucumber", 1.0, "whole", AisleCategory::Produce},
        {"rice vinegar", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"green onion", 2.0, "whole", AisleCategory::Produce},
        {"vegetable oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Slice tempeh into thin strips. Steam for 10 minutes to remove bitterness.",
        "Whisk soy sauce, mirin, honey, sesame oil, minced garlic, and grated ginger for the teriyaki glaze.",
        "Marinate steamed tempeh in half the glaze for 10 minutes.",
        "Grill or pan-sear tempeh in vegetable oil for 3 minutes per side, basting with remaining glaze.",
        "Slice cucumber thinly and toss with rice vinegar and salt for quick pickles.",
        "Cook edamame according to package directions.",
        "Assemble bowls with brown rice, teriyaki tempeh, edamame, pickled cucumber, sliced green onion, and sesame seeds."
    };
    return m;
}

Meal build_meal_29()
{
    Meal m;
    m.id = 29;
    m.name = "Seitan Souvlaki Wrap with Tzatziki";
    m.description = "Oregano-lemon-garlic seitan in whole wheat pita with yogurt tzatziki";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Greek";
    m.method = "Grilled";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"seitan", 225.0, "g", AisleCategory::Proteins},
        {"Greek yogurt", 240.0, "ml", AisleCategory::Dairy},
        {"whole wheat pita", 4.0, "whole", AisleCategory::Grains},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"dried oregano", 1.0, "tsp", AisleCategory::PantrySpices},
        {"cucumber", 0.5, "whole", AisleCategory::Produce},
        {"fresh dill", 1.0, "tbsp", AisleCategory::Produce},
        {"tomato", 1.0, "whole", AisleCategory::Produce},
        {"red onion", 0.25, "whole", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Slice seitan into thin strips. Toss with lemon juice, minced garlic, oregano, olive oil, salt, and pepper. Marinate 15 minutes.",
        "Grate half the cucumber and squeeze out excess moisture. Mix with Greek yogurt, minced garlic, chopped dill, lemon juice, and salt to make tzatziki.",
        "Grill or pan-sear marinated seitan over high heat for 3-4 minutes per side until charred.",
        "Slice tomato and red onion thinly.",
        "Warm pita bread on the grill or in a dry skillet.",
        "Assemble wraps with seitan, tomato, red onion, and a generous spoonful of tzatziki."
    };
    return m;
}

Meal build_meal_30()
{
    Meal m;
    m.id = 30;
    m.name = "Cottage Cheese & Black Bean Stuffed Sweet Potatoes";
    m.description = "Roasted sweet potatoes filled with cottage cheese and cumin-spiced black beans";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Southwestern";
    m.method = "Baked";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"sweet potato", 2.0, "whole", AisleCategory::Produce},
        {"cottage cheese", 480.0, "ml", AisleCategory::Dairy},
        {"black beans, canned", 360.0, "ml", AisleCategory::Canned},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"chili powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"green onion", 2.0, "whole", AisleCategory::Produce},
        {"lime", 0.5, "whole", AisleCategory::Produce},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"hot sauce", 1.0, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Preheat oven to 400 F (200 C). Prick sweet potatoes with a fork and rub with olive oil and salt.",
        "Bake sweet potatoes for 45-50 minutes until tender when pierced.",
        "Heat drained black beans in a saucepan with minced garlic, cumin, chili powder, and a splash of lime juice.",
        "Split baked sweet potatoes open and fluff the insides with a fork.",
        "Fill each potato with spiced black beans and top with a generous scoop of cottage cheese.",
        "Garnish with sliced green onions, hot sauce, and remaining lime juice.",
        "Season with salt and pepper to taste and serve."
    };
    return m;
}

Meal build_meal_31()
{
    Meal m;
    m.id = 31;
    m.name = "Greek Yogurt & Egg Grain Bowl";
    m.description = "Quinoa with hard-boiled eggs, thick Greek yogurt, roasted tomatoes, and za'atar";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Turkish-inspired";
    m.method = "Assembled";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"Greek yogurt", 480.0, "ml", AisleCategory::Dairy},
        {"eggs", 4.0, "whole", AisleCategory::Dairy},
        {"quinoa", 480.0, "ml", AisleCategory::Grains},
        {"cherry tomatoes", 240.0, "ml", AisleCategory::Produce},
        {"cucumber", 0.5, "whole", AisleCategory::Produce},
        {"za'atar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"lemon", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 1.0, "whole", AisleCategory::Produce},
        {"fresh parsley", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions. Fluff and let cool slightly.",
        "Hard-boil eggs for 10 minutes, cool in ice water, peel, and halve.",
        "Halve cherry tomatoes, toss with olive oil, salt, and pepper. Roast at 400 F (200 C) for 15 minutes.",
        "Dice cucumber and chop parsley.",
        "Spread a generous layer of Greek yogurt in each bowl.",
        "Top with quinoa, roasted tomatoes, diced cucumber, and egg halves.",
        "Drizzle with olive oil, sprinkle za'atar, and squeeze lemon juice over each bowl."
    };
    return m;
}

Meal build_meal_32()
{
    Meal m;
    m.id = 32;
    m.name = "Three-Bean Quinoa Chili with Cheddar";
    m.description = "Kidney and black beans simmered with chipotle and fire-roasted tomatoes over quinoa";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Tex-Mex";
    m.method = "Simmered";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"kidney beans, canned", 360.0, "ml", AisleCategory::Canned},
        {"black beans, canned", 360.0, "ml", AisleCategory::Canned},
        {"quinoa", 480.0, "ml", AisleCategory::Grains},
        {"cheddar cheese", 85.0, "g", AisleCategory::Dairy},
        {"fire-roasted tomatoes, canned", 240.0, "ml", AisleCategory::Canned},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"chipotle in adobo", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"chili powder", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sour cream", 2.0, "tbsp", AisleCategory::Dairy},
        {"green onion", 2.0, "whole", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions.",
        "Heat olive oil in a large pot. Saute diced onion for 5 minutes until softened.",
        "Add minced garlic, chili powder, cumin, and chopped chipotle in adobo. Cook for 1 minute.",
        "Add fire-roasted tomatoes, drained kidney beans, and drained black beans. Stir to combine.",
        "Simmer the chili for 20 minutes, stirring occasionally, until thick and flavorful.",
        "Season with salt and pepper to taste.",
        "Serve chili over quinoa, topped with shredded cheddar, sour cream, and sliced green onions."
    };
    return m;
}

Meal build_meal_33()
{
    Meal m;
    m.id = 33;
    m.name = "Lentil & Mozzarella Stuffed Bell Peppers";
    m.description = "Peppers filled with lentils, quinoa, and Italian herbs, topped with melted mozzarella";
    m.category = MealCategory::Vegetarian;
    m.cuisine = "Italian";
    m.method = "Baked";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"lentils", 480.0, "ml", AisleCategory::Grains},
        {"quinoa", 480.0, "ml", AisleCategory::Grains},
        {"mozzarella cheese", 115.0, "g", AisleCategory::Dairy},
        {"bell pepper", 4.0, "whole", AisleCategory::Produce},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"Italian seasoning", 1.0, "tsp", AisleCategory::PantrySpices},
        {"crushed tomatoes, canned", 120.0, "ml", AisleCategory::Canned},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh basil", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"parmesan cheese", 1.0, "tbsp", AisleCategory::Dairy}
    };
    m.steps = {
        "Cook lentils in salted water for 20-25 minutes until tender. Drain.",
        "Cook quinoa according to package directions.",
        "Saute diced onion and garlic in olive oil for 5 minutes. Add Italian seasoning.",
        "Mix cooked lentils, quinoa, sauteed onion mixture, crushed tomatoes, salt, and pepper.",
        "Cut tops off bell peppers and remove seeds. Fill with the lentil-quinoa mixture.",
        "Place stuffed peppers in a baking dish, drizzle with olive oil, and bake at 375 F (190 C) for 25-30 minutes.",
        "Top with shredded mozzarella and parmesan. Bake for 5 more minutes until cheese melts.",
        "Garnish with fresh basil and serve."
    };
    return m;
}

Meal build_meal_34()
{
    Meal m;
    m.id = 34;
    m.name = "Sesame-Ginger Seitan & Edamame Stir-Fry";
    m.description = "Sliced seitan with bok choy, snap peas, and edamame over quinoa";
    m.category = MealCategory::Vegan;
    m.cuisine = "East Asian";
    m.method = "Stir-fried";
    m.protein_grams = 46;
    m.servings = 2;
    m.ingredients = {
        {"seitan", 225.0, "g", AisleCategory::Proteins},
        {"edamame, frozen", 360.0, "ml", AisleCategory::Frozen},
        {"quinoa", 240.0, "ml", AisleCategory::Grains},
        {"bok choy", 480.0, "ml", AisleCategory::Produce},
        {"snap peas", 240.0, "ml", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"soy sauce", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 2.0, "tsp", AisleCategory::PantrySpices},
        {"rice vinegar", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame seeds", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"vegetable oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"red pepper flakes", 0.25, "tsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions.",
        "Slice seitan into thin strips. Season with salt and pepper.",
        "Heat vegetable oil in a wok over high heat. Stir-fry seitan for 3-4 minutes until browned. Remove.",
        "Add garlic, ginger, and red pepper flakes to the wok. Cook for 30 seconds.",
        "Add bok choy, snap peas, and edamame. Stir-fry for 3-4 minutes until tender-crisp.",
        "Return seitan to the wok. Add soy sauce, sesame oil, and rice vinegar. Toss to coat.",
        "Serve over quinoa, garnished with sesame seeds."
    };
    return m;
}

Meal build_meal_35()
{
    Meal m;
    m.id = 35;
    m.name = "Tempeh Tikka Masala with Red Lentil Dal";
    m.description = "Golden tempeh in spiced tomato-coconut cream alongside red lentil dal";
    m.category = MealCategory::Vegan;
    m.cuisine = "Indian";
    m.method = "Simmered";
    m.protein_grams = 37;
    m.servings = 2;
    m.ingredients = {
        {"tempeh", 285.0, "g", AisleCategory::Proteins},
        {"red lentils", 240.0, "ml", AisleCategory::Grains},
        {"coconut milk, canned", 120.0, "ml", AisleCategory::Canned},
        {"crushed tomatoes, canned", 240.0, "ml", AisleCategory::Canned},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"garam masala", 1.5, "tsp", AisleCategory::PantrySpices},
        {"turmeric", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"basmati rice", 240.0, "ml", AisleCategory::Grains},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cube tempeh and pan-fry in olive oil until golden on all sides. Set aside.",
        "Saute diced onion in olive oil for 5 minutes. Add garlic, ginger, garam masala, turmeric, and cumin. Cook 1 minute.",
        "Add crushed tomatoes and coconut milk. Simmer for 10 minutes.",
        "Add fried tempeh cubes and simmer for another 5 minutes to absorb flavors.",
        "In a separate pot, simmer red lentils in 1.5 cups water with turmeric and salt for 15-20 minutes until soft and creamy.",
        "Cook basmati rice according to package directions.",
        "Serve tempeh tikka masala alongside the red lentil dal over basmati rice, garnished with cilantro."
    };
    return m;
}

Meal build_meal_36()
{
    Meal m;
    m.id = 36;
    m.name = "Spicy TVP Taco Bowl with Black Beans";
    m.description = "Taco-seasoned TVP with black beans, brown rice, pico, avocado, and cashew queso";
    m.category = MealCategory::Vegan;
    m.cuisine = "Mexican";
    m.method = "Pan-cooked";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"TVP", 240.0, "ml", AisleCategory::Proteins},
        {"black beans, canned", 360.0, "ml", AisleCategory::Canned},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"nutritional yeast", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"avocado", 1.0, "whole", AisleCategory::Produce},
        {"red onion", 0.25, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"chili powder", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"garlic powder", 0.5, "tsp", AisleCategory::PantrySpices},
        {"smoked paprika", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cashews", 60.0, "ml", AisleCategory::PantrySpices},
        {"olive oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Rehydrate TVP by soaking in 1 cup hot vegetable broth or water for 10 minutes. Drain excess liquid.",
        "Saute TVP in olive oil with chili powder, cumin, garlic powder, smoked paprika, salt, and pepper for 5-7 minutes.",
        "Warm drained black beans in a small saucepan with a pinch of cumin and salt.",
        "Dice tomatoes and red onion. Mix with cilantro and lime juice for pico de gallo.",
        "Blend soaked cashews with nutritional yeast, a splash of water, and salt for cashew queso.",
        "Assemble bowls with brown rice, taco TVP, black beans, pico de gallo, sliced avocado, and a drizzle of cashew queso."
    };
    return m;
}

Meal build_meal_37()
{
    Meal m;
    m.id = 37;
    m.name = "Crispy Tofu & Chickpea Coconut Curry";
    m.description = "Baked tofu and chickpeas in red curry with spinach over quinoa";
    m.category = MealCategory::Vegan;
    m.cuisine = "Thai-Indian fusion";
    m.method = "Simmered";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"firm tofu", 395.0, "g", AisleCategory::Proteins},
        {"chickpeas, canned", 480.0, "ml", AisleCategory::Canned},
        {"quinoa", 240.0, "ml", AisleCategory::Grains},
        {"coconut milk, canned", 240.0, "ml", AisleCategory::Canned},
        {"red curry paste", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"baby spinach", 720.0, "ml", AisleCategory::Produce},
        {"onion", 0.5, "whole", AisleCategory::Produce},
        {"garlic cloves", 3.0, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"soy sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"cornstarch", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"vegetable oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh basil", 60.0, "ml", AisleCategory::Produce},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook quinoa according to package directions.",
        "Press tofu, cube, toss with cornstarch and salt. Bake at 400 F (200 C) for 25 minutes until crispy.",
        "Saute diced onion and garlic in vegetable oil for 3 minutes.",
        "Stir in red curry paste and cook for 1 minute. Pour in coconut milk and soy sauce.",
        "Add drained chickpeas and simmer for 10 minutes.",
        "Stir in spinach until wilted. Add baked tofu and squeeze in lime juice.",
        "Serve curry over quinoa, garnished with fresh basil."
    };
    return m;
}

Meal build_meal_38()
{
    Meal m;
    m.id = 38;
    m.name = "Ethiopian Misir Wot with Pan-Seared Seitan";
    m.description = "Berbere-spiced red lentil stew with seared seitan strips, served with injera";
    m.category = MealCategory::Vegan;
    m.cuisine = "Ethiopian";
    m.method = "Simmered";
    m.protein_grams = 39;
    m.servings = 2;
    m.ingredients = {
        {"seitan", 170.0, "g", AisleCategory::Proteins},
        {"red lentils", 480.0, "ml", AisleCategory::Grains},
        {"onion", 2.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"berbere spice", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"tomato paste", 2.0, "tbsp", AisleCategory::Canned},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"injera bread", 4.0, "piece", AisleCategory::Grains},
        {"turmeric", 0.5, "tsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Dice onions finely. Slowly cook in olive oil over medium-low heat for 15-20 minutes until deeply caramelized and jammy.",
        "Add minced garlic, ginger, and berbere spice. Cook for 2 minutes until fragrant.",
        "Stir in tomato paste and cook for 1 minute.",
        "Add rinsed red lentils and 2.5 cups water. Add turmeric and salt. Bring to a boil, then reduce to a simmer.",
        "Cook lentils for 20-25 minutes, stirring occasionally, until thick and creamy.",
        "Slice seitan into strips. Pan-sear in olive oil over high heat for 2-3 minutes per side until golden.",
        "Serve misir wot with seared seitan strips on top, alongside injera for scooping."
    };
    return m;
}

Meal build_meal_39()
{
    Meal m;
    m.id = 39;
    m.name = "Thai Peanut Tempeh Noodle Bowl";
    m.description = "Grilled tempeh in peanut-lime-chili sauce with rice noodles, cabbage, and hemp seeds";
    m.category = MealCategory::Vegan;
    m.cuisine = "Thai";
    m.method = "Grilled";
    m.protein_grams = 41;
    m.servings = 2;
    m.ingredients = {
        {"tempeh", 285.0, "g", AisleCategory::Proteins},
        {"peanut butter", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"hemp seeds", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"rice noodles", 170.0, "g", AisleCategory::Grains},
        {"green cabbage", 480.0, "ml", AisleCategory::Produce},
        {"carrot", 1.0, "whole", AisleCategory::Produce},
        {"lime", 1.0, "whole", AisleCategory::Produce},
        {"soy sauce", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"sriracha", 1.0, "tsp", AisleCategory::PantrySpices},
        {"garlic cloves", 2.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tsp", AisleCategory::Produce},
        {"green onion", 2.0, "whole", AisleCategory::Produce},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"vegetable oil", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Slice tempeh into strips and marinate in soy sauce and a squeeze of lime for 10 minutes.",
        "Whisk peanut butter, soy sauce, lime juice, sriracha, minced garlic, and ginger with 2 tbsp warm water to make the peanut sauce.",
        "Cook rice noodles according to package directions. Drain and rinse with cold water.",
        "Grill or pan-sear tempeh in vegetable oil for 3-4 minutes per side until charred.",
        "Shred cabbage and julienne carrot for the slaw.",
        "Toss noodles with peanut sauce, cabbage, and carrot.",
        "Top with grilled tempeh, hemp seeds, sliced green onions, and fresh cilantro."
    };
    return m;
}

Meal build_meal_40()
{
    Meal m;
    m.id = 40;
    m.name = "Seitan Shawarma Plate with Hummus";
    m.description = "Shawarma-spiced roasted seitan with hummus, tabbouleh, and garlic tahini";
    m.category = MealCategory::Vegan;
    m.cuisine = "Middle Eastern";
    m.method = "Roasted";
    m.protein_grams = 40;
    m.servings = 2;
    m.ingredients = {
        {"seitan", 285.0, "g", AisleCategory::Proteins},
        {"hummus", 160.0, "ml", AisleCategory::PantrySpices},
        {"bulgur wheat", 120.0, "ml", AisleCategory::Grains},
        {"fresh parsley", 120.0, "ml", AisleCategory::Produce},
        {"fresh mint", 2.0, "tbsp", AisleCategory::Produce},
        {"tomato", 2.0, "whole", AisleCategory::Produce},
        {"lemon", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"tahini", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"cumin", 1.0, "tsp", AisleCategory::PantrySpices},
        {"paprika", 1.0, "tsp", AisleCategory::PantrySpices},
        {"turmeric", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cinnamon", 0.25, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 3.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Slice seitan and toss with olive oil, cumin, paprika, turmeric, cinnamon, salt, and pepper.",
        "Roast seasoned seitan at 400 F (200 C) for 15-20 minutes until edges are crispy.",
        "Soak bulgur in boiling water for 15 minutes, drain, and fluff.",
        "Chop parsley, mint, and tomatoes. Mix with bulgur, lemon juice, and olive oil for tabbouleh.",
        "Whisk tahini with minced garlic, lemon juice, a splash of water, and salt for garlic tahini sauce.",
        "Arrange roasted seitan on a plate with a generous scoop of hummus, tabbouleh, and drizzle of tahini sauce."
    };
    return m;
}

Meal build_meal_41()
{
    Meal m;
    m.id = 41;
    m.name = "TVP Bolognese over Chickpea Pasta";
    m.description = "TVP simmered in San Marzano tomato sauce over Banza chickpea pasta with nutritional yeast";
    m.category = MealCategory::Vegan;
    m.cuisine = "Italian";
    m.method = "Simmered";
    m.protein_grams = 42;
    m.servings = 2;
    m.ingredients = {
        {"TVP", 240.0, "ml", AisleCategory::Proteins},
        {"chickpea pasta", 225.0, "g", AisleCategory::Grains},
        {"nutritional yeast", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"San Marzano tomatoes, canned", 360.0, "ml", AisleCategory::Canned},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"carrot", 1.0, "whole", AisleCategory::Produce},
        {"celery", 1.0, "stalk", AisleCategory::Produce},
        {"Italian seasoning", 1.0, "tsp", AisleCategory::PantrySpices},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"red wine", 60.0, "ml", AisleCategory::PantrySpices},
        {"tomato paste", 1.0, "tbsp", AisleCategory::Canned},
        {"fresh basil", 60.0, "ml", AisleCategory::Produce},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Rehydrate TVP in 1 cup hot water or vegetable broth for 10 minutes. Drain.",
        "Finely dice onion, carrot, and celery (soffritto). Saute in olive oil for 7-8 minutes until softened.",
        "Add minced garlic, Italian seasoning, and tomato paste. Cook for 1 minute.",
        "Add rehydrated TVP and cook for 3 minutes. Deglaze with red wine and cook until evaporated.",
        "Add crushed San Marzano tomatoes, salt, and pepper. Simmer for 20-25 minutes until thick.",
        "Cook chickpea pasta according to package directions. Drain.",
        "Toss pasta with the bolognese sauce. Serve topped with nutritional yeast and fresh basil."
    };
    return m;
}

Meal build_meal_42()
{
    Meal m;
    m.id = 42;
    m.name = "Sichuan Mapo Tofu with Edamame";
    m.description = "Extra-firm tofu in fiery doubanjiang-Sichuan peppercorn sauce with edamame over rice";
    m.category = MealCategory::Vegan;
    m.cuisine = "Chinese";
    m.method = "Stir-fried";
    m.protein_grams = 41;
    m.servings = 2;
    m.ingredients = {
        {"extra-firm tofu", 455.0, "g", AisleCategory::Proteins},
        {"edamame, frozen", 480.0, "ml", AisleCategory::Frozen},
        {"brown rice", 240.0, "ml", AisleCategory::Grains},
        {"doubanjiang", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"Sichuan peppercorns", 1.0, "tsp", AisleCategory::PantrySpices},
        {"soy sauce", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"fresh ginger", 1.0, "tbsp", AisleCategory::Produce},
        {"green onion", 3.0, "whole", AisleCategory::Produce},
        {"vegetable broth", 120.0, "ml", AisleCategory::Canned},
        {"cornstarch", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"sesame oil", 1.0, "tsp", AisleCategory::PantrySpices},
        {"vegetable oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"salt", 0.5, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Cook brown rice according to package directions.",
        "Cut extra-firm tofu into 1-inch cubes. Blanch in salted boiling water for 2 minutes. Drain gently.",
        "Heat vegetable oil in a wok over medium heat. Toast Sichuan peppercorns for 1 minute, then add doubanjiang and stir for 30 seconds.",
        "Add minced garlic, ginger, and white parts of green onion. Stir-fry for 1 minute.",
        "Pour in vegetable broth and soy sauce. Bring to a simmer. Gently add tofu cubes and edamame.",
        "Simmer for 5 minutes. Mix cornstarch with 2 tbsp water and stir in to thicken the sauce.",
        "Drizzle with sesame oil and garnish with green onion tops.",
        "Serve over brown rice."
    };
    return m;
}

Meal build_meal_43()
{
    Meal m;
    m.id = 43;
    m.name = "Moroccan Chickpea & Lentil Tagine";
    m.description = "Slow-simmered chickpeas and lentils with ras el hanout, preserved lemon, and almonds";
    m.category = MealCategory::Vegan;
    m.cuisine = "North African";
    m.method = "Simmered";
    m.protein_grams = 37;
    m.servings = 2;
    m.ingredients = {
        {"chickpeas, canned", 480.0, "ml", AisleCategory::Canned},
        {"lentils", 480.0, "ml", AisleCategory::Grains},
        {"almonds", 4.0, "tbsp", AisleCategory::PantrySpices},
        {"onion", 1.0, "whole", AisleCategory::Produce},
        {"garlic cloves", 4.0, "whole", AisleCategory::Produce},
        {"ras el hanout", 2.0, "tsp", AisleCategory::PantrySpices},
        {"preserved lemon", 1.0, "tbsp", AisleCategory::PantrySpices},
        {"crushed tomatoes, canned", 240.0, "ml", AisleCategory::Canned},
        {"carrot", 2.0, "whole", AisleCategory::Produce},
        {"dried apricots", 4.0, "whole", AisleCategory::Produce},
        {"olive oil", 2.0, "tbsp", AisleCategory::PantrySpices},
        {"fresh cilantro", 2.0, "tbsp", AisleCategory::Produce},
        {"couscous", 240.0, "ml", AisleCategory::Grains},
        {"salt", 1.0, "tsp", AisleCategory::PantrySpices},
        {"black pepper", 0.5, "tsp", AisleCategory::PantrySpices},
        {"cinnamon", 0.25, "tsp", AisleCategory::PantrySpices}
    };
    m.steps = {
        "Heat olive oil in a tagine or heavy pot. Saute diced onion for 5 minutes until golden.",
        "Add minced garlic, ras el hanout, cinnamon, salt, and pepper. Cook for 1 minute.",
        "Add diced carrots, rinsed lentils, and crushed tomatoes. Pour in 2 cups water.",
        "Bring to a boil, then reduce to a simmer. Cook for 15 minutes.",
        "Add drained chickpeas, chopped dried apricots, and preserved lemon. Simmer for 15 more minutes until lentils are tender.",
        "Prepare couscous according to package directions.",
        "Toast slivered almonds in a dry pan until golden.",
        "Serve tagine over couscous, topped with toasted almonds and fresh cilantro."
    };
    return m;
}

void build_all_meals(QVector<Meal>& meals)
{
    meals.reserve(TOTAL_MEALS);
    meals.append(build_meal_01());
    meals.append(build_meal_02());
    meals.append(build_meal_03());
    meals.append(build_meal_04());
    meals.append(build_meal_05());
    meals.append(build_meal_06());
    meals.append(build_meal_07());
    meals.append(build_meal_08());
    meals.append(build_meal_09());
    meals.append(build_meal_10());
    meals.append(build_meal_11());
    meals.append(build_meal_12());
    meals.append(build_meal_13());
    meals.append(build_meal_14());
    meals.append(build_meal_15());
    meals.append(build_meal_16());
    meals.append(build_meal_17());
    meals.append(build_meal_18());
    meals.append(build_meal_19());
    meals.append(build_meal_20());
    meals.append(build_meal_21());
    meals.append(build_meal_22());
    meals.append(build_meal_23());
    meals.append(build_meal_24());
    meals.append(build_meal_25());
    meals.append(build_meal_26());
    meals.append(build_meal_27());
    meals.append(build_meal_28());
    meals.append(build_meal_29());
    meals.append(build_meal_30());
    meals.append(build_meal_31());
    meals.append(build_meal_32());
    meals.append(build_meal_33());
    meals.append(build_meal_34());
    meals.append(build_meal_35());
    meals.append(build_meal_36());
    meals.append(build_meal_37());
    meals.append(build_meal_38());
    meals.append(build_meal_39());
    meals.append(build_meal_40());
    meals.append(build_meal_41());
    meals.append(build_meal_42());
    meals.append(build_meal_43());
}

}  // anonymous namespace

MealDatabase::MealDatabase()
{
    build_all_meals(m_meals);
}

const QVector<Meal>& MealDatabase::all_meals() const
{
    return m_meals;
}

const Meal* MealDatabase::meal_by_id(int id) const
{
    for (const auto& meal : m_meals) {
        if (meal.id == id) {
            return &meal;
        }
    }
    return nullptr;
}

QVector<const Meal*> MealDatabase::meals_in_categories(
    const QVector<MealCategory>& categories) const
{
    QVector<const Meal*> result;
    for (const auto& meal : m_meals) {
        for (const auto& cat : categories) {
            if (meal.category == cat) {
                result.append(&meal);
                break;
            }
        }
    }
    return result;
}

}  // namespace mealplan
