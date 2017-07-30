HEADERS += \
    mywidget.h \
    workthreadb.h \
    workthreadc.h \
    workthreada.h

SOURCES += \
    mywidget.cpp \
    main.cpp \
    workthreadb.cpp \
    workthreadc.cpp \
    workthreada.cpp

QT += widgets gui

LIBS += -lwiringPi
