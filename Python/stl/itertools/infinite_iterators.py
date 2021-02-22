import itertools
# count(start=0, step=1)
# cycle(iterable)
# repeat(object[, items])


def from_num_to_infinite(num: int) -> iter:
    """Generate numbers from passed value to infinitie."""
    return itertools.count(num, 1)


def collection_by_cycle(collection) -> iter:
    """Iterates through the collection in round."""
    return itertools.cycle(collection)


def repeat_message_n_times(message: str, n: int) -> iter:
    """Prints the message n times."""
    for mess in itertools.repeat(message, n):
        print(mess)


# Printing global table.
import pprint  # noqa
pprint.pprint(globals())
