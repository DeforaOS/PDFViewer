/* $Id$ */
/* Copyright (c) 2010 Sébastien Bocahu <zecrazytux@zecrazytux.net> */
/* Copyright (c) 2011-2020 Pierre Pronchery <khorben@defora.org> */
/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>. */



#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <libintl.h>
#include "common.h"
#include "pdfviewer.h"
#include "../config.h"
#define _(string) gettext(string)

/* constants */
#ifndef PREFIX
# define PREFIX		"/usr/local"
#endif
#ifndef DATADIR
# define DATADIR	PREFIX "/share"
#endif
#ifndef LOCALEDIR
# define LOCALEDIR	DATADIR "/locale"
#endif


/* private */
/* prototypes */
static int _error(char const * message, int ret);
static int _usage(void);


/* functions */
/* error */
static int _error(char const * message, int ret)
{
	fputs(PROGNAME_PDFVIEWER ": ", stderr);
	perror(message);
	return ret;
}


/* usage */
static int _usage(void)
{
	fprintf(stderr, _("Usage: %s [file]\n"), PROGNAME_PDFVIEWER);
	return 1;
}


/* main */
int main(int argc, char * argv[])
{
	int o;
	PDFviewer * pdfviewer;

	if(setlocale(LC_ALL, "") == NULL)
		_error("setlocale", 1);
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);
	gtk_init(&argc, &argv);
	while((o = getopt(argc, argv, "")) != -1)
		switch(o)
		{
			default:
				return _usage();
		}
	if(optind != argc && optind + 1 != argc)
		return _usage();
	if((pdfviewer = pdfviewer_new()) == NULL)
		return 2;
	if(argc - optind == 1)
		pdfviewer_open(pdfviewer, argv[optind]);
	gtk_main();
	pdfviewer_delete(pdfviewer);
	return 0;
}
