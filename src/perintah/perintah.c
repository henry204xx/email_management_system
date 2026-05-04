#ifndef PERINTAH_H
#define PERINTAH_H

#include "../modules/mesinKata/mesinkata.h"


boolean isLogin() {
    Word login = StringtoWord("LOGIN");
    if (!isWordsEqual(login,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "LOGIN" */

boolean isRegister() {
    Word Register = StringtoWord("REGISTER");
    if (!isWordsEqual(Register,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "REGISTER" */


boolean isLogout() {
    Word logout = StringtoWord("LOGOUT");
    if (!isWordsEqual(logout,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "LOGOUT" */

boolean isBuatDraft() {
    Word buatdraft = StringtoWord("BUAT_DRAFT");
    if (!isWordsEqual(buatdraft,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "BUAT_DRAFT" */

boolean isBatal() {
    Word batal = StringtoWord("BATAL");
    if (!isWordsEqual(batal,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "BATAL" */

boolean isUbahDraft() {
    Word ubahdraft = StringtoWord("UBAH_DRAFT");
    if (!isWordsEqual(ubahdraft,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "UBAH_DRAFT" */

boolean isKirimDraft() {
    Word kirimdraft = StringtoWord("KIRIM_DRAFT");
    if (!isWordsEqual(kirimdraft,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "KIRIM_DRAFT" */

boolean isLihatDraft() {
    Word lihatdraft = StringtoWord("LIHAT_DRAFT");
    if (!isWordsEqual(lihatdraft,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "LIHAT_DRAFT" */

boolean isUndo() {
    Word undo = StringtoWord("UNDO");
    if (!isWordsEqual(undo,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "UNDO" */

boolean isRedo() {
    Word redo = StringtoWord("REDO");
    if (!isWordsEqual(redo,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "REDO" */

boolean isInbox() {
    Word inbox = StringtoWord("INBOX");
    if (!isWordsEqual(inbox,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "INBOX" */

boolean isDaftarInbox() {
    Word daftarinbox = StringtoWord("DAFTAR_INBOX");
    if (!isWordsEqual(daftarinbox,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "DAFTAR_INBOX" */
boolean isLanjut() {
    Word lanjut = StringtoWord("LANJUT");
    if (!isWordsEqual(lanjut,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "LANJUT" */

boolean isSebelum() {
    Word sebelum = StringtoWord("SEBELUM");
    if (!isWordsEqual(sebelum,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "SEBELUM" */

boolean isBacaPesan() {
    Word bacapesan = StringtoWord("BACA_PESAN");
    if (!isWordsEqual(bacapesan,currentWord)) return false;
    if (EOP) 
    {
        printf("Masukkan EmailID yang ingin dibaca\n"); 
        return false;
    }
    ADVWORD();
    if (!EOP) return false;
    if (currentWord.Length != 8) return false;
    char* email = "EMAIL";
    for (int i = 0; i < currentWord.Length; i++)
    {
        if(i >= 0 && i <= 4)
        {
            if (currentWord.TabWord[i] != email[i]) return false;
        }
        else
        {
            if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') return false;
        }
    }
    return true;
}
/* Cek apakah perintah yang diberikan adalah "BACA_PESAN" */

boolean isKeluar() {
    Word keluar = StringtoWord("KELUAR");
    if (!isWordsEqual(keluar,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "KELUAR" */

boolean isBalasPesan() {
    Word balaspesan = StringtoWord("BALAS_PESAN");
    if (!isWordsEqual(balaspesan,currentWord)) return false;
    if (EOP) 
    {
        printf("Masukkan EmailID yang ingin dibalas\n"); 
        return false;
    }
    ADVWORD();
    if (!EOP) return false;
    if (currentWord.Length != 8) return false;
    char* email = "EMAIL";
    for (int i = 0; i < currentWord.Length; i++)
    {
        if(i >= 0 && i <= 4)
        {
            if (currentWord.TabWord[i] != email[i]) return false;
        }
        else
        {
            if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') return false;
        }
    }
    return true;
}
/* Cek apakah perintah yang diberikan adalah "BALAS_PESAN" */

boolean isStatusKepentingan() {
    Word statuskepentingan = StringtoWord("STATUS_KEPENTINGAN");
    if (!isWordsEqual(statuskepentingan,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "STATUS_KEPENTINGAN" */

boolean isSave() {
    Word save = StringtoWord("SAVE");
    if (!isWordsEqual(save,currentWord)) return false;
    if (!EOP) return false;
    return true;

}
/* Cek apakah perintah yang diberikan adalah "SAVE" */

boolean isLoad() {
    Word load = StringtoWord("LOAD");
    if (!isWordsEqual(load,currentWord)) return false;
    if (!EOP) return false;
    return true;
}
/* Cek apakah perintah yang diberikan adalah "LOAD" */

boolean isExit() {
    Word exit = StringtoWord("EXIT");
    if (!isWordsEqual(exit,currentWord)) return false;
    if (!EOP) return false;
    return true;
}

void AmbilPerintah(){
    printf(">> ");
    STARTWORD();
}

void ErrorMessage() {
    printf("Salah Input wak, input ulang:\n");
}

#endif