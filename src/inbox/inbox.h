#ifndef INBOX_H
#define INBOX_H

#include "../modules/email/email.h"
#include "../modules/naryTree/narytree.h"
#include "../balasPesan/balasPesan.h"


// Konstanta untuk batas batch


// Fungsi untuk filter email yang diterima user
EmailList filterInbox(EmailList list, UserList userList, int userID);

// Fungsi untuk menampilkan email yang diterima user
void TampilkanInbox(EmailList list, UserList userList, int page, int pagination);

// Fungsi untuk menampilkan daftar inbox
void DaftarInbox(EmailList list, UserList userList, int pagination);

// Fungsi untuk menampilkan halaman berikutnya
void LanjutInbox(EmailList list, UserList userList, int *currentPage, int pagination);

// Fungsi untuk menampilkan halaman sebelumnya
void SebelumInbox(EmailList list, UserList userList, int *currentPage, int pagination);

// Fungsi untuk membaca pesan berdasarkan ID email
void BacaPesan(EmailList *list, EmailList *filteredList, NaryTree replyTree, int emailID, UserList userList);

// Fungsi untuk mengubah status email menjadi telah dibaca
void UbahStatusBaca(Email *email);

#endif