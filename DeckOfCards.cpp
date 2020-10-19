/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>

using namespace std;

#include "DeckOfCards.h"
#include "Queue.h"
#include "Card.h"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>


// Default Constructor, creates deck with 52 cards
DeckOfCards::DeckOfCards()
{
    addSuit("H");
    addSuit("C");
    addSuit("S");
    addSuit("D");
}

// Constructor, creates deck with no cards
DeckOfCards::DeckOfCards(bool shuffle)
{
	
}

// Destructor
DeckOfCards::~DeckOfCards()
{
	// The only instance variable is "deck" which is stored on the stack
}

// Shuffle a 52 card deck into a random order
void DeckOfCards::shuffle()
{
	//---- Split decks ----
	
	// Initialise 4 temporary DeckOfCards objects and a temporary Card object on the stack
    DeckOfCards tempDeck1 = DeckOfCards(true);
    DeckOfCards tempDeck2 = DeckOfCards(true);
    DeckOfCards tempDeck3 = DeckOfCards(true);
    DeckOfCards tempDeck4 = DeckOfCards(true);
    Card tempCard;
	
	// Loop 13 times and each time add one card each from the deck into the 4 DeckOfCards
    for (int i = 0; i < 13; i++)
    {
		// Draw a card from the main deck
        tempCard = draw();
		// Add the card to the first temp deck
        tempDeck1.addCard(tempCard);
		// Draw a card from the main deck
        tempCard = draw();
		// Add the card to the second temp deck
        tempDeck2.addCard(tempCard);
        tempCard = draw();
        tempDeck3.addCard(tempCard);
        tempCard = draw();
        tempDeck4.addCard(tempCard);
    }
	//---- Shuffle cards ----

	// Initialise a random number generation with a random seed based on the current computer time to ensure each game is different
    int rand(void);
	srand(time(NULL));
	int randDeck;
	// Repeat the shuffle 1000 times
    for (int i = 0; i < 1000; i++)
    {
		// Pick a random number between 0 and 3
		randDeck = rand() % 4;
		switch(randDeck)
		{
			// Depending on what number was picked, draw a card from a different temp deck
			case 0:
				tempCard = tempDeck1.draw();
				break;
			case 1:
				tempCard = tempDeck2.draw();
				break;
			case 2:
				tempCard = tempDeck3.draw();
				break;
			default:
				tempCard = tempDeck4.draw();
		}

		/*
		If the deck that the card was drawn from was empty, tempCard will be a Card made with the default constructor. In this
		case, the value will be -1. Check for this and if so, restart the for loop to pick a new deck to draw from.
		*/
        if (tempCard.getValue() == -1)
        {
            continue;
        }
		
		// Pick a random number between 0 and 3
		randDeck = rand() % 4;
		switch(randDeck)
		{
			// Depending on what number was picked, add the card back to a different temp deck
			case 0:
				tempDeck1.addCard(tempCard);
				break;
			case 1:
				tempDeck2.addCard(tempCard);
				break;
			case 2:
				tempDeck3.addCard(tempCard);
				break;
			default:
				tempDeck4.addCard(tempCard);
		}
    }

	//---- Reassemble decks ----
    
	// Check the size of the first temp deck and loop through the relevant number of times
    int size = tempDeck1.getSize();
    for (int j = 0; j < size; j++)
    {
		// Draw a card from the temp deck
        tempCard = tempDeck1.draw();
		// Add it back onto the main deck
        addCard(tempCard);
    }
	// Repeat for the other 3 temp decks
	size = tempDeck2.getSize();
    for (int j = 0; j < size; j++)
    {
        tempCard = tempDeck2.draw();
        addCard(tempCard);
    }
	size = tempDeck3.getSize();
    for (int j = 0; j < size; j++)
    {
        tempCard = tempDeck3.draw();
        addCard(tempCard);
    }
	size = tempDeck4.getSize();
    for (int j = 0; j < size; j++)
    {
        tempCard = tempDeck4.draw();
        addCard(tempCard);
    }
}

// Removes a card from the top of the deck
Card DeckOfCards::draw()
{
	// Check if the deck is empty
    if (deck.getSize() == 0)
    {
		// If it is empty, return a blank card
        Card temp = Card();
        return temp;
    }
	// If it is not empty, remove and return the top card off the deck
    return deck.dequeue();
}

// Adds a card to the bottom of the deck
void DeckOfCards::addCard(Card &cardToAdd)
{
	// Create a new card object with the same data as the one that was parsed as an argument
    Card* cardToAdd2 = new Card(cardToAdd.getFace(), cardToAdd.getValue(), cardToAdd.getFaceUp());
	// Add new card object to the bottom of the deck
    deck.enqueue(cardToAdd2);
	cardToAdd2 = NULL;
}

// Adds a single suit of cards to the deck
void DeckOfCards::addSuit(string suit)
{
    string face;
    Card* temp;
	// Loop through the numbers 2-10 for the numerical cards
    for (int i = 2; i <= 10; i++)
    {
        string str;
		// Declare a stringstream to convert int to str
        ostringstream stream;
		// Add the number onto the stream
        stream << i;
		// Convert to str
        str = stream.str();

		// Add the suit to the number
        face = str + "-" + suit;
		// Create a new card with the specified data
        temp = new Card(face, i, false);
		// Add new card to deck
        deck.enqueue(temp);
    }
	// Fact cards completed manually with a flat value
    face = "J-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "Q-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "K-" + suit;
    temp = new Card(face, 10, false);
    deck.enqueue(temp);

    face = "A-" + suit;
    temp = new Card(face, 11, false);
    deck.enqueue(temp);
	temp = NULL;
}

// Returns the size of the queue
const int DeckOfCards::getSize() const
{
    return deck.getSize();
}

// Outputs all the cards in the deck in order
ostream& operator << (ostream& out, DeckOfCards& temp)
{	
	// Get the size of the deck
	int deckSize = temp.getSize();
	Card tempCard;
	out << endl;
	// Loop through all cards in the deck
	for (int i = 0; i < deckSize; i++)
	{	
		// Draw a card from the top of the deck
		tempCard = temp.draw();
		// Output the face of the card 
		out << tempCard;
		// Add the card into the deck again at the bottom
		temp.addCard(tempCard);
	}
	return out;
	
}