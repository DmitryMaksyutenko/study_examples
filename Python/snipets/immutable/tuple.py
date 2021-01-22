# Creation.

empty_tuple = ()
empty_tuple = tuple()
one_lelem_tuple = 1.1,
one_lelem_tuple = (1.1,)
odd_numbers = 1, 3, 5, 7, 9
even_numbers = (2, 4, 6, 8, 10)
from_list = tuple(["one", "two", "three"])


# Operators.

3 in odd_numbers  # True.
2 in odd_numbers  # False.
4 not in odd_numbers  # True.

numbers = odd_numbers + even_numbers  # noqa (1, 3, 5, 7, 9, 2 ,4, 6, 8, 10).

two = from_list[1]  # "two".
num_subset = numbers[2:6]  # (5, 7, 9, 2).
reversed_even = numbers[-1:-6:-1]


# Methods.

index_of_five = numbers.index(5)  # 2.
# not_present = numbers.index(5, 3, 5)  ValueError. not in tuple.

total_number_of = numbers.count(9)  # 1.


# Global tablespace printing.
import pprint  # noqa
pprint.pprint(globals())
