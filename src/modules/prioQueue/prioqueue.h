/* File : prioqueue.h */
/* Definisi ADT Priority Queue terurut mengecil berdasarkan nilai elemen */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define NIL NULL
#define IDX_UNDEF -1
#define PQ_CAPACITY 100

/* Definisi elemen dan address */
typedef struct PQ_node* PQ_Address;
typedef struct PQ_node {
    int emailId;
    boolean penting;
    PQ_Address next;
} PQ_Node;
typedef PQ_Address PrioQueue;


/* ********* AKSES (Selektor) ********* */
/* Jika a adalah Address, maka akses elemen: */
#define PQ_EMAILID(a) (a)->emailId
#define PQ_PENTING(a) (a)->penting
#define PQ_NEXT(a) (a)->next

/* *** Kreator *** */
void PQ_CreatePrioQueue(PrioQueue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi pq == NIL */
/* Proses : Melakukan alokasi, membuat sebuah pq NIL */

PQ_Address PQ_CreateNode(int emailId, boolean penting);
/* mengirimkan address dari node yang sudah dialokasikan */

/* *** Deletor *** */
void PQ_DeleteNode(PQ_Address address);
/* I.S. address teralokasi */
/* F.S. address telah di dealokasi */

/* ********* Prototype ********* */
boolean PQ_isEmpty(PrioQueue pq);
/* Mengirim true jika pq kosong, yaitu ketika pq == NIL */

int PQ_length(PrioQueue pq);
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

boolean PQ_hasEmail(PrioQueue pq, int emailId);
/* Mengirim true jika pq memiiki emailId */

/* *** Primitif Add/Delete *** */
void PQ_enqueue(PrioQueue *pq, int emailId, boolean penting);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai.*/

void PQ_dequeue(PrioQueue *pq, int *emailId, boolean *penting);
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. pq mungkin kosong */

void PQ_deleteEmail(PrioQueue *pq, int emailId);
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq sembarang */
/* F.S. pq tidak memiliki elemen yang mengandung emailId */

void PQ_displayPrioQueue(PrioQueue pq);
/* I.S. pq sembarang */
/* F.S. menampilkan setiap elemen dari pq dengan format 
        [[email1, penting1], [email2, penting2], ..., [emailn, pentingn]] */

#endif