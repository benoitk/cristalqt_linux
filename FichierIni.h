///////////////////////////////////////////////////////////////////
#pragma once
#include "typedefinition.h"
#include <QString>
 DWORD dwGetPrivateProfileString( LPCTSTR lpszSection, LPCTSTR lpszEntry, LPCTSTR lpszDefault,LPTSTR lpszReturnedString,int iSizeMax,QString lpszFileIni);
 BOOL bWritePrivateProfileString( LPCTSTR lpszSection, LPCTSTR lpszEntry,LPTSTR lpszString,QString lpszFileIni);

 int iGetPrivateProfileInt( LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefaultValue ,QString lpszFileIni);
 BOOL bWritePrivateProfileInt( LPCTSTR lpszSection, LPCTSTR lpszEntry, int nDefaultValue ,QString lpszFileIni);
// lecture d'un float dans le fichier INI
 float fGetPrivateProfileFloat(LPCTSTR lpszSection, LPCTSTR lpszEntry,float fDefaultValue,QString lpszFileIni );
// stockage d'un flottant dans le fichier INI
 BOOL bWritePrivateProfileFloat( LPCTSTR lpszSection, LPCTSTR lpszEntry,float fDefaultValue,QString lpszFileIni );
 long lConvString2Long(LPTSTR szVal);
 QString szGetFullPathName(LPTSTR szFileName);
 BOOL bCopyFile( LPCTSTR szSrc, LPCTSTR szDst,BOOL bFailIfExist);
 DWORD bReadLineFromPos(LPCTSTR pszFileName, LPTSTR lpszReturnedString, long& argnPosition);



