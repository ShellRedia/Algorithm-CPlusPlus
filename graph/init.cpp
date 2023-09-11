#include <iostream>
#include <vector>

using namespace std;

struct TreeDiameter{
    const static int N = 50010;
    int n, diameter = 0;
    int d1[N], d2[N];
    vector<pair<int, int>> (&E)[N];

    void dfs(int u, int fa) {
        d1[u] = d2[u] = 0;
        for (auto p : E[u]) {
            int v = p.first, w = p.second;
            if (v == fa) continue;
            dfs(v, u);
            int t = d1[v] + w;
            if (t > d1[u]) d2[u] = d1[u], d1[u] = t;
            else if (t > d2[u]) d2[u] = t;
        }
        diameter = max(diameter, d1[u] + d2[u]);
    }

    TreeDiameter(int n, vector<pair<int, int>> (&edges)[N]):n(n), E(edges){
        dfs(1, 0);
    }
};

int main() {
    int n, m;
    const int N = 50010;
    vector<pair<int, int>> E[N];
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        E[u].push_back({v, w}), E[v].push_back({u, w});
    }
    auto td = TreeDiameter(n, E);

    printf("%d\n", td.diameter);
    return 0;
}