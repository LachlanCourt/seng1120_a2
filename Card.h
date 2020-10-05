#include <iostream>
using namespace std;

#ifndef Card_Class
#define Card_Class

class Card
{
		public:
			//Constructors	
			Card();
			Card(string* face_, int* value_, bool* faceUp_);
			//Destructor
			~Card();
		
			void setFace(string* face_);
			
			void setValue(int* value_);
			
			void setFaceUp(bool* faceUp_);
			
			string* getFace() const;
			
			int* getValue() const;
			
			bool* getFaceUp() const;
		
		private:
			string* face;
			int* value;
			bool* faceUp;
};

ostream& operator << (ostream& out, Card& temp);

#endif