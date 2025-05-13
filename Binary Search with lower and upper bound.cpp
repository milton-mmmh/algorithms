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

///tested with CODEFORCES 2032C


///gives the first index that is equal or smaller than the given value
Long getLastIndexWithSmallerThan(Long x, const vector<Long>& tempVec) {
    return lower_bound(tempVec.begin(), tempVec.end(), x) - tempVec.begin();
}

///gives the last index that is greater than the given value
Long getFirstIndexWithGreaterThan(Long x, const vector<Long>& tempVec) {
    return upper_bound(tempVec.begin(), tempVec.end(), x) - tempVec.begin();
}

///gives the first index that is equal or smaller than the given value within range
Long getLastIndexWithSmallerValueBetweenIndices(const vector<Long>& tempVec, Long searchValue, Long leftIndex, Long rightIndex) {
    return lower_bound(tempVec.begin() + leftIndex, tempVec.begin() + rightIndex, searchValue) - tempVec.begin();
}

void solveTestCase(Long testCase) {
    Long i, j, k, l, n, m, a, b, t, ans, cnt, val, type, num, sum, total, totalNode, Node, pos, minPos, maxPos,pos1,pos2,pos3,ans1,ans2,ans3;
    cin >> n;
    vec1.clear();
    vec1.resize(n);
    for(i = 0; i < n; i++) {
        cin >> vec1[i];
    }
    sort(vec1.begin(), vec1.end());
    ans = MAX;
    for(i = 0; i < n - 1; i++) {
        sum = vec1[i] + vec1[i + 1];

        pos1 = getLastIndexWithSmallerThan(sum,vec1);
        ans1 = min(ans, i + n - pos1);

        pos2 = getFirstIndexWithGreaterThan(sum-1,vec1);
        ans2 = min(ans, i + n - pos2);

        pos3 = getLastIndexWithSmallerValueBetweenIndices(vec1,sum,i,n);
        ans3 = min(ans, i + n - pos3);

        assert(ans1==ans2);
        assert(ans2==ans3);
    }

    cout<<"ALL TESTS RAN PERFECTLY"<<endl;
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
