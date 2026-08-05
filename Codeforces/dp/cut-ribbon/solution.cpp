#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = INT_MIN / 2;

int a, b, c;
vector<int> memo;
// vector<bool> visited;

int helper(int n) {
    if (n == 0) 
        return 0;         
    if (n < 0) 
        return NEG_INF;    

    if (memo[n] != -1)
        return memo[n];


    int best = NEG_INF;

    if (a <= n) {
        int r = helper(n - a);
        if (r != NEG_INF)
            best = max(best, 1 + r);
    }
    if (b <= n) {
        int r = helper(n - b);
        if (r != NEG_INF)
            best = max(best, 1 + r);
    }
    if (c <= n) {
        int r = helper(n - c);
        if (r != NEG_INF)
            best = max(best, 1 + r);
    }

    memo[n] = best;
    return best;
}

int main() {
    int n;
    cin >> n >> a >> b >> c;

    memo.assign(n + 1, -1);
    
    int result = helper(n);

    if (result == NEG_INF)
        cout << -1 << endl;   
    else
        cout << result << endl;

    return 0;
}