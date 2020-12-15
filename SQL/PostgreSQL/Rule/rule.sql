/*
    It modifies queries to take rules into consideration, and then passes the modified query
    to the query planner for planning and execution. It is very powerful, and can be used
    for many things such as query language procedures, views, and versions.

    The rule system is located between the parser and the planner.
    It takes the output of the parser, one query tree, and the user-defined rewrite rules,
    which are also query trees with some extra information, and creates zero or more query trees as result.

    The PostgreSQL rule system allows to define an alternative action on insert, update or delete.
    A rule generates an extra query. As a result, rule execution impacts the performance of the system.

        CREATE [ OR REPLACE ] RULE name AS ON event
            TO table_name [ WHERE condition ]
            DO [ ALSO | INSTEAD ] { NOTHING | command | ( command ; command ... ) }
*/

CREATE OR REPLACE RULE do_nothin AS ON INSERT
TO actor DO INSTEAD NOTHING;
