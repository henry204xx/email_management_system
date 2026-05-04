#include "email.h"
#include "../Datetime/datetime.h"
#include <stdlib.h>
#include <stdio.h>

/* ***********KONSTRUKTOR*********** */

void CreateEmail(Email *e) {
    EmailID(*e) = -1;
    SenderID(*e) = -1;
    RecipientID(*e) = -1;
    CarbonCopyID(*e) = -1;
    ReplyToID(*e) = -1;
    ReadStatus(*e) = 0;
    CcStatus(*e) = 0;
    // Menginisialisasi panjang subject dan body ke 0
    Subject(*e) = StringtoWord("(No Subject)");
    e->body.Length = 0;          // Body kosong
    Timestamp(*e) = GetCurrentDateTime();
}
/* I.S. sembarang */
/* F.S. Sebuah e kosong terbentuk*/
/* Proses : Melakukan alokasi, memasukkan nilai default untuk masing-masing elemen*/


void CreateEmailList(EmailList *list, int capacity) {
    list->emails = (Email *)malloc(capacity * sizeof(Email));
    list->count = 0;
    list->capacity = capacity;
}

void DealocEmailList(EmailList *list) {
    if (list != NULL) {
        if (list->emails != NULL) { 
            free(list->emails); 
            list->emails = NULL;
        }
        list->count = 0;    
        list->capacity = 0; 
    }
}


void AddEmailToList(EmailList *list, Email email) {
    if (list->count == list->capacity) {
        int newCapacity = list->capacity * 2;
        Email *newEmails = (Email *)malloc(newCapacity * sizeof(Email));
        for (int i = 0; i < list->count; i++) {
            newEmails[i] = list->emails[i];
        }
        free(list->emails);
        list->emails = newEmails;
        list->capacity = newCapacity;
    }
    list->emails[list->count++] = email;
}
