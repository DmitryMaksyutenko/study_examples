/*
  DROP INDEX [ CONCURRENTLY ]
  [ IF EXISTS ] index_name
  [ CASCADE | RESTRICT ];

  IF EXISTS - avoids an error.
  CASCADE - automatically drops the depandent objects.
  RESTRICT - refuses tho trop the index if any object depend on it.
  CONCURRENCY - specifies the PostgreSQL waits until the conflicting 
                transaction completes before removing the index.

                Not support CASCADE.
                Executing in a transaction block is also not supportd.
*/

DROP INDEX idx_address_phone;
