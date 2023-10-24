#include <stdio.h>
#include <stdlib.h>
typedef unsigned long longer;
//--------------------------------------------------------------------
//allocate 2D arrray of double
double** malloc2D(longer SIZE){
	double** arr = (double**) malloc(sizeof(double*) * SIZE);
	longer i;
	for(i=0;i<SIZE;i++){
		arr[i] = (double*) malloc(sizeof(double) * SIZE);
	}
	return arr;
}
//--------------------------------------------------------------------
void free2D(double** arr, longer SIZE){
	longer i;
	for(i=0;i<SIZE;i++){
		free(arr[i]);
	}
	free(arr);
}
//--------------------------------------------------------------------
double randFrom(double min, double max){
	double range = max - min;
	return min + rand() / (RAND_MAX / range);
}
//--------------------------------------------------------------------
void matrix_mult(double** a, double** b, double** c, longer SIZE, longer BLOCK){
    longer i,j,k;
    longer  ii, jj, kk;
    for(ii=0; ii<SIZE; ii+=BLOCK){
        for(jj=0; jj<SIZE; jj+=BLOCK){
            for(kk=0; kk<SIZE; kk+=BLOCK){
                for(i=ii; i<(ii+BLOCK); i++){
                    for(j=jj; j<(jj+BLOCK);j++){
                        for(k=kk; k<(kk+BLOCK);k++){
                            c[i][j] += a[i][k] * b[k][j];
                        }
                    }

                }
            }
        }
    }
}
//--------------------------------------------------------------------
int main(int argc, char** argv){
	if(argc != 3){
		printf("Invalid Args\n");
		return -1;
	}
	longer SIZE = atoi(argv[1]);
	longer BLOCK = atoi(argv[2]);
	if(SIZE % BLOCK != 0){
		printf("Invalid block size\n");
		return -1;
	}
	//----------------------------------------------------------------
	double** a = malloc2D(SIZE);
	double** b = malloc2D(SIZE);
	double** c = malloc2D(SIZE);
	//----------------------------------------------------------------
	longer i, j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			a[i][j] = randFrom(-1.0, 1.0);
			b[i][j] = randFrom(-1.0, 1.0);
		}
	}
	//----------------------------------------------------------------
	matrix_mult(a, b, c, SIZE, BLOCK);
	//----------------------------------------------------------------
	free2D(a, SIZE);
	free2D(b, SIZE);
	free2D(c, SIZE);
	return 0;
}
