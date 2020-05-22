import logging
import logging.config
import os

settings_file = os.path.join(os.path.dirname(__file__), 'logging.conf')
print(settings_file)
logging.config.fileConfig(settings_file)

# create logger
logger = logging.getLogger('With settings file.')

# 'application' code
logger.debug('debug message')
logger.info('info message')
logger.warning('warn message')
logger.error('error message')
logger.critical('critical message')
