#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int MAX_N = 1e6 + 7;
vector<int> tree[MAX_N];
vector<int> treeSize(MAX_N);
vector<bool> vist(MAX_N);
int n;
void subtree(int v){
	vist[v] = true;
	for(int u : tree[v]){
		if(!vist[u]){
			subtree(u);	
			treeSize[v] += treeSize[u];
		}
	}
	treeSize[v]++;
}

int findCentroid(int v){
	vist[v] = true;
	int maxx = 0, maxnode;
	for(int u : tree[v]){
		if(vist[u]) continue;
		if(maxx < treeSize[u]){
			maxx = treeSize[u];
			maxnode = u;
		}
	}
	if(maxx <= n/2) return v;
	else return findCentroid(maxnode);
}
int main(){
//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a,b; cin >> a >> b;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	subtree(1);
	vist.assign(n+1,0);
	cout << findCentroid(1);
	return 0;
}
