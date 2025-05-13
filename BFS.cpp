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

void clearAndResize(vector<auto>&vec_, Long size_) {
    vec_.clear();
    vec_.resize(size_);
}

struct BfsGraph {
    queue<Long>nodeQueue;
    vector<vector<Long> >adjList, components;
    vector<Long>nodeColor, nodeDist, nodeParent;

    void initGraph(Long nodeCount) {
        clearAndResize(adjList, nodeCount + 5);
        clearAndResize(components, nodeCount + 5);
        clearAndResize(nodeColor, nodeCount + 5);
        clearAndResize(nodeDist, nodeCount + 5);
        clearAndResize(nodeParent, nodeCount + 5);
        while(!nodeQueue.empty()) {
            nodeQueue.pop();
        }
    }

    void addEdge(Long from, Long to) {
        adjList[from].push_back(to);
    }

    void addBiEdge(Long from, Long to) {
        addEdge(from, to);
        addEdge(to, from);
    }

    void pushNodeIntoQueue(Long node, Long parent, Long color) {
        nodeQueue.push(node);
        nodeColor[node] = color;
        nodeParent[node] = parent;
        nodeDist[node] = nodeDist[parent] + 1;
        components[color].push_back(node);
    }

    void findPath(Long from, Long to, vector<Long>&path) {
        Long c = to;
        while(c != from) {
            path.push_back(c);
            c = nodeParent[c];
        }
        path.push_back(from);
        reverse(path.begin(), path.end());
    }

    void bfs(const vector<Long>&sources, Long currentColor) {
        Long i, j, x, p;
        for(i = 0; i < sources.size(); i++) {
            pushNodeIntoQueue(sources[i], 0, currentColor);
        }
        while(!nodeQueue.empty()) {
            p = nodeQueue.front();
            nodeQueue.pop();
            for(j = 0; j < adjList[p].size(); j++) {
                x = adjList[p][j];
                if(nodeColor[x] == 0) {
                    pushNodeIntoQueue(x, p, nodeColor[p]);
                }
            }
        }
    }
};

BfsGraph bfsClass;

void doBeforeEachBFS(Long nodes) {
    clearAndResize(bfsClass.components, nodes);
    clearAndResize(bfsClass.nodeColor, nodes);
    clearAndResize(bfsClass.nodeDist, nodes);
}

void solveTestCase(Long testCase) {
    Long i, j, k, l, n, m, a, b, from, to;

    cin >> n;

    bfsClass.initGraph(n);

    for(i = 1; i <= n; i++) {
        cin >> a >> b;
        bfsClass.addBiEdge(a, b);
    }

    cin >> m;

    for(i = 1; i <= m; i++) {
        vec1.clear();

        doBeforeEachBFS(n);

        cin >> from >> to;

        bfsClass.bfs({from}, from);

        bfsClass.findPath(from, to, vec1);

        for(j = 0; j < vec1.size(); j++) {
            cout << vec1[j] << " ";
        }
        cout << endl;
    }
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
