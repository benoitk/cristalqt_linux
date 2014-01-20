#pragma once

////////////////////////////////////////////////////////////////////////////
// CSerialPort window
class CCarteMesure : public CSerialPort
{
public:
	CCarteMesure();
	virtual ~CCarteMesure();
    BOOL bReadConfig(QString pszFileName,CListStream *pListStream);
    BOOL bWriteConfig(QString pszFileName);

protected:
    //virtual DWORD RunThread();
    virtual void run();
};

/////////////////////////////////////////////////////////////////////////////
