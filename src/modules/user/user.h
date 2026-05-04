#ifndef USERLIST_H
#define USERLIST_H

#include "../boolean.h"
#include "../mesinKata/mesinkata.h"

/* ********** DEFINISI TYPE User ********** */
#define MAX_USERS 20
#define MAX_PASS_LENGTH 20
#define MAX_EMAIL_LENGTH 255


typedef struct {
    int id;
    Word email;
    Word password;
} User;

/* ********** DEFINISI TYPE UserList ********** */
typedef struct {
    User users[MAX_USERS]; /* Array of Users */
} UserList;

/* ********** PRIMITIF ********** */

/* *** Konstruktor *** */

void createUser(User *user, int id, Word email, Word password);
/* Membentuk sebuah User dengan id, email, dan password yang diberikan */
/* I.S. id, email, dan password terdefinisi */
/* F.S. user terbentuk dengan nilai yang diberikan */

void createUserList(UserList *list);
/* Membuat list user kosong */
/* I.S. list sembarang */
/* F.S. list terbentuk dengan count = 0 */

/* *** Kelompok Baca/Tulis File Konfigurasi *** */


/* *** Validasi *** */

boolean isEmailValid(Word email);
/* Mengecek apakah email yang diberikan sesuai dengan aturan format email yang valid */
/* I.S. : email terdefinisi */
/* F.S. : Mengembalikan true jika email sesuai dengan format valid, false jika tidak */

boolean isEmailUsed(UserList list, Word email);
/* Mengecek apakah email sudah digunakan oleh user lain dalam UserList */
/* I.S. : list terdefinisi, email terdefinisi */
/* F.S. : Mengembalikan true jika email sudah ada di dalam UserList, false jika tidak */

boolean isPasswordValid(Word password);
/* Mengecek apakah password memenuhi aturan atau syarat tertentu */
/* I.S. : password terdefinisi */
/* F.S. : Mengembalikan true jika password valid, false jika tidak */

/* *** Operasi terhadap UserList *** */
void Register(UserList *list);
/* Menambahkan user baru ke dalam list */
/* I.S. list terdefinisi, count >= 0 */
/* F.S. Jika jumlah user < MAX_USERS, user ditambahkan ke list dan count bertambah */
/* Mengembalikan true jika user berhasil ditambahkan, false jika penuh */

/* *** Validasi Registrasi *** */
boolean validateRegister(UserList list, Word email, Word password);
/* Memvalidasi data registrasi user baru */
/* I.S. list, email, dan password terdefinisi */
/* F.S. Mengembalikan true jika email belum digunakan dan password memenuhi kriteria */
/* Password harus memiliki minimal panjang MIN_PASSWORD_LENGTH */

User findUserByEmail(UserList list, Word email);
/* Mencari user berdasarkan email */
/* I.S. list terdefinisi, email terdefinisi */
/* F.S. Mengembalikan user jika ditemukan*/

User findUserByID(UserList list, int id);
/* Mencari user berdasarkan id */
/* I.S. list terdefinisi, id terdefinisi */
/* F.S. Mengembalikan user jika ditemukan */

User Login(UserList *list, User user);
/* Mencari user berdasarkan email dan password */
/* I.S. list terdefinisi */
/* F.S. Mengembalikan user jika ditemukan */

int countUser(UserList list);
/* Menghitung jumlah user dalam list */
/* I.S. list terdefinisi */
/* F.S. Mengembalikan jumlah user dalam list */

boolean isUserListFull(UserList list);
/* Mengembalikan true jika jumlah user dalam list telah mencapai kapasitas maksimum */

boolean isUserListEmpty(UserList list);
/* Mengembalikan true jika tidak ada user dalam list */

/* *** Kelompok Baca/Tulis *** */
void displayUser(User user);
/* Menampilkan informasi user */
/* I.S. user terdefinisi */
/* F.S. Informasi user ditampilkan ke layar */

void displayAllUsers(UserList list);
/* Menampilkan semua user dalam list */
/* I.S. list terdefinisi */
/* F.S. Informasi semua user dalam list ditampilkan ke layar */

Word getEmailById(UserList list, int id);
/* Mengembalikan email pengguna berdasarkan ID yang diberikan dalam UserList */
/* I.S. list terdefinisi */
/* F.S. Informasi email user */

int getIdByEmail(UserList list, Word email);
/* Mengembalikan ID pengguna berdasarkan email yang diberikan dalam UserList */
/* I.S. list terdefinisi */
/* F.S. Informasi ID user */

#endif
