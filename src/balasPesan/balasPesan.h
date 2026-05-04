#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "../modules/naryTree/narytree.h"
#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/stack/stack.h"

Word ReadWordMesinReply();

void bacaPesanReplyParent(EmailList l, NaryTree tree);

void bacaPesanReply(EmailList l, NaryTree tree, int emailId);

void BUAT_DRAFT_REPLY(Stack *Ds, Stack *Dsr, EmailList emailList, UserList *users, NaryTree replyTree, int emailId, User currentuser);

void UBAH_DRAFT_REPLY(Stack *Ds, Stack *Dsr, UserList *users, User currentuser);