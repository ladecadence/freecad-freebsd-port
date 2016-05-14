# Created by: David Pello <dpello@ladecadence.net> 
# $FreeBSD: 10.3-RELEASE FreeBSD 10.3-RELEASE #0 r297264: Fri Mar 25 02:10:02 UTC 2016     root@releng1.nyi.freebsd.org:/usr/obj/usr/src/sys/GENERIC  amd64

PORTNAME=	FreeCAD
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/FreeCAD/FreeCAD/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	dpello@ladecadence.net
COMMENT=	Parametric 3D modeler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying.lib

BUILD_DEPENDS= ${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs \
		cmake:${PORTSDIR}/devel/cmake \
		libtool:${PORTSDIR}/devel/libtool \
		pyside-lupdate:${PORTSDIR}/devel/pyside-tools \
		swig2.0:${PORTSDIR}/devel/swig20 \
		ode-config:${PORTSDIR}/devel/ode
	
		
LIB_DEPENDS=	libpyside-python2.7.so:${PORTSDIR}/devel/pyside \
		libCoin.so:${PORTSDIR}/graphics/Coin \
		libSoQt.so:${PORTSDIR}/x11-toolkits/soqt \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libFWOSPlugin.so:${PORTSDIR}/cad/opencascade \
		libttf.so:${PORTSDIR}/print/freetype \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libsysinfo.so:${PORTSDIR}/sysutils/sysinfo
	
		
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.8.5:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		pivy>=0:${PORTSDIR}/graphics/py-pivy
		

USES=		compiler:c++11-lang cmake python 
USE_QT4=	corelib gui opengl moc_build uic_build rcc_build qmake
PLIST_SUB=	PORTVERSION=${PORTVERSION}
CMAKE_ARGS=	-DFREECAD_USE_EXTERNAL_PIVY=1 -DCMAKE_BUILD_TYPE=Release \
		-DOCC_INCLUDE_DIR=/usr/local/include/OpenCASCADE \
		-DDOXYGEN_EXECUTABLE=/usr/local/bin/doxygen \
		-DBOOST_LIBRARYDIR=/usr/local/lib/boost 
#CMAKE_VERBOSE=	yes	
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
