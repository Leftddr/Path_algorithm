#include <stdio.h>
#include <Windows.h>
#include <math.h>
#pragma warning(disable:4996)

void floyd(int, float(*)[7], float(*)[7], float(*)[7]);
void path(float (*)[7],int, int);

int main() {
	float w[7][7] = { {0,4,INFINITY,INFINITY,INFINITY,10,INFINITY},
		{3,0,INFINITY,18,INFINITY,INFINITY,INFINITY},
		{INFINITY,6,0,INFINITY,INFINITY,INFINITY,INFINITY},
		{INFINITY,5,15,0,2,19,5},
		{INFINITY,INFINITY,12,1,0,INFINITY,INFINITY},
		{INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,0,10},
		{INFINITY,INFINITY,INFINITY,8,INFINITY,INFINITY,0} };
	float a[7][7];
	float d[7][7];
	float d1[7][7];
	float p[7][7];
	float p1[7][7];
	int n;
	int q, r;
	int cri1 = 6;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			a[i][j] = w[cri1 - i][cri1 - j];
		}
	}

	printf("n의 크기를 입력하시오 : ");
	scanf("%d", &n);
	floyd(n, w, d, p);
	floyd(n, a, d1, p1);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%.f ", p1[i][j]);
		}
		printf("\n");
	}
	printf("시작할 지점을 입력하시오 : ");
	scanf("%d", &q);
	printf("목적지를 입력하시오 : ");
	scanf("%d", &r);
	printf("a%d -> ", q);
	path(p, q-1, r-1);
	printf("a%d 끝 \n",r);
	printf("a의 시작지점을 입력하시오 :");
	scanf("%d", &q);
	printf("a의 끝지점을 입력하시오 : ");
	scanf("%d", &r);
	printf("a%d -> ", q);
	path(p1, q - 1, r - 1);
	printf("a%d 끝 \n", r);
	system("pause");
	return 0;
}

void floyd(int n, float(*w)[7], float(*d)[7], float(*p)[7]) {
	int i, j, k;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			p[i][j] = 0;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			d[i][j] = w[i][j];
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for (j = 0; j < n; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					p[i][j] = k+1;
					d[i][j] = d[i][k] + d[k][j];
				}
			}
	return;
}
void path(float (*p)[7],int q, int r) {
	if (p[q][r] != 0) {
		path(p,q, p[q][r]-1);
		printf("a%.f -> ", p[q][r]);
		path(p,p[q][r]-1, r);
	}
}