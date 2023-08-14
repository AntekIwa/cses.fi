#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k; cin >> n >> k;
	vector<int> array(n);
	for(int i = 0; i < n; i++) cin >> array[i];
	sort(array.begin(), array.end());
	int l = 0;
	int r = n - 1;
	int res = n;
	while(l < r){
		if(array[r] + array[l] <= k){
			res--;
			l++;
			r--;
		}
		else r--;
	}
	cout << res;
}
