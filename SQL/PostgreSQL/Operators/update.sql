/*
    For changing values in columns of the table using the UPDATE statement.
*/

UPDATE store
SET
    last_update = NOW()
WHERE
    store_id = 1;
