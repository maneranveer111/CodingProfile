#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    int best = 0, cur = 0;
    for(int i = 0; i < 2*n; i++){
        if(a[i % n] == 1){
            cur++;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    cout << min(best, n) << endl;
}