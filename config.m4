dnl $Id$
dnl config.m4 for extension ever

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(ever, for ever support,
dnl Make sure that the comment is aligned:
dnl [  --with-ever             Include ever support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(ever, whether to enable ever support,
dnl Make sure that the comment is aligned:
dnl [  --enable-ever           Enable ever support])

if test "$PHP_EVER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-ever -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/ever.h"  # you most likely want to change this
  dnl if test -r $PHP_EVER/$SEARCH_FOR; then # path given as parameter
  dnl   EVER_DIR=$PHP_EVER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for ever files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       EVER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$EVER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the ever distribution])
  dnl fi

  dnl # --with-ever -> add include path
  dnl PHP_ADD_INCLUDE($EVER_DIR/include)

  dnl # --with-ever -> check for lib and symbol presence
  dnl LIBNAME=ever # you may want to change this
  dnl LIBSYMBOL=ever # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $EVER_DIR/lib, EVER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_EVERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong ever lib version or lib not found])
  dnl ],[
  dnl   -L$EVER_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(EVER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(ever, ever.c, $ext_shared)
fi
