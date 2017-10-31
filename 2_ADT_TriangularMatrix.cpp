#include<stdio.h>
#include<malloc.h>

#define MAX_TRI_MATRIX_SIZE 99

void up_tri_mat(int* matrix, int size_byte) { // make and show upper triangular matrix
	int* temp;
	int temp_num = size_byte / sizeof(int);

	for (int i = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] == 0)
			temp_num -= 1;
	}
	temp = (int*)malloc(temp_num * sizeof(int));

	for (int i = 0, j = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] != 0) {
			temp[j++] = matrix[i];
		}
	}
	// 위 코드는 matrix의 0이 아닌 원소를 temp 배열에 저장, temp_num은 temp배열의 원소 개수

	int new_size;
	int usable;
	for (int i = 0; i < MAX_TRI_MATRIX_SIZE; i++) {
		new_size = i;
		usable = 0;

		for (int n = new_size; n > 0; n--) {
			usable += n;
		}
		if (usable >= temp_num)
			break;
	}
	// 새로 생성할 삼각행렬의 크기를 지정, new_size는 새로 생성할 n by n 삼각행렬의 최소 n 크기, usable은 삼각행렬의 0이 아닌 원소 개수

	int** upper_tri_matrix;
	upper_tri_matrix = (int**)malloc((new_size) * sizeof(int));
	for (int i = 0; i < new_size; i++) {
		*(upper_tri_matrix + i) = (int*)malloc((new_size) * sizeof(int));
	}

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			upper_tri_matrix[n][m] = 0;
		}
	}
	// upper_tri_matrix 변수에, n = new_size인 n by n 삼각행렬을 생성하고 모든 항을 0으로 초기화

	for (int n = 0, i = 0; n < new_size; n++) {
		for (int m = n; m < new_size; m++) {
			if (i >= temp_num) {
				upper_tri_matrix[n][m] = 0;
			}
			else {
				upper_tri_matrix[n][m] = temp[i++];
			}
		}
	}
	// upper triangular matrix의 0이 아닌 항들의 자리에, 왼쪽에서 오른쪽으로 위에서 아래로의 순서로 temp변수 값 대입 

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			printf("%d ", upper_tri_matrix[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	// 만들어진 upper triangular matrix를 출력

	free(temp);
	free(*upper_tri_matrix);
	free(upper_tri_matrix);
}

void low_tri_mat(int* matrix, int size_byte) { // make and show lower triangular matrix
	int* temp;
	int temp_num = size_byte / sizeof(int);

	for (int i = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] == 0)
			temp_num -= 1;
	}
	temp = (int*)malloc(temp_num * sizeof(int));

	for (int i = 0, j = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] != 0) {
			temp[j++] = matrix[i];
		}
	}
	// 위 코드는 matrix의 0이 아닌 원소를 temp 배열에 저장, temp_num은 temp배열의 원소 개수

	int new_size;
	int usable;
	for (int i = 0; i < MAX_TRI_MATRIX_SIZE; i++) {
		new_size = i;
		usable = 0;

		for (int n = new_size; n > 0; n--) {
			usable += n;
		}
		if (usable >= temp_num)
			break;
	}
	// 새로 생성할 삼각행렬의 크기를 지정, new_size는 새로 생성할 n by n 삼각행렬의 최소 n 크기, usable은 삼각행렬의 0이 아닌 원소 개수

	int** lower_tri_matrix;
	lower_tri_matrix = (int**)malloc((new_size) * sizeof(int));
	for (int i = 0; i < new_size; i++) {
		*(lower_tri_matrix + i) = (int*)malloc((new_size) * sizeof(int));
	}

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			lower_tri_matrix[n][m] = 0;
		}
	}
	// lower_tri_matrix 변수에, n = new_size인 n by n 삼각행렬을 생성하고 모든 항을 0으로 초기화

	for (int n = 0, i = 0; n < new_size; n++) {
		for (int m = 0; m <= n; m++) {
			if (i >= temp_num) {
				lower_tri_matrix[n][m] = 0;
			}
			else {
				lower_tri_matrix[n][m] = temp[i++];
			}
		}
	}
	// lower triangular matrix의 0이 아닌 항들의 자리에, 왼쪽에서 오른쪽으로 위에서 아래로의 순서로 temp변수 값 대입 

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			printf("%d ", lower_tri_matrix[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	// 만들어진 lower triangular matrix를 출력

	free(temp);
	free(*lower_tri_matrix);
	free(lower_tri_matrix);
}

void l_up_tri_mat(int* matrix, int size_byte) { // make and show left upper triangular matrix
	int* temp;
	int temp_num = size_byte / sizeof(int);

	for (int i = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] == 0)
			temp_num -= 1;
	}
	temp = (int*)malloc(temp_num * sizeof(int));

	for (int i = 0, j = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] != 0) {
			temp[j++] = matrix[i];
		}
	}
	// 위 코드는 matrix의 0이 아닌 원소를 temp 배열에 저장, temp_num은 temp배열의 원소 개수

	int new_size;
	int usable;
	for (int i = 0; i < MAX_TRI_MATRIX_SIZE; i++) {
		new_size = i;
		usable = 0;

		for (int n = new_size; n > 0; n--) {
			usable += n;
		}
		if (usable >= temp_num)
			break;
	}
	// 새로 생성할 삼각행렬의 크기를 지정, new_size는 새로 생성할 n by n 삼각행렬의 최소 n 크기, usable은 삼각행렬의 0이 아닌 원소 개수

	int** l_upper_tri_matrix;
	l_upper_tri_matrix = (int**)malloc((new_size) * sizeof(int));
	for (int i = 0; i < new_size; i++) {
		*(l_upper_tri_matrix + i) = (int*)malloc((new_size) * sizeof(int));
	}

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			l_upper_tri_matrix[n][m] = 0;
		}
	}
	// l_upper_tri_matrix 변수에, n = new_size인 n by n 삼각행렬을 생성하고 모든 항을 0으로 초기화

	for (int n = 0, i = 0; n < new_size; n++) {
		for (int m = 0; m < new_size - n; m++) {
			if (i >= temp_num) {
				l_upper_tri_matrix[n][m] = 0;
			}
			else {
				l_upper_tri_matrix[n][m] = temp[i++];
			}
		}
	}
	// left upper triangular matrix의 0이 아닌 항들의 자리에, 왼쪽에서 오른쪽으로 위에서 아래로의 순서로 temp변수 값 대입 

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			printf("%d ", l_upper_tri_matrix[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	// 만들어진 left upper triangular matrix를 출력

	free(temp);
	free(*l_upper_tri_matrix);
	free(l_upper_tri_matrix);
}


void r_low_tri_mat(int* matrix, int size_byte) { // make and show right lower triangular matrix
	int* temp;
	int temp_num = size_byte / sizeof(int);

	for (int i = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] == 0)
			temp_num -= 1;
	}
	temp = (int*)malloc(temp_num * sizeof(int));

	for (int i = 0, j = 0; i < size_byte / sizeof(int); i++) {
		if (matrix[i] != 0) {
			temp[j++] = matrix[i];
		}
	}
	// 위 코드는 matrix의 0이 아닌 원소를 temp 배열에 저장, temp_num은 temp배열의 원소 개수

	int new_size;
	int usable;
	for (int i = 0; i < MAX_TRI_MATRIX_SIZE; i++) {
		new_size = i;
		usable = 0;

		for (int n = new_size; n > 0; n--) {
			usable += n;
		}
		if (usable >= temp_num)
			break;
	}
	// 새로 생성할 삼각행렬의 크기를 지정, new_size는 새로 생성할 n by n 삼각행렬의 최소 n 크기, usable은 삼각행렬의 0이 아닌 원소 개수

	int** r_lower_tri_matrix;
	r_lower_tri_matrix = (int**)malloc((new_size) * sizeof(int));
	for (int i = 0; i < new_size; i++) {
		*(r_lower_tri_matrix + i) = (int*)malloc((new_size) * sizeof(int));
	}

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			r_lower_tri_matrix[n][m] = 0;
		}
	}
	// r_lower_tri_matrix 변수에, n = new_size인 n by n 삼각행렬을 생성하고 모든 항을 0으로 초기화

	for (int n = 0, i = 0; n < new_size; n++) {
		for (int m = new_size - 1 - n; m < new_size; m++) {
			if (i >= temp_num) {
				r_lower_tri_matrix[n][m] = 0;
			}
			else {
				r_lower_tri_matrix[n][m] = temp[i++];
			}
		}
	}
	// right lower triangular matrix의 0이 아닌 항들의 자리에, 왼쪽에서 오른쪽으로 위에서 아래로의 순서로 temp변수 값 대입 

	for (int n = 0; n < new_size; n++) {
		for (int m = 0; m < new_size; m++) {
			printf("%d ", r_lower_tri_matrix[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	// 만들어진 right lower triangular matrix를 출력

	free(temp);
	free(*r_lower_tri_matrix);
	free(r_lower_tri_matrix);
}

void main() {
	int matrix3x3[3][3] = { { 1,2,0 },
	{ 3,4,0 },
	{ 5,6,0 } };
	int matrix4x4[4][4] = { { 1,2,3,4 },
	{ 5,6,0,0 },
	{ 7,0,0,0 },
	{ 8,9,0,0 } };

	up_tri_mat((int*)matrix3x3, sizeof(matrix3x3));
	low_tri_mat((int*)matrix3x3, sizeof(matrix3x3));
	l_up_tri_mat((int*)matrix3x3, sizeof(matrix3x3));
	r_low_tri_mat((int*)matrix3x3, sizeof(matrix3x3));

	up_tri_mat((int*)matrix4x4, sizeof(matrix4x4));
	low_tri_mat((int*)matrix4x4, sizeof(matrix4x4));
	l_up_tri_mat((int*)matrix4x4, sizeof(matrix4x4));
	r_low_tri_mat((int*)matrix4x4, sizeof(matrix4x4));
}