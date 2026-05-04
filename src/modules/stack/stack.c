#include "stdio.h"
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
    return Top(S) == Nil;
}

boolean IsOneElmt(Stack S){
    return Top(S) == 0;
}

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S){
    return Top(S) == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushToStack(Stack * S, infotype X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DealocStack(Stack *S){
    /* I.S. Stack S terdefinisi */
    /* F.S. Stack S dalam keadaan kosong*/
    Top(*S) = Nil;
}

void deleteFirstElement(Stack *S){
    Stack Stemp;
    CreateEmptyStack(&Stemp);
    while (!IsOneElmt(*S)){
        infotype X;
        PopStack(S, &X);
        PushToStack(&Stemp, X);
    }
    infotype Y;
    PopStack(S, &Y);
    while (!IsEmptyStack(Stemp)){
        infotype X;
        PopStack(&Stemp, &X);
        PushToStack(S, X);
    }
}