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

vector<int> BFSD(vector<vector<int>> G, int v) {
    vector<int> DIST(G.size(), INT_MAX);
    queue<int> Q;

    Q.push(v);
    DIST[v] = 0;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();

        for (int i = 0; i < G.size(); ++i) {
            if (G[v][i] > 0 && DIST[v] + G[v][i] < DIST[i]) {
                Q.push(i);
                DIST[i] = DIST[v] + G[v][i];
            }
        }
    }
    return DIST;
}

vector<int> BFS(vector<vector<int>> G, int v) {
    vector<int> DIST(G.size(), -1);
    queue<int> Q;

    Q.push(v);
    DIST[v] = 0;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();

        for (int i = 0; i < G.size(); ++i) {
            if (G[v][i]==1 && DIST[i]==-1) {
                Q.push(i);
                DIST[i] = DIST[v] + 1;
            }
        }
    }
    return DIST;
}

void findRDCvPv(vector<vector<int>>& G) {
    vector<int>dist(G.size());
    vector<int> cV;
    vector<int> pV;

    int radius = INT_MAX;
    int diameter = 0;

    int Dist_min = INT_MAX;
    int Dist_max = 0;

    for (int i = 0; i < G.size(); i++) {
        dist = BFSD(G, i);
        int DISTma = 0;
        for (int di : dist) {
            if (di != INT_MAX) {
                DISTma = max(DISTma, di);
            }
        }
        Dist_max = max(Dist_max, DISTma);
        Dist_min = min(Dist_min, DISTma);
    }

    radius = Dist_min;
    diameter = Dist_max;

    for (int i = 0; i < G.size(); i++) {
        dist = BFSD(G, i);
        int DISTma = 0;
        for (int di : dist) {
            if (di != INT_MAX) {
                DISTma = max(DISTma, di);
            }
        }
        Dist_max = max(Dist_max, DISTma);
        Dist_min = min(Dist_min, DISTma);

        if (DISTma == radius) {
            cV.push_back(i);
        }
        if (DISTma == diameter) {
            pV.push_back(i);
        }
    }

    cout << "Радиус: " << radius << endl;
    cout << "Диаметр: " << diameter << endl;
    cout << "Центральные вершины: ";
    for (int v : cV) {
        cout << v + 1 << " ";
    }
    cout << endl << "Периферийные вершины: ";
    for (int v : pV) {
        cout << v + 1 << " ";
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

    int k = 0;

    vector<vector<int>> G(size, vector<int>(size, 0));

    if (graphType == "weighted" && orientation == "undirected") {
        G = createGNeOr(G);
        cout << "Матрица смежности неориентированного взвешенного графа:" << endl;
        k = 1;
    }
    else if (graphType == "weighted" && orientation == "directed") {
        G = createGOr(G);
        cout << "Матрица смежности ориентированного взвешенного графа:" << endl;
        k = 2;
    }
    else if (graphType == "unweighted" && orientation == "undirected") {
        G = createGNeOrU(G);
        cout << "Создание невзвешенного неориентированного графа:" << endl;
        k = 3;
    }
    else if (graphType == "unweighted" && orientation == "directed") {
        G = createGOrU(G);
        cout << "Создание невзвешенного ориентированного графа:" << endl;
        k = 4;
    }
    else {
        cout << "Некорректные параметры." << endl;
        k = 0;
        return 1;
    }

    printG(G);
    cout << endl << "Обход в ширину BFSD неор:" << endl;
    vector<int> DIST;
    for (int i = 0; i < G.size(); i++) {
        if (k==1 || k==2)
        {
            DIST = BFSD(G, i);  
        }
        else if (k==3 || k == 4){
            DIST = BFS(G, i);
        }
        cout << "От вершины " << i + 1 << ":" << endl;
        int maxDistance = -1;
        for (int j = 0; j < size; j++) {
            if (DIST[j] == 2147483647) DIST[j] = -1;
            cout << "До вершины " << j + 1 << " расстояние: " << DIST[j] << endl;
            if (DIST[j] != -1 && DIST[j] > maxDistance) {
                maxDistance = DIST[j];
            }
        }
        cout << "Эксцентриситет вершины " << i + 1 << ": " << maxDistance << endl;

    }
    findRDCvPv(G);

    return 0;
}
