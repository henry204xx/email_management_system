


#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "mesinkarakter.h"

/* Variabel global */
static FILE *pita;
static int retval;
char currentChar;
boolean EOP;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
    pita = stdin;  
    ADV();         
}

void ADV() {
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika currentChar = MARK maka EOP akan menyala (true) */
   if (pita != NULL) {
      retval = fscanf(pita, "%c", &currentChar);
      if (retval == EOF) 
      {
         EOP = true;       
         if (pita != stdin) {
            fclose(pita);
            pita = NULL;
         }
      } 
      else EOP = (currentChar == MARK); 
   } else {
      currentChar = MARK;
      EOP = true;
   }
}

void STARTFILE(char* fileName) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) 
          Jika file tidak bisa dibaca maka mesin akan berhenti */
   pita = fopen(fileName, "r"); 
   if (pita == NULL) 
   {
      printf("Tidak dapat membuka file %s\n", fileName);
      EOP = true; 
   } 
   else ADV(); 
}
