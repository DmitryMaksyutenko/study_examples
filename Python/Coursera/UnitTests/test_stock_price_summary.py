import a1
import unittest


class TestStockPriceSummary(unittest.TestCase):
    """ Test class for function a1.stock_price_summary. """

    def test_stoc_price_summary_ganes_and_losses(self):
        """
        Test the function with list of different float numbers.
        The result must contain more losses the gains.
        """
        prices = [0.01, 0.03, -0.02, -0.14, 0, 0, 0.10, -0.01]
        summary = (0.14, -0.17)

        sum_from_func = a1.stock_price_summary(prices)

        self.assertEqual(summary, sum_from_func)

    def test_stoc_price_summary_losses(self):
        """
        Test the function with list filled with losses only.
        The result must contain zero value of gains and sum of losses.
        """
        prices = [-0.03, -0.14, -0.01]
        summary = (0, -0.18)

        sum_from_func = a1.stock_price_summary(prices)

        self.assertEqual(summary, sum_from_func)

    def test_stoc_price_summary_gains(self):
        """
        Test the function with list filled with gaines only.
        The result must contain sum of gaines and zero losses.
        """
        prices = [0.03, 0.14, 0.01, 0.05]
        summary = (0.23, 0)

        sum_from_func = a1.stock_price_summary(prices)

        self.assertEqual(summary, sum_from_func)

    def test_stoc_price_summary_empty_list(self):
        """
        Test the function with empty list.
        The reustl must contain zero gains and zero losses.
        """
        prices = []
        summary = (0, 0)

        sum_from_func = a1.stock_price_summary(prices)

        self.assertEqual(summary, sum_from_func)


if __name__ == '__main__':
    unittest.main(exit=False)
