from collections import deque
# The deque is a mutable generalization of stracks and queues.
# Supports a thread-safe memory efficient appends and pops.

# Creation.

empty = deque()
numbers = deque([1, 2, 3, 4, 5, 6, 7, 8, 9])
letters = deque(["a", "b", "c", "d", "e"])
names = deque({"Sam", "Alan", "Tom", "Helen"}, 6)


# Operators.

5 in numbers  # True.
123 not in numbers  # True.

letters + numbers
numbers += [10, 11, 12]
letters * 2

numbers[4]  # 5.


# Methods.

names.append("Dean")
names.append("Bill")
names.append("Travis")  # Discards "Sam".

names.appendleft("Alice")  # Discards "Travis".

numbers.extend([111, 222])  # noqa [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 111, 222].
names.extend(["Crees", "Ban"])  # noqa ["Alice", "Alan", "Tom", "Helen", "Crees", "Ban"].

letters.extendleft(["A", "B"])  # ["A", "B", "a", "b", "c", "d", "e"].

numbers.clear()  # deque([]).

letters.index("a")  # 2.

letters.insert(2, "C")

letters.pop()  # Remove and return "e".
letters.popleft()  # Remove and return "A"

letters.remove("c")  # Remove "c" or raise ValueError.

letters.reverse()  # ['d', 'b', 'a', 'C', 'A'].

letters.rotate(1)  # ['A', 'd', 'b', 'a', 'C']
letters.rotate(2)  # ['a', 'C', 'A', 'd', 'b']
letters.rotate(-1)  # ['C', 'A', 'd', 'b', 'a']

letters.maxlen  # None.
names.maxlen  # 6.


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
