import a1
import unittest


class TestSwapK(unittest.TestCase):
    """ Test class for function a1.swap_k. """

    def test_swap_k_2_elem_list_6(self):
        """
        Test the function with the list of six elements,
        and two elements to swop.
        Swaps two first elements with two last elements in the passed list.
        """
        nums = [1, 2, 3, 4, 5, 6]
        swapped_list = [5, 6, 3, 4, 1, 2]

        a1.swap_k(nums, 2)

        self.assertEqual(nums, swapped_list)

    def test_swap_k_1_elem_list_3(self):
        """
        Test the function with the list of three elements,
        and one element to swop.
        Swaps element with last element in the passed list.
        """
        nums = [1, 2, 3]
        swapped_list = [3, 2, 1]

        a1.swap_k(nums, 1)

        self.assertEqual(nums, swapped_list)

    def test_swap_k_2_elem_list_3(self):
        """
        Test the function with the list of three elements,
        and two elements to swop.
        The list will be extended.
        """
        nums = [1, 2, 3]
        swapped_list = [2, 3, 1, 2]

        a1.swap_k(nums, 2)

        self.assertEqual(nums, swapped_list)

    def test_swap_k_3_elem_list_3(self):
        """
        Test the function with the list of three elements,
        and three elements to swop.
        The list will be extended.
        """
        nums = [1, 2, 3]
        swapped_list = [1, 2, 3, 1, 2, 3]

        a1.swap_k(nums, 3)

        self.assertEqual(nums, swapped_list)

    def test_swap_k_4_elem_list_3(self):
        """
        Test the function with the list of three elements,
        and four elements to swop.
        The list will not be changed.
        """
        nums = [1, 2, 3]
        swapped_list = [1, 2, 3]

        a1.swap_k(nums, 4)

        self.assertEqual(nums, swapped_list)


if __name__ == '__main__':
    unittest.main(exit=False)
