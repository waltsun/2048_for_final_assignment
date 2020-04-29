#include <vector>
#include <ctime>
#include <cstdlib>
#include "gameAPI.h"

using std::vector;

void gameTable::init(){
    m_score = 0;
    memset(m_table,0,sizeof(m_table));
    addRandom2();
    addRandom2();
}

void gameTable::addRandom2(){
    //srand((unsigned)time(NULL));
    int tmp=0;
    for(int i = 0; i < 4 ; ++i){
        for(int j = 0; j < 4; ++j){
            if(m_table[i][j] == 0) ++tmp;
        }
    }
    int add = rand() % tmp + 1;
    for(int i = 0; i < 4 ; ++i){
        for(int j = 0; j < 4; ++j){
            if(m_table[i][j] == 0) --add;
            if(add == 0){
                m_table[i][j] = 2;
                return;
            }
        }
    }
}

bool gameTable::isMovable(){
    if(isMovable(up)) return true;
    if(isMovable(down)) return true;
    if(isMovable(left)) return true;
    if(isMovable(right)) return true;
    return false;
}

bool gameTable::isMovable(direction dir){
    if(dir == up){
        for(int i = 0; i < 4; ++i){
            vector<int> tmp;
            for(int j = 0; j < 4; ++j) if(m_table[i][j] != 0) tmp.push_back(j);
            int siz = tmp.size();
            if( siz == 0 ) continue;
            if( tmp[siz - 1] != siz - 1) return true;
            for(int k = 0; k < siz - 1; ++k){
                if( m_table[i][tmp[k]] == m_table[i][tmp[k+1]] ) return true;
            }
        }
    }
    else if( dir == down ){
        for(int i = 0; i < 4; ++i){
            vector<int> tmp;
            for(int j = 3; j >= 0; --j) if(m_table[i][j] != 0) tmp.push_back(j);
            int siz = tmp.size();
            if( siz == 0 ) continue;
            if( tmp[siz - 1] != 4 - siz ) return true;
            for(int k = 0; k < siz - 1; ++k){
                if( m_table[i][tmp[k]] == m_table[i][tmp[k+1]] ) return true;
            }
        }
    }
    else if(dir == left){
        for(int j = 0; j < 4; ++j){
            vector<int> tmp;
            for(int i = 0; i < 4; ++i) if(m_table[i][j] != 0) tmp.push_back(i);
            int siz = tmp.size();
            if( siz == 0 ) continue;
            if( tmp[siz - 1] != siz - 1) return true;
            for(int k = 0; k < siz - 1; ++k){
                if( m_table[tmp[k]][j] == m_table[tmp[k+1]][j] ) return true;
            }
        }
    }
    else if( dir == right ){
        for(int j = 0; j < 4; ++j){
            vector<int> tmp;
            for(int i = 3; i >= 0; --i) if(m_table[i][j] != 0) tmp.push_back(i);
            int siz = tmp.size();
            if( siz == 0 ) continue;
            if( tmp[siz - 1] != 4 - siz ) return true;
            for(int k = 0; k < siz - 1; ++k){
                if( m_table[tmp[k]][j] == m_table[tmp[k+1]][j] ) return true;
            }
        }
    }
    return false;
}

void gameTable::move(direction dir){
    if(dir == up){
        for(int i = 0; i < 4; ++i){
            vector<int> tmp,ret;
            for(int j = 0; j < 4; ++j){
                if(m_table[i][j] != 0) tmp.push_back(m_table[i][j]);
                m_table[i][j] = 0;
            }
            int siz = tmp.size();
            for(int k = 0; k < siz; ++k){
                if( k == siz - 1 ) ret.push_back(tmp[k]);
                else if( tmp[k] == tmp[k+1] ) ret.push_back(tmp[k++]<<1),m_score+=tmp[k]<<1;
                else ret.push_back(tmp[k]);
            }
            siz = ret.size();
            for(int k = 0; k < siz; ++k) m_table[i][k] = ret[k];
        }
    }
    else if( dir == down ){
        for(int i = 0; i < 4; ++i){
            vector<int> tmp,ret;
            for(int j = 3; j >= 0; --j){
                if(m_table[i][j] != 0) tmp.push_back(m_table[i][j]);
                m_table[i][j] = 0;
            }
            int siz = tmp.size();
            for(int k = 0; k < siz; ++k){
                if( k == siz - 1 ) ret.push_back(tmp[k]);
                else if( tmp[k] == tmp[k+1] ) ret.push_back(tmp[k++]<<1),m_score+=tmp[k]<<1;
                else ret.push_back(tmp[k]);
            }
            siz = ret.size();
            for(int k = 0; k < siz; ++k) m_table[i][3-k] = ret[k];
        }
    }
    else if(dir == left){
        for(int j = 0; j < 4; ++j){
            vector<int> tmp,ret;
            for(int i = 0; i < 4; ++i){
                if(m_table[i][j] != 0) tmp.push_back(m_table[i][j]);
                m_table[i][j] = 0;
            }
            int siz = tmp.size();
            for(int k = 0; k < siz; ++k){
                if( k == siz - 1 ) ret.push_back(tmp[k]);
                else if( tmp[k] == tmp[k+1] ) ret.push_back(tmp[k++]<<1),m_score+=tmp[k]<<1;
                else ret.push_back(tmp[k]);
            }
            siz = ret.size();
            for(int k = 0; k < siz; ++k) m_table[k][j] = ret[k];
        }
    }
    else if( dir == right ){
        for(int j = 0; j < 4; ++j){
            vector<int> tmp,ret;
            for(int i = 3; i >= 0; --i){
                if(m_table[i][j] != 0) tmp.push_back(m_table[i][j]);
                m_table[i][j] = 0;
            }
            int siz = tmp.size();
            for(int k = 0; k < siz; ++k){
                if( k == siz - 1 ) ret.push_back(tmp[k]);
                else if( tmp[k] == tmp[k+1] ) ret.push_back(tmp[k++]<<1),m_score+=tmp[k]<<1;
                else ret.push_back(tmp[k]);
            }
            siz = ret.size();
            for(int k = 0; k < siz; ++k) m_table[3-k][j] = ret[k];
        }
    }
}
