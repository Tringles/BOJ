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

ll n,m[100005],ans,sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
        sum+=m[i];
    }
    for(int i=0;i<n-1;i++){
        sum-=m[i];
        ans+=sum*m[i];
    }
    cout<<ans<<endl;
    return 0;
}