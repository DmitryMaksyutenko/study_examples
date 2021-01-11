# The "with" statement is used to wrapp the execution of a block with
# methods defined by a context manager. This allows common
# try...except...finaly usage pattern to be encapsulated for convinient reuse.

# A "context manager" is an object that defines the runtime context to be
# established when executing "with" statement. It's handles the entry info,
# and the exit form, the desired runtime context for the execution of the
# block of code. Normaly invoked using the "with" key word, but cal also be
# used by directly invoking it's methods.

#   contextmanager.__enter__()
#   contextmanager.__exit__()

# That methods allows user-defined classes to define a runtime context
# that is enterd defore the statement body is executed and exit when
# the statement ends.

# The "contextlib" module provides utilities for common tasks involving
# the with statement.


# The execution of the with statement with one “item” proceeds as follows:
# 1. The context expression is evaluated to obtain a context manager.
# 2. The context manager’s __enter__() is loaded for later use.
# 3. The context manager’s __exit__() is loaded for later use.
# 4. The context manager’s __enter__() method is invoked.
# 5. If a target was included in the with statement, the return value from
# __enter__() is assigned to it.

#   Note: The with statement guarantees that if the __enter__() method returns
#   without an error, then __exit__() will always be called.
#   Thus, if an error occurs during the assignment to the target list, it will
#   be treated the same as an error occurring within the suite would be.

# 6. The suite is executed.

# 7. The context manager’s __exit__() method is invoked. If an exception caused
# the suite to be exited, its type, value, and traceback are passed as
# arguments to __exit__(). Otherwise, three None arguments are supplied.

# If the suite was exited due to an exception, and the return value from
# the __exit__() method was false, the exception is reraised.
# If the return value was true, the exception is suppressed, and execution
# continues with the statement following the with statement.

# If the suite was exited for any reason other than an exception, the return
# value from __exit__() is ignored, and execution proceeds at the normal
# location for the kind of exit that was taken.


#    with EXPRESSION as TARGET:
#      SUITE

# equvivalent to:
#   manager = (EXPRESSION)
#   enter = type(manager).__enter__
#   exit = type(manager).__exit__
#   value = enter(manager)
#   hit_except = False

#   try:
#       TARGET = value
#       SUITE
#   except:
#       hit_except = True
#       if not exit(manager, *sys.exc_info()):
#           raise
#   finally:
#       if not hit_except:
#           exit(manager, None, None, None)


#    with A() as a, B() as b:
#      SUITE

# equvivalent to:
#   with A() as a:
#       with B() as b:
#           SUITE
from contextlib import contextmanager


def get_lines_from_file(file_name):
    """Read file and return list of lines."""
    with open(file_name, "r") as fd:
        lines = fd.readlines()
    return lines


class TestPrint:

    def test_print(self):
        print("TestPrint class test_print method.")

    def __enter__(self):
        print("TestPrint class __enter__() method.")
        self.test_print()

    def __exit__(self, type, value, traceback):
        print("TestPrint class __exit__() method.")
        self.test_print()
        return True


class ReadLinesFromFile:

    def __init__(self, file_name):
        self.file = file_name
        self.fd = None

    def __enter__(self):
        self.fd = open(self.file, "r")
        return self.fd.readlines()

    def __exit__(self, type, value, traceback):
        self.fd.close()
        return True


@contextmanager
def read_lines(feile_name):
    try:
        fd = open(feile_name)
        lines = fd.readlines()
    except FileNotFoundError as e:
        raise e
    else:
        yield lines
    finally:
        fd.close()
