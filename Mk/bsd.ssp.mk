# $FreeBSD$
# SSP Support

SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(SSP_UNSAFE) && \
<<<<<<< HEAD
    (${ARCH} == i386 || ${ARCH} == amd64)
# Overridable as a user may want to use -fstack-protector
SSP_CFLAGS?=	-fstack-protector-all
=======
    (${MACHINE} != "mips")
# Overridable as a user may want to use -fstack-protector-all
SSP_CFLAGS?=	-fstack-protector-strong
>>>>>>> upstream/master
CFLAGS+=	${SSP_CFLAGS}
LDFLAGS+=	${SSP_CFLAGS}
.endif
