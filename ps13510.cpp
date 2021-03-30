#include<bits/stdc++.h>
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

const int MAX = 100005;
const int SIZE = 262144;

class SEG {
public:
    int seg[SIZE], val;
    function<int(int, int)> func;

    SEG(int val_, function<int(int, int)> func_) :val(val_), func(func_) {
        fill(seg, seg + SIZE, val);
    }
    SEG() :SEG(0, [](int a, int b) {return a + b; }) {}
    void init() {
        for (int i = SIZE / 2 - 1; i > 0; i--)
            seg[i] = func(seg[i * 2], seg[i * 2 + 1]);
    }
    void update(int idx, int val) {
        idx += SIZE / 2;
        seg[idx] = val;
        while (idx > 1) {
            idx /= 2;
            seg[idx] = func(seg[idx * 2], seg[idx * 2 + 1]);
        }
    }
    int query(int lo, int hi, int node, int x, int y) {
        if (hi <= x || lo >= y)return val;
        if (lo <= x && y <= hi)return seg[node];
        int mid = (x + y) >> 1;
        return func(query(lo, hi, node * 2, x, mid), query(lo, hi, node * 2 + 1, mid, y));
    }
};

class HLD {
public :
    void init() {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int p1, p2, p3;
            cin >> p1 >> p2 >> p3;
            --p1, --p2;
            adj[p1].push_back({ p2,{p3,i} });
            adj[p2].push_back({ p1,{p3,i} });
        }
        dfs(0);
        c = dcnt = 0;
        memset(head, -1, sizeof(head));
        memset(tail, -1, sizeof(tail));
        parent[0] = -1;
        decomposition(0);
        seg = SEG(-INF, [](int a, int b) { return max(a, b); });
        for (int cur = 0; cur < n; cur++) {
            int U = dfsn[cur];
            for (auto& i : adj[cur]) {
                int next = i.first;
                int d = i.second.first;
                int en = i.second.second;
                int V = dfsn[next];
                if (depth[U] < depth[V]) {
                    v[en] = V;
                    seg.seg[SIZE / 2 + V] = d;
                }
            }
        }
        seg.init();
    }
    void update(int e, int k) {
        seg.update(v[e], k);
    }
    int getMax(int u, int v) {
        int result = -INF;
        u = dfsn[u];
        v = dfsn[v];
        if (group[u] != group[v]) {
            while (1) {
                int uhead = head[group[u]], vhead = head[group[v]];
                if (depth[uhead] > depth[vhead]) {
                    result = max(seg.query(uhead, u + 1, 1, 0, SIZE / 2), result);
                    u = parent[uhead];
                }
                else {
                    result = max(seg.query(vhead, v + 1, 1, 0, SIZE / 2), result);
                    v = parent[vhead];
                }
                if (group[u] == group[v])break;
            }
        }
        result = max(seg.query(min(u, v) + 1, max(u, v) + 1, 1, 0, SIZE / 2), result);
        return result;
    }
private:
    int n, c, dcnt;
    int Size[MAX], dfsn[MAX];
    vector<PII> adj[MAX];
    vector<int> child[MAX];
    int parent[MAX], depth[MAX], group[MAX];
    int v[MAX];
    int head[MAX], tail[MAX];
    SEG seg;
    void dfs(int cur, int pre = -1) {
        Size[cur] = 1;
        for (auto& i : adj[cur]) {
            int next = i.first;
            int d = i.second.first;
            int en = i.second.second;
            if (next != pre) {
                dfs(next, cur);
                child[cur].push_back(next);
                Size[cur] += Size[next];
            }
        }
    }
    void decomposition(int cur, int pre = -1, int curdepth = 0) {
        int u = dfsn[cur] = dcnt++;
        group[u] = c;
        depth[u] = curdepth;
        if (head[c] < 0)head[c] = u;
        tail[c] = u;
        if (child[cur].empty()) {
            ++c;
            return;
        }
        int chain = child[cur][0];
        for (int i = 1; i < child[cur].size(); i++) {
            int next = child[cur][i];
            if (Size[chain] < Size[next])chain = next;
        }
        decomposition(chain, cur, curdepth + 1);
        parent[dfsn[chain]] = u;
        for (int i : child[cur]) {
            if (i != chain)decomposition(i, cur, curdepth + 1);
            int v = dfsn[i];
            parent[v] = u;
        }
    }
};

int q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    HLD hld;
    hld.init();
    cin >> q;
    while (q--) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        if (p1 == 1)hld.update(p2, p3);
        else cout << hld.getMax(p2 - 1, p3 - 1) << endl;
    }
    return 0;
}
