/////////////////////////////////////////////////////////////////////////////
// CSocketTcpClient window
#pragma once
#include "SOCKBASE.H"
class  CSocketTcpClient : public CSocketBase
{
// Construction
public:
	CSocketTcpClient();
	virtual ~CSocketTcpClient();

/////////////////////////////////// FONCTIONS
protected:
	SOCKADDR_IN m_sinClient;
protected:
	virtual long lConnect();          
};

/////////////////////////////////////////////////////////////////////////////
