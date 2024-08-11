#include "welcome.h"
#include "ui_welcome.h"
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <QInputDialog>
#include <QFormLayout>
#include <QDateTime>
#include "activitylist.h"

string booksDirectory = "C:/Users/shevc/Documents/QT_Project/LibraryManagementApp/books.txt";
string usersBooksDirectory = "C:/Users/shevc/Documents/QT_Project/LibraryManagementApp/usersBooks.txt";
string adminsDirectory = "C:/Users/shevc/Documents/QT_Project/LibraryManagementApp/admins.txt";
string usersDirectory = "C:/Users/shevc/Documents/QT_Project/LibraryManagementApp/users.txt";

Welcome::Welcome(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Welcome)
    , bookManager(booksDirectory)
    , userManager(usersBooksDirectory)
{
    ui->setupUi(this);

    // Initialize the ActivityList object
    activityList = new ActivityList(bookManager, this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(datetime()));
    timer->start();

    readFile(adminsDirectory, admins);
    readFile(usersDirectory, users);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::readFile(const std::string& filename, std::map<std::string, std::string>& map)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to open admins file: " + QString::fromStdString(filename));
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password;
        if (std::getline(iss, username, ',') && std::getline(iss, password)) {
            map[username] = password;
        }
    }

    file.close();
}

void Welcome::writeFile(const std::string& filename, const std::map<std::string, std::string>& map)
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for writing: " + QString::fromStdString(filename));
        return;
    }

    for (const auto& pair : map) {
        file << pair.first << "," << pair.second << "\n";
    }

    file.close();
}

void Welcome::on_btnAdmin_clicked()
{
    std::string login = ui->txtLogin->text().toStdString();
    std::string password = ui->txtPassword->text().toStdString();

    if (login.empty() || password.empty()) {
        QMessageBox::critical(nullptr, "Error", "Please provide both login and password.");
        return;
    }

    // Check against admins
    auto it = admins.find(login);
    if (it != admins.end() && it->second == password) {
        this->hide();
        AdminPanel adminPanel(bookManager, login);
        adminPanel.setModal(true);
        adminPanel.exec();
        ui->txtLogin->clear();
        ui->txtPassword->clear();
        // Log the admin login activity
        activityList->addToList(QString::fromStdString("Admin " + login + " logged in at " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString()));

        this->show();
    } else {
        QMessageBox::critical(nullptr, "Error", "Invalid login or password.");
    }
}

void Welcome::on_btnUser_clicked()
{
    std::string login = ui->txtLogin->text().toStdString();
    std::string password = ui->txtPassword->text().toStdString();

    if (login.empty() || password.empty()) {
        QMessageBox::critical(nullptr, "Error", "Please provide both login and password.");
        return;
    }

    // Check against users
    auto it = users.find(login);
    if (it != users.end() && it->second == password) {
        this->hide();
        UserPanel userPanel(bookManager, userManager, login);
        userPanel.setModal(true);
        userPanel.exec();
        ui->txtLogin->clear();
        ui->txtPassword->clear();
        this->show();
    } else {
        QMessageBox::critical(nullptr, "Error", "Invalid login or password.");
    }
}

void Welcome::on_btnCreate_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Create User");

    QFormLayout form(&dialog);

    // Username input field
    QLineEdit usernameEdit;
    form.addRow("Username:", &usernameEdit);

    // Password input field
    QLineEdit passwordEdit;
    passwordEdit.setEchoMode(QLineEdit::Password);
    form.addRow("Password:", &passwordEdit);

    // Buttons
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString username = usernameEdit.text();
        QString password = passwordEdit.text();

        if (username.isEmpty()) {
            QMessageBox::critical(nullptr, "Error", "Username cannot be empty.");
            return;
        }

        if (password.isEmpty()) {
            QMessageBox::critical(nullptr, "Error", "Password cannot be empty.");
            return;
        }

        std::string user = username.toStdString();
        std::string pass = password.toStdString();

        if (users.find(user) != users.end()) {
            QMessageBox::critical(nullptr, "Error", "Username already exists.");
            return;
        }

        users[user] = pass;
        writeFile("C:/Users/shevc/Documents/QT_Project/untitled/users.txt", users);
        QMessageBox::information(nullptr, "Success", "User account created successfully.");
    }
}

void Welcome::datetime()
{
    QDateTime current = QDateTime::currentDateTime();
    QString datetime_text = current.toString("yyyy-MM-dd hh:mm:ss");
    ui->lbl_time->setText(datetime_text);
}
