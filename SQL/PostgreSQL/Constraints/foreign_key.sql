/*
     A foreign key is a column or a group of columns in a table that reference the primary key of another table.

    The table that contains the foreign key is called the referencing table or child table.
    And the table referenced by the foreign key is called the referenced table or parent table.

    A table can have multiple foreign keys depending on its relationships with other tables.

    In PostgreSQL, define a foreign key use the foreign key constraint. The foreign key constraint helps maintain the referential integrity
    of data between the child and parent tables.

    A foreign key constraint indicates that values in a column or a group of columns in the child table equal the values in a column or
    a group of columns of the parent table.

        [CONSTRAINT fk_name]
           FOREIGN KEY(fk_columns) 
           REFERENCES parent_table(parent_key_columns)
           [ON DELETE delete_action]
           [ON UPDATE update_action]
*/


CREATE TABLE person (
    id SERIAL NOT NULL,
    name VARCHAR(30) NOT NULL,
    PRIMARY KEY(id)
);


CREATE TABLE shoes (
    id SERIAL NOT NULL,
    person_id INT,
    name VARCHAR(30),
    color VARCHAR(20),
    PRIMARY KEY(id),
    CONSTRAINT fk_person
        FOREIGN KEY (person_id)
            REFERENCES person (id)
);

INSERT INTO
    person
VALUES
    (default, 'Dan'),
    (default, 'Sam');


INSERT INTO
    shoes
VALUES
    (default, 1, 'Nike', 'red'),
    (default, 1, 'Classic', 'black'),
    (default, 2, 'Nike', 'white'),
    (default, 2, 'Slippers', 'green'),
    (default, 2, 'Classic', 'black'),
    (default, 1, 'Slippers', 'red'),
    (default, 1, 'Boots', 'black');


-- Error.
DELETE FROM
    person
WHERE id = 1;

ALTER TABLE
    shoes
DROP CONSTRAINT fk_person;

ALTER TABLE
    shoes
ADD CONSTRAINT fk_person
    FOREIGN KEY (person_id)
    REFERENCES person (id)
    ON DELETE SET NULL; -- or ON DELETE CASCADE


DROP TABLE IF EXISTS person;
DROP TABLE IF EXISTS shoes CASCADE;
