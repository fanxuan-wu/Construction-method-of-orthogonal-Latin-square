#define  _CRT_SECURE_NO_WARNINGS 1
#include"正交拉丁方.h"

int OLs4(int* A1[4][4], int* A2[4][4]) {//输出4阶正交拉丁方组
	int i, j;
	printf("4阶互为正交的拉丁方A1如下：\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0) printf(" | ");
			printf("%d ", A1[i][j]);
			if (j == 3) printf("| \n");
		}
	}
	printf("4阶互为正交的拉丁方A2如下：\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j == 0) printf(" | ");
			printf("%d ", A2[i][j]);
			if (j == 3) printf("| \n");
		}
	}
}
int OLsOdd(int* A1[][N], int* A2[][N], int* n){
	printf("%d阶互为正交的拉丁方A1如下：\n",*n);
	int i = 0, j = 0;
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			A1[i][j] = (1 * i + j) % *n;
		}
	}
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A1[i][j]);
			if (j == *n - 1) printf("| \n");
		}
	}
	printf("\n");
	printf("%d阶互为正交的拉丁方A2如下：\n",*n);
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			A2[i][j] = (2 * i + j) % *n;
		}
	}
	for (i = 0; i < *n; i++) {
		for (j = 0; j < *n; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A2[i][j]);
			if (j == *n - 1) printf("| \n");
		}
	}
}
int Pnd(int* n, int* p) {//二次判定并分解n；
	{
		int i, a;
		a = *n;
		for (i = 0;; i++) {
			if (a == 1) {//当n存在只存在质数因数2时返回1
				printf("%d = 2^%d\n", *n, *p);
				return 1;
			}
			else if (a % 2 == 0) {//判定存在几个因数2
				a = a / 2;
				*p = *p + 1;
			}
			else if (*p != 1) {//当n不只存在一个因数2，以及一个奇数时返回2
				printf("%d = 2^%d * %d\n", *n, *p, a);
				return 2;
			}
			else if (*p == 1) {//当n存在1个因数2，以及一个奇数时返回0
				printf("由于%d中存在一个因数2\n", *n);
				printf("虽然理论上存在%d阶的正交拉丁方\n", *n);
				printf("但很抱歉,并不能通过此程序构造出%d阶正交拉丁方\n", *n);
				return 0;
			}
		}
	}
}

int init(int* A[][4], int* B[][4], int* A1[][N], int* A2[][N]) {//对A1、A2进行初始化
	int i, j;
	for (i = 0; i < 4; i++) {//将A赋值给A1
		for (j = 0; j < 4; j++)
			A1[i][j] = A[i][j];
	}
	for (i = 0; i < 4; i++) {//将B赋值给A2
		for (j = 0; j < 4; j++)
			A2[i][j] = B[i][j];
	}
}
int copy_array(int source1[][N], int source2[][N], int destination1[][N], int destination2[][N], int m) {
	int i, j;
	{//构造2m阶正交拉丁方destination1
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) destination1[i][j] = source1[i][j];
			for (j = m; j < 2 * m; j++) destination1[i][j] = source1[i][j - m] + m;
		}
		for (i = m; i < 2 * m; i++) {
			for (j = 0; j < m; j++) destination1[i][j] = source1[i - m][j] + m;
			for (j = m; j < 2 * m; j++) destination1[i][j] = source1[i - m][j - m];
		}
	}
	{//构造正交拉丁方destination2
		for (i = 0; i < m / 2; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = source2[i][j];
			for (j = m; j < 2 * m; j++) destination2[i][j] = source2[i][j - m] + m;
		}
		for (i = m; i < 3 * m / 2; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = source2[i - m / 2][j];
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] + m;
		}
		for (i = m / 2; i < m; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = destination2[i - m / 2][j] + m;
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] - m;
		}
		for (i = 3 * m / 2; i < 2 * m; i++) {
			for (j = 0; j < m; j++) destination2[i][j] = destination2[i - m / 2][j] + m;
			for (j = m; j < 2 * m; j++) destination2[i][j] = destination2[i][j - m] - m;
		}
	}
}
int OLs4doub(int* A1[N][N], int* A2[N][N], int* A3[N][N], int* A4[N][N], int p) {//4的倍数阶正交拉丁方的构建
	int a, i, j, m;
	for (i = 0; i < p; i++) {//一共需要构造p次
		m = 4 * (int)pow(2, i);;//从4阶开始构造8阶，直到所要求的阶数
		copy_array(A1, A2, A3, A4, m);//把两个m阶正交拉丁方A1，A2构造成A3，A4
		for (a = 0; a < 2 * m; a++) {//重新把新构成的A3，A4赋值到A1，A2，方便继续构造
			for (j = 0; j < 2 * m; j++)
				A1[a][j] = A3[a][j];
		}
		for (a = 0; a < 2 * m; a++) {
			for (j = 0; j < 2 * m; j++)
				A2[a][j] = A4[a][j];
		}
	}
	copy(A1, A2, m);//输出A1、A2
}
int copy(int* A1[][N], int* A2[][N], int m){
	int i, j;
	printf("\n");
	for (i = 0; i < 2 * m; i++) {//输出A1
		for (j = 0; j < 2 * m; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A1[i][j]);
			if (j == 2 * m - 1) printf("| \n");
		}
	}
	printf("\n");
	for (i = 0; i < 2 * m; i++) {//输出A2
		for (j = 0; j < 2 * m; j++) {
			if (j == 0) printf(" | ");
			printf("%2d ", A2[i][j]);
			if (j == 2 * m - 1) printf("| \n");
		}
	}
}
int OLs4Odd(int C[][N], int D[][N],int C1[][N], int m, int n) {
	int a,i, j, k, o;
	int p = 0, q = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (k = 0; k < n; k++) {
				for (o = 0; o < m; o++) {
					a = C[i][k] * 10 * (D[j][o] / 10 + 1) + D[j][o];
					for (p; p < n * m;) {
						for (q; q < n * m;) {
							C1[p][q] = a;
							q++;
							break;
						}
						if (q == n * m) {
							q = 0; p++; break;
						}
						else break;
					}
				}
			}
		}
	}
}



void reorder_matrix(int* C[][N], int n) {
	int mapping[N] = { 0 };
	int count = 0;
	int i, j, k;
	for (int i = 0; i < n; i++) {//首先遍历矩阵A的第一行，将出现过的元素保存到mapping数组中
		mapping[i] = C[0][i];
	}
	for (i = 0; i < n; i++) {//再次遍历矩阵A，将矩阵A中的元素替换成对应的新值
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (C[i][j] == mapping[k]) {
					C[i][j] = k;
						break;
					}
				}

			}
		}
	for (i = 0; i < n; i++) {//对重复的数值进行重新赋值 
		for (j = 0; j < n; j++) {
			if (j > 1 && C[i][j] == C[i][j - 1])
				C[i][j] = j;
		}
	}
	}

