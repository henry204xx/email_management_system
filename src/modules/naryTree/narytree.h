/* File: narytree.h */
/* ADT N-ary Tree */
/* Representasi Address dengan pointer */
/* int adalah integer */

#ifndef NARY_TREE_H
#define NARY_TREE_H

#include "../boolean.h"

/* Selektor */
#define TR_PARENT(p) (p)->parent
#define TR_EMAILID(p) (p)->emailId
#define TR_NEXT_SIBLING(p) (p)->next_sibling
#define TR_FIRST_CHILD(p) (p)->first_child

typedef struct treeNode* TR_Address;

typedef struct treeNode {
    TR_Address parent;
    int emailId;
    TR_Address next_sibling;
    TR_Address first_child;
} TreeNode;

/* Definisi N-Ary Tree */
/* Tree kosong p = NULL */

typedef TR_Address NaryTree;

/* ****** KONSTRUKTOR ****** */
TR_Address newTreeNode(int val);
/* Alokasi sebuah address untuk node baru, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi elemen dengan nilai val */
/* Jika alokasi berhasil: p.parent=NULL, p.next_sibling=NULL, p.first_child=NULL */
/* Jika alokasi gagal: NULL */

void deallocTreeNode(TR_Address p);
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address p */

void addChild(NaryTree parent, NaryTree child);
/* I.S. parent terdefinisi, child adalah node baru */
/* F.S. child menjadi anak dari parent */
/* Child ditambahkan sebagai first_child jika parent belum memiliki anak */
/* Jika parent sudah memiliki anak, child ditambahkan sebagai next_sibling dari anak yang ada */

/* ****** PREDIKAT ****** */
boolean isTreeEmpty(NaryTree p);
/* Mengirimkan true jika p adalah pohon kosong */

boolean isOneElmt(NaryTree p);
/* Mengirimkan true jika p hanya terdiri dari satu elemen (p != NULL dan tidak memiliki child maupun sibling) */

boolean hasParent(NaryTree p);
/* Mengirimkan true jika p memiliki parent */

boolean hasChildren(NaryTree p);
/* Mengirimkan true jika p memiliki minimal satu child */

boolean hasSiblings(NaryTree p);
/* Mengirimkan true jika p memiliki next_sibling */

/* ****** SEARCH TREE ****** */
TR_Address findNode(NaryTree root, int val);
/* Mencari node dengan nilai tertentu dalam N-ary tree */
/* Mengembalikan address dari node dengan emailId = val jika ditemukan */
/* Jika tidak ditemukan, mengembalikan NULL */
/* Proses:
   - Mencari pada node root terlebih dahulu.
   - Jika tidak ditemukan, mencari secara rekursif di anak-anak dan saudara-saudara root.
   - Jika pohon kosong (root = NULL), langsung mengembalikan NULL.
*/

int countAncestors(NaryTree p);
/* Menghitung ancestor dari p */

TR_Address findSecondLastAncestors(NaryTree p);
/* Mencari second last ancestor dari p */

/* ****** DISPLAY TREE ****** */
void printTree(NaryTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p dicetak dalam format satu baris:
   <Node>(<Child1><Child2>...<ChildN>)
   Jika pohon kosong, menghasilkan ().
   Contoh:
   - Pohon dengan akar A dan dua anak B, C:
     A(B()C())
   - Pohon dengan akar A, anak B yang memiliki anak D dan E, serta anak C:
     A(B(D()E())C())
*/

#endif