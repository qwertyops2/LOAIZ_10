//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <ctime>
//#include <cstdlib>
//#include <windows.h>
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
//
//	int startVertex;
//	cout << "Введите начальную вершину (1 - " << size << "): ";
//	cin >> startVertex;
//
//	vector<int> DIST_NeOr(size, INT_MAX);
//	cout << endl << "Обход в ширину BFSD неор:" << endl;
//	DIST_NeOr = BFSD(G, startVertex-1);
//	cout << endl;
//	for (int i = 0; i < size; i++) {
//		if (DIST_NeOr[i] == 2147483647) DIST_NeOr[i] = -1;
//		cout << "До вершины " << i + 1 << " расстояние: " << DIST_NeOr[i] << endl;
//	}
//
//	vector<vector<int>> Gor(size, vector<int>(size, 0));
//	Gor = createGOr(Gor);
//	cout << endl << "Матрица смежности ориентированного взвешенного графа:" << endl;
//	printG(Gor);
//
//	vector<int> DIST_Or(size, INT_MAX);
//	cout << endl << "Обход в ширину BFSD ор:" << endl;
//	DIST_Or = BFSD(Gor, startVertex - 1);
//	cout << endl;
//	for (int i = 0; i < size; i++) {
//		if (DIST_Or[i] == 2147483647) DIST_Or[i] = -1;
//		cout << "До вершины " << i + 1 << " расстояние: " << DIST_Or[i] << endl;
//	}
//}