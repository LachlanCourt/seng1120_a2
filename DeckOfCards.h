/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;

#ifndef DECKOFCARDS_CLASS
#define DECKOFCARDS_CLASS
#include "Queue.h"
#include "Card.h"

class DeckOfCards
{
	public:
	
		//****Constructors****//
		DeckOfCards();
		DeckOfCards(const bool shuffle);
		//****Destructor****//
		~DeckOfCards();
		
		//****Data manipulation****//
		
		//precondition: Deck must have 52 cards and none of them can be empty
		//postcondition: Cards are in the deck in a random order
		void shuffle();
		//precondition: None (Deck can be empty, it will just return a default blank card if so)
		//postcondition: The top card of the deck is removed and returned
		Card draw();
		//precondition: None
		//postcondition: A card is added to the bottom of the deck
		void addCard(Card& cardToAdd);
		//precondition: None
		//postcondition: Returns the size of the Queue inside the deck
		const int getSize() const;
	private:
		//****Instance variables****//
		Queue<Card> deck;
		
		//****Private methods****//
		
		//precondition: None
		//postcondition: 13 cards from Ace-King are added to the deck with the suit being the string specified
		void addSuit(string suit);
		
	
};

//****Output Operator****//
ostream& operator << (ostream& out, DeckOfCards& temp);

#endif