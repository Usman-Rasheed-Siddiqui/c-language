
#include <stdio.h>

void unique(int arr[], int length) {

    int unique_arr[length];
    int uniquesize = 0;

    for (int i=0; i < length; i++) {
        int found = 0;

        for(int j=0; j< uniquesize; j++) {
            if (arr[i] == unique_arr[j]) {
                found = 1;
            } 
        }
        if (found == 0) {
            unique_arr[uniquesize] = arr[i];
            uniquesize++;
            printf("Unique Element at %d is %d\n",
                 i, arr[i]);
        }

    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 6, 2, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    unique(arr, length);
    return 0;
}