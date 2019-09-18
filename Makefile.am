SUBDIRS = src

EXTRA_DIST = thunderbird-tray.spec.in \
			 thunderbird-tray.desktop.in

desktopdir = $(datadir)/applications
desktop_in_files = thunderbird-tray.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

# Copy all the spec files. Of cource, only one is actually used.
dist-hook:
	for specfile in *.spec; do \
		if test -f $$specfile; then \
			cp -p $$specfile $(distdir); \
		fi \
	done

rpm:
	rpmbuild -bb --build-in-place thunderbird-tray.spec

clean-local:
	-rm -f *.list
