SELECT false = NULL, true = NULL, NULL = NULL;
-- null null null

SELECT 'a' = NULL, 1 = NULL;
-- null null

SELECT 1 = NULL;
-- null

SELECT 1 = NULL OR (1 IS NULL OR NULL IS NULL);
-- true
