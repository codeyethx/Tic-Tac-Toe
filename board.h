#ifndef BOARD_H
#define BOARD_H

const int ROWS = 3;
const int COLUMNS = 3;

class Board {
protected:
    char board[ROWS][COLUMNS];
public:
    Board();
    virtual void play() = 0;
    void computermove();
    void playermove();
    void draw();
    void set(int row, int col, char symbol);
    char get(int row, int col);
    bool is_horizontal(int row, char sym);
    bool is_vertical(int col, char sym);
    bool is_diagonal(char sym);
    char checkwin(char symbol);
    bool valid();
};

#endif //Board.h
