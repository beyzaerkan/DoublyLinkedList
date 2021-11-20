#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp
#include <string> 
#include "Node.hpp"

using namespace std;

class DoublyLinkedList
{
public:
    int length;
    node *root;
    DoublyLinkedList();
    ~DoublyLinkedList();
    void add(string data);
    void addToAnywhere(int index, string data);
    void deleteToAnywhere(int index);
    void deleteLast();
    void printTheList();
};
#endif