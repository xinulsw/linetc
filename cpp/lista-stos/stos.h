#include "lista.h"

class Stos
{
  private:
    Lista lista;
  public:
    void Push(int value);
    int Pop();
    bool Pusty();
};
