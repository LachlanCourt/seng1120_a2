/*************************************
**** Lachlan Court
**** c3308061
**** 19/10/2020
**** SENG1120 Assignment 2
**************************************/

#include <iostream>

// Default Constructor
template <typename value_type>
Node<value_type>::Node()
{
	next = NULL;
	prev = NULL;
	data = NULL;
}

// Initilise node with existing next and previous and data
template <typename value_type>
Node<value_type>::Node(Node* p, Node* n, value_type* i)
{
	next = n;
	prev = p;
	data = i;
}

// Initialise node with only data and NULL directional pointers that can be assigned later
template <typename value_type>
Node<value_type>::Node(value_type* i)
{
	next = NULL;
	prev = NULL;
	data = i;
}

// The pointers to other Nodes need to remain so only delete the Data
template <typename value_type>
Node<value_type>::~Node()
{
	next = NULL;
	prev = NULL;
	delete(data);
}

// Set the next pointer for the Node
template <typename value_type>
void Node<value_type>::setNext(Node<value_type>* n_)
{
	next = n_;
}

// Set the previous pointer for the Node
template <typename value_type>
void Node<value_type>::setPrev(Node<value_type>* p_)
{
	prev = p_;
}

// Set the data pointer for the Node
template <typename value_type>
void Node<value_type>::setData(value_type* data_)
{
	data = data_;
}

// Query the next pointer for the Node
template <typename value_type>
Node<value_type>* Node<value_type>::getNext() const
{
	return next;
}

// Query the previous pointer for the Node
template <typename value_type>
Node<value_type>* Node<value_type>::getPrev() const
{
	return prev;
}

// Query the data pointer for the Node
template <typename value_type>
value_type* Node<value_type>::getData()
{
	return data;
}



