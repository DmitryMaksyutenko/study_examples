"""Multiple queries."""
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#   It can be harder to follow what is going on when reading the source code
#   of the programm.
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#   Multiple queries can be used by connection object or cursor.
# db.cmd_query_iter() - returns a generator that can be used to 
# fetch the result of each of the queries.

# cursor.execute() - when the multi arguments is enabled. Returned a 
# generator fot results.

# cursor.executemany() - method takes a template (query with parameter placeholder)
# and a list of sets of paremeters. There is no support for having results returned.
import mysql.connector
from mysql.connector.conversion import MySQLConverter
from datetime import datetime
from time import sleep


def main():
    """Entyr point."""
    db = mysql.connector.connect(
        option_files = "config.conf",
        use_pure=True
    )
    cursor = db.cursor()

    # cmd_query_iter()
    converter = MySQLConverter(db.charset, True)

    q1 = """SELECT Name, CountryCode, Population
            FROM world.city
            WHERE CountryCode = 'USA'
            ORDER BY Population DESC
            LIMIT 3"""
    q2 = "DO SLEEP(3)"
    q3 = """SELECT Name, CountryCode, Population
            FROM world.city
            WHERE CountryCode = 'IND'
            ORDER BY Population DESC
            LIMIT 3"""
    
    queries = [q1, q2, q3]

    result = db.cmd_query_iter(";".join(queries))

    # Iterate throw the results
    count = 0
    # It is one of the SELECT statements
    # as it has coumn definitions
    # print the result.
    for results in result:
        count = count + 1
        time = datetime.now().strftime('%H:%M:%S')
        print(f"query {count} - {time}\n")
        
        if 'columns' in results:
            print(f"{'City':18s}  {'Code':7s}  {'Popul':3s}")
            city, eof = db.get_row()
            while not eof:
                values = converter.row_to_python(
                    city, results["columns"]
                )
                print(f"{values[0]:18s}  {values[1]:7s}  {values[2]/10000000:3f}")
                city, eof = db.get_row()
        else:
            print("No results.")
        
        sleep(2)
        print("")

    cursor.close()
    db.close()


if __name__ == "__main__":
    main()
