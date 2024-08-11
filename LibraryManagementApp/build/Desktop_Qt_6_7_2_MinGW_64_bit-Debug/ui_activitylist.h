/********************************************************************************
** Form generated from reading UI file 'activitylist.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVITYLIST_H
#define UI_ACTIVITYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_ActivityList
{
public:
    QListWidget *activityList;

    void setupUi(QDialog *ActivityList)
    {
        if (ActivityList->objectName().isEmpty())
            ActivityList->setObjectName("ActivityList");
        ActivityList->resize(559, 361);
        activityList = new QListWidget(ActivityList);
        activityList->setObjectName("activityList");
        activityList->setGeometry(QRect(60, 80, 451, 192));

        retranslateUi(ActivityList);

        QMetaObject::connectSlotsByName(ActivityList);
    } // setupUi

    void retranslateUi(QDialog *ActivityList)
    {
        ActivityList->setWindowTitle(QCoreApplication::translate("ActivityList", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActivityList: public Ui_ActivityList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVITYLIST_H
