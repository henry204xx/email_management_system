/* NOTES: INI HANYALAH SEBUAH CONTOH DRIVER UNTUK MEMBANTU ANDA MEMAHAMI PENGGUNAAN ADT EMAIL*/

#include "../modules/email/email.h"
#include "../modules/user/user.h"
#include "../modules/stack/stack.h"
#include "../modules/Datetime/datetime.h"
#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"


Word ReadWordMesin() {
    Word result;
    STARTWORD();  // Memulai pembacaan kata
    result = currentWord;  // Menyimpan kata yang diakuisisi
    return result;
}

/* **************************************************************/
/* **********************FITUR DRAFT EMAIL***********************/
/* **************************************************************/
// jangan lupa inisialisasi di awal Stack Ds, Dsr;

void BUAT_DRAFT(Stack *Ds, Stack *Dsr, UserList *users, User currentuser){
    if(!IsEmptyStack(*Ds)){
        printf("Anda belum melakukan finalisasi pada draft sebelumnya");
    }
    else{
        printf("MEMBUAT DRAFT EMAIL BARU\n");
        
        Email e;
        CreateEmail(&e);  // Inisialisasi draft email

        printf("Masukkan Email Penerima: ");
        Word emailRecipient = ReadWordMesin(); // Simpan email penerima sebagai Word
        RecipientID(e) = getIdByEmail(*users, emailRecipient);
        while(RecipientID(e) == -1 || RecipientID(e) == currentuser.id){
            printf("Silakan masukkan email penerima yang valid: ");
            emailRecipient = ReadWordMesin();
            RecipientID(e) = getIdByEmail(*users, emailRecipient);
        }

        printf("Masukkan Penerima CC (Kosongkan jika tidak ada): ");
        Word emailCC = ReadWordMesin();  // Simpan email cc sebagai Word
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
        STARTSENTENCE();
        Subject(e) = currentWord;
        if(currentWord.Length == 0){
            Subject(e) = StringtoWord("(No Subject)");
        }
        else {
            for (int i = 0; i < Subject(e).Length; i++)
            {
                if (Subject(e).TabWord[i] == '\n') {
                    Subject(e).TabWord[i] = ' ';
                }
            }
        }

        printf("Masukkan Body (maksimal 1000 karakter):\n");
        STARTBODYWORD(&Body(e));

        PushToStack(Ds, e);

        printf("Draft berhasil dibuat\n");
    }
}


/* LIHAT_DRAFT: Menampilkan draft yang sedang disusun */
void LIHAT_DRAFT(Stack *Ds, UserList *users) {
    printf("MELIHAT DRAFT EMAIL\n");
    // Menampilkan email draft terakhir yang disimpan
    if(IsEmptyStack(*Ds)){
        printf("Tidak ada draft yang dapat dilihat\n");
    }
    else{
        Email e;
        PopStack(Ds, &e);  // Mengambil draft dari Stack

        printf("Email Penerima: %s\n", WordtoString(getEmailById(*users, RecipientID(e))));
        if(CarbonCopyID(e) != -1){   
            printf("Penerima CC: %s\n", WordtoString(getEmailById(*users, CarbonCopyID(e))));
        }
        else{
            printf("Penerima CC: <Tidak ada>");
        }
        printf("\nSubjek: ");
        printWord(Subject(e));
        printf("\nBody: ");
        printBody(Body(e));
        printf("\n");

        // Mengembalikan isi stack yang dikeluarkan
        PushToStack(Ds, e);
    }
}

void BATAL(Stack *Ds, Stack *Dsr){
    DealocStack(Ds);
    DealocStack(Dsr);
    Ds = NULL; Dsr = NULL;
    printf("Draft email berhasil dibatalkan!\n");
}

void UBAH_DRAFT(Stack *Ds, Stack *Dsr, UserList *users, User currentuser){
    Email e;
    CreateEmail(&e);  // Inisialisasi draft email

    printf("Masukkan Email Penerima: ");
    Word emailRecipient = ReadWordMesin(); // Simpan email penerima sebagai Word
    RecipientID(e) = getIdByEmail(*users, emailRecipient);
    while(RecipientID(e) == -1 || RecipientID(e) == currentuser.id){
        printf("Silakan masukkan email penerima yang valid: ");
        emailRecipient = ReadWordMesin();
        RecipientID(e) = getIdByEmail(*users, emailRecipient);
    }

    printf("Masukkan Penerima CC (Kosongkan jika tidak ada): ");
    Word emailCC = ReadWordMesin();  // Simpan email cc sebagai Word
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
    STARTSENTENCE();
    Subject(e) = currentWord;
    if(currentWord.Length == 0){
        Subject(e) = StringtoWord("(No Subject)");
    }
    else {
        for (int i = 0; i < Subject(e).Length; i++)
        {
            if (Subject(e).TabWord[i] == '\n') {
                Subject(e).TabWord[i] = ' ';
            }
        }
    }

    printf("Masukkan Body (maksimal 1000 karakter):\n");
    STARTBODYWORD(&Body(e));
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

void KIRIM_DRAFT(Stack *Ds, EmailList *list, User currentuser){
    if (IsEmptyStack(*Ds)) {
        printf("Tidak ada draft untuk dikirim\n");
        return;
    }

    Email e;
    PopStack(Ds, &e); // Ambil draft terbaru dari stack

    EmailID(e) = (list->count) + 1; // Set ID email
    SenderID(e) = currentuser.id; // Set pengirim email
    AddEmailToList(list, e); // Tambahkan ke EmailList
    printf("Draft Email berhasil dikirim!\n");
}

void UNDO(Stack *Ds, Stack *Dsr){
    Email e;
    if(IsOneElmt(*Ds)){
        printf("Belum ada perubahan yang dapat di-undo\n");
    }
    else{
        PopStack(Ds, &e);
        PushToStack(Dsr, e);
        printf("Perubahan berhasil di-undo\n");
    }
}

void REDO(Stack *Ds, Stack *Dsr){
    Email e;
    if (IsEmptyStack(*Dsr)) {
        printf("Tidak ada perubahan yang dapat di-redo\n");
    }
    else {
        PopStack(Dsr, &e); // Ambil elemen dari Dsr
        PushToStack(Ds, e); // Pindahkan kembali ke Ds
        printf("Perubahan berhasil di-redo\n");
    }    
} 


// int main(){
//     Stack Ds, Dsr;
//     EmailList list;
//     UserList users;

//     int d;
//     boolean jalan = true;
//     while(jalan){
//         scanf("%d", &d);
//         if(d == 1){
//             BUAT_DRAFT(&Ds, &Dsr, &users);
//             printf("\n");
//             printf("\n");
//         }
//         else if(d == 2){
//             LIHAT_DRAFT(&Ds);
//             printf("\n");
//             printf("\n");
//         }
//         else if(d == 3){
//             UBAH_DRAFT(&Ds, &users);
//             printf("\n");
//             printf("\n");            
//         }
//         else if(d == 100){
//             UNDO(&Ds, &Dsr);
//             printf("\n");
//         }
//         else if(d == 101){
//             REDO(&Ds, &Dsr);
//             printf("\n");            
//         }
//         else if(d == 999){
//             KIRIM_DRAFT(&Ds, &list);
//         }
//         else{
//             jalan = false;
//         }
//     }
// }
