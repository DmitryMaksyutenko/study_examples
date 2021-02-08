# The factory function. Returns the subclass of the dict.
from collections import defaultdict

# Cratrion.

lists = defaultdict(list)  # Useful for grouping a sequence of key-value pair.
integer = defaultdict(int)  # Useful for counting.
sets = defaultdict(set)  # Useful for building the dictionary of sets.


# Attribute.

lists.default_factory  # <class 'list'>.
integer.default_factory  # <class 'int'>.
sets.default_factory  # <class 'set'>.


# Examples.

tmp_list = [("yellow", 1), ("red", 2), ("yellow", 2), ("blue", 1)]
for key, value in tmp_list:
    lists[key].append(value)


tmp_string = "test string"
for letter in tmp_string:
    integer[letter] += 1

for key, value in tmp_list:
    sets[key].add(value)


# Pringting the globals.
import pprint  # noqa.
pprint.pprint(globals())
