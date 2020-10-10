#include <iostream>
using namespace std;

#ifndef DECKOFCARDS_CLASS
#define DECKOFCARDS_CLASS
#include "Queue.h"
#include "Card.h"

class DeckOfCards
{
	public:
		DeckOfCards();
		DeckOfCards(bool shuffle);
		DeckOfCards(bool shuffle, DeckOfCards& partialDeck);
		~DeckOfCards();
		
		void shuffle();
		Card draw();
		
	private:
		Queue<Card> deck;
		
		void addSuit(string suit);
		void addCard(Card& cardToAdd);
		DeckOfCards* getPartialDeck();
		int getSize();
	
};

#endif