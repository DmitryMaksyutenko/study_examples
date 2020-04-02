# -*- coding: utf-8 -*-
from errors import FileForCopyFromNotFound

class Copy:
    """Copy content from one file to another."""

    def __init__(self, file_from, file_to):
        """Class constructor.

        Attributes:
        file_from - file for copy.
        file_to - file for copy to.
        """
        try:
            self.fd_from = open(file_from)
        except FileNotFoundError as e:
            raise FileForCopyFromNotFound

        self.fd_to = open(file_to, "w")


    def make_copy(self):
        """Copy context from one file to another."""

        readed = self.fd_from.read()
        self.fd_to.write(readed)

        self.fd_from.close()
        self.fd_to.close()