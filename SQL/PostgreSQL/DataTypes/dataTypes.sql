/*
    Boolean
    A Boolean data type can hold one of three possible values: true, false or null.
    The PostgreSQL uses the one byte for storing the boolean type in memory. The BOOLEAN can be abbriviated as BOOL.

    Character
    PostgreSQL provides three character data types: CHAR(n), VARCHAR(n), and TEXT

      CHAR(n) is the fixed-length character with space padded. If insert a string
      that is shorter than the length of the column, PostgreSQL pads spaces.
      If insert a string that is longer than the length of the column, PostgreSQL
      will issue an error.

      VARCHAR(n) is the variable-length character string. VARCHAR(n), can store up to
      n characters. PostgreSQL does not pad spaces when the stored string
      is shorter than the length of the column.

      TEXT is the variable-length character string. Theoretically, text data is
      a character string with unlimited length.

    Numeric

      Integer
      There are three kinds of integers in PostgreSQL:

      Small integer ( SMALLINT ) is 2-byte signed integer that has a range from -32,768 to 32,767.

      Integer ( INT ) is a 4-byte integer that has a range from -2,147,483,648 to 2,147,483,647.

      Serial is the same as integer except that PostgreSQL will automatically generate
      and populate values into the SERIAL column.
      This is similar to AUTO_INCREMENT column in MySQL or AUTOINCREMENT column in SQLite

      Floating-point number
      There three main types of floating-point numbers:

      float(n) is a floating-point number whose precision, at least, n, up to a maximum of 8 bytes.

      real or float8 is a 4-byte floating-point number.

      numeric or numeric(p,s) is a real number with p digits with s number after the decimal point.      The numeric(p,s) is the exact number.

    Temporal data types
    The temporal data types allow to store date and/or time data.
    PostgreSQL has five main temporal data types:

      DATE stores the dates only.

      TIME stores the time of day values.

      TIMESTAMP stores both date and time values.

      TIMESTAMPTZ is a timezone-aware timestamp data type. It is the abbreviation
      for timestamp with the time zone.

      INTERVAL stores periods of time.

    Arrays
    PostgreSQL can store an array of strings, an array of integers, etc., in array columns.
    The array comes in handy in some situations e.g., storing days of the week, months of the year.

    JSON
    PostgreSQL provides two JSON data types: JSON and JSONB for storing JSON data.

    The JSON data type stores plain JSON data that requires reparsing for each processing,
    while JSONB data type stores JSON data in a binary format which is faster to process
    but slower to insert. In addition, JSONB supports indexing, which can be an advantage.

    UUID
    The UUID data type allows to store Universal Unique Identifiers defined by RFC 4122.
    The UUID values guarantee a better uniqueness than SERIAL and can be used
    to hide sensitive data exposed to the public such as values of id in URL.

    Special data types
    Besides the primitive data types, PostgreSQL also provides several special data types
    related to geometric and network.

      box– a rectangular box.
      line – a set of points.
      point– a geometric pair of numbers.
      lseg– a line segment.
      polygon– a closed geometric.
      inet– an IP4 address.
      macaddr– a MAC address.
*/
