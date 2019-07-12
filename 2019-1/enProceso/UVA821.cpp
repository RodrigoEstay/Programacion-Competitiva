#include <bits/stdc++.h>

using namespace std;

void BFSRec(int** graph, int start, int it, int* visited, int origin){
	vector<int> nodesVisited;
	for(int i=0 ; i<100 ; ++i){
		if(!graph[start][i] || visited[i]) continue;
		visited[i] = 1;
		nodesVisited.push_back(i);
		graph[origin][i] = it;
	}
	for(int i=0 ; i<nodesVisited.size() ; ++i){
		BFSRec(graph, nodesVisited[i], it+1, visited, sum);
	}
}

void BFS(int** graph, int start){
	int sum = 0;
	int *visited = new int[100]();
	visited[start] = 1;
	BFSRec(graph, start, 1, visited, &sum, start);
	return sum;
}

int main(){
	int a, b, sum, cases, combinations;
	int ** graph;
	graph = new int*[100];
	map<int,int> pages;
	cases = 1;
	while(1){
		for(int i=0 ; i<100 ; ++i){
			graph[i] = new int[100]();
		}
		while(1){
			cin >> a >> b;
			if(!a && !b) break;
			graph[a-1][b-1] = 1;
			pages[a] = 1;
			pages[b] = 1;
		}
		if(!pages.size()) break;
		for(int i=0 ; i<100 ; ++i){
			BFS(graph, i);
		}
		sum = 0;
		
		printf("Case %d: average length between pages = %.3f clicks\n", cases, ((float)sum)/combinations);
		for(int i=0 ; i<100 ; ++i){
			delete[] graph[i];
		}
		pages.clear();
		cases++;
	}
	for(int i=0 ; i<100 ; ++i){
		delete[] graph[i];
	}
	delete[] graph;
	return 0;
}