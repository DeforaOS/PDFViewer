TARGETS	= $(OBJDIR)pdfviewer
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
BINDIR	= $(PREFIX)/bin
SBINDIR	= $(PREFIX)/sbin
CC	= cc
CPPFLAGSF= -I $(PREFIX)/include
CPPFLAGS=
CFLAGSF	= -W `pkg-config --cflags libDesktop poppler-glib`
CFLAGS	= -Wall -g -O2 -pedantic -fPIC -fstack-protector
LDFLAGSF= `pkg-config --libs libDesktop poppler-glib` -lm
LDFLAGS	= -Wl,-pie
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

pdfviewer_OBJS = $(OBJDIR)callbacks.o $(OBJDIR)pdfviewer.o $(OBJDIR)main.o
pdfviewer_CFLAGS = $(CPPFLAGSF) $(CPPFLAGS) $(CFLAGSF) $(CFLAGS)
pdfviewer_LDFLAGS = $(LDFLAGSF) $(LDFLAGS)

$(OBJDIR)pdfviewer: $(pdfviewer_OBJS)
	$(CC) -o $(OBJDIR)pdfviewer $(pdfviewer_OBJS) $(pdfviewer_LDFLAGS)

$(OBJDIR)callbacks.o: callbacks.c callbacks.h
	$(CC) $(pdfviewer_CFLAGS) -o $(OBJDIR)callbacks.o -c callbacks.c

$(OBJDIR)pdfviewer.o: pdfviewer.c callbacks.h pdfviewer.h ../config.h
	$(CC) $(pdfviewer_CFLAGS) -o $(OBJDIR)pdfviewer.o -c pdfviewer.c

$(OBJDIR)main.o: main.c
	$(CC) $(pdfviewer_CFLAGS) -o $(OBJDIR)main.o -c main.c

clean:
	$(RM) -- $(pdfviewer_OBJS)

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) -m 0755 $(OBJDIR)pdfviewer $(DESTDIR)$(BINDIR)/pdfviewer

uninstall:
	$(RM) -- $(DESTDIR)$(BINDIR)/pdfviewer

.PHONY: all clean distclean install uninstall
