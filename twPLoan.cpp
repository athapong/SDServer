//## begin module%39463187022B.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/tw/twLoan/twPLoan.cpp-arc   1.5   28 Sep 2009 10:32:50   sddevl  $
//## end module%39463187022B.cm

//## begin module%39463187022B.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%39463187022B.cp

//## Module: twPLoan%39463187022B; Package body
//## Subsystem: twLoan::twLoan Process%394630D50214
//## Source file: C:\Develop\GeneratedCode\tw\twLoan\twPLoan.cpp

//## begin module%39463187022B.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
#include "twIDBalanceAdjustment.h"
#include "twIDMultiBalanceAdjustment.h"

//Begin LN Oct.21,2002 TMB8.0.4 #TW-010
#include "twIDLoanReceiptDetail.h"
BC_EXTERN_GUID(CLSID_AtwDLoanReceiptDetail)
#include "bcIDateTime.h"
#include "bcIPDateTime.h"
//End LN Oct.21,2002 TMB8.0.4 #TW-010

#include "twIMessageManager.h"
#include "bcIServiceKey.h"
#include "bcIPServiceHostFlags.h"
#include "twIPCustomerIdentification.h"
#include "bcIPService2.h"
#include "twITracking.h"
  //BC end module.additionalIncludes
//## end module%39463187022B.additionalIncludes

//## begin module%39463187022B.includes preserve=yes
#include "twLoan.h"
#include "twSupport.h"
#include "twIDBalanceAdjustment.h"
//## end module%39463187022B.includes

// twPLoan
#include "twPLoan.h"
//## begin module%39463187022B.declarations preserve=no
//## end module%39463187022B.declarations
//## Begin Thawee 22-Sep-2009 
#include "twIPChequeLog.h"
//## End Thawee 22-Sep-2009

//## begin module%39463187022B.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
BC_EXTERN_GUID(CLSID_AtwPKey)
BC_EXTERN_GUID(CLSID_AbcPUserParams)
BC_EXTERN_GUID(CLSID_AtwPTransactionFlags)
BC_EXTERN_GUID(CLSID_AtwPDebitCreditEntries)
BC_EXTERN_GUID(CLSID_AtwPTellerMonetary)
BC_EXTERN_GUID(CLSID_AtwPDebitCreditService)
BC_EXTERN_GUID(CLSID_AtwPTellerTracking)
BC_EXTERN_GUID(CLSID_AtwPCustomerIdentifications)
BC_EXTERN_GUID(CLSID_AbcPService2)
BC_EXTERN_GUID(CLSID_AtwIDMultiBalanceAdjustment)
BC_EXTERN_GUID(CLSID_AtwPSubRegionDefault)
BC_EXTERN_GUID(CLSID_AtwDBalanceAdjustment)
BC_EXTERN_GUID(CLSID_AbcPDateTime)
BC_EXTERN_GUID(CLSID_AtwPMessageManager)
BC_EXTERN_GUID(CLSID_AbcPServiceHostFlags)
BC_EXTERN_GUID(CLSID_AbcPServiceKey)
BC_EXTERN_GUID(CLSID_AtwPCustomerIdentification)
BC_EXTERN_GUID(CLSID_AtwDMultiBalanceAdjustment)
//## Begin Thawee 22-Sep-2009 
BC_EXTERN_GUID(CLSID_AtwPChequeLog)
//## End Thawee 22-Sep-2009
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {5D58DCB0-DDBB-4F10-B2E3-FAAEC721A689}
ABCIMPLEMENT_OLECREATE2(AtwPLoan, "AtwPLoan.1", 0x5D58DCB0, 0xDDBB, 0x4F10, 0xB2, 0xE3, 0xFA, 0xAE, 0xC7, 0x21, 0xA6, 0x89);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {5D58DCB0-DDBB-4F10-B2E3-FAAEC721A689}
// DEFINE_GUID(CLSID_AtwPLoan, 0x5D58DCB0, 0xDDBB, 0x4F10, 0xB2, 0xE3, 0xFA, 0xAE, 0xC7, 0x21, 0xA6, 0x89);

  //BC end guid.ole
//## end module%39463187022B.additionalDeclarations

// Class AtwPLoan 


//#define SERVER_TRACE
// Rel7.0 Reapply - SMcDonald - 01/16/2001
// Begin Fix 12/18/2000 SD7.0 Peoples #1539 BSouthard
#define INSERT_FLAG 1
#define UPDATE_FLAG 2
// End Fix 12/18/2000 SD7.0 Peoples #1539 BSouthard

extern long FormatReversalsForForwarding( AtwITransactionFlags*, AtwIDebitCreditEntries*, AbcIService2*, AbcIControlBlock* );

AtwPLoan::AtwPLoan()
  //## begin AtwPLoan::AtwPLoan%.hasinit preserve=no
      : m_RefCnt(0), m_IsPassbook(0), m_GuarantorOnExemptList("N")
  //## end AtwPLoan::AtwPLoan%.hasinit
  //## begin AtwPLoan::AtwPLoan%.initialization preserve=yes
  //## end AtwPLoan::AtwPLoan%.initialization
{
  //## begin AtwPLoan::AtwPLoan%.body preserve=yes
 //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AtwPLoan)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AtwPLoan::AtwPLoan%.body
}


AtwPLoan::~AtwPLoan()
{
  //## begin AtwPLoan::~AtwPLoan%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AtwPLoan)
  AbcOleUnlockApp();
  if(m_Key != NULL)
  {
     m_Key->Release();
  }
  if(m_UserParams != NULL)
  {
     m_UserParams->Release();
  }
  if(m_TransactionFlags != NULL)
  {
     m_TransactionFlags->Release();
  }
  if(m_DebitCreditEntries != NULL)
  {
     m_DebitCreditEntries->Release();
  }
  if(m_TellerMonetary != NULL)
  {
     m_TellerMonetary->Release();
  }
  if(m_DebitCreditService != NULL)
  {
     m_DebitCreditService->Release();
  }
  if(m_TellerTracking != NULL)
  {
     m_TellerTracking->Release();
  }
  if(m_CustomerIdentifications != NULL)
  {
     m_CustomerIdentifications->Release();
  }
  if(m_Service2 != NULL)
  {
     m_Service2->Release();
  }
  //BC end traceCom.dtor
  //## end AtwPLoan::~AtwPLoan%.body
}



//## Other Operations (implementation)
HRESULT STDMETHODCALLTYPE AtwPLoan::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AtwPLoan::QueryInterface%3946318700A5.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) (AtwILoan*) this;
  else
      if (riid == IID_IAtwILoan)
          *ppvObject = (AtwILoan* ) this;
  else
      if (riid == IID_IAtwIPForward)
          *ppvObject = (AtwIPForward* ) this;
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
  //## end AtwPLoan::QueryInterface%3946318700A5.body
}

ULONG STDMETHODCALLTYPE AtwPLoan::AddRef ()
{
  //## begin AtwPLoan::AddRef%394631870145.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AtwPLoan::AddRef%394631870145.body
}

ULONG STDMETHODCALLTYPE AtwPLoan::Release ()
{
  //## begin AtwPLoan::Release%39463187016D.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AtwPLoan::Release%39463187016D.body
}

HRESULT AtwPLoan::FinalConstruct ()
{
  #ifdef SERVER_TRACE
  cout << "Inside AtwPLoan::FinalConstruct()" << endl;
  #endif

  //## begin AtwPLoan::FinalConstruct%39463187018B.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hResult = S_OK;
  if (hResult == S_OK) hResult = AbcCoCreateInstance(CLSID_AtwPKey, NULL, CLSCTX_INPROC_SERVER, IID_IAtwIKey, (LPVOID*)& m_Key);
  if (hResult == S_OK) hResult = AbcCoCreateInstance(CLSID_AbcPUserParams, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIUserParams, (LPVOID*)& m_UserParams);
  if (hResult == S_OK) hResult = AbcCoCreateInstance(CLSID_AtwPTransactionFlags, NULL, CLSCTX_INPROC_SERVER, IID_IAtwITransactionFlags, (LPVOID*)& m_TransactionFlags);

  if (hResult == S_OK)
  {
  hResult = AbcCoCreateInstance(CLSID_AtwPDebitCreditEntries, NULL, CLSCTX_INPROC_SERVER, IID_IAtwIDebitCreditEntries, (LPVOID*)& m_DebitCreditEntries);
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of TransactionFlags failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK)
  {
     hResult = AbcCoCreateInstance(CLSID_AtwPTellerMonetary, NULL, CLSCTX_INPROC_SERVER, IID_IAtwITellerMonetary, (LPVOID*)& m_TellerMonetary);
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of DebitCreditEntries failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK)
  {
     hResult = AbcCoCreateInstance(CLSID_AtwPDebitCreditService, NULL, CLSCTX_INPROC_SERVER, IID_IAtwIDebitCreditService, (LPVOID*)& m_DebitCreditService);
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of TellerMonetary failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK)
  {
     hResult = AbcCoCreateInstance(CLSID_AtwPTellerTracking, NULL, CLSCTX_INPROC_SERVER, IID_IAtwITellerTracking, (LPVOID*)& m_TellerTracking);
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of DebitCreditService failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK)
  {
     hResult = AbcCoCreateInstance(CLSID_AtwPCustomerIdentifications, NULL, CLSCTX_INPROC_SERVER, IID_IAtwICustomerIdentifications, (LPVOID*)& m_CustomerIdentifications);
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of TellerTracking failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK) 
  {
     hResult = AbcCoCreateInstance(CLSID_AbcPService2, NULL, CLSCTX_INPROC_SERVER, IID_IAbcIService2, (LPVOID*)& m_Service2);
  }
  else
  { 
     #ifdef SERVER_TRACE
     cout << "Create of CustomerIdentifications failed inside twPLoan.cpp" << endl;
     #endif
  }

  if (hResult == S_OK)
  {
  }
  else
  {
     #ifdef SERVER_TRACE
     cout << "Create of AbcPService2 failed inside twPLoan.cpp" << endl;
     #endif
  }

  #ifdef SERVER_TRACE
  cout << "Ready to leave FinalContruct:  hResult == " << hResult << endl;
  #endif

  return hResult;
  //BC end com.finalConstruct
  //## end AtwPLoan::FinalConstruct%39463187018B.body
}

long AtwPLoan::Apply (AbcIControlBlock* pIControlBlock)
{
  //## begin AtwPLoan::Apply%394637100106.body preserve=yes
   short StepId = 0;
   short PostedToHost = 0;
   HRESULT hResult = BC_NO_ERRORS;
   long ReturnCode = BC_NO_ERRORS;
   short ServiceID = LOANS_MONETARIES_SERVICE;
   RWCString TempCashIn = "0.00";
   RWCString TempCashOut = "0.00";
   RWCString TrackingID;
   RWCString Mode;

   AbcIPServiceHostFlagsSp pServiceHostFlagsSp;
   AbcIServiceKeySp pServiceKeySp;
   AbcIServiceStepSp pStepSp;
   //DDS Begin 25-Jun-2004 Memory Leaks
   //AbcIPService2Sp pService2Sp( Service2() );
   AbcIService2Sp pIService2Sp( Service2() );
   AbcIPService2Sp pService2Sp( pIService2Sp );
   //DDS End 25-Jun-2004 Memory Leaks
   AbcIServiceStepsSp pStepsSp( pService2Sp->Steps() );
   AtwITransactionFlagsSp pTranFlagsSp( TransactionFlags() );

   // Get a pointer to the ControlBlockTran Object
   AbcIPControlBlockTranSp pCBTranSp(pIControlBlock);
	//Begin DDS 10-Jun-2004 Timings Available
	clock_t StartTime, EndTime, TotalStart, TotalEnd;
	double Elapsed, TotalElapsed;
	time_t ClockTime, ClockStart;
	RWCString CurrentTime;
	RWCString Timing;
	Timing = pCBTranSp->FindUserParm("LOG_TIMING");
	RWCString ReportLogonID = pIControlBlock->LogonId();
	if ( Timing == "Y" )
	{
		TotalStart = clock();
		time( &ClockStart );
	}
	//End DDS 10-Jun-2004 Timings Available

   #ifdef SERVER_TRACE
      //cout << endl;
      cout << "Inside the Loan::Apply Method" << endl;
      //cout << "Aggregated Key object: "           << endl;
      //m_Key->Print();
      //cout << endl;
   #endif

   // Begin Commit/Rollback Block
   pCBTranSp->StartTransaction();


   // Get a pointer to the TrackingStep object
   pStepSp = pStepsSp->ServiceStepList().at( StepId );

   pStepSp->Posted("N");
   pStepSp->StatusId( PENDING );

   #ifdef SERVER_TRACE
	   cout << "Ready to call Loan::DatabaseApply" << endl;
   #endif

   // Save off the Database Data 
	if ( Timing == "Y" )
	{
		StartTime = clock();
		time(&ClockTime);
	}
   ReturnCode = DatabaseApply( pIControlBlock, TrackingID );
	if ( Timing == "Y" )
	{
		EndTime = clock();
		Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
		CurrentTime = ctime(&ClockTime);
		CurrentTime = CurrentTime(11,8);
		cout << "twLoanApply->DatabaseApply() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
	}

   #ifdef SERVER_TRACE
		cout << "Loan::Apply call to Loan::DatabaseApply returned " << ReturnCode << endl;
		cout << "TrackingID after DatabaseApply = " << TrackingID << endl;
   #endif

   if( ReturnCode == BC_NO_ERRORS )
      Mode = pCBTranSp->FindUserParm( "TWMODE" );

   // Rel7.0 Reapply - SMcDonald - 01/16/2001
   // Begin Fix 12/18/2000 SD7.0 Peoples #1655 BSouthard
   RWCString tempFiller = "0";
   RWCString tempLocID  = pCBTranSp->FindUserParm("CURRENT_USER_LOCATIONID");
   short     padLength  = (4 - tempLocID.length() );

   for( int tempCount = 0; tempCount < padLength; tempCount++ )
   {
      tempLocID.prepend( tempFiller.data() );
   }
      
   pTranFlagsSp->Location( tempLocID );
   // End Fix #1655

   if( (ReturnCode == BC_NO_ERRORS ) && ( ( Mode == "PRODUCTION") || (Mode == "ONLINE" ) || (pTranFlagsSp->Offline() == "N") ))
   {
		if ( Timing == "Y" )
		{
			StartTime = clock();
			time(&ClockTime);
		}
      ReturnCode = HostApply( pIControlBlock );
		if ( Timing == "Y" )
		{
			EndTime = clock();
			Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
			CurrentTime = ctime(&ClockTime);
			CurrentTime = CurrentTime(11,8);
			cout << "twLoanApply->HostApply() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
		}
      if( ReturnCode != BC_FATAL )
	 PostedToHost = 1;

       #ifdef SERVER_TRACE
         cout << "Loan::Apply call to Loan::HostApply returned " << ReturnCode << endl;
       #endif
   }
   // Disable Commit if necessary
   if( ReturnCode == BC_FATAL )
      pCBTranSp->DisableCommit();

   // End Commit/RollBack Block
   pCBTranSp->EndTransaction();


   // If we posted to the HOST update the Posted Flag in the Database
	if ( Timing == "Y" )
	{
		StartTime = clock();
		time(&ClockTime);
	}
   if( PostedToHost == 1 )
   { 
       RWDBDateTime now;

       // Begin Temporary Commit/RollBack Segment
       pCBTranSp->StartTransaction();
	
       //DDS Begin 25-Jun-2004 Memory Leaks
       //AbcIPService2Sp pIPService2Sp( Service2() );
       //AbcIPDateTimeSp pDateTimeSp( pStepSp->PostedDate() );
       AbcIPService2Sp pIPService2Sp( pIService2Sp );
       AbcIDateTimeSp pIDateTimeSp( pStepSp->PostedDate() );
       AbcIPDateTimeSp pDateTimeSp( pIDateTimeSp );
       //DDS End 25-Jun-2004 Memory Leaks
       pDateTimeSp->DatabaseDateTime( now );

       pStepSp->StatusId( COMPLETE );
       pStepSp->Posted( "Y" );

       pIPService2Sp->Save( "N", pIControlBlock );

       // End of Temporary Commit/Rollback Segment
       pCBTranSp->EndTransaction();
   }
   
   // Save off the Messages what went to the host.
   if( PostedToHost == 1 )
   {    
       // Begin Temporary Commit/RollBack Segment
       pCBTranSp->StartTransaction();

       AtwIMessageManagerSp pMsgManagerSp;
       hResult = pMsgManagerSp.CreateInstance( CLSID_AtwPMessageManager, NULL, CLSCTX_INPROC_SERVER);
       if( FAILED ( hResult ) )
       {
          ReturnCode = BC_WARNING;
          SetStatus( pCBTranSp, ReturnCode );
          pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_WARNING,
               "AtwQuickCash::Apply Create on AtwPMsgManagerSp" );
          #ifdef SERVER_TRACE
             cout << "Create on AtwPMsgManagerSp Object Failed : " << endl;
             cout << hex << hResult << dec << endl;
          #endif
       }
       AbcIServiceKeySp pServiceKeySp( pService2Sp->ServiceKey() ); 
       TrackingID = pServiceKeySp->ServiceId();

		ReturnCode = pMsgManagerSp->Save( pIControlBlock, TrackingID );
       #ifdef SERVER_TRACE
	  cout << "Call to AtwPMessageManager->Save returned " << ReturnCode << endl;
       #endif
       if(ReturnCode != BC_NO_ERRORS )
	  ReturnCode = BC_WARNING;
       
       // End of Temporary Commit/Rollback Segment
       pCBTranSp->EndTransaction();
    }  // End of if( PostedToHost == 1)


   // Save off the Transaction Flags from what went to the host.
   if( ReturnCode != BC_FATAL )
   {    
       // Begin Temporary Commit/RollBack Segment
       pCBTranSp->StartTransaction();

       long ModificationFlag = INSERT_FLAG;
       ModifyServiceHostFlags( pIControlBlock, pTranFlagsSp, pService2Sp, ModificationFlag );

       // End of Temporary Commit/Rollback Segment
       pCBTranSp->EndTransaction();
   }

   //Begin: Thawee 22-Sep-2009
    if ( ( ReturnCode != BC_FATAL ) && (PostedToHost == 1) )
    {
       pCBTranSp->StartTransaction();
       AtwIPChequeLogSp pChequeLogSp;
       hResult = pChequeLogSp.CreateInstance(CLSID_AtwPChequeLog, NULL, CLSCTX_INPROC_SERVER);
       if( !FAILED ( hResult ) )
       {
	      AtwIDebitCreditEntriesSp pIDebitCreditEntriesSp(DebitCreditEntries());
	      pChequeLogSp->Add(pIDebitCreditEntriesSp, pIService2Sp, pIControlBlock);
	}
	pCBTranSp->EndTransaction();
     }
   //End: Thawee 22-Sep-2009

	if ( Timing == "Y" )
	{
		EndTime = clock();
		Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
		CurrentTime = ctime(&ClockTime);
		CurrentTime = CurrentTime(11,8);
		cout << "twLoanApply->Service->Saves() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
	}

   #ifdef SERVER_TRACE
      cout << "Leaving the AtwPLoan::Apply Method with a ReturnCode of " << ReturnCode  << endl;
   #endif

	if ( Timing == "Y" )
	{
		TotalEnd = clock();
		TotalElapsed = (double)(TotalEnd - TotalStart)/CLOCKS_PER_SEC;
		CurrentTime = ctime(&ClockStart);
		CurrentTime = CurrentTime(11,8);
		cout << "twLoanApply() " << CurrentTime << " " << TotalElapsed << " " << ReportLogonID << endl;
	}
   return ReturnCode;
  //## end AtwPLoan::Apply%394637100106.body
}

long AtwPLoan::Get (AbcIControlBlock* pIControlBlock, const RWCString& TrackingID)
{
  //## begin AtwPLoan::Get%3946371E037D.body preserve=yes
	short   StepId     = 0;
     long    ReturnCode = BC_NO_ERRORS;
     HRESULT hResult    = BC_NO_ERRORS;
     
     AtwISubRegionDefaultSp   pSubRegionDefaultSp;
     AbcIServiceKeySp         pServiceKeySp;
     AbcIPServiceHostFlagsSp  pServiceHostFlagsSp;
     AbcIPControlBlockTranSp  pCBTranSp(    pIControlBlock        );
     AbcIService2Sp           pService2Sp(  Service2()           );
     AbcIServiceStepsSp       pStepsSp(     pService2Sp->Steps() );
     AtwITransactionFlagsSp   pTranFlagsSp( TransactionFlags()   );
     AtwICustomerIdentificationsSp pCustIdsSp( CustomerIdentifications() );
   
     #ifdef SERVER_TRACE
        cout << "Inside AtwPLoan::Get" << endl;
     #endif

     // Create the necessary objects
     hResult = pServiceHostFlagsSp.CreateInstance(CLSID_AbcPServiceHostFlags,NULL,CLSCTX_INPROC_SERVER);
     if(FAILED(hResult))
     {
         ReturnCode = BC_FATAL;
         pCBTranSp->AddMessage(TW_COMPONENT,MSG_BC_INTERFACE_CREATE_FAILED,
                BC_FATAL,"AtwLoan::Get  Create AbcPServiceHostFlags Object");
          SetStatus( pIControlBlock, ReturnCode );
     }
     if( ReturnCode == BC_NO_ERRORS )
     {
        hResult = pSubRegionDefaultSp.CreateInstance(CLSID_AtwPSubRegionDefault,NULL,CLSCTX_INPROC_SERVER);
        if( FAILED ( hResult ) )
        {
           #ifdef SERVER_TRACE
              cout << "pSubRegionDefaultSp.CreateInstance failed" << endl;
           #endif
   
           ReturnCode = BC_FATAL;
           pCBTranSp->AddMessage(TW_COMPONENT,MSG_BC_INTERFACE_CREATE_FAILED,
                  BC_FATAL,"AtwQuickCredit::Get  Create AtwPSubRegionDefault Object");
           SetStatus( pIControlBlock, ReturnCode );
        }
     }

     // Read the Customer IDs that were saved off
     if( ReturnCode == BC_NO_ERRORS )
       ReturnCode = pCustIdsSp->GetListForTrackingID( TrackingID, pIControlBlock);

     #ifdef SERVER_TRACE
        long ItemCount = pCustIdsSp->CustomerIdentificationList().entries();
	     cout << "The CustomerIdentification List has " << ItemCount << " items in it." << endl;
     #endif

     if ( ReturnCode == BC_NO_ERRORS )
     {
        m_TellerMonetary->TrackingID( TrackingID );
        ReturnCode = m_TellerMonetary->Get( pIControlBlock, m_DebitCreditEntries );

        if ( ReturnCode == BC_NO_ERRORS )
        {
           AbcIService2Sp pService2Sp(Service2());
           m_DebitCreditService->TrackingID( TrackingID );
           ReturnCode =  m_DebitCreditService->Get( pIControlBlock, m_DebitCreditEntries, pService2Sp );
           #ifdef SERVER_TRACE
              cout << "The call to m_DebitCreditService->Get returned " << ReturnCode << endl;
           #endif
        }
     }

     // Read the ServiceHostFlags and set up a TransactionFlags Object
     if( ReturnCode == BC_NO_ERRORS )
     {
   	   AbcIServiceStepSp pStepSp = pStepsSp->ServiceStepList().at( StepId );
   	   AbcIDateTimeSp    pPostedDateSp(pStepSp->PostedDate());
   
         pServiceKeySp = pService2Sp->ServiceKey();
           
         long TempReturnCode =  pServiceHostFlagsSp->Get( pServiceKeySp, StepId, pIControlBlock );
   
       	 #ifdef SERVER_TRACE
              cout << "Call to ServiceHostFlags->Get returned " << TempReturnCode << endl;
         #endif
   
         AbcIDateTimeSp pTranDateTimeSp( pTranFlagsSp->TranDateTime() );
         pTranDateTimeSp->Date( pPostedDateSp->Date() );
         pTranDateTimeSp->Time( pServiceHostFlagsSp->TransactionTime( )             );
   
         pTranFlagsSp->OverrideLoginID(    pServiceHostFlagsSp->OverrideTellerID()    );
         pTranFlagsSp->Sequence(           pServiceHostFlagsSp->TransactionSequence() );
         pTranFlagsSp->Location(           pServiceHostFlagsSp->PhysicalLocation()    );
         pTranFlagsSp->ForcePost(          pServiceHostFlagsSp->StoreAndForward()     );
         pTranFlagsSp->PassbookRebid(      pServiceHostFlagsSp->PassbookRebid()       );      
         pTranFlagsSp->TellerOverride(     pServiceHostFlagsSp->TellerOverride()      );      
         pTranFlagsSp->SupervisorOverride( pServiceHostFlagsSp->SupervisorOverride()  );
         pTranFlagsSp->Reversal(           pServiceHostFlagsSp->Correction()          );    
         pTranFlagsSp->NextDay(            pServiceHostFlagsSp->NextDay()             );
         pTranFlagsSp->Training(           pServiceHostFlagsSp->TrainingMode()        );
         pTranFlagsSp->InquiryRebid (      pServiceHostFlagsSp->InquiryRebid()        );
         pTranFlagsSp->Offline(            pServiceHostFlagsSp->OfflineMode()         );
         pTranFlagsSp->AmountLimitOverride(pServiceHostFlagsSp->AmountLimitOverride() );
   
         #ifdef SERVER_TRACE
            cout << "The transactiontime read was -" << pServiceHostFlagsSp->TransactionTime() << "-" << endl;
         #endif
     }


     if( ReturnCode == BC_NO_ERRORS )
     {
        // Set up some temp pointers to other objects and their keys
        AtwIKey      *pTempIKey(           Key()                                );
        AtwIKey      *pDCServiceKey(      m_DebitCreditService->Key()          );
        AbcIDateTime *pTempDate(          pTempIKey->ProcessingDate()           );
        AbcIDateTime *pBusDate (          pDCServiceKey->ProcessingDate()      );

        // Move the data to our aggregated key object
        pTempIKey->SubRegionID(   pDCServiceKey->SubRegionID()         );
        pTempIKey->DrawerID(      pDCServiceKey->DrawerID()            );
        pTempIKey->CSUserID(      pDCServiceKey->CSUserID()            );
        pTempDate->Date(         pBusDate->Date()                     );
        pTempDate->Time(         pBusDate->Time()                     );

        // Release all the temp pointers we created
        pDCServiceKey->Release();
        pTempIKey->Release();
        pTempDate->Release();
        pBusDate->Release();
     }

     if( ReturnCode == BC_NO_ERRORS )
     {
        // Read the SubRegionDefault table for Negotiable IDs
        pSubRegionDefaultSp->SubRegionID( m_Key->SubRegionID() );
        ReturnCode = pSubRegionDefaultSp->Get( pIControlBlock );
        if( ReturnCode == BC_NO_ERRORS )
        {
           #ifdef SERVER_TRACE
              cout << "pSubRegionDefaultSp->Get returned " << ReturnCode << endl;
           #endif

           CashInNegotiableID ( pSubRegionDefaultSp->CashInNegotiableID()  );
           CashOutNegotiableID( pSubRegionDefaultSp->CashOutNegotiableID() );
        }
        else
           SetStatus( pIControlBlock, ReturnCode );
     }

     // Return to Caller
     return ReturnCode;
  //## end AtwPLoan::Get%3946371E037D.body
}

long AtwPLoan::Update (AbcIControlBlock* pIControlBlock)
{
  //## begin AtwPLoan::Update%39463726023E.body preserve=yes
  return BC_NO_ERRORS;
  //## end AtwPLoan::Update%39463726023E.body
}

long AtwPLoan::GetDefaults (AbcIControlBlock* pIControlBlock, AtwIKey* pIKey)
{
  //## begin AtwPLoan::GetDefaults%3946373101A4.body preserve=yes
    long  retCode   = BC_NO_ERRORS;
    short ServiceID = LOANS_MONETARIES_SERVICE;
    AbcIPControlBlockTranSp pCBTranSp(pIControlBlock);
	 //Begin DDS 10-Jun-2004 Timings Available
	 clock_t StartTime, EndTime, TotalStart, TotalEnd;
	 double Elapsed, TotalElapsed;
	 time_t ClockTime, ClockStart;
	 RWCString CurrentTime;
	 RWCString Timing;
	 Timing = pCBTranSp->FindUserParm("LOG_TIMING");
	 RWCString ReportLogonID = pIControlBlock->LogonId();
	 if ( Timing == "Y" )
	 {
		 TotalStart = clock();
		 time( &ClockStart );
	 }
	 //End DDS 10-Jun-2004 Timings Available

    #ifdef SERVER_TRACE
    cout << "Inside Loan::GetDefaults " << endl;
    //cout << "The Key passed in : " << endl;
    //pIKey->Print();
    #endif

    Key(pIKey);
    AtwIKey * tempIKey(Key());

    // Call GetDefaults on the AbcIService2
    AbcIService2Sp pService2Sp(Service2());
	 if ( Timing == "Y" )
	 {
		 StartTime = clock();
		 time(&ClockTime);
	 }
    retCode = m_DebitCreditService->GetDefaults(pIControlBlock, ServiceID, tempIKey, pService2Sp);
	 if ( Timing == "Y" )
	 {
		 EndTime = clock();
		 Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
		 CurrentTime = ctime(&ClockTime);
		 CurrentTime = CurrentTime(11,8);
		 cout << "twLoanGetDefaults->DCService->GetDefaults() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
	 }
   
    tempIKey->Release();
    if(retCode == BC_NO_ERRORS)
    { 
       //DDS Begin 25-Jun-2004 Memory Leaks
       //AbcIPService2Sp pIPService2Sp( Service2() );
       AbcIService2Sp pIService2Sp( Service2() );
       AbcIPService2Sp pIPService2Sp( pIService2Sp );
       //DDS End 25-Jun-2004 Memory Leaks
       AbcIServiceStepsSp pServiceStepsSp( pIPService2Sp->Steps() );
       AbcIServiceStepSp  pServiceStepSp;
       AbcICurrencySp     pInCurrencySp;
       AbcICurrencySp     pOutCurrencySp;

       pServiceStepSp = pServiceStepsSp->ServiceStepList().at(0);  
       pInCurrencySp  = pServiceStepSp->InAmount();
       pInCurrencySp->Amount( "0.00" );

       pOutCurrencySp = pServiceStepSp->InAmount();
       pOutCurrencySp->Amount( "0.00" );
    }

    if ( Timing == "Y" )
	 {
	    TotalEnd = clock();
		 TotalElapsed = (double)(TotalEnd - TotalStart)/CLOCKS_PER_SEC;
		 CurrentTime = ctime(&ClockStart);
		 CurrentTime = CurrentTime(11,8);
		 cout << "twLoanGetDefaults() " << CurrentTime << " " << TotalElapsed << " " << ReportLogonID << endl;
	 }
    return retCode;
  //## end AtwPLoan::GetDefaults%3946373101A4.body
}

long AtwPLoan::GetPrintData (AbcIUserParams* pIUserParams, AbcIControlBlock* pIControlBlock)
{
  //## begin AtwPLoan::GetPrintData%394637390065.body preserve=yes
   long                      Status = BC_NO_ERRORS;
   long			     NewStatus;
   AbcIPControlBlockTranSp   pICBTranSp(pIControlBlock);
	//Begin DDS 10-Jun-2004 Timings Available
	clock_t StartTime, EndTime, TotalStart, TotalEnd;
	double Elapsed, TotalElapsed;
	time_t ClockTime, ClockStart;
	RWCString CurrentTime;
	RWCString Timing;
	Timing = pICBTranSp->FindUserParm("LOG_TIMING");
	RWCString ReportLogonID = pIControlBlock->LogonId();
	if ( Timing == "Y" )
	{
		TotalStart = clock();
		time( &ClockStart );
	}
	//End DDS 10-Jun-2004 Timings Available
   AbcIService2Sp            pIService2Sp(Service2());
   AbcIServiceKeySp          pIServiceKeySp(pIService2Sp->ServiceKey());
   AtwIDebitCreditEntriesSp  pIDebitCreditEntriesSp(DebitCreditEntries());

   //Begin LN Oct.21,2002 TMB8.0.4 #TW-010
   RWCString TrackingID;
   //End LN Oct.21,2002 TMB8.0.4 #TW-010

   #ifdef SERVER_TRACE
      cout << "AtwPLoan::GetPrintData: Entering" << endl;
   #endif

   pICBTranSp->StartTransaction();

	if ( Timing == "Y" )
	{
		StartTime = clock();
		time(&ClockTime);
	}
   Status = m_DebitCreditService->GetPrintData(pIUserParams, pIDebitCreditEntriesSp, pIService2Sp, pIControlBlock);
	if ( Timing == "Y" )
	{
		EndTime = clock();
		Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
		CurrentTime = ctime(&ClockTime);
		CurrentTime = CurrentTime(11,8);
		cout << "twLoanPrint->DCService->GetPrint() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
	}
  
   // Begin LN Oct.21,2002 TMB8.0.4 #TW-010
   if (Status != BC_FATAL)
   {
      TrackingID = pIServiceKeySp->ServiceId();

      #ifdef SERVER_TRACE
	cout << "TrackingID = " << pIServiceKeySp->ServiceId() << endl;
      #endif

		if ( Timing == "Y" )
		{
			StartTime = clock();
			time(&ClockTime);
		}
      NewStatus = GetLoanReceiptPrintData(pIUserParams, pIControlBlock, TrackingID);
		if ( Timing == "Y" )
		{
			EndTime = clock();
			Elapsed = (double)(EndTime - StartTime)/CLOCKS_PER_SEC;
			CurrentTime = ctime(&ClockTime);
			CurrentTime = CurrentTime(11,8);
			cout << "twLoanPrint->GetLoanRecieptPrint() " << CurrentTime << " " << Elapsed << " " << ReportLogonID << endl;
		}
      Status = (NewStatus > Status) ? NewStatus : Status;
   }
   // End LN Oct.21,2002 TMB8.0.4 #TW-010
   
   if (Status == BC_FATAL)
   {
      #ifdef SERVER_TRACE
         cout << "AtwPLoan::GetPrintData: Status = " << Status << ", disabling commit" << endl;
      #endif
      pICBTranSp->DisableCommit();
   }

   pICBTranSp->EndTransaction();

   #ifdef SERVER_TRACE
      cout << "AtwPLoan::GetPrintData: Exiting, Status = " << Status << endl;
   #endif
	if ( Timing == "Y" )
	{
		TotalEnd = clock();
		TotalElapsed = (double)(TotalEnd - TotalStart)/CLOCKS_PER_SEC;
		CurrentTime = ctime(&ClockStart);
		CurrentTime = CurrentTime(11,8);
		cout << "twLoanPrint() " << CurrentTime << " " << TotalElapsed << " " << ReportLogonID << endl;
	}

   return Status;
  //## end AtwPLoan::GetPrintData%394637390065.body
}

//Begin  LN Oct.21,2002 TMB8.0.4 #TW-010
long AtwPLoan::GetLoanReceiptPrintData( AbcIUserParams* pIUserParams, AbcIControlBlock* pIControlBlock, const RWCString& TrackingID )
{
   long Status = BC_NO_ERRORS;
   HRESULT hResult = BC_NO_ERRORS;

   AbcIPControlBlockTranSp pCBTranSp(pIControlBlock);

   #ifdef SERVER_TRACE
	cout << "Inside AtwPLoan::GetLoanReceiptPrintData()" << endl;
   #endif

   AtwIDLoanReceiptDetailSp pLoanReceiptDetail;
   hResult = pLoanReceiptDetail.CreateInstance(CLSID_AtwDLoanReceiptDetail, NULL, CLSCTX_INPROC_SERVER);
   if (FAILED(hResult)) 
   {  
      Status = BC_FATAL;
      pCBTranSp->AddMessage(TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL,
			   "AtwDMultiBalanceAdjustment::GeLoanReceiptPrintData - "
			   "Cannot Create AtwDLoanReceiptDetail Object.");
      SetStatus( pIControlBlock, Status );
   }
   
   // Initialize the Database object
   Status = pLoanReceiptDetail->Initialize( pIControlBlock );
   if ( Status != DB_NO_ERRORS )
   {
      #ifdef SERVER_TRACE
           cout << " Error: pLoanReceiptDetail->Initialize " << endl;
      #endif

      pCBTranSp->AddMessage(TW_COMPONENT, DB_NOT_INITIALIZED, BC_FATAL, "AtwPLoan::GetLoanReceiptData" );
      pCBTranSp->DisableCommit();
      pCBTranSp->EndTransaction();
      SetStatus( pIControlBlock, Status );
      return BC_FATAL;
   }

   if (Status != BC_FATAL)
   {
      pLoanReceiptDetail->TrackingID( TrackingID );
      Status = pLoanReceiptDetail->Get( pIControlBlock );

      #ifdef SERVER_TRACE
	cout << "Tracking ID " << pLoanReceiptDetail->TrackingID() << endl;
      #endif

      if (Status == BC_FATAL)
      {
         #ifdef SERVER_TRACE
	    cout << "AtwPLoan::GetLoanReceiptPrintData: Unable to get LoanReceiptDetail data" << endl;
	 #endif
	 pCBTranSp->AddMessage(TW_COMPONENT, BC_GET_FAILED, BC_FATAL, 
				"AtwPLoan::GetLoanReceiptPrintData  "
	 			"Unable to get LoanReceiptDetail data" );
	 SetStatus(pIControlBlock, Status);
      }
   }

   if ( Status != BC_FATAL )
   {
      #ifdef SERVER_TRACE
          cout << "Status from pLoanReceiptDetail->Get() = " << Status << endl;
	  cout << "OK to print data" << endl;
      #endif

      RWCString Prefix = "";

      AddPrintDataItem( pIUserParams, Prefix, "ACCOUNT_NUMBER", pLoanReceiptDetail->AccountNumber() );
      AddPrintDataItem( pIUserParams, Prefix, "CURRENCY", pLoanReceiptDetail->Currency() );
      AddPrintDataItem( pIUserParams, Prefix, "ACCOUNT_TYPE", pLoanReceiptDetail->AccountType() );
      AddPrintDataItem( pIUserParams, Prefix, "NAMELINE1", pLoanReceiptDetail->NameLine1() );
      AddPrintDataItem( pIUserParams, Prefix, "NAMELINE2", pLoanReceiptDetail->NameLine2() );

      AddPrintDataItem( pIUserParams, Prefix, "EFFECTIVE_DATE", pLoanReceiptDetail->EffectiveDate().asString('x') );
      AddPrintDataItem( pIUserParams, Prefix, "SYSTEM_DATE", pLoanReceiptDetail->SystemDate().asString('x') );

      AddPrintDataItem( pIUserParams, Prefix, "TRANSACTION_CODE" , pLoanReceiptDetail->TransactionCode() );
      AddPrintDataItem( pIUserParams, Prefix, "COMMENTS", pLoanReceiptDetail->Comments() );

      AddPrintDataItem( pIUserParams, Prefix, "PRINCIPAL_AMOUNT", pLoanReceiptDetail->PrincipalAmt() );
      AddPrintDataItem( pIUserParams, Prefix, "INTEREST_AMOUNT" , pLoanReceiptDetail->InterestAmt() );
      AddPrintDataItem( pIUserParams, Prefix, "FEE_AMOUNT" , pLoanReceiptDetail->FeeAmt() );                                   
      AddPrintDataItem( pIUserParams, Prefix, "OTHER_PAYMENT" , pLoanReceiptDetail->OtherPayment() ); 
      AddPrintDataItem( pIUserParams, Prefix, "TRANSACTION_AMOUNT" , pLoanReceiptDetail->TransactionAmt() ); 
      AddPrintDataItem( pIUserParams, Prefix, "OUTSTANDING_PRINCIPAL" , pLoanReceiptDetail->OutstdPrincipal() ); 
      AddPrintDataItem( pIUserParams, Prefix, "OUTSTANDING_INTEREST" , pLoanReceiptDetail->OutstdInterest() );                  
      AddPrintDataItem( pIUserParams, Prefix, "OUTSTANDING_FEE" , pLoanReceiptDetail->OutstdFee() );
      AddPrintDataItem( pIUserParams, Prefix, "SERVICING_BRANCH", pLoanReceiptDetail->ServBranch() );
      AddPrintDataItem( pIUserParams, Prefix, "PRIMARY_BRANCH", pLoanReceiptDetail->PrimBranch() );
	  //Narong - Begin: Loan Payment 1 Nov 2013
      AddPrintDataItem( pIUserParams, Prefix, "CURR_RATE1", pLoanReceiptDetail->CurrRate1() );
      AddPrintDataItem( pIUserParams, Prefix, "CURR_RATE2", pLoanReceiptDetail->CurrRate2() );	  
	  AddPrintDataItem( pIUserParams, Prefix, "CURR_RATE3", pLoanReceiptDetail->CurrRate3() );
      AddPrintDataItem( pIUserParams, Prefix, "UNPAID_PRINCIPAL", pLoanReceiptDetail->UnpaidPrincipal() );	
	  AddPrintDataItem( pIUserParams, Prefix, "FILL0", pLoanReceiptDetail->Fill0() );	
	  //Narong - End
   }

   #ifdef SERVER_TRACE
   	cout << "Account Number      " << pLoanReceiptDetail->AccountNumber() << endl;
   	cout << "NameLine1           " << pLoanReceiptDetail->NameLine1() << endl;
   	cout << "NameLine2           " << pLoanReceiptDetail->NameLine2() << endl;
   	cout << "Account Type        " << pLoanReceiptDetail->AccountType() << endl;
   	cout << "Currency            " << pLoanReceiptDetail->Currency() << endl;
   	cout << "Effective Date      " << pLoanReceiptDetail->EffectiveDate().asString('x') << endl;
   	cout << "System Date         " << pLoanReceiptDetail->SystemDate().asString('x') << endl;
   	cout << "Transaction Code    " << pLoanReceiptDetail->TransactionCode() << endl;
   	cout << "Comments            " << pLoanReceiptDetail->Comments() << endl;
   	cout << "Principal Amount    " << pLoanReceiptDetail->PrincipalAmt() << endl;
   	cout << "Interest Amount     " << pLoanReceiptDetail->InterestAmt() << endl;
   	cout << "Fee Amount          " << pLoanReceiptDetail->FeeAmt() << endl;
   	cout << "Other Payment       " << pLoanReceiptDetail->OtherPayment() << endl;
   	cout << "Transaction Amount  " << pLoanReceiptDetail->TransactionAmt() << endl;
   	cout << "Outstd Principal    " << pLoanReceiptDetail->OutstdPrincipal() << endl;
   	cout << "Outstd Interest     " << pLoanReceiptDetail->OutstdInterest() << endl;
   	cout << "Outstd Fee          " << pLoanReceiptDetail->OutstdFee() << endl;
   	cout << "Servicing Branch    " << pLoanReceiptDetail->ServBranch() << endl;
   	cout << "Prim Branch         " << pLoanReceiptDetail->PrimBranch() << endl;
	
    //Narong - Begin: Loan Payment 1 Nov 2013
	  cout << "Current Rate 1     " << pLoanReceiptDetail->CurrRate1() << endl;
	  cout << "Current Rate 2     " << pLoanReceiptDetail->CurrRate2() << endl;
	  cout << "Current Rate 3     " << pLoanReceiptDetail->CurrRate3() << endl;
	  cout << "Unpaid Principal    " << pLoanReceiptDetail->UnpaidPrincipal() << endl;
	  cout << "Fill0    " << pLoanReceiptDetail->Fill0() << endl;
	//Narong - End
	  
   #endif

   return Status;
}
// End LN Oct.21,2002 TMB8.0.4 #TW-010

long AtwPLoan::Reverse (AbcIControlBlock* pIControlBlock, const RWCString& TrackingID)
{
  //## begin AtwPLoan::Reverse%394637400278.body preserve=yes
   long       ReturnCode    = BC_NO_ERRORS;
   HRESULT    hResult       = BC_NO_ERRORS;
   short      ServiceID = LOANS_MONETARIES_SERVICE;
   short      StepId        = 0;
   AbcIPServiceHostFlagsSp  pServiceHostFlagsSp;
   AbcIServiceKeySp         pServiceKeySp;
   //DDS Begin 25-Jun-2004 Memory Leaks
   //AbcIPService2Sp pService2Sp( Service2() );
   AbcIService2Sp pIService2Sp( Service2() );
   AbcIPService2Sp pService2Sp( pIService2Sp );
   //DDS End 25-Jun-2004 Memory Leaks
   AtwITransactionFlagsSp   pTranFlagsSp( TransactionFlags() );
   RWCString  Mode;

   // Get a pointer to the ControlBlockTran Object
   AbcIPControlBlockTranSp pCBTranSp(pIControlBlock);

   #ifdef SERVER_TRACE
   //   cout << endl;
      cout << "Inside the Loan::Reverse Method" << endl;
   //   cout << "Aggregated Key objcet: "             << endl;
   //   m_Key->Print();
   //   cout << endl;
   #endif

   // Begin Commit/Rollback Block
   pCBTranSp->StartTransaction();

	//Rel7.0 Applied AKC 08/24/00 & 08/30/00
	//Begin Fix 08/16/2000 People's SD7.0 Issue #806 by MSO
	Mode = pCBTranSp->FindUserParm("TWMODE");
	
	if( ( Mode != "PRODUCTION" ) && ( Mode != "ONLINE") )
	{
		AbcIServiceStepsSp pStepsSp( pService2Sp->Steps() );
		AbcIServiceStepSp  pStepSp;
		pStepSp = pStepsSp->ServiceStepList().at( StepId );
		pStepSp->Posted("N");
		pStepSp->StatusId( PENDING );
		pTranFlagsSp->Offline( "Y" );
	}
	//End Fix 08/16/2000 People's SD7.0 Issue #806 by MSO

   // Save off the Database Data 
   ReturnCode = DatabaseApply( pIControlBlock, TrackingID );

   #ifdef SERVER_TRACE
      cout << "Loan::Reverse call to Loan::DatabaseApply returned " << ReturnCode << endl;
   #endif

	//Rel7.0 Applied AKC 08/24/00
	//Begin Fix 08/16/2000 People's SD7.0 Issue #806 by MSO
	// We can comment this code out now since we are doing this 
	// up above in the newly added code.
	//if( ReturnCode == BC_NO_ERRORS )
	//   Mode = pCBTranSp->FindUserParm( "TWMODE" );
	//End Fix 08/16/2000 People's SD7.0 Issue #806 by MSO

    if( ( ReturnCode == BC_NO_ERRORS ) && ( ( pTranFlagsSp->Offline() == "N" ) || ( Mode == "PRODUCTION" ) || ( Mode == "ONLINE" ) ) )
    {
      ReturnCode = HostApply( pIControlBlock );
   
      #ifdef SERVER_TRACE
         cout << "Loan::Reverse call to Loan::HostApply returned " << ReturnCode << endl;
      #endif
    }
   // Disable Commit if necessary
   if( ReturnCode == BC_FATAL )
      pCBTranSp->DisableCommit();

   // End Commit/RollBack Block
   pCBTranSp->EndTransaction();


     // Save off the Transaction Flags from what went to the host.
   if( ReturnCode != BC_FATAL )
   {    
       // Begin A Temporary Commit/RollBack Segment
       pCBTranSp->StartTransaction();

       hResult = pServiceHostFlagsSp.CreateInstance( CLSID_AbcPServiceHostFlags, NULL, CLSCTX_INPROC_SERVER);
       if( FAILED ( hResult ) )
       {
          ReturnCode = BC_WARNING;
          SetStatus( pCBTranSp, ReturnCode );
          pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_WARNING, 
               "AtwQuickCash::HostApply Create on AbcPServieHostFlags" );
          #ifdef SERVER_TRACE
             cout << "Create on AbcPServieHostFlags Object Failed : " << endl;
             cout << hex << hResult << dec << endl;
          #endif
       }
       else
       {
          pServiceKeySp = pService2Sp->ServiceKey();
          AbcIDateTimeSp pTranDateTimeSp( pTranFlagsSp->TranDateTime() );
   
          pServiceHostFlagsSp->TransactionTime(     pTranDateTimeSp->Time()           );
          pServiceHostFlagsSp->OverrideTellerID(    pTranFlagsSp->OverrideLoginID()   );
          pServiceHostFlagsSp->TransactionSequence( pTranFlagsSp->Sequence()          );
          pServiceHostFlagsSp->PhysicalLocation(    pTranFlagsSp->Location()          );
          pServiceHostFlagsSp->StoreAndForward(     pTranFlagsSp->ForcePost()         );
          pServiceHostFlagsSp->PassbookRebid(       pTranFlagsSp->PassbookRebid()     );
          pServiceHostFlagsSp->TellerOverride(      pTranFlagsSp->TellerOverride()    );
          pServiceHostFlagsSp->SupervisorOverride(  pTranFlagsSp->SupervisorOverride());
          pServiceHostFlagsSp->Correction(          pTranFlagsSp->Reversal()          );
          pServiceHostFlagsSp->NextDay(             pTranFlagsSp->NextDay()           );
          pServiceHostFlagsSp->TrainingMode(        pTranFlagsSp->Training()          );
          pServiceHostFlagsSp->InquiryRebid(        pTranFlagsSp->InquiryRebid()      );
          pServiceHostFlagsSp->OfflineMode(         pTranFlagsSp->Offline()           );
   
          long TempReturnCode =  pServiceHostFlagsSp->Insert( pServiceKeySp, StepId, pIControlBlock );
   
          #ifdef SERVER_TRACE
              cout << "Call to ServiceHostFlags->Insert returned " << TempReturnCode << endl;
          #endif
       }
   
       // End Temporary Commit/Rollback Segment
       pCBTranSp->EndTransaction();
   }

   //Begin: Thawee 23-Sep-2009 CRT#256102 - ChequeLog  
   if ( ReturnCode != BC_FATAL )
   {
       pCBTranSp->StartTransaction();
       AtwIPChequeLogSp pChequeLogSp;
       hResult = pChequeLogSp.CreateInstance(CLSID_AtwPChequeLog, NULL, CLSCTX_INPROC_SERVER);
       if( !FAILED ( hResult ) )
       {
	    pChequeLogSp->Delete(TrackingID, pIControlBlock);
       }
       pCBTranSp->EndTransaction();
    }
   //End: Thawee 23-Sep-2009 CRT#256102 -256102 - ChequeLog  

   #ifdef SERVER_TRACE
      cout << "Leaving the AtwPLoan::Reverse Method " << endl;
   #endif

   // Return to Caller
   return ReturnCode;
  //## end AtwPLoan::Reverse%394637400278.body
}

long AtwPLoan::GetForForwarding (AbcIControlBlock* pIControlBlock, const RWCString& TrackingID)
{
  //## begin AtwPLoan::GetForForwarding%3946374602E5.body preserve=yes
   HRESULT   hResult    = BC_NO_ERRORS;
   long      ReturnCode = BC_NO_ERRORS;
   long      CSUserID   = 0;
   RWCString HostLoginID;
   
   AbcICSUserSp pCSUser;
   //DDS Begin 25-Jun-2004 Memory Leaks
   //AbcIPService2Sp pService2Sp( Service2() );
   AbcIService2Sp pIService2Sp( Service2() );
   AbcIPService2Sp pService2Sp( pIService2Sp );
   //DDS End 25-Jun-2004 Memory Leaks
   AbcIPControlBlockTranSp pCBTranSp( pIControlBlock );
   AbcIAuditInfoSp pCreationInfoSp( pService2Sp->CreationInfo() );
   
   #ifdef SERVER_TRACE
      cout << "Inside the Loan::GetForForwarding method" << endl;
   #endif
   
   hResult = pCSUser.CreateInstance( CLSID_AbcPCSUser, NULL, CLSCTX_INPROC_SERVER);
   if( FAILED( hResult ) )
   {
       ReturnCode = BC_FATAL;
       pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, "AtwPLoan::GetForForwarding Create AbcPCSUser Object" );
       SetStatus( pIControlBlock, ReturnCode );
   }

   // If all is well call Get on yourself
   if( ReturnCode == BC_NO_ERRORS )
   {
      ReturnCode = Get( pIControlBlock, TrackingID );

      #ifdef SERVER_TRACE
         cout << "Loan::GetForForwarding call to Loan::Get returned" << ReturnCode << endl;
      #endif
   
      // Set the TansactionFlags Offline indicator appropriateley
      m_TransactionFlags->Offline("N");
   }
   
   // Call Get on the AbcPCSUser object
   if( ReturnCode != BC_FATAL )
   {
      CSUserID = pCreationInfoSp->UserId();

      ReturnCode = pCSUser->Get( CSUserID, pIControlBlock );
      
      #ifdef SERVER_TRACE
         cout << "Loan::GetForForwarding call to AbcPCSUser::Get returned" << ReturnCode << endl;
      #endif
      
      if ( ReturnCode != BC_FATAL )
      {
         HostLoginID = pCSUser->LoginID();
         pIControlBlock->HostLogonId( HostLoginID );
      }  // End of if (ReturnCode != BC_FATAL )
   }  // End Call to AbcPCSUser->Get if (ReturnCode != BC_FATAL )



   #ifdef SERVER_TRACE
      cout << "Leaving Loan::GetForForwarding method" << endl;
   #endif
   
   // Return to Caller
   return ReturnCode;
  //## end AtwPLoan::GetForForwarding%3946374602E5.body
}

long AtwPLoan::Forward (AbcIControlBlock* pIControlBlock )
{
  //## begin AtwPLoan::Forward%3946375000D6.body preserve=yes
   long ReturnCode = BC_NO_ERRORS;
   
   #ifdef SERVER_TRACE
      cout << "Inside the Loan::Forward method" << endl;
   #endif

   // Set the force post bit
   m_TransactionFlags->Offline("N");
   m_TransactionFlags->ForcePost( "Y" );
   
   AtwITransactionFlagsSp pTransactionFlagsSp( TransactionFlags() );
   AtwIDebitCreditEntriesSp pDCEntriesSp( DebitCreditEntries() );
   AbcIService2Sp pIService2Sp( Service2() );

   if ( pTransactionFlagsSp->Reversal() == "Y" )
   {
      ReturnCode = FormatReversalsForForwarding( pTransactionFlagsSp, pDCEntriesSp, pIService2Sp, pIControlBlock );
   }

   if ( ReturnCode != BC_FATAL )
   {
      ReturnCode = HostApply( pIControlBlock );

      #ifdef SERVER_TRACE
         cout << "Loan::Forward call to Loan::HostApply returned " << ReturnCode << endl;
      #endif
   }

   if ( ReturnCode != BC_FATAL )
   {
      //DDS Begin 25-Jun-2004 Memory Leaks
      //AbcIPService2Sp pIPService2Sp( m_Service2 );
      AbcIPService2Sp pIPService2Sp( pIService2Sp );
      //DDS End 25-Jun-2004 Memory Leaks
      AtwITransactionFlagsSp pTranFlagsSp(  TransactionFlags() );
   
      long                   ModificationFlag = UPDATE_FLAG;

      ModifyServiceHostFlags( pIControlBlock, pTranFlagsSp, pIPService2Sp, ModificationFlag );
      
      #ifdef SERVER_TRACE
   	cout << "Loan::Forward call to ModifyServiceHostFlags returned " << ReturnCode << endl;
      #endif
   }

   #ifdef SERVER_TRACE
      cout << "Leaving the Loan::Forward method" << endl;
   #endif

   return ReturnCode;
  //## end AtwPLoan::Forward%3946375000D6.body
}

long AtwPLoan::DatabaseApply (AbcIControlBlock* pIControlBlock, const RWCString &TrackingID)
{
  //## begin AtwPLoan::DatabaseApply%395A5F130263.body preserve=yes
   HRESULT hResult    = BC_NO_ERRORS;
   long    ReturnCode = BC_NO_ERRORS;      
   short   ServiceID = LOANS_MONETARIES_SERVICE;
   char    tempUserID[10];
   short   StepId     = 0;
   RWCString newTrackingID;

   // Declare necessary objects
   AtwISubRegionDefaultSp        pSubRegionDefaultSp;
   AbcIServiceRelationshipSp     pServiceRelationshipSp;
   AtwIPCustomerIdentificationSp pCustIdSp;   
   
   // Get Smart Pointers to necessary objects
   AbcIPControlBlockTranSp       pCBTranSp(   pIControlBlock        );
   AbcIService2Sp                pService2Sp( Service2()           );
   AbcIServiceRelationshipsSp    pServiceRelationshipsSp( pService2Sp->Relationships() );
   AbcIServiceStepsSp            pStepsSp( pService2Sp->Steps() );
   AbcIServiceStepSp             pStepSp( pStepsSp->ServiceStepList().at( StepId ));
   AtwICustomerIdentificationsSp pCustIdsSp( CustomerIdentifications() );
   
   // Get raw pointers to some aggregated objects
   AtwIKey*                 pIKey(        Key()                 );
   AtwIDebitCreditEntries*  pDCList(     DebitCreditEntries()  );
   AtwITransactionFlags*    pTranFlags(  TransactionFlags()    );
    
   #ifdef SERVER_TRACE
	  cout << "ServiceRelationship Count = " << pServiceRelationshipsSp->ServiceRelationshipList().entries() << endl;
      //AbcIServiceRelationshipSp pSR( pServiceRelationshipsSp->ServiceRelationshipList().at(0) );
	  //AbcIServiceKeySp pServiceKey( pSR->RelatedServiceKey() );
	  //cout << "Trackingid = " << pServiceKey->ServiceId() << endl; 
      //AbcIServiceRelationshipSp pSR1( pServiceRelationshipsSp->ServiceRelationshipList().at(2) );
	  //AbcIServiceKeySp pServiceKey1( pSR1->RelatedServiceKey() );
	  //cout << "Trackingid = " << pServiceKey1->ServiceId() << endl; 
      cout << endl;
      cout << "Inside Loan::DatabaseApply" << endl;
      cout << "Aggregated Key object: " << endl;
      m_Key->Print();
      cout << endl;
   #endif
   
   // Create the necessary objects
   hResult = pSubRegionDefaultSp.CreateInstance(CLSID_AtwPSubRegionDefault,NULL,CLSCTX_INPROC_SERVER);
   if( FAILED ( hResult ) )
   {
      #ifdef SERVER_TRACE
         cout << "pSubRegionDefaultSp.CreateInstance failed" << endl;
      #endif
    
      ReturnCode = BC_FATAL;
      pCBTranSp->AddMessage(TW_COMPONENT,MSG_BC_INTERFACE_CREATE_FAILED,
             BC_FATAL,"AtwLoan::DatabaseApply  Create AtwPSubRegionDefault Object");
      SetStatus( pIControlBlock, ReturnCode );
   }
   
   // Begin Commit/Rollback Block
   pCBTranSp->StartTransaction();

   // If all is well go on and do the work
   if( ReturnCode == BC_NO_ERRORS)
   {
      #ifdef SERVER_TRACE
         cout << "pSubRegionDefaultSp.CreateInstance succeeded" << endl;
      #endif
      
      // Make sure the CSUserID/UserID is set in the ControlBlock
      sprintf( tempUserID, "%ld", m_Key->CSUserID() );
      AddUserParam( pCBTranSp, "CSUserID",  tempUserID );
      AddUserParam( pCBTranSp, "UserID",    tempUserID );
       
      // If we are offline make sure database knows it
      if( pTranFlags->Offline() == "Y" )
         pStepSp->Offline( "Y" );
      else
         pStepSp->Offline( "N" );


      // Check to see if we are doing an override
      if ( m_TransactionFlags->SupervisorOverride() == "Y" )
      {
         pStepSp->OverrideTypeId( "S" );
         pStepSp->OverrideUserId( atol(pTranFlags->OverrideID()) );
         AddUserParam( pCBTranSp, "OVERRIDEMODE", "SUPERVISOROVERRIDE" );
      }
      else if ( m_TransactionFlags->AmountLimitOverride() == "Y" )
      {
         pStepSp->OverrideTypeId( "A" );
         pStepSp->OverrideUserId( atol(pTranFlags->OverrideID()) );
         AddUserParam( pCBTranSp, "OVERRIDEMODE", "AMOUNTLIMITOVERRIDE" );
      }
      else if( pTranFlags->TellerOverride() == "Y" )
      {
         pStepSp->OverrideTypeId( "T" );
         pStepSp->OverrideUserId( atol(pTranFlags->OverrideID()) );
         AddUserParam( pCBTranSp, "OVERRIDEMODE", "TELLEROVERRIDE" );
      }
      else 
         AddUserParam( pCBTranSp, "OVERRIDEMODE", "" );
      
      // Read the SubRegionDefault table for Negotiable IDs
      pSubRegionDefaultSp->SubRegionID( m_Key->SubRegionID() );
      ReturnCode = pSubRegionDefaultSp->Get( pIControlBlock );
      #ifdef SERVER_TRACE
          cout << "pSubRegionDefaultSp->Get returned " << ReturnCode << endl;
      #endif
      if( ReturnCode == BC_NO_ERRORS )
      {
         CashInNegotiableID ( pSubRegionDefaultSp->CashInNegotiableID()  );
         CashOutNegotiableID( pSubRegionDefaultSp->CashOutNegotiableID() );
      }
      else
      {
         pCBTranSp->AddMessage(TW_COMPONENT,MSG_BC_INTERFACE_CREATE_FAILED,
             BC_FATAL,"AtwLoan::DatabaseApply  Get AtwPSubRegionDefault Failed");
         SetStatus( pIControlBlock, ReturnCode );
      } // End of else for if( ReturnCode == BC_NO_ERRORS )


      if( ReturnCode == BC_NO_ERRORS )
      {
         // See if this is a Reversal or not
         if( pTranFlags->Reversal() == "Y" )
         {
            #ifdef SERVER_TRACE
               cout << "This is a reversal" << endl;
            #endif
            
            AbcIServiceKey* pServiceKey2( pService2Sp->ServiceKey() );
            pServiceKey2->ServiceId( "-1" );
            
            // Create a AbcServiceRelationship Object
            hResult = pServiceRelationshipSp.CreateInstance( CLSID_AbcPServiceRelationship, NULL, CLSCTX_INPROC_SERVER );
            if( FAILED ( hResult ) )
            {
               ReturnCode = BC_FATAL;
               SetStatus( pIControlBlock, ReturnCode );
               pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, 
                  BC_FATAL, "AtwLoan::DatabaseApply Create on AbcServiceRelationship Object Failed" );
               #ifdef SERVER_TRACE
                     cout << "AtwLoan::DatabaseApply Create on AbcServiceRelationship Object Failed";
               #endif
            }
            else
            {
               AbcIServiceKey* pServiceKey( pServiceRelationshipSp->RelatedServiceKey() );
               pServiceRelationshipSp->Owner(   "Y"                   );
               pServiceRelationshipSp->TypeId(  REVERSAL_RELATIONSHIP );
               pServiceKey->ServiceId(          TrackingID            );
               pServiceKey->ServiceTableId(     ServiceID             );
               
               pServiceRelationshipsSp->ServiceRelationshipList().append( pServiceRelationshipSp );

               #ifdef SERVER_TRACE
                  cout << "ServiceRelationship" << endl;
                  cout << "Owner                         : " << pServiceRelationshipSp->Owner()  << endl;
                  cout << "TypeId                        : " << pServiceRelationshipSp->TypeId() << endl;
                  cout << "RelatedServiceKey->TrackingID : " << pServiceKey->ServiceId()        << endl;
                  cout << "RelatedServiceKey->SeviceID   : " << pServiceKey->ServiceTableId()   << endl;
               #endif
               
               pServiceKey->Release();
            }  // End of else on if(FAILED(hResult))
         }  // End of if( pTranFlags->Reversal == "Y" )
         
         AbcIServiceKeySp pTempServiceKey( pService2Sp->ServiceKey() );
	     pTempServiceKey->ServiceId( "-1" );

         // Create ServiceDelivery Tracking Records
         if( ReturnCode == BC_NO_ERRORS )
         {
            m_DebitCreditService->Key( Key() );
            ReturnCode = m_DebitCreditService->Apply( pIControlBlock, pDCList, pService2Sp );
            #ifdef SERVER_TRACE
               cout << "m_DebitCreditService->Apply returned " << ReturnCode << endl;
            #endif
         }
         
         if( ReturnCode != BC_FATAL )
         {
            newTrackingID = m_DebitCreditService->TrackingID();
			#ifdef SERVER_TRACE
				cout << "newTrackingID = " << newTrackingID << endl;
			#endif

            ReturnCode = m_TellerMonetary->GetDefaults( pIControlBlock, pIKey, newTrackingID );

            #ifdef SERVER_TRACE
               cout << "Call to TellerMonetary->Getdefaults returned " << ReturnCode << endl;
            #endif

            // Update the Total Buckets 
            if( ReturnCode == BC_NO_ERRORS )
               ReturnCode = m_TellerMonetary->Save( pIControlBlock, pDCList, pTranFlags );
         }  // End of if( ReturnCode == BC_NO_ERRORS )

			#ifdef SERVER_TRACE
				cout << "ReturnCode after m_TellerMonetary->Save() = " << ReturnCode << endl;
			#endif

			 // If all is still well save off any Customer Identifications
			 if( ReturnCode != BC_FATAL )
			 {
				 long CustIDCount = pCustIdsSp->CustomerIdentificationList().entries();

				 for ( int i=0; i < CustIDCount; i++ )
				 {
					 pCustIdSp = pCustIdsSp->CustomerIdentificationList().at( i );
					 
					 pCustIdSp->TrackingID( newTrackingID );
					 pCustIdSp->SortOrder(i);

					 ReturnCode = pCustIdSp->Add( pIControlBlock );

					 if( ReturnCode == BC_FATAL)
						break;
				 }
			 }
      }  // End of if( ReturnCode == BC_NO_ERRORS )
   }  // End of if( ReturnCode == BC_NO_ERRORS


   // Disable Commit if necessary
   if( ReturnCode == BC_FATAL )
      pCBTranSp->DisableCommit();

   // End Commit/Rollback Block
   pCBTranSp->EndTransaction();

   // Release any necessary objects
   pDCList->Release();
   pIKey->Release();
   pTranFlags->Release();

   // Exit out of the function

   #ifdef SERVER_TRACE
	cout << "ReturnCode at end of DatabaseApply = " << ReturnCode << endl;
   #endif

   return ReturnCode;
  //## end AtwPLoan::DatabaseApply%395A5F130263.body
}

long AtwPLoan::HostApply (AbcIControlBlock* pIControlBlock)
{
  //## begin AtwPLoan::HostApply%395A5F9F00A1.body preserve=yes
   long        LargeCurrencyTransaction = 0;
   long        ItemCount  = 0;
   long        ReturnCode = BC_NO_ERRORS;
   HRESULT     hResult    = BC_NO_ERRORS;
   RWCString   Mode;
   RWCString   TempCashIn;
   RWCString   AppTranCode;
   RWCString   TempCashOut;
 
   //Begin LN Oct,21,2002 TMB8.0.4 #TW-010
   RWCString   TrackingID;
   //End LN Oct,21,2002 TMB8.0.4 #TW-010

   long        TempCashInNegID;
   long        TempCashOutNegID;

   #ifdef SERVER_TRACE
      cout << "Inside AtwPLoan::HostApply" << endl;
   #endif
   
   // Declare any objects needed
   AtwIDMultiBalanceAdjustmentSp pMultiBalAdjstSp;
   AtwIDebitCreditEntrySp        pDCEntrySp;
   AbcIPControlBlockTranSp       pCBTranSp( pIControlBlock );
   AtwITransactionFlagsSp        pTranFlags( TransactionFlags() );
   AtwISubRegionDefaultSp        pSubRegionDefaultSp;
   
   // Get Smart pointers to aggregated objects
   //DDS Begin 25-Jun-2004 Memory Leaks
   //AbcIPService2Sp pService2Sp ( Service2() );
   AbcIService2Sp pIService2Sp ( Service2() );
   AbcIPService2Sp pService2Sp ( pIService2Sp  );
   //DDS End 25-Jun-2004 Memory Leaks

   // Get a RAW pointer to some aggregated objects
   AtwIDebitCreditEntries* pDCList( DebitCreditEntries() );

   // Begin Commit/RollBack Block
   pCBTranSp->StartTransaction();

   // Create a SubRegionDefault Object
   hResult = pSubRegionDefaultSp.CreateInstance(CLSID_AtwPSubRegionDefault, NULL, CLSCTX_INPROC_SERVER);
   if( FAILED( hResult ) )
   {
      ReturnCode = BC_FATAL;
      pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED,
                             BC_FATAL, "AtwLoan::HostApply Create on AtwPSubRegionDefault Failed" );
      SetStatus( pIControlBlock, ReturnCode );
   }

   // See if we are on-line/(Production) or offline/(Demo Mode) 
   if( ReturnCode == BC_NO_ERRORS )
      Mode = pCBTranSp->FindUserParm( "TWMODE" );
   
   #ifdef SERVER_TRACE
      cout << "Mode found on the ControlBlock was             : " << Mode <<  endl;
      cout << "Offline on the TransactionFlags Object  was : " << pTranFlags->Offline() <<  endl;
   #endif
   
   if( (ReturnCode == BC_NO_ERRORS) && ( ( Mode == "PRODUCTION" ) || ( Mode == "ONLINE" ) || ( pTranFlags->Offline() == "N") ) )
   {
      hResult = pMultiBalAdjstSp.CreateInstance( CLSID_AtwDMultiBalanceAdjustment, NULL, CLSCTX_INPROC_SERVER);
      if( FAILED ( hResult ) )
      {
         ReturnCode = BC_FATAL;
         SetStatus( pCBTranSp, ReturnCode );
         pCBTranSp->AddMessage( TW_COMPONENT, MSG_BC_INTERFACE_CREATE_FAILED, BC_FATAL, 
              "AtwLoan::HostApply Create on AtwDMultiBalanceAdjustment" );
         #ifdef SERVER_TRACE
            cout << "Create on AtDMultiBalanceAdjustment Object Failed : " << endl;
            cout << hex << hResult << dec << endl;
         #endif
      }

      // If all is well then Read the table
      if( ReturnCode == BC_NO_ERRORS )
      {
		#ifdef SERVER_TRACE
			cout << "Ready to read the table ..." << endl;
		#endif

         pSubRegionDefaultSp->SubRegionID( m_Key->SubRegionID() );

         ReturnCode = pSubRegionDefaultSp->Get( pIControlBlock );
         if( ReturnCode == BC_NO_ERRORS )
         {
            TempCashInNegID  = pSubRegionDefaultSp->CashInNegotiableID()  ;
            TempCashOutNegID = pSubRegionDefaultSp->CashOutNegotiableID() ;

            long ItemCount = pDCList->DebitCreditEntryList().entries();
            for( int index =0; index < ItemCount; index++ )
            {
               pDCEntrySp = pDCList->DebitCreditEntryList().at( index );

               AbcICurrency *pCurrency( pDCEntrySp->Amount() );
               pCurrency->Release();

               if( pDCEntrySp->NegotiableID()      == TempCashInNegID )
                 TempCashIn  = pCurrency->Amount();
               else if( pDCEntrySp->NegotiableID() == TempCashOutNegID )
                 TempCashOut = pCurrency->Amount();
            }

	    AppTranCode = "TWLOAN";
	    // Determine if the is an Account Closing or Not.
            for( int TempIndex =0; TempIndex < ItemCount; TempIndex++ )
            {
               pDCEntrySp = pDCList->DebitCreditEntryList().at( TempIndex );

               if( (pDCEntrySp->NegotiableID() == CHECKING_CLOSEOUT                 ) ||
                   (pDCEntrySp->NegotiableID() == STATEMENT_SAVINGS_CLOSEOUT        ) ||
                   (pDCEntrySp->NegotiableID() == CD_CLOSEOUT                       ) ||
                   (pDCEntrySp->NegotiableID() == IRA_CLOSEOUT                      ) ||
		   (pDCEntrySp->NegotiableID() == DEBIT_IM_CLOSE_WITHOUT_TRAN_CODE  ) ) 
		   AppTranCode = "TWCD";
               else if( ( pDCEntrySp->NegotiableID() == CREDIT_CHECKING_CLOSEOUT ) ||
		        ( pDCEntrySp->NegotiableID()  == CREDIT_IM_CLOSE_WITHOUT_TRAN_CODE ) )
		   AppTranCode = "TWCC";
            }

         }
         else
         {
            ReturnCode = BC_FATAL;
            SetStatus( pIControlBlock, ReturnCode );
         }  // End of else
      }  // End of if(ReturnCode == BC_NO_ERRORS)

	
      // If all is well continue

      if( ReturnCode == BC_NO_ERRORS )
      {
         pTranFlags->Sequence( pService2Sp->TransactionID() );

         // See if it was a large currency transaction
         float CashIn  = atof( (char *) TempCashIn.data()  );
         float CashOut = atof( (char *) TempCashOut.data() );

			//Begin DDS 02-Jul-2003 Disable LargeCurrencyTransaction
         //if( (CashIn > LARGE_CURRENCY_LIMIT) || ( CashOut > LARGE_CURRENCY_LIMIT) )
         //   LargeCurrencyTransaction = TRUE;
         //End DDS 02-Jul-2003 Disable LargeCurrencyTransaction

         pMultiBalAdjstSp->DrawerNumber( m_Key->DrawerID() );

         if( LargeCurrencyTransaction )
         {
            long TempCount = m_CustomerIdentifications->CustomerIdentificationList().entries();

            if( TempCount > 0 )
            {
               for(int i=0; i < TempCount; i++)
               {
                  AtwICustomerIdentificationSp  pCustIDSp;
                  pCustIDSp = m_CustomerIdentifications->CustomerIdentificationList().at(i);

                  if(pCustIDSp->CustomerTypeID() == GUARANTOR_TYPE)
                     pMultiBalAdjstSp->GuarantorTIN(pCustIDSp->CustomerNumber());
               }  // End of for (...) loop
            }  // End of if( TempCount > 0 )
            
            pMultiBalAdjstSp->CheckExemptList("Y");
            pMultiBalAdjstSp->CtrInstitution("");

            // This is just for testing the host for now
            pMultiBalAdjstSp->CtrInstitution("0205");

         }  // End of if( LargeCustomerTransaction )
         else
         {
            pMultiBalAdjstSp->CheckExemptList("N" );
            pMultiBalAdjstSp->GuarantorTIN(   ""  );
            pMultiBalAdjstSp->CtrInstitution( ""  );
         }

		#ifdef SERVER_TRACE
			cout << "Calling pMultiBalAdjstSp->Apply()..." << endl;
			cout << "CheckExempList = " << pMultiBalAdjstSp->CheckExemptList() << endl;
		#endif
        
	 //Begin LN Oct,21,2002 TMB8.0.4 #TW-010 
	 TrackingID = m_DebitCreditService->TrackingID();

         ReturnCode = pMultiBalAdjstSp->Apply(pIControlBlock, m_TransactionFlags, AppTranCode, m_DebitCreditEntries, CashInNegotiableID(), CashOutNegotiableID(), TrackingID);
	 //End LN Oct,21,2002 TMB8.0.4 #TW-010

		#ifdef SERVER_TRACE
			cout << "pMultiBalAdjstSp->Apply() returned " << ReturnCode << endl;
		#endif

      }  // End of if( ReturnCode == BC_NO_ERRORS )
      
      if( ReturnCode != BC_FATAL)
      {
       if(pMultiBalAdjstSp->CustomerIsExempt() ==  "Y" )
          GuarantorOnExemptList( "Y" );
       else
          GuarantorOnExemptList( "N" );
      }
   }  // End of if (Mode ... )

   // Release any objects necessary
   pDCList->Release();

   // Disable Commit if necessary
   if( ReturnCode == BC_FATAL )
      pCBTranSp->DisableCommit();

   // End Commit/RollBack Block
   pCBTranSp->EndTransaction();

   #ifdef SERVER_TRACE
      cout << "Leaving the AtwPLoan::HostApply Method with a ReturnCode of " << ReturnCode << endl;
   #endif
   // Return to caller
   return ReturnCode;
  //## end AtwPLoan::HostApply%395A5F9F00A1.body
}

// Additional Declarations
  //## begin AtwPLoan%394631400048.declarations preserve=yes
  //## end AtwPLoan%394631400048.declarations

//## begin module%39463187022B.epilog preserve=yes
//## end module%39463187022B.epilog
