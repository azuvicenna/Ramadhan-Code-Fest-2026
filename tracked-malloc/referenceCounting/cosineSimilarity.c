#include<stdlib.h>
#include"stdio.h"
/*
						 sigma(a[i] * b[i])
cosineSimilarity(a, b) = ---------------------------------------------------------
						 squareRoot(sigma(a[i] ^ 2)) * squareRoot(sigma(b[i] ^ 2))
*/


static int * sigmaAB(int * a, int * b) {

	int * abArray = (int *)malloc(sizeof(int) * 13);
	int * sigmaABarray = malloc(sizeof(int));

	//* sigmaABarray = 0; /*Initialize sigmaABarray to 0 cant be here, we must check nullptr first bellow*/

	if (abArray == NULL || sigmaABarray == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	* sigmaABarray = 0; /*Initialize sigmaABarray to 0*/

	for (int i = 0; i < 13; ++i) {
		abArray[i] = a[i] * b[i];
	}

	for (int i = 0; i < 13; ++i) {
		* sigmaABarray += abArray[i];
	}

	return sigmaABarray;

}



int main() {
	
	/*13 words in total*/
	int document1[] = {1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};
	int document2[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	int document3[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	int * result1 = sigmaAB(document1, document2);

	/*sigmaAB(document1, document2) = 9*/
	printf("sigmaAB(document1, document2) = %d", * result1);

}