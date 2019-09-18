AM_CPPFLAGS = \
	$(GTK_CFLAGS) $(X11_CFLAGS) $(APPINDICATOR_CFLAGS)

# Need to silence the dprecated declarations warnings
# GTK-3 deprecates the main widget this program uses...
AM_CFLAGS =\
	 -Wall\
	 -Wno-deprecated-declarations \
	 -g

bin_PROGRAMS = discord-tray

discord_tray_SOURCES = \
	main.c \
	tray_status_icon.h \
	tray_status_icon.c \
	winctrl.c \
	winctrl.h

discord_tray_LDFLAGS = \
	$(GTK_LDFLAGS) $(X11_LDFLAGS) $(APPINDICATOR_CFLAGS)

discord_tray_LDADD =  \
	$(GTK_LIBS) $(X11_LIBS) $(APPINDICATOR_CFLAGS)

