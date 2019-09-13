"""This module describes how to use cursores with MySQL Python connector."""
#   Usinng the connection directly can be considered the low-level method.
#   For actual programms, it is more common to choose the higher-level cursores,
#   which provide a nicer way of working with queries.
#
#   cmd_query(), get_row(), get_rows() methods helps explain why cursors work    
#   the way they do and is useful when debugging issues.

import mysql.connector
from mysql.connector.cursor import MySQLCursor


def main():
    """Entry point."""
    db = mysql.connector.connect(
        option_files = "config.conf"
    )
    print(f"connection number: {db.connection_id}"
                f"\ncharacter settings: {db.charset}"
                f"\ncollation: {db.collation}")

    #   Creating cursor using object method.
    # The advantage of using cursor() method is that, it can provide arguments
    # for the cursor and the method will return a cursor object using the 
    # appropriate cursor class.
    # ARGUMENTS:
    # buffered:, raw:, prepared:, cursor_class:, dictionary:, named_tuple:,
    cursor1 = db.cursor()
    cursor1.close()

    #   Creating cursor using the constructor.
    # MySQLCursorBuffered - buffered result sets converts to PYthon types
    # MySQLcursorRaw - returns raw results as byte array.
    # MySQLCursorBufferedRaw - raw result set enables buffering.
    # MySQLCursorDict - same as MySQLCursor, rows are returned as dictionaries.
    # MySQLCursorBufferedDict - same as MySQLCursorBufferd, raws returns as dictionaries.
    # MySQLCursorNamedTuple - same as MySQLCursor, rows returns as tuples.
    # ...
    cursor2 = MySQLCursor(db) # Unbuffered output converted to Python types
    cursor2.close()

    #   Closing the cursor when done with it.
    # It's ensures that the reference back to the connection 
    # object is deleted, thus avoiding memory leaks.

    db.close()
    

if __name__ == "__main__":
    main()
