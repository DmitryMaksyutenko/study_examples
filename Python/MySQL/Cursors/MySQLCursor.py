"""This module describes MySQLCursor query exeution."""
#   The main method for executing queries is the execute() method,
# while there are three different methods for reading the rows returned
# by the query.
#
#  fetchone(): Reads one row at a time. This is the
# equivalent of the get_row() method, which is also used
# for unbuffered results. 
#
#  fetchmany(): Fetches a batch of rows with the
# possibility to set the maximum number of rows to
# include in the batch.
#
#  fetchall(): Fetches all remaining rows. This is similar
# to the get_rows() method without any argument.
#
#   The flow starts with the application creating a connection.
# The cursor classes have a property called with_rows that specifies
# whether there is a result set to handle. Once all rows
# are fetched, the fetch method will return None or an empty result. The
# cursor can be reused to execute more queries. Once all queries have been
# executed, both the cursor and the connection are closed.

#   All rows must be fetched explicitly or by enabling consume_
# results for the connection. An exception will be raised if unread
# rows are found and a new query is executed using the same cursor
# or the cursor is closed unless consume_results is enabled. It is
# also only possible to have one cursor for the connection with an
# unread result at a time.
# import mysql.connector

import mysql.connector

def main():
    """Entry point."""
    db = mysql.connector.connect(
        option_files = "config.conf"
    )
    print(f"connection id: {db.connection_id}"
            f"\ncharacter set: {db.charset}"
            f"\ncollation: {db.collation}")

    # Instantiate the cursor
    cursor = db.cursor()

    #   The execute() method takes one required argument, the query to
    # execute, as well as two optional arguments:
    # operation: The query to execute. This argument is mandatory.
    # params: Either a dictionary, list, or tuple of the
    # parameters to use with the query.
    # multi: When True, the operation is considered multiple
    # queries separated by semicolons and execute()
    # returns an iterator to make it possible to iterate over the
    # result of each query.

    cursor.execute("""SELECT Name, CountryCode, Population
    FROM world.city WHERE Population > 9000000
    ORDER BY Population DESC""")

    # The with_rows property of the cursor is checked
    # before fetching the rows. The with_rows property is True when the query
    # returns rows. The value does not change even if all rows have been fetched.
    if cursor.with_rows:
        print("{0:15s}   {1:7s}  {2:3s}".format("City", "country", "Pop"))

        # MySQLCursor class automatically handles the conversion from the raw
        # data to the Python types, irrespective of whether the pure Python or C
        # Extension implementation is used, making it simpler to just loop over the
        # rows and print them.
        city = cursor.fetchone()
        #   The return value of fetchone() is just a tuple of the values for the row
        # whereas get_rows() also includes the eof information. 
        # This means that the loop must
        # terminate when fetchone() returns None.
        while city:
            print("{0:15s}   {1:^7s}  {2:4.1f}".format(
                city[0],
                city[1], 
                city[2]/10000000.0))
            city = cursor.fetchone()

    cursor.close()

    db.close()


if __name__ == "__main__":
    main()
