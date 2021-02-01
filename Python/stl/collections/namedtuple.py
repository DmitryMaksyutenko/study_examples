from collections import namedtuple
# The factory function for tuples with named fields.
# Useful for SQL queries and CSV files.

# Creation.

Person = namedtuple("Person", ["first_name", "last_name", "age"])

person_1 = Person("Tomas", "Robinson", "12")
person_2 = Person("James", "Lee", "13")
person_3 = Person("Jane", "Douel", "13")
person_4 = Person._make(["Reny", "Olfas", "15"])
person_5 = Person(**{"first_name": "Rick",
                     "last_name": "Moralez",
                     "age": "99"})


# Operators.

person_1[0]  # "Tomas".
person_1[1]  # "Robinson".
person_1[2]  # "12".

"Tomas" in person_1  # True.
"14" in person_1  # False.
"first_name" in person_1  # False.


# Methods.

# person_1.index("first_name") raise ValueError.
person_1.index("12")  # 2.
person_1.index("Tomas")  # 0.

person_2.count("age")  # 0.
person_2.count("13")  # 1.
person_2.count("Douel")  # 1.

person_1_as_dict = person_1._asdict()
person_2_as_dict = person_2._asdict()

person_1_new_name = person_1._replace(first_name="Tom")

person_1._fields  # ("first_name", "last_name", "age").

person_1._field_defaults  # {}.


# Printing global table.
import pprint  # noqa.
pprint.pprint(globals())
