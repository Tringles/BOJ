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

int n, alp[26], det[26], ans;
string given, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> given;
    n--;
    for (auto i : given) alp[i - 'A']++;
    while (n--) {
        int sum = 0;
        memset(det, 0, sizeof(det));
        cin >> s;
        for (auto i : s) det[i - 'A']++;
        if (abs((int)given.size() - (int)s.size()) > 1) continue;
        for (int i = 0; i < 26; i++) sum += abs(alp[i] - det[i]);
        if (sum <= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}
