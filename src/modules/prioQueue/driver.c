// #include "prioqueue.h"

// int main(int argc, char const *argv[])
// {
//     PrioQueue pq;
//     char ch;
//     int eTemp, pTemp;

//     PQ_CreatePrioQueue(&pq);
//     PQ_displayPrioQueue(pq);

//     do {
//         scanf("%c", &ch);

//         switch (ch)
//         {
//         case 'E':
//             scanf("%d %d", &eTemp, &pTemp);
//             PQ_enqueue(&pq, eTemp, pTemp);
//             PQ_displayPrioQueue(pq);
//             break;
//         case 'D':
//             PQ_dequeue(&pq);
//             PQ_displayPrioQueue(pq);
//             break;
//         case 'L':
//             scanf("%d", &eTemp);
//             PQ_deleteEmail(&pq, eTemp);
//             PQ_displayPrioQueue(pq);
//             break;
//         }
//     } while (ch != 'X');
//     return 0;
// }
