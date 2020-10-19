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
#include "HandOfCards.h"
#include <sstream>

// Constructor
HandOfCards::HandOfCards()
{
	
}

// Destructor
HandOfCards::~HandOfCards()
{
	// The only instance variable is "data" which is stored on the stack
}

// Counts the value of all the face up cards in a hand
const int HandOfCards::count()
{
	// Determine the size of the hand to loop through
	int handSize = getSize();
	Card tempCard;
	int score = 0;
	// Loop through once for each card in the hand
	for (int i = 0; i < handSize; i++)
	{
		// Pick a card from the "top" of the hand (treating it similar to a deck of cards)
		tempCard = draw();
		if (tempCard.getFaceUp())
		{
			// If the card drawn is face up, add the cards value to the score
			score += tempCard.getValue();
		}
		// Add the card into the hand again at the back
		addCard(tempCard);
	}
	// Return the value of the face up cards
	return score;
}

// Counts the value of all the cards in a hand
const int HandOfCards::countAll()
{
	// Determine the size of the hand to loop through
	int handSize = getSize();
	Card tempCard;
	int score = 0;
	// Loop through once for each card in the hand
	for (int i = 0; i < handSize; i++)
	{
		// Pick a card from the "top" of the hand (treating it similar to a deck of cards)
		tempCard = draw();
		// Add the cards value to the score
		score += tempCard.getValue();
		// Add the card into the hand again at the back
		addCard(tempCard);
	}
	// Return the value of the face up cards
	return score;
}

// Returns a printout of all cards in the hand
const string HandOfCards::value()
{
	// Determine the size of the hand to loop through
	int handSize = getSize();
	Card tempCard;
	// Initialise an stringstream to add each card onto
    ostringstream stream;
	// Loop through once for each card in the hand
	for (int i = 0; i < handSize; i++)
	{
		// Pick a card from the "top" of the hand (treating it similar to a deck of cards)
		tempCard = draw();
		if (tempCard.getFaceUp())
		{
			// Add the face of the card onto the stringstream
			stream << tempCard << "	";
		}
		else
		{
			// If the card is face down, print ?-? instead of the face
			stream << "?-?	" << endl << "	";
		}
		// Add the card into the hand again at the back
		addCard(tempCard);
	}
	// Add the score of the hand
	stream << "Score: " << count() << " points" << endl;
	// Convert the stringstream to a string and return
	string str;
	str = stream.str();
	return str;
}

// Turns all cards in the hand face up
void HandOfCards::faceUp()
{
	// Determine the size of the hand to loop through
	int handSize = getSize();
	Card tempCard;
	// Loop through once for each card in the hand
	for (int i = 0; i < handSize; i++)
	{
		// Pick a card from the "top" of the hand (treating it similar to a deck of cards)
		tempCard = draw();
		// Turn the card face up
		tempCard.setFaceUp(true);
		// Add the card into the hand again at the back
		addCard(tempCard);
	}
}

// Adds a card to the hand with a custom faceUp status
void HandOfCards::add(Card cardToAdd, bool faceUp_)
{
	// Sets the faceUp status of the card
	cardToAdd.setFaceUp(faceUp_);
	// Adds the card to the hand
	addCard(cardToAdd);
}

// Returns the size of the hand
const int HandOfCards::getSize() const
{
	return data.getSize();
}

// Adds a card to the hand
void HandOfCards::addCard(const Card &cardToAdd)
{
	// Create a new card object on the heap with the same values as the card given as a reference
    Card* cardToAdd2 = new Card(cardToAdd.getFace(), cardToAdd.getValue(), cardToAdd.getFaceUp());
	// Add the card to the queue
    data.enqueue(cardToAdd2);
	cardToAdd2 = NULL;
}

// Takes a card from the hand
Card HandOfCards::draw()
{
	// Check that the hand is not empty
    if (data.getSize() == 0)
    {
		// If the hand is empty, return an empty card
        Card temp = Card();
        return temp;
    }
	// If the hand is not empty, return the first card in the hand
    return data.dequeue();
}

// Output all the cards in the hand
ostream& operator << (ostream& out, HandOfCards& tempHand)
{
	out << tempHand.value();
	
	return out;
}