#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include "bookmanager.h"
#include "activitylist.h"
#include <QDialog>
#include <QDateTime>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(BookManager bookManager_, std::string login, QDialog *parent = nullptr);
    ~AdminPanel();

private slots:
    void on_btnAddBook_clicked();
    void on_btnShowBooks_clicked();
    void on_btnDelete_clicked();
    void on_btnList_clicked();
    void clearInputFields();
    void showError(const QString &message);

private:
    Ui::AdminPanel *ui;
    BookManager bookManager;
    std::string admin;
    QDateTime currentDateTime();

    // Add a pointer to ActivityList
    ActivityList *activityList = nullptr;
};

#endif // ADMINPANEL_H
