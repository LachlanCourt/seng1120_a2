#include <iostream>
using namespace std;
#include "Card.h"

Card::Card()
{
	/* 
	Set value to -1 which will be used to determine if the Queue of cards is empty. When the queue is
	empty it will create a new blank card object to return, which can query the value and determine if
	the deck is empty or not
	*/
	value = -1;
}

Card::Card(string face_, int value_, bool faceUp_)
{
	face = face_;
	value = value_;
	faceUp = faceUp_;
}

Card::~Card()
{
	// All variables in the Card class are local variables and as such will be automatically deleted
}

void Card::setFace(string face_)
{
	face = face_;
}
			
void Card::setValue(int value_)
{
	value = value_;
}
			
void Card::setFaceUp(bool faceUp_)
{
	faceUp = faceUp_;
}
			
string Card::getFace() const
{
	return face;
}
			
int Card::getValue() const
{
	return value;
}
			
bool Card::getFaceUp() const
{
	return faceUp;
}

ostream& operator << (ostream& out, Card& temp)
{
	out << temp.getFace() << endl;
	return out;
}





































