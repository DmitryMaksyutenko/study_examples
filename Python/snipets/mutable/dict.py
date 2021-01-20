# Creation.

empty_dict = {}
empty_dict = dict()
vehicle = dict(brand="BMW", year=2015, body_type="sedan")
person = {"first_name": "Bill", "last_name": "Smith", "age": 33}
generated_dict = {i: i ** 2 for i in range(10)}
numbers = dict([(1, "one"), (2, "two"), (3, "three"), (4, "four")])


# Operators.

vehicle["year"]  # return value 2015 by year key.
vehicle["year"] = 2020  # assign value 2020 to year key.

0 in generated_dict  # True
2345 not in generated_dict  # True
"cost" in vehicle  # False

# Methods.

person_values = person.values()  # return new view of the person values.
person_keys = person.keys()  # return new view of the person keys.
person_items = person.items()  # return new [(key, value)] view of the person

numbers.update(dict([(5, "five"), (6, "six")]))

empty_dict.setdefault("key", "some")  # insert key:some into the dictionary.
value_from_person = person.setdefault("age", 55)  # return 33.

LIFO_value_from_numbers = numbers.popitem()  # noqa. return (6, "six"). Raise KeyError.
LIFO_value_from_numbers = numbers.pop(2)  # return (2 "two"). Raise KeyError.

get_value = generated_dict.get(6)  # return 36.
get_value = generated_dict.get(35, 1)  # 35 not in dict.

person_copy = person.copy()

empty_dict.clear()


# Global table prnting.
import pprint  # noqa
pprint.pprint(globals())
