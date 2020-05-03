/*
  The INTERSECT operator combines the result set of two or more
  queries into a single result set. Returns any rows that are aveilable
  in both result set or returned by both queries.

  The number of columns and their order must be the same in all queries.
  The data types of the columns must be compatable.
*/

CREATE TABLE employees (
  employee_id SERIAL PRIMARY KEY,
  employee_name VARCHAR(30) NOT NULL
);

CREATE TABLE keys (
  employee_id INT PRIMARY KEY,
  effective_date DATE NOT NULL,
  FOREIGN KEY (employee_id) REFERENCES employees (employee_id)
);

CREATE TABLE hipos (
  employee_id INT PRIMARY KEY,
  effective_date DATE NOT NULL,
  FOREIGN KEY (employee_id) REFERENCES employees (employee_id)
);

INSERT INTO employees (employee_name)
VALUES
  ('name 1'),
  ('name 2'),
  ('name 3'),
  ('name 4'),
  ('name 5'),
  ('name 6'),
  ('name 7'),
  ('name 8'),
  ('name 9'),
  ('name 10'),
  ('name 11'),
  ('name 12'),
  ('name 13'),
  ('name 14'),
  ('name 15'),
  ('name 16'),
  ('name 17');

INSERT INTO keys 
VALUES
  (1, '2020-01-01'),
  (2, '2020-01-01'),
  (3, '2020-01-01'),
  (4, '2020-01-01'),
  (5, '2020-01-01'),
  (6, '2020-01-01'),
  (7, '2020-01-01'),
  (8, '2020-01-01'),
  (9, '2020-01-01');

INSERT INTO hipos
VALUES
  (1, '2020-03-01'),
  (12, '2020-02-01'),
  (13, '2020-05-01'),
  (14, '2020-11-01'),
  (15, '2020-11-01'),
  (6, '2020-10-01'),
  (17, '2020-02-01'),
  (8, '2020-03-01'),
  (9, '2020-04-01');

SELECT
	employee_id
FROM
	keys
INTERSECT
SELECT
	employee_id
FROM
	hipos;

SELECT
	employee_id
FROM
	keys
INTERSECT
SELECT
	employee_id
FROM
	hipos
ORDER BY
  employee_id;

DROP TABLE keys;
DROP TABLE hipos;
DROP TABLE employees;
