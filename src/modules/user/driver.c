// #include <stdio.h>
// #include "user.h" 

// void testWithInput() {
//     printf("Testing reading users from file...\n");

//     // Specify the file path
//     char* fileName = "C:\\Users\\YOGA\\Downloads\\if2110-tugas-besar-2024-if2110-02-h\\src\\modules\\user\\pengguna.config";

//     // Initialize the UserList
//     UserList userList;
//     createUserList(&userList);

//     // Read users from the file
//     readUsersFromFile(fileName, &userList);

//     // Display all users
//     for (int i = 0; i < countUser(userList); i++) {
//         displayUser(userList.users[i]);
//         printf("\n");
//     }

//     printf("Finished displaying users.\n");

//     Word email;
//     Word password;
//     User user;
//     printf("Enter email: ");
//     STARTWORD();
//     email = currentWord;
//     user.email = email;
    
//     printf("Enter password: ");
//     STARTWORD();
//     password = currentWord;  
//     user.password = password;
//     user.id = countUser(userList) + 1;

//     // if (validateRegister(userList, email, password)) {
//     //     printf("User is valid.\n");
//     // } else {
//     //     printf("User is invalid.\n");
//     // };

//     Register(&userList, user);
//     displayAllUsers(userList);

//     User user2;
//     printf("Login test...\n");
//     printf("Enter email: ");
//     STARTWORD();
//     Word checkemail = currentWord;
    
//     printf("Enter password: ");
//     STARTWORD();
//     Word checkpassword = currentWord;
    

//     createUser(&user2, 2, checkemail, checkpassword);
   
//     user2 = Login(&userList, user2);
//     if (user2.id != -1) {
//         printf("\n");
//         displayUser(user2);
//     } 

//     User finduser = findUserByEmail(userList, StringtoWord("alstrukdat@itb.ac.id"));
//     if (finduser.id != -1) {
//         printf("yay!\n");
//         displayUser(finduser);
//     }
//     displayAllUsers(userList);
//     writeUsersToFile("pengguna1.config", &userList);
// }

// int main() {
//     testWithInput();  // Call the test function
//     return 0;
// }
