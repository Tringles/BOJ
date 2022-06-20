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

int tc, p1, p2, visited[105], ind[105];
set<int> s;
vector<vector<int>> v;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (true) {
        tc++;
        bool ans = true;
        s.clear();
        memset(visited, 0, sizeof(visited));
        memset(ind, 0, sizeof(ind));
        v.resize(100);
        cin >> p1 >> p2;
        if (p1 == -1 && p2 == -1) break;
        while (p1 && p2) {
            s.insert(p1);
            s.insert(p2);
            v[p1].push_back(p2);
            ind[p2]++;
            cin >> p1 >> p2;
        }
        for (auto i : s) {
            if (!ind[i]) {
                q.push(i);
                break;
            }
        }
        while (!q.empty()) {
            if (!ans) break;
            int cur = q.front();
            q.pop();
            for (auto i : v[cur]) {
                if (visited[i]) {
                    ans = false;
                    break;
                }
                visited[i] = true;
                q.push(i);
            }
        }
        if (ans)
            cout << "Case " << tc << " is a tree." << endl;
        else
            cout << "Case " << tc << " is not a tree." << endl;
    }
    return 0;
}