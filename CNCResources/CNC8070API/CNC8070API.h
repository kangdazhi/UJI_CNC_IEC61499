// CNC8070API.h: archivo de encabezado principal del archivo DLL de CNC8070API
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales

#include <initguid.h>
#include "api8070_i.h"
#include "CYStartSink.h"
#include "VariableChangeSink.h"
#include "CNC8070.h"

// CCNC8070APIApp
// Consultar CNC8070API.cpp para realizar la implementaci�n de esta clase
//

class CCNC8070APILib : public CWinApp
{
public:
	CCNC8070CommunicationHandler * m_oHandler;
	CComPtr<IFCDualKernel8070> m_oKernel;
	CComPtr<IFCDualVar8070> m_oVars;
	CComPtr<IFCDualPlc> m_oPlc;
	CCYStartSink m_oCYStartSink;
	DWORD m_dwCYStartSinkCookie;
	CVariableChangeSink m_oVariableChangeSink;
	DWORD m_dwVariableChangeSinkCookie;
	HVAR m_hVarStatus;
	LONG m_lStatus;
	BOOL m_bConnected;
	CStringA m_sCurrentBlock;

public:
	CCNC8070APILib();

// Reemplazos
public:
	virtual BOOL InitInstance();

	inline BOOL IsConnected() { return m_bConnected; }
	BOOL ConnectCNC(CCNC8070CommunicationHandler * a_oHandler);
	BOOL DisconnectCNC();

	BOOL ChkRV(LONG a_lRetVal);

	VOID Start();
	BOOL ExecuteBlock(LPCSTR a_sBlock);
	
	VOID OnNotReady();
	VOID OnReady();
	VOID OnStarted();
	VOID OnExecuting();
	VOID OnInterrupted();
	VOID OnInterruptedByError();

	DECLARE_MESSAGE_MAP()
};

extern CCNC8070APILib theLib;