# -*- coding: utf-8 -*-
import logging
import argparse

import log_lib


# Logging is a means of tracking events that happen when some softvare runs.
# The software's developers adds logging calls to the programms code to
# indicate the events have occured.
# An event is desctibed by a desctiptive message which can contain optional
# variable data.

# When to use logging:
# https://docs.python.org/3/howto/logging.html#when-to-use-logging

# Level    |   When it’s used
# ---------------------------
# DEBUG    |   Detailed information, typically of interest only when diagnosing problems.

# INFO     |   Confirmation that things are working as expected.

# WARNING  |   An indication that something unexpected happened, or indicative of some problem
#              in the near future (e.g. ‘disk space low’). The software is still working as
#              expected.

# ERROR    |   Due to a more serious problem, the software has not been able to perform some function.

# CRITICAL |   A serious error, indicating that the program itself may be unable to continue running.

# The default level is WARNING, which means that only events of this level and
# above will be tracked, unless the logging package is configured to do
# otherwise.

# Events that are tracked can be handled in different ways. The simplest way of
# handling tracked events is to print them to the console. Another common way is
# to write them to a disk file.

parser = argparse.ArgumentParser()
parser.add_argument('--log')
args = parser.parse_args()

# Base example.
# logging.warning('Some Warning!')
# logging.info('Some informational message.') # Not printed because WARNING level.

# Logging into file.
log_type = getattr(logging, vars(args).get('log').upper())

if not isinstance(log_type, int):
    raise ValueError(f'Invalid log level: {log_type}')

format_string = '%(asctime)s %(levelname)s %(message)s'
logging.basicConfig(filename='loggfile.log',
                    filemode='w',
                    format=format_string,
                    level=log_type)
logging.info('START')
logging.debug('Debug message!')
logging.warning('Warning message!!!')
log_lib.log_info()
logging.info('STOP')

