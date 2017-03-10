
typedef struct ELEMENT{
  int value;
  ELEMENT* next;  
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
    Lista();
    ~Lista();
    void Dodaj(int value);
    bool Wstaw(int value, int position);
    bool Usun();
    bool Usun(int);
    void Wyswietl();
};
