#include <iostream>
#include "lista.h"

Lista::Lista(){
  header.head = NULL;
  header.tail = NULL;
}

Lista::~Lista(){
  while(Usun());
}

void Lista::Dodaj(int wartosc){
  ELEMENT* el = new ELEMENT; // utworzenie nowego elementu listy
  el->wartosc = wartosc;
  el->nast = NULL;
  if(header.head == NULL){ // jeżeli lista pusta
    header.head = el; //ustawienie wskaźników na 1 element
    header.tail = el;
  } else{
    header.tail->nast = el;
    header.tail = el;
  }
}

void Lista::Wyswietl(){
  ELEMENT* el = header.head;
  while(el != NULL){
    std::cout << el->wartosc << " ";
    el = el->nast;
  }
  std::cout << std::endl;
}

bool Lista::Usun(){
  if(header.head != NULL){
    if(header.head == header.tail){ //ostatni element listy
      delete header.head;
      header.head = NULL;
      header.tail = NULL;
    } else{
      ELEMENT* el = header.head;
      while(el->nast != header.tail){
        el = el->nast;
      }
      delete el->nast;
      el->nast = NULL;
      header.tail = el;
    }
    return true;
  } else
      return false;
}

bool Lista::Wstaw(int wartosc, int pozycja){
  if(pozycja < 0) return false;
  ELEMENT* temp = new ELEMENT;
  temp->wartosc = wartosc;
  if (pozycja == 0){
    temp->nast = header.head;
    header.head = temp;
  }
  else{
    ELEMENT* el = header.head;
    int i = 0;
    while(el != NULL && ++i < pozycja)
      el = el->nast;
      if(el == NULL){
        delete temp;
        return false;
      }
    temp->nast = el->nast;
    el->nast = temp;
  }
  if(temp->nast == NULL){
    header.tail = temp;
  }
  return true;
}

bool Lista::Usun(int pozycja){
  if(pozycja < 1 || header.head == NULL) return false;
  if(pozycja == 1){
    if(header.head->nast == NULL){
      delete header.head;
      header.head = NULL;
      header.tail = NULL;
    }
    else{
      ELEMENT* temp = header.head->nast;
      delete header.head;
      header.head = temp;
    }
  }
  else{
    ELEMENT* el = header.head;
    int i = 1;
    while(el != NULL && ++i < pozycja)
      el = el->nast;
    if(el == NULL) return false;
    if(el->nast == NULL) return false;
    ELEMENT* temp = el->nast->nast;
    delete el->nast;
    el->nast = temp;
    if (temp == NULL)
      header.tail = el;
  }
  return true;
}
