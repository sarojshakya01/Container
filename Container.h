#ifndef CONTAINER_H
#define CONTAINER_H

// A generic doubly linked list Node
template <class T>
class Container {
	private:
		static int length;
		T value;
		Container <T>* next;
		Container <T>* prev;
	public:
		void insertFront(Container** p_head, T new_value);
		void insertRear(Container** p_head, T new_value);
		void deleteItem(Container** p_head, T value);
		void deleteItemByManFac(Container** p_head, string value);
		int listSize(Container* p_head);
		T findItem(Container* Container, T value);
		void printList(Container* Container, int option);
		Container* getNext();
		Container* getPrev();
		void setNext();
		void setPrev();
		T getValue();
};

#endif