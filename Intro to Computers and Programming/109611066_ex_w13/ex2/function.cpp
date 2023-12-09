#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void construct(DeckOfCards *deck) {
    deck->currentCard = 0;
    deck->desk = (Card*)malloc(sizeof(Card) * 52);
    for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck->desk[i * 13 + j].suit = i;
            deck->desk[i * 13 + j].face = j;
            deck->currentCard++;
		}
	}
}

void shuffle(DeckOfCards *deck) {
    // TODO
    srand(time(NULL));
    for(int i = 0; i < 52; i++)
    {
        int chooseIndex = rand() % (52 - i);
        Card temp = deck->desk[i];
        deck->desk[i] = deck->desk[i + chooseIndex];
        deck->desk[i + chooseIndex] = temp;
    }
}

int compare(Card player1, Card player2) {
    // TODO
    if(player1.face > player2.face)
        return 1;
    else if(player2.face > player1.face)
        return 0;
    
    if(player1.suit > player2.suit)
        return 1;
    else if(player2.suit > player1.suit)
        return 0;

    return -1;
}