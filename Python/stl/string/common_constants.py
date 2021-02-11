import string

letters = string.ascii_letters
lowercase = string.ascii_lowercase
uppercase = string.ascii_uppercase
digits = string.digits
hexdigits = string.hexdigits
octdigits = string.octdigits
punctioation = string.punctuation
printable = string.printable
whitespace = string.whitespace


# Printing global table.
import pprint  # noqa.
filtered = {k: v for k, v in globals().items() if not k.startswith("__")}
pprint.pprint(filtered)
