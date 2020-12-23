# An "iterable" is any object in Python which has an __iter__ or a __getitem__
# method implemented which returns an iterator or can take indexes

# An "iterator" is any object in Python which has a __next__ method defined.


class MyIterator:
    def __init__(self, start=0, stop=None, step=1):
        self.start = start
        self.stop = stop
        self.step = step

    def __iter__(self):
        return self

    def __next__(self):
        if self.start == self.stop:
            raise StopIteration
        else:
            number = self.start
            self.start += self.step
            return number


itr = MyIterator(0, 10, 2)

print("Iterator: ")
for i in itr:
    print(i, end=", ")

# Generator functions are a special kind of function that return a lazy
# iterator. These are objects that can loop over objects like a list.
# However, unlike lists, lazy iterators do not store their contents in memory.
# The generator can remember the state of it's execution, suspend it, return
# control to the caller, and resume execution from remembered state.


def simple_generator():
    for number in MyIterator(0, 20):
        yield number


print("\nGenerator: ")
for item in simple_generator():
    print(item, end=", ")


def fibonacci(n):
    num = next_num = 1
    for i in range(n):
        num, next_num = next_num, num + i
        yield num


print("\nFibonacci: ")
for num in fibonacci(100):
    print(num, end=", ")


def show_words():
    try:
        while True:
            try:
                print("BEFORE YIELD")
                word = yield
                print(word)
            except StopIteration:
                print("EXCEPT INNER")
    except StopIteration:
        print("EXCEPT UOTER")
        return
