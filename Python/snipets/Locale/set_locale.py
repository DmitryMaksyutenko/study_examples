# -*- coding: utf-8 -*-
import locale

if __name__ == '__main__':
    all_locale = locale.setlocale(locale.LC_ALL, '').split(';')

    print('ALL LOCALE:')
    [print('    ', i) for i in all_locale]

    print('CODESET: ', locale.nl_langinfo(locale.CODESET))
    print('D_T_FMT: ', locale.nl_langinfo(locale.D_T_FMT))
    print('RADIXCHAR: ', locale.nl_langinfo(locale.RADIXCHAR))
    print('ALT_DIGITS: ', locale.nl_langinfo(locale.ALT_DIGITS))
    print('ERA: ', locale.nl_langinfo(locale.ERA))
    print('NOEXPR: ', locale.nl_langinfo(locale.NOEXPR))
    print('YESEXPR: ', locale.nl_langinfo(locale.YESEXPR))

    print('default locale: ', locale.getdefaultlocale())

    loc = locale.setlocale(locale.LC_ALL, '')
    new_locale = locale.setlocale(locale.LC_ALL, 'ru_RU.cp1251').split(';')

    print('NEW ALL LOCALE:')
    [print('    ', i) for i in new_locale]

    print('RESTORED ALL LOCALE:')
    new_locale = locale.setlocale(locale.LC_ALL, loc).split(';')
    [print('    ', i) for i in new_locale]
