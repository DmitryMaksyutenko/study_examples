# Do not import any modules. If you do, the tester may reject your submission.

# Constants for the contents of the maze.

# The visual representation of a wall.
WALL = '#'

# The visual representation of a hallway.
HALL = '.'

# The visual representation of a brussels sprout.
SPROUT = '@'

# Constants for the directions. Use these to make Rats move.

# The left direction.
LEFT = -1

# The right direction.
RIGHT = 1

# No change in direction.
NO_CHANGE = 0

# The up direction.
UP = -1

# The down direction.
DOWN = 1

# The letters for rat_1 and rat_2 in the maze.
RAT_1_CHAR = 'J'
RAT_2_CHAR = 'P'


class Rat:
    """ A rat caught in a maze. """

    def __init__(self, symbol, row, col) -> None:
        """(Rat, str, int, int) -> NoneType

        The first parameter represents the rat to be initialized,
        the second parameter represents the 1-character symbol for the rat,
        the third parameter represents the row where the rat is located,
        and the fourth parameter represents the column where the rat is
        located.

        >>> r = Rat('P', 1, 4)
        >>> r
        'P at (1, 4) ate 0 sprouts.'
        >>> r = Rat('P', 2, 2)
        >>> r
        'P at (2, 2) ate 0 sprouts.'
        """
        self.symbol = symbol
        self.row = row
        self.col = col
        self.num_sprouts_eaten = 0

    def set_location(self, row, col) -> None:
        """(Rat, int, int) -> NoneType


        The first parameter represents a rat, the second represents a row,
        and the third represents a column.
        Set the rat's row and col instance variables to the given row
        and column.

        >>> r = Rat('P', 1, 4)
        r.set_location(3, 2)
        >>> r
        'P at (3, 2) ate 0 sprouts.'
        >>> r.set_location(1, 3)
        >>> r
        'P at (1, 3) ate 0 sprouts.'
        """
        self.row = row
        self.col = col

    def eat_sprout(self) -> None:
        """(Rat) -> NoneType

        The first parameter represents a rat.
        Add one to the rat's instance variable num_sprouts_eaten. Yuck.

        >>> r = Rat('P', 1, 2)
        >>> r.eat_sprout()
        >>> r.num_sprouts_eaten
        1
        >>> r.eat_sprout()
        >>> r.num_sprouts_eaten
        2
        """
        self.num_sprouts_eaten += 1

    def __str__(self) -> str:
        """(Rat) -> str

        Returns the Rat printable representation.

        >>> r = Rat('P', 1, 4)
        >>> r
        'P at (1, 4) ate 0 sprouts.'
        >>> r = Rat('P', 2, 2)
        >>> r
        'P at (2, 2) ate 0 sprouts.'
        """
        return "{0} at ({1}, {2}) ate {3} sprouts.".format(
            self.symbol, self.row, self.col, self.num_sprouts_eaten)


class Maze:
    """ A 2D maze. """

    def __init__(self, maze, rat_1, rat_2) -> None:
        """(Rat, list of list of str, Rat, Rat) -> NoneType

        The first paramter represents the maze to be initialized,
        the second parameter represents the contents of the maze,
        the third parameter represents the first rat in the maze,
        and the fourth parameter represents the second rat in the maze.

        >>> m = Maze([['#', '#', '#', '#', '#', '#', '#'],
                      ['#', '.', '.', '.', '.', '.', '#'],
                      ['#', '.', '#', '#', '#', '.', '#'],
                      ['#', '.', '.', '@', '#', '.', '#'],
                      ['#', '@', '#', '.', '@', '.', '#'],
                      ['#', '#', '#', '#', '#', '#', '#']],
                      Rat('J', 1, 1),
                      Rat('P', 1, 4))
        >>> m.num_sprouts_left
        3
        >>> str(m.rat_1)
        'J at (1, 1) eat 0 sprouts'
        >>> str(m.rat_2)
        'P at (1, 4) eat 0 sprouts'
        """
        self.maze = maze
        self.rat_1 = rat_1
        self.rat_2 = rat_2
        self.num_sprouts_left = self.__get_sprouts_count(maze)

    def is_wall(self, row, col) -> bool:
        """(Maze, int, int) -> bool

        The first parameter represents a maze, the second represents a row,
        and the third represents a column.
        Return True if and only if there is a wall at the given row and column
        of the maze.

        """
        if self.maze[row][col] == WALL:
            return True
        return False

    def get_character(self, row, col) -> str:
        """(Maze, int, int) -> str


        The first parameter represents a maze, the second represents a row,
        and the third represents a column.
        Return the character in the maze at the given row and column.
        If there is a rat at that location, then its character should be
        returned rather than HALL.

        """
        if self.__is_rat_1(row, col):
            return self.rat_1.symbol
        elif self.__is_rat_2(row, col):
            return self.rat_2.symbol
        else:
            return HALL

    def move(self, rat, vertical, horizontal) -> bool:
        """(Maze, Rat, int, int) -> boll

        The first parameter represents a maze, the second represents a rat,
        the third represents a vertical direction change
        (UP, NO_CHANGE or DOWN),
        and the fourth represents a horizontal direction change
        (LEFT, NO_CHANGE or RIGHT).

        Move the rat in the given direction, unless there is a wall in the way.
        Also, check for a Brussels sprout at that location and, if present:

            have the rat eat the Brussels sprout,
            make that location a HALL, and
            decrease the value that num_sprouts_left refers to by one.
            Return True if and only if there wasn't a wall in the way.

        """
        if not self.is_wall(
            rat.row + vertical,
            rat.col + horizontal
        ):
            rat.set_location(rat.row + vertical, rat.col + horizontal)
            if self.maze[rat.row][rat.col] == SPROUT:
                rat.eat_sprout()
                self.num_sprouts_left -= 1
                self.maze[rat.row][rat.col] = HALL
            return True
        return False

    def __str__(self) -> str:
        """(Maze) -> str

        The parameter represents a maze.
        Return a string representation of the maze.

        >>> maze = Maze([['#', '#', '#', '#', '#', '#', '#'],
                    ['#', 'J', '@', '.', 'P', '.', '#'],
                    ['#', '.', '#', '#', '#', '.', '#'],
                    ['#', '.', '.', '@', '#', '.', '#'],
                    ['#', '@', '#', '.', '@', '.', '#'],
                    ['#', '#', '#', '#', '#', '#', '#']],
                    Rat('J', 1, 1),
                    Rat('P', 1, 4))
        >>> str(maze)
        #######
        #J..P.#
        #.###.#
        #..@#.#
        #@#.@.#
        #######
        J at (1, 1) ate 0 sprouts.
        P at (1, 4) ate 0 sprouts
        """
        maze = "".join(["".join(j) for j in [i for i in self.maze]])
        maze += str(self.rat_1)
        maze += str(self.rat_2)
        return maze

    def __get_sprouts_count(self, maze) -> int:
        """(Maze, list of list of str) -> int


        Takes the Maze instance as the first parameter
        and the maze content as a second.
        Return the count of sprouts in a maze.

        >>> m = Maze([['#', '#', '#', '#', '#', '#', '#'],
                ['#', '.', '.', '.', '.', '.', '#'],
                ['#', '.', '#', '#', '#', '.', '#'],
                ['#', '.', '.', '@', '#', '.', '#'],
                ['#', '@', '#', '.', '@', '.', '#'],
                ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))
        >>> m.__get_sprouts_count(m.maze)
        3
        """
        return sum([i.count(SPROUT) for i in maze])

    def __is_rat_1(self, row, col) -> bool:
        """(Maze, int, int) -> bool

        Return true if there are rat_1 at given position.

        >>> m = Maze([['#', '#', '#', '#', '#', '#', '#'],
                ['#', '.', '.', '.', '.', '.', '#'],
                ['#', '.', '#', '#', '#', '.', '#'],
                ['#', '.', '.', '@', '#', '.', '#'],
                ['#', '@', '#', '.', '@', '.', '#'],
                ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

        >>> m.__is_rat_1(1, 1)
        True
        >>> m.__is_rat_1(1, 2)
        False
        """
        return self.rat_1.row == row and self.rat_1.col == col

    def __is_rat_2(self, row, col) -> bool:
        """(Maze, int, int) -> bool

        Return true if there are rat_1 at given position.

        >>> m = Maze([['#', '#', '#', '#', '#', '#', '#'],
                ['#', '.', '.', '.', '.', '.', '#'],
                ['#', '.', '#', '#', '#', '.', '#'],
                ['#', '.', '.', '@', '#', '.', '#'],
                ['#', '@', '#', '.', '@', '.', '#'],
                ['#', '#', '#', '#', '#', '#', '#']],
                Rat('J', 1, 1),
                Rat('P', 1, 4))

        >>> m.__is_rat_1(1, 4)
        True
        >>> m.__is_rat_1(1, 2)
        False
        """
        return self.rat_2.row == row and self.rat_2.col == col
