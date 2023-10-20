#include "headers/app.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;

    window.setWindowTitle(WINDOW_TITLE);
    window.show();

    return application.exec();
}
