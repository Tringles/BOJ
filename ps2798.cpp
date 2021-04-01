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

int n, m, b[105];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> m;
    ans = m;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == j|| j ==k || i == k)continue;
                if(ans > (m - (b[i] + b[j] + b[k])) && (m - (b[i] + b[j] + b[k]) >= 0)){
                    ans = m - (b[i] + b[j] + b[k]);
                }
            }
        }
    }
    cout << m - ans << endl;
    return 0;
}
