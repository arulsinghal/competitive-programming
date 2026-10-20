/*	
problem name: polycarp's practice
Link: https://codeforces.com/problemset/problem/1006/B
Topic: greedy, sorting
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    vector<pair<long long, long long>>v;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        v.push_back({x,i});
    }
    sort(v.begin(),v.end());
    long long sum = 0;
    for(long long i = k; i > 0;i--){
        sum+=v[n-i].first;
    }
    cout << sum << "\n";
    vector<long long>final(k);
    for(int i = 0; i < k; i++){
        final[i] = v[n-i-1].second;
    }
    sort(final.begin(), final.end());
    long long pointer = 0;
    for(int i = k; i > 1; i--){
        cout << final[k-i] - pointer + 1 << " ";
        pointer = final[k-i] + 1;
    }
    cout << n - pointer << "\n";
	return 0;
	
	
    
}
