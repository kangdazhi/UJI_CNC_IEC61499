/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_SendBlk
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-08-25/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_SendBlk.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_SendBlk_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_SendBlk, g_nStringIdL0_SendBlk)

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdsBlock};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdCNCState};

const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUSINT};

const TForteInt16 FORTE_L0_SendBlk::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_L0_SendBlk::scm_anEIWith[] = {0, 1, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L0_SendBlk::scm_anEOWith[] = {0, 255, 0, 255, 1, 255};
const TForteInt16 FORTE_L0_SendBlk::scm_anEOWithIndexes[] = {0, 2, 4, -1};
const CStringDictionary::TStringId FORTE_L0_SendBlk::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF, g_nStringIdIND};

const SFBInterfaceSpec FORTE_L0_SendBlk::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  3,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L0_SendBlk::setInitialValues(){
  CNCState() = 0;
}

void FORTE_L0_SendBlk::RetreiveCmd(){
	m_CmdList.clear();
	std::istringstream iss;
	char * pacTempString = (char*)forte_malloc(sizeof(char)* (sBlock().length() + 1));
	if (pacTempString != NULL){
		if (-1 != sBlock().toString(pacTempString, static_cast<unsigned int>(sBlock().length() + 1), 1)){
			iss.str(std::string(pacTempString));
			boost::archive::text_iarchive ia(iss);
			ia >> m_CmdList;
			ia.delete_created_pointers();
		}
		forte_free(pacTempString);
		pacTempString = NULL;
	}
	else{
		DEVLOG_ERROR("Allocation error while desirealizing in L0_SendBlk\n");
	}
}
void FORTE_L0_SendBlk::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		if (QI()){
			CNC8070Connect(this);
			QO() = TRUE;
		}
		else{
			CNC8070Disconnect();
			QO() = FALSE;
		}
		sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
		RetreiveCmd();
		if (!m_CmdList.empty()){
			CNC8070Start();
		}
		else{
			DEVLOG_INFO("Empty command vector\n");
			//Check operation as completed, CNC state will remain the same
			sendOutputEvent(scm_nEventINDID);
		}
		sendOutputEvent(scm_nEventCNFID);
      break;
	case cg_nExternalEventID:
		sendOutputEvent(scm_nEventINDID);
		break;
	default:
		DEVLOG_ERROR("Event Input ID out of range\n");
		break;
  }
}

//CNC8070ComunicationHandler methods implementation

void FORTE_L0_SendBlk::Log(LOGTYPE a_lType, const char * a_lMsg)
{
	switch(a_lType){
	case LOG_OUTPUT:
		DEVLOG_DEBUG(a_lMsg);
		break;
	case LOG_ERROR:
		DEVLOG_ERROR(a_lMsg);
		break;
	case LOG_INFORMATION:
		DEVLOG_INFO(a_lMsg);
		break;
	case LOG_WARNING:
		DEVLOG_WARNING(a_lMsg);
		break;
	default:
		DEVLOG_ERROR(a_lMsg);
		break;
	}
}

void FORTE_L0_SendBlk::OnNotReady()
{
	DEVLOG_INFO("CNC not Ready\n");
	CNCState() = 0;
	if (getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID_inh)){
		getDeviceExecution()->startNewEventChain(this);
	}
	else{
		DEVLOG_DEBUG("External Event Not allowed\n");
	}
}

void FORTE_L0_SendBlk::OnReady()
{
	DEVLOG_INFO("CNC Ready\n");
	CNCState() = 1;
	if (!m_CmdList.empty()){
		//Keep sending commands until the list is empty
		CNC8070Start();
	}
	else{
		//Operation execution completed
		if (getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID_inh)){
			getDeviceExecution()->startNewEventChain(this);
		}
		else{
			DEVLOG_DEBUG("External Event Not allowed\n");
		}
	}
}

void FORTE_L0_SendBlk::OnStarted()
{
	DEVLOG_INFO("CNC Started\n");
	//Execute 1st command in the list and delete it after
	CNC8070ExecuteBlock(m_CmdList.front().c_str());
	m_CmdList.pop_front();
}

void FORTE_L0_SendBlk::OnExecuting()
{
	DEVLOG_INFO("CNC Executing\n");
	CNCState() = 2;
	if (getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID_inh)){
		getDeviceExecution()->startNewEventChain(this);
	}
	else{
		DEVLOG_DEBUG("External Event Not allowed\n");
	}

}

void FORTE_L0_SendBlk::OnInterrupted()
{
	DEVLOG_INFO("CNC Execution Interrupted\n");
	CNCState() = 3;
	if (getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID_inh)){
		getDeviceExecution()->startNewEventChain(this);
	}
	else{
		DEVLOG_DEBUG("External Event Not allowed\n");
	}
}

void FORTE_L0_SendBlk::OnInterruptedByError()
{
	DEVLOG_ERROR("CNC unexpected error\n");
	CNCState() = 4;
	if (getDeviceExecution()->extEvHandlerIsAllowed(m_nExtEvHandID_inh)){
		getDeviceExecution()->startNewEventChain(this);
	}
	else{
		DEVLOG_DEBUG("External Event Not allowed\n");
	}
}

void FORTE_L0_SendBlk::OnMagazineUpdateAdd(const char * pa_sID, int pa_nPos, int pa_nState, long pa_nLocalID){
	Tool_Table::addTool(Tool(std::string(pa_sID), pa_nPos, (Tool_State) pa_nState, pa_nLocalID));
}

void FORTE_L0_SendBlk::OnMagazineUpdateDelete(){
	Tool_Table::deleteTable();
}

void FORTE_L0_SendBlk::OnMagazineUpdateDelete(const char * pa_sID, int pa_nPos, int pa_nState, long pa_lITool){

}
//CExternalEventsHandler methods implementation
void FORTE_L0_SendBlk::enableHandler(void){

}

void FORTE_L0_SendBlk::disableHandler(void){

}

void FORTE_L0_SendBlk::setPriority(int pa_nPriority){

}

int FORTE_L0_SendBlk::getPriority(void) const{
	return 1;
}


