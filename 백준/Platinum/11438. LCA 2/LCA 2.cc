#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
vector<int> mp[100001];
int parent[18][100001];
int depth[100001];


void dfs(int x, int d, int p) {
	depth[x] = d;
	parent[0][x] = p;
	for (int i : mp[x]) {
		if (p == i) {
			continue;
		}

		dfs(i, d + 1, x);


	}

}


int solve(int a, int b) {
	int ha = depth[a], hb = depth[b];
	if (ha < hb) {
		swap(a, b);
	} // h[a]>h[b] 만들기

	//높이 맞추기
	for (int i = 17; i >= 0; i--) {
		if (depth[a]-depth[b] >= (1 << i)) {
			a = parent[i][a];
		}
	}

	if (a == b) {
		return a;
	}

	for (int i = 17; i >= 0; i--) {
		if (parent[i][a] == parent[i][b]) {
			continue;

		}
		else {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
		
	}

	
	dfs(1, 0, 0);
	// parent 배열 채우기
	
	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
	/*
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j <17; j++) {
			cout << i << " " << j << " " << parent[j][i] << "\n";
		}
	}*/

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << solve(a, b) << "\n";
	}

	return 0;
	
}