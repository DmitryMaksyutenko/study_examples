/*
    The DATE data type is used for storing the date only.

    It can store values in a range from 4713 BC to 5874897 AD.

    The storing format is yyyy-mm-dd "2000-12-31".

    When creates the table with the DATE column data type, it's possible to assign the default value
    with CURRENT_DATE after the DEFAULT keyword to that column.
*/


CREATE TABLE person (
    person_id SERIAL PRIMARY KEY NOT NULL,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    birthday DATE NOT NULL,
    insertion_day DATE NOT NULL DEFAULT CURRENT_DATE,
    hire_date DATE
);

-- Insert default values.
INSERT INTO
    person
VALUES
    (default, 'Name1', 'Surname1', '1988-04-20', default, '2010-05-25'),
    (default, 'Name2', 'Surname2', '1996-01-20', default, '2016-03-07'),
    (default, 'Name3', 'Surname3', '1983-02-18', default, '2000-05-23'),
    (default, 'Name4', 'Surname4', '1986-06-16', default, '2003-11-11'),
    (default, 'Name5', 'Surname5', '1992-07-16', default, '2010-02-03'),
    (default, 'Name6', 'Surname6', '2007-04-13', default, NULL),
    (default, 'Name7', 'Surname7', '2016-01-16', default, NULL);

-- Insert person in table with current day.
INSERT INTO
    person
VALUES
    (default, 'Name8', 'Surname8', '1990-01-10', default, CURRENT_DATE);

-- Outputting date value in a specific format.
SELECT
    first_name,
    last_name,
    TO_CHAR(birthday, 'yyyy/mm/dd') AS birthday
FROM
    person;

-- Get the age of a person.
SELECT
    first_name,
    last_name,
    AGE(birthday) AS age
FROM
    person;

-- Getting the difference in age between the persons.
SELECT
    a.first_name,
    a.last_name,
    MAKE_INTERVAL(days => ABS(a.birthday - b.birthday)) AS difference,
    b.first_name,
    b.last_name
FROM
    person AS a JOIN person AS b
    ON
        a.person_id <> b.person_id;


DROP TABLE IF EXISTS person;
