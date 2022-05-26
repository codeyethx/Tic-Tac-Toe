/*
 * Description: Program that allows user to play Tic Tac Toe
 * @file: players.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: June 10, 2021
 */
#include "board.h"
#include "players.h"
#include <ncurses.h>
#include <iostream>

using namespace std;

/**
 * Adds color from ncurses library to the game
 */
void add_color(){
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    addstr("CONGRATULATIONS, YOU WON!");
    attroff(COLOR_PAIR(1));
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    attron(COLOR_PAIR(2));
    addstr("\nPRESS ENTER TO EXIT");
    attroff(COLOR_PAIR(2));
    refresh();
    getch();
    endwin();
}

/**
 * Adds another color from ncurses library to the game
 */
void add_color2() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    attron(COLOR_PAIR(1));
    addstr("Uh oh, computer won. Try again next time!");
    attroff(COLOR_PAIR(1));
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    attron(COLOR_PAIR(2));
    addstr("\nPRESS ENTER TO EXIT");
    attroff(COLOR_PAIR(2));
    refresh();
    getch();
    endwin();
}

/**
 * Allows user to play the game
 */
void Player::play() {
    while (valid()) {
        draw();
        playermove();
        if (checkwin('X') == 'X') {
            draw();
            add_color();
            break;
        }
        draw();
        computermove();
        if (checkwin('R') == 'R') {
            draw();
            add_color2();
            break;
        }
    }
}
