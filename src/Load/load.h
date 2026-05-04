#include <stdio.h>
#include <stdlib.h>
#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "../modules/naryTree/narytree.h"


void LoadUmumConfig(char *filename, int *pagination, int *important);
/* Membaca data umum dari file konfigurasi 'umum.config' */

void LoadUserConfig(char *filename, UserList *list);
/* Membaca data pengguna dari file konfigurasi 'pengguna.config' */
/* I.S. file pengguna.config terdefinisi dan dapat diakses */
/* F.S. list terisi dengan data pengguna dari file */

void LoadEmailConfig(EmailList *list, NaryTree *tree, char *filename);

boolean folderExists(char *folderPath);

boolean validateConfigFolder(char *folderPath);

boolean loadConfigFolder(char *folderPath);

void LOAD(EmailList *emailList, UserList *userList, NaryTree *tree, int *pagination, int *important);