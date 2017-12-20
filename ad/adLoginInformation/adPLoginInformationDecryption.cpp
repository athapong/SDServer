//## begin module.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/ad/adLoginInformation/adPLoginInformationDecryption.cpp-arc   1.0   13 Jun 2002 09:58:44   sddevl  $
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

//## Module: adPLoginInformation; Package body
//## Subsystem: adLoginInformation::adLoginInformation Process
//## Source file: U:\ad\adLoginInformation\adPLoginInformation.cpp


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
//## end module.includes

// adPLoginInformation
#include "adPLoginInformation.h"

//#include "bcIPSecurityObjects.h"

EXTERN_C const GUID CLSID_AbcPSecurityObjects;

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {38C01D25-2EF1-11D3-A24D-0000F64E5788}
ABCIMPLEMENT_OLECREATE2(AadPLoginInformation, "AadPLoginInformation.1", 0x38C01D25, 0x2EF1, 0x11D3, 0xA2, 0x4D, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {38C01D25-2EF1-11D3-A24D-0000F64E5788}
// DEFINE_GUID(CLSID_AadPLoginInformation, 0x38C01D25, 0x2EF1, 0x11D3, 0xA2, 0x4D, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);

  //BC end guid.ole
//## end module.additionalDeclarations


// Class AadPLoginInformation 




AadPLoginInformation::AadPLoginInformation()
  //## begin AadPLoginInformation::AadPLoginInformation%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AadPLoginInformation::AadPLoginInformation%.hasinit
  //## begin AadPLoginInformation::AadPLoginInformation%.initialization preserve=yes
  //## end AadPLoginInformation::AadPLoginInformation%.initialization
{
  //## begin AadPLoginInformation::AadPLoginInformation%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AadPLoginInformation)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AadPLoginInformation::AadPLoginInformation%.body
}


AadPLoginInformation::~AadPLoginInformation()
{
  //## begin AadPLoginInformation::~AadPLoginInformation%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AadPLoginInformation)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
  //## end AadPLoginInformation::~AadPLoginInformation%.body
}



//## Other Operations (implementation)
long AadPLoginInformation::Retrieve()
{
  //## begin AadPLoginInformation::Retrieve%930750422.body preserve=yes
    long Status = BC_FATAL;

    IPControlBlock * pIControlBlock;
    HRESULT hresult = AbcCreateInstance(CLSID_AbcPControlBlock,
                                        NULL,
                                        CLSCTX_INPROC_SERVER,
                                        IID_IAbcIPControlBlock,
                                        (LPVOID*)& pIControlBlock);	

    if (SUCCEEDED(hresult))
    {
        RetrieveLoginInformation("bc.ini", &pIControlBlock);
        Status = BC_NO_ERRORS;
    }
    else
    {
        char x[100];
        sprintf(x,"Could not create Control Block %x\n", hresult);
        
        Status = BC_FATAL;
    }

    return Status;
  //## end AadPLoginInformation::Retrieve%930750422.body
}

HRESULT STDMETHODCALLTYPE AadPLoginInformation::QueryInterface(REFIID riid, void** ppvObject)
{
  //## begin AadPLoginInformation::QueryInterface%930750423.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAadILoginInformation)
          *ppvObject = (AadILoginInformation* ) this;
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
  //## end AadPLoginInformation::QueryInterface%930750423.body
}

ULONG STDMETHODCALLTYPE AadPLoginInformation::AddRef()
{
  //## begin AadPLoginInformation::AddRef%930750424.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AadPLoginInformation::AddRef%930750424.body
}

ULONG STDMETHODCALLTYPE AadPLoginInformation::Release()
{
  //## begin AadPLoginInformation::Release%930750425.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AadPLoginInformation::Release%930750425.body
}

HRESULT AadPLoginInformation::FinalConstruct()
{
  //## begin AadPLoginInformation::FinalConstruct%930750426.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  return hresult;
  //BC end com.finalConstruct
  //## end AadPLoginInformation::FinalConstruct%930750426.body
}


// Additional Declarations
//## begin AadPLoginInformation.declarations preserve=yes
void AadPLoginInformation::RetrieveLoginInformation(const RWCString& IniFileName, AbcIControlBlock* pControlBlock)
{
    AbcIPControlBlockTranSp spControlBlockTran(pControlBlock);
    if (!spControlBlockTran)
    {
        static const int MAX_NAMELEN = 80;
        char szUserName[MAX_NAMELEN] ;
        char szPassword[MAX_NAMELEN] ;
     
        //dummy - this returns a length
        GetPrivateProfileString("DATABASE_SECTION",
                    "USERNAME",
                    "",
                    szUserName,
                    sizeof(szUserName)-1,
                    (char *)(const char *)IniFileName) ;
    
        AbcIPSecurityObjects *pIPSecurityObjects;
        HRESULT hresult = AbcCoCreateInstance(CLSID_AbcPSecurityObjects, 
                                                  NULL, 
                                                  CLSCTX_INPROC_SERVER, 
                                                  IID_IAbcIPSecurityObjects, 
                                                  (LPVOID*)& pISecurityObjects);
        
        AbcIPEncryption *pIEncryption;
        pIEncryption = pISecurityObjects->Encryption();	
        
                	
    	if (SUCCEEDED(hresult))
        {
            RWCString sIniKeyName = "BCKEYFILE";
            

            //dummy change this to something intelligent and loose the cast.
            char		csPW[300];
            char		*pcsPW = (char *)csPW;
            strcpy(csPW, szUserName);
            long lSysErr = pIEncryption->DecipherString( sIniKeyName,   
                                                         &pcsPW,
                                                         pControlBlock);
            #ifdef _DEBUG
                      
            if (lSysErr == 0)
            {
                cout << "Decipher Worked" << endl;
            }
            else
            {
                cout << "decipher failed" << endl;
            }
            #endif
        
            m_Login = csPW;
     

        }

        GetPrivateProfileString("DATABASE_SECTION",
                    "PASSWORD",
                    "",
                    szPassword,
                    sizeof(szPassword)-1,
                    (char *)(const char *)IniFileName) ;
    
        m_Password = szPassword;

        pISecurityObjects->Release();
        pIEncryption->Release();
    }

    
}
//## end AadPLoginInformation.declarations




