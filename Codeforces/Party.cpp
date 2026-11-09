/**
 * Problem: Party
 * Platform: Codeforces
 * Key Concept: Ordered graph and dfs
 * Link: https://codeforces.com/problemset/problem/115/A
 * 
 * Logic Summary:
 * - make a vector for "roots", ie, top bosses.
 * - make a dfs function that inputs height of node and a node.
 * - height starts at 1 and does recursive behaviour as we go deeper in the graph.
 * - update maximum height as we recurse.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> g;
long long maxi = 0;

void dfs(long long v, long long depth) {
    maxi = max(maxi, depth);
    for (long long u : g[v]) {
        dfs(u, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    
    g.resize(n + 1);
    vector<long long> roots;
    
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        if (x == -1) {
            roots.push_back(i); // Root node (no manager)
        } else {
            g[x].push_back(i);  // Edge from manager (x) to employee (i)
        }
    }
    
    for (long long root : roots) {
        dfs(root, 1);
    }
    
    cout << maxi << "\n";
    
    return 0;
}
