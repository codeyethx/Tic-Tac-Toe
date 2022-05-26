/*
 * Description: Program that allows user to play Tic Tac Toe
 * @file: main.cpp
 * @name: Gift Chidera Uwakwe
 * @collaborators
 * @date: June 10, 2021
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "board.h"
#include "players.h"

using namespace std;

/**
 * Controls main function of the game
 */
int main() {
    string name;
    cout << endl << "What's your name: ";
    cin >> name;
    cout << endl << "Nice to meet you, "<< name << ". Welcome to Tic Tac Toe!" << endl;
    Player game;
    game.play();
    return 0;
};
