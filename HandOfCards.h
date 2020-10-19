/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;
#include "Queue.h"
#include "Card.h"

#ifndef HANDOFCARDS_CLASS
#define HANDOFCARDS_CLASS

//cd /cygdrive/C/Users/lachl/OneDrive/Documents/Uni/SENG1120_Assessment/Assignment2

class HandOfCards
{
	public:
		//****Constructor****//
		HandOfCards();
		//****Destructor****//
		~HandOfCards();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Returns the score of all cards in the hand where faceUp is true
		const int count();
		//precondition: None
		//postcondition: Returns the score of all cards in the hand
		const int countAll();
		//precondition: None
		//postcondition: Returns the cards in readable form, cards where faceUp is false show up as "?-?"
		const string value();
		
		//****Data manipulation****//
		
		//precondition: None
		//postcondition: All cards in the hand will have their faceUp value changed to true
		void faceUp();
		//precondition: None
		//postcondition: Card will be added to the hand with the faceUp value matching the argument
		void add(const Card cardToAdd, const bool faceUp_);
		
		
	
	private:
		//****Instance variables****//
		Queue<Card> data;
		
		//****Private methods****//
		
		//precondition: None
		//postcondition: Returns the number of cards in the hand
		const int getSize() const;
		//precondition: None
		//postcondition: Card will be added to the hand
		void addCard(const Card &cardToAdd);
		//precondition: None (Hand can be empty, it will just return a default blank card if so)
		//postcondition: The top card of the hand is removed and returned
		Card draw();
		
		
};

//****Output Operator****//
ostream& operator << (ostream& out, HandOfCards& temp);

#endif