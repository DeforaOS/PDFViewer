PREFIX	= /usr/local
DESTDIR	=
MKDIR	= mkdir -m 0755 -p
INSTALL	= install
RM	= rm -f


all:

clean:

distclean: clean

install:
	$(MKDIR) $(DESTDIR)$(PREFIX)/share/applications
	$(INSTALL) -m 0644 deforaos-pdfviewer.desktop $(DESTDIR)$(PREFIX)/share/applications/deforaos-pdfviewer.desktop

uninstall:
	$(RM) -- $(DESTDIR)$(PREFIX)/share/applications/deforaos-pdfviewer.desktop

.PHONY: all clean distclean install uninstall
