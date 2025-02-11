#include <iostream>
#include <vector>
#include <queue>




using namespace std;
int edges[501][501];
int visitedDFS[501][501];
long long dist[501];
vector <int> path[501];
int visited[501];
int n, m;
int s,e;





void dijk(){
	for (int i=0; i<n; i++){
		dist[i]=1e9;
		visited[i]=0;
	}
	
	dist[s]=0;
	
	for (int i=0; i<n-1; i++){ // n-1번만 하면 된다. 
		int minIndex = -1;
		long long minValue = 1e9;
		
		for (int j=0; j<n; j++){
			if (visited[j]==1){
				continue;
			}
			
			if (dist[j] < minValue){
				
				minIndex = j;
				minValue = dist[j];
			}
		}
		
		visited[minIndex] = 1;
		
		for (int j=0; j<n; j++){
			if (visited[j]==1){
				continue;
			}
			
			if (edges[minIndex][j]>0){
				if(dist[j] >= dist[minIndex]+edges[minIndex][j]){
					if (dist[j] != dist[minIndex]+edges[minIndex][j]){
						path[j].clear();
					}
					dist[j] = dist[minIndex]+edges[minIndex][j];
					path[j].push_back(minIndex);
				}
			}
		}
		
		
	}
	/*
	for (int i=0; i<n; i++) {
		cout << dist[i] << " ";
	}
	
	for (int i=0; i<n; i++){
		cout << "path " << i << " "; 
		for (int e : path[i]){
			cout << e << " ";
		}
		cout << "\n";
	}
	*/
}

void modifydijk(){
	for (int i=0; i<n; i++){
		dist[i]=1e9;
		visited[i]=0;
	}
	
	dist[s]=0;
	
	for (int i=0; i<n-1; i++){ // n-1번만 하면 된다. 
		int minIndex = -1;
		long long minValue = 1e9;
		
		for (int j=0; j<n; j++){
			if (visited[j]==1){
				continue;
			}
			
			if (dist[j] < minValue){
				
				minIndex = j;
				minValue = dist[j];
			}
		}
		
		visited[minIndex] = 1;
		
		for (int j=0; j<n; j++){
			if (visited[j]==1){
				continue;
			}
			
			if (edges[minIndex][j]>0){
				if(dist[j] > dist[minIndex]+edges[minIndex][j]){
					dist[j] = dist[minIndex]+edges[minIndex][j];
				}
			}
		}
		
		
	}
	/*
	for (int i=0; i<n; i++) {
		cout << dist[i] << " ";
	}
	
	for (int i=0; i<n; i++){
		cout << "path " << i << " "; 
		for (int e : path[i]){
			cout << e << " ";
		}
		cout << "\n";
	}
	*/
}


void dfs(int v){

	
	if (v==s){
		return;
	}
	
	else{
		for (int temp : path[v]){
			if (!visitedDFS[v][temp]){
				visitedDFS[v][temp]=1;
				edges[temp][v]=0; // edge 삭제
				dfs(temp);
			}
			
		}
	}
	
	
	
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		cin >> n >> m;
		if (n==0){
			return 0;
		}
		cin >> s >> e;
	
	
	
		for (int i=0; i<n; i++){
			
			path[i].clear();
		}
		
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				edges[i][j]=0;
				visitedDFS[i][j]=0;
			}
		}
		
	
		for (int i=0; i<m; i++){
			int a,b,c;
			cin >> a >> b >> c;
			edges[a][b]=c;
		}
		
		/*
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				cout << i << " " << j << " " << edges[i][j] << "\n";
			}
		}
		*/
		dijk();
		
		
		dfs(e);
		
		dijk();
		
		
		if (dist[e]==1e9){
			cout << "-1" << "\n";
		}
		else{
			cout << dist[e] << "\n";
		}

		
	}
	
	
	
	return 0;
}