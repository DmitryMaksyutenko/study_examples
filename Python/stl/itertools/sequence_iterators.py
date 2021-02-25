import itertools
import operator
# accumulate(iteratble[, func, *, initial=None])
# chain(*iterables)
# chain.from_iterable(iterable)
# compress(data, selectors)
# dropwhile(predicate, iterable)
# filterfalse(predicate, iterable)
# groupby(iterable, key=None)
# islice(iterable, stop)
# islice(iterable, start, stop[, step])
# starmap(function, iterable)
# takewhile(predicate, iterable)
# tee(iterable, n=2)
# zip_longest(*iterables, fillvare=None)


list_sum = itertools.accumulate([1, 2, 3, 4, 5])
list_mul = itertools.accumulate([1, 2, 3, 4, 5], operator.mul)

chained_list = itertools.chain([1, 2], [10, 20], [100, 200])
from_list = itertools.chain.from_iterable([[1, 2], [3, 4], [5, 6]])

vowels = itertools.compress("ABCDEF", [1, 0, 0, 0, 1, 0])

from_five = itertools.dropwhile(lambda x: x < 5, [1, 2, 3, 4, 5, 6])

odd_nums = itertools.filterfalse(lambda x: not x % 2, [1, 2, 3, 4, 5])

is_even = itertools.groupby([1, 2, 3, 4, 5], lambda x: x % 2 == 0)

get_elem_from_start = itertools.islice([1, 2, 3, 4, 5], None)
get_odd_elements_from_3 = itertools.islice([1, 2, 3, 4, 5], 2, None)
get_even_step_2 = itertools.islice([1, 2, 3, 4, 5, 6, 7, 8], 1, None, 2)

sum_of_tuple = itertools.starmap(operator.add, [(2, 2,), (2, 3), (65, 1)])

get_char_lower_95 = itertools.takewhile(lambda x: x < 97, range(127))

two_iterators = itertools.tee([1, 2, 3, 4, 5])
three_iterators = itertools.tee([1, 2, 3, 4, 5], 3)

letters = itertools.zip_longest("ABCD", "abcd")
letters_more_capital = itertools.zip_longest("ABCDEF", "abcd", fillvalue=".")


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
