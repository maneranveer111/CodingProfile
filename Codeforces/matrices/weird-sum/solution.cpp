#include <bits/stdc++.h>
using namespace std;

long long sumAbsDiffPairs(vector<int> a) {
    sort(a.begin(), a.end());
    long long sum = 0, prefix = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        sum += (long long)a[i] * i - prefix;
        prefix += a[i];
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> xs, ys;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            xs[a].push_back(i);
            ys[a].push_back(j);
        }
    }

    long long ans = 0;
    for (auto &[key, vec] : xs) {
        ans += sumAbsDiffPairs(vec);
    }
    for (auto &[key, vec] : ys) {
        ans += sumAbsDiffPairs(vec);
    }

    cout << ans << endl;
    return 0;
}