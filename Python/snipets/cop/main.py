# -*- coding: utf-8 -*-

import errors
from argparser import ArgParser
from copy import Copy

if __name__ == "__main__":

    try:
        arg_parser = ArgParser()
        file_from = arg_parser.get_from()
        file_to = arg_parser.get_to()

        copy = Copy(file_from, file_to)
        copy.make_copy()

    except (errors.NoArgumentsPassed,
            errors.ToManyArgumentsPassed,
            errors.NotMuchArgumentsCount,
            errors.FileForCopyFromNotFound) as e:
        print(e.message)