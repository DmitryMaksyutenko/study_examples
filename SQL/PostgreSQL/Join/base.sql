/*
    A joined table is a table derived from two other (real or derived) tables
    according to the rules of the particular join type. Inner, outer, and
    cross-joins are available. The general syntax of a joined table is

        T1 join_type T2 [ join_condition  ]

    Joins of all types can be chained together, or nested: either or both T1 and T2
    can be joined tables. Parentheses can be used around JOIN clauses to control
    the join order. In the absence of parentheses, JOIN clauses nest left-to-right.

    PostgreSQL join is used to combine columns from one (self-join) or more tables
    based on the values of the common columns between the tables.
    The common columns are typically the primary key columns of the first table
    and foreign key columns of the second table.

    PostgreSQL supports:
            inner join,
            left join,
            right join,
            full outer join,
            cross join,
            natural join,
            and a special kind of join called self-join.
*/


-- Tables for examples.
CREATE TABLE basket_a (
    id INT PRIMARY KEY,
    fruit VARCHAR(100) NOT NULL
);


CREATE TABLE basket_b (
    id INT PRIMARY KEY,
    fruit VARCHAR(100) NOT NULL
);

INSERT INTO basket_a (id, fruit)
VALUES
    (1, 'Apple'),
    (2, 'Orange'),
    (3, 'Banana'),
    (4, 'Cucumber');

INSERT INTO basket_b (id, fruit)
VALUES
    (1, 'Orange'),
    (2, 'Apple'),
    (3, 'Watermelon'),
    (4, 'Pear');


DROP TABLE IF EXISTS basket_a;
DROP TABLE IF EXISTS basket_b;
