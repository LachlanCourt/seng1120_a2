#include <iostream>
using namespace std;

#ifndef QUEUE_CLASS
#define QUEUE_CLASS
#include "LinkedList.h"

template <typename value_type>
class Queue
{
	public:
		
		//Constructor
		Queue();
		//Destructor
		~Queue();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Function returns the size of the Linked List
		int getSize() const;
		
		value_type* front();
		//****Data manipulation****//
		
		//precondition: None (Empty list possibility is checked during function)
		//postcondition: Linked List has data added as a new node at the end of the list
		void enqueue(value_type* data_);
		//precondition: identifier cannot be NULL but can be empty
		//postcondition: All items that match the specified identifier will be removed from the list
		value_type dequeue();
		
	private:
		//****Instance variables****//
		LinkedList<value_type> data;
		int size;
};

#include "Queue.hpp"
#endif