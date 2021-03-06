# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtorrent-rasterbar
DISTVERSIONPREFIX=	libtorrent-
DISTVERSION=	1_2_6
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library implementing a BitTorrent client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		cmake iconv:wchar_t libtool pathfix pkgconfig python:2.7,test shebangfix ssl # compiler:c++14-lang
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
SHEBANG_FILES=	test/socks.py test/web_server.py
USE_GITHUB=	yes
GH_ACCOUNT=	arvidn
GH_PROJECT=	libtorrent
USE_LDCONFIG=	yes

SHLIB_VER=	10
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"

DOCFILES=	AUTHORS ChangeLog
PORTDOCS=	${DOCFILES} docs/*
PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=		DOCS EXAMPLES LOGGING
OPTIONS_DEFAULT=	LOGGING
OPTIONS_SUB=		yes
LOGGING_DESC=		Enable logging to disk

EXAMPLES_CMAKE_BOOL=	build_examples
LOGGING_CMAKE_BOOL=	logging

.include <bsd.port.options.mk>

.if !${ARCH:Mpowerpc*} && ${OPSYS}_${OSREL:R} == FreeBSD_13 && ${OSVERSION} < 1300093
# workaroud for the clang-10 compiler failure: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=244830
# on powerpc, llvm 9 crashes with segfault, while 10 works https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=243958
# on powerpc64 elfv1, clang doesn't work at all (no support for elfv1), on elfv2 clang from base works ok
LLVM_VER=	90
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}
.else
USES+=		compiler:c++11-lang
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/include|${PREFIX}/include|' \
		${WRKSRC}/Jamfile
	@${REINPLACE_CMD} -e 's|return "python";|return "${PYTHON_CMD}";|' \
		${WRKSRC}/test/setup_transfer.cpp

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/libtorrent/Makefile*
	# Workaround for -DTHREADS_HAVE_PTHREAD_ARG:BOOL=YES being set in
	# Mk/Uses/cmake.mk
	# References:   https://mariadb.atlassian.net/browse/MDEV-9388
	#               https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=206169
	@${REINPLACE_CMD} 's/-l-pthread/-lpthread/' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/libtorrent-rasterbar.pc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/docs/._*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dbuild_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
