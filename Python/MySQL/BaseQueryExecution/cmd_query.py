"""This module keep examples of base queries"""
import mysql.connector
import pprint


def main():
    """Entry point"""
    printer = pprint.PrettyPrinter(indent=2)
    db = mysql.connector.connect(
        option_files = "configuration.ini",
    )

    # Method takes query to execute and returns a dictionaty with respond.
    result = db.cmd_query(
        """SELECT Name, CountryCode, Population FROM world.city
            WHERE Population > 9000000 ORDER BY Population DESC"""
    )

    # When the last row of a result set is read, "unread_result = False".
    # It must be False to avoid "mysql.connection.errors.InternalError".
    # Whenever a query returns a result set, the rows must be consumed
    # before another query can be executed.
    print("Unreaded result flag is: ",db.unread_result)

    # Method returns all rows found by query.
    result_set = db.get_rows()

    print("Result\n" + "="*20)
    printer.pprint(result)
    print("\nResult Set\n" + "="*20)
    printer.pprint(result_set)

    print("Unreaded result flag is: ",db.unread_result)

    db.close()


if __name__ == "__main__":
    main()
