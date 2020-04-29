#include "gamewindow.h"
#include "gameAPI.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    QApplication a(argc, argv);
    gameWindow *win = new gameWindow;
    //QObject::connect(win->tmp_f(),SIGNAL(pressed()),win,SLOT(grestart()));
    return a.exec();
}
