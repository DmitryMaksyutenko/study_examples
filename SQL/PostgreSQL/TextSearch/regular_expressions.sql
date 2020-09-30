/*
    PATTERN MATCHING.

    There are three types of pattern matching in PostgreSQL:

        LIKE - described in ../Operators/like.sql.

        SIMILAR TO - operator returns true or false, depending on whether the provided string is matching to a pattern.
        Supports these pattern-matching metacharacters borrowed from POSIX regular expressions.

        POSIX regular expressions provide a more powerful means for pattern matching than the LIKE and SIMILAR TO operators.
            ~   Matches regular expression in case sensetive.
            ~*  Mathces regular expression in case insensetive.
            !~  Does not match regular expression in case sensetive.
            !~* Does not match regular expression in case insensetive.
*/

-- SIMILAR TO
SELECT 'some text string.' SIMILAR TO '%g.'; -- t
SELECT 'some text string.' SIMILAR TO '%text%'; -- t
SELECT 'some text string.' SIMILAR TO 'some'; -- f
SELECT 'somo text string.' SIMILAR TO 'som(e|_)%'; -- t
SELECT 'some text string.' SIMILAR TO '%(t?ext)%'; -- t
SELECT 'some correct text string.' SIMILAR TO '%cor{2}ect%';

-- The substring function with three parameters provides extraction of a substring that matches an SQL regular expression pattern.
-- substring(string, pattern, escape-character)
SELECT SUBSTRING('test strint', '%#"s_r#"%', '#'); -- returns 'srt'
SELECT SUBSTRING('test strint', '#"s_r#"%', '#'); -- NULL

SELECT
    d.film_id,
    d.title,
    d.description
FROM
    film AS d
WHERE
    d.description SIMILAR TO '%and%'; -- Returns 186 rows.


-- POSIX regular expressions.
SELECT 'some text correct string.' ~ 'xt'; -- t
SELECT 'some text correct string.' ~ '^xt'; -- f
SELECT 'some text correct string.' ~ '\w{4}\.'; -- t
SELECT 'some text correct string.' ~ '^[a-z]*[ ][a-z]*[ ][a-z]*rr[a-z]*[ ][a-z]*.$'; -- t
SELECT 'some text' ~ '[[:alpha:]]'; -- t
SELECT 'some 4 text' ~ '[[:alpha:]]'; -- t
SELECT '4' ~ '[[:alpha:]]'; -- f
