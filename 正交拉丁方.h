#pragma once
#include<stdio.h>
#include<math.h>
#define N 100
//º¯ÊıÉùÃ÷
int Pnd(int *n, int *p);
int OLs4(int* A1[4][4], int* A2[4][4]);
int OLsOdd(int* A1[][N], int* A2[][N], int* n);

int init(int* A[][4], int* B[][4], int* A1[][N], int* A2[][N]);
int copy(int* A1[][N], int* B2[][N], int m);
int copy_array(int source1[][N], int source2[][N], int destination1[][N], int destination2[][N], int m);

void reorder_matrix(int* C[N][N], int n);
int OLs4doub(int* A1[N][N], int* A2[N][N], int* A3[N][N], int* A4[N][N], int p);
int OLs4Odd(int C[][N], int D[][N], int C1[][N], int m, int n);
