Name:		thunderbird-tray
Version:	0.1
Release:	1%{?dist}
Summary:	Tray icon for the Thunderbird client application

License:	GPLv3+
Source0:	%{name}-%{version}.tar.bz2

BuildRequires:	gtk3-devel
Requires:		thunderbird


%description
Adds a tray icon for the Thunderbird client application.


%prep
%setup -q


%build
%configure
make %{?_smp_mflags}


%install
%make_install
desktop-file-install --delete-original \
	--dir $RPM_BUILD_ROOT%{_datadir}/applications \
	$RPM_BUILD_ROOT%{_datadir}/applications/%{name}.desktop


%files
%doc README.md
%license LICENSE
%{_bindir}/thunderbird-tray
%{_datadir}/applications/*%{name}.desktop


%changelog
* Fri Sep 07 2018 Tomas Smetana <tomas@smetana.name> - 0.1
- Built from the spec file template

