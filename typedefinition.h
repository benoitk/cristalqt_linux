#ifndef TYPEDEFINITION_H
#define TYPEDEFINITION_H
#include <stdio.h>
#include <wchar.h>
#define UNICODE
#define _UNICODE
#include "tchar.h"
#define FALSE false
#define TRUE true
#define CONV_BUFFER_SIZE 64
#define NBR_EXCHANGE_JBUS_MAX 256
#define NBR_MESURE_MAX 4
#define NB_MESURE_MOYENNEE 1
#define __TEXT(a) L##a
#define _T(a) __TEXT(a)
//#define __TEXT(quote) L##quote
#define MAX_PATH 250
#define lstrlenW wcslen
#define lstrlen lstrlenW
#define lstrcpyW wcscpy
#define lstrcpy lstrcpyW
#define lstrcatW wcscat
#define lstrcat lstrcatW
#define lstrcmp wcscmp
typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int SOCKET;
typedef wchar_t WCHAR;
typedef const WCHAR *LPCWSTR, *PCWSTR;
typedef WCHAR *LPWSTR;
typedef LPCWSTR LPCTSTR;
typedef LPWSTR LPTSTR;
typedef void *LPVOID, *HANDLE;
typedef wchar_t TCHAR;
typedef unsigned int SOCKET;
typedef unsigned int UINT;
typedef unsigned short USHORT;
#define INVALID_SOCKET (SOCKET)(~0)
#define INVALID_HANDLE_VALUE (HANDLE)-1

#define HIBYTE(w) ((BYTE)(((WORD)(w)>> 8) &0xFF))
#define LOBYTE(w) ((BYTE)(w))
#define MAKEWORD(a, b) ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))

/* A REMPLACER AVEC QThread::lock(&mutex) */
typedef struct CRITICAL_SECTION{
    unsigned int LockCount;
    HANDLE OwnerThread;

}CRITICAL_SECTION, *LPCRITICAL_SECTION;

struct in_addr{
    union{
        struct { unsigned char s_b1, s_b2, s_b3, s_b4; }S_un_b;
        struct { unsigned short s_w1, s_w2; } S_un_w;
        unsigned long S_addr;
    }S_un;
#define s_addr S_un.S_addr
#define s_host S_un.S_un_b.s_b2
#define s_net S_un.S_un_b.s_b1
#define s_imp S_un.S_un_w.s_w2
#define s_impno S_un.S_un_b.s_b4
#define s_lh S_un.S_un_b.s_b3
};

struct SOCKADDR_IN{
    short sin_family;
    unsigned short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};

typedef struct _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff:1;
    DWORD fOutX:1;
    DWORD fInX:1;
    DWORD fErrorChar:1;
    DWORD fNull:1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:1;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    char XonChar;
    char XoffChar;
    char ErrorChar;
    char EofChar;
    char EvtChar;
    WORD wReserved1;
}DCB, *LPDCB;

#endif // TYPEDEFINITION_H
