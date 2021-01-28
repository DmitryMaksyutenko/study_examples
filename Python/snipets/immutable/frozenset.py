# Creation.

empty_set = frozenset()
numbers = {1, 2, 3, 4, 5}
relatives = {"mother", "father", "sister"}
letters = frozenset(["a", "b", "c", "d"])


# Operators.

"a" in letters  # True.
"g" in letters  # False.
"g" not in letters  # True.

letters <= numbers  # False.
{"mother", "father"} <= relatives  # True.
{"mother", "father"} < relatives  # True.
{"mother", "sister", "father"} < relatives  # False.
nums_and_letters = numbers | letters
letters & {"a", "c", "e", "r"}  # {"a", "c"}
letters - {"a", "c", "e", "r"}  # {"b", "d"}
letters ^ {"a", "c", "e", "r"}  # {"b", "d", "e", "r"}


# Methods.

new_letters = letters.copy()
letters.isdisjoint(numbers)  # True.
letters.issubset(numbers)  # False.
{"mother", "father"}.issubset(relatives)  # True.
nums_and_letters = numbers.union(letters)
common_letters = letters.intersection({"a", "c", "e", "r"})
different_letters = letters.difference({"a", "c", "e", "r"})
sym_diff = letters.symmetric_difference({"a", "c", "e", "r"})


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
