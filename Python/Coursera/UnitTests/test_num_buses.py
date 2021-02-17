import a1
import unittest


class TestNumBuses(unittest.TestCase):
    """ Test class for function a1.num_buses. """

    def test_num_buses_with_75_people(self):
        """
        Test function with seventy five peoples.
        For that count of people requires 2 busses.
        """
        peoples = 75
        buses_required = 2

        buses = a1.num_buses(peoples)

        self.assertEqual(buses_required, buses)

    def test_num_buses_with_0_people(self):
        """
        Test function with zero peoples.
        For that count of people requires no busses.
        """
        peoples = 0
        buses_required = 0

        buses = a1.num_buses(peoples)

        self.assertEqual(buses_required, buses)

    def test_num_buses_with_10_people(self):
        """
        Test function with ten peoples.
        For that count of people requires 1 busses.
        """
        peoples = 10
        buses_required = 1

        buses = a1.num_buses(peoples)

        self.assertEqual(buses_required, buses)

    def test_num_buses_with_50_people(self):
        """
        Test function with fifty peoples.
        For that count of people requires 1 busses.
        """
        peoples = 50
        buses_required = 1

        buses = a1.num_buses(peoples)

        self.assertEqual(buses_required, buses)

    def test_num_buses_with_150_people(self):
        """
        Test function with one hundred and fifty peoples.
        For that count of people requires 3 busses.
        """
        peoples = 150
        buses_required = 3

        buses = a1.num_buses(peoples)

        self.assertEqual(buses_required, buses)


if __name__ == '__main__':
    unittest.main(exit=False)
