#!/usr/bin/python3
"""
Minimum coins needed to make change.
"""


def makeChange(coins, total):
    """Return the fewest number of coins to reach *total*.

    coins is a list of positive integer denominations.  We assume an infinite
    supply of each coin.  If *total* is less than or equal to zero, 0 is
    returned.  When no combination of coins can produce the desired total,
    -1 is returned.

    The implementation uses a bottom-up dynamic programming approach with a
    one-dimensional table of length total + 1; dp[t] will hold the minimum
    coins needed to make amount *t*.
    """

    if total <= 0:
        return 0

    # initialize dp array with a value larger than any possible coin count
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for t in range(1, total + 1):
        for c in coins:
            if c <= t:
                if dp[t - c] + 1 < dp[t]:
                    dp[t] = dp[t - c] + 1

    return dp[total] if dp[total] != total + 1 else -1
