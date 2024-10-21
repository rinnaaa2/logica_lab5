#include <iostream>
#include <locale.h>

int main() {
    srand(time(0));
    setlocale(LC_ALL, "");

    int m = 5, Gsize = 0;
    int** G, * deg, ** incidence;

    deg = (int*)malloc(m * sizeof(int));
    G = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        G[i] = (int*)malloc(m * sizeof(int));
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
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
    printf("Размер графа = %d\n", Gsize / 2);

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
        printf("Степень вершины %d = %d\n", i, deg[i]);
    }

    for (int i = 0; i < m; i++) {
        if (deg[i] == 0) printf("Вершина %d изолированная\n", i);
        if (deg[i] == 1) printf("Вершина %d концевая\n", i);
        if (deg[i] == m - 1) printf("Вершина %d доминирующая\n", i);
    }

    printf("\nЗадание 4\n");
    int rebro = 0; // для счета ребер
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) { 
            if (G[i][j] == 1) {
                rebro++;
            }
        }
    }

    incidence = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        incidence[i] = (int*)malloc(rebro * sizeof(int));
        for (int j = 0; j < rebro; j++) {
            incidence[i][j] = 0; 
        }
    }

    int tec_rebro = 0; 
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (G[i][j] == 1) {
                incidence[i][tec_rebro] = 1;
                incidence[j][tec_rebro] = 1;
                tec_rebro++;
            }
        }
    }

    printf("Матрица инцидентности:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < rebro; j++) {
            printf("%d ", incidence[i][j]);
        }
        printf("\n");
    }

    printf("Задание 5\n");
    int Gsize_incidence = 0;
    for (int j = 0; j < rebro; j++) {
        int rebro_count = 0;
        for (int i = 0; i < m; i++) {
            if (incidence[i][j] == 1) {
                rebro_count++;
            }
        }
        if (rebro_count == 2) {
            Gsize_incidence++;
        }
    }
    printf("Размер графа по матрице инцидентности = %d\n", Gsize_incidence);

    printf("\nЗадание 6\n");
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < rebro; j++) {
            if (incidence[i][j] == 1) {
                count++;
            }
        }

        if (count == 0) printf("Вершина %d изолированная\n", i);
        if (count == 1) printf("Вершина %d концевая\n", i);
        if (count == m - 1) printf("Вершина %d доминирующая\n", i);
    }
    return 0;
}
