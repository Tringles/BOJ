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

int n;
double m;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> m;
        getline(cin, str);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '@')
                m *= 3.0;
            else if (str[i] == '%')
                m += 5.0;
            else if (str[i] == '#')
                m -= 7.0;
        }
        cout << fixed << setprecision(2) << m << endl;
    }
    return 0;
}
