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

struct NonNegativeIntegerUtil {

    string integerToString(Long number) {
        assert(number >= 0);
        return to_string(number);
    }

    vector<Long> integerToVector(Long number) {
        assert(number >= 0);
        string tempStr = integerToString(number);
        vector<Long>tempVec(tempStr.size());
        for(int i = 0; i < tempStr.size(); i++) {
            tempVec[i] = tempStr[i] - '0';
        }
        return tempVec;
    }
};

NonNegativeIntegerUtil integerUtil;
Long keepBitCount[MAX_LENGTH + 9];
string keepNumberString[MAX_LENGTH + 9];
string aa, ss, dd;
vector<Long> vec1;

void solveTestCase(Long testCase) {
    Long i, j, k, l, n, m, a, b, t, ans, cnt, val, num, sum, total, totalNode, Node, pos, minPos, maxPos, maxAns, maxBit, maxNum;
    aa.clear();
    vec1.clear();
    cin>>aa;
    cin>>n;
    cout<<"so the string of number n is "<<integerUtil.integerToString(n)<<endl;
    vec1 = integerUtil.integerToVector(n);
    cout<<"so the vector of number n is : "<<endl;
    for(i=0;i<vec1.size();i++){
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    Long i, testCase, testCaseCount;
    cin >> testCaseCount;
    for(testCase = 1; testCase <= testCaseCount; testCase++) {
        solveTestCase(testCase);
    }
    return 0;
}
