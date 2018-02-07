//## begin module.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqDSecureFundingInquiry.h-arc   1.1   20 Feb 2003 14:29:18   mike  $
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

//## Module: iqDSecureFundingInquiry; Package specification
//## Subsystem: iqSecureFunding::iqSecureFundingInquiry::iqSecureFundingInquiry Data Access
//## Source file: U:\iq\iqSecureFunding\iqDSecureFundingInquiry.h


#ifndef iqDSecureFundingInquiry
#define iqDSecureFundingInquiry 1

//## begin module.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
  //BC end module.additionalIncludes
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// iqISecureFundingInquiry
#include "iqIDSecureFundingInquiry.h"

#include "SDPCIMODData.h"

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


//## Class: AiqDSecureFundingInquiry
//## Category: Aiq SecureFunding::Aiq SecureFundingInquiry::Aiq SecureFundingInquiry Data Access
//## Subsystem: iqSecureFunding::iqSecureFundingInquiry::iqSecureFundingInquiry Data Access
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AiqDSecureFundingInquiry : public AiqIDSecureFundingInquiry  //## Inherits: <unnamed>%3D7E0E5201D7
{
  //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.initialDeclarations preserve=yes
  //## end AiqDSecureFundingInquiry%3D7E0A5A0096.initialDeclarations

  public:
    //## Constructors (generated)
      AiqDSecureFundingInquiry();

    //## Destructor (generated)
      virtual ~AiqDSecureFundingInquiry();


    //## Other Operations (specified)
      //## Operation: Get%3D7E0B5B00EF
      long Get (AiqISecureFundingAccountList* pTransList, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock);

      //## Operation: GetHostData%910818764
      long GetHostData(AiqISecureFundingAccountList* pTransList, AsdSDPCIMODData& SDPCIMOD, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock);

      //## Operation: ReadResults%910818765
      long ReadResults(AiqISecureFundingAccountList* pTransList, AsdSDPCIMODData::AsdSDIMODP* pSDIMODP, AbcIControlBlock* pControlBlock);

      //## Operation: InitializeInput%910818766
      long InitializeInput(AsdSDPCIMODData::AsdSDIMODP* pSDIMODP, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock);

      //## Operation: QueryInterface%3D7E0E520119
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3D7E0E520169
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3D7E0E52017D
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3D7E0E520187
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.public preserve=yes
      //## end AiqDSecureFundingInquiry%3D7E0A5A0096.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: AccountKey%3D7E0A800068
      virtual AbcIAccountKey* AccountKey ();
      virtual void AccountKey (AbcIAccountKey* value);

      //## Attribute: TotalCollateralAmount%3D7E0A97021A
      virtual AbcICurrency* TotalCollateralAmount ();
      virtual void TotalCollateralAmount (AbcICurrency* value);

    // Additional Protected Declarations
      //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.protected preserve=yes
      //## end AiqDSecureFundingInquiry%3D7E0A5A0096.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3D7E0E5200FB
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.private preserve=yes
      //## end AiqDSecureFundingInquiry%3D7E0A5A0096.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.attr preserve=no  protected: AbcIAccountKey* {U} 
      AbcIAccountKey* m_AccountKey;
      //## end AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.attr

      //## begin AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.attr preserve=no  protected: AbcICurrency* {U} 
      AbcICurrency* m_TotalCollateralAmount;
      //## end AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.attr

      //## begin AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.attr


    // Additional Implementation Declarations
      //## begin AiqDSecureFundingInquiry%3D7E0A5A0096.implementation preserve=yes
      //## end AiqDSecureFundingInquiry%3D7E0A5A0096.implementation

};

//## begin AiqDSecureFundingInquiry%3D7E0A5A0096.postscript preserve=yes
//## end AiqDSecureFundingInquiry%3D7E0A5A0096.postscript

// Class AiqDSecureFundingInquiry 

//## Get and Set Operations for Class Attributes (inline)

inline AbcIAccountKey * AiqDSecureFundingInquiry::AccountKey ()
{
  //## begin AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_AccountKey != NULL)
  {
     m_AccountKey->AddRef();
  }
  return m_AccountKey;
  //BC end attribute.accessor
  //## end AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.get
}

inline void AiqDSecureFundingInquiry::AccountKey (AbcIAccountKey * value)
{
  //## begin AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_AccountKey != NULL)
  {
     m_AccountKey->Release();
  }
  m_AccountKey = value;
  if(m_AccountKey != NULL)
  {
     m_AccountKey->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqDSecureFundingInquiry::AccountKey%3D7E0A800068.set
}

inline AbcICurrency * AiqDSecureFundingInquiry::TotalCollateralAmount ()
{
  //## begin AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->AddRef();
  }
  return m_TotalCollateralAmount;
  //BC end attribute.accessor
  //## end AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.get
}

inline void AiqDSecureFundingInquiry::TotalCollateralAmount (AbcICurrency * value)
{
  //## begin AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->Release();
  }
  m_TotalCollateralAmount = value;
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqDSecureFundingInquiry::TotalCollateralAmount%3D7E0A97021A.set
}

inline long& AiqDSecureFundingInquiry::RefCnt ()
{
  //## begin AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.get preserve=no
  return m_RefCnt;
  //## end AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.get
}

inline void AiqDSecureFundingInquiry::RefCnt (const long& value)
{
  //## begin AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.set preserve=no
  m_RefCnt = value;
  //## end AiqDSecureFundingInquiry::RefCnt%3D7E0E5200FB.set
}

//## begin module%3D7E0E5201E1.epilog preserve=yes
//## end module%3D7E0E5201E1.epilog


#endif

