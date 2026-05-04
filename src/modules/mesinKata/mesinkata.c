#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"


boolean EndWord;
Word currentWord;

/* ------------------------------------PROSEDUR------------------------------------*/
void IgnoreBlanks() {
    /* Mengabaikan satu atau beberapa BLANK dan ENTER
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == ENTER) {
        ADV(); 
    }
}

void STARTWORD() {
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();       
    IgnoreBlanks(); 
    if (currentChar == MARK) {
        EndWord = true; 
        currentWord.Length = 0;
    } else {
        EndWord = false;
        CopyWord(); 
    }
}

void STARTSENTENCE() {
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();       
    IgnoreBlanks(); 
    if (currentChar == MARK) {
        EndWord = true; 
        currentWord.Length = 0;
    } else {
        EndWord = false;
        CopySentence(); 
    }
}

void STARTFILEWORD(char* fileName) {
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan mesin berhenti;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    STARTFILE(fileName); 
    IgnoreBlanks();      
    if (currentChar == MARK) EndWord = true;  
    else 
    {
        EndWord = false;
        CopyWordFile(); 
    }
}

void STARTBODYWORD(Body *BEmail) {
    START();
    if (currentChar == MARK) {
        EndWord = true;
        currentWord.Length = 0;
    }
    else
    {
        EndWord = false;
        *BEmail = CopyBodyEmail();
    }
}

void ADVWORD() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks(); 
    if (currentChar == MARK) EndWord = true;  
    else CopyWord(); 
}
void ADVWORDFILE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi dari file
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi dari file,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks(); 
    if (currentChar == MARK) EndWord = true;  
    else CopyWordFile(); 
}

void ADVSENTENCE() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi dari file
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi dari file,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks(); 
    if (currentChar == MARK) EndWord = true;  
    else CopySentenceFile(); 
}

void CopyWord() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) 
    {
        if (i < NMax) 
        { 
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV(); 
    }
    currentWord.Length = i; 
}

void CopySentence() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((currentChar != MARK)) 
    {
        if (i < NMax) 
        { 
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV(); 
    }
    currentWord.Length = i; 
}

void CopyWordFile() {
    /* Mengakuisisi kata dari file, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi dari file;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK) && (currentChar != ENTER) && !EOP) 
    {
        if (i < NMax && currentChar != DANGER) 
        { 
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV(); 
    }
    currentWord.Length = i; 
}

void CopySentenceFile() {
    /* Mengakuisisi kata dari file, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi dari file;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while (currentChar != ENTER) 
    {
        if (i < NMax && currentChar != DANGER) 
        { 
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV(); 
    }
    currentWord.Length = i; 
}

Body CopyBodyEmail() {
    boolean HasEscape;
    Body resultBody;
    int i = 0;
    while (!EOP || HasEscape)
    {
        if (i < BMax)
        {
            HasEscape = false;  
            resultBody.TabWord[i] = currentChar;
            i++;
        if (currentChar == ESCAPE) 
        {
            ADV();
            if (currentChar == MARK) {
                HasEscape = true;
                resultBody.TabWord[i - 1] = MARK;
            }
            else {
                resultBody.TabWord[i] = currentChar;
                i++;
            }
        }
            ValidateEnter(&resultBody);
        }
        ADV();
    }
    resultBody.Length = i;
    return resultBody;
}


void ValidateEnter(Body *BEmail) {
    if (currentChar == ENTER) BEmail->NEnter++;
}

/* ------------------------------------PREDIKAT------------------------------------*/
boolean IsInteger(Word kata) {
    /* Mengembalikan nilai true jika kata merupakan bilangan bulat */
    int i = 0;
    boolean isInteger = true;
    while (i < kata.Length) {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') { 
            isInteger = false;
            break;
        }
        i++;
    }
    return isInteger;
}

boolean isWordsEqual(Word kata1, Word kata2) {
    /* Mengembalikan nilai true jika kata1 sama dengan kata2 */
    if (kata1.Length != kata2.Length) {
        return false;
    }
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

/* ------------------------------------PROSEDUR------------------------------------*/
void printWord(Word kata) {
   /* I.S. : kata sembarang
      F.S. : kata tercetak */
   for (int i = 0; i < kata.Length; i++) 
   {
      printf("%c", kata.TabWord[i]); 
   }
}

void printWordLn(Word kata) {
    /* I.S. : kata sembarang
       F.S. : kata tercetak dengan newline */
    for (int i = 0; i < kata.Length; i++) 
    {
        printf("%c", kata.TabWord[i]); 
    }
    printf("\n"); 
}

void printBody(Body BEmail) {
   /* I.S. : kata sembarang
      F.S. : kata tercetak */
   for (int i = 0; i < BEmail.Length; i++) 
   {
      printf("%c", BEmail.TabWord[i]); 
   }
}

#include <stdio.h>
#include <stdlib.h>

/* Fungsi untuk menggabungkan dua string */
char* concatStrings(char *str1, char *str2) {
    int length1 = 0, length2 = 0, i = 0, j = 0;

    while (str1[length1] != '\0') {
        length1++;
    }

    while (str2[length2] != '\0') {
        length2++;
    }

    char *result = (char *)malloc((length1 + length2 + 1) * sizeof(char));
    if (result == NULL) {
        printf("Error: Alokasi memori gagal!\n");
        exit(1);
    }

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';

    return result;
}

/* ------------------------------------FUNGSI------------------------------------*/
int WordtoInt(Word kata) {
    int sum = 0;
    boolean isNegative = false;
    int i = 0;

    if (kata.TabWord[0] == '-') {
        isNegative = true;
        i = 1;
    }

    while (kata.Length > i) {
        if (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9') {
           sum = sum * 10 + (kata.TabWord[i] - '0'); 
        }
        i++;
    }

    if (isNegative) sum = -sum;
    return sum;
}

Word HardCopyWord(Word kata) {
    Word result;
    result.Length = kata.Length;
    for (int i = 0; i < kata.Length; i++) {
        result.TabWord[i] = kata.TabWord[i];
    }
    return result;
}


Word intToWord(int num) {
   /* Mengubah integer menjadi word yang berisi char-char angka */
    Word kata;
    kata.Length = 0;
    if (num == 0) 
    {
       kata.TabWord[kata.Length] = '0';
       kata.Length++;
    } 
    else 
    {
        while (num > 0) 
        {
           kata.TabWord[kata.Length] = num % 10 + '0';
           kata.Length++;
           num /= 10;
        }
    }
    return kata;
}

char* WordtoString(Word kata) {
    char* string = (char*) malloc((kata.Length + 1) * sizeof(char));

    if (string == NULL) {
        return NULL;
    }

    for (int i = 0; i < kata.Length; i++) {
        string[i] = kata.TabWord[i];
    }

    string[kata.Length] = '\0';
    return string;
}
/* Mengubah Word menjadi string */

Word StringtoWord(char* string) {
    Word kata;
    int i = 0;
    while (string[i] != '\0') {
        kata.TabWord[i] = string[i];
        i++;
    }
    kata.Length = i;
    return kata;
}
/* Mengubah string menjadi Word */

char* BodytoString(Body B) {
    int lenStr = B.Length + B.NEnter * 3; // Tambahkan ekstra 2 karakter untuk setiap \n (total \ -> \\n)
    char* resultStr = (char*) malloc((lenStr + 1) * sizeof(char)); // +1 untuk null-terminator
    int i = 0, j = 0; // i: indeks untuk resultStr, j: indeks untuk B.TabWord

    while (j < B.Length) {
        if (B.TabWord[j] == '\n') { 
            resultStr[i++] = '\\'; // Backslash pertama
            resultStr[i++] = '\n'; // Backslash kedua
        } else {
            resultStr[i++] = B.TabWord[j]; // Salin karakter biasa
        }
        j++;
    }

    resultStr[i] = '\0'; // Tambahkan null-terminator di akhir
    return resultStr;
}


char* DateTimetoString(DateTime DT) {
    char* resultStr = (char*) malloc(20 * sizeof(char));
    sprintf(resultStr, "%02d-%02d-%02d %02d.%02d.%02d", DT.day, DT.month, DT.year, DT.hour, DT.minute, DT.second);
    return resultStr;
}

Body StringtoBody(char* string) {
    Body newBody;
    int i = 0;
    newBody.Length = 0;
    newBody.NEnter = 0;

    // Copy the string into the TabWord of Body
    while (string[i] != '\0' && i < BMax - 1) {
        newBody.TabWord[i] = string[i];
        if (string[i] == ENTER) {
            newBody.NEnter++;  
        }
        i++;
    }
    newBody.TabWord[i] = '\0';  
    newBody.Length = i; 

    return newBody;
}

