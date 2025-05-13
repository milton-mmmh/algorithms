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

void clearAndResize(vector<auto>&vec_, Long size_) {
    vec_.clear();
    vec_.resize(size_);
}

struct NumberTheory {
    vector<bool> isPrime;
    vector<Long> primes, coprimeCount, divisorCount, divisorSum, smallestPrimeFactor;
    vector<vector<pair<Long, Long> > >allPrimeFactors;
    Long primeCount;

    void init(Long nodeCount) {
        clearAndResize(coprimeCount, nodeCount + 5);
        clearAndResize(divisorCount, nodeCount + 5);
        clearAndResize(divisorSum, nodeCount + 5);
        clearAndResize(allPrimeFactors, nodeCount + 5);
    }

    void generatePrimes(Long primeLimit) {
        isPrime.resize(primeLimit + 1, true);
        smallestPrimeFactor.resize(primeLimit + 1, 1);
        primes.clear();
        primes.push_back(1);
        for(Long i = 2; i <= primeLimit; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
                smallestPrimeFactor[i] = i;
                primeCount++;
                for(Long j = 2 * i; j <= primeLimit; j += i) {
                    if(isPrime[j]) {
                        isPrime[j] = false;
                        smallestPrimeFactor[j] = i;
                    }
                }
            }
        }
    }

    pair<Long, Long> removeThisPrime(Long num, Long factor) {
        Long cnt;
        cnt = 0;
        while(num % factor == 0) {
            cnt++;
            num /= factor;
        }
        return {num, cnt};
    }

    void findBasicProperties(Long num) {
        init(num + 1);
        for(Long i = 2; i <= num; i++) {
            pair<Long, Long>val = removeThisPrime(i, smallestPrimeFactor[i]);
            if(val.first == 1) {
                coprimeCount[i] = i - (i / smallestPrimeFactor[i]);
                divisorCount[i] = val.second + 1;
                divisorSum[i] = ((i * smallestPrimeFactor[i]) - 1) / (smallestPrimeFactor[i] - 1);
                allPrimeFactors[i].push_back(make_pair(smallestPrimeFactor[i], val.second));
            } else {
                coprimeCount[i] = coprimeCount[val.first] * coprimeCount[i / val.first];
                divisorCount[i] = divisorCount[val.first] * divisorCount[i / val.first];
                divisorSum[i] = divisorSum[val.first] * divisorSum[i / val.first];
                allPrimeFactors[i] = allPrimeFactors[val.first];
                allPrimeFactors[i].push_back(make_pair(smallestPrimeFactor[i], val.second));
            }
            sort(allPrimeFactors.begin(), allPrimeFactors.end());
        }
    }
};

NumberTheory numTheory;

void solveTestCase(Long testCase) {
    Long i, j, k, l, n, m, a, b, t, ans, cnt, val, num, sum, total, totalNode, Node, pos, minPos, maxPos, minVal, maxVal, cntCo, cntDiv, sumDiv;

    cin >> n;

    numTheory.generatePrimes(n);
    numTheory.findBasicProperties(n);
    vector<vector<pair<Long, Long> > >vec1;
    vec1.resize(n + 5);

    for(i = 2; i <= n; i++) {
        cout << "Basic Properties for number " << i << " : " << endl;

        cntCo = 1;
        cntDiv = 1;
        sumDiv = 1;

        for(j = 2; j <= i; j++) {
            if(__gcd(i, j) == 1) {
                cntCo++;
            }

            if(i % j == 0) {
                cntDiv++;

                sumDiv += j;

                k = i;

                cnt = 0;

                while(k % j == 0) {
                    cnt++;
                    k /= j;
                }

                vec1[j].push_back(make_pair(i, cnt));
            }
        }

        cout << "Coprime Counts " << numTheory.coprimeCount[i] << " Divisor Counts " << numTheory.divisorCount[i] << " Sum of Divisors " << numTheory.divisorSum[i] << endl;

        /// testing if the code calculating properties correctly

        assert(numTheory.coprimeCount[i] == cntCo);
        assert(numTheory.divisorCount[i] == cntDiv);
        assert(numTheory.divisorSum[i] == sumDiv);
    }
    cout << "All test case ran perfectly\n";
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

