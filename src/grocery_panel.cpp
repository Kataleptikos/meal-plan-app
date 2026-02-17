#include "grocery_panel.h"

#include <QHeaderView>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

namespace mealplan {

GroceryPanel::GroceryPanel(
    const QMap<AisleCategory, QVector<GroceryItem>>& groceries,
    QWidget* parent)
    : QWidget(parent)
{
    setup_ui(groceries);
}

void GroceryPanel::setup_ui(
    const QMap<AisleCategory, QVector<GroceryItem>>& groceries)
{
    auto* layout = new QVBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);

    auto* tree = new QTreeWidget(this);
    tree->setHeaderLabels({"Item", "Quantity", "Unit"});
    tree->setRootIsDecorated(true);
    tree->setAlternatingRowColors(true);
    tree->setStyleSheet(
        "QTreeWidget {"
        "  font-size: 12px;"
        "  color: palette(text);"
        "  border: 1px solid palette(mid);"
        "  border-radius: 4px;"
        "}"
        "QTreeWidget::item {"
        "  padding: 3px 0px;"
        "}"
        "QHeaderView::section {"
        "  color: palette(text);"
        "}");

    // Set column widths
    tree->header()->setStretchLastSection(false);
    tree->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    tree->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tree->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    for (auto it = groceries.constBegin();
         it != groceries.constEnd(); ++it) {

        // Aisle category as top-level item
        auto* aisle_item = new QTreeWidgetItem(tree);
        aisle_item->setText(0, aisle_display_name(it.key()));
        aisle_item->setExpanded(true);

        // Make the aisle header bold
        QFont bold_font = aisle_item->font(0);
        bold_font.setBold(true);
        bold_font.setPointSize(bold_font.pointSize() + 1);
        aisle_item->setFont(0, bold_font);

        // Item count in the quantity column
        aisle_item->setText(
            1, QString("(%1 items)").arg(it.value().size()));

        // Add grocery items as children
        for (const GroceryItem& item : it.value()) {
            auto* child = new QTreeWidgetItem(aisle_item);
            child->setText(0, item.name);
            child->setText(1, format_quantity(item.quantity));
            child->setText(2, item.unit);
        }
    }

    layout->addWidget(tree);
}

}  // namespace mealplan
