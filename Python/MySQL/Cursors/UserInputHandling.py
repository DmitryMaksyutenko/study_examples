"""Module keeps a commons scenario on input from user."""
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#   Never input information into database without ensuring that it is 
# handled such that it cannot change the meaning of the queries.
# Falling to do so can, for example, open the applicaton to SQL 
# injection attacks.
#   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#   There ate several ways to secure the program:
#   - Validating the input.
#   - Parametrizing the queries.
#   - Use prepared statements.

# PREPARED STATEMENTS:
#
#   cursor = db.cursor(prepared=True)
#
#   Behinde the scenes, there ate subtledifferences, though. The first time a query
# executed, the statement is prepared: that is, the statement is submitted to MySQL Server with
# plasce holders, and MySQL Server parepares the statement for future use. Then the cursor sends a
# command to tell MySQL Server to execute the prepared statement along with the parameters to use
# for the query.
#   Approaches:
# - MySQL Server does ad much of the preparetin of the querqy during the prepare phase as possible.
# This neans that for subsequent executions, there is less work required, and only the parameters
# need tobe sent over the networok, so the performance is impruved.
# - MySQL Server resolves which tables and columns are required for the query, so it able to ensure
# the submitted parameters ate handled according to the data type of the column.
# This prevent SQL injection.

import mysql.connector


def main():
    """Entry point."""
    user_input = "'Sydney' OR True"

    db = mysql.connector.connect(
        option_files = "config.conf"
    )
    cursor = db.cursor(dictionary=True)

    # Query without parameters
    query_1 = """SELECT * FROM world.city
                    WHERE Name = {0}""".format(user_input)

    query_2 = """SELECT * FROM world.city
                    WHERE Name = %(name)s"""
    
    params = {'name': user_input}

    cursor.execute(query_2, params=params)
    result = cursor.fetchall()

    # Nothin will be printed because there is no rows 
    # with city name "'Sydney' OR True"
    for i in result:
        print(i)

    print(cursor.statement)

    # cursor.execute(query_1)
    # result = cursor.fetchall()

    # # It will print all table because WHERE clause consists:
    # # Name = 'Sydney' OR True
    # # True matches everything
    # for i in result:
    #     print(i)
    
    # print(cursor.statement)

    cursor.close()
    db.close()


if __name__ == "__main__":
    main()