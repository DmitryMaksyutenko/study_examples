def print_ints(n):
    """ (int) -> NoneType

    Print the integers from 1 to n, inclusive.
    """

    for i in range(1, n + 1):
        print(i)

# Output:
# >>> print_ints(10)
# 1
# 2
# 3
# 4
# 5
# 6
# 7
# 8
# 9
# 10

# When the function is called, the value that n refers to is equal
# to the number of items printed:
# when n refers to 10, it prints 10 integers
# when n refers to 20, it prints 20 integers
# when n refers to 40, it prints 40 integers

# The number of steps is proportional to n.
