#include "inbox.h"
#include <stdio.h>

EmailList filterInbox(EmailList list, UserList userList, int userID) {
    EmailList filteredEmails;
    CreateEmailList(&filteredEmails, 20);
    for (int i = list.count-1; i >= 0; i--) {
        if (list.emails[i].recipientID == userID || list.emails[i].ccID == userID) {
            AddEmailToList(&filteredEmails, list.emails[i]);
        }
    }
    return filteredEmails;
}

void DaftarInbox(EmailList list, UserList userList, int pagination) {
    TampilkanInbox(list, userList, 1, pagination);
}


void printDash(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
}

void TampilkanInbox(EmailList list, UserList userList, int page, int pagination) {
    User user;
    int start = (page - 1) * pagination;
    int end = start + pagination;
    if (end > list.count) {
        end = list.count;
    }

    int maxlen = 0;
    int maxlen2 = 0;
    for (int k = start; k < end; k++) {
        user = findUserByID(userList, list.emails[k].senderID);
        if (list.emails[k].subject.Length > maxlen) {
            maxlen = list.emails[k].subject.Length;
        }
        if (user.email.Length > maxlen2) {
            maxlen2 = user.email.Length;
        }
    }

    int dash = 48 + maxlen + maxlen2;

    

    printf("[");
    printDash(dash);
    printf("]\n");

    if (list.count != 0) {
       
    
    printf("[");
    if (dash % 2 != 0) {
        printDash(((dash-1)-33)/2);
    } else {
        printDash((dash-33)/2);
    }
    printf(" Anda memiliki %d pesan pada Inbox ", list.count);
    if (dash % 2 != 0) {
        printDash(((dash+1)-33)/2);
    } else {
        printDash((dash-33)/2);
    }
    printf("]\n"); }
    printf("[");
    if (dash % 2 != 0) {
        printDash(((dash+1)-18)/2);
    } else {
        printDash((dash-18)/2);
    }
    printf(" [ Daftar Inbox ] ");
    printDash((dash-18)/2);
    printf("]\n");
    printf("[");
    printDash(dash);
    printf("]\n");
    if (list.count == 0) {
        printf("|");
        int space = 12; 
        for (int i = 0; i < space; i++) {
            printf(" ");
        }  
        printf("Inbox anda masih kosong");
        for (int i = 0; i < space+1; i++) {
            printf(" ");
        }
        printf("|\n");
    }
    else {
    printf("| %-8s | %-*s | %-*s | %-7s | %-19s |\n", "Email ID", maxlen, "Subject", maxlen2, "Pengirim", "Status", "Timestamp");
    for (int i = start; i < end; i++) {
        user = findUserByID(userList, list.emails[i].senderID);
        printf("| EMAIL%-3.3d | %-*s | %-*s | %-7s | %-19s |\n",
                list.emails[i].emailID,
               maxlen, WordtoString(list.emails[i].subject),
               maxlen2, WordtoString(user.email),
               list.emails[i].readStatus ? "Read" : "Unread",
               DateTimetoString(list.emails[i].timestamp));
    }
    printf("[");
    printDash(dash);
    printf("]\n");
    printf("[");
    printDash((dash-22)/2);
    printf("     Page [%d]/[%d]     ", page, (list.count + pagination - 1) / pagination);
    printDash((dash-21)/2);
    printf("]\n"); }
    printf("[");
    printDash(dash);
    printf("]\n");
}

void LanjutInbox(EmailList list, UserList Userlist, int *currentPage, int pagination) {
    if ((*currentPage) * pagination < list.count) {
        (*currentPage)++;
        TampilkanInbox(list, Userlist, *currentPage, pagination);
    } else {
        printf("Kamu sudah berada di page terakhir.\n");
    }
}

void SebelumInbox(EmailList list, UserList Userlist, int *currentPage, int pagination) {
    if (*currentPage > 1) {
        (*currentPage)--;
        TampilkanInbox(list,  Userlist , *currentPage, pagination); 
    } else {
        printf("Kamu sudah berada di page pertama.\n");
    }
}

void BacaPesan(EmailList *emaillist, EmailList *list, NaryTree replyTree, int emailID, UserList userList) {
    User user;
    for (int i = 0; i < list->count; i++) {
        if (list->emails[i].emailID == emailID) {
    
            printf("[");
            printDash(75);
            printf("]\n");
            printf("[");
            printDash(30);
            printf("[ Baca Pesan ]");
            printDash(31);
            printf("]\n");
            printf("| %s %-62d |", "Email ID: ", list->emails[i].emailID);

            printf("\n");
            printf("| %s %-63s |", "Subject: ", WordtoString(list->emails[i].subject));
            user = findUserByID(userList, list->emails[i].senderID);
            printf("\n");
            printf("| %s %-62s |", "Pengirim: ", WordtoString(user.email));
            printf("\n");
            if (list->emails[i].ccStatus != 0) {
                User cc = findUserByID(userList, list->emails[i].ccStatus);
                printf("| %s %-68s |", "CC: ", WordtoString(cc.email));
            }
            printf("\n");
            printf("| %s %-61s |", "Timestamp: ", DateTimetoString(list->emails[i].timestamp));

            printf("\n");
            printf("[");
            printDash(75);
            printf("]\n\n");

            bacaPesanReply(*emaillist, replyTree, emailID);

            printBody(list->emails[i].body);
            printf("\n");
            printDash(150);
            printf("\n");
            UbahStatusBaca(&list->emails[i]);
            for (int j = 0; j < emaillist->count; j++) {
                if (emaillist->emails[j].emailID == emailID) {
                    UbahStatusBaca(&emaillist->emails[j]);
                    return;
                }
            }
        }
    }
    printf("Email ID %d tidak ditemukan.\n", emailID);
}

void UbahStatusBaca(Email *email) {
    email->readStatus = 1;
}