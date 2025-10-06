#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int SIZE, NNZ;
double *matrix_nnz, *input_vector, *output_vector;
int *matrix_rows, *matrix_columns;
void allocateCOO() {
        matrix_rows=(int *)malloc(sizeof(int)*NNZ);
        matrix_columns=(int *)malloc(sizeof(int)*NNZ);
        matrix_nnz=(double *)malloc(sizeof(double)*NNZ);
        input_vector=(double *)malloc(sizeof(double)*SIZE);
        output_vector=(double *)malloc(sizeof(double)*SIZE);
}
void deallocateCOO() {
        free(matrix_rows);
        free(matrix_columns);
        free(matrix_nnz);
        free(input_vector);
        free(output_vector);
}
double rand_double(double min, double max){
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
int rand_int(int min, int max){
                return rand() % (max - min);

}
void initCOO() {
        int i;
        for(i=0;i<SIZE;i++)
                scanf("%lf %lf",&input_vector[i],&output_vector[i]);
        for(i=0;i<NNZ;i++)
		scanf("%d %d %lf", &matrix_rows[i], &matrix_columns[i], &matrix_nnz[i]);
}

void SPMV() {
        int i;
        for (int i=0;i<NNZ;i++){
                output_vector[matrix_rows[i]] += matrix_nnz[i]*input_vector[matrix_columns[i]];
	}
}

int main() {
        int i;
	scanf("%d %d",&SIZE,&NNZ);
        allocateCOO();
        initCOO();
	//-------------->
        SPMV();
	//-------------->
        deallocateCOO();
        return 0;
}
