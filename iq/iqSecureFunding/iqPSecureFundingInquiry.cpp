//## begin module%3E1CF47900C3.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqPSecureFundingInquiry.cpp-arc   1.1   20 Feb 2003 14:29:22   mike  $
//## end module%3E1CF47900C3.cm

//## begin module%3E1CF47900C3.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%3E1CF47900C3.cp

//## Module: iqPSecureFundingInquiry%3E1CF47900C3; Package body
//## Subsystem: iqSecureFunding::iqSecureFunding Process%3E1CEC070301
//## Source file: U:\iq\iqSecureFunding\iqPSecureFundingInquiry.cpp

//## begin module%3E1CF47900C3.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module%3E1CF47900C3.additionalIncludes

//## begin module%3E1CF47900C3.includes preserve=yes
//## end module%3E1CF47900C3.includes

// iqPSecureFundingInquiry
#include "iqPSecureFundingInquiry.h"
//## begin module%3E1CF47900C3.declarations preserve=no
//## end module%3E1CF47900C3.declarations

//## begin module%3E1CF47900C3.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AbcPCurrency)
BC_EXTERN_GUID(CLSID_AbcPAccountKey)
BC_EXTERN_GUID(CLSID_AiqDSecureFundingInquiry)
BC_EXTERN_GUID(CLSID_AiqPSecureFundingAccounts)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {1E8A8C51-08D4-4AB2-9D23-A40A09CFB925}
ABCIMPLEMENT_OLECREATE2(AiqPSecureFundingInquiry, "AiqPSecureFundingInquiry.1", 0x1E8A8C51, 0x08D4, 0x4AB2, 0x9D, 0x23, 0xA4, 0x0A, 0x09, 0xCF, 0xB9, 0x25);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {1E8A8C51-08D4-4AB2-9D23-A40A09CFB925}
// DEFINE_GUID(CLSID_AiqPSecureFundingInquiry, 0x1E8A8C51, 0x08D4, 0x4AB2, 0x9D, 0x23, 0xA4, 0x0A, 0x09, 0xCF, 0xB9, 0x25);

  //BC end guid.ole
//## end module%3E1CF47900C3.additionalDeclarations


// Class AiqPSecureFundingInquiry 





AiqPSecureFundingInquiry::AiqPSecureFundingInquiry()
  //## begin AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.hasinit
  //## begin AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.initialization preserve=yes
  //## end AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.initialization
{
  //## begin AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqPSecureFundingInquiry)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqPSecureFundingInquiry::AiqPSecureFundingInquiry%.body
}


AiqPSecureFundingInquiry::~AiqPSecureFundingInquiry()
{
  //## begin AiqPSecureFundingInquiry::~AiqPSecureFundingInquiry%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqPSecureFundingInquiry)
  AbcOleUnlockApp();
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->Release();
  }  
  if(m_AccountKey != NULL)
  {
     m_AccountKey->Release();
  }
  if(m_SecureFundingAccounts != NULL)
  {
     m_SecureFundingAccounts->Release();
  }
  //BC end traceCom.dtor
  //## end AiqPSecureFundingInquiry::~AiqPSecureFundingInquiry%.body
}



//## Other Operations (implementation)
long AiqPSecureFundingInquiry::Get (AbcIAccountKey* pAccountKey, AbcIControlBlock* ControlBlock)
{   
  //## begin AiqPSecureFundingInquiry::Get%3E1CF3E701E5.body preserve=yes                                                                       
    HRESULT hresult;
    long RetCode;
      
    AbcIMessagesSp pIMessages = ControlBlock->Messages();    
    if (pIMessages->MessageList().entries() != 0)  {
    	pIMessages->MessageList().clear();
    	pIMessages->MaxSeverity(0);
    }
    
    AiqIDSecureFundingInquirySp pIDSecureFundingInquiry;
    hresult = pIDSecureFundingInquiry.CreateInstance(CLSID_AiqDSecureFundingInquiry, NULL, CLSCTX_INPROC_SERVER);
    if(FAILED(hresult))  {
    	pIMessages->Add(BUSINESS_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "AiqPSecureFundingInquiry::Get");
    	return BC_FATAL;
    }
    
    if (AccountKey()->Validate(ControlBlock))
      return BC_FATAL;  
    
    //fill out D object
    pIDSecureFundingInquiry->AccountKey(AccountKey());
      
    if (SecureFundingAccounts()->SecureFundingAccountList().entries()!=0)
       SecureFundingAccounts()->SecureFundingAccountList().clear();
                 
    RetCode = pIDSecureFundingInquiry->Get(&SecureFundingAccounts()->SecureFundingAccountList(), AccountKey(), ControlBlock);
    
    //get data from D object and put into P object
    TotalCollateralAmount(pIDSecureFundingInquiry->TotalCollateralAmount());
    
    return RetCode;
  //## end AiqPSecureFundingInquiry::Get%3E1CF3E701E5.body  
}

HRESULT STDMETHODCALLTYPE AiqPSecureFundingInquiry::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqPSecureFundingInquiry::QueryInterface%3E1CF4790022.body preserve=yes                                             
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqISecureFundingInquiry)
          *ppvObject = (AiqISecureFundingInquiry* ) this;
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
  //## end AiqPSecureFundingInquiry::QueryInterface%3E1CF4790022.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingInquiry::AddRef ()
{
  //## begin AiqPSecureFundingInquiry::AddRef%3E1CF479005E.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqPSecureFundingInquiry::AddRef%3E1CF479005E.body
}

ULONG STDMETHODCALLTYPE AiqPSecureFundingInquiry::Release ()
{
  //## begin AiqPSecureFundingInquiry::Release%3E1CF4790068.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqPSecureFundingInquiry::Release%3E1CF4790068.body
}

HRESULT AiqPSecureFundingInquiry::FinalConstruct ()
{
  //## begin AiqPSecureFundingInquiry::FinalConstruct%3E1CF4790072.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPCurrency, NULL, CLSCTX_INPROC_SERVER, IID_IAbcICurrency, (LPVOID*)& m_TotalCollateralAmount);
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPAccountKey, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIAccountKey, (LPVOID*)& m_AccountKey);
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AiqPSecureFundingAccounts, NULL, CLSCTX_INPROC_SERVER, IID_IAiqISecureFundingAccounts, (LPVOID*)& m_SecureFundingAccounts);
  return hresult;
  //BC end com.finalConstruct
  //## end AiqPSecureFundingInquiry::FinalConstruct%3E1CF4790072.body
}

// Additional Declarations
  //## begin AiqPSecureFundingInquiry%3E1CF3290386.declarations preserve=yes
  //## end AiqPSecureFundingInquiry%3E1CF3290386.declarations

//## begin module%3E1CF47900C3.epilog preserve=yes
//## end module%3E1CF47900C3.epilog
