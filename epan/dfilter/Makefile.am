# Makefile.am
#
# Wireshark - Network traffic analyzer
# By Gerald Combs <gerald@wireshark.org>
# Copyright 2001 Gerald Combs
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

include $(top_srcdir)/Makefile.am.inc

AM_CPPFLAGS = $(INCLUDEDIRS) -I$(top_srcdir)/epan -I$(lemon_srcdir) \
	$(WS_CPPFLAGS) $(GLIB_CFLAGS)

noinst_LTLIBRARIES = libdfilter_generated.la libdfilter.la

# C source files that are part of the display filter source; this includes only
# .c files, not YACC or Lex or... files (as Makefile.nmake maps this list
# into a list of object files by replacing ".c" with ".obj") or files
# generated from YACC or Lex files (as Automake doesn't want them in
# _SOURCES variables).
NONGENERATED_C_FILES = \
	dfilter.c		\
	dfilter-macro.c 	\
	dfunctions.c		\
	dfvm.c			\
	drange.c		\
	gencode.c		\
	semcheck.c		\
	sttype-function.c	\
	sttype-integer.c	\
	sttype-pointer.c	\
	sttype-range.c		\
	sttype-set.c		\
	sttype-string.c		\
	sttype-test.c		\
	syntax-tree.c

# Header files that are not generated from other files
NONGENERATED_HEADERS_PRIVATE = \
	dfilter-macro.h 	\
	dfilter-int.h		\
	dfunctions.h		\
	dfvm.h			\
	gencode.h		\
	semcheck.h		\
	sttype-function.h	\
	sttype-range.h		\
	sttype-set.h		\
	sttype-test.h		\
	syntax-tree.h

NONGENERATED_HEADERS_PUBLIC = \
	dfilter.h	\
	drange.h

# Files that generate compileable files
GENERATOR_FILES = \
	grammar.lemon		\
        scanner.l

# The C source files they generate and that we want in the distribution
GENERATED_C_FILES = \
	scanner.c

# The C source files they generate and that we don't want in the distribution
NODIST_GENERATED_C_FILES = \
	grammar.c

# The header files that they generate and that we want in the distribution
GENERATED_HEADER_FILES = \
	scanner_lex.h

# The header files that they generate and that we don't want in the distribution
NODIST_GENERATED_HEADER_FILES = \
	grammar.h

# All the generated files we want in the distribution.
GENERATED_FILES = \
	$(GENERATED_C_FILES) \
	$(GENERATED_HEADER_FILES)

# All the generated files we don't want in the distribution.
NODIST_GENERATED_FILES = \
	$(NODIST_GENERATED_C_FILES) \
	$(NODIST_GENERATED_HEADER_FILES)

subpkgincludedir = $(pkgincludedir)/epan/dfilter

subpkginclude_HEADERS = $(NONGENERATED_HEADERS_PUBLIC)


#Since code generated by lex may trigger gcc warnings, we are now generating two
#libraries.  A single library is generated with the lex code without the barrier
#"stop on warning". An other library is generated from the remaining source
#files with the "stop on warning" barrier.
libdfilter_la_SOURCES = \
	$(NONGENERATED_C_FILES)	\
	$(NONGENERATED_HEADERS_PRIVATE)

libdfilter_la_LIBADD = \
	libdfilter_generated.la

libdfilter_la_DEPENDENCIES = \
	libdfilter_generated.la

libdfilter_generated_la_SOURCES = \
	$(GENERATED_C_FILES)	\
	$(GENERATED_HEADER_FILES)

libdfilter_generated_la_CFLAGS = $(GENERATED_CFLAGS)

nodist_libdfilter_generated_la_SOURCES = \
	$(NODIST_GENERATED_C_FILES)	\
	$(NODIST_GENERATED_HEADER_FILES)

EXTRA_DIST = \
	.editorconfig		\
	$(GENERATOR_FILES)	\
	CMakeLists.txt

CLEANFILES = \
	libdfilter.a		\
	libdfilter.la		\
	libdfilter_generated.a 	\
	libdfilter_generated.la \
	*~

DISTCLEANFILES = \
	grammar.out	\
	$(NODIST_GENERATED_FILES)

MAINTAINERCLEANFILES = \
	$(GENERATED_FILES)	\
	$(NODIST_GENERATED_FILES)	\
	Makefile.in

BUILT_SOURCES = \
	grammar.h

scanner_lex.h : scanner.c

grammar.h : grammar.c
grammar.c : $(LEMON) $(lemon_srcdir)/lempar.c $(srcdir)/grammar.lemon
	$(AM_V_LEMON)$(LEMON) T=$(lemon_srcdir)/lempar.c $(srcdir)/grammar.lemon || \
		(rm -f grammar.c grammar.h ; false)

checkapi:
	$(PERL) $(top_srcdir)/tools/checkAPIs.pl -g termoutput -build \
	-sourcedir=$(srcdir) $(NONGENERATED_C_FILES)
