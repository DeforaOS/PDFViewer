TARGETS	= pdfviewer.1 pdfviewer.html
PREFIX	= /usr/local
DESTDIR	=
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: $(TARGETS)

pdfviewer.1: pdfviewer.xml
	./docbook.sh -P "$(PREFIX)" -- "pdfviewer.1"

pdfviewer.html: manual.css.xml pdfviewer.css.xml pdfviewer.xml
	./docbook.sh -P "$(PREFIX)" -- "pdfviewer.html"

clean:
	$(RM) -- $(pdfviewer.1_OBJS) $(pdfviewer.html_OBJS)
	./docbook.sh -c -P "$(PREFIX)" -- "pdfviewer.1"
	./docbook.sh -c -P "$(PREFIX)" -- "pdfviewer.html"

distclean: clean
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -i -- "pdfviewer.1"
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -i -- "pdfviewer.html"

uninstall:
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -u -- "pdfviewer.1"
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -u -- "pdfviewer.html"

.PHONY: all clean distclean install uninstall
