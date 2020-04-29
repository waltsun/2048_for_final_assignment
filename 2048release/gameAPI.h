#ifndef GAMEAPI_H
#define GAMEAPI_H

enum direction {up, down, left, right};

class gameTable{
private:
    int m_table[4][4];
    int m_score;
public:
    gameTable() {init();}
    ~gameTable() {}
    void init();
    void addRandom2();
    bool isMovable();
    bool isMovable(direction dir);
    void move(direction dir);
    int getScore() {return m_score;}
    int getTable(int x, int y) {return m_table[x][y];}
};

#endif // GAMEAPI_H
