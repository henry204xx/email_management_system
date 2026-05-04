// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../modules/boolean.h"
// #include "load.h"

// void testFolderExists() {
//     char folderPath[256];
//     printf("\n=== Test folderExists ===\n");
//     printf("Enter folder path to check: ");
//     scanf("%s", folderPath);

//     if (folderExists(folderPath)) {
//         printf("Folder '%s' exists.\n", folderPath);
//     } else {
//         printf("Folder '%s' does not exist.\n", folderPath);
//     }
// }

// void testValidateConfigFolder() {
//     char folderPath[256];
//     printf("\n=== Test validateConfigFolder ===\n");
//     printf("Enter folder path to validate config files: ");
//     scanf("%s", folderPath);

//     if (validateConfigFolder(folderPath)) {
//         printf("Folder '%s' has all required config files.\n", folderPath);
//     } else {
//         printf("Folder '%s' is missing some required config files.\n", folderPath);
//     }
// }

// void testLoadConfigFolder() {
//     char folderPath[256];
//     printf("\n=== Test loadConfigFolder ===\n");
//     printf("Enter folder path to load: ");
//     scanf("%s", folderPath);

//     if (loadConfigFolder(folderPath)) {
//         printf("Folder '%s' is ready to use.\n", folderPath);
//     } else {
//         printf("Folder '%s' is invalid or missing required files.\n", folderPath);
//     }
// }

// int main() {
//     int choice;

//     while (1) {
//         printf("\n========================\n");
//         printf("1. Test folderExists\n");
//         printf("2. Test validateConfigFolder\n");
//         printf("3. Test loadConfigFolder\n");
//         printf("4. Exit\n");
//         printf("========================\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 testFolderExists();
//                 break;
//             case 2:
//                 testValidateConfigFolder();
//                 break;
//             case 3:
//                 testLoadConfigFolder();
//                 break;
//             case 4:
//                 printf("Exiting test driver.\n");
//                 exit(0);
//                 break;
//             default:
//                 printf("Invalid choice. Try again.\n");
//                 break;
//         }
//     }

//     return 0;
// }
