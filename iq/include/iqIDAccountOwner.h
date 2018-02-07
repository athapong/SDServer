//## begin module%38297D65005A.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/include/iqIDAccountOwner.h-arc   1.0   13 Jun 2002 10:17:20   sddevl  $
//## end module%38297D65005A.cm

//## begin module%38297D65005A.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%38297D65005A.cp

//## Module: iqIDAccountOwner%38297D65005A; Package specification
//## Subsystem: iqAccountOwner::iqAccountOwner Local Interface%3828851900A9
//## Source file: U:\curwave\iq\include\iqIDAccountOwner.h

#ifndef iqIDAccountOwner
#define iqIDAccountOwner 1

//## begin module%38297D65005A.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
  //BC end module.additionalIncludes
//## end module%38297D65005A.additionalIncludes

//## begin module%38297D65005A.includes preserve=yes
//## end module%38297D65005A.includes

// iqIAccountOwner
#include "iqIAccountOwner.h"
// IUnknown
#include "bcObjBase.h"
// bcIAccountKey
#include "bcIAccountKey.h"
//## begin module%38297D65005A.declarations preserve=no
//## end module%38297D65005A.declarations

//## begin module%38297D65005A.additionalDeclarations preserve=yes
class AiqPAccountOwners;
  //BC begin guid.id DO NOT ADD CODE BETWEEN THESE BC TAGS

// {161642D3-592A-4C24-9E14-B4B2EA963FBB}
DEFINE_GUID(IID_IAiqIDAccountOwner, 0x161642D3, 0x592A, 0x4C24, 0x9E, 0x14, 0xB4, 0xB2, 0xEA, 0x96, 0x3F, 0xBB);

  //BC end guid.id
//## end module%38297D65005A.additionalDeclarations


//## begin AiqIDAccountOwner%38297D6402DA.preface preserve=yes
//## end AiqIDAccountOwner%38297D6402DA.preface

//## Class: AiqIDAccountOwner%38297D6402DA
//## Category: Aiq Account Owner::Aiq Account Owner Local Interface%38288519008C
//## Subsystem: iqAccountOwner::iqAccountOwner Local Interface%3828851900A9
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38297E980048;AbcIAccountKey { -> }
//## Uses: <unnamed>%3BCC3E6200F2;AiqIAccountOwners { -> }

class AiqIDAccountOwner : public IUnknown  //## Inherits: <unnamed>%38297D640349
{
  //## begin AiqIDAccountOwner%38297D6402DA.initialDeclarations preserve=yes
  //## end AiqIDAccountOwner%38297D6402DA.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Get%38297D6402DB
      virtual long Get (AbcIAccountKey*const  pIAccountKey, AiqIAccountOwners* pAccountOwners, AbcIControlBlock* pIControlBlock) = 0;

    // Additional Public Declarations
      //## begin AiqIDAccountOwner%38297D6402DA.public preserve=yes
      //## end AiqIDAccountOwner%38297D6402DA.public

  protected:
    // Additional Protected Declarations
      //## begin AiqIDAccountOwner%38297D6402DA.protected preserve=yes
      //## end AiqIDAccountOwner%38297D6402DA.protected

  private:
    // Additional Private Declarations
      //## begin AiqIDAccountOwner%38297D6402DA.private preserve=yes
      //## end AiqIDAccountOwner%38297D6402DA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin AiqIDAccountOwner%38297D6402DA.implementation preserve=yes
      //## end AiqIDAccountOwner%38297D6402DA.implementation

};

//## begin AiqIDAccountOwner%38297D6402DA.postscript preserve=yes
//## end AiqIDAccountOwner%38297D6402DA.postscript

//## begin AiqIDAccountOwnerSp%38297D6402E5.preface preserve=yes
//## end AiqIDAccountOwnerSp%38297D6402E5.preface

//## Class: AiqIDAccountOwnerSp%38297D6402E5
//## Category: Aiq Account Owner::Aiq Account Owner Local Interface%38288519008C
//## Subsystem: iqAccountOwner::iqAccountOwner Local Interface%3828851900A9
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38297D640352;AiqIDAccountOwner { -> }

typedef AbcComQiPtr<AiqIDAccountOwner, &IID_IAiqIDAccountOwner> AiqIDAccountOwnerSp;

//## begin AiqIDAccountOwnerSp%38297D6402E5.postscript preserve=yes
//## end AiqIDAccountOwnerSp%38297D6402E5.postscript

// Class AiqIDAccountOwner 

//## begin module%38297D65005A.epilog preserve=yes
//## end module%38297D65005A.epilog


#endif
