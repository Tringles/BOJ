import sys
input=sys.stdin.readline

dp=[0 for i in range(255)]
dp[0]=1
dp[1]=1
dp[2]=3
for i in range(3,251):
    dp[i]=2*dp[i-2]+dp[i-1]
for n in sys.stdin:
    print(dp[int(n)])