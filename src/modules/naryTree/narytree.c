#include "narytree.h"
#include <stdlib.h>
#include <stdio.h>

/* ****** KONSTRUKTOR ****** */
TR_Address newTreeNode(int val)
/* Alokasi sebuah address untuk node baru, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi elemen dengan nilai val */
/* Jika alokasi berhasil: p.parent=NULL, p.next_sibling=NULL, p.first_child=NULL */
/* Jika alokasi gagal: NULL */
{
    TR_Address p = (TR_Address) malloc(sizeof(TreeNode));
    TR_PARENT(p) = NULL;
    TR_EMAILID(p) = val;
    TR_NEXT_SIBLING(p) = NULL;
    TR_FIRST_CHILD(p) = NULL;
    return p;
}

void deallocTreeNode(TR_Address p)
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address p */
{
    free(p);
}

void addChild(NaryTree parent, NaryTree child)
/* I.S. parent terdefinisi, child adalah node baru */
/* F.S. child menjadi anak dari parent */
/* Child ditambahkan sebagai first_child jika parent belum memiliki anak */
/* Jika parent sudah memiliki anak, child ditambahkan sebagai next_sibling dari anak yang ada */
{
    if (hasChildren(parent)) {
        TR_Address p = TR_FIRST_CHILD(parent);
        while (TR_NEXT_SIBLING(p) != NULL) {
            p = TR_NEXT_SIBLING(p);
        }
        TR_NEXT_SIBLING(p) = child;
    } else {
        TR_FIRST_CHILD(parent) = child;
    }
    TR_PARENT(child) = parent;
}

/* ****** PREDIKAT ****** */
boolean isTreeEmpty(NaryTree p)
/* Mengirimkan true jika p adalah pohon kosong */
{
    return (p == NULL);
}

boolean isOneElmt(NaryTree p)
/* Mengirimkan true jika p hanya terdiri dari satu elemen (p != NULL dan tidak memiliki child) */
{
    return (isTreeEmpty(TR_FIRST_CHILD(p)));
}

boolean hasParent(NaryTree p) 
/* Mengirimkan true jika p memiliki parent */
{
    return (!isTreeEmpty(TR_PARENT(p)));
}

boolean hasChildren(NaryTree p)
/* Mengirimkan true jika p memiliki minimal satu child */
{
    return (!isTreeEmpty(TR_FIRST_CHILD(p)));
}

boolean hasSiblings(NaryTree p)
/* Mengirimkan true jika p memiliki next_sibling */
{
    if (hasParent(p)) {
        TR_Address q = TR_FIRST_CHILD(TR_PARENT(p));
        while (q != NULL) {
            if (p != q) {
                return true;
            }
            q = TR_NEXT_SIBLING(q);
        }
    }
    return false;
}

/* ****** SEARCH TREE ****** */
TR_Address findNode(NaryTree root, int val) {
/* Mencari node dengan nilai tertentu dalam N-ary tree */
/* Mengembalikan address dari node dengan emailId = val jika ditemukan */
/* Jika tidak ditemukan, mengembalikan NULL */
/* Proses:
   - Mencari pada node root terlebih dahulu.
   - Jika tidak ditemukan, mencari secara rekursif di anak-anak dan saudara-saudara root.
   - Jika pohon kosong (root = NULL), langsung mengembalikan NULL.
*/
    if (root == NULL) {
        return NULL;
    }
    if (TR_EMAILID(root) == val) {
        return root;
    }

    TR_Address child = TR_FIRST_CHILD(root);
    while (child != NULL) {
        TR_Address result = findNode(child, val);
        if (result != NULL) {
            return result;
        }
        child = TR_NEXT_SIBLING(child);
    }
    return NULL;
}

int countAncestors(NaryTree p) {
    int count = 0;
    while (hasParent(p)) {
        count++;
        p = TR_PARENT(p);
    }
    return count;
}

TR_Address findSecondLastAncestors(NaryTree p) {
    while (hasParent(p) && hasParent(TR_PARENT(p))) {
        p = TR_PARENT(p);
    }
    return p;
}

/* ****** DISPLAY TREE ****** */
void printTree(NaryTree p)
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
{
    printf("%d", TR_EMAILID(p));
    printf("(");
    if (hasChildren(p)) {
        printTree(TR_FIRST_CHILD(p));
    }
    printf(")");
    if (TR_NEXT_SIBLING(p) != NULL) {
        printTree(TR_NEXT_SIBLING(p));
    }
}