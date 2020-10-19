/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>

// Constructor, initialise empty queue
template <typename value_type>
Queue<value_type>::Queue()
{
	size = 0;
}

// Destructor
template <typename value_type>	
Queue<value_type>::~Queue()
{
	// The only instance variable is the LinkedList "data" which is stored on the stack
}

// Returns the size of the queue
template <typename value_type>		
const int Queue<value_type>::getSize() const
{
	return size;
}

// Returns the first item in the queue without removing it
template <typename value_type>	
value_type* Queue<value_type>::front()
{
	// A value of -1 means that the queue is empty. If it is not, return the data in the first position
	if (data.jumpToHead() != -1)
	{
		return data.getCurrent();
	}
	// If the queue is empty, create a new item with the default constructor and return
	value_type* temp = new value_type();
	return temp;
}

// Add an item onto the list using the linked list addToTail function
template <typename value_type>	
void Queue<value_type>::enqueue(value_type* data_)
{
	size++;
	data.addToTail(data_);
}

// Removes and returns the first item in the queue
template <typename value_type>
value_type Queue<value_type>::dequeue()
{
	// Check if the queue is empty
	if (size != 0)
	{
		// If it is not empty, decrement the size and call the removeFromHead Linked List function
		size--;
		return data.removeFromHead();
	}
	// If the queue is empty, create a new item with the default constructor and return
	value_type temp = value_type();
	return temp;
}