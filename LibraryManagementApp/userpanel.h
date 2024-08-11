#ifndef USERPANEL_H
#define USERPANEL_H

#include <QDialog>
#include "bookmanager.h"
#include "qlistwidget.h"
#include "activitylist.h"  // Include the header for ActivityList

using namespace std;

namespace Ui {
class UserPanel;
}

class UserPanel : public QDialog
{
    Q_OBJECT

public:
    explicit UserPanel(BookManager bookManager_, BookManager userManager_, string login, QWidget *parent = nullptr);
    ~UserPanel();

private slots:
    void on_btn_clicked();
    void on_listAviableBooks_itemDoubleClicked(QListWidgetItem *item);
    void on_btnAllBooks_clicked();
    void on_btnMyAllBooks_clicked();
    void on_listMyBooks_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::UserPanel *ui;
    BookManager bookManager;
    BookManager userBookManager;
    string user;

};

#endif // USERPANEL_H
