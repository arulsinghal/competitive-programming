/**
 * Problem: Equal Audience Love / Disjoint Triads
 * Platform: Codeforces
 * Key Concept: Prefix Frequency Map (unordered_map) + Offset Filtering
 * 
 * Logic Summary:
 * - Triads at x and y overlap if y - x == 2 or y - x == 4.
 * - Triads are disjoint if y - x >= 5, y - x == 1, or y - x == 3.
 * - Use unordered_map to store triads >= 5 steps behind y for O(1) lookups.
 */

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long love[n];
    for(int i = 0; i < n; i++){
        cin >> love[i];
    }

    vector<long long> total;
    long long x = 0;
    while(x + 4 < n){
        long long calc = love[x] + love[x+2] - love[x+4];
        total.push_back(calc);
        x++;
    }

    long long answer = 0;
    int m = total.size();
    unordered_map<long long, long long> mp;

    for(int y = 0; y < m; y++){
        // Triad at (y - 5) is safe to put in frequency map
        if(y - 5 >= 0){
            mp[total[y - 5]]++;
        }

        // Count safe matching triads
        answer += mp[total[y]];

        // Check x = y - 1 offset (disjoint)
        if(y - 1 >= 0 && total[y - 1] == total[y]){
            answer++;
        }

        // Check x = y - 3 offset (disjoint)
        if(y - 3 >= 0 && total[y - 3] == total[y]){
            answer++;
        }
    }

    cout << answer << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
