//## begin module%38297D65000A.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/iqDAccountOwner.h-arc   1.0   13 Jun 2002 10:17:22   sddevl  $
//## end module%38297D65000A.cm

//## begin module%38297D65000A.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%38297D65000A.cp

//## Module: iqDAccountOwner%38297D65000A; Package specification
//## Subsystem: iqAccountOwner::iqAccountOwner Data Access%3828851900B4
//## Source file: U:\curwave\iq\iqAccountOwner\iqDAccountOwner.h

#ifndef iqDAccountOwner
#define iqDAccountOwner 1

//## begin module%38297D65000A.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
  //BC end module.additionalIncludes
//## end module%38297D65000A.additionalIncludes

//## begin module%38297D65000A.includes preserve=yes
#include "WVPCRMOWData.h"
//## end module%38297D65000A.includes

// iqIAccountOwner
#include "iqIAccountOwner.h"
// iqIDAccountOwner
#include "iqIDAccountOwner.h"
// bcIAccountKey
#include "bcIAccountKey.h"
//## begin module%38297D65000A.declarations preserve=no
//## end module%38297D65000A.declarations

//## begin module%38297D65000A.additionalDeclarations preserve=yes
//## end module%38297D65000A.additionalDeclarations


//## begin AiqDAccountOwner%37FA464D036E.preface preserve=yes
//## end AiqDAccountOwner%37FA464D036E.preface

//## Class: AiqDAccountOwner%37FA464D036E
//## Category: Aiq Account Owner::Aiq Account Owner Data Access%382885190092
//## Subsystem: iqAccountOwner::iqAccountOwner Data Access%3828851900B4
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38297D920131;AbcIAccountKey { -> }
//## Uses: <unnamed>%3BCC367C016D;AiqIAccountOwners { -> }

class AiqDAccountOwner : public AiqIDAccountOwner  //## Inherits: <unnamed>%38297D640348
{
  //## begin AiqDAccountOwner%37FA464D036E.initialDeclarations preserve=yes
  //## end AiqDAccountOwner%37FA464D036E.initialDeclarations

  public:
    //## Constructors (generated)
      AiqDAccountOwner();

    //## Destructor (generated)
      virtual ~AiqDAccountOwner();


    //## Other Operations (specified)
      //## Operation: Get%37FA46AD0222
      long Get (AbcIAccountKey*const  pIAccountKey, AiqIAccountOwners* pAccountOwners, AbcIControlBlock* pIControlBlock);

      //## Operation: QueryInterface%3828860C0044
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3828860C0148
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3828860C0184
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3828860C01B6
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AiqDAccountOwner%37FA464D036E.public preserve=yes
      //## end AiqDAccountOwner%37FA464D036E.public

  protected:
    // Additional Protected Declarations
      //## begin AiqDAccountOwner%37FA464D036E.protected preserve=yes
      //## end AiqDAccountOwner%37FA464D036E.protected

  private:

    //## Other Operations (specified)
      //## Operation: PopulateData%37FA48D9033A
      long PopulateData (AsdWVPCRMOWData::AsdWVRMOWNO* pOutputData, AiqIAccountOwners* pAccountOwners, AbcIControlBlock* pIControlBlock);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3828860B03D2
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqDAccountOwner%37FA464D036E.private preserve=yes
      long SetSearchCriteria (AsdWVPCRMOWData::AsdWVRMOWNI* pInputDag, AbcIAccountKey* pIAccountKey, AbcIControlBlock* pIControlBlock);
      //## end AiqDAccountOwner%37FA464D036E.private
  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqDAccountOwner::RefCnt%3828860B03D2.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqDAccountOwner::RefCnt%3828860B03D2.attr

    // Additional Implementation Declarations
      //## begin AiqDAccountOwner%37FA464D036E.implementation preserve=yes
      //## end AiqDAccountOwner%37FA464D036E.implementation

};

//## begin AiqDAccountOwner%37FA464D036E.postscript preserve=yes
//## end AiqDAccountOwner%37FA464D036E.postscript

// Class AiqDAccountOwner 

//## Get and Set Operations for Class Attributes (inline)

inline long& AiqDAccountOwner::RefCnt ()
{
  //## begin AiqDAccountOwner::RefCnt%3828860B03D2.get preserve=no
  return m_RefCnt;
  //## end AiqDAccountOwner::RefCnt%3828860B03D2.get
}

inline void AiqDAccountOwner::RefCnt (const long& value)
{
  //## begin AiqDAccountOwner::RefCnt%3828860B03D2.set preserve=no
  m_RefCnt = value;
  //## end AiqDAccountOwner::RefCnt%3828860B03D2.set
}

//## begin module%38297D65000A.epilog preserve=yes
//## end module%38297D65000A.epilog


#endif
