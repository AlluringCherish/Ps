#include <bits/stdc++.h>
#define X first
#define Y second


using namespace std;


int n, k; 
int visited[100001];
queue <int> Q;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> k;
	
	for (int i=0; i<100001; i++){
		visited[i]=-1;
	}
	
	visited[n]=0;
	Q.push(n);
	
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		
		int x1 = cur + 1, x2 = cur - 1, x3 = 2*cur;
		if (x1 >= 0 && x1 <= 100000 && visited[x1]==-1){
			Q.push(x1);
			visited[x1]=visited[cur]+1;
		}
		if (x2 >= 0 && x2 <= 100000 && visited[x2]==-1){
			Q.push(x2);
			visited[x2]=visited[cur]+1;
		}
		
		
		if (x3 >= 0 && x3 <= 100000 && visited[x3]==-1){
			Q.push(x3);
			visited[x3]=visited[cur]+1;
		}
		
		
		
	}
	
	
	
	cout << visited[k];
	
	

	
}