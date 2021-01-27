# Creation.

empty_str = ''
empty_str = ""
empty_str = """"""
first_name = "John"
last_name = "Smith"
empty_str = str()
b_abc = str(b"abc")  # "b'abc'".
b_abc = str(b"abc", "utf-8")  # "abc".
seven = str(7)  # "7".
brackets = str([])  # "[]".
class_int = str(int)  # "<class 'int'>".


# Operators.

"a" in b_abc  # True.
"R" not in b_abc  # True.
"J" in b_abc  # False.
full_name = first_name + " " + last_name
triple_seven = seven * 3

"abc" == b_abc  # True.
"abc " == b_abc  # False.
"abc " != b_abc  # True.

o_from_name = first_name[1]
Joh_part = first_name[:3]
ith_part = last_name[2:]
Sih_from_last_name = last_name[::2]


# Methods.

ABC = b_abc.upper()  # "Abc".
ABC.lower()  # "abc"
Abc = b_abc.capitalize()  # "Abc".
title = "hello world".title()  # "Hello World".
title.swapcase()  # "hELLO wORLD".

classname = "ClassName".casefold()  # "classname".
___abc___ = b_abc.center(9, "_")  # "___abc___".
ab_count = "abracadabra".count("ab")  # 2.
byn_abc = b_abc.encode()  # b"abc".

first_name.endswith("hn")  # True.
first_name.startswith("Jo")  # True.

exp_tabs = """ some
string
for test\t end""".expandtabs(2)

S_index = full_name.find("S")  # 5.
"la la la ".rfind("la")  # 6.
S_index = full_name.index("S")  # 5. Otherwise raise ValueError.
"la la la ".rindex("la")  # 6. Otherwise raise ValueError.

"format {0}".format("string")  # "format string".
value_from_dict = "The {key} is a value from dict".format_map({"key": "value"})

(seven + ABC + b_abc).isalnum()  # True.
(seven + ABC + b_abc + brackets).isalnum()  # False.
(ABC + b_abc).isalpha()  # True.
(ABC + b_abc + seven).isalpha()  # False.
(seven + ABC + b_abc + brackets).isascii()  # True.
(seven + ABC + b_abc + brackets + chr(15755)).isascii()  # False.
seven.isdecimal()  # True.
seven.isdigit()  # True.
seven.isidentifier()  # False.
b_abc.isidentifier()  # True.
b_abc.islower()  # True.
ABC.islower()  # False.
ABC.isupper()  # True.
ABC.isnumeric()  # False.
seven.isnumeric()  # True.
"    ".isspace()  # True.
"a    ".isspace()  # False.
"Title".istitle()  # True.

" ".join("abc")  # "a b c".

"   abc   ".strip()  # "abc".
"   abc   ".lstrip()  # "abc   ".
"www.example.com".lstrip('cmowz.')  # "example.com".
"   abc   ".rstrip()  # "   abc".

full_name.partition(" ")  # ("John", " ", "Smith").
"string for partition.".rpartition("i")  # ('string for partit', 'i', 'on.').

full_name.replace(" ", "_")  # "John_Smith".

"abc".rjust(5, ".")  # "..abc".

"a,b,c".split(",")  # ["a", "b", "c"]

"142".zfill(6)  # "000142".


# Printing the global table.
import pprint  # noqa.
pprint.pprint(globals())
