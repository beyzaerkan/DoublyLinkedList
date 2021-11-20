/** 
* @ file        DoublyLinkedList.cpp
* @ description Cift bagli listede ekleme cikarma foksiyonlarinin bulundugu dosyadir. Ayni zamanda kurucu ve yikici fonksiyonlara da ulasilabilir.
* @ course      1-B
* @ assignment  1
* @ date        12.11.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include "Node.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    root = 0;
    length = 0;
}
DoublyLinkedList::~DoublyLinkedList(){
    node* temp = root;
    while (temp!=0)
    {
        node* willBeDeleted = temp;
        temp = temp->next;
        delete willBeDeleted;
    }
}
void DoublyLinkedList::add(string data)
{
    //yeni bir dugum tanimlar
    node *newNode = new node(data);
    length++;
    //eger ilk eleman bossa yeni tanımladigi dugume esitler
    if (root == 0)
    {
        root = newNode;
        return;
    }
    //gecici bir pointer tutar ve ilk elemana esitler
    node *temp = root;
    //listenin sonuncu elemanina ulasır ve geciciyi son elemana esitler
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    //son elemanın sonraki degerini yeni dugume esitler
    temp->next = newNode;
    //yeni dugumun onceki degerini de geciye esitler.
    newNode->prev = temp;
};

//herhangi bir yere eleman ekler
void DoublyLinkedList::addToAnywhere(int index, string data)
{
    //sona bos bir dugum tanimlar
    add(" ");

    //gecici bir pointer tutar ve ilk elemana esitler
    node *temp = root;
    //listenin sonuncu elemanina ulasır ve geciciyi son elemana esitler
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    //sonuncu elemandan baslayarak verilen indexteki elemana kadar kendisinden bir onceki elemanın verisini kendine kopyalar
    for (int i = length-1; i > index; i--)
    {
        temp = temp->prev;
        temp->next->data = temp->data;
    }
    //verilen indexteki elemanin verisini girilen veriye esitler
    temp->data = data;
};

//sonuncu elemani siler
void DoublyLinkedList::deleteLast(){
    //gecici bir pointer tutar ve ilk elemana esitler
    node* temp=root;

    //eleman sayisi 1 oldugunda 
    if(length==1){
        delete temp->next;
        length--;
        root = 0;
        return;
    }
    //listenin sonuncu elemanina ulasır ve geciciyi son elemana esitler
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    //gecicinin onceki elemanının sonraki degerini gecicinin sonraki degerine esitler
    temp->prev->next=temp->next;
    //geciciyi siler
    delete temp;
    //dugum sayisini bir azaltir
    length--;
    };

void DoublyLinkedList::deleteToAnywhere(int index)
{
    //girilen index listenin uzunlugundan buyuk oldugu durumda sondaki elemani siler
    if(index>length-1){
        deleteLast();
        return;
    }
    //gecici bir pointer tutar ve ilk elemana esitler
    node *temp = root;
    //ilk elemandan baslayarak indexteki elemana kadar gider ve sonucta gecici indexteki eleman olmus olur.
    for(int i=0; i<index; i++){
        temp=temp->next;
    }
    //indexteki elemandan baslayarak son elemana kadar kendisinden bir sonraki elemanin verisini kendine kopyalar
    while(temp->next!=0){
        temp->data=temp->next->data;
        temp = temp->next;
    }
    // silmeden once sonuncu elemandan bir onceki elemanın sonraki degerini 0' a esitler
    temp->prev->next=0;
    //sonuncu elemani siler
    delete  temp;
    //sildikten sonra uzunlugu bir azaltir
    length--;
};

void DoublyLinkedList::printTheList(){
    //gecici bir pointer tutar ve ilk elemana esitler
    node* temp=root;
    //ilk elemandan baslayarak son elemana kadar elemanların verilerini ekrana yazar
    while(temp!=0){
        cout<<temp->data<<" <--> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
