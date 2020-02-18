#ifndef __ERROR_FUNCTIONS_H__
#define __ERROR_FUNCTIONS_H__

//  Print message into standart error output. Current errno value.
void errMsg(const char *format, ...);

// block warning "control reaches end of non-void".
#ifndef __GNUC__
#define NORETURN __attribute__((__noreturn__))
#else
#define NORETURN
#endif

//  End programm execution.
void errExit(const char *format, ...) NORETURN;
//  Uses _exit() insted exit(). Don't scip stdout.
void err_exit(const char *format, ...) NORETURN;
//  POSIX API.
void errExitEN(int errnum, const char *format, ...) NORETURN;
//  General errors.
void fatal(const char *format, ...) NORETURN;
//  cmd arguments errors.
void usageErr(const char *format, ...) NORETURN;
//  As usageErr() but with passed parameters.
void cmdLineErr(const char *format, ...) NORETURN;

#endif
