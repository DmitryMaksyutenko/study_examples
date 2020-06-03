/*
    JSON data types are for storing JSON (JavaScript Object Notation) data. Such data can also be stored as text,
    but the JSON data types have the advantage of enforcing that each stored value is valid according to the JSON rules.

    The json data type stores an exact copy of the input text, which processing functions must reparse on each execution;
    while jsonb data is stored in a decomposed binary format that makes it slightly slower to input due to added conversion
    overhead, but significantly faster to process, since no reparsing is needed. jsonb also supports indexing,
    which can be a significant advantage.

    Use UTF-8 when work with JSON or JSONB types.

    –> –>> Returns field of JSON-object by index or field name.
    #> #>> Returs field of JSON-object by path.
*/

-- Without processing.
SELECT '{"name": "value", "name": "value"}'::json;
SELECT '{"key": 1.1, "key": 1.1}'::json;

-- With processing.
SELECT '{"name": "value", "name": "value"}'::jsonb;
SELECT '{"key": 1.1, "key": 1.1}'::jsonb;
