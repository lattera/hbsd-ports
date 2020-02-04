# $FreeBSD$

PORTNAME=	iichid-kmod
MAINTAINER=	shawn.webb@hardenedbsd.org
DISTVERSION=	g2020020300

CATEGORIES=	sysutils
COMMENT=	i2c HID driver

USES=		kmod uidfix
USE_GITLAB=	nodefault
GL_SITE=	https://git-01.md.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	iichid
GL_COMMIT=	79299fac1a2816eb21cac71d504a2d79665d015b

WRKSRC=		${WRKDIR}/iichid
MASTER_SITES+=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/archive/${GL_COMMIT}.tar.gz?dummy=/

pre-build:
	(cd ${WRKSRC}; make depend)

.include <bsd.port.mk>
