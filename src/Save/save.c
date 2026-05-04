#include "../modules/email/email.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/user/user.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "../modules/mesinKata/mesinkata.h"
#include "save.h"
#include "../load/load.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void writeUsersToFile(const char *filename, UserList *list) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    fprintf(file, "%d\n", countUser(*list));
    for (int i = 0; i < MAX_USERS; i++) {
        if (list->users[i].id != -1) {
            fprintf(file, "%d\n", list->users[i].id);
            fprintf(file, "%s\n", WordtoString(list->users[i].email));
            fprintf(file, "%s", WordtoString(list->users[i].password));
            if (i < countUser(*list) - 1) {
                fprintf(file, "\n");
            }
        }
    }

    fclose(file);
}

void writeEmailsToFile(const char *filename, EmailList *Elist) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    fprintf(file, "%d\n", Elist->count);
    for (int i = 0; i < Elist->count; i++) {
        fprintf(file, "%d\n", Elist->emails[i].emailID);
        fprintf(file, "%d\n", Elist->emails[i].senderID);
        fprintf(file, "%d\n", Elist->emails[i].recipientID);
        fprintf(file, "%d\n", Elist->emails[i].ccID);
        fprintf(file, "%s\n", DateTimetoString(Elist->emails[i].timestamp));
        fprintf(file, "%s\n", WordtoString(Elist->emails[i].subject));
        fprintf(file, "%s\n", BodytoString(Elist->emails[i].body));
        fprintf(file, "%d\n", Elist->emails[i].replyToID);
        fprintf(file, "%d\n", Elist->emails[i].readStatus);
        fprintf(file, "%d", Elist->emails[i].ccStatus);
        if (i < Elist->count - 1) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

void writeUmumtoFile(const char *filename, int pagination, int important) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }

    fprintf(file, "%d\n", pagination);
    fprintf(file, "%d", important);

    fclose(file);
}

void SAVE(EmailList emailList, UserList userList, int pagination, int important) {
    char *folderPath, *folderName;
    Word folderInput;

    printf("Masukkan nama folder penyimpanan: ");
    STARTSENTENCE();
    folderInput = currentWord;
    folderName = WordtoString(folderInput);
    folderPath = concatStrings("config/", folderName);
    
    if (!folderExists(folderPath)) {
        printf("Folder '%s' tidak ditemukan. Membuat folder...\n", folderName);
        printf("1...\n");
        printf("2...\n");
        printf("3...\n");
        if (mkdir(folderPath, 0777) != 0) {
            printf("Error: Tidak dapat membuat folder '%s'.\n", folderName);
            return;
        }
        printf("Folder '%s' berhasil dibuat.\n", folderName);
    }

    printf("Anda akan melakukan penyimpanan di '%s'.\n", folderName);
    printf("1...\n");
    writeEmailsToFile(concatStrings(folderPath, "/email.config"), &emailList);
    printf("2...\n");
    writeUsersToFile(concatStrings(folderPath, "/pengguna.config"), &userList);
    printf("3...\n");
    writeUmumtoFile(concatStrings(folderPath, "/umum.config"), pagination, important);


    printf("Data berhasil disimpan ke folder '%s'.\n", folderName);
}

// int main() {
//     // Step 1: Create an EmailList with a capacity of 5
//     EmailList emailList;
//     CreateEmailList(&emailList, 5);

//     Body body = {"jere\ndsd\nsadj\n", 14, 3};
//     // Step 2: Create 5 Email objects and initialize them with sample data
//     Email email1, email2, email3, email4, email5;

//     // Initialize email1
//     CreateEmail(&email1);
//     email1.emailID = 1;
//     email1.senderID = 101;
//     email1.recipientID = 202;
//     email1.ccID = -1;
//     email1.timestamp = GetCurrentDateTime();
//     email1.subject = StringtoWord("Subject 1");
//     email1.body = body;  // Use StringtoBody to create Body
//     email1.replyToID = -1;
//     email1.readStatus = 0;
//     email1.ccStatus = 0;

//     // Initialize email2
//     CreateEmail(&email2);
//     email2.emailID = 2;
//     email2.senderID = 102;
//     email2.recipientID = 203;
//     email2.ccID = -1;
//     email2.timestamp = GetCurrentDateTime();
//     email2.subject = StringtoWord("Subject 2");
//     email2.body = StringtoBody("Body of Email 2");  // Use StringtoBody to create Body
//     email2.replyToID = -1;
//     email2.readStatus = 0;
//     email2.ccStatus = 0;

//     // Initialize email3
//     CreateEmail(&email3);
//     email3.emailID = 3;
//     email3.senderID = 103;
//     email3.recipientID = 204;
//     email3.ccID = -1;
//     email3.timestamp = GetCurrentDateTime();
//     email3.subject = StringtoWord("Subject 3");
//     email3.body = StringtoBody("Body of Email 3");  // Use StringtoBody to create Body
//     email3.replyToID = -1;
//     email3.readStatus = 0;
//     email3.ccStatus = 0;

//     // Initialize email4
//     CreateEmail(&email4);
//     email4.emailID = 4;
//     email4.senderID = 104;
//     email4.recipientID = 205;
//     email4.ccID = -1;
//     email4.timestamp = GetCurrentDateTime();
//     email4.subject = StringtoWord("Subject 4");
//     email4.body = StringtoBody("Body of Email 4");  // Use StringtoBody to create Body
//     email4.replyToID = -1;
//     email4.readStatus = 0;
//     email4.ccStatus = 0;

//     // Initialize email5
//     CreateEmail(&email5);
//     email5.emailID = 5;
//     email5.senderID = 105;
//     email5.recipientID = 206;
//     email5.ccID = -1;
//     email5.timestamp = GetCurrentDateTime();
//     email5.subject = StringtoWord("Subject 5");
//     email5.body = StringtoBody("Body of Email 5");  // Use StringtoBody to create Body
//     email5.replyToID = -1;
//     email5.readStatus = 0;
//     email5.ccStatus = 0;

//     // Step 3: Add the emails to the EmailList
//     AddEmailToList(&emailList, email1);
//     AddEmailToList(&emailList, email2);
//     AddEmailToList(&emailList, email3);
//     AddEmailToList(&emailList, email4);
//     AddEmailToList(&emailList, email5);

//     // Optional: Print the emails to verify
//     for (int i = 0; i < emailList.count; i++) {
//         printf("Email %d: Subject = %s, SenderID = %d, RecipientID = %d\n",
//             emailList.emails[i].emailID,
//             WordtoString(emailList.emails[i].subject),
//             emailList.emails[i].senderID,
//             emailList.emails[i].recipientID);
//     }

//     writeEmailsToFile("emails.txt", &emailList);

//     return 0;
// }
