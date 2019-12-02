#include "header.h"

void central (Apontador r) {
   if (r != NULL) {
      central (r->Esq);
      printf ("%s\n", r->Reg.chave);
      central (r->Dir); 
   }
}
