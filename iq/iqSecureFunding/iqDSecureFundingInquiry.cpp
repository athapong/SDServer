//## begin module.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqSecureFunding/iqDSecureFundingInquiry.cpp-arc   1.1   20 Feb 2003 14:29:18   mike  $
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

//## Module: iqDSecureFundingInquiry; Package body
//## Subsystem: iqSecureFunding::iqSecureFundingInquiry::iqSecureFundingInquiry Data Access
//## Source file: U:\iq\iqSecureFunding\iqDSecureFundingInquiry.cpp


//## begin module.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "iqSecureFundingGuid.h"
#include "bcIPCurrency.h"
//## end module.includes

// iqDSecureFundingInquiry
#include "iqDSecureFundingInquiry.h"

//## begin module.declarations preserve=yes
BC_EXTERN_GUID(CLSID_AbcPCurrency)
BC_EXTERN_GUID(CLSID_AbcPDateTime)

#define BUSINESS_MODULE "SDIMODP" 
#define BUSINESS_MODULE_TYPE "A"
#define SECURITY_CODE "K"
#define EXTERNAL_TRAN_CODE "SDOP"  
#define SEVERITY 1
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AbcPAccountKey)
BC_EXTERN_GUID(CLSID_AbcPUserParams)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {48D75BCA-79AB-11D2-A25A-0000F64DA776}
ABCIMPLEMENT_OLECREATE2(AiqDSecureFundingInquiry, "AiqDSecureFundingInquiry.1", 0x48D75BCA, 0x79AB, 0x11D2, 0xA2, 0x5A, 0x00, 0x00, 0xF6, 0x4D, 0xA7, 0x76);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {48D75BCA-79AB-11D2-A25A-0000F64DA776}
// DEFINE_GUID(CLSID_AiqDSecureFundingInquiry, 0x48D75BCA, 0x79AB, 0x11D2, 0xA2, 0x5A, 0x00, 0x00, 0xF6, 0x4D, 0xA7, 0x76);

  //BC end guid.ole
//## end module.additionalDeclarations


// Class AiqDSecureFundingInquiry 


AiqDSecureFundingInquiry::AiqDSecureFundingInquiry()
  //## begin AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.hasinit
  //## begin AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.initialization preserve=yes
  //## end AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.initialization
{
  //## begin AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqDSecureFundingInquiry)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqDSecureFundingInquiry::AiqDSecureFundingInquiry%.body
}


AiqDSecureFundingInquiry::~AiqDSecureFundingInquiry()
{
  //## begin AiqDSecureFundingInquiry::~AiqDSecureFundingInquiry%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqDSecureFundingInquiry)
  AbcOleUnlockApp();
  if(m_AccountKey != NULL)
  {
     m_AccountKey->Release();
  }
  if(m_TotalCollateralAmount != NULL)
  {
     m_TotalCollateralAmount->Release();
  }
  //BC end traceCom.dtor
  //## end AiqDSecureFundingInquiry::~AiqDSecureFundingInquiry%.body
}



//## Other Operations (implementation)
long AiqDSecureFundingInquiry::Get(AiqISecureFundingAccountList* pTransList, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock)
{
  //## begin AiqDSecureFundingInquiry::Get%910818763.body preserve=yes
    long RetCode = BC_NO_ERRORS;
    AbcIMessagesSp pMessages = pControlBlock->Messages();
    
    AsdSDPCIMODData SDPCIMOD;
    AsdSDPCIMODData::AsdSDIMODP* pSDIMODP = SDPCIMOD.SDIMODP;		 // dag wrapper
    
    if (RetCode != BC_FATAL) 
    {  	    	    	
        RetCode = InitializeInput(pSDIMODP, pAccountKey, pControlBlock);
        if (RetCode == BC_NO_ERRORS) 
            RetCode = GetHostData(pTransList, SDPCIMOD, pAccountKey, pControlBlock);
    }

    return RetCode; 
  //## end AiqDSecureFundingInquiry::Get%910818763.body
}

long AiqDSecureFundingInquiry::GetHostData(AiqISecureFundingAccountList* pTransList, AsdSDPCIMODData& SDPCIMOD, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock)
{
  //## begin AiqDSecureFundingInquiry::GetHostData%910818764.body preserve=yes
    long RetCode = BC_NO_ERRORS;
    
    AsdSDPCIMODData::AsdTSHeader* pTSHeader = SDPCIMOD.TSHeader; 
    AsdSDPCIMODData::AsdSDIMODP* pSDIMODP = SDPCIMOD.SDIMODP;                 // dag wrapper
    AsdSDPCIMODData::AsdTSMDA* pTSMDA = SDPCIMOD.TSMDA;       

    AbcIMessagesSp pMessages = pControlBlock->Messages();

    RWCString HostLogonId;                         // Host login extracted from CB
    HostLogonId = pControlBlock->HostLogonId();
    
    if (RetCode == BC_NO_ERRORS) 
    {
       pTSHeader->UserId(HostLogonId);
       pTSHeader->BusinessModule(BUSINESS_MODULE);
       pTSHeader->BusModuleType(BUSINESS_MODULE_TYPE);
       pTSHeader->ExtTranCode(EXTERNAL_TRAN_CODE);
       pTSHeader->FunSecurityCode(SECURITY_CODE);
       pTSHeader->RemoteTPName(SDPCIMOD.GetRemoteTpName(REMOTETP_SD));
        
       RetCode = SDPCIMOD.SessionExecute(pControlBlock);
       if ( RetCode != BC_FATAL )
       {
          RetCode = ReadResults(pTransList, pSDIMODP, pControlBlock); 
       }
    }
    return RetCode;
  //## end AiqDSecureFundingInquiry::GetHostData%910818764.body
}

long AiqDSecureFundingInquiry::ReadResults(AiqISecureFundingAccountList* pTransList, AsdSDPCIMODData::AsdSDIMODP* pSDIMODP, AbcIControlBlock* pControlBlock)
{
  //## begin AiqDSecureFundingInquiry::ReadResults%910818765.body preserve=yes
    long RetCode = BC_NO_ERRORS;
    long lRecordsToRead;    
    HRESULT hresult;
    char * StopString;
    
    AbcIMessagesSp pMessages = pControlBlock->Messages();

    lRecordsToRead = atoi(pSDIMODP->NoStAccts());  //number of records that came back in the dag this time
        
    AbcICurrencySp pTotalCollateralAmount;
    hresult = pTotalCollateralAmount.CreateInstance(CLSID_AbcPCurrency, 0, CLSCTX_INPROC_SERVER);
    if (FAILED(hresult))
      {
        pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPCurrency in AiqDSecureFundingInquiry::ReadResults");
        return BC_FATAL;
      } 
    pTotalCollateralAmount->Amount(pSDIMODP->TotCollateralAmt().strip());         
    TotalCollateralAmount(pTotalCollateralAmount);
        
    for (short index = 0; index < lRecordsToRead; index++) 
    {
        AbcIAccountKeySp pAccountKey;
        hresult = pAccountKey.CreateInstance(CLSID_AbcPAccountKey, 0, CLSCTX_INPROC_SERVER);
        if (FAILED(hresult))
        {
            pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPAccountKey in AiqDSecureFundingInquiry::ReadResults");
            return BC_FATAL;
        }    	
    	
        AbcICurrencySp pCollateralAmount;
        hresult = pCollateralAmount.CreateInstance(CLSID_AbcPCurrency, 0, CLSCTX_INPROC_SERVER);
        if (FAILED(hresult))
        {
            pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPCurrency in AiqDSecureFundingInquiry::ReadResults");
            return BC_FATAL;
        }
        
        AbcIDateTimeSp pEffectiveDate;
        hresult = pEffectiveDate.CreateInstance(CLSID_AbcPDateTime, 0, CLSCTX_INPROC_SERVER);
        if (FAILED(hresult))
        {
            pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPDateTime in AiqDSecureFundingInquiry::ReadResults");
            return BC_FATAL;
        }
        
        AbcIDateTimeSp pMaturityDate;
        hresult = pMaturityDate.CreateInstance(CLSID_AbcPDateTime, 0, CLSCTX_INPROC_SERVER);
        if (FAILED(hresult))
        {
            pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPDateTime in AiqDSecureFundingInquiry::ReadResults");
            return BC_FATAL;
        }        
        
        AiqISecureFundingAccountSp pSecureFundingAccount;
        hresult = pSecureFundingAccount.CreateInstance(CLSID_AiqPSecureFundingAccount, 0, CLSCTX_INPROC_SERVER);
        if (FAILED(hresult))
        {
            pMessages->Add("BC", MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AiqPSecureFundingAccount in AiqDSecureFundingInquiry::ReadResults");
            return BC_FATAL;
        }   
        
        pAccountKey->AccountNumber(pSDIMODP->CStCollateralAccts[index].StAccountNo().strip());
        pSecureFundingAccount->AccountKey(pAccountKey);
        
        pCollateralAmount->Amount(pSDIMODP->CStCollateralAccts[index].CollateralAmt());
        pSecureFundingAccount->CollateralAmount(pCollateralAmount);         
        
        pSecureFundingAccount->Rate(pSDIMODP->CStCollateralAccts[index].CdRate().strip());
        
        pEffectiveDate->Date(pSDIMODP->CStCollateralAccts[index].CdEffectiveDate().strip());
        pSecureFundingAccount->EffectiveDate(pEffectiveDate);
        
        pMaturityDate->Date(pSDIMODP->CStCollateralAccts[index].CdMaturityDate().strip());
        pSecureFundingAccount->MaturityDate(pMaturityDate);        
            
        if (RetCode != BC_FATAL) 
            pTransList->append(pSecureFundingAccount);
    }
    return RetCode;
  //## end AiqDSecureFundingInquiry::ReadResults%910818765.body
}

long AiqDSecureFundingInquiry::InitializeInput(AsdSDPCIMODData::AsdSDIMODP* pSDIMODP, AbcIAccountKey* pAccountKey, AbcIControlBlock* pControlBlock)
{
  //## begin AiqDSecureFundingInquiry::InitializeInput%910818766.body preserve=yes
    long RetCode = BC_NO_ERRORS;
    RWCString CtlString;
    
    CtlString = pAccountKey->Control1();   
    pSDIMODP->Control1(CtlString(2,2));  
    CtlString = pAccountKey->Control2();     
    pSDIMODP->Control2(CtlString(1,3));                           
    CtlString = pAccountKey->Control3();
    pSDIMODP->Control3(CtlString(1,3));                           
    pSDIMODP->Control4(pAccountKey->Control4());                  
    pSDIMODP->AcctNo(pAccountKey->AccountNumber());
        
    return BC_NO_ERRORS;
  //## end AiqDSecureFundingInquiry::InitializeInput%910818766.body
}

HRESULT STDMETHODCALLTYPE AiqDSecureFundingInquiry::QueryInterface(REFIID riid, void** ppvObject)
{
  //## begin AiqDSecureFundingInquiry::QueryInterface%910818767.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqIDSecureFundingInquiry)
          *ppvObject = (AiqIDSecureFundingInquiry* ) this;
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
  //## end AiqDSecureFundingInquiry::QueryInterface%910818767.body
}

ULONG STDMETHODCALLTYPE AiqDSecureFundingInquiry::AddRef()
{
  //## begin AiqDSecureFundingInquiry::AddRef%910818768.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqDSecureFundingInquiry::AddRef%910818768.body
}

ULONG STDMETHODCALLTYPE AiqDSecureFundingInquiry::Release()
{
  //## begin AiqDSecureFundingInquiry::Release%910818769.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqDSecureFundingInquiry::Release%910818769.body
}

HRESULT AiqDSecureFundingInquiry::FinalConstruct()
{
  //## begin AiqDSecureFundingInquiry::FinalConstruct%910818770.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPAccountKey, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIAccountKey, (LPVOID*)& m_AccountKey);
  if (hresult == S_OK) hresult = AbcCoCreateInstance(CLSID_AbcPCurrency, NULL, CLSCTX_INPROC_SERVER, IID_IAbcICurrency, (LPVOID*)& m_TotalCollateralAmount);
  return hresult;
  //BC end com.finalConstruct
  //## end AiqDSecureFundingInquiry::FinalConstruct%910818770.body
}


// Additional Declarations
//## begin AiqDSecureFundingInquiry.declarations preserve=yes
//## end AiqDSecureFundingInquiry.declarations
