/*************************************
**** Lachlan Court
**** c3308061
**** 13/09/2020
**** SENG1120 Assignment 1
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
		
		//Constructor
		LinkedList();
		//Destructor
		~LinkedList();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Function returns the size of the Linked List
		int getSize() const;
		
		//****Data manipulation****//
		
		//precondition: None (Empty list possibility is checked during function)
		//postcondition: Linked List has data added as a new node at the end of the list
		void addToTail(value_type* data_);
		//precondition: identifier cannot be NULL but can be empty
		//postcondition: All items that match the specified identifier will be removed from the list
		value_type removeFromHead();
		
		//****List traversing****//
		
		//precondition: None
		//postcondition: Linked List current is set to head, returns -1 if list is empty and 0 if successful
		int jumpToHead();
		//precondition: None
		//postcondition: Linked List current is set to tail, returns -1 if list is empty and 0 if successful
		int jumpToTail();
		//precondition: Linked List current cannot be NULL
		//postcondition: Linked List current is set to the value of it's next, returns -1 if current is now NULL and 0 if successful
		int moveNext();
		//precondition: Linked List current cannot be NULL
		//postcondition: Linked List current is set to the value of it's previous, returns -1 if current is now NULL and 0 if successful
		int movePrev();
		//precondition: Linked List current cannot be NULL
		//postcondition: Returns the pointer to the data of the current Node
		value_type* getCurrent() const;
		
	private:
		//****Instance variables****//
		Node<value_type>* head;
		Node<value_type>* tail;
		Node<value_type>* current;
		int size;
		
		//****Private methods****//

		void deleteCurrent();
};
#include "LinkedList.hpp"
#endif