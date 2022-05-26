/*
 * Description: Program that allows user to play Tic Tac Toe
 * @file: board.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: June 10, 2021
 */
#include "board.h"
#include "players.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

/**
 * Constructor for Board class
 */
Board::Board() {
    for (int row = 0; row  < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
             board[row][col] = '0';
        }
    }
}

/**
 * Draws the grid for the game
 */
void Board::draw() {
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t-----|-----|-----" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t-----|-----|-----" << endl;
    cout << "\t     |     |     " << endl;
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "\t     |     |     " << endl;
}

/**
 * Sets the data stored at the given index to a symbol
 * @param row is the number of rows
 * @param col is the number of COLUMNS
 * @param symbol is letter that user is assigned
 */
void Board::set(int row, int col, char symbol) {
    board[row][col] = symbol;
}

/**
 * Gets the data stored at index
 * @param row is the number of rows
 * @param col is the number of COLUMNS
 * @return the placement of symbol
 */
char Board::get(int row, int col) {
    return board[row][col];
}

/**
 * Checks if horizonatally there is a winner
 * @param row is the number of rows
 * @param symbol is letter that user is assigned
 * @return the win if horizontal
 */
bool Board::is_horizontal(int row, char sym) {
    for (int col = 0; col < COLUMNS; col++) {
        if (sym != board[row][col])
            return false;
    }
    return true;
}

/**
 * Checks if vertically there is a winner
 * @param row is the number of rows
 * @param symbol is letter that user is assigned
 * @return the win if vertical
 */
bool Board::is_vertical(int col, char sym) {
    for (int row = 0; row < ROWS; row++) {
        if (sym != board[row][col])
            return false;
    }
    return true;
}

/**
 * Checks if diagonally there is a winner
 * @param symbol is letter that user is assigned
 * @return the win if diagonal
 */
bool Board::is_diagonal(char sym) {
    bool ascending = sym == board[0][0] &&
    sym == board[1][1] && sym == board[2][2];
    bool descending = sym == board[2][0] &&
    sym == board[1][1] && sym == board[0][2];
    if (ascending || descending)
        return true;
    else
        return false;
}

/**
 * Checks if there is a win
 * @param symbol is letter that user is assigned
 * @return the win if there is any
 */
char Board::checkwin(char symbol) {
    if (is_diagonal(symbol))
        return symbol;
    for (int index= 0; index < ROWS; index++) {
        if (is_horizontal(index, symbol))
            return symbol;
        else if (is_vertical(index, symbol))
            return symbol;
    }
    return '0';
}

/**
 * Checks if game should continue
 * @return if game is still valid
 */
bool Board::valid() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            if (board[row][col] == '0') {
                return true;
            }
        }
    }
    return false;
}

/**
 * Allows computer to play after user has played
 */
void Board::computermove() {
    if (valid()) {
        cout << endl << "Computer is thinking..." << endl;
        srand(time(0));
        int row = rand() % 3, column = rand() % 3;
        while (board[row][column] != '0') {
            row = rand() % 3, column = rand() % 3;
        }
        board[row][column] = 'R';
    }
}

/**
 * Allows user to input postion to play
 */
void Board::playermove() {
    int row = 0, column = 0;
    cout << endl << "Make a Move :)" << endl;
    cout << endl << "Enter Row Coordinate: ";
    cin >> row;
    cout << endl << "Enter Column Coordinate: ";
    cin >> column;
    while (board[row][column] != '0') {
        cout << "Sorry, try again." << endl;
        cout << "Enter Row Coordinate: ";
        cin >> row;
        cout << "Enter Column Coordinate: ";
        cin >> column;
    }
    board[row][column] = 'X';
}
