import math
from itertools import filterfalse


def num_buses(n):
    """ (int) -> int

    Precondition: n >= 0

    Return the minimum number of buses required to transport n people.
    Each bus can hold 50 people.

    >>> num_buses(75)
    2
    >>> num_buses(0)
    0
    >>> num_buses(10)
    1
    >>> num_buses(50)
    1
    >>> num_buses(150)
    3
    """
    return math.ceil(n / 50)


def stock_price_summary(price_changes):
    """ (list of number) -> (number, number) tuple

    price_changes contains a list of stock price changes. Return a 2-item
    tuple where the first item is the sum of the gains in price_changes and
    the second is the sum of the losses in price_changes.

    >>> stock_price_summary([0.01, 0.03, -0.02, -0.14, 0, 0, 0.10, -0.01])
    (0.14, -0.17)
    >>> stock_price_summary([-0.03, -0.14, -0.01])
    (0.0, -0.18)
    >>> stock_price_summary([0.03, 0.14, 0.01, 0.05])
    (0.23, 0.0)
    >>> stock_price_summary([])
    (0.0, 0.0)
    """
    gain = sum(filterfalse(lambda x: x < 0, price_changes))
    loss = sum(filterfalse(lambda x: x > 0, price_changes))

    return (float("{:.2f}".format(gain)), float("{:.2f}".format(loss)))


def swap_k(L, k):
    """ (list, int) -> NoneType

    Precondtion: 0 <= k <= len(L) // 2

    Swap the first k items of L with the last k items of L.

    >>> nums = [1, 2, 3, 4, 5, 6]
    >>> swap_k(nums, 2)
    >>> nums
    [5, 6, 3, 4, 1, 2]
    >>> nums = [1, 2, 3]
    >>> swap_k(nums, 1)
    >>> nums
    [3, 2, 1]
    >>> swap_k(nums, 2)
    >>> nums
    [2, 3, 1, 2]
    >>> nums = [1, 2, 3]
    >>> swap_k(nums, 3)
    >>> nums
    [1, 2, 3, 1, 2, 3]
    >>> nums = [1, 2, 3]
    >>> swap_k(nums, 4)
    >>> nums
    [1, 2, 3]
    """
    if k > len(L):
        return

    first_nums = L[:k]
    last_nums = L[-k:]
    middle = L[k:-k]
    L.clear()
    L.extend(last_nums + middle + first_nums)


if __name__ == '__main__':
    import doctest
    doctest.testmod()
