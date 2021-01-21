# Creation.

empty_btarr = bytearray()
zero_filled = bytearray(10)
from_iterable = bytearray([97, 98, 99, 100, 101])
use_buffer_protocol = bytearray(b"Hello World!")


# Operators.

b"h" in use_buffer_protocol  # False.
b"H" in use_buffer_protocol  # True.

use_buffer_protocol[0]  # 72.
use_buffer_protocol[:5]  # bytearray(b'Hello')
use_buffer_protocol[:5:2]  # bytearray(b'Hlo')


# Methods.

from_hex = bytearray().fromhex("fa0113a9bb")  # noqa bytearray(b'\xfa\x01\x13\xa9\xbb').
from_iterable.hex()  # '6162636465'.

sub = use_buffer_protocol.count(bytes(b"l"))  # 3. Count.
new_str = use_buffer_protocol.decode()  # "Hello World!".
from_iterable.decode()  # 'abcde'.

from_iterable.endswith(b"e")  # True.
from_iterable.startwith(b"e")  # False.
from_iterable.startwith(b"a")  # True.

use_buffer_protocol.find(b"b")  # -1.
use_buffer_protocol.find(b"l")  # 2.
use_buffer_protocol.find(101)  # 1.
from_iterable.find(99)  # 2.

use_buffer_protocol.rfind(b"l")  # 9.
use_buffer_protocol.rfind(101)  # 1.

use_buffer_protocol.index(b"b")  # raise ValueError.
use_buffer_protocol.index(101)  # 1.
from_iterable.index(99)  # 2.

use_buffer_protocol.rindex(b"b")  # raise ValueError.
use_buffer_protocol.rindex(101)  # 1.

joined = b"-".join([b"this", b"is", b"joined", b"bytes."])

three_tuple = joined.partition(b"-")  # noqa (b'this', b'-', b'is-joined-bytes.').
rthree_tuple = joined.rpartition(b"-")  # noqa (b'bytes.', b'-', b'this-is-joined').

replaced = joined.replace(b"-", b"_")  # b'this_is_joined_bytes.'.

from_iterable.center(7)  # bytearray(b" abcde ").
from_iterable.center(7, b".")  # bytearray(b".abcde.").
from_iterable.ljust(7, b".")  # bytearray(b"bcde..").
from_iterable.rjust(7, b".")  # bytearray(b"..bcde").

splitted = joined.split(b"-")  # [b'this', b'is', b'joined', b'bytes.'].
r_splitted = joined.rsplit(b"-", 2)  # [b'this-is', b'joined', b'bytes.'].
l_splitted = joined.lsplit(b"-", 2)  # [b'this', b'is', b'joined-bytes.'].

b"   some    ".strip()  # b"some".
b"   some    ".rstrip()  # b"   some".
b"   some    ".lstrip()  # b"some   ".


# Global table printing.
import pprint  # noqa
pprint.pprint(globals())
