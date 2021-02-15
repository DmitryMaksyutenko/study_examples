import string
# The Formater class allows to create and customize own string formatting
# behaviors using the same implementation as the builtin format().


class MyFormat(string.Formatter):

    def vformat(self, format_string, *args, **kwargs):
        new_str = ""
        values = self.get_value(0, args, kwargs)
        for i, tpl in enumerate(self.parse(format_string)):
            new_str += "".join(tpl[0] + values[i])
        return new_str
