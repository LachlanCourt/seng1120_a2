#include <iostream>
using namespace std;
#include "Queue.h"
#include "Card.h"
#include "HandOfCards.h"
#include <sstream>

HandOfCards::HandOfCards()
{
	
}
		
int HandOfCards::count()
{
	int handSize = getSize();
	Card tempCard;
	int score = 0;
	for (int i = 0; i < handSize; i++)
	{
		tempCard = draw();
		if (tempCard.getFaceUp())
		{
			score += tempCard.getValue();
		}
		addCard(tempCard);
	}
	return score;
}
int HandOfCards::countAll()
{
	int handSize = getSize();
	Card tempCard;
	int score = 0;
	for (int i = 0; i < handSize; i++)
	{
		tempCard = draw();
		score += tempCard.getValue();
		addCard(tempCard);
	}
	return score;
}
string HandOfCards::value()
{
	int handSize = getSize();
	Card tempCard;
    ostringstream stream;
	
	for (int i = 0; i < handSize; i++)
	{
		tempCard = draw();
		if (tempCard.getFaceUp())
		{
			stream << tempCard << "	";
		}
		else
		{
			stream << "?-?	";
		}
		addCard(tempCard);
	}
	string str;
	str = stream.str();
	return str;
}

void HandOfCards::faceUp()
{
	int handSize = getSize();
	Card tempCard;
	for (int i = 0; i < handSize; i++)
	{
		tempCard = draw();
		tempCard.setFaceUp(true);
		addCard(tempCard);
	}
}

void HandOfCards::add(Card cardToAdd, bool faceUp_)
{
	cardToAdd.setFaceUp(faceUp_);
	addCard(cardToAdd);
}

int HandOfCards::getSize()
{
	return data.getSize();
}

void HandOfCards::addCard(Card &cardToAdd)
{
    Card* cardToAdd2 = new Card(cardToAdd.getFace(), cardToAdd.getValue(), cardToAdd.getFaceUp());
    data.enqueue(cardToAdd2);
}

Card HandOfCards::draw()
{
    if (data.getSize() == 0)
    {
        Card temp = Card();
        return temp;
    }
    return data.dequeue();
}

ostream& operator << (ostream& out, HandOfCards& tempHand)
{
	out << tempHand.value();
	
	return out;
}