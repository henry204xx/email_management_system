#include <stdio.h>
#include "matrix.h"


void createMatrix(int nRows, int nCols, Matrix *m) {
    if (nRows < 1 || nRows > ROW_CAP || nCols < 1 || nCols > COL_CAP) {
        return; 
    }
    
    m->rowEff = nRows; 
    m->colEff = nCols;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j) {
   return (i<ROW_CAP && j < COL_CAP && i >= 0 && j >= 0);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m) {
   return (m.rowEff-1);
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m) {
   return (m.colEff-1);
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
   return (i < m.rowEff && i >= 0 &&  j < m.colEff && j >= 0);
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i) {
   return (m.mem[i][i]);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut) {
    mOut->rowEff = mIn.rowEff;
    mOut->colEff = mIn.colEff;

        for (int i = 0; i <= getLastIdxRow(mIn); i++) {
            for (int j = 0; j <= getLastIdxCol(mIn); j++) {
                mOut->mem[i][j] = mIn.mem[i][j];
            }
        }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol) {
   int i,j,x;
   createMatrix(nRow,nCol,m);
   for (i = 0; i < nRow; i++) {
      for (j = 0; j < nCol; j++) {
         scanf("%d", &x);
         m->mem[i][j] = x;
      }
   }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m) {
    printf("[");
    for (int k = 0; k <= m.colEff;k++) {
        printf("-----");
    }
    printf("]\n");
   printf("| ID  |");
    for (int i = 1; i <= m.colEff; i++) {
      printf(" %02d |", i);
    }
    printf("\n");
    printf("-");
    for (int k = 0; k <= m.colEff;k++) {
        printf("-----");
    }
    printf("-\n");
   int i,j;
   for (i = 0; i <= getLastIdxRow(m); i++) {
      printf("| %02d  |", i+1);
      for (j = 0; j <= getLastIdxCol(m); j++) {
         printf(" %02d |", m.mem[i][j]);
      }
      printf("\n");
   }
   printf("[");
    for (int k = 0; k <= m.colEff;k++) {
        printf("-----");
    }
    printf("]\n");
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2) {
   Matrix m3;
   int i,j;
   createMatrix(m1.rowEff, m2.colEff,&m3);
   for (i = 0; i <= getLastIdxRow(m1); i++) {
      for (j = 0; j <= getLastIdxCol(m1); j++) {
         m3.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2) {
   Matrix m3;
   int i,j;
   createMatrix(m1.rowEff, m2.colEff,&m3);
   for (i = 0; i <= getLastIdxRow(m1); i++) {
      for (j = 0; j <= getLastIdxCol(m1); j++) {
         m3.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
      }
   }
   return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2) {
   Matrix m3;
   createMatrix(m1.rowEff, m2.colEff,&m3);
        for (int i = 0; i < m1.rowEff; i++) {
            for (int j = 0; j < m2.colEff; j++) {
                int sum = 0;
                for (int k = 0; k < m1.colEff; k++) {
                    sum += (m1.mem[i][k] * m2.mem[k][j]);
                }
                m3.mem[i][j] = sum;
            }
        }
        return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x) {
   Matrix m3;
   createMatrix(m.rowEff, m.colEff,&m3);
        for (int i = 0; i < m.rowEff; i++) {
            for (int j = 0; j < m.colEff; j++) {
               m3.mem[i][j] = m.mem[i][j] * x;
            }
        }
        return m3;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k) {
   for (int i = 0; i < m->rowEff; i++) {
            for (int j = 0; j < m->colEff; j++) {
               m->mem[i][j] *= k;
            }
        }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2) {
   if (m1.colEff != m2.colEff || m1.rowEff != m2.rowEff) {
      return 0;
   }
   else {
      for (int i = 0; i < m1.rowEff; i++) {
            for (int j = 0; j < m1.colEff; j++) {
               if (m1.mem[i][j] != m2.mem[i][j]) {
                  return 0;
               }
            }
        }
      return 1;
   }
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
   if (m1.colEff != m2.colEff || m1.rowEff != m2.rowEff) {
      return 1;
   }
   else {
      for (int i = 0; i < m1.rowEff; i++) {
            for (int j = 0; j < m1.colEff; j++) {
               if (m1.mem[i][j] != m2.mem[i][j]) {
                  return 1;
               }
            }
        }
      return 0;
   }
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
   return (m1.colEff == m2.colEff && m1.rowEff == m2.rowEff);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m) {
   return (m.colEff * m.rowEff);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m) {
   return (m.colEff == m.rowEff);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m) {
   if (!(isSquare(m))) {
      return 0;
   }

   for (int i = 0; i < m.rowEff; i++) {
            for (int j = 0; j < m.colEff; j++) {
               if (m.mem[i][j] != m.mem[j][i]) {
                  return 0;
               }
            }
        }
   return 1;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m) {
   for (int i = 0; i < m.rowEff; i++) {
            for (int j = 0; j < m.colEff; j++) {
               if (m.mem[i][j] != 0 && i != j) {
                  return 0;
               }
               if (m.mem[i][j] != 1 && i == j) {
                  return 0;
               }
            }
        }
   return 1;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m) {
   int countzero = 0;
   int countnonzero = 0;
   for (int i = 0; i < m.rowEff; i++) {
      for (int j = 0; j < m.colEff; j++) {
            if (m.mem[i][j] == 0) {
               countzero += 1;
            }
            else if (m.mem[i][j] != 0) {
               countnonzero += 1;
            }
      }
   }
   return (countnonzero <= (countElmt(m)/20));
      
   
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m) {
   Matrix m2 = multiplyByConst(m,-1);
   return m2;
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m) {
   pMultiplyByConst(m,-1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m) {
   float det = 0;
    
    
    if (m.rowEff == 1) {
        return m.mem[0][0];
    }
    
   
    if (m.rowEff == 2) {
        return (m.mem[0][0] * m.mem[1][1]) - (m.mem[0][1] * m.mem[1][0]);
    }

    
    for (int k = 0; k < m.colEff; k++) {
        Matrix subMatrix;
        createMatrix(m.rowEff - 1, m.colEff - 1, &subMatrix);

        
        for (int i = 1; i < m.rowEff; i++) {
            int colIndex = 0;
            for (int j = 0; j < m.colEff; j++) {
                if (j == k) {
                    continue;  
                }
                subMatrix.mem[i - 1][colIndex] = m.mem[i][j];
                colIndex++;
            }
        }

            int sign;
            if (k % 2 == 0) {
            sign = 1;} 
            else {
            sign = -1;}

        det += sign * m.mem[0][k] * determinant(subMatrix);
    }
    
    return det;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m) {
   Matrix m3;
   createMatrix(m.rowEff,m.colEff,&m3);
   int i,j;
   for (i = 0; i < m.rowEff; i++) {
      for (j = 0; j < m.colEff; j++) {
         m3.mem[i][j] = m.mem[j][i];
      }
   }
   return m3;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m) {
   Matrix m3 = transpose(*m);
   copyMatrix(m3,m);

}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

