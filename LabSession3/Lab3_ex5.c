
#include <stdio.h>

void addMatrices(int *mat1, int *mat2, int rows,
     int cols, int *result){

    
    for(int i=0; i<rows; i++){
        for (int j = 0; j < cols; j++){
            *(result + i*cols + j) = *(mat1 + i*cols + j)
             + *(mat2 + i*cols + j);

        }   
    }
}

int main(){
    int mat1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int mat2[3][3] = {
        {4, 5, 6},
        {7, 8, 9},
        {1, 2, 3}
        
    };

    int rows = sizeof(mat1)/sizeof(*mat1);
    int cols = sizeof((*mat1))/sizeof(**mat1);
    int result[3][3];

    addMatrices((int *)mat1, (int *)mat2, rows,
     cols, (int *)result);

    for(int i=0; i < 3; i++){
        for(int j=0; j<3; j++){
            printf("| %d ", *(*(result + i) + j));

        }
        printf("|\n------------");
        printf("\n");
    }
    return 0;
}

