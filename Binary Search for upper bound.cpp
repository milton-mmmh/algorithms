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



///tested with CODEFORCES 474B



///for finding the first one or upper bound :::

Long func1(Long mid) {
    return prefixSum[mid] >= globalVal;
}

Long binarySearchGetFirstOne(Long low, Long high, Long(*binarySearchCheck)(Long)) {
    while(high - low > 1) {
        Long mid = high - (high - low) / 2;
        if(binarySearchCheck(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    if(binarySearchCheck(low)) {
        return low;
    } else {
        return high;
    }
}

/// for finding prefix sum of an array i.e from sum from index 0 to n

void findPrefixSum(Long n) {
    Long i;
    prefixSum[0] = 0;
    for(i = 1; i <= n; i++) {
        prefixSum[i] = ar[i] + prefixSum[i - 1];
    }
}

void solveTestCase(Long testCase) {
    Long i, j, k, l, m, a, b, t, ans, cnt, sum, total, totalNode, Node, pos, minPos, maxPos, n;

    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    findPrefixSum(n);

    cin >> m;

    for(i = 1; i <= m; i++) {
        cin >> a;

        globalVal = a;

        minPos = binarySearchGetFirstOne(1, n, &func1);

        cout << minPos << endl;
    }
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
