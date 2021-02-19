def print_double_step(n):
    """ (int) -> NoneType

    Print integers from 1 to n inclusive, with an initial
    step size of 1 and each subsequent step size being
    twice as large as it was previously.
    """

    i = 1
    while i < n + 1:
        print(i)
        i = i * 2

# In this example, the step size varies.
# It size of the first step is 1,
# the next step would be 2, then 4, 8, 16, 32...

# How many values would be printed for different values of n?

# Output 1:
# >>> print_double_step(4)
# 1
# 2
# 4
# When n refers to 4, 3 integers are printed.

# Output 2:
# >>> print_double_step(5)
# 1
# 2
# 4
# When n refers to 5, 3 integers are printed.

# It's not until n refers to 8 that more than 3 integers are printed.

# Output 3:
# >>> print_double_step(8)
# 1
# 2
# 4
# 8
# When n refers to values 8 to 15, there will be 4 integers printed.

# When n refers to 16, 5 integers are printed.
# When n refers to 32, 6 integers are printed.
# When n refers to 64, 8 integers are printed.

# Starting with n referring to 1, each time that n is doubled,
# it prints one extra line.

# This function is logarithmic and as the input size increases,
# the running time grows more slowly than for linear and quadratic functions.
