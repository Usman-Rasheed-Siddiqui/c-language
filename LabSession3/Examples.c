
#include <stdio.h>
#include <stdlib.h>

// int *getRandom(){
//     static int r[10];
//     int i;
//     srand((unsigned) time(NULL));
//     for(i=0; i<10; i++){
//         r[i] = rand();
//         printf("%d\n", r[i]);
//     }
//     return r;
// }

// int main(){
//     int *p;
//     int i;

//     p = getRandom();
//     for(i=0; i<10; i++){
//         printf("(*p + [%d]): %d\n",i, *(p + i));
//     }
// }


// double Average(int *arr, int size);

// int main(){
//     int balance[5] = {1000, 2, 3, 17, 50};
//     double avg;
//     avg = Average(balance, 5);
//     printf("Average value is: %f\n", avg ); 
//     return 0; 
// }


// double Average(int *arr, int size){
//     int i, sum = 0;
//     for(i=0; i < size; i++){
//         sum += *(arr + i);

//     }
//     double avg = (double) sum/ size;
//     return avg;

// }


// void getSeconds(unsigned long *par);

// int main(){
//     unsigned long sec;
//     getSeconds(&sec);

//     printf("Number of seconds: %d", sec);
//     return 0;
// }

// void getSeconds(unsigned long *par){
//     *par = time ( NULL );
//     return; 
// }