/** 
* @ file        Node.cpp
* @ description Dugum sinifinin govdesinin oldugu kisimdir. Dugumun icerikleri tanimlanir.
* @ course      1-B
* @ assignment  1
* @ date        12.11.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/

#include <string>
#include "Node.hpp"

using namespace std;

node::node(string data)
{
    this->data = data;
    next = 0;
    prev = 0;
};