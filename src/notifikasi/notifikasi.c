#include <stdio.h>
#include <stdlib.h>
#include "notifikasi.h"

void getNotification(int User_Id, EmailList emailList, UserList userList, int important) {
    // Create and initialize the importance matrix
    boolean isPenting = false;
    int emailId;
    Matrix importanceMatrix;
    createMatrix(countUser(userList), countUser(userList), &importanceMatrix);
    for (int i = 0; i < countUser(userList); i++) {
        for (int j = 0; j < countUser(userList); j++) {
            ELMT(importanceMatrix, i, j) = 0;
        }
    }

    // Populate the importance matrix based on email interactions
    for (int i = 0; i < emailList.count; i++) {
        int senderID = emailList.emails[i].senderID;
        int recipientID = emailList.emails[i].recipientID;
        ELMT(importanceMatrix, senderID - 1, recipientID - 1)++;
    }

    // Print notification
    PrioQueue pq;
    PQ_CreatePrioQueue(&pq);

    // Iterate through the email list
    for (int i = 0; i < emailList.count; i++) {
        Email email = emailList.emails[i];
        isPenting = false;
        // Check if the User_Id matches either Receiver ID or Receiver ID CC
        // and if the email has not been read by the respective user
        if ((email.recipientID == User_Id && email.readStatus == 0) || 
            (email.ccID == User_Id && email.ccStatus == 0)) {
            // Determine the priority using the importance matrix
            emailId = email.emailID;
            int priority = ELMT(importanceMatrix, email.senderID - 1, User_Id - 1);
            if (priority > important) {
                isPenting = true;
            } // else: isPenting = false
            PQ_enqueue(&pq, emailId, isPenting);
        }
    }

    // Print Notifications
    if (PQ_isEmpty(pq)) {
        printf("Tidak ada notifikasi\n");
    } else {
        printf("Notifikasi:\n");
        while (!PQ_isEmpty(pq)) {
            PQ_dequeue(&pq, &emailId, &isPenting);
            emailId -= 1;
            char *string1 = WordtoString(emailList.emails[emailId].subject);
            if (isPenting) { // Assuming any positive priority indicates importance
                printf("%s [IMPORTANT] %s\n", DateTimetoString(emailList.emails[emailId].timestamp), string1);
            } else {
                printf("%s %s\n", DateTimetoString(emailList.emails[emailId].timestamp), string1);
            }
        }
    }
}