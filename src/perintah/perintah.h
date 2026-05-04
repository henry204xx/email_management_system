#ifndef PERINTAH_H
#define PERINTAH_H

#include "../modules/mesinKata/mesinkata.h"
#include "../modules/mesinKata/mesinkarakter.h"


boolean isLogin();
/* Cek apakah perintah yang diberikan adalah "LOGIN" */

boolean isRegister();
/* Cek apakah perintah yang diberikan adalah "REGISTER" */

boolean isLogout();
/* Cek apakah perintah yang diberikan adalah "LOGOUT" */

boolean isBuatDraft();
/* Cek apakah perintah yang diberikan adalah "BUAT_DRAFT" */

boolean isBatal();
/* Cek apakah perintah yang diberikan adalah "BATAL" */

boolean isUbahDraft();
/* Cek apakah perintah yang diberikan adalah "UBAH_DRAFT" */

boolean isKirimDraft();
/* Cek apakah perintah yang diberikan adalah "KIRIM_DRAFT" */

boolean isLihatDraft();
/* Cek apakah perintah yang diberikan adalah "LIHAT_DRAFT" */

boolean isUndo();
/* Cek apakah perintah yang diberikan adalah "UNDO" */

boolean isRedo();
/* Cek apakah perintah yang diberikan adalah "REDO" */

boolean isInbox();
/* Cek apakah perintah yang diberikan adalah "INBOX" */

boolean isDaftarInbox();
/* Cek apakah perintah yang diberikan adalah "DAFTAR_INBOX" */

boolean isLanjut();
/* Cek apakah perintah yang diberikan adalah "LANJUT" */

boolean isSebelum();
/* Cek apakah perintah yang diberikan adalah "SEBELUM" */

boolean isBacaPesan();
/* Cek apakah perintah yang diberikan adalah "BACA_PESAN" */

boolean isKeluar();
/* Cek apakah perintah yang diberikan adalah "KELUAR" */

boolean isBalasPesan();
/* Cek apakah perintah yang diberikan adalah "BALAS_PESAN" */

boolean isStatusKepentingan();
/* Cek apakah perintah yang diberikan adalah "STATUS_KEPENTINGAN" */

boolean isSave();
/* Cek apakah perintah yang diberikan adalah "SAVE" */

boolean isLoad();
/* Cek apakah perintah yang diberikan adalah "LOAD" */

boolean isExit();
/* Cek apakah perintah yang diberikan adalah "EXIT" */

void AmbilPerintah();
/* I.S. : Perintah belum terdefinisi 
   F.S. : Perintah terdefinisi */


void ErrorMessage();
/* Menampilkan pesan error */


#endif