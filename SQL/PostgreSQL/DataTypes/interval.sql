/*
    The INTERVAL data type allows store and manipulates a time period of years, montgs, days, hours, minutes, seconds atc.

        interval [ fields ] [ (p) ]

            16 bytes.
            -178000000 years Low value.
            178000000 years High value.

    Interval values can be written using the following verbose syntax:

        [@] quantity unit [quantity unit...] [direction]

        where quantity is a number (possibly signed);

        unit is microsecond, millisecond, second, minute, hour, day, week, month, year, decade, century, millennium,
        or abbreviations or plurals of these units;

        direction can be ago or empty.

    Internally, PostgreSQL stores interval values as months, days, and seconds.
    The months and days values are integers while the seconds field can have fractions.

    The interval values are very useful when doing date or time arithmetic.
*/

SELECT INTERVAL '1 year 2 months 3 days 5 hours 30 minutes 33 seconds';
SELECT INTERVAL '1 year 5 3:45:03';
SELECT INTERVAL '1 months 5 3:45:03';
SELECT INTERVAL '5 3:45:03';
SELECT INTERVAL '5 3:45:03 ago';
SELECT INTERVAL '5 3:45:03 - 3 days';

-- Arithmetic.
SELECT
    NOW(),
    NOW() - INTERVAL '3 12:00:00' AS result;

SELECT
    NOW(),
    NOW() + INTERVAL '3 12:00:00' AS result;

SELECT 60 * INTERVAL '1 second';

SELECT 60 * INTERVAL '1 millisecond';

SELECT TO_CHAR(INTERVAL '19 year 12 month 4 03:32:00.03',
                        'YYYY-MM-DD HH:MM:SS::MS');

SELECT EXTRACT(MONTH FROM INTERVAL '1 year 3 month');

SELECT JUSTIFY_DAYS(INTERVAL '44 days 3:33:33');

SELECT JUSTIFY_HOURS(INTERVAL '144 hours 13 minutes');

SELECT JUSTIFY_INTERVAL(INTERVAL '144 hours 13 minutes - 1 day');
