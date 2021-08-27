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

string str;
double ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> str;
    if (str == "F")
        cout << "0.0" << endl;
    else {
        ans += (4 - (str[0] - 'A'));
        if (str[1] == '+')
            ans += 0.3;
        else if (str[1] == '-')
            ans -= 0.3;
        cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}
