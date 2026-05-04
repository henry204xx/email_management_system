// #include <stdio.h>
// #include <stdlib.h>
// #include "mesinkata.h"
// #include "mesinkarakter.h"

// // Fungsi untuk mengetes IsInteger
// void testIsInteger() {
//     printf("\n--- TEST IsInteger ---\n");
//     Word kata1 = StringtoWord("12345");
//     Word kata2 = StringtoWord("12a45");

//     printf("Kata: ");
//     printWord(kata1);
//     printf("IsInteger: %s\n", IsInteger(kata1) ? "True" : "False");

//     printf("Kata: ");
//     printWordLn(kata2);
//     printf("IsInteger: %s\n", IsInteger(kata2) ? "True" : "False");
// }

// // Fungsi untuk mengetes isWordsEqual
// void testIsWordsEqual() {
//     printf("\n--- TEST isWordsEqual ---\n");
//     Word kata1 = StringtoWord("Hello");
//     Word kata2 = StringtoWord("Hello");
//     Word kata3 = StringtoWord("World");

//     printf("Kata1: ");
//     printWordLn(kata1);
//     printf("Kata2: ");
//     printWordLn(kata2);
//     printf("IsEqual: %s\n", isWordsEqual(kata1, kata2) ? "True" : "False");

//     printf("Kata1: ");
//     printWordLn(kata1);
//     printf("Kata3: ");
//     printWordLn(kata3);
//     printf("IsEqual: %s\n", isWordsEqual(kata1, kata3) ? "True" : "False");
// }

// // Fungsi untuk mengetes WordtoInt dan intToWord
// void testWordIntConversion() {
//     printf("\n--- TEST WordtoInt & intToWord ---\n");
//     Word kata1 = StringtoWord("-12345");
//     int angka = WordtoInt(kata1);
//     printf("Kata: ");
//     printWordLn(kata1);
//     printf("WordtoInt: %d\n", angka);

//     Word kata2 = intToWord(67890);
//     printf("Int: 67890\n");
//     printf("intToWord: ");
//     printWordLn(kata2);
// }

// // Fungsi untuk mengetes WordtoString dan StringtoWord
// void testStringConversion() {
//     printf("\n--- TEST WordtoString & StringtoWord ---\n");
//     Word kata1 = StringtoWord("Testing123");
//     char *string1 = WordtoString(kata1);
//     printf("Word to String: %s\n", string1);
//     free(string1);

//     char *inputStr = "HelloWorld";
//     Word kata2 = StringtoWord(inputStr);
//     printf("String to Word: ");
//     printWordLn(kata2);
// }

// // Fungsi untuk mengetes STARTFILEWORD, ADVWORDFILE, dan CopyWordFile
// void testFileReading() {
//     printf("\n--- TEST STARTFILEWORD & ADVWORDFILE ---\n");
//     char filename[100];
//     printf("Masukkan nama file untuk diuji: ");
//     scanf("%s", filename);

//     STARTFILEWORD(filename);
//     if (EndWord) {
//         printf("File kosong atau gagal dibaca.\n");
//         return;
//     }

//     int wordCount = 0;
//     while (!EndWord) {
//         wordCount++;
//         printf("Kata %d: ", wordCount);
//         printWordLn(currentWord);
//         ADVWORDFILE();
//     }
//     printf("Total kata terbaca: %d\n", wordCount);
// }

// // Fungsi untuk mengetes printBody dan BodytoString
// void testBodyHandling() {
//     printf("\n--- TEST Body Handling ---\n");
//     char *bodyString = "Ini adalah contoh body email.\nBaris kedua body.\nBaris ketiga.";
//     printf("Input Body String:\n%s\n", bodyString);

//     Body body = StringtoBody(bodyString);
//     printf("Body setelah diolah:\n");
//     printBody(body);

//     char *convertedBody = BodytoString(body);
//     printf("\nBody to String:\n%s\n", convertedBody);
//     free(convertedBody);
// }

// int main() {
//     printf("===== TEST SEMUA FUNGSI DALAM MESINKATA.H =====\n");

//     // Test File Reading Functions
//     // testFileReading();

//     // Test Integer Validation
//     testIsInteger();

//     // Test Word Equality
//     testIsWordsEqual();

//     // Test Word <-> Integer Conversion
//     testWordIntConversion();

//     // Test Word <-> String Conversion
//     testStringConversion();

//     // Test Body Handling
//     testBodyHandling();

//     printf("\n===== SEMUA TEST SELESAI =====\n");
//     return 0;
// }
