# -*- coding: utf-8 -*-
import sys

from errors import NoArgumentsPassed, ToManyArgumentsPassed, \
                    NotMuchArgumentsCount


class ArgParser:
    """The parser class for the arguments.

    Attributes:
        argc - arguments count.
        argv - arguments list.
    """

    def __init__(self):
        if len(sys.argv) <= 1:
            raise NoArgumentsPassed
        if len(sys.argv) == 2:
            raise NotMuchArgumentsCount
        if len(sys.argv) > 3:
            raise ToManyArgumentsPassed

        self.argc = len(sys.argv)
        self.argv = sys.argv

    def get_from(self):
        """Return the file for copy."""
        return self.argv[1]

    def get_to(self):
        """Return the file copie to."""
        return self.argv[2]
