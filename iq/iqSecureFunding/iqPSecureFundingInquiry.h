//## begin module%3E1CF47900A5.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqPSecureFundingInquiry.h-arc   1.1   20 Feb 2003 14:29:22   mike  $
//## end module%3E1CF47900A5.cm

//## begin module%3E1CF47900A5.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3E1CF47900A5.cp

//## Module: iqPSecureFundingInquiry%3E1CF47900A5; Package specification
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Source file: U:\iq\iqSecureFunding\iqPSecureFundingInquiry.h

#ifndef iqPSecureFundingInquiry
#define iqPSecureFundingInquiry 1

//## begin module%3E1CF47900A5.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
#include "bcICurrency.h"
  //BC end module.additionalIncludes
//## end module%3E1CF47900A5.additionalIncludes

//## begin module%3E1CF47900A5.includes preserve=yes
//## end module%3E1CF47900A5.includes

// iqISecureFundingInquiry
#include "iqISecureFundingInquiry.h"
//## begin module%3E1CF47900A5.declarations preserve=no
//## end module%3E1CF47900A5.declarations

//## begin module%3E1CF47900A5.additionalDeclarations preserve=yes
//## end module%3E1CF47900A5.additionalDeclarations
#include "iqIDSecureFundingInquiry.h"


//## begin AiqPSecureFundingInquiry%3E1CF3290386.preface preserve=yes
//## end AiqPSecureFundingInquiry%3E1CF3290386.preface

//## Class: AiqPSecureFundingInquiry%3E1CF3290386
//## Category: Aiq SecureFunding::Aiq SecureFunding Process%3E1CEC0702FA
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AiqPSecureFundingInquiry : public AiqISecureFundingInquiry  //## Inherits: <unnamed>%3E1CF479009B
{
  //## begin AiqPSecureFundingInquiry%3E1CF3290386.initialDeclarations preserve=yes
  //## end AiqPSecureFundingInquiry%3E1CF3290386.initialDeclarations

  public:
    //## Constructors (generated)
      AiqPSecureFundingInquiry();

    //## Destructor (generated)
      virtual ~AiqPSecureFundingInquiry();


    //## Other Operations (specified)
      //## Operation: Get%3E1CF3E701E5
      long Get (AbcIAccountKey* AccountKey, AbcIControlBlock* ControlBlock);

      //## Operation: QueryInterface%3E1CF4790022
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3E1CF479005E
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3E1CF4790068
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3E1CF4790072
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AiqPSecureFundingInquiry%3E1CF3290386.public preserve=yes
      //## end AiqPSecureFundingInquiry%3E1CF3290386.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: TotalCollateralAmount%3E1CF3C10231
      virtual AbcICurrency* TotalCollateralAmount ();
      virtual void TotalCollateralAmount (AbcICurrency* value);

      //## Attribute: AccountKey%3E1CF3D5035C
      virtual AbcIAccountKey* AccountKey ();
      virtual void AccountKey (AbcIAccountKey* value);

      //## Attribute: SecureFundingAccounts%3E1D1E7100CC
      virtual AiqISecureFundingAccounts* SecureFundingAccounts ();
      virtual void SecureFundingAccounts (AiqISecureFundingAccounts* value);

    // Additional Protected Declarations
      //## begin AiqPSecureFundingInquiry%3E1CF3290386.protected preserve=yes
      //## end AiqPSecureFundingInquiry%3E1CF3290386.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3E1CF4790004
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqPSecureFundingInquiry%3E1CF3290386.private preserve=yes
      //## end AiqPSecureFundingInquiry%3E1CF3290386.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.attr preserve=no  protected: AbcICurrency* {U} 
      AbcICurrency* m_TotalCollateralAmount;
      //## end AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.attr

      //## begin AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.attr preserve=no  protected: AbcIAccountKey* {U} 
      AbcIAccountKey* m_AccountKey;
      //## end AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.attr

      //## begin AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.attr preserve=no  protected: AiqISecureFundingAccounts* {U} 
      AiqISecureFundingAccounts* m_SecureFundingAccounts;
      //## end AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.attr

      //## begin AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.attr

    // Additional Implementation Declarations
      //## begin AiqPSecureFundingInquiry%3E1CF3290386.implementation preserve=yes
      //## end AiqPSecureFundingInquiry%3E1CF3290386.implementation

};

//## begin AiqPSecureFundingInquiry%3E1CF3290386.postscript preserve=yes
//## end AiqPSecureFundingInquiry%3E1CF3290386.postscript

// Class AiqPSecureFundingInquiry 

//## Get and Set Operations for Class Attributes (inline)

inline AbcICurrency* AiqPSecureFundingInquiry::TotalCollateralAmount ()
{
  //## begin AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->AddRef();
  }
  return m_TotalCollateralAmount;
  //BC end attribute.accessor
  //## end AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.get
}

inline void AiqPSecureFundingInquiry::TotalCollateralAmount (AbcICurrency* value)
{
  //## begin AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.set preserve=yes
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
  //## end AiqPSecureFundingInquiry::TotalCollateralAmount%3E1CF3C10231.set
}

inline AbcIAccountKey* AiqPSecureFundingInquiry::AccountKey ()
{
  //## begin AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_AccountKey != NULL)
  {
     m_AccountKey->AddRef();
  }
  return m_AccountKey;
  //BC end attribute.accessor
  //## end AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.get
}

inline void AiqPSecureFundingInquiry::AccountKey (AbcIAccountKey* value)
{
  //## begin AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.set preserve=yes
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
  //## end AiqPSecureFundingInquiry::AccountKey%3E1CF3D5035C.set
}

inline AiqISecureFundingAccounts* AiqPSecureFundingInquiry::SecureFundingAccounts ()
{
//## begin AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_SecureFundingAccounts != NULL)
  {
     m_SecureFundingAccounts->AddRef();
  }
  return m_SecureFundingAccounts;
  //BC end attribute.accessor
  //## end AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.get
}

inline void AiqPSecureFundingInquiry::SecureFundingAccounts (AiqISecureFundingAccounts* value)
{
//## begin AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_SecureFundingAccounts != NULL)
  {
     m_SecureFundingAccounts->Release();
  }
  m_SecureFundingAccounts = value;
  if(m_SecureFundingAccounts != NULL)
  {
     m_SecureFundingAccounts->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqPSecureFundingInquiry::SecureFundingAccounts%3E1D1E7100CC.set
}

inline long& AiqPSecureFundingInquiry::RefCnt ()
{
  //## begin AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.get preserve=no
  return m_RefCnt;
  //## end AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.get
}

inline void AiqPSecureFundingInquiry::RefCnt (const long& value)
{
  //## begin AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.set preserve=no
  m_RefCnt = value;
  //## end AiqPSecureFundingInquiry::RefCnt%3E1CF4790004.set
}

//## begin module%3E1CF47900A5.epilog preserve=yes
//## end module%3E1CF47900A5.epilog


#endif
