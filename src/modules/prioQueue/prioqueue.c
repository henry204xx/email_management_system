#include "prioqueue.h"

/* *** Kreator *** */
void PQ_CreatePrioQueue(PrioQueue *pq)
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi pq == NIL */
/* Proses : Melakukan alokasi, membuat sebuah pq NIL */
{
    *pq = NIL;
}

PQ_Address PQ_CreateNode(int emailId, boolean penting)
/* mengirimkan address dari node yang sudah dialokasikan */
{
    PQ_Address a;
    a = (PQ_Address) malloc(sizeof(PQ_Node));
    PQ_EMAILID(a) = emailId;
    PQ_PENTING(a) = penting;
    PQ_NEXT(a) = NIL;

    return a;
}

/* *** Deletor *** */
void PQ_DeleteNode(PQ_Address address)
/* I.S. address teralokasi */
/* F.S. address telah di dealokasi */
{
    free(address);
}

/* ********* Prototype ********* */
boolean PQ_isEmpty(PrioQueue pq)
/* Mengirim true jika pq kosong, yaitu ketika pq == NIL */
{
    return (pq == NIL);
}

int PQ_length(PrioQueue pq)
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */
{
    PQ_Address p;
    int counter;

    p = pq;
    counter = 0;
    while (p != NIL) {
        counter++;
        p = PQ_NEXT(p);
    }
    return counter;
}

boolean PQ_hasEmail(PrioQueue pq, int emailId)
/* Mengirim true jika pq memiiki emailId */
{
    PQ_Address p;

    p = pq;
    while (p != NIL) {
        if (PQ_EMAILID(p) == emailId) {
            return true;
        }
    }
    return false;
}

/* *** Primitif Add/Delete *** */
void PQ_enqueue(PrioQueue *pq, int emailId, boolean penting)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai.*/
{
    PQ_Address p, q, new;
    boolean found;
    
    new = PQ_CreateNode(emailId, penting);
    p = *pq;
    q = NIL;
    found = false;
    while (!found && p != NIL) {
        if (!PQ_PENTING(p) && penting) {
            found = true;
        } else {
            q = p;
            p = PQ_NEXT(p);
        }
    }
    if (q == NIL) {
        PQ_NEXT(new) = *pq;
        *pq = new;
    } else {
        PQ_NEXT(new) = p;
        PQ_NEXT(q) = new;
    }

}

void PQ_dequeue(PrioQueue *pq, int *emailId, boolean *penting)
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. pq mungkin kosong */
{
    PQ_Address p;
    *emailId = PQ_EMAILID(*pq);
    *penting = PQ_PENTING(*pq);
    p = *pq;
    *pq = PQ_NEXT(*pq);
    PQ_DeleteNode(p);
}

void PQ_deleteEmail(PrioQueue *pq, int emailId)
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq sembarang */
/* F.S. pq tidak memiliki elemen yang mengandung emailId */
{
    PQ_Address p, q;
    // boolean found;

    p = *pq;
    while (p != NIL && PQ_EMAILID(p) == emailId) {
        *pq = PQ_NEXT(p);
        PQ_DeleteNode(p);
        p = *pq;
    }
    if (p != NIL) {
        q = p;
        p = PQ_NEXT(p);
    }
    while (p != NIL) {
        if (PQ_EMAILID(p) == emailId) {
            PQ_NEXT(q) = PQ_NEXT(p);
            PQ_DeleteNode(p);
            p = PQ_NEXT(q);
        } else {
            q = p;
            p = PQ_NEXT(p);
        }
    }
}

/* *** Primitif Display *** */
void PQ_displayPrioQueue(PrioQueue pq)
/* I.S. pq sembarang */
/* F.S. menampilkan setiap elemen dari pq dengan format 
        [[email1, penting1], [email2, penting2], ..., [emailn, pentingn]] */
{
    PQ_Address p;
    
    printf("[");
    p = pq;
    if (p != NIL) {
        printf("[%d, %d]", PQ_EMAILID(p), PQ_PENTING(p));
        p = PQ_NEXT(p);
        while (p != NIL) {
            printf(", [%d, %d]", PQ_EMAILID(p), PQ_PENTING(p));
            p = PQ_NEXT(p);
        }
    }
    printf("]\n");
}
