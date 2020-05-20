/*
     A window function performs a calculation across a set of table rows that are somehow
    related to the current row. This is comparable to the type of calculation that can be
    done with an aggregate function. However, window functions do not cause rows to become
    grouped into a single output row like non-window aggregate calls would. Instead, the
    rows retain their separate identities. Behind the scenes, the window function is able
    to access more than just the current row of the query result.

        function_name ([expression [, expression ... ]]) [ FILTER ( WHERE filter_clause  )  ] OVER window_name
        function_name ([expression [, expression ... ]]) [ FILTER ( WHERE filter_clause  )  ] OVER
                                                                                ( window_definition  )
        function_name ( *  ) [ FILTER ( WHERE filter_clause  )  ] OVER window_name
        function_name ( *  ) [ FILTER ( WHERE filter_clause  )  ] OVER ( window_definition  )


    where "window_definition" has the syntax:
        [ existing_window_name  ]
        [ PARTITION BY expression [, ...]  ]
        [ ORDER BY expression [ ASC | DESC | USING operator  ] [ NULLS { FIRST | LAST  }  ] [, ...]  ]
        [ frame_clause  ]

    The optional "frame_clause" can be one of:
        { RANGE | ROWS | GROUPS  } frame_start [ frame_exclusion  ]
        { RANGE | ROWS | GROUPS  } BETWEEN frame_start AND frame_end [ frame_exclusion  ]

    where "frame_start" and frame_end can be one of:
        UNBOUNDED PRECEDING
        offset PRECEDING
        CURRENT ROW
        offset FOLLOWING
        UNBOUNDED FOLLOWING

    and "frame_exclusion" can be one of:
        EXCLUDE CURRENT ROW
        EXCLUDE GROUP
        EXCLUDE TIES
        EXCLUDE NO OTHERS
*/
