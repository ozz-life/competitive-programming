SELECT
    tweet_id
FROM
    Tweets
WHERE
    LENGTH(content) > 15;

---
SELECT
    tweet_id
FROM
    Tweets
WHERE
    content LIKE '________________%';

----
SELECT
    tweet_id
FROM
    tweets
WHERE
    length(regexp_replace(content, ' ', '')) > 15