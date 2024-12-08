#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <climits>
#include <cstring>

using namespace std;

vector<vector<int>> createGNeOr(vector<vector<int>> G) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (rand() % 2) {
                G[i][j] = rand() % 9 + 1;
                G[j][i] = G[i][j];
            }
            if (i == j) G[i][j] = 0;
        }
    }
    return G;
}

vector<vector<int>> createGOr(vector<vector<int>> G) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (rand() % 2) {
                G[i][j] = rand() % 9 + 1;
            }
            if (i == j) G[i][j] = 0;
        }
    }
    return G;
}

vector<vector<int>> createGNeOrU(vector<vector<int>> G) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (rand() % 2) {
                G[i][j] = 1;
                G[j][i] = G[i][j];
            }
            if (i == j) G[i][j] = 0;
        }
    }
    return G;
}

vector<vector<int>> createGOrU(vector<vector<int>> G) {
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G.size(); j++) {
            if (rand() % 2) {
                G[i][j] = 1;
            }
            if (i == j) G[i][j] = 0;
        }
    }
    return G;
}

void printG(vector<vector<int>>& G) {
    for (int i = 0; i < G.size(); i++) {
        for (int val : G[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc < 5) {
        cout << "Использование: " << argv[0] << " -type <weighted/unweighted> -orientation <directed/undirected>" << endl;
        return 1;
    }

    string graphType;
    string orientation;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-type") == 0 && i + 1 < argc) {
            graphType = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i], "-orientation") == 0 && i + 1 < argc) {
            orientation = argv[i + 1];
            i++;
        }
    }

    cout << "Тип графа: " << graphType << endl;
    cout << "Ориентация графа: " << orientation << endl;

    int size = 0;
    cout << "Введите количество вершин графа: ";
    cin >> size;

    vector<vector<int>> G(size, vector<int>(size, 0));

    if (graphType == "weighted" && orientation == "undirected") {
        G = createGNeOr(G);
        cout << "Матрица смежности неориентированного взвешенного графа:" << endl;
    }
    else if (graphType == "weighted" && orientation == "directed") {
        G = createGOr(G);
        cout << "Матрица смежности ориентированного взвешенного графа:" << endl;
    }
    else if (graphType == "unweighted" && orientation == "undirected") {
        G = createGNeOrU(G);
        cout << "Создание невзвешенного неориентированного графа:" << endl;
    }
    else if (graphType == "unweighted" && orientation == "directed") {
        G = createGOrU(G);
        cout << "Создание невзвешенного ориентированного графа:" << endl;
    }
    else {
        cout << "Некорректные параметры." << endl;
        return 1;
    }

    printG(G);

    return 0;
}
