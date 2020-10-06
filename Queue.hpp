#include <iostream>

template <typename value_type>
Queue<value_type>::Queue()
{
	size = 0;
}
	
template <typename value_type>	
Queue<value_type>::~Queue()
{
	
}

template <typename value_type>		
int Queue<value_type>::getSize() const
{
	return size;
}
	
template <typename value_type>	
value_type* Queue<value_type>::front()
{
	if (data.jumpToHead() != -1)
	{
		return data.getCurrent();
	}
	value_type* temp = new value_type();
	return temp;
}
	
template <typename value_type>	
void Queue<value_type>::enqueue(value_type* data_)
{
	size++;
	data.addToTail(data_);
}

template <typename value_type>
value_type Queue<value_type>::dequeue()
{
	
	if (size != 0)
	{
		size--;
		return data.removeFromHead();
	}
	value_type temp = value_type();
	return temp;
}