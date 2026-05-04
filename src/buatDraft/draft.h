/* NOTES: INI HANYALAH SEBUAH CONTOH DRIVER UNTUK MEMBANTU ANDA MEMAHAMI PENGGUNAAN ADT EMAIL*/

#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/stack/stack.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"


Word ReadWordMesin();


/* **************************************************************/
/* **********************FITUR DRAFT EMAIL***********************/
/* **************************************************************/
// jangan lupa inisialisasi di awal Stack Ds, Dsr;
void BUAT_DRAFT(Stack *Ds, Stack *Dsr, UserList *users, User currentuser);

/* LIHAT_DRAFT: Menampilkan draft yang sedang disusun */
void LIHAT_DRAFT(Stack *Ds, UserList *users);

void BATAL(Stack *Ds, Stack *Dsr);

void UBAH_DRAFT(Stack *Ds, Stack *Dsr, UserList *users, User currentuser);

void KIRIM_DRAFT(Stack *Ds, EmailList *list, User currentuser);

void UNDO(Stack *Ds, Stack *Dsr);

void REDO(Stack *Ds, Stack *Dsr);


// int main(){
//     Stack Ds, Dsr;
//     EmailList list;
//     UserList users;

//     int d;
//     boolean jalan = true;
//     while(jalan){
//         scanf("%d", &d);
//         if(d == 1){
//             BUAT_DRAFT(&Ds, &Dsr, &users);
//             printf("\n");
//             printf("\n");
//         }
//         else if(d == 2){
//             LIHAT_DRAFT(&Ds);
//             printf("\n");
//             printf("\n");
//         }
//         else if(d == 3){
//             UBAH_DRAFT(&Ds, &users);
//             printf("\n");
//             printf("\n");            
//         }
//         else if(d == 100){
//             UNDO(&Ds, &Dsr);
//             printf("\n");
//         }
//         else if(d == 101){
//             REDO(&Ds, &Dsr);
//             printf("\n");            
//         }
//         else if(d == 999){
//             KIRIM_DRAFT(&Ds, &list);
//         }
//         else{
//             jalan = false;
//         }
//     }
// }
