#ifndef LISTA_H
#define LISTA_H

typedef struct ELEMENT{
  int wartosc;
  ELEMENT* nast;
}ELEMENT;

typedef struct HEADER{
  ELEMENT* head;
  ELEMENT* tail;
}HEADER;

class Lista
{
  private:
    HEADER header;
  public:
    Lista(); //konstruktor
    ~Lista(); //dekonstruktor
    void Dodaj(int);
    bool Wstaw(int, int);
    bool Usun();
    bool Usun(int);
    void Wyswietl();
};

#endif
