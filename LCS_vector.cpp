// LCS for a vector see https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

typedef vector<int> Myvec;

Myvec longestCommonSubsequence(Myvec X, Myvec Y) 
{
    Myvec result;
    int last_x, last_y;

    size_t n = X.size();
    size_t m = Y.size();

	if (n == 0 || m == 0) return result;       // dummy

    // copy last number
    last_x = X[n - 1];
    last_y = Y[m - 1];
    
	if (last_x == last_y)
    {
		X.pop_back(); Y.pop_back();
        result = longestCommonSubsequence(X, Y);
        result.push_back(last_x);
        return result;
    }

	X.pop_back();
	Myvec v1 = longestCommonSubsequence(X, Y);

	X.push_back(last_x);
	Y.pop_back();
	Myvec v2 = longestCommonSubsequence(X, Y);

	size_t len1 = v1.size();
	size_t len2 = v2.size();

	if (len1 > len2)
		return v1;
	else
		return v2;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}
