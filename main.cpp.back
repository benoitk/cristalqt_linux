#include <QApplication>
#include <QFile>
 //#include <QDebug>
//#include <QFontDatabase>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "CWinMainControler.h"
#include "StdAfx.h"
#include "header.h"

#include <stdio.h>





int main(int argc, char *argv[])
{
	TCHAR szText[MAX_PATH];
	//TCHAR szMessage[260];
	//HANDLE hCristalAppOnce = NULL;
	BOOL bReturn;
	CAnalyseur* pAnalyseur = new CAnalyseur();
	CSocketIHM* pSocketIHM = new CSocketIHM();
	CCarteIO* pCarteIO = new CCarteIO();
    CCarteMesure* pCarteMesure = new CCarteMesure();
	CCarteJbusSlave* pCarteJbusSlave = new CCarteJbusSlave();


	////Process result code


	_tprintf(_T(" CHARGEMENT CONFIGURATION...\n\n"));

	pAnalyseur->m_ExternalInterface.SetExternalInterface(pSocketIHM,pCarteIO,pCarteMesure,pCarteJbusSlave);
    _tprintf(_T("pAnalyseur->m_ExternalInterface.SetExternalInterface\n"));
    pSocketIHM->m_ExternalInterface.SetExternalInterface(pSocketIHM,pCarteIO,pCarteMesure,pCarteJbusSlave);
    _tprintf(_T("pSocketIHM->m_ExternalInterface.SetExternalInterface\n"));
    pSocketIHM->SetAccess(TRUE,TRUE);
    _tprintf(_T("pSocketIHM->SetAccess\n"));
	// chargement config
    //bReturn = bCopyFile(szGetFullPathName(_T("MsgErrorIHM.ini"),szText),SZ_FIC_TEMP,FALSE);
//    _tprintf(_T("bCopyFile\n"));
    if (bReturn) ReadConfigMsgError(szGetFullPathName(_T("MsgErrorIHM.ini"),szText));
    _tprintf(_T("ReadConfigMsgError"));
//    if (bReturn) bReturn = bCopyFile(szGetFullPathName(_T("config.ini"),szText),SZ_FIC_TEMP,FALSE);
//    _tprintf(_T("bCopyFile\n"));
    if (bReturn) bReturn = pAnalyseur->bReadConfig(szGetFullPathName(_T("config.ini"),szText));
    _tprintf(_T("bReadConfig\n"));
    if (bReturn) bReturn = pAnalyseur->bReadCycle(szGetFullPathName(_T("config.ini"),szText));
	//if (bReturn) bReturn = bCopyFile(szGetFullPathName(_T("InterfaceIHM.ini"),szText),SZ_FIC_TEMP,FALSE);
	//if (bReturn) bReturn = pSocketIHM->bReadConfig(SZ_FIC_TEMP,pAnalyseur);

	/*if (bReturn) bReturn = bCopyFile(szGetFullPathName(_T("InterfaceIO.ini"),szText),SZ_FIC_TEMP,FALSE);
	if (bReturn) bReturn = pCarteIO->bReadConfig(SZ_FIC_TEMP,pAnalyseur);
	if (bReturn) bReturn = bCopyFile(szGetFullPathName(_T("InterfaceMesure.ini"),szText),SZ_FIC_TEMP,FALSE);
	if (bReturn) bReturn = pCarteMesure->bReadConfig(SZ_FIC_TEMP,pAnalyseur);
	if (bReturn) bReturn = bCopyFile(szGetFullPathName(_T("InterfaceJbusSlave.ini"),szText),SZ_FIC_TEMP,FALSE);
	if (bReturn) bReturn = pCarteJbusSlave->bReadConfig(SZ_FIC_TEMP,pAnalyseur);*/
    _tprintf(_T("bReadCycle\n"));
    if (bReturn) bReturn = pCarteIO->bReadConfig(szGetFullPathName(_T("InterfaceIO.ini"),szText),pAnalyseur);
    _tprintf(_T("bReadConfig\n"));
    if (bReturn) bReturn = pCarteMesure->bReadConfig(szGetFullPathName(_T("InterfaceMesure.ini"),szText),pAnalyseur);
    _tprintf(_T("bReadConfig2\n"));
    if (bReturn) bReturn = pCarteJbusSlave->bReadConfig(szGetFullPathName(_T("InterfaceJbusSlave.ini"),szText),pAnalyseur);

    wchar_t *s4 = L"é";
	_tprintf(_T("****************************************\n"));
    _tprintf(L"* BILAN DES TESTSù CONFIG ANALYSEUR: %ls *\n",bReturn ? _T("OKI") : L"ZKO");
	_tprintf(_T("****************************************\n\n"));

	TRACE_LOG_MSG(_T("APPLICATION STARTED"));
	
	TCHAR ch;
	if (bReturn)
	{
		/*DWORD m_dwThreadID = 0;
		while ( ::CreateThread(NULL, 0,ThreadEntryPoint, NULL, 0, &m_dwThreadID) == NULL)
		{
			
			_tprintf(_T("CreateThread failed: 0x%08x\n"),GetLastError());
			Sleep(1000);
		}
		_tprintf(_T("CreateThread success\n"));
		while (1)
		{
			Sleep(1000);
			_tprintf(_T("main tick\n"));
		}*/


		QApplication a(argc, argv);
		//while (!pSocketIHM->bGetInRunThread()) Sleep(1000);
		//TRACE_LOG_MSG(_T("SocketIHM STARTED"));*/
        pCarteIO->setStackSize(64000);
		pCarteIO->start();
        while (!pCarteIO->bGetInRunThread()) QThread::msleep(1000);
		TRACE_LOG_MSG(_T("CarteIO STARTED"));
           
        pCarteMesure->setStackSize(64000);
        pCarteMesure->start();
        while (!pCarteMesure->bGetInRunThread()) QThread::msleep(1000);
		TRACE_LOG_MSG(_T("CarteMesure STARTED"));
     
        pCarteJbusSlave->setStackSize(64000);
		pCarteJbusSlave->start();
        while (!pCarteJbusSlave->bGetInRunThread()) QThread::msleep(1000);
		TRACE_LOG_MSG(_T("CarteJbusSlave STARTED"));

        pAnalyseur->setStackSize(64000);
  		pAnalyseur->start();
		TRACE_LOG_MSG(_T("Analyseur STARTED"));
		
		/*pThreadIhm->setStackSize(64000);
		pThreadIhm->start();
		while (!pThreadIhm->bGetInRunThread()) Sleep(1000);
		TRACE_LOG_MSG(_T("pThreadIhm STARTED"));
		while(pThreadIhm->isRunning()) Sleep(5000);*/
		
		_tprintf(_T("* Appuyer sur la touche <ENTER> pour quitter l'application: %s *\n"),bReturn ? _T("OK") : _T("KO"));
		
		
		
		QTranslator qtTranslator;
		if(qtTranslator.load("cristalqtarm_en.qm"))
				qDebug() << "Fichier anglais chargé" ;
        else if(qtTranslator.load("cristalqtarm_ru.qm"))
				qDebug() << "Fichier anglais chargé" ;
		a.installTranslator(&qtTranslator);

		//chargement stylesheet
#ifdef RES_640_480
		QFile file("cristalX86.qss");
#else
		QFile file("cristal.qss");
#endif
		file.open(QFile::ReadOnly);
		a.setStyleSheet(QLatin1String(file.readAll()));
		
		CWinMainControler* pControler= new CWinMainControler(pAnalyseur, pCarteIO,pCarteMesure, pSocketIHM);
		pControler->execControler();
		
		a.exec();

        _tprintf(_T("* Arret des process ..."));
        pAnalyseur->quit();
        delete pAnalyseur;
		_tprintf(_T("."));
        pCarteMesure->quit();
        delete pCarteMesure;
		_tprintf(_T("."));
        pCarteIO->quit();
        delete pCarteIO;
		_tprintf(_T("."));
        pCarteJbusSlave->quit();
        delete pCarteJbusSlave;
		_tprintf(_T("."));
        pSocketIHM->quit();
        delete pSocketIHM;
		_tprintf(_T("."));
		
		

#ifndef _WIN32_WCE
		pAnalyseur->bWriteConfig(szGetFullPathName(_T("configSave.ini"),szText));
		if (bReturn) bReturn = pSocketIHM->bWriteConfig(szGetFullPathName(_T("InterfaceIHMSave.ini"),szText));
		if (bReturn) bReturn = pCarteIO->bWriteConfig(szGetFullPathName(_T("InterfaceIOSave.ini"),szText));
		if (bReturn) bReturn = pCarteMesure->bWriteConfig(szGetFullPathName(_T("InterfaceMesureSave.ini"),szText));
		if (bReturn) bReturn = pCarteJbusSlave->bWriteConfig(szGetFullPathName(_T("InterfaceJbusSlaveSave.ini"),szText));
	
		WriteConfigMsgError(szGetFullPathName(_T("MsgErrorIHMSave.ini"),szText));
#endif
	}

	else
	{
		
        /*do
		{
			ch = GetKeyState(VK_ESCAPE);//getchar();
			ch |= GetKeyState(VK_RETURN);//getchar();
			Sleep(1000);
		}
        while ((ch & 0x8000) == 0);*/
		
	}
	_tprintf(_T("."));
	
//	CloseHandle(hCristalAppOnce);
	_tprintf(_T("."));
	
	return 0;
}
