#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long helper(vector<long long>& arr) {
    long long idx = n / 2;
    long long ans = arr[idx];

    for (long long i = idx; i + 1 < n; i++) {
        long long diff = arr[i + 1] - arr[i];
        long long len = i - idx + 1;

        long long cost = len * diff;

        if (cost <= k) {
            ans = arr[i + 1];
            k -= cost;
        }
        else {
            ans += k / len;
            return ans;   
        }
    }

    if (k > 0) {
        long long len = n - idx;
        ans += k / len;
    }

    return ans;
}

int main() {
    cin >> n >> k;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cout << helper(arr) << endl;

    return 0;
}