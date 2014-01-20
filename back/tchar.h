//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this sample source code is subject to the terms of the Microsoft
// license agreement under which you licensed this sample source code. If
// you did not accept the terms of the license agreement, you are not
// authorized to use this sample source code. For the terms of the license,
// please see the license agreement between you and Microsoft or, if applicable,
// see the LICENSE.RTF on your install media or the root of your tools installation.
// THE SAMPLE SOURCE CODE IS PROVIDED "AS IS", WITH NO WARRANTIES.
//
/***
*tchar.h - definitions for generic international text functions
*
*Purpose:
*   This file has been completely revamped to support the full set of CRT-like
*   functionality exported by COREDLL and *only* those functions (v2.10 and later)
*
****/

#ifndef _INC_TCHAR
#define _INC_TCHAR

/*
 * STDLIB is included for legacy reasons.
 */
#include <stdlib.h>

#ifdef  __cplusplus
extern "C" {
#endif

//#define __T(x)      __TEXT(x)
//#define _T(x)       __TEXT(x)

#ifdef  UNICODE
/* ++++++++++++++++++++ UNICODE ++++++++++++++++++++ */

#ifndef __TCHAR_DEFINED
typedef wchar_t         _TCHAR;
typedef wchar_t         _TSCHAR;
typedef wchar_t         _TUCHAR;
typedef wchar_t         _TXCHAR;
typedef wint_t          _TINT;
#define __TCHAR_DEFINED
#endif

#if     !__STDC__
#ifndef _TCHAR_DEFINED
typedef wchar_t         TCHAR, *PTCHAR;
typedef wchar_t         TBYTE, *PTBYTE;
#define _TCHAR_DEFINED
#endif
#define __TEXT(x)       L ## x
#endif

#define _TEOF           WEOF


#define _tmain          wmain

#ifdef UNDER_CE
#   define _tWinMain    WinMain // On CE it's always WinMain
#else
#   define _tWinMain    wWinMain
#endif

/* Formatted i/o */
#define _tprintf        wprintf
#define _tprintf_s      wprintf_s
#define _ftprintf       fwprintf
#define _ftprintf_s     fwprintf_s
#define _stprintf       swprintf
#define _stprintf_s     swprintf_s
#define _sntprintf      _snwprintf
#define _sntprintf_s    _snwprintf_s
#define _vtprintf       vwprintf
#define _vtprintf_s     vwprintf_s
#define _vftprintf      vfwprintf
#define _vftprintf_s    vfwprintf_s
#define _vstprintf      vswprintf
#define _vstprintf_s    vswprintf_s
#define _vsntprintf     _vsnwprintf
#define _vsntprintf_s   _vsnwprintf_s
#define _tscanf         wscanf
#define _tscanf_s       wscanf_s
#define _ftscanf        fwscanf
#define _ftscanf_s      fwscanf_s
#define _stscanf        swscanf
#define _stscanf_s      swscanf_s

/* Unformatted i/o */
#define _fgettc         fgetwc
#define _fgetts         fgetws
#define _fputtc         fputwc
#define _fputts         fputws
#define _gettc          getwc
#define _gettchar       getwchar
#define _getts          _getws
#define _getts_s        _getws_s
#define _puttc          putwc
#define _puttchar       putwchar
#define _putts          _putws
#define _ungettc        ungetwc

// Stdio functions
#define _tfopen         _wfopen
#define _tfopen_s       _wfopen_s
#define _tfreopen       _wfreopen
#define _tfreopen_s     _wfreopen_s

/* String conversion functions */
#define _tcstod         wcstod
#define _tcstol         wcstol
#define _tcstoul        wcstoul

#define _itot           _itow
#define _itot_s         _itow_s
#define _ltot           _ltow
#define _ltot_s         _ltow_s
#define _ultot          _ultow
#define _ultot_s        _ultow_s
#define _ttoi           _wtoi
#define _tstoi          _wtoi
#define _ttol           _wtol
#define _tstol          _wtol
#ifndef UNDER_CE
// Not implemented for CE
#define _ttof           _wtof
#define _tstof          _wtof
#endif
#define _ttoi64         _wtoi64
#define _tstoi64        _wtoi64

/* String functions */
#define _tcscat         wcscat
#define _tcscat_s       wcscat_s
#define _tcschr         wcschr
#define _tcscmp         wcscmp
#define _tcscpy         wcscpy
#define _tcscpy_s       wcscpy_s
#define _tcscspn        wcscspn
#define _tcslen         wcslen
#define _tcsnlen        wcsnlen
#define _tcsclen        wcslen

#define _tcsncat        wcsncat
#define _tcsncat_s      wcsncat_s
#define _tcsnccat       wcsncat
#define _tcsnccmp       wcsncmp
#define _tcsncmp        wcsncmp
#define _tcsncpy        wcsncpy
#define _tcsncpy_s      wcsncpy_s
#define _tcsnccpy       wcsncpy
#define _tcspbrk        wcspbrk
#define _tcsrchr        wcsrchr
#define _tcsspn         wcsspn
#define _tcsstr         wcsstr
#define _tcstok         wcstok
#define _tcstok_s       wcstok_s
#define _tcsdup         _wcsdup
#define _tcsicmp        _wcsicmp
#define _tcsncicmp      _wcsnicmp
#define _tcsnicmp       _wcsnicmp
#define _tcsnset        _wcsnset
#define _tcsnset_s      _wcsnset_s
#define _tcsncset       _wcsnset
#define _tcsrev         _wcsrev
#define _tcsset         _wcsset
#define _tcsset_s       _wcsset_s

#define _tcslwr         _wcslwr
#define _tcslwr_s       _wcslwr_s
#define _tcsupr         _wcsupr
#define _tcsupr_s       _wcsupr_s

// ctype functions
#define _istalpha       iswalpha
#define _istupper       iswupper
#define _istlower       iswlower
#define _istdigit       iswdigit
#define _istxdigit      iswxdigit
#define _istspace       iswspace
#define _istpunct       iswpunct
#define _istalnum       iswalnum
#define _istprint       iswprint
#define _istgraph       iswgraph
#define _istcntrl       iswcntrl
#define _istascii       iswascii

#define _totupper       towupper
#define _totlower       towlower

#define _istlegal(_c)       (1)
#define _istlead(_c)        (0)
#define _istleadbyte(_c)    (0)

#else   /* ndef UNICODE */

///* ++++++++++++++++++++ SBCS (MBCS is not supported) ++++++++++++++++++++ */

//#ifndef __TCHAR_DEFINED
//typedef char            _TCHAR;
//typedef signed char     _TSCHAR;
//typedef unsigned char   _TUCHAR;
//typedef unsigned char   _TXCHAR;
//typedef unsigned int    _TINT;
//#define __TCHAR_DEFINED
//#endif

//#if     !__STDC__
//#ifndef _TCHAR_DEFINED
//typedef char            TCHAR, *PTCHAR;
//typedef unsigned char   TBYTE, *PTBYTE;
//#define _TCHAR_DEFINED
//#endif
//#define __TEXT(x)       x
//#endif

//#define _TEOF           EOF


///* Program */
//#define _tmain          main
//#define _tWinMain       WinMain


///* Formatted i/o */
//#define _tprintf        printf
//#define _tprintf_s      printf_s
//#define _ftprintf       fprintf
//#define _ftprintf_s     fprintf_s
//#define _stprintf       sprintf
//#define _stprintf_s     sprintf_s
//#define _sntprintf      _snprintf
//#define _sntprintf_s    _snprintf_s
//#define _vtprintf       vprintf
//#define _vtprintf_s     vprintf_s
//#define _vftprintf      vfprintf
//#define _vftprintf_s    vfprintf_s
//#define _vstprintf      vsprintf
//#define _vstprintf_s    vsprintf_s
//#define _vsntprintf     _vsnprintf
//#define _vsntprintf_s   _vsnprintf_s
//#define _tscanf         scanf
//#define _tscanf_s       scanf_s
//#define _ftscanf        fscanf
//#define _ftscanf_s      fscanf_s
//#define _stscanf        sscanf
//#define _stscanf_s      sscanf_s

///* Unformatted i/o */
//#define _fgettc         fgetc
//#define _fgetts         fgets
//#define _fputtc         fputc
//#define _fputts         fputs
//#define _gettc          getc
//#define _gettchar       getchar
//#define _getts          gets
//#define _getts_s        gets_s
//#define _puttc          putc
//#define _puttchar       putchar
//#define _putts          puts
//#define _ungettc        ungetc

//// Stdio functions
//#define _tfopen         _fopen
//#define _tfopen_s       _fopen_s

//#ifndef UNDER_CE
//// Not implemented for CE
//#define _tfreopen       _freopen
//#define _tfreopen_s     _freopen_s
//#endif

//// String conversion functions
//#define _tcstod         strtod
//#define _tcstol         strtol
//#define _tcstoul        strtoul
//#define _itot           _itoa
//#define _itot_s         _itoa_s
//#define _ltot           _ltoa
//#define _ltot_s         _ltoa_s
//#define _ultot          _ultoa
//#define _ultot_s        _ultoa_s
//#define _ttoi           atoi
//#define _tstoi          atoi
//#define _ttol           atol
//#define _tstol          atol
//#define _ttof           atof
//#define _tstof          atof
//#define _ttoi64         _atoi64
//#define _tstoi64        _atoi64

///* String functions */
//#define _tcscat         strcat
//#define _tcscat_s       strcat_s
//#define _tcschr         strchr
//#define _tcscmp         strcmp
//#define _tcscpy         strcpy
//#define _tcscpy_s       strcpy_s
//#define _tcscspn        strcspn
//#define _tcslen         strlen
//#define _tcsnlen        strnlen
//#define _tcsclen        strlen

//#define _tcsncat        strncat
//#define _tcsncat_s      strncat_s
//#define _tcsnccat       strncat
//#define _tcsnccmp       strncmp
//#define _tcsncmp        strncmp
//#define _tcsncpy        strncpy
//#define _tcsncpy_s      strncpy_s
//#define _tcsnccpy       strncpy
//#define _tcspbrk        strpbrk
//#define _tcsrchr        strrchr
//#define _tcsspn         strspn
//#define _tcsstr         strstr
//#define _tcstok         strtok
//#define _tcstok_s       strtok_s
//#define _tcsdup         _strdup
//#define _tcsicmp        _stricmp
//#define _tcsncicmp      _strnicmp
//#define _tcsnicmp       _strnicmp
//#define _tcsnset        _strnset
//#define _tcsnset_s      _strnset_s
//#define _tcsncset       _strnset
//#define _tcsrev         _strrev
//#define _tcsset         _strset
//#define _tcsset_s       _strset_s
//#define _tcslwr         _strlwr
//#define _tcslwr_s       _strlwr_s
//#define _tcsupr         _strupr
//#define _tcsupr_s       _strupr_s

//// ctype functions
//#define _istalpha       isalpha
//#define _istupper       isupper
//#define _istlower       islower
//#define _istdigit       isdigit
//#define _istxdigit      isxdigit
//#define _istspace       isspace
//#define _istpunct       ispunct
//#define _istalnum       isalnum
//#define _istprint       isprint
//#define _istgraph       isgraph
//#define _istcntrl       iscntrl
//#define _istascii       isascii

//#define _totupper       toupper
//#define _totlower       tolower

//#define _istlegal(_c)       (1)
//#define _istlead(_c)        (0)
//#define _istleadbyte(_c)    (0)

#endif  /* UNICODE */

#ifdef __cplusplus
}
#endif

#endif  /* _INC_TCHAR */
