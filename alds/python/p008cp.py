
# 入力の受け取り

N = int(input())
S = input()

# 今回はatcoderをTとする
T = "atcoder"

# 余りのための変数
mod = 10**9+7

#0文字からN文字まで考えるので、"+1個"配列を定義
dp = [[0]*(len(T)+1) for _ in range(N+1)]

# j=0の時、全て1を代入
for i in range(N+1):
  dp[i][0] = 1

# S[i]がT[j]に等しいかで場合分け
# dpのiとS[i]で示すiが1ズレている点に注意（jも同様）
# 答えをmodで割った余りを格納
for i in range(N):
  for j in range(len(T)):
    if S[i] == T[j]:
      dp[i+1][j+1] = dp[i][j] + dp[i][j+1]
      dp[i+1][j+1] %= mod
    else:
      dp[i+1][j+1] = dp[i][j+1]
      dp[i+1][j+1] %= mod

# N文字まで使って、Tになる時の通り数を出力
print(dp[N][len(T)])
