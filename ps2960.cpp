#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

vector<int> v;
bool prime[10001];
int n, m, ans, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(prime + 2, 1, sizeof(prime));
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (prime[j]) {
				prime[j] = false;
				cnt++;
				if (cnt == m) {
					cout << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
