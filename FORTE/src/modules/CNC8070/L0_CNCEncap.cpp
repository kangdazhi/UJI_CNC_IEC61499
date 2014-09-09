/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L0_CNCEncap
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2014-09-01/EQUEROL - UJI - null
 *************************************************************************/

#include "L0_CNCEncap.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L0_CNCEncap_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_L0_CNCEncap, g_nStringIdL0_CNCEncap)

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdCmdID, g_nStringIdSD, g_nStringIdPN};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdUINT, g_nStringIdSTRING, g_nStringIdUSINT};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdsBlock};

const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_L0_CNCEncap::scm_anEIWithIndexes[] = {0, 2};
const TDataIOID FORTE_L0_CNCEncap::scm_anEIWith[] = {0, 255, 0, 2, 1, 3, 255};
const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_L0_CNCEncap::scm_anEOWith[] = {0, 255, 0, 1, 255};
const TForteInt16 FORTE_L0_CNCEncap::scm_anEOWithIndexes[] = {0, 2, -1};
const CStringDictionary::TStringId FORTE_L0_CNCEncap::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_L0_CNCEncap::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  4,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_L0_CNCEncap::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
		if (QI()){
			QO() = TRUE;
		}
		else
		{
			QO() = FALSE;
		}
		sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
		//Convert CIEC_STRING in String
		m_pacParamstr = (char*) forte_malloc(sizeof(char) * (SD().length() + 1));
		if (-1 != SD().toString(m_pacParamstr, static_cast<unsigned int>(SD().length() + 1), 1)){
			//Parse received data
			m_nAllocatedstrings = PN();
			if (ParseReceivedData(m_pacParamstr, m_nAllocatedstrings) == m_nAllocatedstrings){
				//Parsing success, remember to free memory
				if (BuildCNCString(CmdID(), m_nAllocatedstrings) > 0){
					//Output string build success

				}
				//free allocated memory
				for (; m_nAllocatedstrings-- > 0;){
					forte_free((void *)m_ppacParamArray[m_nAllocatedstrings]);
				}
				forte_free((void *)m_ppacParamArray);
			}
		}
		forte_free(m_pacParamstr);
		//TODO: Handle errors, how to notify 61499 layer this error
		QI() = 1;
		sendOutputEvent(scm_nEventCNFID);
		break;
  }
}

int FORTE_L0_CNCEncap::ParseReceivedData(char * pa_pacValue, UINT pa_nMembers){
	int nretVal = -1;
	UINT nParsedstr = 0;
	char * pacAux;
	//Allocate space to hold string pointers
	m_ppacParamArray = (char**)forte_malloc(sizeof(char *)*pa_nMembers);

	//Start parsing the received string, params are separed by ","
	pacAux = strtok(pa_pacValue, ",");
	for (;pacAux != NULL && nParsedstr < pa_nMembers; nParsedstr++){
		//Allocate memory to hold parsed strings
		m_ppacParamArray[nParsedstr] = (char *)forte_malloc(sizeof(char)* (strlen(pacAux) + 1));
		strcpy(m_ppacParamArray[nParsedstr], pacAux);
		pacAux = strtok(NULL, ",");
	}
	if (nParsedstr == pa_nMembers){
		nretVal = nParsedstr;
	}
	else{
		//Parsing failed, free allocated space
		for (; nParsedstr-- > 0; ){
			forte_free((void *)m_ppacParamArray[nParsedstr]);
		}
		forte_free((void *)m_ppacParamArray);
		DEVLOG_DEBUG("Parsing parameters failed \n");
	}
	return nretVal;
}

int FORTE_L0_CNCEncap::BuildCNCString(UINT pa_nCmdID, UINT pa_nMembers){
	int retnValue = -1;

	switch (pa_nCmdID){
	case 0:
		break;
	case 7:
		if (pa_nMembers == CNCID_7_PN){
			if (m_ppacParamArray[0][0] == '0'){
				sBlock().fromString("G71");
			}
			else{
				sBlock().fromString("G70");
			}
			retnValue = 1;
		}
		break;
	case 8:
		if (pa_nMembers == CNCID_8_PN){
			if (m_ppacParamArray[0][0] == '0'){
				sBlock().fromString("G90");
			}
			else{
				sBlock().fromString("G91");
			}
			retnValue = 1;
		}
		break;
	case 9:
		if (pa_nMembers == CNCID_9_PN){
			if (m_ppacParamArray[0][0] == '0'){
				sBlock().fromString("G152");
			}
			else{
				sBlock().fromString("G153");
			}
			retnValue = 1;
		}
		break;
	case 10:
		if (pa_nMembers == CNCID_10_PN){
			retnValue = sprintf(m_acBuffer, "V.A.FIXT[%s].X=%s V.A.FIXT[%s].Y=%s V.A.FIXT[%s].Z=%s V.G.FIX=%s",
				m_ppacParamArray[0], m_ppacParamArray[1], m_ppacParamArray[0], m_ppacParamArray[2],
				m_ppacParamArray[0], m_ppacParamArray[3], m_ppacParamArray[0]);
			if (retnValue > 0){
				sBlock().fromString(m_acBuffer);
			}

		}
		break;
	case 11:
		if (pa_nMembers == CNCID_11_PN){
			retnValue = sprintf(m_acBuffer, "V.A.ORGT[%s].X=%s V.A.ORGT[%s].Y=%s V.A.ORGT[%s].Z=%s G159=%s",
				m_ppacParamArray[0], m_ppacParamArray[1], m_ppacParamArray[0], m_ppacParamArray[2],
				m_ppacParamArray[0], m_ppacParamArray[3], m_ppacParamArray[0]);
			if (retnValue > 0){
				sBlock().fromString(m_acBuffer);
			}

		}
		break;
	case 16:
		if (pa_nMembers == CNCID_16_PN){
			retnValue = sprintf(m_acBuffer, "#DGWZ[%s,%s,%s,%s,%s,%s]",
				m_ppacParamArray[0], m_ppacParamArray[1], m_ppacParamArray[2], m_ppacParamArray[3],
				m_ppacParamArray[4], m_ppacParamArray[5]);
			if (retnValue > 0){
				sBlock().fromString(m_acBuffer);
			}

		}
		break;
	case 20: 
		if (CNCID_20_PN_MIN <= pa_nMembers || pa_nMembers <= CNCID_20_PN_MAX){
			switch (pa_nMembers){
			case 1:
				retnValue = sprintf(m_acBuffer, "G00 %s",
					m_ppacParamArray[0]);
				break;
			case 2:
				retnValue = sprintf(m_acBuffer, "G00 %s %s",
					m_ppacParamArray[0], m_ppacParamArray[1]);
				break;
			case 3:
				retnValue = sprintf(m_acBuffer, "G00 %s %s %s",
					m_ppacParamArray[0], m_ppacParamArray[1], m_ppacParamArray[2]);
				break;
			default:
				DEVLOG_ERROR("Error PN out of boundary\n");
				break;
			}
			if (retnValue > 0){
				sBlock().fromString(m_acBuffer);
			}
		}
		break;
	default:
		DEVLOG_ERROR("Requested Command ID not defined\n");
		break;
	}
	return retnValue;
}

