#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "../modules/mesinKata/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

void writeUsersToFile(const char *filename, UserList *list);
/* I.S. : list terdefinisi 
   F.S. : User disimpan ke file filename */
   
void writeEmailsToFile(const char *filename, EmailList *Elist);
/* I.S. : Elist terdefinisi 
   F.S. : Email disimpan ke file filename */

void writeUmumtoFile(const char *filename, int pagination, int important);
/* I.S. : Pagination dan important terdefinisi 
   F.S. : pagination dan important disimpan ke file filename */

void SAVE(EmailList emailList, UserList userList, int pagination, int important);
/* I.S. : emailList, userList, pagination, important terdefinisi
   F.S. : emailList, userList, pagination, important disimpan ke file */