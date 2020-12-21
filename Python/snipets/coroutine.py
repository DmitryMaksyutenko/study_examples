# When the logic of a complex function is divided into several
# self-contained steps that are themselves functions,
# then these functions are called helper functions or "subroutines".

# Unlike subroutines, coroutines have many entry points for suspending
# and resuming execution. Coroutine can suspend its execution and transfer
# control to other coroutine and can resume again execution from the point
# it left off.

# Coroutines work cooperatively multi task by suspending and resuming
# at set points by programmer.

# In Python, coroutines are similar to generators but with few extra methods
# and slight change in how used yield statement.
# Generators produce data for iteration while coroutines can also consume data.
# Both return the control of the program.
import asyncio
from random import randint


# Simple example.
def print_name(name):
    print(f"This is my name - {name}")
    while True:
        passed = yield
        if passed == name:
            print(f"passed {passed} equal to name {name}.")


coroutine = print_name("Sam")
next(coroutine)
coroutine.send("George")
coroutine.send("Sam")
coroutine.close()


# Base asyncio example.
async def random_sleep():
    await asyncio.gather(counter_1(), counter_2())


async def counter_1():
    print("start counter 1")
    rand_num = randint(1, 20)
    await asyncio.sleep(rand_num)
    print(f"end counter 1 after {rand_num} sec.")


async def counter_2():
    print("start counter 2")
    rand_num = randint(1, 20)
    await asyncio.sleep(rand_num)
    print(f"end counter 2 after {rand_num} sec.")


asyncio.run(random_sleep())
