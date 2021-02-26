import itertools
# product(*iterables, repeat=1)
# permutations(iterable, r=None)
# combinations(iterable, r)
# combinations_with_replacement(iterable, r)


letter_combinations = itertools.product("ABC", "ij")
nums_combinations = itertools.product(range(2), repeat=2)

list_elem_combinations = itertools.permutations([1, 2, 3], 2)
range_elem_combinations = itertools.permutations(range(5))

unique_combinations = itertools.combinations("BDCA", 2)

combine_unique = itertools.combinations_with_replacement("BCA", 2)

# Printing global table.
import pprint  # noqa
pprint.pprint(globals())
