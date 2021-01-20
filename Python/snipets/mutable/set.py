# Creation.

empty_set = {}
empty_set = set()
generadet_set = {i for i in range(10)}
set_from_list = set([1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6])

odd_numbers = {1, 3, 5, 7, 9}
even_numbers = {2, 4, 6, 8, 10}

rgb_colors = {"red", "green", "blue"}
wb_colors = {"white", "black"}

fruits = {"banana", "apple", "pear"}
berries = {"cherry", "raspberry", "cranberry"}


# Operations.
2 in even_numbers  # True
2 in odd_numbers  # False
"red" not in wb_colors  # True

odd_numbers <= even_numbers  # False
odd_numbers < even_numbers  # False
{1, 3, 5} >= odd_numbers  # False
{1, 3, 5, 7, 9} >= odd_numbers  # True
{1, 3, 5, 7, 9} > odd_numbers  # False
{1, 3, 5, 7, 9, 11} > odd_numbers  # True

colors = rgb_colors | wb_colors  # {"red", "green", "blue", "white", "black"}
rgb_colors & wb_colors  # {}
{"red", "grey"} & rgb_colors  # {"red"}
rgb_colors - wb_colors  # {"blue", "green", "red"}
rgb_colors ^ wb_colors  # {'white', 'green', 'blue', 'black', 'red'}
fruits |= {"kivi fruit", "peach"}  # noqa {"banana", "apple", "pear", "kivi fruit", "peach"}
wb_colors &= colors  # {"white", "black"}
colors -= wb_colors  # {"red", "green", "blue"}
colors ^= wb_colors  # {"white", "red", "balck", "green", "blue"}


# methods.
even_copy = even_numbers.copy()
even_numbers.add(12)  # {2, 4, 6, 8, 10, 12}
even_numbers.remove(12)  # {2, 4, 6, 8, 10} Raise KeyError
even_numbers.discard(2)  # {4, 6, 8, 10}
colors.clear()  # {}
odd_numbers.pop()  # {3, 5, 7, 9}

odd_numbers.update({11, 13, 15})  # {3, 5, 7, 9, 11, 13} equivalent to |=
even_numbers.intersection_update({2, 4, 6, 8})  # {8, 4, 6} equivalent to &=
even_numbers.difference_update({2, 4, 6, 8})  # {} equivalent ot -=
odd_numbers.symmetric_difference_update({1, 3, 5, 7, 9})  # noqa {1, 11, 13 15} equivalent to ^=
odd_numbers.difference({3, 5, 7, 1})  # {11, 13, 15} equivalent to -
odd_numbers.intersection({3, 5, 7, 1})  # {1} equivalent to &
odd_numbers.union(even_numbers)  # {1, 4, 6, 8, 11, 13, 15} equivalent to |
odd_numbers.issubset(even_numbers)  # False equivalent to <=
odd_numbers.issuperset(even_numbers)  # False equivalent to >=
odd_numbers.isdisjoint(even_numbers)  # True


# Global table prnting.
import pprint  # noqa
pprint.pprint(globals())
