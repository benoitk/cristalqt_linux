#pragma once

////////////////////////////////////////////////////////////////////////////
// CSerialPort window
#define NBR_CMD_WRITE_JBUS_SLAVE_MAX		300
#define NBR_CMD_READ_JBUS_SLAVE_MAX			300

#define BASE_ADDR_WRITE						0x8600
#define BASE_ADDR_READ						0x8610

class CCarteJbusSlave : public CSerialPort
{
public:
	CCarteJbusSlave();
	virtual ~CCarteJbusSlave();
	virtual BOOL bRead(BYTE* lpData,long lSizeDataMax,long *plNbrLu,BOOL bByPass);
    BOOL bReadConfig(QString pszFileName,CListStream *pListStream);
    BOOL bWriteConfig(QString pszFileName);

public:
	CElemList m_ListDataCanRead;
	CElemList m_ListDataCanWrite;

protected:
	virtual long lDispatchTrame(BYTE* lpData,long lSizeTotal);
};

/////////////////////////////////////////////////////////////////////////////
