//## begin module%3829E17B00A3.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/iqPAccountOwner.cpp-arc   1.0   13 Jun 2002 10:17:24   sddevl  $
//## end module%3829E17B00A3.cm

//## begin module%3829E17B00A3.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3829E17B00A3.cp

//## Module: iqPAccountOwner%3829E17B00A3; Package body
//## Subsystem: iqAccountOwner::iqAccountOwner Process%3828851900B3
//## Source file: U:\iq\iqAccountOwner\iqPAccountOwner.cpp

//## begin module%3829E17B00A3.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module%3829E17B00A3.additionalIncludes

//## begin module%3829E17B00A3.includes preserve=yes
#include "iqIDAccountOwner.h"
//## end module%3829E17B00A3.includes

// iqPAccountOwner
#include "iqPAccountOwner.h"
//## begin module%3829E17B00A3.declarations preserve=no
//## end module%3829E17B00A3.declarations

//## begin module%3829E17B00A3.additionalDeclarations preserve=yes
BC_EXTERN_GUID(CLSID_AiqDAccountOwner)
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AbcPAccountKey)
BC_EXTERN_GUID(CLSID_AbcPUserParams)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {5739A9C8-97B3-11D3-A2CD-0000F64E5788}
ABCIMPLEMENT_OLECREATE2(AiqPAccountOwners, "AiqPAccountOwners.1", 0x5739A9C8, 0x97B3, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {5739A9C8-97B3-11D3-A2CD-0000F64E5788}
// DEFINE_GUID(CLSID_AiqPAccountOwners, 0x5739A9C8, 0x97B3, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);

// {5739A9C9-97B3-11D3-A2CD-0000F64E5788}
ABCIMPLEMENT_OLECREATE2(AiqPAccountOwner, "AiqPAccountOwner.1", 0x5739A9C9, 0x97B3, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {5739A9C9-97B3-11D3-A2CD-0000F64E5788}
// DEFINE_GUID(CLSID_AiqPAccountOwner, 0x5739A9C9, 0x97B3, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);

  //BC end guid.ole
//## end module%3829E17B00A3.additionalDeclarations


// Class AiqPAccountOwner 





AiqPAccountOwner::AiqPAccountOwner()
  //## begin AiqPAccountOwner::AiqPAccountOwner%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqPAccountOwner::AiqPAccountOwner%.hasinit
  //## begin AiqPAccountOwner::AiqPAccountOwner%.initialization preserve=yes
  //## end AiqPAccountOwner::AiqPAccountOwner%.initialization
{
  //## begin AiqPAccountOwner::AiqPAccountOwner%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPAccountOwner)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqPAccountOwner::AiqPAccountOwner%.body
}


AiqPAccountOwner::~AiqPAccountOwner()
{
  //## begin AiqPAccountOwner::~AiqPAccountOwner%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPAccountOwner)
  AbcOleUnlockApp();
  if(m_CustomerKey != NULL)
  {
     m_CustomerKey->Release();
  }
  //BC end traceCom.dtor
  //## end AiqPAccountOwner::~AiqPAccountOwner%.body
}



//## Other Operations (implementation)
HRESULT STDMETHODCALLTYPE AiqPAccountOwner::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqPAccountOwner::QueryInterface%382888A00057.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqIAccountOwner)
          *ppvObject = (AiqIAccountOwner* ) this;
  else
      *ppvObject = 0;
  if (*ppvObject)
  {
      AddRef();
      return S_OK;
  }
  else
      return E_NOINTERFACE;

  return S_OK;
  //BC end com.queryInterface
  //## end AiqPAccountOwner::QueryInterface%382888A00057.body
}

ULONG STDMETHODCALLTYPE AiqPAccountOwner::AddRef ()
{
  //## begin AiqPAccountOwner::AddRef%382888A00151.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqPAccountOwner::AddRef%382888A00151.body
}

ULONG STDMETHODCALLTYPE AiqPAccountOwner::Release ()
{
  //## begin AiqPAccountOwner::Release%382888A00183.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqPAccountOwner::Release%382888A00183.body
}

HRESULT AiqPAccountOwner::FinalConstruct ()
{
  //## begin AiqPAccountOwner::FinalConstruct%382888A001B5.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPAccountKey, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIAccountKey, (LPVOID*)& m_CustomerKey);
  return hresult;
  //BC end com.finalConstruct
  //## end AiqPAccountOwner::FinalConstruct%382888A001B5.body
}

// Additional Declarations
  //## begin AiqPAccountOwner%37FA1D44014C.declarations preserve=yes
  //## end AiqPAccountOwner%37FA1D44014C.declarations

// Class AiqPAccountOwners 



AiqPAccountOwners::AiqPAccountOwners()
  //## begin AiqPAccountOwners::AiqPAccountOwners%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqPAccountOwners::AiqPAccountOwners%.hasinit
  //## begin AiqPAccountOwners::AiqPAccountOwners%.initialization preserve=yes
  //## end AiqPAccountOwners::AiqPAccountOwners%.initialization
{
  //## begin AiqPAccountOwners::AiqPAccountOwners%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPAccountOwners)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqPAccountOwners::AiqPAccountOwners%.body
}


AiqPAccountOwners::~AiqPAccountOwners()
{
  //## begin AiqPAccountOwners::~AiqPAccountOwners%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPAccountOwners)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
  //## end AiqPAccountOwners::~AiqPAccountOwners%.body
}



//## Other Operations (implementation)
long AiqPAccountOwners::InternalGet (AbcIControlBlock* pControlBlock, int WhereClauseIndex, int ModifySelectorIndex)
{
  //## begin AiqPAccountOwners::InternalGet%3829E17B01D9.body preserve=yes

    HRESULT hresult;
    long RetCode = 0;

    return RetCode; 
  //## end AiqPAccountOwners::InternalGet%3829E17B01D9.body
}

long AiqPAccountOwners::Get (AbcIAccountKey* pIAccountKey, AbcIControlBlock* pControlBlock)
{
  //## begin AiqPAccountOwners::Get%3829E17B01DD.body preserve=yes

    HRESULT hresult;
    long RetCode;

    AiqIDAccountOwnerSp pIDAccountOwner;
    hresult = pIDAccountOwner.CreateInstance(CLSID_AiqDAccountOwner, NULL, CLSCTX_INPROC_SERVER);
    if (FAILED(hresult) )
    {
        //pIMessages->Add(BUSINESS_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "AbcPAccountOwners::Get");
        return BC_FATAL;
    }

    //dummy - ?
    RetCode = pIDAccountOwner->Get(pIAccountKey, this, pControlBlock );
    return RetCode;
  //## end AiqPAccountOwners::Get%3829E17B01DD.body
}

HRESULT STDMETHODCALLTYPE AiqPAccountOwners::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqPAccountOwners::QueryInterface%3829E17F0008.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqIAccountOwners)
          *ppvObject = (AiqIAccountOwners* ) this;
  else
      *ppvObject = 0;
  if (*ppvObject)
  {
      AddRef();
      return S_OK;
  }
  else
      return E_NOINTERFACE;

  return S_OK;
  //BC end com.queryInterface
  //## end AiqPAccountOwners::QueryInterface%3829E17F0008.body
}

ULONG STDMETHODCALLTYPE AiqPAccountOwners::AddRef ()
{
  //## begin AiqPAccountOwners::AddRef%3829E17F00DB.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqPAccountOwners::AddRef%3829E17F00DB.body
}

ULONG STDMETHODCALLTYPE AiqPAccountOwners::Release ()
{
  //## begin AiqPAccountOwners::Release%3829E17F010D.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqPAccountOwners::Release%3829E17F010D.body
}

HRESULT AiqPAccountOwners::FinalConstruct ()
{
  //## begin AiqPAccountOwners::FinalConstruct%3829E17F0135.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  return hresult;
  //BC end com.finalConstruct
  //## end AiqPAccountOwners::FinalConstruct%3829E17F0135.body
}

// Additional Declarations
  //## begin AiqPAccountOwners%3829E17B01CF.declarations preserve=yes
  //## end AiqPAccountOwners%3829E17B01CF.declarations

//## begin module%3829E17B00A3.epilog preserve=yes
//## end module%3829E17B00A3.epilog
 

