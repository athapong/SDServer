//## begin module.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/include/iqIDSecureFundingInquiry.h-arc   1.1   20 Feb 2003 14:29:36   mike  $
//## end module.cm

//## begin module.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1998, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module.cp

//## Module: iqIDSecureFundingInquiry; Package specification
//## Subsystem: iqSecureFunding::iqSecureFundingInquiry::iqSecureFundingInquiry Local Interface
//## Source file: U:\iq\include\iqIDSecureFundingInquiry.h


#ifndef iqIDSecureFundingInquiry
#define iqIDSecureFundingInquiry 1

//## begin module.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
#include "bcIAccountKey.h"
#include "bcICurrency.h"
  //BC end module.additionalIncludes
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "iqISecureFundingAccount.h"
//## end module.includes

// IUnknown
#include "bcObjBase.h"

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
  //BC begin guid.id DO NOT ADD CODE BETWEEN THESE BC TAGS

// {6D8E3B22-83B7-11D2-A25B-0000F64DA776}
DEFINE_GUID(IID_IAiqIDSecureFundingInquiry, 0x6D8E3B22, 0x83B7, 0x11D2, 0xA2, 0x5B, 0x00, 0x00, 0xF6, 0x4D, 0xA7, 0x76);

  //BC end guid.id
//## end module.additionalDeclarations


//## Class: AbcIDSecureFundingInquiry
//## Category: Aiq SecureFundingInquiry::Aiq SecureFundingInquiry::Aiq SecureFundingInquiry Local Interface
//## Subsystem: iqSecureFundingInquiry::iqSecureFundingInquiry::iqSecureFundingInquiry Local Interface
//## Persistence: Transient
//## Cardinality/Multiplicity: n


class AiqIDSecureFundingInquiry : public IUnknown  //## Inherits: <unnamed>

{
  //## begin AiqIDSecureFundingInquiry.initialDeclarations preserve=yes
  //## end AiqIDSecureFundingInquiry.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Get%910818771
      virtual long Get(AiqISecureFundingAccountList* pAccountList, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock) = 0;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: AccountKey%3D7E0A800068
      virtual AbcIAccountKey* AccountKey () = 0;
      virtual void AccountKey (AbcIAccountKey* value) = 0;

      //## Attribute: TotalCollateralAmount%3D7E0A97021A
      virtual AbcICurrency* TotalCollateralAmount () = 0;
      virtual void TotalCollateralAmount (AbcICurrency* value) = 0;

    // Additional Protected Declarations
      //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.protected preserve=yes
      //## end AiqDSecureFundingInquiry%3D7E0A5A0096.protected


  protected:
    // Additional Protected Declarations
      //## begin AiqDSecureFundingInquiry.protected preserve=yes
      //## end AiqDSecureFundingInquiry.protected


  private:
    // Additional Private Declarations
      //## begin AiqDSecureFundingInquiry.private preserve=yes
      //## end AiqDSecureFundingInquiry.private


  private:  //## implementation
    // Data Members for Class Attributes


};



//## Class: AiqDSecureFundingInquirySp
//## Category: Aiq SecureFundingInquiry::Aiq SecureFundingInquiry::Aiq SecureFundingInquiry Local Interface
//## Subsystem: iqSecureFundingInquiry::iqSecureFundingInquiry::iqSecureFundingInquiry Local Interface
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>; AiqIDSecureFundingInquiry { -> }

typedef AbcComQiPtr<AiqIDSecureFundingInquiry, &IID_IAiqIDSecureFundingInquiry> AiqIDSecureFundingInquirySp;


// Class AiqIDSecureFundingInquiry





// Class AiqIDSecureFundingInquirySp





#endif


