#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include "bookmanager.h"
#include <QDialog>
#include <QListWidget>

namespace Ui {
class ActivityList;
}

class ActivityList : public QDialog
{
    Q_OBJECT

public:
    ActivityList(BookManager bookManager_, QWidget *parent = nullptr);
    ~ActivityList();

    static void addToList(const QString& text);

private:
    static QListWidget* activityListWidget;
    Ui::ActivityList *ui;
    BookManager bookManager;
};

#endif // ACTIVITYLIST_H
