#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int SIZE, NNZ;
double **matrix, *input_vector, *output_vector;
void allocateCOO() {
        matrix = (double **) malloc(sizeof(double *) * SIZE);
	for(int i=0;i<SIZE;i++){
		matrix[i] = (double *)malloc(sizeof(double) * SIZE);
	}
        input_vector = (double *) malloc(sizeof(double) * SIZE);
        output_vector = (double *) malloc(sizeof(double) * SIZE);
}
void deallocateCOO() {
	for(int i=0;i<SIZE;i++){
		free(matrix[i]);
	}
        free(matrix);
        free(input_vector);
        free(output_vector);
}
void initCOO() {
        int i,j;
	int di,dj;
	double v;
        for(i=0;i<SIZE;i++){
                scanf("%lf %lf",&input_vector[i],&output_vector[i]);
	}
	for(i<=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			matrix[i][j]=0.0;
		}
	}
        for(i=0;i<NNZ;i++) {
		scanf("%d %d %lf", &di, &dj, &v);
		matrix[di][dj]=v;
	}
}
void dot_product() {
	//make this parallel ....
        int i,j;
        for (i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
	                output_vector[i] += matrix[i][j] * input_vector[j];
		}
	}
}
int main() {
        int i;
	scanf("%d %d",&SIZE,&NNZ);
        allocateCOO();
        initCOO();
	//------------>
       	dot_product();
	//------------>
        deallocateCOO();
        return 0;
}
