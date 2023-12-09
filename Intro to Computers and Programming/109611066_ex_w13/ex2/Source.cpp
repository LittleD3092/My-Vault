#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "struct.h"

char faceNames[13][6] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
char suitNames[4][9] = { "Clubs", "Diamonds", "Hearts", "Spades"};

int main() {
    Card player1;
    Card player2;
    DeckOfCards cards;

    construct(&cards);
    shuffle(&cards);

    player1 = cards.desk[0];
    player2 = cards.desk[1];

    printf("Player1: %s %s\n", faceNames[player1.face], suitNames[player1.suit]);
    printf("Player2: %s %s\n", faceNames[player2.face], suitNames[player2.suit]);

    if (compare(player1, player2)){
        printf("Player1 Win !!!\n");
    }
    else {
        printf("Player2 Win !!!\n");
    }
}