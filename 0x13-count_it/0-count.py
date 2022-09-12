#!/usr/bin/python3
"""
Recursive function that queries the Reddit API, parses the title of all
hot articles,and prints a sorted count of given keywords
(case-insensitive, delimited by spaces. Javascript should count as javascript,
but java should not).
"""

import requests


def sort_and_print_dict(word_count):
    """
    Sort the dictionary by value, then by key, then print
    the key and value
    """
    sorted_dict = dict(sorted(
        word_count.items(),
        key=lambda argument: (argument[1], argument[0]),
        reverse=True
    ))
    for key, value in sorted_dict.items():
        if value > 0:
            print(f"{key}: {value}")


def make_request(subreddit, after):
    """
    It makes a request to the Reddit API for the hot posts in
    a given subreddit, and returns the response
    """

    url = f"https://api.reddit.com/r/{subreddit}/hot"
    headers = {'user-agent': 'counting-app'}
    params = {'limit': 100, 'after': after}
    return requests.get(
        url,
        headers=headers,
        params=params, allow_redirects=False
    )


def count_words(subreddit, word_list, word_count={}, after=""):
    """Recursive function to count a subreddit words"""
    if len(word_count) == 0:
        for word in word_list:
            word_count[word.lower()] = 0
    if after is None:
        sort_and_print_dict(word_count)
        return None
    response = make_request(subreddit, after)
    if response.status_code != 200:
        return None
    after = response.json()['data']['after']
    children = response.json()['data']['children']
    for child_object in children:
        title_string_split = child_object['data']['title'].lower().split(" ")
        for word in word_list:
            word_count[word.lower()] += title_string_split.count(
                word.lower())
    count_words(subreddit, word_list, word_count, after)
