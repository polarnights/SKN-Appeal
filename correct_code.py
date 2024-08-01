n, a = list(map(int, input().split()))


dp = [0] * (n + 1)
dp[1] = 1
dp[0] = 1

# 1 1 1 1 1
for i in range(2, len(dp)):
    # dp[i] = 1
    for j in range(1, min(i, a) + 1):
        if i - j < 0:
            break

        dp[i] += dp[i - j]

print(dp[n])