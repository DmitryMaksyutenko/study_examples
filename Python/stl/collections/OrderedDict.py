from collections import OrderedDict
# The dictionary that remember the order, the keys were last inserted.


# Creation.

empty = OrderedDict()
args = OrderedDict(one=1, two=2, four=4, free=3)
from_dict = OrderedDict({1: "one", 3: "three", 2: "two"})
letter_keys = OrderedDict.fromkeys("bcas")


# Methods.

from_dict.move_to_end(3)  # noqa OrderedDict([(1, 'one'), (2, 'two'), (3, 'three')]).
from_dict.popitem()  # OrderedDict([(1, 'one'), (2, 'two')]).


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
