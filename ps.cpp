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

string str;
int cnt[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++)cnt[str[i] - 'a']++;
	for (int i = 0; i <= 25; i++)cout << cnt[i] << ' ';
	cout << endl;
	return 0;
}
