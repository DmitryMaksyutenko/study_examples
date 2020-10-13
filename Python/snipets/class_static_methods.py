# The class method decorator, can be used as alternative constructor,
# or factory method.
class Person:

    def __init__(self, first_name="", last_name=""):
        self.first_name = first_name
        self.last_name = last_name

    # Receives the implicit first parameter.
    @classmethod
    def from_string(cls, string):
        first_name, last_name = string.split(" ")
        return cls(first_name, last_name)


user1 = Person()
# The empty attributes.
print(user1.first_name, user1.last_name)

user2 = Person("Din", "Vinchester")
print(user2.first_name, user2.last_name)

user3 = Person.from_string("Sam Vinchester")
print(user3.first_name, user3.last_name)


# The static method is similar to C++ static functions.
class Vehicle:

    color = "red"
    name = "BMW"

    def __init__(self, color, name):
        self.color = color
        self.name = name

    # Doesn't receive the implicit first parameter.
    @staticmethod
    def base_color():
        return Vehicle.color



print(Vehicle.base_color())
