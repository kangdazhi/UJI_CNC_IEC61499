/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: F_REAL_TO_UDINT
 *** Description: convert REAL to UDINT
 *** Version: 
 ***     0.0: 2011-07-21/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "F_REAL_TO_UDINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_REAL_TO_UDINT_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_F_REAL_TO_UDINT, g_nStringIdF_REAL_TO_UDINT)

const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anDataOutputTypeIds[] = {g_nStringIdUDINT};

const TForteInt16 FORTE_F_REAL_TO_UDINT::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_REAL_TO_UDINT::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_REAL_TO_UDINT::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_F_REAL_TO_UDINT::scm_anEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_REAL_TO_UDINT::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_REAL_TO_UDINT::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_REAL_TO_UDINT::executeEvent(int pa_nEIID){
  if(scm_nEventREQID == pa_nEIID){
	  OUT() = REAL_TO_UDINT(IN());
	  sendOutputEvent(scm_nEventCNFID);
  }
}



