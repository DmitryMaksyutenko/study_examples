/*
    The TIME data type allows to store the time of the day.

        time [ (p) ] without time zone,  8 bytes, 00:00:00 to 24:00:00 DEFAULT.
        time [ (p) ] with time zone, 12 bytes, 00:00:00+1559 to 24:00:00-1559.

            p - is the precision with max 6 digits.

        formats:
            HH:MM
            HH:MM:SS
            HHMMSS

            with precision:
            MM:SS.pppppp
            HH:MM:SS.pppppp
            HHMMSS.pppppp
*/
SELECT CURRENT_TIME;
SELECT CURRENT_TIME(3);
SELECT LOCALTIME;
SELECT LOCALTIME(0);
SELECT LOCALTIME AT TIME ZONE 'Asia/Hong_Kong';

CREATE TABLE time_test (
    cur_time TIME WITH TIME ZONE DEFAULT CURRENT_TIME,
    end_point TIME WITH TIME ZONE NOT NULL
);

INSERT INTO
    time_test
VALUES
    (default, NOW() + '24:00:00');

INSERT INTO
    time_test
VALUES
    (default, NOW() + '12:00:00');


DROP TABLE IF EXISTS time_test;
