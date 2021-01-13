# The "memoryview" objects allow Python code to access the internal data of an
# object that supports the "buffer protocol" without copying.

#           https://docs.python.org/3/c-api/buffer.html#bufferobjects

# class memoryview(obj) - Create a memoryview that references the obj.
# The obj must support the "buffer protocol". Built-in objects that support the
# "buffer protocol" is "bytes" and "bytearray".
import array

byte_string = b"abcdef"
arr = array.array("l", [1234, 5234, 4444, 6, 77])

print(dir(memoryview))

byte_memview = memoryview(byte_string)
arr_memview = memoryview(arr)
