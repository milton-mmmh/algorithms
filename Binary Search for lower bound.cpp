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

vector<Long>q;
Long ar[MAX_LENGTH + 9], br[MAX_LENGTH + 9], prefixSum[MAX_LENGTH + 9];
Long globalVal;


/// tested with CODEFORCES 279B

///for finding the last zero or lower bound of a number :::


Long func(Long mid) {
    return prefixSum[mid] > globalVal;
}

Long binarySearchGetLastZero(Long low, Long high, Long(*binarySearchCheck)(Long)) {
    while(high - low > 1) {
        Long mid = high - (high - low) / 2;
        if(!binarySearchCheck(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    if(!binarySearchCheck(high)) {
        return high;
    } else {
        return low;
    }
}

/// For finding prefix sum of an array :::

void findPrefixSum(Long n) {
    Long i;
    prefixSum[0] = 0;
    for(i = 1; i <= n; i++) {
        prefixSum[i] = ar[i] + prefixSum[i - 1];
    }
}

void solveTestCase(Long testCase) {
    Long i, j, k, l, r, n, m, ans, cnt, sum, maxPos;

    cin >> n >> m;

    for(i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    findPrefixSum(n);

    sort(ar + 1, ar + n + 1);

    ans = 0;

    if(m < ar[1]) {
        cout << "0" << endl;
        return;
    }

    for(i = 1; i <= n; i++) {
        globalVal = m + prefixSum[i - 1];

        maxPos = binarySearchGetLastZero(i, n, &func);

        ans = max(ans, maxPos - i + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    Long testCase, testCaseCount;
    testCaseCount = 1;
    for(testCase = 1; testCase <= testCaseCount; testCase++) {
        solveTestCase(testCase);
    }
    return 0;
}
