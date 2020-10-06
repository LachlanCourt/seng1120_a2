/*************************************
**** Lachlan Court
**** c3308061
**** 13/09/2020
**** SENG1120 Assignment 1
**************************************/


//cd /cygdrive/C/Users/lachl/OneDrive/Documents/Uni/SENG1120_Assessment/Assignment2
//Node.h LinkedList.h Queue.h HandOfCards.cpp DeckOfCards.cpp

#include <iostream>

// Constructor, initialise empty list
template <typename value_type>
LinkedList<value_type>::LinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	size = 0;
}

// Destructor

template <typename value_type>
LinkedList<value_type>::~LinkedList()
{
	// Loop through until the head is NULL and delete the head each time
	while (head != NULL)
	{	
		// Keep track of the item in the list after the head
		current = head->getNext();
		// Delete head
		delete(head);
		// Set the head to what used to be the second item in the list
		head = current;
	}
	
}

// Query the size of the list
template <typename value_type>
int LinkedList<value_type>::getSize() const
{
	return size;
}


// Receives a string that will be added to the Linked List at the end
template <typename value_type>
void LinkedList<value_type>::addToTail(value_type* data_)
{
	// Check if the list is empty
	if ((head == NULL) && (tail == NULL))
	{
		// Create a new node with the specified data
		head = new Node<value_type>(data_);
		// The list has one item so the tail and head are the same node
		tail = head;
		current = head;
		// Increase the size of the list
		size++;
	}
	else
	{
		// Create a new node with the specified data
		current = new Node<value_type>(data_);
		// Link the new node's previous to the tail of the list
		current->setPrev(tail);
		// Link the tail's next to the new node
		tail->setNext(current);
		// Set the tail to the new node
		tail = current;
		
		// Having just manipulated the current, reset it to head
		jumpToHead();
		// Increase the size of the list
		size++;
	}	
}

// Receives a string that will be removed from the Linked List
template <typename value_type>
value_type LinkedList<value_type>::removeFromHead()
{
	value_type temp;
	jumpToHead();
	temp = *current->getData();
	head = current->getNext();
	delete(current);
	size--;
	if (head != NULL)
	{
		head->setPrev(NULL);
		current = head;
	}
	else
	{
		tail = NULL;
		current = NULL;
	}
	return temp;
}


// Resets current to head
template <typename value_type>
int LinkedList<value_type>::jumpToHead()
{
	current = head;
	// Return -1 if current is now NULL - indicating list is empty
	if (current == NULL)
	{
		return -1;
	}
	return 0;
}

// Resets current to tail
template <typename value_type>
int LinkedList<value_type>::jumpToTail()
{
	current = tail;
	// Return -1 if current is now NULL - indicating list is empty
	if (current == NULL)
	{
		return -1;
	}
	return 0;
}

// Moves current to the next Node in the list
template <typename value_type>
int LinkedList<value_type>::moveNext()
{
	current = current->getNext();
	// Return -1 if current is now NULL - reached the end of the list
	if (current == NULL)
	{
		return -1;
	}
	return 0;
}

// Moves current to the previous Node in the list
template <typename value_type>
int LinkedList<value_type>::movePrev()
{
	current = current->getPrev();
	// Return -1 if current is now NULL - reached the start of the list
	if (current == NULL)
	{
		return -1;
	}
	return 0;
}

// Return the data stored in the current Node
template <typename value_type>
value_type* LinkedList<value_type>::getCurrent() const
{
	return current->getData();
}

template <typename value_type>
void LinkedList<value_type>::deleteCurrent()
{
			// If there is one item in the list
			if (head == tail)
			{
				// Reset the head and tail as the list is about to become empty
				head = NULL;
				tail = NULL;
			}
			// If the first item in the list
			else if (current == head)
			{
				// Set the head to the second item in the list as the first is about to be removed
				head = current->getNext();
				head->setPrev(NULL);
		
			}
			// If the last item in the list
			else if (current == tail)
			{
				// Set the tail to the second last item in the list as the last is about to be removed
				tail = current->getPrev();
				tail->setNext(NULL);
		
			}
			// The list has more than one item and the item to be removed is not at the head or tail
			else
			{
				// Link the node before the current to the node after the current
				current->getPrev()->setNext(current->getNext());
				current->getNext()->setPrev(current->getPrev());
			}
			// Delete the current and decrement the size
			delete(current);
			size--;
			// current has just been deleted so reset it to the head and start the loop over
			jumpToHead();
}
















































