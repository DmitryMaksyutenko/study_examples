/*
    PostgreSQL provides the INSERT statement that allows to insert one or more rows into a table at a time.

    INSERT INTO table_name
        (column1, column2, …)
    VALUES
        (value1, value2, …);
*/

CREATE TABLE IF NOT EXISTS sessions (
    session_key VARCHAR(40) NOT NULL,
    session_data TEXT NOT NULL,
    expire_date TIMESTAMP WITH TIME ZONE NOT NULL
);

DROP TABLE IF EXISTS sessions;


-- Simple insertion.
INSERT INTO sessions
VALUES (
    'testsessionkey1',
    'some not incrypted data.',
    NOW() + '1 day'
);


-- Insert with the list columns explicitly.
INSERT INTO sessions
    (session_key,
     session_data,
     expire_date)
VALUES (
    'sessionkey3',
    'some new data.',
    NOW() + '1 day'
);

-- Insert with the list columns in random order.
INSERT INTO sessions
    (session_data,
     session_key,
     expire_date)
VALUES (
    'some session data.',
    'newkey',
    NOW() + '1 day'
);

-- Multiple row insertion.
INSERT INTO sessions
VALUES (
    'key1',
    'data 111111',
    NOW() + '1 DAY'
),
(
    'key2',
    'data 222222',
    NOW() + '1 DAY'
),
(
    'key3',
    'data 333333',
    NOW() + '1 DAY'
);
