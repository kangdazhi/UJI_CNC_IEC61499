/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L1_FClosedPocket
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2015-03-03/4DIAC-IDE - 4DIAC-Consortium - 
 *************************************************************************/

#ifndef _L1_FCLOSEDPOCKET_H_
#define _L1_FCLOSEDPOCKET_H_

#include <funcbloc.h>
#include <forte_usint.h>
#include <forte_string.h>
#include "L1_GENFeature.h"
#include "Tool_Table.h"


class FORTE_L1_FClosedPocket: public CFunctionBlock, public L1_GENFeature{
  DECLARE_FIRMWARE_FB(FORTE_L1_FClosedPocket)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &Operation() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_USINT &L1MIDIn() {
    return *static_cast<CIEC_USINT*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_STRING &Cmd() {
    return *static_cast<CIEC_STRING*>(getDO(0));
  };

  CIEC_USINT &L1MIDOut() {
    return *static_cast<CIEC_USINT*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 2, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_L1_FClosedPocket){
  };

  virtual ~FORTE_L1_FClosedPocket(){};

};

#endif //close the ifdef sequence from the beginning of the file

