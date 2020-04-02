# -*- coding: utf-8 -*-


class BaseCopyException(Exception):
    """ The base Exeption class for the application.

    Attributes:
        message - the default class error message.
    """

    def __init__(self):
        self.message = "This is the default message of the base error class."


class NoArgumentsPassed(BaseCopyException):
    """Exception raised in case no arguments passed."""
    def __init__(self):
        self.message = "No arguments passed."


class ToManyArgumentsPassed(BaseCopyException):
    """Exception raised in case more then two arguments passed."""
    def __init__(self):
        self.message = "To many arguments passed."


class NotMuchArgumentsCount(BaseCopyException):
    """Excaption raised in case one argument passed."""
    def __init__(self):
        self.message = "Not enough arguments."


class FileForCopyFromNotFound(BaseCopyException):
    """Excaption reaised in case file for copy from is not found."""
    def __init__(self):
        self.message = "File for copy from not found."
