# Creation.

one = 1
two = int(2)
zero = int()
dec_101 = int("101")
bin_5 = int("101", 2)
oct_11 = int("13", 8)
hex_15 = int("F", 16)


# Operators.

one + two  # 3.
two - one  # 1.
two * two  # 4.
hex_15 / two  # 7.5.
hex_15 // two  # 7.
bin_5 % two  # 1.
negative_one = -1


# Bitwise operator.

one | two  # 3.
one | one  # 1.
one ^ two  # 3.
one ^ one  # 0.
one & one  # 1.
one & two  # 0.
one << 3  # 8.
one >> 3  # 0.
10 >> 3  # 1.
~10  # -11.


# Methods.

one.bit_length()  # 1.
hex_15.bit_length()  # 4.

one.to_bytes(2, byteorder="big")  # b"\x00\x01".
hex_15.to_bytes(2, byteorder="big")  # b"\x00\x0f".
hex_15.to_bytes(2, byteorder="little")  # b"\xf0\x00".

int.from_bytes(b"\x02", byteorder="big")  # 2.
int.from_bytes(b"\x01\x02", byteorder="big")  # 258.

one.as_integer_ratio()  # (1, 1).


# Global table printing.
import pprint  # noqa
pprint.pprint(globals())
