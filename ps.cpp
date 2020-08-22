#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, m, sep[42], fib[41], ans = 1, s;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	fib[1] = 1, fib[2] = 2;
	for (int i = 3; i <= n; i++)fib[i] = fib[i - 1] + fib[i - 2];
	sep[0] = 0, sep[m + 1] = n + 1;
	for (int i = 1; i <= m; i++)cin >> sep[i];
	for (int i = 1; i <= m + 1; i++)v.push_back(sep[i] - sep[i - 1] - 1);
	for (auto& i : v) {
		if (!i)continue;
		ans *= fib[i];
	}
	cout << ans << endl;
	return 0;
}