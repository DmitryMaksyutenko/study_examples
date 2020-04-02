# -*- encoding: utf-8 -*-
import unittest

import errors


class ErorrsTests(unittest.TestCase):
    """Test cases for copy errors."""

    def test_base_error(self):
        """Tests BaseCopyException class."""
        self.assertTrue("This is the default message of the base error class.",
                        errors.BaseCopyException())

    def test_no_arguments(self):
        """Tests NoArgumentsPassed class."""
        self.assertTrue("No arguments passed.",
                        errors.NoArgumentsPassed())
