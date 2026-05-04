#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../modules/email/email.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "load.h"
#include "../modules/boolean.h"
#include "../modules/user/user.h"
#include "../modules/naryTree/narytree.h"


void LoadUmumConfig(char *filename, int *pagination, int *important) {
    STARTFILEWORD(filename);
    *pagination = WordtoInt(currentWord);
    ADVWORDFILE();
    *important = WordtoInt(currentWord);
}

void LoadUserConfig(char *filename, UserList *list) {
    
    STARTFILEWORD(filename); 

    // Jumlah user
    int numberOfUsers = WordtoInt(currentWord);
    ADVWORDFILE();

    int userCount = 0;
    while (userCount < numberOfUsers) {
       
        //id
        int userID = WordtoInt(currentWord);
       
        ADVWORDFILE();

        //email
        Word userEmail = currentWord;
        ADVWORDFILE();
      
        //password
        Word userPassword = currentWord;
        ADVWORDFILE();
        
        User user;
        createUser(&user, userID, userEmail, userPassword);
        

        if (!isUserListFull(*list)) {
            list->users[userCount] = user;
        } 

        userCount++; 

    }
}

void LoadEmailConfig(EmailList *list, NaryTree *tree, char *filename) {
    

    STARTFILEWORD(filename); 
    // boolean HasEscape = false; // End = false;
    int numberOfEmails = WordtoInt(currentWord);
    CreateEmailList(list, numberOfEmails);

    int emailCount = 0;
    while (emailCount < numberOfEmails)
    {
        Email email;
        email.body.NEnter = 0;
        int lenBody = 0, lenWord;
        //HAPUS

        ADVWORDFILE();
       
        CreateEmail(&email);

        // Baca emailID
        email.emailID = WordtoInt(currentWord);
        ADVWORDFILE();

        // Baca senderID
        email.senderID = WordtoInt(currentWord);
        ADVWORDFILE();

        // Baca recipientID
        email.recipientID = WordtoInt(currentWord);
        ADVWORDFILE();

        // Baca ccID
        email.ccID = WordtoInt(currentWord);
        ADVSENTENCE();

        int day = 0, month = 0, year = 0, hour = 0, minute = 0, second = 0;
        // Baca timestamp
        for (int i = 0; i < currentWord.Length; i++)
        {
            if (i < 4) {
                day = day * 10 + currentWord.TabWord[i] - '0';
            } else if (i < 7 && i > 4) {
                month = month * 10 + currentWord.TabWord[i] - '0';
            }
            else if (i > 7 && i < 10) {
                year = year * 10 + currentWord.TabWord[i] - '0';
            }
            else if (i > 10 && i < 13) {
                hour = hour * 10 + currentWord.TabWord[i] - '0';
            }
            else if (i > 13 && i < 16) {
                minute = minute * 10 + currentWord.TabWord[i] - '0';
            }
            else if (i > 16 && i < 19) {
                second = second * 10 + currentWord.TabWord[i] - '0';
            }
        }
        DateTime dt = CreateDateTime(year, month, day, hour, minute, second);
        email.timestamp = dt;

        
        // free(timestampStr); 
        ADVSENTENCE();

        // Baca subject
        email.subject = currentWord;
        
        while (true)
        {
            ADVSENTENCE();
            lenWord = currentWord.Length;
            for (int i = 0; i < lenWord; i++)
            {
                email.body.TabWord[lenBody++] = currentWord.TabWord[i];
            }
            if (email.body.TabWord[lenBody - 1] == ESCAPE)
            {
                email.body.TabWord[lenBody - 1] = ENTER;
               // HasEscape = true;
                email.body.NEnter++;
            }
            else break;
        }
        email.body.Length = lenBody;

        ADVWORDFILE();

        // Baca replyToID
        email.replyToID = WordtoInt(currentWord);
        addChild(findNode(*tree, email.replyToID), newTreeNode(email.emailID));
        ADVWORDFILE();

        // Baca readStatus
        email.readStatus = WordtoInt(currentWord);
        ADVWORDFILE();

        // Baca ccStatus
        email.ccStatus = WordtoInt(currentWord);

        // Tambahkan email ke list
        AddEmailToList(list, email);

        emailCount++;
    
    }
}


boolean folderExists(char *folderPath) {
    struct stat info;
    if (stat(folderPath, &info) == 0) {
        if (S_ISDIR(info.st_mode)) {
            return true; 
        }
    }
    return false;
}


boolean validateConfigFolder(char *folderPath) {
    char *pengguna, *umum, *email;
    FILE *file;
    
    pengguna = concatStrings(folderPath, "/pengguna.config");
    file = fopen(pengguna, "r");
    if (!file) return false;
    fclose(file);

    
    umum = concatStrings(folderPath, "/umum.config");
    file = fopen(umum, "r");
    if (!file) return false;
    fclose(file);

    
    email = concatStrings(folderPath, "/email.config");
    file = fopen(email, "r");
    if (!file) return false;
    fclose(file);
    
    return true;
}


boolean loadConfigFolder(char *folderPath) {
    if (!folderExists(folderPath)) {
        return false;
    }
    if (!validateConfigFolder(folderPath))return false;
    
    return true;
}


void LOAD(EmailList *emailList, UserList *userList, NaryTree *tree, int *pagination, int *important) {
    char* folderName, *folderPath, *email, *pengguna, *umum;
    printf("Masukkan nama folder yang hendak dimuat: ");
    STARTSENTENCE();
    folderName = WordtoString(currentWord);
    folderPath = concatStrings("config/", folderName);

    if (loadConfigFolder(folderPath)) {
        printf("Anda akan melakukan pemuatan dari folder %s.\n\n", folderName);

        printf("Mohon tunggu...\n");
        // Load umum.config
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

        printf("Pemuatan selesai!\n");
    } else {
        printf("Folder '%s' tidak ditemukan atau konfigurasi tidak lengkap!\n", folderName);
    }
}
