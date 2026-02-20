#!/usr/bin/python3
"""
0-count
Recursive function that queries the Reddit API, parses the titles of all hot
articles, and prints a sorted count of given keywords (case-insensitive).
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Count occurrences of words from word_list in the hot titles of subreddit.

    - subreddit: subreddit name (str)
    - word_list: list of keywords (list of str)
    This function is recursive and prints results when all pages are processed.
    """
    # Initialize counts and multipliers on first call
    if counts is None:
        # Map lowercase keyword -> count
        counts = {}
        for w in word_list:
            key = w.lower()
            counts.setdefault(key, 0)
        # Count how many times each keyword appears in the input list
        # (duplicates should be summed into final result)
        count_multipliers = {}
        for w in word_list:
            count_multipliers[w.lower()] = count_multipliers.get(w.lower(), 0) + 1
    else:
        # Recreate multipliers from provided word_list each recursive call
        count_multipliers = {}
        for w in word_list:
            count_multipliers[w.lower()] = count_multipliers.get(w.lower(), 0) + 1

    # Reddit API request
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    params = {"limit": 100}
    if after:
        params["after"] = after
    headers = {"User-Agent": "holberton-script"}

    try:
        r = requests.get(url, headers=headers, params=params, allow_redirects=False, timeout=10)
    except requests.RequestException:
        return

    if r.status_code != 200:
        # Invalid subreddit or redirect; per requirements print nothing
        return

    data = r.json().get("data", {})
    children = data.get("children", [])

    for child in children:
        title = child.get("data", {}).get("title", "")
        # Split by whitespace; per spec punctuation attached to words should not match
        tokens = title.split()
        for token in tokens:
            t = token.lower()
            if t in counts:
                counts[t] += 1

    after = data.get("after", None)

    if after:
        # Recursive call to get next page
        return count_words(subreddit, word_list, after=after, counts=counts)

    # Base case: no more pages, prepare and print results
    # Apply multipliers from duplicates in word_list
    final = {}
    for key, c in counts.items():
        total = c * count_multipliers.get(key, 1)
        if total > 0:
            final[key] = total

    if not final:
        return

    # Sort by count descending, then alphabetically ascending
    for word, cnt in sorted(final.items(), key=lambda x: (-x[1], x[0])):
        print("{}: {}".format(word, cnt))


if __name__ == "__main__":
    # Example usage (not used by main test harness)
    pass
