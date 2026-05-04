#include <stdio.h>
#include "modules/boolean.h"
#include "modules/mesinKata/mesinkata.h"
#include "perintah/perintah.h"
#include "inisialisasi/inisialisasi.h"
#include "modules/stack/stack.h"
#include "modules/matrix/matrix.h"
#include "buatDraft/draft.h"
#include "modules/email/email.h"
#include "modules/user/user.h"
#include "modules/naryTree/narytree.h"
#include "inbox/inbox.h"
#include "load/load.h"
#include "save/save.h"
#include "notifikasi/notifikasi.h"
#include "balasPesan/balasPesan.h"

int main() {

    EmailList emailList;
    UserList userList;
    NaryTree replyTree;
    int pagination;
    int important;

    createUserList(&userList);
    replyTree = newTreeNode(-1);
    printf("######  #     # ######  ######  #     #    #     #    #    ### #\n");
    printf("#     # #     # #     # #     #  #   #     ##   ##   # #    #  #\n");
    printf("#     # #     # #     # #     #   # #      # # # #  #   #   #  #\n");
    printf("######  #     # ######  ######     #       #  #  # #     #  #  #\n");
    printf("#       #     # #   #   #   #      #       #     # #######  #  #\n");
    printf("#       #     # #    #  #    #     #       #     # #     #  #  #\n");
    printf("#        #####  #     # #     #    #       #     # #     # ### #######\n");
    Inisialisasi(&emailList, &userList, &replyTree, &pagination, &important);

    boolean login = false; 
    User currentUser;
    Matrix statusKepentingan;
    AmbilPerintah();
    while (true)
    {
        if (isLogin()) // Bisa tambahin lagi aja conditional nya, lagi login atau tidak
        {
            if (!login) {
                printf("Masukkan email: ");
                STARTWORD();
                currentUser.email = currentWord;
                printf("Masukkan password: ");
                STARTWORD();
                currentUser.password = currentWord;
                currentUser = Login(&userList, currentUser);
                if (currentUser.id != -1)
                {
                    login = true;
                    getNotification(currentUser.id, emailList, userList, important);
                }
            }

            else {
                printf("Anda sudah login sebagai %s\n", WordtoString(currentUser.email));
            }
            
        } 
        else if (isRegister()) // ini juga
        {
            printf("######  #######  #####  ###  #####  ####### ####### ######\n");
            printf("#     # #       #     #  #  #     #    #    #       #     #\n");
            printf("#     # #       #        #  #          #    #       #     #\n");
            printf("######  #####   #  ####  #   #####     #    #####   ######\n");
            printf("#   #   #       #     #  #        #    #    #       #   #\n");
            printf("#    #  #       #     #  #  #     #    #    #       #    #\n");
            printf("#     # #######  #####  ###  #####     #    ####### #     #\n");

            if (!login) {
                Register(&userList); }

            else {
                printf("Anda harus logout terlebih dahulu untuk melakukan perintah ini.\n");
            }
        }
        else if (isLogout()) // ini juga
        {
            if (login) {
                login = false;
                printf("Berhasil logout\n");
            }
            else {
                printf("Anda belum login. Silakan login terlebih dahulu.\n");
            }
        }
        else if (isBuatDraft() && login) 
        {
            printf("#     # ####### #     # #     #    ######  ######     #    ####### #######\n");
            printf("##   ## #       ##    # #     #    #     # #     #   # #   #          #\n");
            printf("# # # # #       # #   # #     #    #     # #     #  #   #  #          #\n");
            printf("#  #  # #####   #  #  # #     #    #     # ######  #     # #####      #\n");
            printf("#     # #       #   # # #     #    #     # #   #   ####### #          #\n");
            printf("#     # #       #    ## #     #    #     # #    #  #     # #          #\n");
            printf("#     # ####### #     #  #####     ######  #     # #     # #          #\n");
            Stack Ds, Dsr;
            CreateEmptyStack(&Ds);  // Inisialisasi stack kosong berisi Draft Stack
            CreateEmptyStack(&Dsr);  // Inisialisasi stack kosong berisi Draft Stack Redo
            BUAT_DRAFT(&Ds, &Dsr, &userList, currentUser);
            AmbilPerintah();
            boolean buatDraft = true;
            while (buatDraft)
            {
                if (isBatal()) // Bikin nge-break
                {
                    BATAL(&Ds,&Dsr);
                    buatDraft = false;
                    break;
                }
                else if (isUbahDraft())
                {
                    UBAH_DRAFT(&Ds, &Dsr, &userList, currentUser); //ini masih nunggu nama list usernya apa
                }
                else if (isKirimDraft()) // Bikin nge-break
                {
                    KIRIM_DRAFT(&Ds, &emailList, currentUser);
                    addChild(findNode(replyTree, ReplyToID(emailList.emails[emailList.count - 1])), newTreeNode(EmailID(emailList.emails[emailList.count - 1])));
                    buatDraft = false;
                    break;
                }
                else if (isLihatDraft())
                {
                    LIHAT_DRAFT(&Ds, &userList);
                }
                else if (isRedo())
                {
                    REDO(&Ds, &Dsr);
                }
                else if(isUndo())
                {
                    UNDO(&Ds, &Dsr);
                }
                else if(isBuatDraft()){
                    printf("Maaf, sudah ada draft terbuat! Silakan finalisasi draft yang sudah dibuat.\n");
                }
                else
                {
                    printf("Perintah anda tidak valid dalam DRAFT.\nMohon masukkan ulang perintah");
                }
                printf("DRAFT >> ");
                STARTWORD();
            }
        }

        else if (isDaftarInbox() && login) {
            EmailList filteredList = filterInbox(emailList, userList, currentUser.id);
            DaftarInbox(filteredList, userList, pagination);
        }
        else if (isInbox())
        {
            printf("#     # ####### #     # #     #    ### #     # ######  ####### #     #\n");
            printf("##   ## #       ##    # #     #     #  ##    # #     # #     #  #   #\n");
            printf("# # # # #       # #   # #     #     #  # #   # #     # #     #   # #\n");
            printf("#  #  # #####   #  #  # #     #     #  #  #  # ######  #     #    #\n");
            printf("#     # #       #   # # #     #     #  #   # # #     # #     #   # #\n");
            printf("#     # #       #    ## #     #     #  #    ## #     # #     #  #   #\n");
            printf("#     # ####### #     #  #####     ### #     # ######  ####### #     #\n");

            printf("INBOX >> ");
            STARTWORD();            
            int currentPage = 1;   
            while (true) 
            {
                EmailList filteredList = filterInbox(emailList, userList, currentUser.id);
                if (isDaftarInbox())
                {
                    DaftarInbox(filteredList, userList, pagination); //pagination dari config
                    currentPage = 1;
                }
                
                else if (isLanjut())
                {
                    LanjutInbox(filteredList, userList, &currentPage, pagination); 
                }
                else if (isSebelum())
                {
                    SebelumInbox(filteredList, userList, &currentPage, pagination);
                }
                else if (isBacaPesan()) // Ini Tambahin conditional, kek tambah kasus dimana email ID ga valid
                {
                    int emailID = 0;
                    for (int i = 5; i < 8; i++)
                    {
                        emailID = emailID * 10 + currentWord.TabWord[i] - '0';
                    }
                    BacaPesan(&emailList, &filteredList, replyTree, emailID, userList);
                }
                
                else if (isKeluar()) // BREAK dari INBOX
                {
                    break;
                }                
                else 
                {
                    printf("Perintah anda tidak valid dalam INBOX.\nMohon masukkan ulang perintah");
                }
                printf("INBOX >> ");
                STARTWORD();
            }
        }

        else if (isBalasPesan() && login) // Ini Tambahin conditional, kek tambah kasus dimana email ID ga valid
                {
                    printf("#     # ####### #     # #     #    ######  ######     #    ####### #######\n");
                    printf("##   ## #       ##    # #     #    #     # #     #   # #   #          #\n");
                    printf("# # # # #       # #   # #     #    #     # #     #  #   #  #          #\n");
                    printf("#  #  # #####   #  #  # #     #    #     # ######  #     # #####      #\n");
                    printf("#     # #       #   # # #     #    #     # #   #   ####### #          #\n");
                    printf("#     # #       #    ## #     #    #     # #    #  #     # #          #\n");
                    printf("#     # ####### #     #  #####     ######  #     # #     # #          #\n");
                    int emailID = 0;
                    for (int i = 5; i < 8; i++)
                    {
                        emailID = emailID * 10 + currentWord.TabWord[i] - '0';
                    }
                    if (emailList.emails[emailID - 1].recipientID == currentUser.id) {
                        Stack Ds, Dsr;
                        CreateEmptyStack(&Ds);  // Inisialisasi stack kosong berisi Draft Stack
                        CreateEmptyStack(&Dsr);  // Inisialisasi stack kosong berisi Draft Stack Redo
                        BUAT_DRAFT_REPLY(&Ds, &Dsr, emailList, &userList, replyTree, emailID, currentUser);
                        AmbilPerintah();
                        boolean buatDraft = true;
                        while (buatDraft)
                        {
                            if (isBatal()) // Bikin nge-break
                            {
                                BATAL(&Ds,&Dsr);
                                buatDraft = false;
                                break;
                            }
                            else if (isUbahDraft())
                            {
                                UBAH_DRAFT_REPLY(&Ds, &Dsr, &userList, currentUser); //ini masih nunggu nama list usernya apa
                            }
                            else if (isKirimDraft()) // Bikin nge-break
                            {
                                KIRIM_DRAFT(&Ds, &emailList, currentUser);
                                addChild(findNode(replyTree, ReplyToID(emailList.emails[emailList.count - 1])), newTreeNode(EmailID(emailList.emails[emailList.count - 1])));
                                buatDraft = false;
                                break;
                            }
                            else if (isLihatDraft())
                            {
                                LIHAT_DRAFT(&Ds, &userList);
                            }
                            else if (isRedo())
                            {
                                REDO(&Ds, &Dsr);
                            }
                            else if(isUndo())
                            {
                                UNDO(&Ds, &Dsr);
                            }
                            else if(isBuatDraft()){
                                printf("Maaf, sudah ada draft terbuat! Silakan finalisasi draft yang sudah dibuat.\n");
                            }
                            else
                            {
                                printf("Perintah anda tidak valid dalam BALAS PESAN.\nMohon masukkan ulang perintah");
                            }
                            printf("DRAFT >> ");
                            STARTWORD();
                        }
                    } else {
                        printf("Anda tidak dapat membalas pesan ini!\n");
                    }
                }

        else if (isStatusKepentingan() && login)
        {
            createMatrix(countUser(userList), countUser(userList), &statusKepentingan);
            for (int i = 0; i < countUser(userList); i++)
            {
                for (int j = 0; j < countUser(userList); j++)
                {
                    ELMT(statusKepentingan, i, j) = 0;
                }
            }

            for (int k = 0; k < emailList.count; k++) {
                int senderID = emailList.emails[k].senderID;
                int recipientID = emailList.emails[k].recipientID;
                ELMT(statusKepentingan, senderID - 1, recipientID - 1) += 1;
            }
            displayMatrix(statusKepentingan);
        }

        else if (isLoad()) // Tambahin conditional, load bisa digas kalau belom login
        {
            if(login){
                printf("Anda harus logout terlebih dahulu untuk melakukan perintah ini.\n");
            }
            else LOAD(&emailList, &userList, &replyTree, &pagination, &important);
        }
        else if (isSave()) // Bisa kapan aja
        {
            SAVE(emailList, userList, pagination, important);
        }
        else if (isExit())
        {
            printf("Terimakasih telah menggunakan program ini!\n");
            break;   
        }
        else
        {
            ErrorMessage();
        }
        AmbilPerintah();
    }
    

    return 0;
}
