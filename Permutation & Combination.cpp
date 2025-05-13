#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

#define Long long long
#define MAX 1LL<<60
#define MAX_LENGTH 500000
#define MOD7 1000000007
#define MOD9 1000000009

using namespace std;
using namespace __gnu_pbds;

vector<Long>vec1;
Long ar[MAX_LENGTH + 9];

Long nCr(Long n, Long r) {
    Long nCrNumerator, nCrDenumerator, gcdVal;
    if(n < r)return 0;
    if(n == r)return 1;
    if(n - r < r) {
        r = n - r;
    }
    nCrNumerator = 1;
    nCrDenumerator = 1;
    while(r > 0) {
        nCrNumerator *= n;
        nCrDenumerator *= r;
        gcdVal = __gcd(nCrNumerator, nCrDenumerator);
        nCrNumerator /= gcdVal;
        nCrDenumerator /= gcdVal;
        n--;
        r--;
    }
    return nCrNumerator;
}

Long nPr(Long n, Long r) {
    Long nPrVal = 1;
    while(r--) {
        nPrVal *= n--;
    }
    return nPrVal;
}

Long Factorial(Long n) {
    Long ans = 1;
    for(Long i = 2; i <= n; i++) {
        ans *= i;
        //factorial[i]=ans;
    }
    return ans;
}

void solveTestCase(Long testCase) {
    Long i, j, k, l, n, m, a, b, t, r, ans, cnt, val, num, sum, total, totalNode, Node, pos, minPos, maxPos, minVal, maxVal;
    cin >> n >> r;
    cout << "Combination " << nCr(n, r) << " Permutation " << nPr(n, r) <<" Factorial "<<Factorial(n)<<" Factorial "<<Factorial(r)<< endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    Long testCase, testCaseCount;
    cin >> testCaseCount;
    for(testCase = 1; testCase <= testCaseCount; testCase++) {
        solveTestCase(testCase);
    }
    return 0;
}
