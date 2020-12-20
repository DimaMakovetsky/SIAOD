#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#define N 6
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int mat[N][N];
    
    mat[0][0] = 0;      mat[0][1] = 10;     mat[0][2] = 70;     mat[0][3] = 30;     mat[0][4] = 0;      mat[0][5] = 0;
    mat[1][0] = 0;      mat[1][1] = 0;      mat[1][2] = 50;     mat[1][3] = 0;      mat[1][4] = 0;      mat[1][5] = 60;
    mat[2][0] = 0;      mat[2][1] = 0;      mat[2][2] = 0;      mat[2][3] = 20;     mat[2][4] = 20;     mat[2][5] = 40;
    mat[3][0] = 0;      mat[3][1] = 0;      mat[3][2] = 0;      mat[3][3] = 0;      mat[3][4] = 30;     mat[3][5] = 0;
    mat[4][0] = 0;      mat[4][1] = 0;      mat[4][2] = 0;      mat[4][3] = 0;      mat[4][4] = 0;      mat[4][5] = 10;
    mat[5][0] = 0;      mat[5][1] = 60;      mat[5][2] = 40;      mat[5][3] = 0;      mat[5][4] = 10;      mat[5][5] = 0;
    cout << "    ";
    for (int i = 0; i < N; i++)
    {
        printf("%3d  ", i);
    }
    cout << endl;
    cout << "————————————————————————————————";
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j]==0)
                cout << "     ";
            else
                printf("%3d  ", mat[i][j] );
        }
        cout << endl;
    }
    int choise, swap, pathEnd;
    int shortestPath[N];
    int longestPath[N];
    int mat2[N][N];
    int masMax[N] = { 0 };
    int minFromMax = 1000, minFromMaxIndex = 0;

    cout << "Выберите действие: "<<endl;
    cout << "1 — минимальный путь между вершинами " << endl;
    cout << "2 — максимальный путь между вершинами " << endl;
    cout << "3 — центр орграфа " << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
        cout << "Искать путь от: ";
        cin >> swap;
        cout << "До: ";
        cin >> pathEnd;
        if (swap == pathEnd)
        {
            cout << "Путь от вершины к самой себе всегда =0 " << endl;
            return 0;
        }
        for (int i = 0; i < N; i++)
        {
            int temp = mat[swap][i];
            mat[swap][i] = mat[0][i];
            mat[0][i] = temp;
        }
        for (int i = 0; i < N; i++)
        {
            int temp = mat[i][swap];
            mat[i][swap] = mat[i][0];
            mat[i][0] = temp;
        }
        shortestPath[0] = 0;
        for (int i = 1; i < N; i++)
        {

            shortestPath[i] = 1000;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] != 0)
                {

                    if (shortestPath[j] > shortestPath[i] + mat[i][j])
                    {
                        shortestPath[j] = shortestPath[i] + mat[i][j];
                    }
                }
            }
        }
        if (pathEnd == 0)
        {
            if (shortestPath[swap] == 1000)
            {
                printf("Пути %d->%d нет\n", swap, 0);
                return 0;
            }
            printf("Самый короткий путь %d->%d: %3d\n", swap, 0, shortestPath[swap]);
        }
        else
        {
            if (shortestPath[pathEnd] == 1000)
            {
                printf("Пути %d->%d нет\n", swap, pathEnd);
                return 0;
            }
            printf("Самый короткий путь %d->%d: %3d\n", swap, pathEnd, shortestPath[pathEnd]);
        }
        break;
    case 2:
        cout << "Искать путь от: ";
        cin >> swap;
        cout << "До: ";
        cin >> pathEnd;
        if (swap == pathEnd)
        {
            cout << "Путь от вершины к самой себе всегда =0 " << endl;
            return 0;
        }
        for (int i = 0; i < N; i++)
        {
            longestPath[i] = 0;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] != 0)
                {

                    if (longestPath[j] < longestPath[i] + mat[i][j])
                    {

                        longestPath[j] = longestPath[i] + mat[i][j];
                        cout << longestPath[j] << endl;
                    }
                }
            }
        }
        if (pathEnd == 0)
        {
            if (longestPath[swap] == 0)
            {
                printf("Пути %d->%d нет\n", swap, 0);
                return 0;
            }
            printf("Самый длинный путь %d->%d: %3d\n", swap, 0, longestPath[swap]);
        }
        else
        {
            if (longestPath[pathEnd] == 0)
            {
                printf("Пути %d->%d нет\n", swap, pathEnd);
                return 0;
            }
            printf("Самый длинный путь %d->%d: %3d\n", swap, pathEnd, longestPath[pathEnd]);
        }
        break;
    case 3:

        shortestPath[0] = 0;
        for (int i = 1; i < N; i++)
        {
            shortestPath[i] = 1000;
        }
        for (int h = 0; h < N; h++)
        {
            shortestPath[0] = 0;
            for (int i = 1; i < N; i++)
            {
                shortestPath[i] = 1000;
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (mat[i][j] != 0)
                    {

                        if (shortestPath[j] > shortestPath[i] + mat[i][j])
                        {
                            shortestPath[j] = shortestPath[i] + mat[i][j];
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++)
            {

                if (shortestPath[i] == 1000 || i == h)
                    mat2[h][i] = 0;
                else
                    mat2[h][i] = shortestPath[i];
            }
            if (h < N - 1)
            {
                for (int i = 0; i < N; i++)
                {
                    int temp = mat[h + 1][i];
                    mat[h + 1][i] = mat[0][i];
                    mat[0][i] = temp;

                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat2[i][j] > masMax[j])
                {
                    masMax[j] = mat2[i][j];
                }
            }
        }
        for (int i = 1; i < N; i++)
        {
            if (masMax[i] < minFromMax)
            {
                minFromMax = masMax[i];
                minFromMaxIndex = i;
            }
        }
        cout << "    ";
        for (int i = 0; i < N; i++)
        {
            printf("%3d  ", i);
        }
        cout << endl;
        cout << "————————————————————————————————";
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            cout << i << " | ";
            for (int j = 0; j < N; j++)
            {
                if (mat2[i][j] == 0)
                    cout << "     ";
                else
                    printf("%3d  ", mat2[i][j]);
            }
            cout << endl;
        }
        cout << "Центр орграфа вершина " << minFromMaxIndex << " с эксцентриситетом " << minFromMax;
        break;
    default:
        break;
    }
    return 0;
    
}

