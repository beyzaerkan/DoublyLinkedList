#include <string>
#ifndef Node_hpp
#define Node_hpp

using namespace std;
class node {
public:
    string data;
    node* next;
    node* prev;
    node(string data);
};
#endif