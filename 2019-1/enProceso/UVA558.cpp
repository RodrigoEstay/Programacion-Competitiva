#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<pair<int,int> > > graph, int *visited, int *parent, int start, int* minSum){
	int current, sum, aux;
	stack<int> ancestors;
	bool foundCycle;
	for(int i=0 ; i<graph[start].size() ; ++i){
		while(!ancestors.empty()){
			ancestors.pop();
		}
		if(visited[graph[start][i].first]){
			foundCycle = false;
			current = parent[start];
			while(current != -1){
				ancestors.push(current);
				if(current == graph[start][i].first){
					foundCycle = true;
					break;
				}
				current = parent[current];
			}
			if(foundCycle){
				sum = 0;
				current = ancestors.top();
				ancestors.pop();
				while(!ancestors.empty()){
					for(int j=0 ; j<graph[current].size() ; ++j){
						if(graph[current][j].first == ancestors.top()){
							aux = graph[current][j].second;
							break;
						}
					}
					sum += aux;
					current = ancestors.top();
					ancestors.pop();
				}
				for(int j=0 ; j<graph[current].size() ; ++j){
					if(graph[current][j].first == start){
						aux = graph[current][j].second;
						break;
					}
				}
				sum += aux;
				sum += graph[start][i].second;
				if(sum < *minSum) *minSum = sum;
			}
		}
		else{
			visited[graph[start][i].first] = 1;
			parent[graph[start][i].first] = start;
			DFS(graph, visited, parent, graph[start][i].first, minSum);
		}
	}
}

int minCycleSum(vector<vector<pair<int,int> > > graph){
	int *visited = new int[graph.size()]();
	int *parent = new int[graph.size()]();
	int minSum = INT_MAX;
	visited[0] = 1;
	parent[0] = -1;
	DFS(graph, visited, parent, 0, &minSum);
	delete[] visited;
	delete[] parent;
	visited = new int[graph.size()]();
	parent = new int[graph.size()]();
	visited[graph.size()-1] = 1;
	parent[graph.size()-1] = -1;
	DFS(graph, visited, parent, graph.size()-1, &minSum);
	delete[] visited;
	delete[] parent;
	return minSum;
}

int main(){
	int c, n, m, x, y, t, minSum;
	vector<vector<pair<int,int> > > graph;
	cin >> c;
	while(c--){
		cin >> n >> m;
		graph.resize(n);
		while(m--){
			cin >> x >> y >> t;
			graph[x].push_back(make_pair(y,t));
		}
		minSum = minCycleSum(graph);
		if(minSum < 0) cout << "possible\n";
		else cout << "not possible\n";
		for(int i=0 ; i<graph.size() ; ++i){
			graph[i].clear();
		}
		graph.clear();
	}
	return 0;
}