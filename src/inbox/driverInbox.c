// #include "inbox.h"
// #include <stdio.h>



// int main() {
//     EmailList emailList;
//     CreateEmailList(&emailList, 20); // Create an EmailList with capacity of 20

//     UserList userList;
//     createUserList(&userList);

//     // Create some sample users
//     User user1, user2, user3;
//     createUser(&user1, 1, StringtoWord("user1234@example.com"), StringtoWord("password1"));
//     createUser(&user2, 2, StringtoWord("user2@example.com"), StringtoWord("password2"));
//     createUser(&user3, 3, StringtoWord("user3@example.com"), StringtoWord("password3"));

//     // Add users to the lis
//     userList.users[0] = user1;
//     userList.users[1] = user2;
//     userList.users[2] = user3;

//     // Create some sample emails
//     Email email1, email2, email3;
//     CreateEmail(&email1);
//     email1.emailID = 1;
//     email1.senderID = user1.id;
//     email1.recipientID = user2.id;
//     email1.ccStatus = user3.id;
//     email1.subject = StringtoWord("Subjdfbsndgjsdgsfhnsgndgject 1");
//     email1.body = StringtoBody("Gomen, amanai. Ore wa ima~~ omae no tameni wakotenai. Daremoni kunjai iinai. imawa tada tada..... Kono sekai wa kokochi tenjo tengen, yui hatokson. dai dai tsudaru-sodeno jujutsuki no merito wa, torisetsuna koto. \n demerito wa, jujutsukino joho ga ore wa sui-koto anta, zen'in keto nengen daro mukagen jujutsu no koto yo~kushderu akeda danga-kore wa, gojo keno-naka-no-koku-ichibun-no-negen Laper rek shikAshirinai junten to hanten soro soro no mugen wosho-totsu saseru koto desu se se sareru, kaso hitsuruyo oshidasu kiyoshiki. Murasaki.");

//     CreateEmail(&email2);
//     email2.emailID = 2;
//     email2.senderID = user2.id;
//     email2.recipientID = user3.id;
//     email2.subject = StringtoWord("Subjectsdgshfejndgjdg 2");
//     email2.body = StringtoBody("Body of Email 2");

//     CreateEmail(&email3);
//     email3.emailID = 3;
//     email3.senderID = user3.id;
//     email3.recipientID = user1.id;
//     email3.subject = StringtoWord("Subject 3");
//     email3.body = StringtoBody("Body of Email 3");

//     // Add emails to the list
//     AddEmailToList(&emailList, email1);
//     AddEmailToList(&emailList, email2);
//     AddEmailToList(&emailList, email3);

//     // Create more sample emails
//     for (int i = 4; i <= 20; i++) {
//         Email email;
//         CreateEmail(&email);
//         email.emailID = i;
//         email.senderID = i % (countUser(userList)) + 1;
//         email.recipientID = (i + 1) % (countUser(userList)) + 1;
//         char subject[20];
//         char body[50];
//         sprintf(subject, "Subject %d", i);
//         sprintf(body, "Body of Email %d", i);
//         email.subject = StringtoWord(subject);
//         email.body = StringtoBody(body);
//         AddEmailToList(&emailList, email);
//     }

//     EmailList filteredList = filterInbox(emailList, userList, 2);

//     int currentPage = 1;
//     DaftarInbox(filteredList , userList);

//     printf("\nLanjut ke halaman berikutnya:\n");
//     LanjutInbox(filteredList, userList, &currentPage);

//     printf("\nKembali ke halaman sebelumnya:\n");
//     SebelumInbox(filteredList, userList, &currentPage);

//     printf("\nBaca pesan dengan ID 2:\n");
//     BacaPesan(&emailList, &filteredList, 1, userList);



//     return 0;
// }