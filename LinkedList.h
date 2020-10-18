/*************************************
**** Lachlan Court
**** c3308061
**** 17/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;
#ifndef LINKEDLIST_CLASS
#define LINKEDLIST_CLASS
#include "Node.h"

template <typename value_type>
class LinkedList
{
	
	public:
		
		//****Constructor****//
		LinkedList();
		//****Destructor****//
		~LinkedList();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Function returns the size of the Linked List
		const int getSize() const;
		
		//****Data manipulation****//
		
		//precondition: None (Empty list possibility is checked during function)
		//postcondition: Linked List has data added as a new node at the end of the list
		void addToTail(value_type* data_);
		//precondition: Linked List cannot be empty
		//postcondition: The first item in the list will be removed and returned
		value_type removeFromHead();
		
		//****List traversing****//
		
		//precondition: None
		//postcondition: Linked List current is set to head, returns -1 if list is empty and 0 if successful
		const int jumpToHead();
		//precondition: None
		//postcondition: Linked List current is set to tail, returns -1 if list is empty and 0 if successful
		const int jumpToTail();
		//precondition: Linked List current cannot be NULL
		//postcondition: Linked List current is set to the value of it's next, returns -1 if current is now NULL and 0 if successful
		const int moveNext();
		//precondition: Linked List current cannot be NULL
		//postcondition: Linked List current is set to the value of it's previous, returns -1 if current is now NULL and 0 if successful
		const int movePrev();
		//precondition: Linked List current cannot be NULL
		//postcondition: Returns the pointer to the data of the current Node
		value_type* getCurrent() const;
		
	private:
		//****Instance variables****//
		Node<value_type>* head;
		Node<value_type>* tail;
		Node<value_type>* current;
		int size;
};
#include "LinkedList.hpp"
#endif