#include "bookmanager.h"
#include "adminpanel.h"
#include "welcome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome w;
    w.show();
    return a.exec();
}
