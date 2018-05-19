<<<<<<< HEAD:sysutils/bareos-bat/Makefile
# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD: head/sysutils/bareos-bat/Makefile 426215 2016-11-16 07:11:54Z acm $
=======
# $FreeBSD$
>>>>>>> freebsd/master:sysutils/bareos16-bat/Makefile

PORTNAME=	bareos16
PKGNAMESUFFIX=	-bat
PORTREVISION=	1

COMMENT=	Backup archiving recovery open sourced (GUI)

LIB_DEPENDS+=	libqwt.so:x11-toolkits/qwt5 \
		libbareos.so:sysutils/bareos16-client

CONFLICTS=	bacula*-bat-*

USES=		pkgconfig desktop-file-utils
USE_QT4=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

<<<<<<< HEAD:sysutils/bareos-bat/Makefile
MASTERDIR=	${.CURDIR}/../bareos-server
=======
MASTERDIR=	${.CURDIR}/../../sysutils/bareos16-server
>>>>>>> freebsd/master:sysutils/bareos16-bat/Makefile

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

.include "${MASTERDIR}/Makefile"
