//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "Network.h"

#include <QFile>
#include <QSettings>
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//#define _WIN_INI
#define SIZE_CODE_UNICODE		2


DWORD dwGetPrivateProfileString(LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszDefault,LPTSTR lpszReturnedString,int iSizeMax,QString lpszFileIni)
{
#ifdef _WIN_INI
	return GetPrivateProfileString( lpszSection, lpszEntry, lpszDefault,lpszReturnedString,iSizeMax,lpszFileIni);
#endif

//	static HANDLE hf = INVALID_HANDLE_VALUE;
//    static TCHAR _lpszFileIni[MAX_PATH] = _T("");
//    static QString _lpszFileIni("");
    QFile file;
    BOOL bReturn = FALSE;
//	TCHAR *lpbuf = NULL;
//	long filelen = 0;
//	DWORD nReadSize;
//	TCHAR szRub[MAX_PATH];
//	TCHAR *pStart;
//	TCHAR *pEnd;


//    if ((!file.isOpen()) || _lpszFileIni == lpszFileIni)
//    {
//        if (file.isOpen())
//        {
//            qDebug() << "close old file " << _lpszFileIni;
//           file.close();
//        }
//        _lpszFileIni = lpszFileIni;
//        file.setFileName(_lpszFileIni);
//    }

//    int ntry = 0;
//	//lstrcpy(lpszReturnedString,lpszDefault);
//    StringCchCopy(lpszReturnedString, MAX_PATH, lpszDefault);
    file.setFileName(lpszFileIni);
    int ntry = 0;
    while ((!file.isOpen()) && (ntry < 100))
//	do
    {
//        qDebug() << "try open new file " << lpszFileIni;

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "impossible de lire le fichier " << lpszFileIni;
            if(ntry++ > 100) return FALSE;
        }
    }

    if (file.isOpen())
    {
//        qDebug() << "FILE IS OPEN";
        QTextStream stream(&file);
        QString sFileStream = stream.readAll();
//        qDebug() << "STREAM " << sFileStream;
        QString sSection = "[" + QString::fromWCharArray(lpszSection) + "]";
        //qDebug() << "SECTION " << sSection;
        if(sFileStream.contains(sSection))
        {
//            qDebug() << "if(sFileStream.contains(sSection)) index" << sFileStream.indexOf(sSection)
//                     << " count " << sSection.count();
            sFileStream = sFileStream.mid(sFileStream.indexOf(sSection) + sSection.count());
//           qDebug() << "STREAM 2 " << sFileStream;
            QString sRub = QString::fromWCharArray(lpszEntry)+"=";
//            qDebug() << "RUB  " << sRub;
            if(sFileStream.contains(sRub))
            {
//                qDebug() << " if(sFileStream.contains(sRub))";
                sFileStream = sFileStream.mid(sFileStream.indexOf(sRub));
//                qDebug() << "STREAM 3 " << sFileStream;
                QString sEOL = "\n";
//                qDebug() << "EOL  " << sEOL;
                if(sFileStream.contains(sEOL)){
//                    qDebug() << "  if(sFileStream.contains(sEOL)){";
                    sFileStream = sFileStream.left(sFileStream.indexOf(sEOL));
//                    qDebug() << "STREAM 4 " << sFileStream;
                    if(sFileStream.contains("="))
                        sFileStream = sFileStream.split("=").last();
//                    qDebug() << "VALUE " << sFileStream;
                    sFileStream.toWCharArray(lpszReturnedString);
                    lpszReturnedString[sFileStream.count()] = _T('\0');
                    qDebug() << "VALUE IN WCHAR " << QString::fromWCharArray(lpszReturnedString);
                    bReturn = TRUE;
                }

            }
        }
        file.close();
    }

    if(!bReturn){
        lstrcpy(lpszReturnedString, lpszDefault);

        qDebug() << "Erreur à la lecture la clé " << QString::fromWCharArray(lpszEntry)
                 << " de la section " << QString::fromWCharArray(lpszSection);
        qDebug() << "Valeur par defaut " << QString::fromWCharArray(lpszReturnedString);

    }

	return (lstrlen(lpszReturnedString));
}



BOOL bWritePrivateProfileString( LPCTSTR lpszSection, LPCTSTR lpszEntry,LPTSTR lpszString,QString lpszFileIni)
{
	HANDLE hf;
	TCHAR *lpbuf = NULL;
	DWORD filelen = 0;
	DWORD nReadSize = 0;
	BOOL bReturn = FALSE; 
	int ntry = 0;
	TCHAR szRub[2*MAX_PATH];
	TCHAR *pStart;
	TCHAR *pStart2;
	TCHAR *pEnd;
	int iSize;

#ifdef _WIN_INI
	return WritePrivateProfileString(lpszSection,lpszEntry,lpszString,lpszFileIni);
#endif

//	do
//	{
//		ntry ++;
//		hf = CreateFile(lpszFileIni,
//			GENERIC_READ|GENERIC_WRITE,
//			0,//FILE_SHARE_READ|FILE_SHARE_WRITE,
//			NULL,
//			OPEN_ALWAYS,
//			FILE_ATTRIBUTE_NORMAL,
//			NULL);

//		if (hf == INVALID_HANDLE_VALUE)
//		{
//			filelen = GetLastError();
//			if (filelen == ERROR_ACCESS_DENIED)
//			{
//				Sleep(50);
//			}
//			else break;
//		}
//	}
//	while ((hf == INVALID_HANDLE_VALUE) && (ntry < 100));

//	if (hf != INVALID_HANDLE_VALUE)
//	{
//		filelen = GetFileSize(hf, NULL);

//		if (filelen >= SIZE_CODE_UNICODE)
//		{
//			SetFilePointer(hf, SIZE_CODE_UNICODE, 0, FILE_BEGIN);
//			filelen -= SIZE_CODE_UNICODE;
//		}
//		iSize = filelen/sizeof(TCHAR) + lstrlen(lpszString) + lstrlen(lpszSection)  + lstrlen(lpszEntry) + 32; // 32 ==> extra caracteres ([, ],  =, cr/lf ;
//		if (lpbuf = new TCHAR[iSize])
//		{
//			memset(lpbuf,0,iSize * sizeof(TCHAR));
//			if (ReadFile(hf, lpbuf, filelen, &nReadSize, NULL))
//			{
//			}
//			lpbuf[nReadSize/sizeof(TCHAR)] = 0;
//			// debut de RUB
//            _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("[%s]"),lpszSection);
//			if (pStart = _tcsstr(lpbuf,szRub))
//			{
//				// recherche fin rub
//				pStart++;
//				pEnd = _tcsstr(pStart,_T("["));
//				if (pEnd == NULL)
//				{
//					// recherche clef
//                    _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s="),lpszEntry);
//					pStart2 = _tcsstr(pStart,szRub);
//					if (pStart2 == NULL)// c'est la dernière rubrique du fichier ==> ajout à la fin du fichier
//					{
//						pStart2 = _tcsstr(pStart,_T("\n"));
//						if (pStart2 == NULL)
//						{
//							lstrcat(lpbuf,_T("\r\n"));
//						}
//                        _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s=%s\r\n"),lpszEntry,lpszString);
//						lstrcat(lpbuf,szRub);
//					}
//					else pEnd = (TCHAR*)(lpbuf + nReadSize);
//				}
//				if (pEnd != NULL)
//				{
//					// recherche clef
//                    _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s="),lpszEntry);
//					if ((pStart2 = _tcsstr(pStart,szRub)) && (pStart2 < pEnd))
//					{
//						pEnd = _tcsstr(pStart2,_T("\r\n"));
//						pStart2 += lstrlen(szRub);
//                        _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s"),lpszString);
//						if (pEnd)
//						{
//							memmove(pStart2 + lstrlen(szRub),pEnd,(((BYTE*)lpbuf) + nReadSize - ((BYTE*)pEnd)));
//							memcpy(pStart2,szRub,lstrlen(szRub)*sizeof(TCHAR));
//						}
//					}
//					else // insertion d'une clef
//					{
//                        _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s=%s\r\n"),lpszEntry,lpszString);
//						memmove(pEnd + lstrlen(szRub),pEnd,((BYTE*)lpbuf) + nReadSize - ((BYTE*)pEnd));
//						memcpy(pEnd,szRub,lstrlen(szRub)*sizeof(TCHAR));
//					}
//				}
//			}
//			else
//			{
//				//ajouter à la fin
//                _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("[%s]\r\n"),lpszSection);
//				lstrcat(lpbuf,szRub);
//                _stprintf(szRub, sizeof(szRub)/sizeof(TCHAR),_T("%s=%s\r\n"),lpszEntry,lpszString);
//				lstrcat(lpbuf,szRub);
//			}

//			if (filelen >= SIZE_CODE_UNICODE)
//			{
//				SetFilePointer(hf, SIZE_CODE_UNICODE, 0, FILE_BEGIN);
//				filelen -= SIZE_CODE_UNICODE;
//			}
//			else if (filelen == 0)
//			{
////				DWORD	dwCodageUnicode = 0xFFFE;		//UNICODE LITTLEENDIAN
//				WORD	dwCodageUnicode = 0xFEFF;		//UNICODE BIGENDIAN
//				// encodage unicode
//				bReturn= WriteFile(hf, &dwCodageUnicode, sizeof(dwCodageUnicode), &nReadSize, NULL);
				
//			}
//			bReturn= WriteFile(hf, lpbuf, lstrlen(lpbuf)*sizeof(TCHAR), &nReadSize, NULL);
//			if (bReturn)
//			{
//				bReturn = SetEndOfFile(hf);
//			}
//			CloseHandle(hf);
//			delete [] lpbuf;
//		}
//	}
	return bReturn;
}




/*(@!*****************************************************************
* Nom                          : bWritePrivateProfileInt
* Role                         : ecriture d'un entier dans le fichier INI
*
*****************************************************************@!)*/
BOOL bWritePrivateProfileInt( LPCTSTR lpszSection, LPCTSTR lpszEntry, int nValue ,QString lpszFileIni)
{
	TCHAR szText[CONV_BUFFER_SIZE];

    _stprintf(szText, sizeof(szText)/sizeof(TCHAR),_T("%d"),nValue);
	return bWritePrivateProfileString(lpszSection, lpszEntry, szText,lpszFileIni);
}

/*(@!*****************************************************************
* Nom                          : iGetPrivateProfileInt
* Role                         : ecriture d'un entier dans le fichier INI
*
*****************************************************************@!)*/
int iGetPrivateProfileInt( LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefaultValue ,QString lpszFileIni)
{
	TCHAR szText[CONV_BUFFER_SIZE];

    dwGetPrivateProfileString(lpszSection,lpszEntry,_T("1"),szText,sizeof(szText) / sizeof(TCHAR),lpszFileIni);
//	if (lstrlen(szText) > 0) nDefaultValue = _ttoi(szText);
    if (lstrlen(szText) > 0) _stscanf( szText, _T("%d"), &nDefaultValue );
    return nDefaultValue;
}

/*(@!*****************************************************************
* Nom                          : WritePrivateProfileFloat
* Role                         : ecriture d'un entier dans le fichier INI
*
*****************************************************************@!)*/
BOOL bWritePrivateProfileFloat( LPCTSTR lpszSection, LPCTSTR lpszEntry, float fValue ,QString lpszFileIni)
{
	TCHAR szText[CONV_BUFFER_SIZE];

    _stprintf(szText, sizeof(szText)/sizeof(TCHAR),_T("%.3f"),fValue);
	return bWritePrivateProfileString(lpszSection, lpszEntry, szText,lpszFileIni);
}


/*(@!*****************************************************************
* Nom                          : fGetPrivateProfileFloat
* Role                         : lecture d'un flottant dans le fichier INI
*
*****************************************************************@!)*/
float fGetPrivateProfileFloat( LPCTSTR lpszSection, LPCTSTR lpszEntry, float fDefaultValue ,QString lpszFileIni)
{
	TCHAR szText[CONV_BUFFER_SIZE];
	
    dwGetPrivateProfileString(lpszSection, lpszEntry,_T(""),szText,sizeof(szText)/sizeof(TCHAR),lpszFileIni );
	if (lstrlen(szText) > 0) _stscanf( szText, _T("%f"), &fDefaultValue );
	return fDefaultValue;
}

long lConvString2Long(LPTSTR szVal)
{
	long lID = 0;
	if ((_tcsstr(szVal,_T("0x")) != NULL) || (_tcsstr(szVal,_T("0X")) != NULL))// c'est une adresse
	{
		_stscanf(szVal,_T("%x"),&lID);
	}
//	else lID = _ttoi(szVal);
    else _stscanf( szVal, _T("%d"), &lID );
    return lID;
}

QString szGetFullPathName(LPTSTR szFileName)
{
//	int iSize;

//	iSize = GetModuleFileName(NULL,szFullPathName,MAX_PATH);

//	while ((iSize>0) && (szFullPathName[iSize-1] != _T('\\'))) {iSize--; szFullPathName[iSize] = 0 ; }
//	lstrcat(szFullPathName,szFileName);
    QString appDirPath = QCoreApplication::applicationDirPath();
    qDebug() << "Application Dir " << appDirPath;
    qDebug() << "File NAME " << QString::fromWCharArray(szFileName);
    QString fullPathName = appDirPath + "/" + QString::fromWCharArray(szFileName);
    qDebug() << "Full Path " << fullPathName ;

    return fullPathName;
}

BOOL bCopyFile( LPCTSTR szSrc, LPCTSTR szDst,BOOL bFailIfExist)
{
	//QMessageBox Box;

	BOOL bReturn;

//	DeleteFile(szDst);
//	bReturn = CopyFile(szSrc,szDst,FALSE);

	if (!bReturn) 
	{
		TRACE_DEBUG(eError,eConfig,_T(__FILE__),_T(__FUNCTION__),__LINE__,_T("Error: fichier %s introuvable"),szSrc);
		/*Box.setText("Error: fichier %s introuvable");
		Box.exec();*/
	}
	
	return bReturn;
}

//Lit jusqu'à la fin d'une ligne à partir d'une position dans le fichier
DWORD bReadLineFromPos(LPCTSTR pszFileName, LPTSTR lpszReturnedString, long& argnPosition)
{
	HANDLE hf;
	BOOL bReturn = FALSE;
	TCHAR *lpbuf = NULL;
	long filelen = 0;
	int iSizeMax = MAX_PATH;
	DWORD nReadSize;
	TCHAR *pStart;
	TCHAR *pEnd;
	
	//Lecture du fichier
//	int ntry = 0;
//	memset(lpszReturnedString, NULL, iSizeMax);
//	do
//	{
//		ntry ++;

//		hf = CreateFile(pszFileName, GENERIC_READ,
//			FILE_SHARE_READ|FILE_SHARE_WRITE,
//			NULL,
//			OPEN_EXISTING,
//			FILE_ATTRIBUTE_NORMAL,
//			NULL);

//		if (hf == INVALID_HANDLE_VALUE)
//		{
//			//TRACE_LOG_MSG(_T("INVALID_HANDLE_VALUE  \n"));

//			filelen = GetLastError();
//			if (filelen == ERROR_ACCESS_DENIED)
//			{
//				//TRACE_LOG_MSG(_T("ERROR_ACCESS_DENIED  \n"));
//				Sleep(50);
//			}
//			else break;
//		}
//	}
//	while ((hf == INVALID_HANDLE_VALUE) && (ntry < 100));

	
//	if (hf != INVALID_HANDLE_VALUE)
//	{
//		filelen = (long)GetFileSize(hf, NULL);
//		if (filelen > 0)
//		{
//			if (filelen >= SIZE_CODE_UNICODE)
//			{
//				SetFilePointer(hf, SIZE_CODE_UNICODE, 0, FILE_BEGIN);
//				filelen -= SIZE_CODE_UNICODE;
//			}
//			lpbuf = new TCHAR[filelen/sizeof(TCHAR) + 2];
//			if (lpbuf)
//			{
				
//				if (ReadFile(hf, lpbuf, filelen, &nReadSize, NULL))
//				{
//					lpbuf[nReadSize/sizeof(TCHAR)] = 0;
//					// debut de la lecture à partir de lpbuf+argnPosition
//					if (pStart = (lpbuf+argnPosition))
//					{
						
						
//						pEnd = _tcsstr(pStart,_T("\r"));
//						if (pEnd == NULL)
//						{
							
//							pEnd = _tcsstr(pStart,_T("\n"));
//						}
						
//						if (pEnd == NULL) pEnd = lpbuf + nReadSize/2;
//						//Taille de la ligne
//						filelen = (int)(pEnd - pStart);
//						if ((filelen > 0) && (filelen < iSizeMax))
//						{
							
//							*pEnd = 0;
//							lstrcpy(lpszReturnedString,pStart);
//						}
//						//Positionnement sur la prochaine ligne
//						argnPosition += filelen+1;

//					}
//				}
//				delete [] lpbuf;
//			}
//		}
//	}
//	CloseHandle(hf);
//	hf = INVALID_HANDLE_VALUE;

	return (lstrlen(lpszReturnedString));
}
