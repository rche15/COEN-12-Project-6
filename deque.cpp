/* 
* Ray Che
* COEN 12

This program contains several functions that handle the creation of a deque, adding and removing items from the deque, returning an item within the deque, and the deque's destruction. The deque is implemented in the form of a circular doubly-linked list with a dummy node, allowing insertation and deletion from the front or the end of the list in constant O(1) time.
 */

// Include header files. "deque.h" is a local header file.
#include <iostream>
#include <cassert>
#include "deque.h"

using namespace std; 

/* This function is the constructor for the deque. It initializes the count and allocates memory for the dummy node. This function has a run time of O(1). */
Deque::Deque(){
    count=0;
    
    dummy=new Node();
    assert(dummy!=NULL);
    
    // Establishes linked list as doubly circular.
    dummy->next=dummy;
    dummy->prev=dummy;
}

/* This function is the destructor for the deque. It traverses the linked list and deallocates the memory for all nodes in the list. This function has a run time of O(n). */
Deque::~Deque(){
    Node *np, *next;
    np=dummy;
    
    do {
        next=np->next;
        delete[]np;
        np=next;
    } while (np!=dummy);
}

/* This function returns the size of the deque. This function has a run time of O(1). */
int Deque::size(){
    return count;
}

/* This function creates a new node containing the passed data into the beginning of the linked list (right after the dummy). This function has a run time of O(1). */
void Deque::addFirst(int x){
    // Creates new node with data.
    Node *np;
    np=new Node();
    assert(np!=NULL);
    np->data=x;
   
    count++;
    
    // Inserts after dummy, changing pointers to maintain doubly circular property.
    np->prev=dummy;
    np->next=dummy->next;
    dummy->next->prev=np;
    dummy->next=np;
}

/* This function creates a new node containing the passed data into the end of the linked list (right before the dummy). This function has a run time of O(1). */
void Deque::addLast(int x){
    // Creates new node with data.
    Node *np;
    np=new Node();
    assert(np!=NULL);
    np->data=x;
    
    count++;
    
    // Inserts before dummy, changing pointers to maintain doubly circular property.
    np->prev=dummy->prev;
    np->next=dummy;
    dummy->prev->next=np;
    dummy->prev=np;
}

/* This function removes the first node (after the dummy) from the linked list and returns the value that was in that node. This function has a run time of O(1). */
int Deque::removeFirst(){
    int x;
    Node *np;
   
    assert(count>0);
    
    count--;
    
    // Removes node from the linked list
    np=dummy->next;
    dummy->next=np->next;
    np->next->prev=dummy;
    
    // Captures data and deletes memory for node
    x=np->data;
    delete[]np;
    
    return x;
}

/* This function removes the last node (before the dummy) from the linked list and returns the value that was in that node. This function has a run time of O(1). */
int Deque::removeLast(){
    int x;
    Node *np;
    
    assert(count>0);
    
    count--;
    
    // Removes node from the linked list
    np=dummy->prev;
    dummy->prev=np->prev;
    np->prev->next=dummy;
    
    // Captures data and deletes memory for node
    x=np->data;
    delete[]np;
    
    return x;
}

/* This function simply returns the data contained in the first node in the linked list (after the dummy). This function has a run time of O(1). */
int Deque::getFirst(){
    return dummy->next->data;
}

/* This function simply returns the data contained in the last node in the linked list (before the dummy). This function has a run time of O(1). */
int Deque::getLast(){
    return dummy->prev->data;
}
