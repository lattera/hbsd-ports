# Created by: Patrick Dung (patrick_dkt@yahoo.com.hk)
# $FreeBSD$

PORTNAME=	pdftk
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.8
CATEGORIES=	print java
MASTER_SITES=	http://repo.maven.apache.org/maven2/:bcprov
DISTFILES=	${_BCPROV_JAR}:bcprov

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple tool for doing everyday things with PDF documents

LICENSE=	GPLv2
<<<<<<< HEAD

# Get GCC version suffix without the dot in USE_GCC
CSUFF=		${_USE_GCC:S/.//}

USE_GCC=	6	# Only GCC 6 provides Java (GCJ and libgcj).
USES=		iconv gmake zip

USE_HARDENING=	pie:off

# gcj/libgcj don't exist on some platforms
ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	GNU gcj does not exist on this platform

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-dist
WRKSRC=		${PATCH_WRKSRC}/${PORTNAME}

MAKEFILE=	Makefile.FreeBSD
MAKE_ENV=	GCJ=gcj${CSUFF} GCJH=gcjh${CSUFF} GCPP=cpp${CSUFF} \
		OBJCOPY=${OBJCOPY}

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

pre-configure:
	@if [ ! -e ${LOCALBASE}/bin/gcj${CSUFF} ]; then \
		${ECHO_MSG} ""; \
		${ECHO_MSG} "Cannot find gcj${CSUFF}"; \
		${ECHO_MSG} "Please rebuild ${_GCC_PORT} with java support"; \
		${ECHO_MSG} ""; \
		exit 1; \
	fi

post-patch:
	@${REINPLACE_CMD} -e "s|TOOLPATH=|TOOLPATH=${LOCALBASE}/bin/|g; \
		s|VERSUFF=|VERSUFF=${CSUFF}|g; s|GCJFLAGS=|GCJFLAGS= -L${LOCALBASE}/lib ${LDFLAGS} -w|g; \
		s|LDLIBS= -lgcj|LDLIBS= -lgcj -pthread ${ICONV_LIB} -lz -L${LOCALBASE}/lib ${LDFLAGS} -w|g" \
		${WRKSRC}/${MAKEFILE}
=======
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3
RUN_DEPENDS=	${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3

USE_ANT=	yes
USE_GITLAB=	yes
GL_ACCOUNT=	pdftk-java
GL_COMMIT=	c98f90e623376942b5a0e9c77345e11710e50509
USE_JAVA=	yes
ALL_TARGET=	jar
NO_ARCH=	yes
SUB_FILES=	pdftk
SUB_LIST=	CLASSPATH="${_CLASSPATH:ts:}" \
		JAVA="${JAVA}"
PLIST_FILES=	${JAVAJARDIR}/${_BCPROV_JAR:T} \
		${JAVAJARDIR}/pdftk.jar \
		bin/pdftk \
		man/man1/pdftk.1.gz

_BCPROV_JAR=	org/bouncycastle/bcprov-jdk15on/1.51/bcprov-jdk15on-1.51.jar
_CLASSPATH=	${JAVAJARDIR}/${_BCPROV_JAR:T} ${JAVAJARDIR}/commons-lang3.jar \
		${JAVAJARDIR}/pdftk.jar

post-extract:
	@${MKDIR} ${WRKSRC}/lib
	@${LN} -sf ${JAVAJARDIR}/commons-lang3.jar ${WRKSRC}/lib
	@${LN} -sf ${DISTDIR}/${_BCPROV_JAR} ${WRKSRC}/lib
>>>>>>> upstream/master

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pdftk \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/jar/pdftk.jar \
		${DISTDIR}/${_BCPROV_JAR} \
		${STAGEDIR}${JAVAJARDIR}
	${INSTALL_MAN} ${WRKSRC}/pdftk.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
