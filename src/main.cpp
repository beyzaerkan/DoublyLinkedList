/** 
* @ file        Node.cpp
* @ description Dosyadan okuma islemini gerceklestirir. Ayni zamanda DoublyLinkedList.cpp dosyasinda tanimlanan fonksiyonlari kullanir.
* @ course      1-B
* @ assignment  1
* @ date        12.11.2021
* @ author      Beyza Erkan  beyza.erkan@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include "DoublyLinkedList.hpp"

using namespace std;

int main()
{
  DoublyLinkedList *list = new DoublyLinkedList();
    ifstream readFile("veri.txt");
    string line; //dosyadaki satirlari temsil eder.
    int index; //satirdaki fonksiyonlarin icinden alinan index degerlerini temsil eder.
    string data; //satirdaki ekle fonksiyonunun icinden alinan veri degerini temslil eder.
    string order; //satirdaki fonksiyonlarin hangi fonksiyon oldugunu temsil eder.  ('E' veya 'S' gibi)

  // dosya acilirsa islemleri yapar
   if ( readFile.is_open() ){

    while ( getline(readFile, line) ){

      //satirin ilk elemani fonksiyonu temsil edecegi icin ilk elemani tutar ve kucuk buyuk harf hassasiyetini kaldirir.
      order=tolower(line[0]);
      //Sil fonksiyonu yazilmissa
      if(order == "s"){
        //satirdaki ilk parantezden son paranteze kadar olan kismi string olarak tutar daha sonra int'e cevirir
        //en son olarak index degerine esitler
        index=stoi(line.substr(2,line.find(")")));
        //verilen indexteki elemani siler
        list->deleteToAnywhere(index);
        
      }
      // Ekle fonksiyonu yazilmissa
      if(order=="e"){

          //satirdaki 2. elemandan baslayarak diyeze kadar olan kismi index adli degiskene atar.
          //2 cikarilmasinin sebebi bastaki 'E(' kisimlarini atmakdir.
          index=stoi(line.substr(2,line.find("#")-2));

          //diyezden bir sonraki elemandan baslayarak son paranteze kadar olan kismi data adli degiskene atar.
          //elaman sayisindan diyezin degeri ve 2 cikarilmasinin sebebi bastaki diyez dahil diyeze kadar olan kismi ve sondaki parantezi atmaktir. 
          data=line.substr(line.find("#")+1,(line.length()-line.find("#")-2));

          //verilen index'e verilen datayi ekler
          list->addToAnywhere(index,data);
      }

    }
    //cift yonlu bagli listenin son halini yazdirir.
    list->printTheList();
    
    //dosyayi kapatir
    readFile.close();
  } 
  return 0;
}
