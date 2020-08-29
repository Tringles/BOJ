#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int a, b, defcycle;
ll dist[555];
vector<vector<pair<int, int>>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    v.resize(a + 1);
    for (int i = 0; i < b; i++) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        v[p1].push_back({ p2,p3 });
    }
    fill(dist + 1, dist + 555, LINF);
    dist[1] = 0;
    for (int i = 1; i <= a; i++) {
        for (int cur = 1; cur <= a; cur++) {
            for (auto& o : v[cur]) {
                int next = o.first, n_dist = o.second;
                if (dist[cur] != LINF) {
                    if (dist[next] > dist[cur] + n_dist) {
                        dist[next] = dist[cur] + n_dist;
                        if (i == a) {
                            defcycle = true;
                        }
                    }
                }
            }
        }
    }
    if (defcycle) {
        cout << -1 << endl;
    }
    else {
        for (int i = 2; i <= a; i++) {
            if (dist[i] == LINF) {
                cout << -1 << endl;
            }
            else {
                cout << dist[i] << endl;
            }
        }
    }
    return 0;
}
