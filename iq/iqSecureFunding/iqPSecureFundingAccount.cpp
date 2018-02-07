//## begin module%3E1CF2FE0104.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqPSecureFundingAccount.cpp-arc   1.1   20 Feb 2003 14:29:22   mike  $
//## end module%3E1CF2FE0104.cm

//## begin module%3E1CF2FE0104.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3E1CF2FE0104.cp

//## Module: iqPSecureFundingAccount%3E1CF2FE0104; Package body
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Source file: U:\iq\iqSecureFunding\iqPSecureFundingAccount.cpp

//## begin module%3E1CF2FE0104.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module%3E1CF2FE0104.additionalIncludes

//## begin module%3E1CF2FE0104.includes preserve=yes
//## end module%3E1CF2FE0104.includes

// iqPSecureFundingAccount
#include "iqPSecureFundingAccount.h"
//## begin module%3E1CF2FE0104.declarations preserve=no
//## end module%3E1CF2FE0104.declarations

//## begin module%3E1CF2FE0104.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AbcPAccountKey)
BC_EXTERN_GUID(CLSID_AbcPCurrency)
BC_EXTERN_GUID(CLSID_AbcPDateTime)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {70E6FE25-5D27-4F15-A377-B14DCEC02886}
ABCIMPLEMENT_OLECREATE2(AiqPSecureFundingAccounts, "AiqPSecureFundingAccounts.1", 0x70E6FE25, 0x5D27, 0x4F15, 0xA3, 0x77, 0xB1, 0x4D, 0xCE, 0xC0, 0x28, 0x86);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {70E6FE25-5D27-4F15-A377-B14DCEC02886}
// DEFINE_GUID(CLSID_AiqPSecureFundingAccounts, 0x70E6FE25, 0x5D27, 0x4F15, 0xA3, 0x77, 0xB1, 0x4D, 0xCE, 0xC0, 0x28, 0x86);

// {CFE1BBA2-8292-4081-907B-0743BE49D37A}
ABCIMPLEMENT_OLECREATE2(AiqPSecureFundingAccount, "AiqPSecureFundingAccount.1", 0xCFE1BBA2, 0x8292, 0x4081, 0x90, 0x7B, 0x07, 0x43, 0xBE, 0x49, 0xD3, 0x7A);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {CFE1BBA2-8292-4081-907B-0743BE49D37A}
// DEFINE_GUID(CLSID_AiqPSecureFundingAccount, 0xCFE1BBA2, 0x8292, 0x4081, 0x90, 0x7B, 0x07, 0x43, 0xBE, 0x49, 0xD3, 0x7A);

  //BC end guid.ole
//## end module%3E1CF2FE0104.additionalDeclarations


// Class AiqPSecureFundingAccount 







AiqPSecureFundingAccount::AiqPSecureFundingAccount()
  //## begin AiqPSecureFundingAccount::AiqPSecureFundingAccount%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqPSecureFundingAccount::AiqPSecureFundingAccount%.hasinit
  //## begin AiqPSecureFundingAccount::AiqPSecureFundingAccount%.initialization preserve=yes
  //## end AiqPSecureFundingAccount::AiqPSecureFundingAccount%.initialization
{
  //## begin AiqPSecureFundingAccount::AiqPSecureFundingAccount%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPSecureFundingAccount)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqPSecureFundingAccount::AiqPSecureFundingAccount%.body
}


AiqPSecureFundingAccount::~AiqPSecureFundingAccount()
{
  //## begin AiqPSecureFundingAccount::~AiqPSecureFundingAccount%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPSecureFundingAccount)
  AbcOleUnlockApp();
    if(m_AccountKey != NULL)
  {
     m_AccountKey->Release();
  }  
    if(m_CollateralAmount != NULL)
  {
     m_CollateralAmount->Release();
  }
  if(m_EffectiveDate != NULL)
  {
     m_EffectiveDate->Release();
  }
  if(m_MaturityDate != NULL)
  {
     m_MaturityDate->Release();
  }
  //BC end traceCom.dtor
  //## end AiqPSecureFundingAccount::~AiqPSecureFundingAccount%.body
}



//## Other Operations (implementation)
HRESULT STDMETHODCALLTYPE AiqPSecureFundingAccount::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqPSecureFundingAccount::QueryInterface%3E1CF2FE0059.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqISecureFundingAccount)
          *ppvObject = (AiqISecureFundingAccount* ) this;
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
  //## end AiqPSecureFundingAccount::QueryInterface%3E1CF2FE0059.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingAccount::AddRef ()
{
  //## begin AiqPSecureFundingAccount::AddRef%3E1CF2FE00A0.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqPSecureFundingAccount::AddRef%3E1CF2FE00A0.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingAccount::Release ()
{
  //## begin AiqPSecureFundingAccount::Release%3E1CF2FE00AA.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqPSecureFundingAccount::Release%3E1CF2FE00AA.body
}

HRESULT AiqPSecureFundingAccount::FinalConstruct ()
{
  //## begin AiqPSecureFundingAccount::FinalConstruct%3E1CF2FE00B4.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPAccountKey, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIAccountKey, (LPVOID*)& m_AccountKey);
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPCurrency, NULL, CLSCTX_INPROC_SERVER, IID_IAbcICurrency, (LPVOID*)& m_CollateralAmount);    
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPDateTime, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIDateTime, (LPVOID*)& m_EffectiveDate);
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPDateTime, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIDateTime, (LPVOID*)& m_MaturityDate);
  return hresult;
  //BC end com.finalConstruct
  //## end AiqPSecureFundingAccount::FinalConstruct%3E1CF2FE00B4.body
}

// Additional Declarations
  //## begin AiqPSecureFundingAccount%3E1CEC9402A7.declarations preserve=yes
  //## end AiqPSecureFundingAccount%3E1CEC9402A7.declarations

// Class AiqPSecureFundingAccounts 



AiqPSecureFundingAccounts::AiqPSecureFundingAccounts()
  //## begin AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.hasinit
  //## begin AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.initialization preserve=yes
  //## end AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.initialization
{
  //## begin AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPSecureFundingAccounts)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.body
}


AiqPSecureFundingAccounts::~AiqPSecureFundingAccounts()
{
  //## begin AiqPSecureFundingAccounts::~AiqPSecureFundingAccounts%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPSecureFundingAccounts)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
  //## end AiqPSecureFundingAccounts::~AiqPSecureFundingAccounts%.body
}



//## Other Operations (implementation)
long AiqPSecureFundingAccounts::InternalGet (AbcIControlBlock* pControlBlock, int WhereClauseIndex, int ModifySelectorIndex)
{
  //## begin AiqPSecureFundingAccounts::InternalGet%3E1CF2FE02DB.body preserve=yes
  //## end AiqPSecureFundingAccounts::InternalGet%3E1CF2FE02DB.body
}

long AiqPSecureFundingAccounts::Get (AbcIControlBlock* pControlBlock)
{
  //## begin AiqPSecureFundingAccounts::Get%3E1CF2FE02DF.body preserve=yes
  //## end AiqPSecureFundingAccounts::Get%3E1CF2FE02DF.body
}

HRESULT STDMETHODCALLTYPE AiqPSecureFundingAccounts::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqPSecureFundingAccounts::QueryInterface%3E1CF3100164.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqISecureFundingAccounts)
          *ppvObject = (AiqISecureFundingAccounts* ) this;
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
  //## end AiqPSecureFundingAccounts::QueryInterface%3E1CF3100164.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingAccounts::AddRef ()
{
  //## begin AiqPSecureFundingAccounts::AddRef%3E1CF31001A0.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqPSecureFundingAccounts::AddRef%3E1CF31001A0.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingAccounts::Release ()
{
  //## begin AiqPSecureFundingAccounts::Release%3E1CF31001AA.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqPSecureFundingAccounts::Release%3E1CF31001AA.body
}

HRESULT AiqPSecureFundingAccounts::FinalConstruct ()
{
  //## begin AiqPSecureFundingAccounts::FinalConstruct%3E1CF31001B4.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  return hresult;
  //BC end com.finalConstruct
  //## end AiqPSecureFundingAccounts::FinalConstruct%3E1CF31001B4.body
}

// Additional Declarations
  //## begin AiqPSecureFundingAccounts%3E1CF2FE02DA.declarations preserve=yes
  //## end AiqPSecureFundingAccounts%3E1CF2FE02DA.declarations

//## begin module%3E1CF2FE0104.epilog preserve=yes
//## end module%3E1CF2FE0104.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin AiqPSecureFundingAccount::AiqPSecureFundingAccount%.body preserve=no
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPSecureFundingAccount)
  AbcOleLockApp();
  //BC end traceCom.ctor
//## end AiqPSecureFundingAccount::AiqPSecureFundingAccount%.body

//## begin AiqPSecureFundingAccount::~AiqPSecureFundingAccount%.body preserve=no
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPSecureFundingAccount)
  AbcOleUnlockApp();
  if(m_AccountKey != NULL)
  {
     m_AccountKey->Release();
  }
  if(m_CollateralAmount != NULL)
  {
     m_CollateralAmount->Release();
  }
  if(m_EffectiveDate != NULL)
  {
     m_EffectiveDate->Release();
  }
  if(m_MaturityDate != NULL)
  {
     m_MaturityDate->Release();
  }
  //BC end traceCom.dtor
//## end AiqPSecureFundingAccount::~AiqPSecureFundingAccount%.body

//## begin AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.body preserve=no
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPSecureFundingAccounts)
  AbcOleLockApp();
  //BC end traceCom.ctor
//## end AiqPSecureFundingAccounts::AiqPSecureFundingAccounts%.body

//## begin AiqPSecureFundingAccounts::~AiqPSecureFundingAccounts%.body preserve=no
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPSecureFundingAccounts)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
//## end AiqPSecureFundingAccounts::~AiqPSecureFundingAccounts%.body

#endif
