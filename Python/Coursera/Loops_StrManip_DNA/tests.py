import a2


atcg = "ATCG"
atcgat = "ATCGAT"
atcta = "atcta"
at = "AT"
atcg = "ATCG"
atcgga = "ATCGGA"


def test_get_length():
    atcgat_len = len(atcgat)
    atcg_len = len(atcg)

    length_1 = a2.get_length(atcgat)
    length_2 = a2.get_length(atcg)

    assert type(length_1) is int
    assert length_1 == atcgat_len
    assert length_2 == atcg_len


def test_is_longer():
    atcg_longer_at = True
    atcg_shorter_atcgga = False

    res_1 = a2.is_longer(atcg, at)
    res_2 = a2.is_longer(atcg, atcgga)

    assert type(res_1) is bool
    assert res_1 == atcg_longer_at
    assert res_2 == atcg_shorter_atcgga


def test_count_nucleotides():
    num_1 = a2.count_nucleotides(atcgga, "G")
    num_2 = a2.count_nucleotides(atcta, "G")
    assert type(num_1) is int
    assert num_1 == 2
    assert num_2 == 0


def test_contains_sequence():
    res_1 = a2.contains_sequence(atcgga, "GG")
    res_2 = a2.contains_sequence(atcgga, "GT")
    assert type(res_1) is bool
    assert res_1 is True
    assert res_2 is False


def test_is_valid_sequence():
    res_1 = a2.is_valid_sequence(atcgga)
    res_2 = a2.is_valid_sequence(atcg)
    res_3 = a2.is_valid_sequence(atcg + "a")
    res_4 = a2.is_valid_sequence(atcg + "XV")
    assert type(res_1) is bool
    assert res_1 is True
    assert res_2 is True
    assert res_3 is False
    assert res_4 is False


def test_insert_sequence():
    res_1 = a2.insert_sequence(atcg, "AT", 2)
    res_2 = a2.insert_sequence(atcgga, "ATA", 1)
    res_3 = a2.insert_sequence(at, "GGG", 2)
    assert type(res_1) is str
    assert res_1 == "ATATCG"
    assert res_2 == "AATATCGGA"
    assert res_3 == "ATGGG"


def test_get_complement():
    res_1 = a2.get_complement("A")
    res_2 = a2.get_complement("T")
    res_3 = a2.get_complement("G")
    res_4 = a2.get_complement("C")
    assert type(res_1) is str
    assert res_1 == "T"
    assert res_2 == "A"
    assert res_3 == "C"
    assert res_4 == "G"


def test_get_complementary_sequence():
    res_1 = a2.get_complementary_sequence(atcg)
    res_2 = a2.get_complementary_sequence(at)
    res_3 = a2.get_complementary_sequence(atcgga)
    assert type(res_1) is str
    assert res_1 == "TAGC"
    assert res_2 == "TA"
    assert res_3 == "TAGCCT"
