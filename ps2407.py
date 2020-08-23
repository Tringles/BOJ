import sys
input=sys.stdin.readline

n,m=map(int,input().split())
ans=1
div=1
for i in range(0,m):
    ans*=(n-i)
    div*=(m-i)
print(ans//div)
