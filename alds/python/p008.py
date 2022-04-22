
n = int(input())
s = input()

T = "atcorder"

mod = 10**9+ 7

dp = [ [0]*(len(T)+1) for _ in range(n + 1)]

for i in range(n + 1):
    dp[i][0] = 1

for i in range (n):
    for j in range (len(T)):
        m 
        if s[i] == T[i]:
            m = dp[i][j] + dp[i][j + 1]
        else:
            m = dp[i][j + 1]
        m %= mod
        dp[i + 1][j + 1] = m

print (dp[n][len(T)])
        
            
 

