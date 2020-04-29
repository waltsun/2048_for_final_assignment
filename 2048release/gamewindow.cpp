#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <string>
#include <cstdio>
using std::string;

gameWindow::gameWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameWindow)
    , m_table(new gameTable)
    , m_scoreLbl(new QLabel(this))
    , m_restartBtn(new QPushButton("Press me to restart.",this))
{
    ui->setupUi(this);
    this->setFixedSize(1000,500);
    this->setWindowTitle("2048 by kirakiradokidoki");
    m_restartBtn->move(300,10);
    m_restartBtn->resize(300,30);
    bool tmp=connect(m_restartBtn,&QPushButton::clicked,this,&gameWindow::restart);
    setFocus();
    m_restartBtn->setEnabled(true);
    m_restartBtn->show();
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4 ; ++j){
            m_lbl[i][j] = new QLabel(this);
            m_lbl[i][j]->move(150+i*200,100+j*50);
            m_lbl[i][j]->resize(200,50);
            m_lbl[i][j]->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            m_lbl[i][j]->setAlignment(Qt::AlignBottom | Qt::AlignRight);
        }
    }
    m_scoreLbl->move(300,100);
    //m_scoreLbl->resize(50,30);
    m_scoreLbl->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_scoreLbl->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    showTable();
    changeScore();
    grabKeyboard();
    this->show();
}

gameWindow::~gameWindow()
{
    delete ui;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            delete m_lbl[i][j];
        }
    }
    delete m_scoreLbl;
    delete m_table;
    delete m_restartBtn;
}

void gameWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up){
        if(m_table->isMovable(up)) move(up);
    }
    else if(event->key() == Qt::Key_Down){
        if(m_table->isMovable(down)) move(down);
    }
    else if(event->key() == Qt::Key_Left){
        if(m_table->isMovable(left)) move(left);
    }
    else if(event->key() == Qt::Key_Right){
        if(m_table->isMovable(right)) move(right);
    }
}

void gameWindow::showTable(){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            char s[50];
            sprintf(s,"%d",m_table->getTable(i,j));
            m_lbl[i][j]->setText(s);
            m_lbl[i][j]->update();
        }
    }
}

void gameWindow::changeScore(){
    char s[50];
    sprintf(s,"score: %d",m_table->getScore());
    m_scoreLbl->setText(s);
    m_scoreLbl->adjustSize();
    m_scoreLbl->update();
}

void gameWindow::restart(){
    m_table->init();
    showTable();
    changeScore();
}

void gameWindow::fail(){
    m_failLbl = new QLabel(this);
    m_failLbl->setText("You failed.");
    m_failLbl->move(500,200);
    //m_failLbl->show();
    this->update();
}

void gameWindow::move(direction dir){
    if(m_table->isMovable(dir)){
        m_table->move(dir);
        m_table->addRandom2();
        showTable();
        changeScore();
    }
    if(m_table->isMovable() == false) fail();
}
