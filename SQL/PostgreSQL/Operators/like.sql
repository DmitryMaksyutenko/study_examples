/*
    string LIKE pattern [ESCAPE escape-character]
    string NOT LIKE pattern [ESCAPE escape-character]

    The LIKE expression returns true if the string matches the supplied pattern.
    (As expected, the NOT LIKE expression returns false if LIKE returns true, and vice versa.
    An equivalent expression is NOT (string LIKE pattern).)

    If pattern does not contain percent signs or underscores, then the pattern only represents
    the string itself; in that case LIKE acts like the equals operator. An underscore (_) in
    pattern stands for (matches) any single character; a percent sign (%) matches any sequence
    of zero or more characters.

    Percent ( % ) for matching any sequence of characters.
    Underscore ( _ ) for matching any single character.

    'abc' LIKE 'abc'    true
    'abc' LIKE 'a%'     true
    'abc' LIKE '_b_'    true
    'abc' LIKE 'c'      false
*/

SELECT
    'foo' LIKE 'foo' AS one,
    'foo' LIKE 'f%' AS two,
    'foo' LIKE '_o_' AS three,
    'bar' LIKE 'b_' AS four;

SELECT
    first_name,
    last_name
FROM
    actor
WHERE
    first_name LIKE 'A%';
