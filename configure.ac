AC_PREREQ([2.69])
AC_INIT([coniod], [0.1.0], [binary@benary.org])

AM_INIT_AUTOMAKE(gnu check-news -Werror -Wall)

AC_CONFIG_SRCDIR([src/config.h.in])
AC_CONFIG_HEADERS([src/config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([err.h fcntl.h getopt.h stdio.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_PROG_CC_C99
AC_PROG_CC_STDC

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])

CFLAGS+=' "-DCONIOD_DEFAULT_CONFIGFILE=\"$(sysconfdir)/coniod.conf\""'

AC_OUTPUT
