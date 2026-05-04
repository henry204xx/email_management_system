#ifndef NOTIFIKASI_H
#define NOTIFIKASI_H

#include "../modules/boolean.h"
#include "../modules/email/email.h"
#include "../modules/matrix/matrix.h"
#include "../modules/prioQueue/prioqueue.h"
#include "../modules/user/user.h"
#include "../modules/mesinKata/mesinkata.h"

void getNotification(int User_Id, EmailList emailList, UserList userList, int important);

#endif