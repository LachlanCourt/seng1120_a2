/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>
using namespace std;
#ifndef NODE_CLASS
#define NODE_CLASS
#include <string>
template <typename value_type>
class Node
{
	public:		
		//****Constructors****//
		Node();
		Node(Node* p, Node* n, value_type* i);
		Node(value_type* i);
		//****Destructor****//
		~Node();
		
		//****Queries****//
		
		//precondition: None
		//postcondition: Function returns the pointer to the next Node object
		Node<value_type>* getNext() const;
		//precondition: None
		//postcondition: Function returns the pointer to the previous Node object
		Node<value_type>* getPrev() const;
		//precondition: Data should not be NULL
		//postcondition: Function returns the pointer to the data
		value_type* getData();
		
		//****Data manipulation****//
	
		//precondition: None
		//postcondition: Node's next variable will be a pointer to the next Node object
		void setNext(Node<value_type>* n_);
		//precondition: None
		//postcondition: Node's previous variable will be a pointer to the next Node object
		void setPrev(Node<value_type>* p_);
		//precondition: None
		//postcondition: Node's data variable will be a pointer to data on the heap
		void setData(value_type* data_);
		
	private:
		//****Instance variables****//
		value_type* data;
		Node* next;
		Node* prev;
};
#include "Node.hpp"
#endif