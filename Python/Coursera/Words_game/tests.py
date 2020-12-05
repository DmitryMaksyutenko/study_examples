import a3

BOARD = [['A', 'N', 'T', 'T'], ['X', 'S', 'O', 'B']]
WORD_LIST = ['ANT', 'BOX', 'SOB', 'TO']


def test_is_valid_word():
    res_1 = a3.is_valid_word(WORD_LIST, "TO")
    res_2 = a3.is_valid_word(WORD_LIST, "tot")
    res_3 = a3.is_valid_word(WORD_LIST, "ant")

    assert type(res_1) is bool
    assert res_1 is True
    assert res_2 is False
    assert res_3 is False


def test_make_str_from_row():
    res_1 = a3.make_str_from_row(BOARD, 0)
    res_2 = a3.make_str_from_row(BOARD, 1)

    assert type(res_1) is str
    assert res_1 == "ANTT"
    assert res_2 == "XSOB"


def test_make_str_form_column():
    res_1 = a3.make_str_from_column(BOARD, 1)
    res_2 = a3.make_str_from_column(BOARD, 0)
    res_3 = a3.make_str_from_column(BOARD, 3)

    assert type(res_1) is str
    assert res_1 == "NS"
    assert res_2 == "AX"
    assert res_3 == "TB"


def test_board_contains_word_in_row():
    res_1 = a3.board_contains_word_in_row(BOARD, "SOB")
    res_2 = a3.board_contains_word_in_row(BOARD, "SOX")

    assert type(res_1) is bool
    assert res_1 is True
    assert res_2 is False


def test_board_contains_word_in_column():
    res_1 = a3.board_contains_word_in_column(BOARD, "NO")
    res_2 = a3.board_contains_word_in_column(BOARD, "AX")

    assert type(res_1) is bool
    assert res_1 is False
    assert res_2 is True


def test_board_contains_word():
    res_1 = a3.board_contains_word(BOARD, "ANT")
    res_2 = a3.board_contains_word(BOARD, "NS")
    res_3 = a3.board_contains_word(BOARD, "NSA")

    assert type(res_1) is bool
    assert res_1 is True
    assert res_2 is True
    assert res_3 is False


def test_word_scope():
    res_1 = a3.word_score("DRUDGERY")
    res_2 = a3.word_score("DR")
    res_3 = a3.word_score("DRS")
    res_4 = a3.word_score("DRSREDFTYR")

    assert type(res_1) is int
    assert res_1 == 16
    assert res_2 == 0
    assert res_3 == 3
    assert res_4 == 30


def test_update_score():
    player_1 = ['Jonathan', 4]
    player_2 = ['Jon', 1]

    a3.update_score(player_1, "ANT")
    a3.update_score(player_2, "ANT")

    assert player_1[1] == 7
    assert player_2[1] == 4


def test_num_words_on_board():
    res_1 = a3.num_words_on_board(BOARD, WORD_LIST)
    res_2 = a3.num_words_on_board(BOARD, ["AS", "BOX", "SOB", "TO"])

    assert type(res_1) is int
    assert res_1 == 3
    assert res_2 == 2


def test_read_words():
    res_1 = a3.read_words("wordlist1.txt")

    with open("wordlist1.txt") as f:
        words_list = f.readlines()

    assert type(res_1) is list
    assert res_1 == words_list


def test_read_board():
    res_1 = a3.read_board("board1.txt")

    with open("board1.txt") as f:
        board_list = f.readlines()

    assert type(res_1) is list
    assert res_1 == board_list
