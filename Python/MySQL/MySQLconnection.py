# -*- coding: utf-8 -*-
import mysql.connector

def main():
    """Entry point"""
    #   Creating a connection using mysql.connector.connect()
    #   Gives access to all connection-related features.
    db = mysql.connector.connect(
        option_files = [            # Specifies the path to one
            "shared.ini",           # more configuration files
            "app_specific.ini"      # to read.
        ],
        option_groups = [            # Which option groups 
            "client",               # to read from.
            "connector_python"
        ]
    )

    print("connection id: ", db.connection_id)
    print("\n".join(mysql.connector.ClientFlag.get_full_info()))

    db.close() # Always close the connection when done with it.

if __name__ == "__main__":
    main()
