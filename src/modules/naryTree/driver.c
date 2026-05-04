// #include <stdio.h>
// #include "narytree.h"

// int main(int argc, char const *argv[]) {
//     NaryTree root = NULL; // Initialize an empty tree
//     int val, parentVal;
//     char ch;

//     do {
//         scanf("%c", &ch);

//         switch (ch) {
//         /* Create root */
//         case 'R':
//             scanf("%d", &val);
//             if (root == NULL) {
//                 root = newTreeNode(val);
//             } else {
//                 printf("Root already exists!\n");
//             }
//             break;
//         /* Add child */
//         case 'A':
//             scanf("%d %d", &parentVal, &val);
//             if (root == NULL) {
//                 printf("Tree is empty! Create root first.\n");
//             } else {
//                 TR_Address parent = findNode(root, parentVal);
//                 if (parent == NULL) {
//                     printf("Parent node with value %d not found.\n", parentVal);
//                 } else {
//                     TR_Address child = newTreeNode(val);
//                     addChild(parent, child);
//                 }
//             }
//             break;
//         /* Print Tree */
//         case 'P':
//             if (root == NULL) {
//                 printf("Tree is empty.\n");
//             } else {
//                 printTree(root);
//                 printf("\n");
//             }
//             break;
//         }
//     } while (ch != 'X');

//     return 0;
// }