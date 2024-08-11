#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "adminpanel.h"
#include "userpanel.h"
#include "bookmanager.h"
#include <map>
#include <QTimer>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_btnAdmin_clicked();
    void on_btnUser_clicked();
    void on_btnCreate_clicked();
    void datetime();

private:
    Ui::Welcome *ui;
    BookManager bookManager;
    BookManager userManager;
    std::map<std::string, std::string> admins;
    std::map<std::string, std::string> users;
    QTimer* timer;

    // Declare ActivityList object
    ActivityList* activityList;

    void readFile(const std::string& filename, std::map<std::string, std::string>& map);
    void writeFile(const std::string& filename, const std::map<std::string, std::string>& map);
};

#endif // WELCOME_H
