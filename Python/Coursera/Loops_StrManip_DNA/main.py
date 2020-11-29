def get_length(dna):
    """ (str) -> int

    Return the length of the DNA sequence dna.

    >>> get_length('ATCGAT')
    6
    >>> get_length('ATCG')
    4
    """
    return len(dna)


def is_longer(dna1, dna2):
    """ (str, str) -> bool

    Return True if and only if DNA sequence dna1 is longer than DNA sequence
    dna2.

    >>> is_longer('ATCG', 'AT')
    True
    >>> is_longer('ATCG', 'ATCGGA')
    False
    """
    return len(dna1) > len(dna2)


def count_nucleotides(dna, nucleotide):
    """ (str, str) -> int

    Return the number of occurrences of nucleotide in the DNA sequence dna.

    >>> count_nucleotides('ATCGGC', 'G')
    2
    >>> count_nucleotides('ATCTA', 'G')
    0
    """
    return dna.count(nucleotide)


def contains_sequence(dna1, dna2):
    """ (str, str) -> bool

    Return True if and only if DNA sequence dna2 occurs in the DNA sequence
    dna1.

    >>> contains_sequence('ATCGGC', 'GG')
    True
    >>> contains_sequence('ATCGGC', 'GT')
    False

    """
    return dna2 in dna1


def is_valid_sequence(dna):
    """(srt) -> bool

    Return True if and only if the DNA sequence is valid.

    >>> is_valid_sequence("ATCGGA")
    True
    >>> is_valid_sequence("ATCG")
    True
    >>> is_valid_sequence("ATCGa")
    False
    >>> is_valid_sequence("ATCGXV")
    False
    """
    nucleotides = ["A", "C", "G", "T"]
    for char in dna:
        if char not in nucleotides:
            return False
    return True


def insert_sequence(dna1, dna2, index):
    """(str, str, int) -> str

    Return the DNA sequence obtained by inserting
    the second DNA sequence into the first DNA sequence
    at the given index.

    >>> insert_sequence("ATCG", "AT", 2)
    ATATCG
    >>> insert_sequence("ATCGGA", "ATA", 1)
    AATATCGGA
    >>> insert_sequence("AT", "GGG", 2)
    ATGGG
    """
    new_dna = dna1[:index] + dna2 + dna1[index:]
    return new_dna


def get_complement(nucleotide):
    """(str) -> str

    Return the nucleotide's complement.

    >>> get_complement("A")
    T
    >>> get_complement("T")
    A
    >>> get_complement("G")
    C
    >>> get_complement("C")
    G
    """
    complement = str()
    if nucleotide == "A":
        complement = "T"
    elif nucleotide == "T":
        complement = "A"
    elif nucleotide == "C":
        complement = "G"
    elif nucleotide == "G":
        complement = "C"
    return complement


def get_complementary_sequence(dna):
    """(str) -> str

    Return the DNA sequence that is complementary
    to the given DNA sequence.

    >>> get_complementary_sequence("ATCG")
    TAGC
    >>> get_complementary_sequence("AT")
    TA
    >>> get_complementary_sequence("ATCGGA")
    TAGCCT
    """
    sequence = ""
    for nucleotide in map(get_complement, dna):
        sequence += nucleotide
    return sequence
