/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;
#include "Card.h"

// Default constructor
Card::Card()
{
	/* 
	A card made with the default constructor will have a value of -1. Several functions will use this to determine if
	it is a blank card by querying the value and checking if it is -1
	*/
	value = -1;
}

// Initialise card with face, value, and it's faceUp status
Card::Card(string face_, int value_, bool faceUp_)
{
	face = face_;
	value = value_;
	faceUp = faceUp_;
}

// Destructor
Card::~Card()
{
	// All variables in the Card class are local member variables and as such will be automatically deleted
}

// Set the face value of the card
void Card::setFace(string face_)
{
	face = face_;
}
	
// Set the value of the card	
void Card::setValue(int value_)
{
	value = value_;
}

// Set the faceUp status of the card			
void Card::setFaceUp(bool faceUp_)
{
	faceUp = faceUp_;
}
	
// Query the face value of the card	
string Card::getFace() const
{
	return face;
}
	
// Query the value of the card	
int Card::getValue() const
{
	return value;
}
	
// Query the faceUp status of the card	
bool Card::getFaceUp() const
{
	return faceUp;
}

// Output the face of the card
ostream& operator << (ostream& out, Card& temp)
{
	out << temp.getFace() << endl;
	return out;
}





































