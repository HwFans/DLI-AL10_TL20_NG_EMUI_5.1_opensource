# DJGPP specific configuration file.
# Sed script for additional DJGPP specific editing
# of the configure script generated by autoconf 2.62.

# Copyright (C) 2005-2012 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


# Additional editing of Makefiles
/^eval sed.*ac_file_inputs.*tmp\/out \\$/ {
:loop
n
/^$/!b loop
a\
cat > "$tmp/subs-djgpp.sed" << eof_djgpp\
# DJGPP specific Makefile changes.\
s,\\.deps,_deps,g\
s,\\.libs,_libs,g\
s,\\.new\\.,_new.,g\
s,\\.old\\.,_old.,g\
s,\\.tab\\.,_tab.,g\
s,c++\\.at,cxx.at,g\
s,c++\\.m4,cxx.m4,g\
s,c++-skel\\.m4,cxx-skel.m4,g\
s,calc++,calcxx,g\
s,scan-gram-c,c-scan-gram,g\
s,scan-skel-c,c-scan-skel,g\
s,inttypes_,_inttypes,g\
s,javacomp\\.sh\\.in,javacomp.sh-in,g\
s,javaexec\\.sh\\.in,javaexec.sh-in,g\
s,yacc\\.1\\.in,yacc.1-in,g\
s,bench\\.pl\\.in,bench.pl-in,g\
s,Makefile\\.am\\.in,Makefile.am-in,g\
s,Makefile\\.in\\.in,Makefile.in-in,g\
/^\\.y\\.c:/,/^$/ {\
  /\\\$(YACCCOMPILE)/ {\
    a\\\\\
	-@test -f y.tab.c && mv -f y.tab.c y_tab.c\\\\\
	-@test -f y.tab.h && mv -f y.tab.h y_tab.h\
  }\
}\
/^libbison.a:/ i\\\\\
\\$(top_srcdir)/djgpp/subpipe.c: \\$(top_srcdir)/djgpp/subpipe.h\\\\\
subpipe.o: \\$(top_srcdir)/djgpp/subpipe.c \\$(top_srcdir)/djgpp/subpipe.h\\\\\
	\\$(COMPILE) -c \\$<\
/^yacc:/ i\\\\\
yacc.bat:\\\\\
	echo "bison\\$(EXEEXT) -y %1 %2 %3 %4 %5 %6 %7 %8 %9" >\\$@\
/^bin_SCRIPTS =/s/$/ yacc.bat/\
/^MOSTLYCLEANFILES = yacc/s/$/ yacc.bat/\
/cross-options.texi:/,/^$/ s|bison|&.exe|g\
/^\\.x\\.1:/,/^$/ s|\\$program|&.exe|g\
eof_djgpp\
sed -f "\$tmp/subs-djgpp.sed" \$tmp/out > \$tmp/out.djgpp\
mv -f \$tmp/out.djgpp \$tmp/out
}

# Makefile.in.in is renamed to Makefile.in-in.
/ac_config_files=/ {
  /runtime-po/!s|po/Makefile\.in|&:po/Makefile.in-in|
  s|runtime-po/Makefile\.in|&:runtime-po/Makefile.in-in|
  s|javacomp\.sh\.in|javacomp.sh-in|
  s|javaexec\.sh\.in|javaexec.sh-in|
  s|doc/yacc\.1|&:doc/yacc.1-in|
  s|etc/bench.pl|&:etc/bench.pl-in|
}

/CONFIG_FILES=/ {
  /runtime-po/!s|po/Makefile\.in|&:po/Makefile.in-in|2
  s|runtime-po/Makefile\.in|&:runtime-po/Makefile.in-in|2
  s|javacomp\.sh\.in|javacomp.sh-in|
  s|javaexec\.sh\.in|javaexec.sh-in|
  s|doc/yacc\.1|&:doc/yacc.1-in|2
  s|etc/bench\.pl|&:etc/bench.pl-in|2
}

# We always use _deps and _libs instead of .deps and .libs, because
# the latter is an invalid name on 8+3 MS-DOS file system.  This makes
# the generated Makefiles good for every DJGPP installation, not only
# the one where the package was configured (which could happen to be
# a Windows box, where leading dots in file names are allowed).
/^rmdir[	 ]*\.tst/ i\
am__leading_dot=_

# Replace (command) > /dev/null with `command > /dev/null`, since
# parenthesized commands always return zero status in the ported Bash,
# even if the named command doesn't exist
/if ([^|;`]*null/{
  s,(,`,
  s,),,
  /null[	 ]*2>&1/ s,2>&1,&`,
  /null.*null/ s,null.*null,&`,
  /null.*null/ !{
    /null[	 ]*2>&1/ !s,null,&`,
  }
}

# DOS-style absolute file names should be supported as well
/\*) top_srcdir=/s,/\*,[\\\\/]* | ?:[\\\\/]*,

# The following two items are changes needed for configuring
# and compiling across partitions.
# 1) The given srcdir value is always translated from the
#    "x:" syntax into "/dev/x" syntax while we run configure.
/^[	 ]*-srcdir=\*.*$/ a\
    ac_optarg=`echo "$ac_optarg" | sed "s,^\\([A-Za-z]\\):,/dev/\\1,"`
/set X `ls -Lt \$srcdir/ i\
   if `echo $srcdir | grep "^/dev/" - > /dev/null`; then\
     srcdir=`echo "$srcdir" | sed -e "s%^/dev/%%" -e "s%/%:/%"`\
   fi

# Autoconf 2.52e generated configure scripts
# write absolute paths into Makefiles and bison.in
# making them useless for DJGPP installations for
# which the package has not been configured for.
/MISSING=/,/^$/ {
  /^fi$/ a\
am_missing_run=`echo "$am_missing_run" | sed 's%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%${top_srcdir}%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%${top_srcdir}%'`
}
/^install_sh=/a\
install_sh=`echo "$install_sh" | sed 's%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%${top_srcdir}%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%${top_srcdir}%'`

# This will only work if the assumption that the
# testsuite is ran from the following path:
#   ${top_srcdir}/tests/testsuite.dir
# holds. The explicit names are of no importance.
#   ../../. == ${top_srcdir}
#/^esac$/,/^ac_abs_srcdir=/ {
/^ac_abs_srcdir=/ i\
ac_abs_builddir=`echo "$ac_abs_builddir" | sed "s%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../.%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../.%"`\
ac_abs_top_builddir=`echo "$ac_abs_top_builddir" | sed "s%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../..%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../..%"`\
ac_abs_top_srcdir=`echo "$ac_abs_top_srcdir" | sed "s%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../..%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../..%"`
#ac_abs_srcdir=`echo "$ac_abs_srcdir" | sed "s%/dev/.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../.%;s%.:.*/bison[-_0-9]\\{1,1\\}[-.0-9A-Za-z+]*%../../.%"`
/^ac_abs_srcdir=/ a\
for dj_dir in $ac_abs_builddir $ac_abs_top_builddir $ac_abs_top_srcdir $ac_abs_srcdir\
do\
  ac_abs_builddir=`echo "$ac_abs_builddir" | sed "s%//%/%g"`\
  ac_abs_top_builddir=`echo "$ac_abs_top_builddir" | sed "s%//%/%g"`\
  ac_abs_top_srcdir=`echo "$ac_abs_top_srcdir" | sed "s%//%/%g"`\
  ac_abs_srcdir=`echo "$ac_abs_srcdir" | sed "s%//%/%g"`\
done

# Add DJGPP version information.
/^#define VERSION/ s/\$VERSION/&  (DJGPP port (r1))/

# We need makeinfo to make the html formated docs.
/\$am_missing_run[	 ]*makeinfo/ s,\$am_missing_run,,

# The path to the FORTRAN compiler and libraries
# shall contain no absolute path reference so it
# will be good for all djgpp installations.
/^FLIBS="\$ac_cv_flibs"/ i\
ac_djgpp_path=`echo "$DJDIR" | sed 's%\\\\\\%/%g' | tr $as_cr_LETTERS $as_cr_letters`\
ac_cv_flibs=`echo "$ac_cv_flibs" | sed "s%-L$ac_djgpp_path%-L/dev/env/DJDIR%g"`

# Autoconf generated configure scripts write absolute
# paths of certain header files into Makefiles making
# them useless for DJGPP installations for which the
# package has not been configured for.
/^.*echo "\$as_me:\$LINENO: result: \$gl_cv_absolute_.*$/ {
h
s,^.*\(gl_cv_absolute_\)\([a-z0-9_]*\)\(_h\).*$,\1\2\3=`echo $\1\2\3 | sed "s%[^:]:.*/include/%/dev/env/DJDIR/include/%"`,
G
}
/^.*echo "\$as_me:\$LINENO: result: \$gl_cv_full_.*$/ {
h
s,^.*\(gl_cv_full_\)\([a-z0-9_]*\)\(_h\).*$,\1\2\3=`echo $\1\2\3 | sed "s%[^:]:.*/include/%/dev/env/DJDIR/include/%"`,
G
}

# The following is not a valid DOS file name
s/calc++/calcxx/g

# The CR test for awk does not work for DJGPP.
/^ac_cs_awk_cr=/,/^$/ {
  /^fi$/ a\
ac_cs_awk_cr=$ac_cr
}
