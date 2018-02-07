//## begin module%3829E17B0099.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/iqPAccountOwner.h-arc   1.0   13 Jun 2002 10:17:24   sddevl  $
//## end module%3829E17B0099.cm

//## begin module%3829E17B0099.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3829E17B0099.cp

//## Module: iqPAccountOwner%3829E17B0099; Package specification
//## Subsystem: iqAccountOwner::iqAccountOwner Process%3828851900B3
//## Source file: U:\iq\iqAccountOwner\iqPAccountOwner.h

#ifndef iqPAccountOwner
#define iqPAccountOwner 1

//## begin module%3829E17B0099.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
#include "bcIAccountKey.h"
#include "bcIUserParam.h"
  //BC end module.additionalIncludes
//## end module%3829E17B0099.additionalIncludes

//## begin module%3829E17B0099.includes preserve=yes
//## end module%3829E17B0099.includes

// iqIAccountOwner
#include "iqIAccountOwner.h"
//## begin module%3829E17B0099.declarations preserve=no
//## end module%3829E17B0099.declarations

//## begin module%3829E17B0099.additionalDeclarations preserve=yes
//## end module%3829E17B0099.additionalDeclarations


//## begin AiqPAccountOwner%37FA1D44014C.preface preserve=yes
//## end AiqPAccountOwner%37FA1D44014C.preface

//## Class: AiqPAccountOwner%37FA1D44014C
//## Category: Aiq Account Owner::Aiq Account Owner Process%382885190090
//## Subsystem: iqAccountOwner::iqAccountOwner Process%3828851900B3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%38298330016B;AbcIAccountKey { -> }
//## Uses: <unnamed>%3829837D019E;AbcIUserParams { -> }

class AiqPAccountOwner : public AiqIAccountOwner  //## Inherits: <unnamed>%3829E17B005D
{
  //## begin AiqPAccountOwner%37FA1D44014C.initialDeclarations preserve=yes
  //## end AiqPAccountOwner%37FA1D44014C.initialDeclarations

  public:
    //## Constructors (generated)
      AiqPAccountOwner();

    //## Destructor (generated)
      virtual ~AiqPAccountOwner();


    //## Other Operations (specified)
      //## Operation: QueryInterface%382888A00057
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%382888A00151
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%382888A00183
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%382888A001B5
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AiqPAccountOwner%37FA1D44014C.public preserve=yes
      //## end AiqPAccountOwner%37FA1D44014C.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: CustomerKey%382888140182
      virtual AbcIAccountKey* CustomerKey ();
      virtual void CustomerKey (AbcIAccountKey* value);

      //## Attribute: NameLine1%37FA1EFF0171
      virtual RWCString& NameLine1 ();
      virtual void NameLine1 (const RWCString& value);

      //## Attribute: Ownership%37FA1F1702E8
      virtual RWCString& Ownership ();
      virtual void Ownership (const RWCString& value);

    // Additional Protected Declarations
      //## begin AiqPAccountOwner%37FA1D44014C.protected preserve=yes
      //## end AiqPAccountOwner%37FA1D44014C.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3828889F03E5
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqPAccountOwner%37FA1D44014C.private preserve=yes
      //## end AiqPAccountOwner%37FA1D44014C.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqPAccountOwner::CustomerKey%382888140182.attr preserve=no  protected: AbcIAccountKey* {U} 
      AbcIAccountKey* m_CustomerKey;
      //## end AiqPAccountOwner::CustomerKey%382888140182.attr

      //## begin AiqPAccountOwner::NameLine1%37FA1EFF0171.attr preserve=no  protected: RWCString {U} 
      RWCString m_NameLine1;
      //## end AiqPAccountOwner::NameLine1%37FA1EFF0171.attr

      //## begin AiqPAccountOwner::Ownership%37FA1F1702E8.attr preserve=no  protected: RWCString {U} 
      RWCString m_Ownership;
      //## end AiqPAccountOwner::Ownership%37FA1F1702E8.attr

      //## begin AiqPAccountOwner::RefCnt%3828889F03E5.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqPAccountOwner::RefCnt%3828889F03E5.attr

    // Additional Implementation Declarations
      //## begin AiqPAccountOwner%37FA1D44014C.implementation preserve=yes
      //## end AiqPAccountOwner%37FA1D44014C.implementation

};

//## begin AiqPAccountOwner%37FA1D44014C.postscript preserve=yes
//## end AiqPAccountOwner%37FA1D44014C.postscript

//## begin AiqPAccountOwners%3829E17B01CF.preface preserve=yes
//## end AiqPAccountOwners%3829E17B01CF.preface

//## Class: AiqPAccountOwners%3829E17B01CF
//## Category: Aiq Account Owner::Aiq Account Owner Process%382885190090
//## Subsystem: iqAccountOwner::iqAccountOwner Process%3828851900B3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AiqPAccountOwners : public AiqIAccountOwners  //## Inherits: <unnamed>%3829E17F01CB
{
  //## begin AiqPAccountOwners%3829E17B01CF.initialDeclarations preserve=yes
  //## end AiqPAccountOwners%3829E17B01CF.initialDeclarations

  public:
    //## Constructors (generated)
      AiqPAccountOwners();

    //## Destructor (generated)
      virtual ~AiqPAccountOwners();


    //## Other Operations (specified)
      //## Operation: Get%3829E17B01DD
      long Get (AbcIAccountKey* pIAccountKey, AbcIControlBlock* pControlBlock);

      //## Operation: QueryInterface%3829E17F0008
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%3829E17F00DB
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%3829E17F010D
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%3829E17F0135
      HRESULT FinalConstruct ();

    //## Get and Set Operations for Associations (generated)

      //## Association: Aiq Account Owner::Aiq Account Owner Process::<unnamed>%3829E17F02ED
      //## Role: AiqPAccountOwners::AccountOwnerList%3829E17F02F7
      virtual AiqIAccountOwnerList& AccountOwnerList ();
      virtual void AccountOwnerList (const AiqIAccountOwnerList& value);

    // Additional Public Declarations
      //## begin AiqPAccountOwners%3829E17B01CF.public preserve=yes
      //## end AiqPAccountOwners%3829E17B01CF.public

  protected:
    // Additional Protected Declarations
      //## begin AiqPAccountOwners%3829E17B01CF.protected preserve=yes
      //## end AiqPAccountOwners%3829E17B01CF.protected

  private:

    //## Other Operations (specified)
      //## Operation: InternalGet%3829E17B01D9
      long InternalGet (AbcIControlBlock* pControlBlock, int WhereClauseIndex, int ModifySelectorIndex);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%3829E17E03AA
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AiqPAccountOwners%3829E17B01CF.private preserve=yes
      //## end AiqPAccountOwners%3829E17B01CF.private

  private: //## implementation
    // Data Members for Class Attributes

      //## begin AiqPAccountOwners::RefCnt%3829E17E03AA.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AiqPAccountOwners::RefCnt%3829E17E03AA.attr

    // Data Members for Associations

      //## Association: Aiq Account Owner::Aiq Account Owner Process::<unnamed>%3829E17F02ED
      //## begin AiqPAccountOwners::AccountOwnerList%3829E17F02F7.role preserve=no  public: AiqIAccountOwnerList { -> 1VHN}
      AiqIAccountOwnerList m_AccountOwnerList;
      //## end AiqPAccountOwners::AccountOwnerList%3829E17F02F7.role

    // Additional Implementation Declarations
      //## begin AiqPAccountOwners%3829E17B01CF.implementation preserve=yes
      //## end AiqPAccountOwners%3829E17B01CF.implementation

};

//## begin AiqPAccountOwners%3829E17B01CF.postscript preserve=yes
//## end AiqPAccountOwners%3829E17B01CF.postscript

// Class AiqPAccountOwner 

//## Get and Set Operations for Class Attributes (inline)

inline AbcIAccountKey* AiqPAccountOwner::CustomerKey ()
{
  //## begin AiqPAccountOwner::CustomerKey%382888140182.get preserve=yes
  //BC begin attribute.accessor DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_CustomerKey != NULL)
  {
     m_CustomerKey->AddRef();
  }
  return m_CustomerKey;
  //BC end attribute.accessor
  //## end AiqPAccountOwner::CustomerKey%382888140182.get
}

inline void AiqPAccountOwner::CustomerKey (AbcIAccountKey* value)
{
  //## begin AiqPAccountOwner::CustomerKey%382888140182.set preserve=yes
  //BC begin attribute.mutator DO NOT ADD CODE BETWEEN THESE BC TAGS
  if(m_CustomerKey != NULL)
  {
     m_CustomerKey->Release();
  }
  m_CustomerKey = value;
  if(m_CustomerKey != NULL)
  {
     m_CustomerKey->AddRef();
  }
  //BC end attribute.mutator
  //## end AiqPAccountOwner::CustomerKey%382888140182.set
}

inline RWCString& AiqPAccountOwner::NameLine1 ()
{
  //## begin AiqPAccountOwner::NameLine1%37FA1EFF0171.get preserve=no
  return m_NameLine1;
  //## end AiqPAccountOwner::NameLine1%37FA1EFF0171.get
}

inline void AiqPAccountOwner::NameLine1 (const RWCString& value)
{
  //## begin AiqPAccountOwner::NameLine1%37FA1EFF0171.set preserve=no
  m_NameLine1 = value;
  //## end AiqPAccountOwner::NameLine1%37FA1EFF0171.set
}

inline RWCString& AiqPAccountOwner::Ownership ()
{
  //## begin AiqPAccountOwner::Ownership%37FA1F1702E8.get preserve=no
  return m_Ownership;
  //## end AiqPAccountOwner::Ownership%37FA1F1702E8.get
}

inline void AiqPAccountOwner::Ownership (const RWCString& value)
{
  //## begin AiqPAccountOwner::Ownership%37FA1F1702E8.set preserve=no
  m_Ownership = value;
  //## end AiqPAccountOwner::Ownership%37FA1F1702E8.set
}

inline long& AiqPAccountOwner::RefCnt ()
{
  //## begin AiqPAccountOwner::RefCnt%3828889F03E5.get preserve=no
  return m_RefCnt;
  //## end AiqPAccountOwner::RefCnt%3828889F03E5.get
}

inline void AiqPAccountOwner::RefCnt (const long& value)
{
  //## begin AiqPAccountOwner::RefCnt%3828889F03E5.set preserve=no
  m_RefCnt = value;
  //## end AiqPAccountOwner::RefCnt%3828889F03E5.set
}

// Class AiqPAccountOwners 

//## Get and Set Operations for Class Attributes (inline)

inline long& AiqPAccountOwners::RefCnt ()
{
  //## begin AiqPAccountOwners::RefCnt%3829E17E03AA.get preserve=no
  return m_RefCnt;
  //## end AiqPAccountOwners::RefCnt%3829E17E03AA.get
}

inline void AiqPAccountOwners::RefCnt (const long& value)
{
  //## begin AiqPAccountOwners::RefCnt%3829E17E03AA.set preserve=no
  m_RefCnt = value;
  //## end AiqPAccountOwners::RefCnt%3829E17E03AA.set
}

//## Get and Set Operations for Associations (inline)

inline AiqIAccountOwnerList& AiqPAccountOwners::AccountOwnerList ()
{
  //## begin AiqPAccountOwners::AccountOwnerList%3829E17F02F7.get preserve=no
  return m_AccountOwnerList;
  //## end AiqPAccountOwners::AccountOwnerList%3829E17F02F7.get
}

inline void AiqPAccountOwners::AccountOwnerList (const AiqIAccountOwnerList& value)
{
  //## begin AiqPAccountOwners::AccountOwnerList%3829E17F02F7.set preserve=no
  m_AccountOwnerList = value;
  //## end AiqPAccountOwners::AccountOwnerList%3829E17F02F7.set
}

//## begin module%3829E17B0099.epilog preserve=yes
//## end module%3829E17B0099.epilog


#endif


