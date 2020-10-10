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
		DeckOfCards(bool output, DeckOfCards& partialDeck);
		~DeckOfCards();
		
		void shuffle();
		Card draw();
		
		void addCard(Card& cardToAdd);
	private:
		Queue<Card> deck;
		
		void addSuit(string suit);
		DeckOfCards* getPartialDeck();
		int getSize();
	
};

ostream& operator << (ostream& out, DeckOfCards& temp);

#endif