//## begin module%38297D650028.cm preserve=no
//      $Header:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/iqDAccountOwner.cpp-arc   1.0   13 Jun 2002 10:17:22   sddevl  $
//## end module%38297D650028.cm

//## begin module%38297D650028.cp preserve=no
//      *********************************************************
//      *  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//      *  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//      *  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//      *  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//      *  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//      *  1999, ALL RIGHTS RESERVED.
//      *********************************************************
//## end module%38297D650028.cp

//## Module: iqDAccountOwner%38297D650028; Package body
//## Subsystem: iqAccountOwner::iqAccountOwner Data Access%3828851900B4
//## Source file: U:\curwave\iq\iqAccountOwner\iqDAccountOwner.cpp

//## begin module%38297D650028.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module%38297D650028.additionalIncludes

//## begin module%38297D650028.includes preserve=yes
#include "apptbl.h"
//## end module%38297D650028.includes

// iqDAccountOwner
#include "iqDAccountOwner.h"
//## begin module%38297D650028.declarations preserve=no
//## end module%38297D650028.declarations
#include "twSupport.h" //Chalongchai 20-MAY-2011 CR DC001 add 2 input DAG to RM 
//## begin module%38297D650028.additionalDeclarations preserve=yes
BC_EXTERN_GUID(CLSID_AbcPUserParams)
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AbcPAccountKey)
BC_EXTERN_GUID(CLSID_AiqPAccountOwners)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {4CC8D8C4-9777-11D3-A2CD-0000F64E5788}
ABCIMPLEMENT_OLECREATE2(AiqDAccountOwner, "AiqDAccountOwner.1", 0x4CC8D8C4, 0x9777, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {4CC8D8C4-9777-11D3-A2CD-0000F64E5788}
// DEFINE_GUID(CLSID_AiqDAccountOwner, 0x4CC8D8C4, 0x9777, 0x11D3, 0xA2, 0xCD, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);

  //BC end guid.ole
//## end module%38297D650028.additionalDeclarations


// Class AiqDAccountOwner 


AiqDAccountOwner::AiqDAccountOwner()
  //## begin AiqDAccountOwner::AiqDAccountOwner%.hasinit preserve=no
      : m_RefCnt(0)
  //## end AiqDAccountOwner::AiqDAccountOwner%.hasinit
  //## begin AiqDAccountOwner::AiqDAccountOwner%.initialization preserve=yes
  //## end AiqDAccountOwner::AiqDAccountOwner%.initialization
{
  //## begin AiqDAccountOwner::AiqDAccountOwner%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AiqDAccountOwner)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AiqDAccountOwner::AiqDAccountOwner%.body
}


AiqDAccountOwner::~AiqDAccountOwner()
{
  //## begin AiqDAccountOwner::~AiqDAccountOwner%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AiqDAccountOwner)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
  //## end AiqDAccountOwner::~AiqDAccountOwner%.body
}


void ResetAsdWVPCRMOWData( AsdWVPCRMOWData* SDWVPCRMOW )
{
        AsdWVPCRMOWData::AsdTSHeader* pTSHeader = SDWVPCRMOW->TSHeader;
        AsdWVPCRMOWData::AsdWVRMOWNI* pInputDag = SDWVPCRMOW->WVRMOWNI;
        AsdWVPCRMOWData::AsdWVRMOWNO* pOutputDag = SDWVPCRMOW->WVRMOWNO;

        AsdWVPCRMOWData SDWVPCRMOW2;
        AsdWVPCRMOWData::AsdTSHeader* pTSHeader2 = SDWVPCRMOW2.TSHeader;
        AsdWVPCRMOWData::AsdWVRMOWNI* pInputDag2 = SDWVPCRMOW2.WVRMOWNI;
        AsdWVPCRMOWData::AsdWVRMOWNO* pOutputDag2 = SDWVPCRMOW2.WVRMOWNO;
   

   pTSHeader2->RemoteTPName(pTSHeader->RemoteTPName());
   pTSHeader2->PSBARC1(pTSHeader->PSBARC1());
   pTSHeader2->ExtTranCode(pTSHeader->ExtTranCode());
   pTSHeader2->OverrideTellerId(pTSHeader->OverrideTellerId());
   pTSHeader2->TranSeq(pTSHeader->TranSeq());

   pTSHeader2->TranTime(pTSHeader->TranTime());
   pTSHeader2->LandFill0(pTSHeader->LandFill0());
   pTSHeader2->RecLen(pTSHeader->RecLen());
   pTSHeader2->UserId(pTSHeader->UserId());
   pTSHeader2->FunSecurityCode(pTSHeader->FunSecurityCode());
   pTSHeader2->BusModuleType(pTSHeader->BusModuleType());
   pTSHeader2->BusinessModule(pTSHeader->BusinessModule());
   pTSHeader2->MaximumSeverity(pTSHeader->MaximumSeverity());
   pTSHeader2->AppcErrorCode(pTSHeader->AppcErrorCode());
   pTSHeader2->NumDags(pTSHeader->NumDags());
   
   
   pInputDag2->BegKey(pInputDag->BegKey());
   pInputDag2->EndKey(pInputDag->EndKey());
   pInputDag2->ReqFromEntKey(pInputDag->ReqFromEntKey());
   pInputDag2->CustCtl1(pInputDag->CustCtl1());
   pInputDag2->CustCtl2(pInputDag->CustCtl2());
   pInputDag2->CustCtl3(pInputDag->CustCtl3());
   pInputDag2->CustCtl4(pInputDag->CustCtl4());
   pInputDag2->CustNbr(pInputDag->CustNbr());
   //Begin Chalongchai 19-may-2011 CR :# DC001 AddInputDAGToRM
   cout << "start reset ResetAsdWVPCRMOWData" << endl;
   if(pInputDag->SrchComdLine()!="")
   {   
       //cout << "pInputDag->SrchComdLine() != empty in iqDAccountOwner->SetSearchCriteria  pInputDag->SrchComdLine()='"+ pInputDag->SrchComdLine() +"'" << endl;
	   pInputDag2->SrchComdLine(pInputDag->SrchComdLine());//BIN Number 10 digits+ space 65 digits
   }
   //End Chalongchai 19-may-2011 CR :# DC001 AddInputDAGToRM
   SDWVPCRMOW->Reinit();

   pTSHeader->RemoteTPName(pTSHeader2->RemoteTPName());
   pTSHeader->PSBARC1(pTSHeader2->PSBARC1());
   pTSHeader->ExtTranCode(pTSHeader2->ExtTranCode());
   pTSHeader->OverrideTellerId(pTSHeader2->OverrideTellerId());
   pTSHeader->TranSeq(pTSHeader2->TranSeq());
   pTSHeader->TranTime(pTSHeader2->TranTime());
   pTSHeader->LandFill0(pTSHeader2->LandFill0());
   pTSHeader->RecLen(pTSHeader2->RecLen());
   pTSHeader->UserId(pTSHeader2->UserId());
   pTSHeader->FunSecurityCode(pTSHeader2->FunSecurityCode());
   pTSHeader->BusModuleType(pTSHeader2->BusModuleType());
   pTSHeader->BusinessModule(pTSHeader2->BusinessModule());
   pTSHeader->MaximumSeverity(pTSHeader2->MaximumSeverity());
   pTSHeader->AppcErrorCode(pTSHeader2->AppcErrorCode());
   pTSHeader->NumDags(pTSHeader2->NumDags());

        
        
   pInputDag->BegKey(pInputDag2->BegKey());
   pInputDag->EndKey(pInputDag2->EndKey());
   pInputDag->ReqFromEntKey(pInputDag2->ReqFromEntKey());
   pInputDag->CustCtl1(pInputDag2->CustCtl1());
   pInputDag->CustCtl2(pInputDag2->CustCtl2());
   pInputDag->CustCtl3(pInputDag2->CustCtl3());
   pInputDag->CustCtl4(pInputDag2->CustCtl4());
   pInputDag->CustNbr(pInputDag2->CustNbr());
   //Begin Chalongchai 19-may-2011 CR :# DC001 AddInputDAGToRM 
   if(pInputDag2->SrchComdLine() !="")
   {
       //cout << "pInputDag2->SrchComdLine() != empty in iqDAccountOwner->SetSearchCriteria  pInputDag2->SrchComdLine()='"+ pInputDag2->SrchComdLine() +"'" << endl;
	   pInputDag->SrchComdLine(pInputDag2->SrchComdLine());//BIN Number 10 digits+ space 65 digits
   }

   //End Chalongchai 19-may-2011 CR :# DC001 AddInputDAGToRM
}




//## Other Operations (implementation)
long AiqDAccountOwner::Get (AbcIAccountKey* const pIAccountKey, AiqIAccountOwners* pAccountOwners, AbcIControlBlock* pIControlBlock)
{
  //## begin AiqDAccountOwner::Get%37FA46AD0222.body preserve=yes
   long RetCode = BC_NO_ERRORS;
   RWCString HostLogId;

   #ifdef _DEBUG
   cout << "Entered AbcDAccountOwner::Get(): " << endl;
   #endif

   //make an instance of the class that represents the transaction
   AsdWVPCRMOWData WVPCRMOW;

   //WVPCRMOW.TSHeader is a pointer that is created in the transaction object and intialized in its constructor
   AsdWVPCRMOWData::AsdTSHeader* pTSHeader = WVPCRMOW.TSHeader;

   //WVPCRMOW.WVRMOWNI is a pointer that is created in the transaction object and intialized in its constructor
   AsdWVPCRMOWData::AsdWVRMOWNI* pInputDag = WVPCRMOW.WVRMOWNI;

   //WVPCRMOW.WVRMOWNO is a pointer that is created in the transaction object and intialized in its constructor
   AsdWVPCRMOWData::AsdWVRMOWNO* pOutputDag = WVPCRMOW.WVRMOWNO;

   //WVPCRMOW.TSMDA is a pointer that is created in the transaction object and intialized in its constructor
   AsdWVPCRMOWData::AsdTSMDA* pTSMDA = WVPCRMOW.TSMDA;

   AbcIPControlBlockTranSp pCBTran = pIControlBlock;
   AbcIMessagesSp pIMessages = pIControlBlock->Messages();
   HostLogId = pCBTran->HostLogonId();

   RetCode = SetSearchCriteria( pInputDag, pIAccountKey, pIControlBlock ); 
   //Begin Chalongchai 20-May-2011 CR :# DC001 AddInputDAGToRM 
   // cout << "Before DeleteUserParam in abcDAccountOwner::Get(): srchcomdline is '"+ pCBTran->FindUserParm("srchcomdline") +"'" << endl;
   // Remove extensions 'srchcomdline' since it not use;
   DeleteUserParam( pCBTran, "srchcomdline" );
   // cout << "After DeleteUserParam in abcDAccountOwner::Get(): srchcomdline is '"+ pCBTran->FindUserParm("srchcomdline") +"'" << endl;
   //End Chalongchai 20-May-2011 CR :# DC001 AddInputDAGToRM 
   if (RetCode != BC_NO_ERRORS) {
      pCBTran->AddMessage(BUSINESS_COMPONENT, MSG_BC_UNABLE_TO_COMPLETE_FUNCTION, BC_FATAL, "In AiqDAccountInquiry::Get, could not complete call to iqDWvrmowni::SetSearchCriteria");
      return BC_FATAL;
   }   
 
   pInputDag->MoreInd(" ");
     
   while (TRUE)
   {
       pTSHeader->UserId(HostLogId);
       pTSHeader->BusinessModule("WVPCRMOW");
       pTSHeader->BusModuleType("A");
       pTSHeader->ExtTranCode("RMRB");
       pTSHeader->FunSecurityCode("I");       
       pTSHeader->RemoteTPName(WVPCRMOW.GetRemoteTpName(REMOTETP));       

       //RetCode = WVPCRMOW.SessionExecute(pIControlBlock);
        RetCode = WVPCRMOW.Execute(pIControlBlock);
		   

       if ( RetCode != BC_FATAL )
       {

           if (pOutputDag->TblUsed() != 0)
           {

               RetCode = PopulateData(pOutputDag, pAccountOwners,  pIControlBlock );


               if ( RetCode != BC_NO_ERRORS )
               { 

				   ResetAsdWVPCRMOWData(&WVPCRMOW);

                   return RetCode;
               }
           }

           if ( pInputDag->MoreInd() == "N" ) 
           {

			   break;
           }

       }
       else
       {     
           return RetCode;
       }
   }

   return RetCode; 
  //## end AiqDAccountOwner::Get%37FA46AD0222.body
}

long AiqDAccountOwner::PopulateData (AsdWVPCRMOWData::AsdWVRMOWNO* pOutputData, AiqIAccountOwners* pAccountOwners, AbcIControlBlock* pIControlBlock)
{
  //## begin AiqDAccountOwner::PopulateData%37FA48D9033A.body preserve=yes

    long RetCode = BC_NO_ERRORS;
    HRESULT hresult;

    AbcIPControlBlockTranSp pCB = pIControlBlock;
    AbcIMessagesSp Messages(pIControlBlock->Messages());

    long NumberOfOwners = pOutputData->TblUsed();
    long Index = 0;
    for (; Index < NumberOfOwners; Index++)
    {
          AiqIAccountOwnerSp pIAccountOwner;
          hresult =  pIAccountOwner.CreateInstance( CLSID_AiqPAccountOwner, 0, CLSCTX_INPROC_SERVER );
          if ( FAILED( hresult ) )
          {
              pCB->AddMessage( BUSINESS_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "CLSID_AbcPAccountOwner in AbcDAccountOwner::PopulateData" );
              return BC_FATAL;
          }

          AbcIAccountKeySp pICustKey = pIAccountOwner->CustomerKey();
          pICustKey->ApplicationId("RM");
          pICustKey->Control1(pOutputData->CCustLst[Index].CustCtl1() );
          pICustKey->Control2(pOutputData->CCustLst[Index].CustCtl2() );
          pICustKey->Control3(pOutputData->CCustLst[Index].CustCtl3() );
          pICustKey->Control4(pOutputData->CCustLst[Index].CustCtl4() );
          pICustKey->AccountNumber(pOutputData->CCustLst[Index].CustNbr() );
          pIAccountOwner->Ownership( pOutputData->CCustLst[Index].PriSecOthCd() );
          pIAccountOwner->NameLine1( pOutputData->CCustLst[Index].NameLine1() );

          #ifdef _DEBUG
          cout << "Account Owner #" << Index << endl;
          cout << "AppID:      " << pIAccountOwner->CustomerKey()->ApplicationId() << endl;
          cout << "Control 1 : " << pIAccountOwner->CustomerKey()->Control1() << endl;
          cout << "Control 2 : " << pIAccountOwner->CustomerKey()->Control2() << endl;
          cout << "Control 3 : " << pIAccountOwner->CustomerKey()->Control3() << endl;
          cout << "Control 4 : " << pIAccountOwner->CustomerKey()->Control4() << endl;
          cout << "CustomerNumber: " << pIAccountOwner->CustomerKey()->AccountNumber() << endl;
          cout << "Ownership : " << pIAccountOwner->Ownership() << endl; 
          cout << "NameLine1 : " << pIAccountOwner->NameLine1() << endl;
          #endif

          pAccountOwners->AccountOwnerList().append(pIAccountOwner);
          //pIAccountOwnerList->append( pIAccountOwner );
    }

    return RetCode;
  //## end AiqDAccountOwner::PopulateData%37FA48D9033A.body
}

HRESULT STDMETHODCALLTYPE AiqDAccountOwner::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AiqDAccountOwner::QueryInterface%3828860C0044.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) this;
  else
      if (riid == IID_IAiqIDAccountOwner)
          *ppvObject = (AiqIDAccountOwner* ) this;
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
  //## end AiqDAccountOwner::QueryInterface%3828860C0044.body
}

ULONG STDMETHODCALLTYPE AiqDAccountOwner::AddRef ()
{
  //## begin AiqDAccountOwner::AddRef%3828860C0148.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AiqDAccountOwner::AddRef%3828860C0148.body
}

ULONG STDMETHODCALLTYPE AiqDAccountOwner::Release ()
{
  //## begin AiqDAccountOwner::Release%3828860C0184.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AiqDAccountOwner::Release%3828860C0184.body
}

HRESULT AiqDAccountOwner::FinalConstruct ()
{
  //## begin AiqDAccountOwner::FinalConstruct%3828860C01B6.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  return hresult;
  //BC end com.finalConstruct
  //## end AiqDAccountOwner::FinalConstruct%3828860C01B6.body
}

// Additional Declarations
  //## begin AiqDAccountOwner%37FA464D036E.declarations preserve=yes
  //## end AiqDAccountOwner%37FA464D036E.declarations

//## begin module%38297D650028.epilog preserve=yes
long AiqDAccountOwner::SetSearchCriteria (AsdWVPCRMOWData::AsdWVRMOWNI* pInputDag, AbcIAccountKey* pIAccountKey, AbcIControlBlock* pIControlBlock)
{
    RWCString AccountNumber = pIAccountKey->AccountNumber();
    char SeqCode[3];
    int KeyLength;
    if (findMatch(pIAccountKey->ApplicationId().data(), SeqCode, KeyLength))
    {
        pInputDag->ReqFromApplCd(SeqCode);
        if (AccountNumber.length() == KeyLength)
        {
            //do nothing
        }
        else
        {
            AccountNumber = AccountNumber.strip(RWCString::leading, '0');
            int CharactersLacking = KeyLength - AccountNumber.length();
            if (CharactersLacking > 0)
            {
                AccountNumber = AccountNumber.prepend('0', CharactersLacking);
            }
        }
    }

    RWCString AccountKey = pIAccountKey->Control1();
    AccountKey += pIAccountKey->Control2();
    AccountKey += pIAccountKey->Control3();
    AccountKey += pIAccountKey->Control4();
    AccountKey += AccountNumber;

    pInputDag->BegKey(AccountKey);
    pInputDag->EndKey(AccountKey);
    pInputDag->ReqFromEntKey(AccountKey);

    //cout << "pInputDag->ReqFromEntKey : " << pInputDag->ReqFromEntKey() << endl;

    pInputDag->CustCtl1(pIAccountKey->Control1());
    pInputDag->CustCtl2(pIAccountKey->Control2());
    pInputDag->CustCtl3(pIAccountKey->Control3());
    pInputDag->CustCtl4(pIAccountKey->Control4());
    pInputDag->CustNbr(AccountNumber);
    
	//Begin Chalongchai 20-May-2011 CR :# DC001 AddInputDAGToRM 
	AbcIPControlBlockTranSp	pCBTranSp( pIControlBlock );
	RWCString sSrchComdLine = pCBTranSp->FindUserParm("srchcomdline");
	#ifdef _DEBUG
	cout << "iqDAccountOwner->SetSearchCriteria  srchcomdline='"+ sSrchComdLine +"'" << endl;
	#endif
	//cout << "Start checking sSrchComdLine in iqDAccountOwner->SetSearchCriteria  srchcomdline='"+ sSrchComdLine +"'" << endl;
	if(sSrchComdLine!="")
	{
	    pInputDag->SrchComdLine(sSrchComdLine);//BIN Number 10 digits + space 65 digits
	}
	//cout << "End checking sSrchComdLine in iqDAccountOwner->SetSearchCriteria  srchcomdline='"+ sSrchComdLine +"'" << endl;
    //End Chalongchai 20-May-2011 CR :# DC001 AddInputDAGToRM
    return BC_NO_ERRORS;
}

//## end module%38297D650028.epilog
