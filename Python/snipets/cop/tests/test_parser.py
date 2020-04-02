# -*- coding: utf-8 -*-
import sys
import unittest

import argparser


class ParserTests(unittest.TestCase):

    def setUp(self):
        """Fixture."""
        sys.argv[1] = "f.txt"
        sys.argv[2] = "t.txt"

    def test_get_from_method(self):
        """Test get_from() method."""
        pars = argparser.ArgParser()

        self.assertEqual(sys.argv[1], pars.get_from())

    def test_get_to_method(self):
        """Tests get_to() method."""
        pars = argparser.ArgParser()

        self.assertEqual(sys.argv[2], pars.get_to())
