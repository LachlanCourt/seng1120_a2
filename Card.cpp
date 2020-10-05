#include <iostream>
using namespace std;
#include "Card.h"

Card::Card()
{
	face = NULL;
	value = NULL;
	faceUp = NULL;
}

Card::Card(string* face_, int* value_, bool* faceUp_)
{
	face = face_;
	value = value_;
	faceUp = faceUp_;
}

Card::~Card()
{
	
}

void Card::setFace(string* face_)
{
	if (face != NULL)
	{
		delete(face);
	}
	face = face_;
}
			
void Card::setValue(int* value_)
{
	if (value != NULL)
	{
		delete(value);
	}
	value = value_;
}
			
void Card::setFaceUp(bool* faceUp_)
{
	if (faceUp != NULL)
	{
		delete(faceUp);
	}
	faceUp = faceUp_;
}
			
string* Card::getFace() const
{
	return face;
}
			
int* Card::getValue() const
{
	return value;
}
			
bool* Card::getFaceUp() const
{
	return faceUp;
}

ostream& operator << (ostream& out, Card& temp)
{
	out << *temp.getFace() << endl;
	return out;
}




































