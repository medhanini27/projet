## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet

projet_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        date.c date.h \
	profile.c profile.h \
	rendezvous.c rendezvous.h\
	rendezvousA.c rendezvousA.h\
	verfier.c verfier.h\
	evenement.c evenement.h\
	profiles.c profiles.h\
	fiche.c fiche.h

projet_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

