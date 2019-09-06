"""This module describe connection with character set options"""
import mysql.connector as conn

def main():
    """Entry point"""
    config = {
        "user": "dima",
        "password": "0000",
        "host": "127.0.0.1",
        "port": "3306",
        "database": "information_schema",
        "charset": "utf8mb4",
        "collation": "utf8mb4_unicode_ci",
        "use_unicode": True,
    }

    db = conn.connect(**config)

    print(__file__ + " - settings character set:")
    print("connection ID: ", db.connection_id)

    print("database charset: ", db.charset)
    print("database collation", db.collation)

    #   Change character set and collation
    #   Always use this method insted SQL, Connector/Python knows which settings
    #   are used for covering bytearray into Python strings.
    db.set_charset_collation(
        charset = "latin1",
        collation = "latin1_general_ci"
    )

    print("database charset and collation aftre change:")
    print("database charset: ", db.charset)
    print("database collation", db.collation)

    db_cursor = db.cursor()

    charset_query = (
        "SELECT CHARACTER_SET_NAME as Name, DEFAULT_COLLATE_NAME "
        "FROM information_schema.CHARACTER_SETS " 
        "ORDER by CHARACTER_SET_NAME"
    )

    db_cursor.execute(charset_query)
    character_result = db_cursor.fetchall()
    print("\nlist of characer sets:\n")
    print(*character_result, sep="\n")

    collation_query = (
        "SELECT COLLATION_NAME, IS_DEFAULT "
        "FROM information_schema.COLLATIONS "
        "WHERE CHARACTER_SET_NAME = 'utf8mb4'"
    )

    db_cursor.execute(collation_query)
    collation_result = db_cursor.fetchall()
    print("\nlist of collations:\n")
    print(*collation_result, sep="\n")

    db.close()



if __name__ == "__main__":
    main()
