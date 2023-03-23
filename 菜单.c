#define  _CRT_SECURE_NO_WARNINGS 1
#include"正交拉丁方.h"

int main()
{
	int n;
	int A[4][4] = { 0,1,2,3, 1,0,3,2, 2,3,0,1, 3,2,1,0 };
	int B[4][4] = { 0,1,2,3, 2,3,0,1, 3,2,1,0, 1,0,3,2 };
	int A1[N][N] = { 0 };
	int A2[N][N] = { 0 };
	int A3[N][N] = { 0 };
	int A4[N][N] = { 0 };//构造几个空矩阵用于存储数据；
	int C1[N][N] = { 0 }, C2[N][N] = { 0 };
	printf("请输入所要求的正交拉丁方的阶数n:\n");
	scanf("%d", &n);
	if (n <= 2 || n == 6) {//基础成立条件判定
		printf("不存在阶数为%d的正交拉丁方\n", n);
		return 0;
	}
	else if (n == 4) {
		OLs4(A, B);//输出4阶正交拉丁方组
		return 0;
	}
	else if (n % 2 == 1) {
		OLsOdd(A1, A2, &n);//构造并输出奇数正交拉丁方组
		return 0;
	}

	int p = 0, m;
	m = Pnd(&n, &p);//二次判定并分解n；
	if (m == 1) {//构造并输出4*2^p阶正交拉丁方。
		init(A, B, A1, A2);//对A1、A2进行初始化，即把4阶矩阵A、B的值赋值到A1、A2
		p = p - 2;//得到n=4*2^p
		OLs4doub(A1, A2, A3, A4, p);//4*2^p的倍数阶正交拉丁方的构建,并输出。
	}
	else if (m == 2) {
		if (p == 2) {
			m = 4, n = n / 4;
			OLsOdd(A1, A2, &n); //构造并输出奇数正交拉丁方组
			init(A, B, A3, A4);//对A3、A4进行初始化，即把4阶矩阵A、B的值赋值到A3、A4
			OLs4Odd(A3, A1, C1, n, m);
			OLs4Odd(A4, A2, C2, n, m);
			reorder_matrix(C1, n * m);//对C1重新排序
			reorder_matrix(C2, n * m);
			copy(C1, C2, n * m / 2);//输出C1、C2
		}
		else {
			n = n / (int)pow(2, p);
			p = p - 2;//得到n=4*2^p
			OLsOdd(A1, A2, &n); //构造并输出奇数正交拉丁方组
			init(A, B, A3, A4);//对A3、A4进行初始化，即把4阶矩阵A、B的值赋值到A3、A4
			OLs4doub(A3, A4, C1, C2, p);//4*2^p的倍数阶正交拉丁方的构建,并输出。
			OLs4Odd(A3, A1, C1, n, 4 * (int)pow(2, p));
			OLs4Odd(A4, A2, C2, n, 4 * (int)pow(2, p));
			reorder_matrix(C1, n * 4 * (int)pow(2, p));//对C1重新排序
			reorder_matrix(C2, n * 4 * (int)pow(2, p));
			copy(C1, C2, n * 4 * (int)pow(2, p) / 2);//输出C1、C2
		}
	}
	return 0;
}