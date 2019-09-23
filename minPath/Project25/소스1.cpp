#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int W[5][5] = { {0,8,13,18,20},{3,0,7,8,10},{4,11,0,10,7},{6,6,7,0,11},{10,6,2,1,0} }; //가중치 배열
int complete[5] = { 0, };//해당 도시를 지나쳐 갔는지 확인해 주는 배열
int cost = 0;// 비용을 계산하기 위한 변수

void Min(int);
int path(int);

int main() {
	Min(0);
	printf("1");
	printf("\n");
	printf("총 가중치 : %d\n", cost);
	system("pause");
	return 0;
}

void Min(int vertex) {
	int i, nvertex;
	complete[vertex] = 1;
	printf("%d-->", vertex + 1);
	nvertex = path(vertex);//그후 vertex로 간다.

	if (nvertex == 1000)
	{
		nvertex = 0;
		cost += W[vertex][nvertex];
		return;
	}
	Min(nvertex); //다시 Min 함수로 재귀한다.
}

int path(int low) {
	int i, nlow = 1000;
	int min = 1000, kmin;
	for (i = 0; i < 5; i++) {
		if ((W[low][i] != 0) && (complete[i] == 0))//가중치가 0 이아니고 해당 도시를 지나쳐 가지 않았을때
			if (W[low][i] + W[i][low] < min)//low에서 i까지 i low 까지 거리가 min보다 작을때
			{
				min = W[i][0] + W[low][i];//i에서 1까지  low에서 i까지 가는 거리를 min 에 넣어놓는다.
				kmin = W[low][i];//kmin에 저장
				nlow = i;//nlow에 i vertex를 저장해 놓는다.
			}
	}
	if (min != 1000)
		cost += kmin;
	return nlow;// 그 후 vertex로 간다.
}