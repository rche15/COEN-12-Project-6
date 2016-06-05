/* 
* Ray Che
* COEN 12

This header file contains the class definitions for Deque and Node used in deque.cpp.
*/

class Deque{
    int count;
    class Node *dummy;
    
public:
    int size();
    
    void addFirst(int x);
    
    void addLast(int x);
    
    int removeFirst();
    
    int removeLast();
    
    int getFirst();
    
    int getLast();
    
    Deque();
    
    ~Deque();
};

class Node {
public:
    int data;
    Node *next;
    Node *prev;
};
