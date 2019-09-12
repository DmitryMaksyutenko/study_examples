"""This module keeps MySQLCursor Properties."""
#   An advantage of working with cursors is that it is no longer necessary
# to consider the eof information that cmd_query(), get_rows(), and
# get_row() return. Instead, the relevant information is available through
#   All of the properties are read-only and contain information related to
# the latest query that was executed. Each of the properties will be briefly
# discussed in the following sections.

#   column_names:
# The column_names property includes the name of each column in the same
# order as their values. It is the same as the first element in the list for the
# columns in the result dictionary returned by the cmd_query() method.
# import mysql.connector

#   description:
# The description property is equivalent to the entire columns element
# in the cmd_query() result dictionary. The value of the property is a list of
# tuples.

#   lastrowid:
# The lastrowid can be used to get the last assigned ID after inserting
# it into a table with an auto-increment column. This is the same as the
# insert_id element of the OK package returned by cmd_query() for
# INSERT statements. If the statement inserts multiple rows, it is the ID of
# the first row that is assigned to lastrowid. If no ID is available, the value of
# lastrowid is None.

#   rowcount:
# The meaning of the rowcount property depends on the statement that was
# executed. For SELECT statements, it is the number of rows returned. For
# data modification language (DML) statements such as INSERT, UPDATE, and
# DELETE, it is the number of rows affected.

#   statement:
# The statement property holds the last query or queries to be executed.

#   with_rows:
# The with_rows property is a Boolean that is True when the query returns
# a result set. Unlike the unread_result property of the connection,
# with_rows is not set to False when all rows have been read.
import mysql.connector

def main():
    """Entry point."""
    db = mysql.connector.connect(
        option_files = "config.conf"
    )
    print(f"connection id: {db.connection_id}"
            f"\ncharacter set: {db.charset}"
            f"\ncollation: {db.collation}")
    
    # The result will be treated as dictionary.
    # cursor = db.cursor(dictionary=True)
    # cursor.execute(
    #     """SELECT Name, CountryCode, Population
    #     FROM world.city
    #     WHERE Population > 9000000
    #     ORDER BY Population DESC"""
    # )

    # if cursor.with_rows:
    #     print(f"{'City':15s}  {'Country':7s}  {'Pop':3s}")

    #     city = cursor.fetchone()
    #     while city:
    #         print(f"{city['Name']:15s}  {city['CountryCode']:^7s}  {city['Population']/1000000:4.1f}")
    #         city = cursor.fetchone()

    # cursor.close()
    # The result will be treated as Tuple.
    cursor = db.cursor(named_tuple=True)
    cursor.execute(
        """SELECT Name, CountryCode, Population
        FROM world.city
        WHERE Population > 9000000
        ORDER BY Population DESC"""
    )

    if cursor.with_rows:
        print(f"{'City':15s}  {'Country':7s}  {'Pop':3s}")

        city = cursor.fetchone()
        while city:
            print(f"{city.Name:15s}  {city.CountryCode:^7s}  {city.Population/1000000:4.1f}")
            city = cursor.fetchone()

    cursor.close()
    db.close()


if __name__ == "__main__":
    main()
