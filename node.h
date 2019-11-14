#ifndef NODE_H
#define NODE_H

// A generic doubly linked list node
template <class T>
class Node {
	private:
		static int length;
		T value;
		Node <T>* next;
		Node <T>* prev;
	public:
		void insertFront(Node** p_head, T new_value);
		void insertRear(Node** p_head, T new_value);
		void deleteItem(Node** p_head, T value);
		void deleteItemByManFac(Node** p_head, string value);
		int listSize(Node* p_head);
		T findItem(Node* node, T value);
		void printList(Node* node, int option);
		Node* getNext();
		Node* getPrev();
		void setNext();
		void setPrev();
		T getValue();
};

#endif