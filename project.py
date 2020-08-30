import sys
input=sys.stdin.readline

dp=[0 for i in range(69)]
dp[0]=dp[1]=1
dp[2]=2
dp[3]=4
for i in range(4,68):
    dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]

n=int(input())
while n:
    m=int(input())
    print(dp[m])
    n-=1