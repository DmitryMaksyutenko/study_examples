# Creation.

zero = complex()
one = 1+1j
two = complex(2, 2)
three = complex("3+3j")


# Operators.

four = one + three  # (4+4j).
seven = four + three  # (7+7j).
five = seven - two  # (5+5j).
negative_one = one - two  # (-1-1j).
two * two  # (4+4j).
four / two  # (2+2j).


# Methods.

real_one = one.real  # 1.0.
imag_one = one.imag  # 1.0.
conjugate_one = one.conjugate()


# Print the global table names.
import pprint  # noqa
pprint.pprint(globals())
