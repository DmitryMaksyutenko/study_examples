from a2 import Rat, Maze


def test_Rat_instantiation():
    rat = Rat("P", 1, 4)

    assert rat.symbol == "P"
    assert rat.row == 1
    assert rat.col == 4
    assert rat.num_sprouts_eaten == 0


def test_Rat_print():
    rat_1 = Rat("P", 1, 4)
    rat_2 = Rat("P", 2, 2)

    assert str(rat_1) == "P at (1, 4) ate 0 sprouts."
    assert str(rat_2) == "P at (2, 2) ate 0 sprouts."


def test_Rat_set_location():
    rat = Rat("P", 1, 4)

    rat.set_location(3, 2)
    assert rat.row == 3
    assert rat.col == 2

    rat.set_location(1, 3)
    assert rat.row == 1
    assert rat.col == 3


def test_Rat_eat_sprout():
    rat = Rat("P", 1, 4)

    rat.eat_sprout()
    assert rat.num_sprouts_eaten == 1

    rat.eat_sprout()
    assert rat.num_sprouts_eaten == 2


def test_Maze_initialization():
    maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                 ['#', '.', '@', '.', '.', '.', '#'],
                 ['#', '.', '#', '#', '#', '.', '#'],
                 ['#', '.', '.', '@', '#', '.', '#'],
                 ['#', '@', '#', '.', '@', '.', '#'],
                 ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

    assert maze.num_sprouts_left == 4
    assert str(maze.rat_1) == "J at (1, 1) ate 0 sprouts."
    assert str(maze.rat_2) == "P at (1, 4) ate 0 sprouts."


def test_Maze_is_wall():
    maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                 ['#', '.', '@', '.', '.', '.', '#'],
                 ['#', '.', '#', '#', '#', '.', '#'],
                 ['#', '.', '.', '@', '#', '.', '#'],
                 ['#', '@', '#', '.', '@', '.', '#'],
                 ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 0),
                Rat('P', 1, 4))

    assert maze.is_wall(maze.rat_1.row, maze.rat_1.col)
    assert not maze.is_wall(maze.rat_2.row, maze.rat_2.col)


def test_Maze_get_character():
    maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                 ['#', 'J', '@', '.', 'P', '.', '#'],
                 ['#', '.', '#', '#', '#', '.', '#'],
                 ['#', '.', '.', '@', '#', '.', '#'],
                 ['#', '@', '#', '.', '@', '.', '#'],
                 ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

    assert maze.get_character(1, 1) == "J"
    assert maze.get_character(1, 4) == "P"
    assert maze.get_character(1, 5) == "."


def test_Maze_move():
    maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                 ['#', 'J', '@', '.', 'P', '.', '#'],
                 ['#', '.', '#', '#', '#', '.', '#'],
                 ['#', '.', '.', '@', '#', '.', '#'],
                 ['#', '@', '#', '.', '@', '.', '#'],
                 ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

    assert maze.move(maze.rat_1, 0, 1)
    assert not maze.move(maze.rat_2, -1, 0)
    assert maze.maze[maze.rat_1.row][maze.rat_1.col] == "."
    assert maze.num_sprouts_left == 3


def test_Maze_str():
    maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                 ['#', 'J', '@', '.', 'P', '.', '#'],
                 ['#', '.', '#', '#', '#', '.', '#'],
                 ['#', '.', '.', '@', '#', '.', '#'],
                 ['#', '@', '#', '.', '@', '.', '#'],
                 ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

    breakpoint()
    assert str(maze) == """#######
#J@.P.#
#.###.#
# .@#.#
#@#.@.#
#######
J at (1, 1) ate 0 sprouts.
P at (1, 4) ate 0 sprouts."""
