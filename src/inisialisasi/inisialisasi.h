#ifndef INISIALISASI_H
#define INISIALISASI_H

#include <stdio.h>
#include <stdlib.h>
#include "../modules/boolean.h"
#include "../modules/user/user.h"
#include "../modules/email/email.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../load/load.h"

void Inisialisasi(EmailList *emailList, UserList *userList, NaryTree *tree, int *pagination, int *important);
/* I.S. : Sembarang
   F.S. : 
   Proses : Inisialisasi */

#endif