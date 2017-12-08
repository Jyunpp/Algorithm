//20171208 
//다익스트라 복습
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define sd(x) scanf(" %d", &x);
#define slld(x) scanf(" %lld", &x);
#define sc(x) scanf(" %c", &x);
#define ll long long
#define xx first
#define yy second

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <functional>
using namespace std;
const int MAX_V = 20000;
const int INF = 987654321;
typedef pair<int, int> P;

int main() {
	int V, E, K;
	vector<P> adj[MAX_V + 1]; // adj[i][j] : i정점-> j정점의 거리.
	sd(V); sd(E); sd(K);
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		sd(u); sd(v); sd(w);
		adj[u].push_back(P(v, w));
	}
	int dist[MAX_V + 1];
	fill(dist, dist + MAX_V + 1, INF);
	bool visited[MAX_V + 1] = { false };
	priority_queue<P, vector<P>, greater<P> > PQ;
	
	//다익스트라
	dist[K] = 0;
	PQ.push(P(0, K));
	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().yy;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);

		if (visited[curr]) break;

		visited[curr] = true;
		for (auto &i : adj[curr]) {
			int next = i.xx;
			int d = i.yy;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	system("pause");
	return 0;
}