#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

string str;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c[1001];
		int cnt = 0;
		for (int j = i; j < str.size(); j++) c[cnt++] = str[j];
		c[cnt] = '\0';
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	for (auto& i : v)cout << i << endl;
	return 0;
}