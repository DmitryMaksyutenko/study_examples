# First, the try clause (the statement(s) between the try and except keywords)
# is executed.

# If no exception occurs, the except clause is skipped and execution of the try
# statement is finished.

# If an exception occurs during execution of the try clause, the rest of the
# clause is skipped. Then if its type matches the exception named after the
# except keyword, the except clause is executed, and then execution continues
# after the try statement.

# If an exception occurs which does not match the exception named in the except
# clause, it is passed on to outer try statements; if no handler is found,
# it is an unhandled exception and execution stops with a message
# as shown above.


# If a finally clause is present, the finally clause will execute as the last
# task before the try statement completes. The finally clause runs whether or
# not the try statement produces an exception.

# If an exception occurs during execution of the try clause, the exception may
# be handled by an except clause. If the exception is not handled by an except
# clause, the exception is re-raised after the finally clause has been
# executed.

# An exception could occur during execution of an except or else clause.
# Again, the exception is re-raised after the finally clause has been executed.

# If the try statement reaches a break, continue or return statement,
# the finally clause will execute just prior to the break, continue or return
# statement’s execution.

# If a finally clause includes a return statement, the returned value will be
# the one from the finally clause’s return statement, not the value from the
# try clause’s return statement.


def div(divident, divisor):
    quotient = 0
    try:
        print("The try clause.")  # All print functions must be removed.
        quotient = divident // divisor
    except ZeroDivisionError as e:
        print(f"The expect clause. {e}")
        raise e
    except BaseException as e:
        print(f"Unexpected error: {e}")
        raise e
    else:
        print("The else clause.")
        return quotient
    finally:
        print("The finally clause.")
        return quotient
