# List creation.

empty_list = []
empty_list = list()
list_with_values = [1, 2, 3, 4, 5]
list_comprehension = [0 for _ in range(10)]
list_constructor = list(list_with_values)

# Data for tests.
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
colors = ["red", "green", "blue", "yellow", "orange"]
fruits = ["apple", "banana", "pear", "peach"]
tuples = [(1, "one"), (2, "two"), (3, "three"), (4, "four")]


# Operators.

# assigning.
list_with_values[0] = 33  # [33, 2, 3, 4, 5]

# subset replacing.
fruits[1:3] = colors  # noqa ['apple', 'red', 'green', 'blue', 'yellow', 'orange', 'peach']

# range deleting.
del fruits[1:5]  # ["apple", "orange", "peach"]

# in / not in
1 in numbers  # True
123 in numbers  # False
432 not in numbers  # True
"red" in colors  # True
"black" not in colors  # False
"b" in colors  # False
1 in tuples  # False
(2, "two") in tuples  # True

# concatenation.
colors + fruits  # noqa [red", "green", "blue", "yellow", "orange", "apple", "banana", "pear", "peach"]
numbers + list_with_values  # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5]
tuples + list_with_values  # noqa [(1, "one"), (2, "two"), (3, "three"), (4, "four"), 1, 2, 3, 4, 5]

# multiplication.
list_with_values * 2  # [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]

# indexing.
numbers[0]  # 1
numbers[4]  # 5
# numbers[14]  # IndexError
tuples[1]

# slicing.
numbers[:5]  # [1, 2, 3, 4, 5]
numbers[1:]  # [2, 3, 4, 5, 6, 7, 8, 9, 10]
colors[1:4]  # ["green", "blue", "yellow"]
numbers[::2]  # [1, 3, 5, 7, 9]


# Methods.
colors.sort()  # ['blue', 'green', 'orange', 'red', 'yellow']
fruits.sort(key=lambda x: x[1])  # ['banana', 'pear', 'peach', 'apple']
numbers.sort(reverse=True)

colors.append("grey")  # ['blue', 'green', 'orange', 'red', 'yellow', 'grey']

list_with_values.clear()

colors_copy = colors.copy()

list_with_values.extend(numbers)  # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

fruits.insert(3, "kivifruit")  # noqa ['banana', 'pear', 'peach', 'kivifruit', 'apple']

fruits.pop()  # "apple"
fruits.pop(0)  # "banana"

numbers.remove(10)  # [9, 8, 7, 6, 5, 4, 3, 2, 1]
numbers.remove(1)  # [9, 8, 7, 6, 5, 4, 3, 2]

numbers.reverse()  # [2, 3, 4, 5, 6, 7, 8, 9]


# Global table prnting.
import pprint  # noqa
pprint.pprint(globals())
