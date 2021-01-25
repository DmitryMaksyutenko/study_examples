# Creation.

zero = 0.0
zero = float(0)
inf = float("infinity")
nan = float("nan")
one = float(+1.0)
two = float("2")
three = float("3e0")
twenty = float("2e1")
minus_one = float(-1)


# Operators.

one + two  # 3.0.
three - one  # 2.0.
two * two  # 4.0.
twenty / two  # 10.0.
twenty // two  # 10.0.
twenty % three  # 2.0.


# Print global names table.
import pprint  # noqa
pprint.pprint(globals())
