#include <iostream>
using namespace std; 
#include "Container.h"
#define FTR 1
#define RTF 2

template <class T>
void Container<T> :: insertFront(Container<T>** p_head, T new_value) {
	/*
	/* param1: pointer to pointer of head of list
	/* param2: value to be inserted
	/* fuction: inserts a new node on the front of the list
	*/
	
	// allocate node
	Container<T>* new_node = new Container(); 

	// put the value in node
	new_node->value = new_value; 

	// make next of new node as head and previous as NULL
	new_node->next = (*p_head); 
	new_node->prev = NULL; 

	// change prev of head node to new node
	if ((*p_head) != NULL) 
		(*p_head)->prev = new_node; 

	// move the head to point to the new node
	(*p_head) = new_node; 

	// increament the lenght
	(*p_head)->length++;
}

template <class T>
void Container<T> :: insertRear(Container<T>** p_head, T new_value) {
	/*
	/* param1: pointer to pointer of head of list
	/* param2: value to be inserted
	/* fuction: inserts a new node at the end of the list
	*/

	// increment the lengh
	(*p_head)->length++;

	//allocate node
	Container<T>* new_node = new Container(); 

	Container<T>* last = *p_head; /* used in step 5*/

	// put the value in node
	new_node->value = new_value; 

	// make next of it as NULL
	new_node->next = NULL; 

	// if the List is empty, make the new node as head
	if (*p_head == NULL) { 
		new_node->prev = NULL; 
		*p_head = new_node;
		return; 
	}

	// traverse till the last node
	while (last->next != NULL) 
		last = last->next; 

	// change the next of last node
	last->next = new_node; 

	// make last node as previous of new node
	new_node->prev = last; 

	return;
}

template <class T>
void Container<T> :: printList(Container<T>* node, int option) {
	/*
	/* param1: pointer to of head of list
	/* param2: option:- FTR (value = 1) : front to rear; FTF (value = 2) : rear to front
	/* fuction: prints the element of list accodring to option provided, prints both option otherwise
	*/

	Container<T>* last;

	if (option == 1) {
		cout<<"\nDLL in Forward direction:\n["; 
		while (node != NULL) { 
			cout<<node->value<<"  "; 
			last = node; 
			node = node->next; 
		}
		cout<<"]"; 
	} else if (option == 2) {
		cout<<"\nDLL in Reverse direction:\n[";
		while (node != NULL) {
			last = node; 
			node = node->next; 
		}
		while (last != NULL) 
		{ 
			cout<<last->value<<"  "; 
			last = last->prev; 
		}
		cout<<"]";
	} else {
		cout<<"\nDLL in Forward direction:\n["; 
		while (node != NULL) { 
			cout<<node->value<<"  "; 
			last = node; 
			node = node->next; 
		}
		cout<<"]"; 

		cout<<"\n\nDLL in Reverse direction:\n["; 
		while (last != NULL) { 
			cout<<last->value<<"  "; 
			last = last->prev; 
		}
		cout<<"]"; 
	}
	cout<<endl;
} 

template <class T>
void Container<T> :: deleteItem(Container<T>** p_head, T value) {
	/* base case */
	if (*p_head == NULL)  
		return;

	Container<T>* prev = (*p_head);
	Container<T>* curr = (*p_head)->getNext();

	while(curr != NULL) {
		if (curr->value == value) {
			break;
		} else {
			prev = curr;
			curr = curr->getNext();
		}
	}

	if (curr == NULL) {
		cout << "\nDeletion Failed: Value '" << value << "' is not found in list!\n";
	} else {
		//change the next and prev only if they are not null
		if(curr->next != NULL)
			curr->next->prev = curr->prev;

		if(curr->prev != NULL)
			curr->prev->next = curr->next;

		delete curr;
		(*p_head)->length--;
		cout << "\nDeleted '" << value << "' from the list!\n";
	} 
}

template <class T>
Container<T>* Container<T> :: getNext() {
	if (this != NULL)
		return this->next;
	else {
		cout<<"Node does not exist!\n";
		return NULL;
	}
}

template <class T>
Container<T>* Container<T> :: getPrev() {
	if (this != NULL)
		return this->prev;
	else {
		cout<<"Node does not exist!\n";
		return NULL;
	}
}

template <class T>
int Container<T> :: listSize(Container<T>* p_head) {
	if (p_head == NULL) {
		return 0;
	} else {
		return p_head->length;
	}
}

template <class T>
int Container<T>::length = 0;

int main() {
	// create a new empty list
	Container<int>* head = NULL;
	head->insertFront(&head, 54);
	head->insertFront(&head, 57);
	head->insertRear(&head, 66);
	head->insertRear(&head, 87);
	head->insertFront(&head, 79);
	head->printList(head, FTR);
	head->printList(head, RTF);
	head->deleteItem(&head, 57);
	head->deleteItem(&head, 54);
	head->deleteItem(&head, 54);
	head->deleteItem(&head, 87);
	head->insertFront(&head, 99);
	head->deleteItem(&head, 79);
	head->printList(head, FTR);
	return 0; 
}