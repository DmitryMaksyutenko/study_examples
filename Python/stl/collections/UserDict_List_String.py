from collections import (
    UserDict, UserList, UserString
)
# This classes is useful for overriding or
# extendig the dict, list, str classes.


class MyDict(UserDict):
    def to_string(self):
        return ", ".join(
            [f"{key} = {value}" for key, value in self.data.items()]
        )


class MyList(UserList):
    def largest(self):
        return max(self.data)


class MyString(UserString):
    def largest(self):
        return max(self.data)
