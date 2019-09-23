#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int W[5][5] = { {0,8,13,18,20},{3,0,7,8,10},{4,11,0,10,7},{6,6,7,0,11},{10,6,2,1,0} }; //����ġ �迭
int complete[5] = { 0, };//�ش� ���ø� ������ ������ Ȯ���� �ִ� �迭
int cost = 0;// ����� ����ϱ� ���� ����

void Min(int);
int path(int);

int main() {
	Min(0);
	printf("1");
	printf("\n");
	printf("�� ����ġ : %d\n", cost);
	system("pause");
	return 0;
}

void Min(int vertex) {
	int i, nvertex;
	complete[vertex] = 1;
	printf("%d-->", vertex + 1);
	nvertex = path(vertex);//���� vertex�� ����.

	if (nvertex == 1000)
	{
		nvertex = 0;
		cost += W[vertex][nvertex];
		return;
	}
	Min(nvertex); //�ٽ� Min �Լ��� ����Ѵ�.
}

int path(int low) {
	int i, nlow = 1000;
	int min = 1000, kmin;
	for (i = 0; i < 5; i++) {
		if ((W[low][i] != 0) && (complete[i] == 0))//����ġ�� 0 �̾ƴϰ� �ش� ���ø� ������ ���� �ʾ�����
			if (W[low][i] + W[i][low] < min)//low���� i���� i low ���� �Ÿ��� min���� ������
			{
				min = W[i][0] + W[low][i];//i���� 1����  low���� i���� ���� �Ÿ��� min �� �־���´�.
				kmin = W[low][i];//kmin�� ����
				nlow = i;//nlow�� i vertex�� ������ ���´�.
			}
	}
	if (min != 1000)
		cost += kmin;
	return nlow;// �� �� vertex�� ����.
}