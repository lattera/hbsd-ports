# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tracker
PORTVERSION=	2.0.4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libicutu.so:devel/icu

PORTSCOUT=	limitw:1,even

<<<<<<< HEAD
USE_HARDENING=	pie:off relro:off

USES=		compiler:c++11-lib desktop-file-utils gettext gmake gnome \
		libarchive libtool pathfix pkgconfig python:run shebangfix \
		sqlite tar:xz
USE_GNOME=	gtk30 intltool introspection:build libxslt:build
=======
USES=		compiler:c++11-lib gettext gmake gnome libtool localbase \
		pathfix pkgconfig python:3.4+,build shebangfix sqlite tar:xz
USE_GNOME=	glib20 intltool introspection:build libxml2 
>>>>>>> freebsd/master
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-static \
		--disable-network-manager \
		--with-bash-completion-dir=no
INSTALL_TARGET=	install-strip
GLIB_SCHEMAS=	org.freedesktop.Tracker.DB.gschema.xml \
		org.freedesktop.Tracker.FTS.gschema.xml \
		org.freedesktop.Tracker.Store.gschema.xml \
		org.freedesktop.Tracker.enums.xml \
		org.freedesktop.Tracker.gschema.xml
SHEBANG_FILES=	utils/g-ir-merge/g-ir-merge

PLIST_SUB=	LIBVER=0.4.0

# force regen of this file, so the correct tracker version is embedded
# https://bugzilla.gnome.org/show_bug.cgi?id=792691
post-patch:
	@${RM} ${WRKSRC}/src/libtracker-sparql/tracker-sparql.vapi

.include <bsd.port.mk>
