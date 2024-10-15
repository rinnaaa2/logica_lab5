#include <iostream>
#include <locale.h>
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "");
	int m = 10, Gsize = 0;
	int** G, * deg;
	deg = (int*)malloc(m * sizeof(int));

	G = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		G[i] = (int*)malloc(m * sizeof(int));
	}

	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}

	printf("Задание 1\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d", G[i][j]);
		}
		printf("\n");
	}

	printf("\nЗадание 2\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				Gsize++;
			}
		}
	}
	printf("Размер графа =%d\n", Gsize/2);

	printf("\nЗадание 3\n");
	for (int i = 0; i < m; i++) {
		deg[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				deg[i]++;
			}
		}
		printf("Степень вершины %d = %d\n",i, deg[i]);
	}

	for (int i = 0; i < m; i++) {
		if (deg[i] == 0) printf("Вершина %d изолированная\n", i);
		if (deg[i] == 1) printf("Вершина %d концевая\n", i);
		if (deg[i] == m-1) printf("Вершина %d доминирующая\n", i);
	}
	return 0;
}

