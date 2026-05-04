/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkarakter.h"
#include "../Datetime/datetime.h"

#define NMax 50
#define BMax 1000
#define BLANK ' '
#define ENTER '\n'
#define ESCAPE '\\'
#define DANGER '\r'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

typedef struct
{
   char TabWord[BMax]; 
   int Length;
   int NEnter;
} Body;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

/* ------------------------------------PROSEDUR------------------------------------*/
void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK dan ENTER 
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTSENTENCE();
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */

void STARTFILEWORD(char* fileName);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan mesin berhenti;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTBODYWORD(Body *BEmail);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi dari file
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi dari file,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
         Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void ADVSENTENCE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi dari file
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi dari file,
         currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
   Proses : Akuisisi kata menggunakan procedure CopySentence */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopySentence();
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordFile();
/* Mengakuisisi kata dari file, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi dari file;
         currentChar = BLANK atau currentChar = MARK;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


void CopySentenceFile();
/* Mengakuisisi kata dari file, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi dari file;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


Body CopyBodyEmail();
/* Mengakuisisi kata dari file, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
         currentChar = BLANK atau currentChar = MARK;
         currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
         Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


void ValidateEnter(Body *BEmail);
/* I.S. : Body terdefinisi
   F.S. : NEnter increment jika ketemu ENTER */

/* ------------------------------------PREDIKAT------------------------------------*/
boolean IsInteger(Word kata);
/* Mengecek apakah kata merupakan bilangan bulat */

boolean isWordsEqual(Word kata1, Word kata2);
    /* Mengembalikan nilai true jika kata1 sama dengan kata2 */

/* ------------------------------------PROSEDUR------------------------------------*/
void printWord(Word kata);
/* I.S. : kata sembarang*/
/* F.S. : kata tercetak*/

void printWordLn(Word kata);
/* I.S. : kata sembarang*/
/* F.S. : kata tercetak dengan newline */

void printBody(Body BEmail);
/* I.S. : Body terdefinisi
   F.S. : Body tercetak */

char* concatStrings(char *str1, char *str2);

/* ------------------------------------FUNGSI------------------------------------*/
int WordtoInt(Word kata);
/* Mengubah word yang berisi char-char angka menjadi integer */

Word HardCopyWord(Word kata);
/* Mengembalikan Word yang merupakan salinan kata */

Word intToWord(int num);
/* Mengubah integer menjadi Word yang berisi char-char angka */

char* WordtoString(Word kata);
/* Mengubah Word menjadi string */

Word StringtoWord(char* string);
/* Mengubah string menjadi Word */

char* BodytoString(Body B);
/* Mengubah Body menjadi string */

char* DateTimetoString(DateTime dt);
/* Mengubah DateTime menjadi string */

Body StringtoBody(char* string);
/* Mengubah string menjadi Body */

#endif