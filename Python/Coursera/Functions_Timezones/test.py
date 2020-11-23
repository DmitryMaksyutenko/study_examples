import a1


def test_second_difference():
    function_result_1 = a1.seconds_difference(1800.0, 3600.0)
    function_result_2 = a1.seconds_difference(3600.0, 1800.0)
    function_result_3 = a1.seconds_difference(1800.0, 2160.0)
    function_result_4 = a1.seconds_difference(1800.0, 1800.0)
    assert type(function_result_1) is float
    assert function_result_1 == 1800.0
    assert function_result_2 == -1800.0
    assert function_result_3 == 360.0
    assert function_result_4 == 0.0


def test_hours_difference():
    function_result_1 = a1.hours_difference(1800.0, 3600.0)
    function_result_2 = a1.hours_difference(3600.0, 1800.0)
    function_result_3 = a1.hours_difference(1800.0, 2160.0)
    function_result_4 = a1.hours_difference(1800.0, 1800.0)
    assert type(function_result_1) is float
    assert function_result_1 == 0.5
    assert function_result_2 == -0.5
    assert function_result_3 == 0.1
    assert function_result_4 == 0.0


def test_to_float_hours():
    function_result_1 = a1.to_float_hours(0, 15, 0)
    function_result_2 = a1.to_float_hours(2, 45, 9)
    function_result_3 = a1.to_float_hours(1, 0, 36)
    assert type(function_result_1) is float
    assert function_result_1 == 0.25
    assert function_result_2 == 2.7525
    assert function_result_3 == 1.01


def test_to_24_hour_clock():
    function_result_1 = a1.to_24_hour_clock(24)
    function_result_2 = a1.to_24_hour_clock(48)
    function_result_3 = a1.to_24_hour_clock(25)
    function_result_4 = a1.to_24_hour_clock(4)
    function_result_5 = a1.to_24_hour_clock(28.5)
    assert type(function_result_1) is int or float
    assert function_result_1 == 0
    assert function_result_2 == 0
    assert function_result_3 == 1
    assert function_result_4 == 4
    assert function_result_5 == 4.5


def test_get_hours():
    function_result_1 = a1.get_hours(3800)
    function_result_2 = a1.get_hours(14400)
    function_result_3 = a1.get_hours(32400)
    assert type(function_result_1) is int
    assert function_result_1 == 1
    assert function_result_2 == 4
    assert function_result_3 == 9


def test_get_minutes():
    function_result_1 = a1.get_minutes(3800)
    function_result_2 = a1.get_minutes(4000)
    function_result_3 = a1.get_minutes(42000)
    assert type(function_result_1) is int
    assert function_result_1 == 3
    assert function_result_2 == 6
    assert function_result_3 == 40


def test_get_seconds():
    function_result_1 = a1.get_seconds(3800)
    function_result_2 = a1.get_seconds(1432)
    function_result_3 = a1.get_seconds(4000)
    assert type(function_result_1) is int
    assert function_result_1 == 20
    assert function_result_2 == 52
    assert function_result_3 == 40


def test_time_to_utc():
    function_result_1 = a1.time_to_utc(+0, 12.0)
    function_result_2 = a1.time_to_utc(+1, 12.0)
    function_result_3 = a1.time_to_utc(-1, 12.0)
    function_result_4 = a1.time_to_utc(-11, 18.0)
    function_result_5 = a1.time_to_utc(-1, 0.0)
    function_result_6 = a1.time_to_utc(-1, 23.0)
    assert type(function_result_1) is float
    assert function_result_1 == 12.0
    assert function_result_2 == 11.0
    assert function_result_3 == 13.0
    assert function_result_4 == 5.0
    assert function_result_5 == 1.0
    assert function_result_6 == 0.0


def test_time_form_utc():
    function_result_1 = a1.time_from_utc(+0, 12.0)
    function_result_2 = a1.time_from_utc(+1, 12.0)
    function_result_3 = a1.time_from_utc(-1, 12.0)
    function_result_4 = a1.time_from_utc(+6, 6.0)
    function_result_5 = a1.time_from_utc(-7, 6.0)
    function_result_6 = a1.time_from_utc(-1, 0.0)
    function_result_7 = a1.time_from_utc(-1, 23.0)
    function_result_8 = a1.time_from_utc(+1, 23.0)
    assert type(function_result_1) is float
    assert function_result_1 == 12.0
    assert function_result_2 == 13.0
    assert function_result_3 == 11.0
    assert function_result_4 == 12.0
    assert function_result_5 == 23.0
    assert function_result_6 == 23.0
    assert function_result_7 == 22.0
    assert function_result_8 == 0.0
