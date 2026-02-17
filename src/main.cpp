#include <QApplication>

#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Meal Plan Generator");
    app.setOrganizationName("MealPlanApp");

    mealplan::MainWindow window;
    window.setWindowTitle("Weekly Meal Plan Generator");
    window.resize(1100, 800);
    window.show();

    return app.exec();
}
