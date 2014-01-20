#pragma once

////////////////////////////////////////////////////////////////////////////
// CSerialPort window
class CCarteIO : public CSerialPort
{
public:
	CCarteIO();
	virtual ~CCarteIO();
//	virtual void Stop();
    BOOL bReadConfig(QString pszFileName,CListStream *pListStream);
    BOOL bWriteConfig(QString pszFileName);
protected:
    //virtual DWORD RunThread();
    virtual void run();
public:
	CElemCycleStep m_ElemCycleStep;
protected:
	DWORD m_dwDelay;
};

/////////////////////////////////////////////////////////////////////////////
