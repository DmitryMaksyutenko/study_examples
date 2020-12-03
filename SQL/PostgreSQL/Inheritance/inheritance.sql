/*
    Inheritance allows a table to inherit some of its column attributes from one or more other tables,
    creating a parent-child relationship. This causes the child table to have each of the same columns
    and constraints as its inherited table (or tables), as well as its own defined columns.

    When performing a query on an inherited table, the query can be instructed to retrieve either all
    rows of a table and its descendants, or just the rows in the parent table itself.
    The child table, on the other hand, will never return rows from its parent.
*/

CREATE TABLE person (
    person_id INT,
    first_name VARCHAR(20),
    last_name VARCHAR(20)
);


CREATE TABLE student (
    student_group CHAR(2)
) INHERITS (person);


-- Insert only in to the person.
INSERT INTO person
VALUES
    (1, 'Peter', 'Johnson');


-- Insert into to student.
INSERT INTO student
VALUES
    (1, 'Sam', 'Ras', 'A1');

-- Failed insertion.
INSERT INTO person
VALUES
    (2, 'Nik', 'Groob', 'A1');

-- Data retrieving.
SELECT * FROM person;
SELECT * FROM ONLY person;
SELECT * FROM student;


DROP TABLE IF EXISTS student;
DROP TABLE IF EXISTS person;
