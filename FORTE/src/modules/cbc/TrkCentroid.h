/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TrkCentroid
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _TRKCENTROID_H_
#define _TRKCENTROID_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>

class FORTE_TrkCentroid : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_TrkCentroid)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_INT &CH(){
      return *static_cast<CIEC_INT*>(getDI(1));
    }
    ;

    CIEC_INT &I_BLOB(){
      return *static_cast<CIEC_INT*>(getDI(2));
    }
    ;

    CIEC_BOOL &INFO(){
      return *static_cast<CIEC_BOOL*>(getDI(3));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_INT &COUNT(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &SIZE(){
      return *static_cast<CIEC_INT*>(getDO(2));
    }
    ;

    CIEC_BOOL &FRAME(){
      return *static_cast<CIEC_BOOL*>(getDO(3));
    }
    ;

    CIEC_INT &X(){
      return *static_cast<CIEC_INT*>(getDO(4));
    }
    ;

    CIEC_INT &Y(){
      return *static_cast<CIEC_INT*>(getDO(5));
    }
    ;

    CIEC_INT &CONFIDENCE(){
      return *static_cast<CIEC_INT*>(getDO(6));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(1, 4, 7, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_TrkCentroid){
  };

  virtual ~FORTE_TrkCentroid(){};

};

#endif //close the ifdef sequence from the beginning of the file
