#!/usr/bin/python3
"""
Reddis count
"""

import requests


def count_words(subreddit, word_list):
    """
    A recursive function that counts the number of times
    a word appears in a subreddit.

    :param subreddit: the subreddit to search
    :param word_list: a list of words to search for
    :return: A dictionary with the words as keys and the
    number of times they appear as values.
    """
    instances = {}
    after = ""
    count = 0

    return alt_count_words(subreddit, word_list, instances, after, count)


def alt_count_words(subreddit, word_list, instances={}, after="", count=0):
    """
    It takes a subreddit, a list of words, and a dictionary of words and their
    instances, and returns a
    dictionary of words and their instances

    :param subreddit: the subreddit to search
    :param word_list: list of words to search for
    :param instances: a dictionary that will hold the words and
    their respective counts
    :param after: the last post in the list
    :param count: the number of items that have been fetched so far, defaults
    to 0 (optional)
    :return: A dictionary with the words and the number of times they appear
    in the
            titles of the hot posts of a subreddit.
    """
    url = f"https://www.reddit.com/r/{subreddit}/hot/.json"
    headers = {"User-Agent": "test-python"}
    body = {"after": after, "count": count, "limit": 100}

    response = requests.get(
        url,
        headers=headers,
        params=body,
        allow_redirects=False)

    try:
        json_response = response.json()
        if response.status_code > 300:
            raise BaseException

    except BaseException:
        return

    json_response = json_response.get("data")
    after = json_response.get("after")
    count += json_response.get("dist")
    for child in json_response.get("children"):
        title = child.get("data").get("title").lower().split()
        for word in word_list:
            if word.lower() in title:
                total = len([total for total in title
                             if total == word.lower()])
                got_word = instances.get(word)
                instances[word] = total if got_word is None\
                    else instances[word] + total

    if after is None:
        if len(instances) == 0:
            print("")
            return
        code = []
        for item, value in instances.items():
            code.append((value, item))
        code.sort(reverse=True)
        for k in code:
            item, value = k[0], k[1]
            print(f"{value}: {item}")
    else:
        alt_count_words(subreddit, word_list, instances, after, count)
