/*************************************
**** Lachlan Court
**** c3308061
**** 18/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;

#ifndef QUEUE_CLASS
#define QUEUE_CLASS
#include "LinkedList.h"

template <typename value_type>
class Queue
{
	public:
		
		//****Constructor****//
		Queue();
		//****Destructor****//
		~Queue();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Function returns the size of the Queue
		const int getSize() const;
		
		value_type* front();
		
		//****Data manipulation****//
		
		//precondition: None
		//postcondition: The Linked List stored inside the Queue has data added as a new node at the end of the list
		void enqueue(value_type* data_);
		//precondition: identifier cannot be NULL but can be empty
		//postcondition: The first item in the Linked List stored inside the Queue will be removed and returned
		value_type dequeue();
		
	private:
		//****Instance variables****//
		LinkedList<value_type> data;
		int size;
};

#include "Queue.hpp"
#endif