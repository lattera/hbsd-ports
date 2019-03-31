# $FreeBSD$

PORTNAME=	tigervnc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	meta@FreeBSD.org
COMMENT=	High-performance, platform-neutral implementation of VNC (meta port)

USES=		metaport

OPTIONS_DEFINE=	SERVER VIEWER
OPTIONS_DEFAULT=	SERVER
SERVER_RUN_DEPENDS=	vncserver:net/tigervnc-server
VIEWER_RUN_DEPENDS=	vncviewer:net/tigervnc-viewer

<<<<<<< HEAD
USE_HARDENING=	cfi safestack
CFI_OVERRIDE=	-fno-sanitize=cfi-icall

USES=		autoreconf:build cmake:insource,noninja cpe gl iconv jpeg libtool \
		pkgconfig python ssl
USE_GL=		gl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
=======
do-patch:	# noop
do-install:	# noop
>>>>>>> upstream/master

.include <bsd.port.mk>
