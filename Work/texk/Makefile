# Makefile.aux. Generated from Makefile.in by configure.
# Makefile.  Generated from Makefile.aux by configure.
# Top-level Makefile for kpathsea-using programs.

# Package subdirectories, the library, and all subdirectories.
ESUBDIRS=

programs = web2c $(ESUBDIRS)
kpathsea_dir = kpathsea
all_dirs = $(programs) $(kpathsea_dir)

# paths.mk -- installation directories.
# $Id: paths.mk 10296 2008-08-12 23:46:59Z karl $

# Do not change prefix and exec_prefix in Makefile.in!
# configure doesn't propagate the change to the other Makefiles.
# Instead, give the -prefix/-exec-prefix options to configure.
# (See kpathsea/INSTALL for more details.) This is arguably
# a bug, but it's not likely to change soon.
prefix = /opt/luatex/metafont-2.718281/inst
exec_prefix = ${prefix}

# Architecture-dependent executables.
bindir = ${exec_prefix}/bin/i686-pc-linux-gnu

# Architecture-independent executables.
scriptdir = $(bindir)

# Architecture-dependent files, such as lib*.a files.
libdir = ${exec_prefix}/lib/i686-pc-linux-gnu

# Architecture-independent files.
datarootdir = ${prefix}/share
datadir = /opt/luatex/metafont-2.718281/inst

# Header files.
includedir = ${prefix}/include

# GNU .info* files.
infodir = ${datarootdir}/info

# Unix man pages.
manext = 1
mandir = ${datarootdir}/man
man1dir = $(mandir)/man$(manext)
man5dir = $(mandir)/man5

# modifiable single-machine data.
localstatedir = ${prefix}/var

# read-only single-machine data (configuration).
sysconfdir = ${prefix}/etc

# executables that other programs run.
libexecdir = ${exec_prefix}/libexec


# TeX system-specific directories. Not all of the following are relevant
# for all programs, but it seems cleaner to collect everything in one place.

# The default paths are in kpathsea/texmf.cnf. Passing all the paths to
# sub-makes can make the arg list too long.  If you make
# changes below, you will have to make the corresponding changes to
# texmf.cnf yourself.

# The root of the main tree.
texmf = /opt/luatex/metafont-2.718281/inst/texmf

# The directory used by varfonts.
vartexfonts = /var/tmp/texfonts

# Regular input files.
texinputdir = $(texmf)/tex
mfinputdir = $(texmf)/metafont
mpinputdir = $(texmf)/metapost
mftinputdir = $(texmf)/mft

# dvips's epsf.tex, rotate.tex, etc. get installed here;
# ditto for dvilj's fonts support.
dvips_plain_macrodir = $(texinputdir)/plain/dvips
dvilj_latex2e_macrodir = $(texinputdir)/latex/dvilj

# mktex.cnf, texmf.cnf, etc.
web2cdir = $(texmf)/web2c

# The top-level font directory.
fontdir = $(texmf)/fonts

# Memory dumps (.fmt/.base/.mem).
fmtdir = $(web2cdir)/tex
basedir = $(web2cdir)/metafont
memdir = $(web2cdir)/metapost

# Pool files.
texpooldir = $(web2cdir)
mfpooldir = $(texpooldir)
mppooldir = $(texpooldir)

# Where the .map files from fontname are installed.
fontnamedir = $(texmf)/fontname

# For dvips configuration files, psfonts.map, etc.
dvipsdir = $(texmf)/dvips

# For dvips .pro files, gsftopk's render.ps, etc.
psheaderdir = $(dvipsdir)

# If a font can't be found close enough to its stated size, we look for
# each of these sizes in the order given.  This colon-separated list is
# overridden by the envvar TEXSIZES, and by a program-specific variable
# (e.g., XDVISIZES), and perhaps by a config file (e.g., in dvips).
# This list must be sorted in ascending order.
default_texsizes = 600

# End of paths.mk.
# makevars.mk -- the directory names we pass.
# It's important that none of these values contain [ @%], for the sake
# of kpathsea/texmf.sed.
makevars = prefix=$(prefix) exec_prefix=$(exec_prefix) \
  bindir=$(bindir) scriptdir=$(scriptdir) libdir=$(libdir) \
  datadir=$(datadir) infodir=$(infodir) includedir=$(includedir) \
  mandir=$(mandir) manext=$(manext) man1dir=$(man1dir) \
  sysconfdir=$(sysconfdir) localstatedir=$(localstatedir) \
  libexecdir=$(libexecdir) \
  texmf=$(texmf) web2cdir=$(web2cdir) vartexfonts=$(vartexfonts)\
  texinputdir=$(texinputdir) mfinputdir=$(mfinputdir) mpinputdir=$(mpinputdir)\
  fontdir=$(fontdir) fmtdir=$(fmtdir) basedir=$(basedir) memdir=$(memdir) \
  texpooldir=$(texpooldir) mfpooldir=$(mfpooldir) mppooldir=$(mppooldir) \
  dvips_plain_macrodir=$(dvips_plain_macrodir) \
  dvilj_latex2e_macrodir=$(dvilj_latex2e_macrodir) \
  dvipsdir=$(dvipsdir) psheaderdir=$(psheaderdir) \
  default_texsizes='$(default_texsizes)'
# End of makevars.mk.

# It's too bad we have to pass all these down, but I see no alternative,
# if we are to propagate changes at the top level.
# XMAKEARGS is for the user to override.
makeargs = $(MFLAGS) CC='$(CC)' CFLAGS='$(CFLAGS)' LDFLAGS='$(LDFLAGS)' $(makevars) $(XMAKEARGS)
installargs = $(makeargs)

# Not everything from common.mk is relevant to this top-level
# Makefile, but most of it is, and it doesn't seem worth separating the
# compilation-specific stuff.
# common.mk -- used by all Makefiles.
SHELL = /bin/sh

top_srcdir = ../../texk
srcdir = ../../texk
VPATH = ../../texk

CC = gcc
CFLAGS = -g -O2 $(XCFLAGS)
CPPFLAGS =  $(XCPPFLAGS)
DEFS = -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DEDITOR=\"vi\ +%d\ %s\" -DIPC=/\*\*/ -DGREY=1 -DCOLOR=1 -DLDT1LIB=1 -DT1LIB=1 -DA4=1 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 $(XDEFS)
LDFLAGS =  $(XLDFLAGS)

# Kpathsea needs this for compiling, programs need it for linking.
LIBTOOL = $(SHELL) $(kpathsea_parent)/libtool

# You can change [X]CPPFLAGS, [X]CFLAGS, or [X]DEFS, but
# please don't change ALL_CPPFLAGS or ALL_CFLAGS.
# prog_cflags is set by subdirectories of web2c.
ALL_CPPFLAGS = $(DEFS) -I. -I$(srcdir) -I$(kpathsea_parent) \
  -I$(kpathsea_srcdir_parent) $(prog_cflags) $(CPPFLAGS)
ALL_CFLAGS = $(ALL_CPPFLAGS) $(CFLAGS)
ALL_CXXFLAGS = $(ALL_CPPFLAGS) $(CXXFLAGS)
compile = $(CC) $(ALL_CFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o .lo # in case the suffix list has been cleared, e.g., by web2c
.c.o:
	$(compile) -c $< -o $@

# Installation.
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_LIBTOOL_LIBS = $(LIBTOOL) --mode=install $(INSTALL_DATA)
INSTALL_LIBTOOL_PROG = $(LIBTOOL) --mode=install $(INSTALL_PROGRAM)

# Creating (symbolic) links.
LN = ln -s

# Removing files.
RM = rm -f

# Uninstall.
UNINSTALL = $(RM)
UNINSTALL_PROGRAM = $(RM)
UNINSTALL_SCRIPT = $(RM)
UNINSTALL_DATA = $(RM)
UNINSTALL_LIBTOOL_LIBS = $(LIBTOOL) --mode=uninstall $(RM)
UNINSTALL_LIBTOOL_PROG = $(LIBTOOL) --mode=uninstall $(RM)

# We use these for many things.
kpathsea_parent = ..
kpathsea_dir = $(kpathsea_parent)/kpathsea
kpathsea_srcdir_parent = $(top_srcdir)/..
kpathsea_srcdir = $(kpathsea_srcdir_parent)/kpathsea
kpathsea = $(kpathsea_dir)/libkpathsea.la

#M#ifeq ($(CC), gcc)
#M#XDEFS = -Wpointer-arith $(warn_more)
#M#CFLAGS = -g $(XCFLAGS)
#M#endif
# End of common.mk.

# Get more of the default setup.
# programs.mk -- used by Makefiles for executables only.

# Don't include $(CFLAGS), since ld -g under Linux forces
# static libraries, e.g., libc.a and libX*.a.
LDFLAGS =  $(XLDFLAGS)

# proglib is for web2c; 
# XLOADLIBES is for the installer.
LIBS = 
LOADLIBES = $(proglib) $(kpathsea) $(LIBS) $(XLOADLIBES)

# May as well separate linking from compiling, just in case.
CCLD = $(CC)
link_command = $(CCLD) -o $@ $(LDFLAGS) 

# When we link with Kpathsea, have to take account that it might be a
# shared library, etc.
kpathsea_link = $(LIBTOOL) --mode=link $(link_command)
# End of programs.mk.

# kpathsea is not a sibling, it's a child.
kpathsea_parent = .

# Make the library before the programs.
# Always make all, rather than $@, because automake-generated Makefiles,
# among others, do not have a default target.
# Use if ... rather than || or && because Ultrix sh exits for
# no good reason with the latter.
default all: do-kpathsea
	for d in $(programs); do if test -f $$d/Makefile; then \
	  (cd $$d && $(MAKE) $(makeargs) all) || exit 1; else true; fi; done

install install-data install-exec:
	for d in kpathsea $(programs); do if test -f $$d/Makefile; then \
	  (cd $$d && $(MAKE) $(installargs) $@) || exit 1; else true; fi; done

# Other standard targets for everything.
uninstall uninstall-exec uninstall-data \
mostlyclean clean realclean extraclean configclean \
info dvi check depend::
	for d in $(all_dirs); do if test -f $$d/Makefile; then \
	  (cd $$d && $(MAKE) $(makeargs) $@) || exit 1; else true; fi; done

distclean::
	rm -rf conftest*

distclean::
	for d in $(all_dirs); do if test -f $$d/Makefile; then \
	  (cd $$d && $(MAKE) $(makeargs) $@) || exit 1; else true; fi; done

distclean realclean::
	rm -f Makefile Makefile.aux config.status config.cache config.log libtool

# Unconditionally remake the library, since we don't want to write out
# the dependencies here.
do-kpathsea:
	cd $(kpathsea_dir) && $(MAKE) $(makeargs)

# Targets that only apply to web2c.
triptrap trip trap mptrap \
formats fmts bases mems \
install-formats install-fmts install-bases install-mems \
install-links c-sources: do-kpathsea
	cd web2c && $(MAKE) $(makeargs) $@

#M#ac_dir = $(srcdir)/etc/autoconf
#M#autoconf = $(ac_dir)/acspecific.m4 $(ac_dir)/acgeneral.m4 $(ac_dir)/acsite.m4
#M#configure_in = $(srcdir)/configure.in
#M#$(srcdir)/configure: $(configure_in) $(srcdir)/withenable.ac $(autoconf)
#M#	cd $(srcdir) && $(srcdir)/autoconf2.13 -m $(ac_dir)
#M#
#M## And make sure that --enable-maintainer-mode is used if configure is
#M## called from the makefiles.  We do not try to do this through the
#M## cache, lest the option sneaks into a global cache file.
#M#enablemaintflag = --enable-maintainer-mode

config.status: $(srcdir)/configure
	$(SHELL) $(srcdir)/configure --no-create --verbose  $(enablemaintflag)

Makefile: $(srcdir)/Makefile.in config.status
	$(SHELL) config.status

TAGS:
	find $(srcdir) \( -name '*.[cCfFhilsy]' -o -name '*.el' \) | etags -
