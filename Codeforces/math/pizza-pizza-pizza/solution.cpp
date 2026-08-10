#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long a;
	cin >> a;
	
	if(a == 0) {
	    cout << a << endl;
	    return 0;
	}
	
	if((a + 1) % 2 == 0)
	    cout << (a + 1) / 2 << endl;
	else if(a != 0)
	    cout << (a + 1) << endl;
 
    return 0;
}