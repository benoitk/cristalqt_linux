#pragma once

class CSocketIHM : public CSocketTcpServeur
{
// Construction
public:
	CSocketIHM();
	virtual ~CSocketIHM();
/////////////////////////////////// FONCTIONS
public:
	// Fonctions normales de connexion  / deconnexion
	virtual long lDispatchTrame(long lExtraHeader,BYTE* lpData,long lSizeTotal,long *plUsed);
    BOOL bReadConfig(QString pszFileName,CListStream *pListStream);
    BOOL bWriteConfig(QString pszFileName);

public:
	CElemCycleStep m_ElemCycleStep;
};

/////////////////////////////////////////////////////////////////////////////
