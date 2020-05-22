# -*- coding: utf-8 -*-
# The logging library takes a modular approach and offers several categories of
# components: loggers, handlers, filters, and formatters.

# Loggers expose the interface that application code directly uses.
#
# Handlers send the log records (created by loggers) to the appropriate destination.
#
# Filters provide a finer grained facility for determining which log records to output.
#
# Formatters specify the layout of log records in the final output.
#
# Log event information is passed between loggers, handlers, filters and
# formatters in a LogRecord instance.
#
# Logging is performed by calling methods on instances of the Logger class
# (hereafter called loggers). Each instance has a name, and they are conceptually
# arranged in a namespace hierarchy using dots (periods) as separators. For
# example, a logger named ‘scan’ is the parent of loggers ‘scan.text’,
# ‘scan.html’ and ‘scan.pdf’. Logger names can be anything you want, and indicate
# the area of an application in which a logged message originates.
#
# A good convention to use when naming loggers is to use a module-level logger,
# in each module which uses logging.

# 1.  Creating loggers, handlers, and formatters explicitly using Python code that
#     calls the configuration methods listed above.
#
# 2. Creating a logging config file and reading it using the fileConfig() function.
#
# 3. Creating a dictionary of configuration information and passing it to the
#    dictConfig() function.
import logging

# Loggers:
# Logger objects have a threefold job. First, they expose several methods to
# application code so that applications can log messages at runtime. Second,
# logger objects determine which log messages to act upon based upon severity
# (the default filtering facility) or filter objects. Third, logger objects pass
# along relevant log messages to all interested log handlers.
logger = logging.getLogger('Root logger.')
logger.setLevel(logging.DEBUG)

# Handler objects are responsible for dispatching the appropriate log messages
# (based on the log messages’ severity) to the handler’s specified destination.
consoleHandler = logging.StreamHandler()
consoleHandler.setLevel(logging.DEBUG)

# Formatter objects configure the final order, structure, and contents of the
# log message.
formater = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
consoleHandler.setFormatter(formater)
logger.addHandler(consoleHandler)

# 'application' code
logger.debug('debug message')
logger.info('info message')
logger.warning('warn message')
logger.error('error message')
logger.critical('critical message')
