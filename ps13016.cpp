#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef pair<int, pair<int, int>> PII;
typedef pair<ll, pair<ll, ll>> PLL;
#define endl '\n'
#define INF 2e9
#define LINF 2e15
#define MOD 1000000007

int n, visit[50005], mdist, uv, vv;
vector<vector<PI>> v;

void dfs(int cur) {
    for (auto& i : v[cur]) {
        int next = i.first, ndist = i.second;
        if (!visit[next]) {
            visit[next] = visit[cur] + ndist;
            if (visit[next] > mdist) {
                mdist = visit[next];
                uv = next;
            }
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    v.resize(n + 1);
    for (int i = 0, p1, p2, p3; i < n - 1; i++) {
        cin >> p1 >> p2 >> p3;
        v[p1].push_back({p2, p3});
        v[p2].push_back({p1, p3});
    }
    dfs(1);
    memset(visit, 0, sizeof(visit));
    vv = uv;
    mdist = 0;
    dfs(vv);
    vector<int> vvisit;
    for (auto& i : visit) vvisit.push_back(i);
    memset(visit, 0, sizeof(visit));
    dfs(uv);
    for (int i = 1; i <= n; i++) cout << max(vvisit[i], visit[i]) << endl;
    return 0;
}
