/*
    The TIMESTAMP datatype allows to store both date and time. However, it does not have any time zone data.
    It means that when change the timezone of database server, the timestamp value stored in the database will not change automatically.

    The TIMESTAMPTZ datatype is the timestamp with the time zone. The timestamptz datatype is a time zone-aware date and time data type.


    PostgreSQL stores the timestamptz in UTC value. (Universal Coordinated Time)

        When insert a value into a TIMESTAMPTZ column, PostgreSQL converts the TIMESTAMPTZ value into a UTC value and stores the UTC value in the table.

        When query TIMESTAMPTZ from the database, PostgreSQL converts the UTC value back to the time value of the timezone set by the database server,
        the user, or the current database connection.

    Notice that both timestamp and timestamptz uses 8 bytes for storing the timestamp values.
*/

-- TYMESTAM size.
SELECT
      typname,
      typlen
FROM
      pg_type
WHERE
      typname ~ '^timestamp';

-- Test table creation.
CREATE TABLE event(
    event_id SERIAL PRIMARY KEY NOT NULL,
    event_name VARCHAR(100) NOT NULL,
    day_1 TIMESTAMP NOT NULL,
    day_2 TIMESTAMP,
    day_3 TIMESTAMPTZ
);


SET TIMEZONE = 'America/Los_Angeles';
SHOW TIMEZONE;

INSERT INTO
    event
VALUES
    (default, 'New Year.', '2020-12-31', '2021-01-01', '2021-01-02');

INSERT INTO
    event
VALUES
    (default, 'Big event', '2020-10-09 12:00:00', '2020-10-09 12:00:00'::TIMESTAMP + '1 day'::INTERVAL, NULL);

INSERT INTO
    event
VALUES
    (default, 'Fest', NOW(), NOW(), NOW());

SET TIMEZONE = 'Europe/Kiev';

DROP TABLE IF EXISTS event;
