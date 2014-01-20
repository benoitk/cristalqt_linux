#-------------------------------------------------
#
# Project created by QtCreator 2014-01-09T14:15:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = essai_5
TEMPLATE = app


SOURCES += main.cpp \
    CWinStreamView.cpp \
    CWinStreamSelectorModel.cpp \
    CWinStreamModel.cpp \
    CWinStreamControler.cpp \
    CWinSchedulerView.cpp \
    CWinSchedulerModel.cpp \
    CWinSchedulerControler.cpp \
    CWinMeasureCardView.cpp \
    CWinMeasureCardModel.cpp \
    CWinMeasureCardControler.cpp \
    CWinMainView.cpp \
    CWinMaintenanceView.cpp \
    CWinMaintenanceModel.cpp \
    CWinMaintenanceControler.cpp \
    CWinMainModel.cpp \
    CWinMainControler.cpp \
    CWinExternalCardView.cpp \
    CWinExternalCardModel.cpp \
    CWinExternalCardControler.cpp \
    CWinEVPompeView.cpp \
    CWinEVPompeModel.cpp \
    CWinEVPompeControler.cpp \
    CWinElecTestView.cpp \
    CWinElecTestControler.cpp \
    CWindowTestCartesExt.cpp \
    CWindowTest.cpp \
    CWindowAlarm.cpp \
    CUserSession.cpp \
    CStreamModel.cpp \
    CPushButton.cpp \
    CMesureModel.cpp \
    CMeasureCardModel.cpp \
    CGraphicsRectItem.cpp \
    CDialogValEtalon.cpp \
    CDialogStreamChoice.cpp \
    CDialogStopCycle.cpp \
    CDialogResultatEtalon.cpp \
    CDialogRestauration.cpp \
    CDialogPaveNum.cpp \
    CDialogPassword.cpp \
    CDialogMessage.cpp \
    CDialogMaintenanceView.cpp \
    CDialogInfo.cpp \
    CDialogCopyFiles.cpp \
    CDialogConfigSeuil.cpp \
    CDialogAlarm.cpp \
    CCmdJBusRunnable.cpp \
    CCardJBusModel.cpp \
    CAlarmSortFilterProxyModel.cpp \
    CAlarmSortedView.cpp \
    TrameJBUS.cpp \
    tracedebug.cpp \
    ThreadInterface.cpp \
    Thread.cpp \
    System.cpp \
    stream.cpp \
    StdAfx.cpp \
    SockTcpServeur.cpp \
    SocketIHM.cpp \
    serial.cpp \
    Protection.cpp \
    Network.cpp \
    mesure.cpp \
    FichierIni.cpp \
    Elem.cpp \
    Cycle.cpp \
    CSupervision.cpp \
    CarteMesure.cpp \
    CarteJbusSlave.cpp \
    CarteIO.cpp \
    Analyseur.cpp \
    SockTcpClient.CPP \
    socketbase.cpp

HEADERS  += \
    resource1.h \
    resource.h \
    main.cpp_back \
    InterfaceUserSession.h \
    header_qt.h \
    header_ihm.h \
    GraphicsRectItem.h \
    CWinStreamView.h \
    CWinStreamSelectorModel.h \
    CWinStreamModel.h \
    CWinStreamControler.h \
    CWinSchedulerView.h \
    CWinSchedulerModel.h \
    CWinSchedulerControler.h \
    CWinMeasureCardView.h \
    CWinMeasureCardModel.h \
    CWinMeasureCardControler.h \
    CWinMainView.h \
    CWinMaintenanceView.h \
    CWinMaintenanceModel.h \
    CWinMaintenanceControler.h \
    CWinMainModel.h \
    CWinMainControler.h \
    CWinExternalCardView.h \
    CWinExternalCardModel.h \
    CWinExternalCardControler.h \
    CWinEVPompeView.h \
    CWinEVPompeModel.h \
    CWinEVPompeControler.h \
    CWinElecTestView.h \
    CWinElecTestControler.h \
    CWindowTestCartesExt.h \
    CWindowTest.h \
    CWindowAlarm.h \
    CUserSession.h \
    CSupervision.h \
    CStreamModel.h \
    CristalQTARM.aps \
    CPushButton.h \
    CMesureModel.h \
    CMeasureCardModel.h \
    CGraphicsRectItem.h \
    CDialogValEtalon.h \
    CDialogStreamChoice.h \
    CDialogStopCycle.h \
    CDialogResultatEtalon.h \
    CDialogRestauration.h \
    CDialogPaveNum.h \
    CDialogPassword.h \
    CDialogMessage.h \
    CDialogMaintenanceView.h \
    CDialogInfo.h \
    CDialogCopyFiles.h \
    CDialogConfigSeuil.h \
    CDialogAlarm.h \
    CCmdJBusRunnable.h \
    CCardJBusModel.h \
    CAlarmSortFilterProxyModel.h \
    CAlarmSortedView.h \
    header.h \
    trameJBUS.h \
    tracedebug.h \
    ThreadInterface.h \
    Thread.h \
    System.h \
    Stream.h \
    StdAfx.h \
    SockTcpServeur.h \
    SockTcpClient.H \
    SocketIHM.h \
    SOCKBASE.H \
    serial.h \
    Protection.h \
    Network.h \
    mesure.h \
    FichierIni.h \
    elem.h \
    cycle.h \
    CristalApp.cpp.bak \
    CarteMesure.h \
    CarteJbusSlave.h \
    CarteIO.h \
    Analyseur.h \
    Analyseur.cpp.bak \
    typedefinition.h \
    tchar.h \


FORMS    += \
    cristalqtarm.ui

OTHER_FILES += \
    info_version.rc \
    info_version.aps \
    essai_5.pro.user \
    cristalqtarm_zh.ts \
    cristalqtarm_zh.qm \
    cristalqtarm_ru.ts \
    cristalqtarm_ru.qm \
    cristalqtarm_fr.ts \
    cristalqtarm_fr.qm \
    cristalqtarm_en.ts \
    cristalqtarm_en.qm \
    CristalQTARM1.rc \
    CristalQTARM.rc \
    CristalApp.aps

RESOURCES += \
    cristalqtarm.qrc \
    picto.qrc
