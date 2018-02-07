//## begin module%3E1CF2FE00F0.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqPSecureFundingAccount.h-arc   1.1   20 Feb 2003 14:29:22   mike  $
//## end module%3E1CF2FE00F0.cm

//## begin module%3E1CF2FE00F0.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3E1CF2FE00F0.cp

//## Module: iqPSecureFundingAccount%3E1CF2FE00F0; Package specification
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Source file: U:\iq\iqSecureFunding\iqPSecureFundingAccount.h

#ifndef iqPSecureFundingAccount
#define iqPSecureFundingAccount 1

//## begin module%3E1CF2FE00F0.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
  //BC end module.additionalIncludes
//## end module%3E1CF2FE00F0.additionalIncludes

//## begin module%3E1CF2FE00F0.includes preserve=yes
//## end module%3E1CF2FE00F0.includes

// iqISecureFundingAccount
#include "iqISecureFundingAccount.h"
//## begin module%3E1CF2FE00F0.declarations preserve=no
//## end module%3E1CF2FE00F0.declarations

//## begin module%3E1CF2FE00F0.additionalDeclarations preserve=yes
//## end module%3E1CF2FE00F0.additionalDeclarations


//## begin AiqPSecureFundingAccount%3E1CEC9402A7.preface preserve=yes
//## end AiqPSecureFundingAccount%3E1CEC9402A7.preface

//## Class: AiqPSecureFundingAccount%3E1CEC9402A7
//## Category: Aiq SecureFunding::Aiq SecureFunding Process%3E1CEC0702FA
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AiqPSecureFundingAccount : public AiqISecureFundingAccount  //## Inherits: <unnamed>%3E1CF2FE00E6
{
  //## begin AiqPSecureFundingAccount%3E1CEC9402A7.initialDeclarations preserve=yes
  //## end AiqPSecureFundingAccount%3E1CEC9402A7.initialDeclarations

  public:
    //## Constructors (generated)
      AiqPSecureFundingAccount();

    //## Destructor (generated)
      virtual ~AiqPSecureFundingAccount();


    //## Other Operations (specified)
      //## Operation: QueryInterface%3E1CF2FE0059
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3E1CF2FE00A0
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3E1CF2FE00AA
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3E1CF2FE00B4
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AiqPSecureFundingAccount%3E1CEC9402A7.public preserve=yes
      //## end AiqPSecureFundingAccount%3E1CEC9402A7.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: AccountKey%3E1CECCE032D
      virtual AbcIAccountKey* AccountKey ();
      virtual void AccountKey (AbcIAccountKey* value);

      //## Attribute: CollateralAmount%3E1CEFE103E3
      virtual AbcICurrency* CollateralAmount ();
      virtual void CollateralAmount (AbcICurrency* value);

      //## Attribute: Rate%3E1CEFF801C9
      virtual RWCString& Rate ();
      virtual void Rate (const RWCString& value);

      //## Attribute: EffectiveDate%3E1CEFFF0378
      virtual AbcIDateTime* EffectiveDate ();
      virtual void EffectiveDate (AbcIDateTime* value);

      //## Attribute: MaturityDate%3E1CF03A0001
      virtual AbcIDateTime* MaturityDate ();
      virtual void MaturityDate (AbcIDateTime* value);      

    // Additional Protected Declarations
      //## begin AiqPSecureFundingAccount%3E1CEC9402A7.protected preserve=yes
      //## end AiqPSecureFundingAccount%3E1CEC9402A7.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3E1CF2FE003B
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqPSecureFundingAccount%3E1CEC9402A7.private preserve=yes
      //## end AiqPSecureFundingAccount%3E1CEC9402A7.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.attr preserve=no  protected: AbcIAccountKey* {U} 
      AbcIAccountKey* m_AccountKey;
      //## end AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.attr

      //## begin AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.attr preserve=no  protected: AbcICurrency* {U} 
      AbcICurrency* m_CollateralAmount;
      //## end AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.attr

      //## begin AiqPSecureFundingAccount::Rate%3E1CEFF801C9.attr preserve=no  protected: RWCString {U} 
      RWCString m_Rate;
      //## end AiqPSecureFundingAccount::Rate%3E1CEFF801C9.attr

      //## begin AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.attr preserve=no  protected: AbcIDateTime* {U} 
      AbcIDateTime* m_EffectiveDate;
      //## end AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.attr

      //## begin AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.attr preserve=no  protected: AbcIDateTime* {U} 
      AbcIDateTime* m_MaturityDate;
      //## end AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.attr

      //## begin AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.attr

    // Additional Implementation Declarations
      //## begin AiqPSecureFundingAccount%3E1CEC9402A7.implementation preserve=yes
      //## end AiqPSecureFundingAccount%3E1CEC9402A7.implementation

};

//## begin AiqPSecureFundingAccount%3E1CEC9402A7.postscript preserve=yes
//## end AiqPSecureFundingAccount%3E1CEC9402A7.postscript

//## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.preface preserve=yes
//## end AiqPSecureFundingAccounts%3E1CF2FE02DA.preface

//## Class: AiqPSecureFundingAccounts%3E1CF2FE02DA
//## Category: Aiq SecureFunding::Aiq SecureFunding Process%3E1CEC0702FA
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AiqPSecureFundingAccounts : public AiqISecureFundingAccounts  //## Inherits: <unnamed>%3E1CF31001DC
{
  //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.initialDeclarations preserve=yes
  //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.initialDeclarations

  public:
    //## Constructors (generated)
      AiqPSecureFundingAccounts();

    //## Destructor (generated)
      virtual ~AiqPSecureFundingAccounts();


    //## Other Operations (specified)
      //## Operation: Get%3E1CF2FE02DF
      long Get (AbcIControlBlock* pControlBlock);

      //## Operation: QueryInterface%3E1CF3100164
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3E1CF31001A0
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3E1CF31001AA
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3E1CF31001B4
      HRESULT FinalConstruct ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Aiq SecureFunding::Aiq SecureFunding Process::<unnamed>%3E1CF3100272
      //## Role: AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274
      virtual AiqISecureFundingAccountList& SecureFundingAccountList ();
      virtual void SecureFundingAccountList (const AiqISecureFundingAccountList& value);

    // Additional Public Declarations
      //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.public preserve=yes
      //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.public

  protected:
    // Additional Protected Declarations
      //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.protected preserve=yes
      //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.protected

  private:

    //## Other Operations (specified)
      //## Operation: InternalGet%3E1CF2FE02DB
      long InternalGet (AbcIControlBlock* pControlBlock, int WhereClauseIndex, int ModifySelectorIndex);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3E1CF310015A
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.private preserve=yes
      //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.attr

    // Data Members for Associations

      //## Association: Aiq SecureFunding::Aiq SecureFunding Process::<unnamed>%3E1CF3100272
      //## begin AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.role preserve=no  public: AiqISecureFundingAccountList { -> 1VHgN}
      AiqISecureFundingAccountList m_SecureFundingAccountList;
      //## end AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.role

    // Additional Implementation Declarations
      //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.implementation preserve=yes
      //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.implementation

};

//## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.postscript preserve=yes
//## end AiqPSecureFundingAccounts%3E1CF2FE02DA.postscript

// Class AiqPSecureFundingAccount 

//## Get and Set Operations for Class Attributes (inline)

inline AbcIAccountKey* AiqPSecureFundingAccount::AccountKey ()
{
  //## begin AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_AccountKey != NULL)
  {
     m_AccountKey->AddRef();
  }
  return m_AccountKey;
  //BC end attribute.accessor
  //## end AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.get
}

inline void AiqPSecureFundingAccount::AccountKey (AbcIAccountKey* value)
{
  //## begin AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.set preserve=yes
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
  //## end AiqPSecureFundingAccount::AccountKey%3E1CECCE032D.set
}

inline AbcICurrency* AiqPSecureFundingAccount::CollateralAmount ()
{
  //## begin AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_CollateralAmount != NULL)
  {
     m_CollateralAmount->AddRef();
  }
  return m_CollateralAmount;
  //BC end attribute.accessor
  //## end AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.get
}

inline void AiqPSecureFundingAccount::CollateralAmount (AbcICurrency* value)
{
  //## begin AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_CollateralAmount != NULL)
  {
     m_CollateralAmount->Release();
  }
  m_CollateralAmount = value;
  if(m_CollateralAmount != NULL)
  {
     m_CollateralAmount->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqPSecureFundingAccount::CollateralAmount%3E1CEFE103E3.set
}

inline RWCString& AiqPSecureFundingAccount::Rate ()
{
  //## begin AiqPSecureFundingAccount::Rate%3E1CEFF801C9.get preserve=no
  return m_Rate;
  //## end AiqPSecureFundingAccount::Rate%3E1CEFF801C9.get
}

inline void AiqPSecureFundingAccount::Rate (const RWCString& value)
{
  //## begin AiqPSecureFundingAccount::Rate%3E1CEFF801C9.set preserve=no
  m_Rate = value;
  //## end AiqPSecureFundingAccount::Rate%3E1CEFF801C9.set
}

inline AbcIDateTime* AiqPSecureFundingAccount::EffectiveDate ()
{
  //## begin AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_EffectiveDate != NULL)
  {
     m_EffectiveDate->AddRef();
  }
  return m_EffectiveDate;
  //BC end attribute.accessor
  //## end AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.get
}

inline void AiqPSecureFundingAccount::EffectiveDate (AbcIDateTime* value)
{
  //## begin AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_EffectiveDate != NULL)
  {
     m_EffectiveDate->Release();
  }
  m_EffectiveDate = value;
  if(m_EffectiveDate != NULL)
  {
     m_EffectiveDate->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqPSecureFundingAccount::EffectiveDate%3E1CEFFF0378.set
}

inline AbcIDateTime* AiqPSecureFundingAccount::MaturityDate ()
{
  //## begin AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_MaturityDate != NULL)
  {
     m_MaturityDate->AddRef();
  }
  return m_MaturityDate;
  //BC end attribute.accessor
  //## end AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.get
}

inline void AiqPSecureFundingAccount::MaturityDate (AbcIDateTime* value)
{
  //## begin AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_MaturityDate != NULL)
  {
     m_MaturityDate->Release();
  }
  m_MaturityDate = value;
  if(m_MaturityDate != NULL)
  {
     m_MaturityDate->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqPSecureFundingAccount::MaturityDate%3E1CF03A0001.set
}

inline long& AiqPSecureFundingAccount::RefCnt ()
{
  //## begin AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.get preserve=no
  return m_RefCnt;
  //## end AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.get
}

inline void AiqPSecureFundingAccount::RefCnt (const long& value)
{
  //## begin AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.set preserve=no
  m_RefCnt = value;
  //## end AiqPSecureFundingAccount::RefCnt%3E1CF2FE003B.set
}

// Class AiqPSecureFundingAccounts 

//## Get and Set Operations for Class Attributes (inline)

inline long& AiqPSecureFundingAccounts::RefCnt ()
{
  //## begin AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.get preserve=no
  return m_RefCnt;
  //## end AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.get
}

inline void AiqPSecureFundingAccounts::RefCnt (const long& value)
{
  //## begin AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.set preserve=no
  m_RefCnt = value;
  //## end AiqPSecureFundingAccounts::RefCnt%3E1CF310015A.set
}

//## Get and Set Operations for Associations (inline)

inline AiqISecureFundingAccountList& AiqPSecureFundingAccounts::SecureFundingAccountList ()
{
  //## begin AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.get preserve=no
  return m_SecureFundingAccountList;
  //## end AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.get
}

inline void AiqPSecureFundingAccounts::SecureFundingAccountList (const AiqISecureFundingAccountList& value)
{
  //## begin AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.set preserve=no
  m_SecureFundingAccountList = value;
  //## end AiqPSecureFundingAccounts::SecureFundingAccountList%3E1CF3100274.set
}

//## begin module%3E1CF2FE00F0.epilog preserve=yes
//## end module%3E1CF2FE00F0.epilog


#endif
