#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define endl '\n'
#define INF 2e9
#define LINF 2e11
#define MOD 1000000007

int n, dp[10000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
    cout << dp[n] << endl;
    return 0;
}
