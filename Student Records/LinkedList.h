#pragma once
#include <stdexcept>

/*******************************************************************************
**		This class is an implementation of a Doubly Linked-List.              **
**		Author: Lord Alzer T. Casiño.                                         **
********************************************************************************/
template <typename T>
class LinkedList
{
private:

	/*   Private nested Node class   */
	class Node
	{
	public:
		T elem;              //The item inside the node.
		Node *next;          //points to the next node.
		Node *prev;          //points to the previous node.
	};

	Node *header;            //Points to the header guard node.
	Node *trailer;           //Points to the trailer guard node.
	int size;                //The number of elements inside the list.

public:

	/*     Creates a new, empty Linked-List.     */
	LinkedList()
	{
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}

	/*    The destructor - destroys/deletes dynamic variables allocated in the heap    */
	~LinkedList()
	{
		while (!isEmpty())
			removeFront();
		delete header;
		delete trailer;
	}

	/*    Returns the number of elements in the list.    */
	int size_of() const
	{
		return size;
	}

	/*    Tests if the list is empty.    */
	bool isEmpty() const
	{
		return size == 0;
	}

	/*    Returns the first item in the list.
	      May throw std::out_of_range() if list is empty.    */
	const T& front() const
	{
		if (isEmpty())
			throw std::out_of_range("List is empty.");
		return header->next->elem;
	}

	/*    Returns the last item in the list.
		  May throw std::out_of_range() if list is empty.    */
	const T& back() const
	{
		if (isEmpty())
			throw std::out_of_range("List is empty.");
		return trailer->prev->elem;
	}

	/*	  Adds an item at the front of the list.    */
	void addFront(const T& item)
	{
		addBetween(item, header, header->next);
	}

	/*	  Adds an item at the back of the list.    */
	void addBack(const T& item)
	{
		addBetween(item, trailer->prev, trailer);
	}

	/*    Adds an item with the index indicated into the list.
	      May throw std::out_of_range() if index is negative or greater than size + 1    */
	void addAt(const T& item, int index)
	{
		if (index > size)
			throw std::out_of_range("Index exceeds size of list.");
		else if (index < 0)
			throw std::out_of_range("Index cannot be negative");
		Node *node = header;
		for (int i = 0; i < index; i++)
			node = node->next;
		addBetween(item, node, node->next);
	}

	/*    Removes the first item in the list.
	      May throw std::out_of_range() if list is empty.    */
	const T removeFront()
	{
		if (isEmpty())
			throw std::out_of_range("List is empty");
		return remove(header->next);
	}

	/*    Removes the last item in the list.
	      May throw std::out_of_range() if list is empty.    */
	const T removeBack()
	{
		if (isEmpty())
			throw std::out_of_range("List is empty");
		return remove(trailer->prev);
	}

	/*    Removes the item of the index indicated in the list.
	      May throw std::out_of_range() if list is empty, exceeds size, or negative index.    */
	const T removeAt(int index)
	{
		if (isEmpty())
			throw std::out_of_range("List is empty");
		if (index >= size)
			throw std::out_of_range("Index exceeds size of list.");
		else if (index < 0)
			throw std::out_of_range("Index cannot be negative.");
		Node *node = header;
		for (int i = 0; i < size; i++)
			node = node->next;
		return remove(node->next);
	}

protected:
	
	/*    Protected Members    */
	
	/*    Adds the item between two nodes.   */
	void addBetween(const T& item, Node *predecessor, Node *successor)
	{
		Node *newest = new Node;
		newest->elem = item;
		newest->prev = predecessor;
		newest->next = successor;
		predecessor->next = newest;
		successor->prev = newest;
		size++;
	}

	/*    Removes the node indicated.    */
	const T remove(Node *node)
	{
		Node *predecessor = node->prev;
		Node *successor = node->next;
		predecessor->next = successor;
		successor->prev = predecessor;
		T oldItem = node->elem;
		size--;
		delete node;
		return oldItem;
	}
};
