/*************************************
**** Lachlan Court
**** c3308061
**** 17/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;

#ifndef Card_Class
#define Card_Class

class Card
{
		public:
			//****Constructors****//
			Card();
			Card(const string face_, const int value_, const bool faceUp_);
			//****Destructor****//
			~Card();
		
			//precondition: None
			//postcondition: face variable is updated
			void setFace(const string face_);
			//precondition: None
			//postcondition: value variable is updated
			void setValue(const int value_);
			//precondition: None
			//postcondition: faceUp variable is updated
			void setFaceUp(const bool faceUp_);
			
			
			//****Queries****//
			
			//precondition: None
			//postcondition: face variable is returned
			string getFace() const;
			//precondition: None
			//postcondition: value variable is returned
			int getValue() const;
			//precondition: None
			//postcondition: faceUp variable is returned
			bool getFaceUp() const;
		
		private:
			//****Instance variables****//
			string face;
			int value;
			bool faceUp;
};

//****Output Operator****//
ostream& operator << (ostream& out, Card& temp);

#endif