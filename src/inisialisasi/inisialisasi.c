#include <stdio.h>
#include <stdlib.h>
#include "../modules/boolean.h"
#include "../modules/user/user.h"
#include "../modules/email/email.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../modules/naryTree/narytree.h"
#include "../load/load.h"

void Inisialisasi(EmailList *emailList, UserList *userList, NaryTree *tree, int *pagination, int *important) {
    Word folderNameWord;   
    char *folderName, *folderPath, *umum, *email, *pengguna;     
    boolean loaded = false;

    printf("Selamat datang di PurryMail!\n\n");

    while (!loaded) {
        printf("Masukkan folder konfigurasi untuk dimuat: ");
        STARTSENTENCE(); 
        folderNameWord = currentWord; 
        folderName = WordtoString(folderNameWord);
        folderPath = concatStrings("config/", folderName);

        if (loadConfigFolder(folderPath)) {

            printf("1...\n");
            umum = concatStrings(folderPath, "/umum.config");
            LoadUmumConfig(umum, pagination, important);

            // Load pengguna.config
            printf("2...\n");
            pengguna = concatStrings(folderPath, "/pengguna.config");
            LoadUserConfig(pengguna, userList);

            // Load email.config
            printf("3...\n");
            email = concatStrings(folderPath, "/email.config");
            LoadEmailConfig(emailList, tree, email);
            printf("File konfigurasi berhasil dimuat dari folder '%s'!\n", folderName);
            loaded = true; 
        } else {
            printf("Folder '%s' tidak valid atau konfigurasi tidak lengkap. Silakan coba lagi.\n", folderName);
        }
    }
}