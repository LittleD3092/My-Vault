#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct __Card {
    int face;
	int suit;
} Card;

typedef struct __DeckOfCards {
    Card* desk;
	int currentCard;
} DeckOfCards;

void construct(DeckOfCards *deck);
void shuffle(DeckOfCards *deck);
int compare(Card player1, Card player2);

#endif // __STRUCT_H__