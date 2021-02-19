def print_pairs(n):
    """ (int) -> NoneType

    Print all combinations of pairs of integers 1 to n, inclusive.
    """

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            print(i, j)

# Output 1:
# >>> print_pairs(2)
# 1 1
# 1 2
# 2 1
# 2 2
# The function call above prints 4 pairs of integers.

# Output 2:
# >>> print_pairs(3)
# 1 1
# 1 2
# 1 3
# 2 1
# 2 2
# 2 3
# 3 1
# 3 2
# 3 3
# The function call above prints 9 pairs of integers.

# Output 3:
# >>>print_pairs(4)
# 1 1
# 1 2
# 1 3
# 1 4
# 2 1
# 2 2
# 2 3
# 2 4
# 3 1
# 3 2
# 3 3
# 3 4
# 4 1
# 4 2
# 4 3
# 4 4
# The function call above prints 16 pairs of integers.

# For argument n, the print function is called n2 times.

# When reading the code, notice that the print function call
# is inside a for loop, which loops n times. This for loop
# is also within a for loop that executes n times.

# Therefore:
# n (outside loop iterations) * n (inside loop iterations) = n2 iterations
