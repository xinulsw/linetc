#include <iostream>
#include "lista.h"

using namespace std;

Lista::Lista(){
  header.head = NULL;
  header.tail = NULL;
}

Lista::~Lista(){
  while(header.head != NULL)
    Usun();
}

void Lista::Dodaj(int value){
  ELEMENT* el = new ELEMENT;
  el->value = value;
  el->next = NULL;
  if(header.head == NULL){
    header.head = el;
    header.tail = el;
  }
  else{
    header.tail->next = el;
    header.tail = el;
  }
}

bool Lista::Wstaw(int value, int position){
  if(position < 0) return false;
  ELEMENT* temp = new ELEMENT;
  temp->value = value;
  if (position == 0){
    temp->next = header.head;
    header.head = temp;
  }
  else{
    ELEMENT* el = header.head;
    int i = 0;
    while(el != NULL && ++i < position)
      el = el->next;
      if(el == NULL){
        delete temp;
        return false;
      }
    temp->next = el->next;
    el->next = temp;
  }
  if(temp->next == NULL){
    header.tail = temp;
  }
  return true;
}


bool Lista::Usun(int position){
  if(position < 1 || header.head == NULL) return false;
  if(position == 1){
    if(header.head->next == NULL){
      delete header.head;
      header.head = NULL;
      header.tail = NULL;
    }
    else{
      ELEMENT* temp = header.head->next;
      delete header.head;
      header.head = temp;
    }
  }
  else{
    ELEMENT* el = header.head;
    int i = 1;
    while(el != NULL && ++i < position)
      el = el->next;
    if(el == NULL) return false;
    if(el->next == NULL) return false;
    ELEMENT* temp = el->next->next;
    delete el->next;
    el->next = temp;
    if (temp == NULL)
      header.tail = el;
  }
  return true;
}

void Lista::Wyswietl(){
  ELEMENT* el = header.head;
  int i = 1;
  while(el != NULL){
    cout << el->value << endl;
    el = el->next;
  }
}

int Lista::Usun(){
  if(header.head != NULL){
    if(header.head == header.tail){
      int temp = header.head->value;
      delete header.head;
      header.head = NULL;
      header.tail = NULL;
      return temp;
    }
    else{
      ELEMENT* el = header.head;
      while(el->next != header.tail){
        el = el->next;
      }
      int temp = el->next->value;
      delete el->next;
      el->next = NULL;
      header.tail = el;
      return temp;
    }
  }
  return 0;
}

bool Lista::Pusta(){
  if(header.head == NULL)
    return true;
  else
    return false;
}
