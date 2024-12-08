//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//#include <climits>
//
//using namespace std;
//
//vector<vector<int>> createGNeOr(vector<vector<int>> G) {
//	for (int i = 0; i < G.size(); i++) {
//		for (int j = 0; j < G.size(); j++) {
//			if (rand() % 2) {
//				G[i][j] = rand() % 9 + 1;
//				G[j][i] = G[i][j];
//			}
//			if (i == j) G[i][j] = 0;
//
//		}
//	}
//	return G;
//}
//
//vector<vector<int>> createGOr(vector<vector<int>> G) {
//	for (int i = 0; i < G.size(); i++) {
//		for (int j = 0; j < G.size(); j++) {
//			if (rand() % 2) {
//				G[i][j] = rand() % 9 + 1;
//			}
//			if (i == j) G[i][j] = 0;
//
//		}
//	}
//	return G;
//}
//
//void printG(vector<vector<int>>& G) {
//	for (int i = 0; i < G.size(); i++) {
//		for (int val : G[i]) {
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//}
//
//vector<int> BFSD(vector<vector<int>> G, int v) {
//	vector<int> DIST(G.size(), INT_MAX);
//	queue<int> Q;
//
//	Q.push(v);
//	DIST[v] = 0;
//
//	while (!Q.empty()) {
//		v = Q.front();
//		Q.pop();
//
//		for (int i = 0; i < G.size(); ++i) {
//			if (G[v][i] > 0 && DIST[v] + G[v][i] < DIST[i]) {
//				Q.push(i);
//				DIST[i] = DIST[v] + G[v][i];
//			}
//		}
//	}
//	return DIST;
//}
//
//void findRDCvPv(vector<vector<int>>& G) {
//	vector<int>dist(G.size());
//	vector<int> cV;
//	vector<int> pV;
//
//	int radius = INT_MAX;
//	int diameter = 0;
//
//	int Dist_min = INT_MAX;
//	int Dist_max = 0;
//
//	for (int i = 0; i < G.size(); i++) {
//		dist = BFSD(G, i);
//		int DISTma = 0;
//		for (int di : dist) {
//			if (di != INT_MAX) {
//				DISTma = max(DISTma, di);
//			}
//		}
//		Dist_max = max(Dist_max, DISTma);
//		Dist_min = min(Dist_min, DISTma);
//	}
//
//	radius = Dist_min;
//	diameter = Dist_max;
//
//	for (int i = 0; i < G.size(); i++) {
//		dist = BFSD(G, i);
//		int DISTma = 0;
//		for (int di : dist) {
//			if (di != INT_MAX) {
//				DISTma = max(DISTma, di);
//			}
//		}
//		Dist_max = max(Dist_max, DISTma);
//		Dist_min = min(Dist_min, DISTma);
//
//		if (DISTma == radius) {
//			cV.push_back(i);
//		}
//		if (DISTma == diameter) {
//			pV.push_back(i);
//		}
//	}
//
//	cout << "Радиус: " << radius << endl;
//	cout << "Диаметр: " << diameter << endl;
//	cout << "Центральные вершины: ";
//	for (int v : cV) {
//		cout << v + 1 << " ";
//	}
//	cout << endl << "Периферийные вершины: ";
//	for (int v : pV) {
//		cout << v + 1 << " ";
//	}
//}
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int size = 0;
//	cout << "Введите количество вершин графа: ";
//	cin >> size;
//
//	vector<vector<int>> G(size, vector<int>(size, 0));
//	G = createGNeOr(G);
//	cout << "Матрица смежности неориентированного взвешенного графа:" << endl;
//	printG(G);
//	findRDCvPv(G);
//
//	vector<vector<int>> Gor(size, vector<int>(size, 0));
//	Gor = createGOr(Gor);
//	cout << endl << "Матрица смежности ориентированного взвешенного графа:" << endl;
//	printG(Gor);
//	findRDCvPv(Gor);
//}