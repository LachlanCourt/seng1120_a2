#include <iostream>
using namespace std;
#include "Queue.h"
#include "Card.h"

#ifndef HANDOFCARDS_CLASS
#define HANDOFCARDS_CLASS

class HandOfCards
{
	public:
		HandOfCards();
		
		int count();
		int countAll();
		string value();
		void faceUp();
		void add(Card cardToAdd, bool faceUp_);
		
		
	
	private:
		Queue<Card> data;
		
		int getSize();
		void addCard(Card &cardToAdd);
		Card draw();
		
		
};

ostream& operator << (ostream& out, HandOfCards& temp);

#endif