from collections import ChainMap
# A ChainMap provides quick linking a number of mappings,
# so they can be treated as a single unit.

# Creation.
empty = ChainMap()  # ChainMap({}).
users = ChainMap({"name": "Sam", "age": 20}, {"name": "Alan", "age": 21})

# Methods.

users_list = users.maps
users_list.append({"name": "Alice", "age": 20})

new_users = users.new_child()
new_users.maps.append({"name": "Tom", "age": 23})

users.parents  # excludes "Sam".

key_list = list(users)  # ["name", "age"].


# Printing global table.
import pprint  # noqa.
pprint.pprint(globals())
