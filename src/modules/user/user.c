#include "user.h"
#include <stdio.h>



boolean isEmailValid(Word email) {
    if (email.Length > MAX_EMAIL_LENGTH) return false;

    boolean atFound = false, dotAgain = false, firstpart = false, secondpart = false, thirdpart = false;
    // boolean dotFound = false;
    int atIndex = -1, dotIndex = -1, prevDotIndex = -1;


    for (int i = 0; i < email.Length; i++) {
        char c = email.TabWord[i];

        //first part of regex
        if (firstpart == false) {
            if (c != '+' && c != '-' && c != '.' && c != '_' && c != '%' && (c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c != '@')) return false;
            
            if (c == '@') {
                if (atFound) return false; // @ lebih dari satu
                if (i == 0) return false; // '@' di awal
                atFound = true;
                firstpart = true;
                atIndex = i;
        }
    
        } 
        
        else if (secondpart == false) {
            if (c != '.' && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) return false;
            if (c != '.') {
                dotAgain = false;
            }
            if (c == '.') {
                if (i == atIndex + 1) return false; // '.' after '@'
                if (dotAgain) return false; // '.' berturut-turut
                // dotFound = true;
                dotAgain = true;
                for (int k = i; k < email.Length; k++) { //check where the last dot is
                    char check = email.TabWord[k];
                    if (check == '.') {
                        prevDotIndex = dotIndex;
                        dotIndex = k;
                    }
                }
                if (dotIndex == -1 || prevDotIndex == dotIndex-1 || (email.Length - dotIndex - 1) < 2) return false; // panjang domain >= 2
            secondpart = true;
            }
        }
        else if (thirdpart == false) {
            if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) return false;
            thirdpart = true;
        }
    }

    return firstpart && secondpart && thirdpart;
}

/* *** Konstruktor *** */
void createUser(User *user, int id, Word email, Word password) {
    user->id = id;
    user->email = email;
    user->password = password;
}

void createUserList(UserList *list) {
    for (int i = 0; i < MAX_USERS; i++) {
        list->users[i].id = -1;
    }
}



/* *** Operasi terhadap UserList *** */
void Register(UserList *list) {

    if (isUserListFull(*list)) {
        printf("Register gagal. Jumlah user sudah maksimal.\n");
    }

    else {
        User newUser;
        printf("Masukkan email: ");
        STARTWORD();
        newUser.email = currentWord;
        if (!isEmailValid(newUser.email)) {
            printf("Email yang dimasukkan tidak valid.\n");}

        else if (isEmailUsed(*list, newUser.email)) {
            printf("Maaf, email address %s sudah terdaftar :(. Harap pilih email address yang lain.\n", WordtoString(newUser.email));
        }

        else {
            printf("Masukkan password: ");
            STARTWORD();
            newUser.password = currentWord;
            if (!isPasswordValid(newUser.password)) {
                printf("Password yang dimasukkan tidak valid.\n");
                }
            else {
                for (int i = 0; i < MAX_USERS; i++) {
                    if (list->users[i].id == -1) {
                        newUser.id = i + 1;
                        list->users[i] = newUser;
                        printf("Akun dengan email address %s berhasil didaftarkan! Silahkan gunakan perintah LOGIN untuk mengakses fitur-fitur PurryMail.\n", WordtoString(newUser.email));
                        break;
                    }
                }
            }
        }
    }

    }


boolean isEmailUsed(UserList list, Word email) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id != -1 && isWordsEqual(list.users[i].email, email)) {
            return true;
        }
    }
    return false;
}

boolean isPasswordValid(Word password) {
    return (password.Length > 0 && password.Length <= MAX_PASS_LENGTH);
}

boolean validateRegister(UserList list, Word email, Word password) {
    if (!isPasswordValid (password) || isEmailUsed(list, email) || !isEmailValid(email)) return false; // register tidak valid
    return true; // register valid
}

User findUserByEmail(UserList list, Word email) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (isWordsEqual(list.users[i].email, email)) {
            return list.users[i];
        }
    }
    User emptyUser;
    emptyUser.id = -1;
    return emptyUser;
}
/* Mencari user berdasarkan email */
/* I.S. list terdefinisi, email terdefinisi */
/* F.S. Mengembalikan user jika ditemukan*/

User findUserByID(UserList list, int id) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id == id) {
            return list.users[i];
        }
    }
    User emptyUser;
    emptyUser.id = -1;
    return emptyUser;
}

/* Mencari user berdasarkan id */
/* I.S. list terdefinisi, id terdefinisi */
/* F.S. Mengembalikan user jika ditemukan */
User Login(UserList *list, User user) {
    
    for (int i = 0; i < MAX_USERS; i++) {
        if (isWordsEqual(list->users[i].email, user.email) && isWordsEqual(list->users[i].password, user.password)) {
            printf("Login berhasil, selamat datang di PurryMail!\n");
            return list->users[i];
        }
    }
    User emptyUser;
    emptyUser.id = -1;
    printf("Email atau password salah.\n");
    return emptyUser;
}

int countUser(UserList list) {
    int count = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id != -1) {
            count++;
        }
    }
    return count;
}

boolean isUserListFull(UserList list) {
    return countUser(list) >= MAX_USERS;
}

boolean isUserListEmpty(UserList list) {
    return countUser(list) == 0;
}

/* *** Kelompok Baca/Tulis *** */
void displayUser(User user) {
    if (user.id == -1) {
        printf("User tidak ditemukan.\n");
        return;
    }

    printf("USER%03d\n", user.id);
    printf("Email: ");
    for (int i = 0; i < user.email.Length; i++) {
        printf("%c", user.email.TabWord[i]); 
    }
    // printf("\nPassword: ");
    // for (int i = 0; i < user.password.Length; i++) {
    //     printf("%c", user.password.TabWord[i]); 
    // }
    printf("\n");
}

void displayAllUsers(UserList list) {
    if (isUserListEmpty(list)) {
        printf("Tidak ada user.\n");
        return;
    }

    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id != -1) {
            displayUser(list.users[i]);
            printf("\n");
        }
    }
}

Word getEmailById(UserList list, int id) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id == id) {
            return list.users[i].email;
        }
    }

    // Jika tidak ditemukan, return email kosong
    Word emptyWord;
    emptyWord.Length = 0;
    return emptyWord;
}

int getIdByEmail(UserList list, Word email) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (list.users[i].id != -1 && isWordsEqual(list.users[i].email, email)) {
            return list.users[i].id;
        }
    }

    // Jika tidak ditemukan, kembalikan ID tidak valid (misalnya -1)
    return -1;
}

