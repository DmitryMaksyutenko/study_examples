from collections import Counter
# It is a dictionary where elements are stored as keys
# and their counts as values.

# Creation.

from_list = Counter([1, 2, 3, 4, 4, 1, 2, 3, 5, 3, 5])
from_string = Counter("This is a test string. This is simple.")
from_dictionaty = Counter({"one": 1, "two": 2, "three": 3})
from_keywords = Counter(cats=2, dogs=3)


# Operators.

"a" in from_string  # Frue.

from_string["a"]  # 1.
from_string["z"]  # 0. Don't raise KeyError.
from_string["z"] = 1  # 1.


# Methods.

from_list.elements()  # iterator.

from_list.most_common()  # [(3, 3), (1, 2), (2, 2), (4, 2), (5, 2)].
from_list.most_common(1)  # [(3, 3)].
from_list.most_common(2)  # [(3, 3), (1, 2)].

from_list.subtract(Counter([1, 2, 3]))  # noqa [(3, 2), (1, 1), (2, 1), (4, 2), (5, 2)].

from_list.update(Counter([1, 2, 3]))  # noqa [(3, 3), (1, 2), (2, 2), (4, 2), (5, 2)].

# from_list.fromkeys([1, 2, 3]) Not implemented.


# The global table printing.
import pprint  # noqa.
pprint.pprint(globals())
