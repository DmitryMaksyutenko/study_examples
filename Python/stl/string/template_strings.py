from string import Template
# Template strings provide simpler string substitution.
# A primary use case for template strings is for internalization i18n.

title_text = Template("This is title text for ${name}.")
# >>> title_text.substitute(name="article").
# >>> title_text.substitute(article="article") rise KeyError.
# >>> title_text.safe_substitute(article="article") without KeyError.


class MyTemplate(Template):
    delimiter = "="
    idpattern = "[a-z]*"


full_name = MyTemplate("=first_name, =last_name.")
# >>> full_name.substitute(first_name="Tom", last_name="Soer") KeyError first.

full_name = MyTemplate("=firstname, =lastname.")
# >>> full_name.substitute(firstname="Tom", lastname="Soer").


# Printing the global table.
import pprint  # noqa
pprint.pprint(globals())
