# Creation.

empty_bytes = b''
empty_bytes = b""
empty_bytes = b""""""
empty_bytes = bytes()
zeros = bytes(10)
int_bytes = bytes([1, 2, 3, 4])
letters = b"abcd"
sentence = b"The quick brown fox jumps over the lazy dog"


# Operators.

b"a" in letters  # True.
b"a" not in letters  # False.
b"e" not in letters  # True.

c_letter = letters[2]  # 99.
letters[:2]  # b"ab".

letters + b"gre"  # b"abcgre".
letters * 2  # b"abcdabcd".


# Methods.

from_hex = bytes.fromhex("FFFF A12A")
sentence.count(b"o")  # 4.
sentence.decode()  # utf-8.
sentence.endswith(b"dog")  # True.
sentence.startswith(b"The")  # True.
sentence.find(b"ox")  # 17.
sentence.rfind(b"o")  # 41.
sentence.index(b"ov")  # 25. raise ValuseError.
sentence.rindex(b"o")  # 41. raise ValueError.
b"-".join([b"a", b"b", b"c"])  # b"a-b-c".
trantable = bytes.maketrans(letters, int_bytes)
sentence.translate(trantable)
letters.partition(b"b")  # (b"a", b"b", b"cd").
letters.rpartition(b"c")  # (b"ab", b"c", b"d").
sentence.replace(b"o", b"X")
letters.center(8, b".")  # b"..abcd..".
letters.ljust(8, b"-")  # b"abcd----".
letters.rjust(8, b"-")  # b"----abcd".
b"    abc    ".strip()  # b"abc".
sentence.strip(b"godheT")  # b' quick brown fox jumps over the lazy '
b"    abc    ".lstrip()  # b"abc    ".
b"    abc    ".rstrip()  # b"    abc".
sentence.split(b"o")
letters.capitalize()  # b"Abcd".
b"a\tb\tc".expandtabs(4)  # b"a    b    c".
b'ABCabc1'.isalnum()  # True.
b'ABCabc1'.isalpha()  # False.
b'ABCabc1'.isascii()  # True.
b'ABCabc1'.isdigit()  # False.
b'ABCabc1'.islower()  # False.
b'ABCabc1'.isupper()  # False.
b'ABCabc1'.isspace()  # False.
b'ABCabc1'.istitle()  # True.
b'ABCabc1'.lower()  # b"abcabc1".
b'ABCabc1'.upper()  # b"ABCABC1".
b'ab c\n\nde fg\rkl\r\n'.splitlines()  # list of lines.
b'ABCabc1'.swapcase()  # b"cbaCBA1".
b"bbc abc".title()  # b"Bbc Abc".
b"abc".zfill(5)  # b"00abc".

# Printng the global table.
import pprint  # noqa.
pprint.pprint(globals())
