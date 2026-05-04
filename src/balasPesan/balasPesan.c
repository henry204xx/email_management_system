#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"
#include "../modules/naryTree/narytree.h"
#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/stack/stack.h"
#include "../buatDraft/draft.h"

Word ReadWordMesinReply() {
    Word result;
    STARTWORD();  // Memulai pembacaan kata
    result = currentWord;  // Menyimpan kata yang diakuisisi
    return result;
}

void bacaPesanReplyParent(EmailList l, NaryTree tree) {
    if (TR_EMAILID(TR_PARENT(tree)) != -1) {
        bacaPesanReplyParent(l, TR_PARENT(tree));
    }
    printWord(Subject(l.emails[TR_EMAILID(tree) - 1]));
    printf("\n[---------------------------------------------------------------------]\n");
    printBody(Body(l.emails[TR_EMAILID(tree) - 1]));
    printf("\n[---------------------------------------------------------------------]\n\n");
}

void bacaPesanReply(EmailList l, NaryTree tree, int emailId) {
    TR_Address p = findNode(tree, emailId);
    if (TR_EMAILID(TR_PARENT(p)) != -1)
        bacaPesanReplyParent(l, TR_PARENT(p));
}

void BUAT_DRAFT_REPLY(Stack *Ds, Stack *Dsr, EmailList emailList, UserList *users, NaryTree replyTree, int emailId, User currentuser) {
    if(!IsEmptyStack(*Ds)){
        printf("Anda belum melakukan finalisasi pada draft sebelumnya");
    }
    else{
        printf("MEMBUAT DRAFT EMAIL BARU\n");
        
        Email e;
        CreateEmail(&e);  // Inisialisasi draft email

        Email reply = emailList.emails[emailId - 1];

        printf("Masukkan Email Penerima: ");
        printWordLn(getEmailById(*users, SenderID(reply)));
        RecipientID(e) = SenderID(reply);

        printf("Masukkan Penerima CC (Kosongkan jika tidak ada): ");
        Word emailCC = ReadWordMesinReply();  // Simpan email cc sebagai Word
        CarbonCopyID(e) = getIdByEmail(*users, emailCC); 
        if(emailCC.Length != 0){
            CarbonCopyID(e) = getIdByEmail(*users, emailCC); 
            while(CarbonCopyID(e) == -1 || CarbonCopyID(e) == currentuser.id){
                printf("Email tidak ditemukan, silakan masukkan email penerima CC yang valid: ");
                emailCC = ReadWordMesin();
                CarbonCopyID(e) = getIdByEmail(*users, emailCC);
                if (emailCC.Length == 0){
                    CarbonCopyID(e) = -1;
                    break;
                }
                else if (CarbonCopyID(e) == -1){
                    continue;
                }
            }
        }
        else{
            CarbonCopyID(e) = -1;
        }

        Email ancestor = emailList.emails[TR_EMAILID(findNode(replyTree, SenderID(reply))) - 1];
        printf("Masukkan Subjek: ");
        printf("Re[%d]: %s", countAncestors(findNode(replyTree, EmailID(reply))), WordtoString(Subject(ancestor)));
        Word subjek = StringtoWord(concatStrings(concatStrings(concatStrings("Re[", WordtoString(intToWord(countAncestors(findNode(replyTree, EmailID(reply)))))), "]: "), WordtoString(Subject(ancestor))));
        Subject(e) = subjek;

        printf("\nMasukkan Body (maksimal 1000 karakter):\n");
        STARTBODYWORD(&Body(e));

        ReplyToID(e) = EmailID(reply);

        PushToStack(Ds, e);

        printf("Draft berhasil dibuat\n");
    }
}

void UBAH_DRAFT_REPLY(Stack *Ds, Stack *Dsr, UserList *users, User currentuser) {
    Email e;
    CreateEmail(&e);  // Inisialisasi draft email
    Email last;
    last = InfoTop(*Ds);

    printf("Masukkan Email Penerima: ");
    printWordLn(getEmailById(*users, RecipientID(last)));
    RecipientID(e) = RecipientID(last);
    

    printf("Masukkan Penerima CC (Kosongkan jika tidak ada): ");
    Word emailCC = ReadWordMesinReply();  // Simpan email cc sebagai Word
    CarbonCopyID(e) = getIdByEmail(*users, emailCC);
    if(emailCC.Length != 0){
        CarbonCopyID(e) = getIdByEmail(*users, emailCC); 
        while(CarbonCopyID(e) == -1 || CarbonCopyID(e) == currentuser.id){
            printf("Email tidak ditemukan, silakan masukkan email penerima CC yang valid: ");
            emailCC = ReadWordMesin();
            CarbonCopyID(e) = getIdByEmail(*users, emailCC);
            if (emailCC.Length == 0){
                CarbonCopyID(e) = -1;
                break;
            }
            else if (CarbonCopyID(e) == -1){
                continue;
            }
        }
    }
    else{
        CarbonCopyID(e) = -1;
    }

    printf("Masukkan Subjek: ");
    printWordLn(Subject(last));
    Subject(e) = Subject(last);

    printf("Masukkan Body (maksimal 1000 karakter):\n");
    STARTBODYWORD(&Body(e));

    ReplyToID(e) = ReplyToID(last);

    if(!IsFullStack(*Ds)){
        PushToStack(Ds, e);
    }
    else{
        deleteFirstElement(Ds);
        PushToStack(Ds, e);
    }

    if(!IsEmptyStack(*Dsr)){
        DealocStack(Dsr);
        CreateEmptyStack(Dsr);
    }

    printf("Draft berhasil diubah\n");
}