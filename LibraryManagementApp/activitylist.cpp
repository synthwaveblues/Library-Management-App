#include "activitylist.h"
#include "ui_activitylist.h"

// Define the static member
QListWidget* ActivityList::activityListWidget = nullptr;

ActivityList::ActivityList(BookManager bookManager_, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ActivityList)
    , bookManager(bookManager_)
{
    ui->setupUi(this);
    activityListWidget = ui->activityList;
}

ActivityList::~ActivityList()
{
    delete ui;
}

void ActivityList::addToList(const QString& text)
{
    // Ensure that the widget is initialized before using it
    if (activityListWidget) {
        activityListWidget->addItem(text);
    } else {
        qWarning() << "Activity list widget is not initialized.";
    }
}
