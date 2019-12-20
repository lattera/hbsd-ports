# $FreeBSD$
# SSP Support

SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(SSP_UNSAFE) && \
<<<<<<< HEAD
    (${MACHINE} != "mips")
# Overridable as a user may want to use -fstack-protector
SSP_CFLAGS?=	-fstack-protector-all
=======
    (! ${ARCH:Mmips*})
# Overridable as a user may want to use -fstack-protector-all
SSP_CFLAGS?=	-fstack-protector-strong
>>>>>>> freebsd/master
CFLAGS+=	${SSP_CFLAGS}
LDFLAGS+=	${SSP_CFLAGS}
.endif
