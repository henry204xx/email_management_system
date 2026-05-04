#ifndef EMAIL_H
#define EMAIL_H

#include "../boolean.h"
#include "../mesinKata/mesinkata.h"
#include "../mesinKata/mesinkarakter.h"
#include "../Datetime/datetime.h"
#include "../user/user.h"

/* ********** DEFINISI EMAIL ********** */
// Email kosong : Berisi nilai default masing-masing

typedef struct {
    int emailID;         // ID unik untuk email
    int senderID;        // ID pengirim (referensi ID dari konfigurasi pengguna)
    int recipientID;     // ID penerima
    int ccID;            // ID penerima CC (-1 jika tidak ada)
    DateTime timestamp;  // Waktu pengiriman/penerimaan
    Word subject;        // Subjek email
    Body body;           // Isi email
    int replyToID;       // ID email induk balasan (-1 jika bukan balasan)
    int readStatus;      // Status membaca (0 = Unread, 1 = Read)
    int ccStatus;        // Status membaca CC (0 = Unread, 1 = Read)
} Email;

/* ********** DEFINISI LIST EMAIL ********** */
typedef struct {
    Email *emails;  // Pointer to array of emails
    int count;      // Number of emails in the list
    int capacity;   // Capacity of the list
} EmailList;

/* ***********SELEKTOR*********** */
#define EmailID(E) (E).emailID
#define SenderID(E) (E).senderID
#define RecipientID(E) (E).recipientID
#define CarbonCopyID(E) (E).ccID
#define Timestamp(E) (E).timestamp
#define Subject(E) (E).subject
#define Body(E) (E).body
#define ReplyToID(E) (E).replyToID
#define ReadStatus(E) (E).readStatus
#define CcStatus(E) (E).ccStatus

#define Draft(D) (D).draft
#define History(D) (D).history


/* ***********KONSTRUKTOR*********** */
void CreateEmail(Email *e);

/* ********** DEALOKASI ********** */
// void DealocEmail(Email *email);
// void DealocDraft(Stack *draft);

/* ***********KHUSUS EMAIL LIST*********** */
void CreateEmailList(EmailList *list, int capacity);
// /* I.S. sembarang */
// /* F.S. Sebuah EmailList kosong terbentuk dengan kapasitas sebesar capacity */
// /* Proses: Melakukan alokasi memori untuk EmailList dan menginisialisasi jumlah elemen (size) menjadi 0, 
//    serta kapasitas sesuai parameter yang diberikan */

void DealocEmail(Email *email);
/* I.S. Email terdefinisi */
/* F.S. Memori yang digunakan oleh Email dibebaskan */
/* Proses: Membebaskan memori yang dialokasikan untuk Email */
void DealocEmailList(EmailList *list);
// /* I.S. EmailList terdefinisi */
// /* F.S. Memori yang digunakan oleh EmailList dilepaskan */
// /* Proses: Membebaskan memori yang dialokasikan untuk EmailList */

void AddEmailToList(EmailList *list, Email email);
/* I.S. EmailList terdefinisi dan tidak penuh */
/* F.S. Email baru ditambahkan ke EmailList pada posisi paling akhir */
/* Proses: Memasukkan email ke elemen terakhir EmailList dan menambahkan jumlah elemen (size) */

#endif
