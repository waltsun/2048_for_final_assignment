#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include "gameAPI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gameWindow; }
QT_END_NAMESPACE

class gameTable;

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    gameWindow(QWidget *parent = nullptr);
    ~gameWindow();
    void keyPressEvent(QKeyEvent *event);
    void showTable();
    void changeScore();
    void move(direction dir);
    void fail();
    QPushButton *tmp_f(){return m_restartBtn;}
private:
    Ui::gameWindow *ui;
    gameTable *m_table;
    QLabel *m_lbl[4][4];
    QLabel *m_scoreLbl, *m_failLbl;
    QPushButton *m_restartBtn;

public slots:
    void restart();
};
#endif // GAMEWINDOW_H
