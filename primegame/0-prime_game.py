#!/usr/bin/python3
"""Prime Game module."""


def isWinner(x, nums):
    """Return the player name with the most wins after x rounds.

    In each round with value n, the winner is determined by the parity of the
    number of primes <= n:
    - odd  -> Maria wins
    - even -> Ben wins
    """
    if not x or not nums or x < 1:
        return None

    rounds = nums[:x]
    if not rounds:
        return None

    max_n = max(rounds)
    if max_n < 2:
        return "Ben"

    # Sieve of Eratosthenes to mark primes up to max_n.
    is_prime = [True] * (max_n + 1)
    is_prime[0] = False
    is_prime[1] = False

    p = 2
    while p * p <= max_n:
        if is_prime[p]:
            multiple = p * p
            while multiple <= max_n:
                is_prime[multiple] = False
                multiple += p
        p += 1

    # prime_count[i] = number of primes <= i
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(max_n + 1):
        if is_prime[i]:
            count += 1
        prime_count[i] = count

    maria_wins = 0
    ben_wins = 0

    for n in rounds:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
