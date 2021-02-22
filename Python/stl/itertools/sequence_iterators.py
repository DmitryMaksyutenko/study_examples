import itertools
import operator
# accumulate(iteratble[, func, *, initial=None])
# chain(*iterables)
# chain.from_iterable(iterable)
# compress(data, selectors)


list_sum = itertools.accumulate([1, 2, 3, 4, 5])
list_mul = itertools.accumulate([1, 2, 3, 4, 5], operator.mul)

chained_list = itertools.chain([1, 2], [10, 20], [100, 200])
from_list = itertools.chain.from_iterable([[1, 2], [3, 4], [5, 6]])

vowels = itertools.compress("ABCDEF", [1, 0, 1, 0, 1, 1])


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
