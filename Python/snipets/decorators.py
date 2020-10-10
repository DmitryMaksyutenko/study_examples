# Decorators.
# The functions which modify the functionality of other functions.


# In Python, the function can be assigned to a variable, and be called later.
def printHello():
    print("Hello\n")

hello = printHello

hello()


# The function can be defined inside the other function (nested).
def foo():
    print("foo function")

    def baz():
        return "baz function"

    def bar():
        return "bar function\n"

    print(baz())
    print(bar())

foo()


# The function can be returned from another function.
def foo():
    print("foo function")

    def baz():
        return "baz function\n"

    return baz

print(foo()())


# The function as argument of other function.
def baz(function):
    print("baz function")

    return function()

print(baz(foo)())


# The decorator.
def decor(function):

    def wrapFunction():
         print("some decorator logic before.")
         function()
         print("some decorator logic after.\n")

    return wrapFunction

printHello = decor(printHello)
printHello()


# Use the @ as a short way to marking up the decorated function.
@decor
def foo():
    print("The decorated foo function.")

foo()


# The problem with __name__.
print(foo.__name__)

from functools import wraps

def decor(function):

    @wraps(function)
    def wrapFunction():
         print("some decorator logic before.")
         function()
         print("some decorator logic after.\n")

    return wrapFunction

@decor
def foo():
    print("The decorated foo function.")

print(foo.__name__, end="\n\n")


# The decorator with arguments.
def showArgs(func):
    @wraps(func)
    def wrap(*args, **kwargs):
        args_list = list(args)
        kwargs_list = dict(kwargs)
        print("args: ", args_list)
        print("kwargs: ", kwargs_list)
        return func(*args, **kwargs)
    return wrap

@showArgs
def add(x, y):
    return x + y

print(add(2, 4))

@showArgs
def mul(x, y, name):
    return x * y

print(mul(3, 3, name="NEW"))
