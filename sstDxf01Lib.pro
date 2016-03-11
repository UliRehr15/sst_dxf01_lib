TEMPLATE	= lib
CONFIG		+= warn_on
CONFIG    -= qt
CONFIG    -= windows

# CONFIG    -= debug  # ist RELEASE aktiv
CONFIG    -= release  # ist DEBUG aktiv

CONFIG    += staticlib

INCLUDEPATH += ../dxflib/Header
INCLUDEPATH += ../sst_str01_lib/Header
INCLUDEPATH += ../sst_misc01_lib/Header
INCLUDEPATH += ../sst_rec04_lib/Header
INCLUDEPATH += ./Header


# SOURCES		+= str1_lib1.cpp
HEADERS		+= ./Header/sstDxf01Lib.h

SOURCES		+=  \
                   sstDxf01Read.cpp \
    sstdxf01Layer.cpp \
    sstdxf01Block.cpp \
    sstDxf01Arc.cpp \
    sstDxf01Insert.cpp \
    sstDxf01Base.cpp

OTHER_FILES += README.md

debug{
  TARGET		= sst_dxf01_lib_d
}
release{
  TARGET		= sst_dxf01_lib_r
}

DESTDIR     = ../libs

