
//////////////////////////////////////////////////////////////////////////////////////////////
// message object test main()
//////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#include "bcObjBase.h"
#include "bcErrors.h"

#include <bcInitGuid.h>
#include "bcMwServicesGuid.h"
#include "bcCommonGuid.h"
#include "iqAccountOwnersGuid.h"
#include "bcServicingGuid.h"


void DumpMessages(AbcIControlBlock* pCB)
{
    AbcIMessagesSp pIMessages(pCB->Messages());

    int Entries = pIMessages->MessageList().entries();
    cout << "Message Entries = " << Entries << endl; 
    cout << "Message Max Severity = " << pIMessages->MaxSeverity() << endl;

    for (int i=0; i<Entries; i++)
    {
        AbcIMessage* pIMessage = pIMessages->MessageList().at(i);
        cout << "Message = " << pIMessage->MessageNumber() << ", "
        << pIMessage->Description() << ", "
        << pIMessage->Severity() << endl;
        pIMessage->Release();
    }
}


void TestAccoutOwner( AbcIControlBlockSp pIControlBlock )
{
   long ReturnCode = BC_NO_ERRORS;
   HRESULT hresult;
   AiqIAccountOwnersSp pIAccountOwners;

   hresult = pIAccountOwners.CreateInstance( CLSID_AiqPAccountOwners, NULL,CLSCTX_INPROC_SERVER );
   if ( FAILED( hresult ) )
   {
      cout << "Could not create CLSID_AiqPAccountOwners for AiqIAccountOwnersSp" << endl;
      return;
   }

   AbcIAccountKeySp pIAccountKey;
   hresult = pIAccountKey.CreateInstance( CLSID_AbcPAccountKey,NULL,CLSCTX_INPROC_SERVER );
   if ( FAILED( hresult ) )
   {
      cout << "Could not create CLSID_AbcPAccountKey" << endl;
      return;
   }

   #if 0
   pIAccountKey->ApplicationId( "ST" );
   pIAccountKey->Control1( "0010" );
   pIAccountKey->Control2( "0000" );
   pIAccountKey->Control3( "0000" );
   pIAccountKey->Control4( "0000" );
   pIAccountKey->AccountNumber( "00000038782315" );
   #endif

   #if 0
   pIAccountKey->ApplicationId( "RF" );
   pIAccountKey->Control1( "0010" );
   pIAccountKey->Control2( "0000" );
   pIAccountKey->Control3( "0000" );
   pIAccountKey->Control4( "0000" );
   pIAccountKey->AccountNumber( "0000000000003878226" );
   #endif
   
   #if 0
   pIAccountKey->ApplicationId( "IM" );
   pIAccountKey->Control1( "0010" );
   pIAccountKey->Control2( "0000" );
   pIAccountKey->Control3( "0000" );
   pIAccountKey->Control4( "0000" );
   pIAccountKey->AccountNumber( "0000000000000000038782144" );
   #endif

   #if 1
   pIAccountKey->ApplicationId( "AC" );
   pIAccountKey->Control1( "0010" );
   pIAccountKey->Control2( "0000" );
   pIAccountKey->Control3( "0000" );
   pIAccountKey->Control4( "0000" );
   pIAccountKey->AccountNumber( "00000432001000" );
   #endif


   ReturnCode = pIAccountOwners->Get( pIAccountKey, pIControlBlock );
   AiqIAccountOwnerList &OwnerList = pIAccountOwners->AccountOwnerList();

   size_t Entries = OwnerList.entries();
   for ( size_t i = 0; i < Entries; ++i )
   {
       AiqIAccountOwner* pIAccountOwner = OwnerList.at( i );
       AbcIAccountKeySp pICustKey = pIAccountOwner->CustomerKey();
       cout << "Account Owner #" << i << endl;
       cout << "AppID:      " << pICustKey->ApplicationId() << endl;
       cout << "Control 1 : " << pICustKey->Control1() << endl;
       cout << "Control 2 : " << pICustKey->Control2() << endl;
       cout << "Control 3 : " << pICustKey->Control3() << endl;
       cout << "Control 4 : " << pICustKey->Control4() << endl;
       cout << "CustomerNumber: " << pICustKey->AccountNumber() << endl;
       cout << "Ownership : " << pIAccountOwner->Ownership() << endl; 
       cout << "NameLine1 : " << pIAccountOwner->NameLine1() << endl;
       pIAccountOwner->Release();
   }

   //if ( ReturnCode != BC_FATAL ) 
   {
        cout << "In TestAccountOwner ReturnCode from Get=" << ReturnCode << endl;
   }
}

 
int main()                                                          
{
    int ReturnValue = 0;
   {
   
    HRESULT hresult;
    //AbcClassFactoryMgr::Dump();

    AbcIPControlBlockAdminSp pIControlBlockAdmin;
    AbcIControlBlockSp pIControlBlock;

    hresult = AbcCoCreateInstance(CLSID_AbcPControlBlock, NULL, 0, IID_IAbcIPControlBlockAdmin, (LPVOID*) &pIControlBlockAdmin);    

    if (pIControlBlockAdmin->ConnectToDatabase("bc.ini") == FALSE)
    {
       cout << "Could not Open Database" << endl;
       return ReturnValue;
    }
    else
    {
       cout << "Connected to database" << endl;
    }
    
    pIControlBlockAdmin->HostLogonId("38782");
    
    AbcIMwUserParm* pIUserParm;
    hresult = AbcCoCreateInstance(CLSID_AbcPMwUserParm, NULL, 0, IID_IAbcIMwUserParm, (LPVOID*) &pIUserParm);
    pIUserParm->Name("UserID");
    pIUserParm->Value("121");

    pIControlBlockAdmin->Extensions().append(pIUserParm);
    pIUserParm->Release();
    
    hresult = AbcCoCreateInstance(CLSID_AbcPMwUserParm, NULL, 0, IID_IAbcIMwUserParm, (LPVOID*) &pIUserParm);
    pIUserParm->Name("ProcessingCenterId");
    pIUserParm->Value("1");

    pIControlBlockAdmin->Extensions().append(pIUserParm);
    pIUserParm->Release() ;

    hresult = AbcCoCreateInstance(CLSID_AbcPMwUserParm, NULL, 0, IID_IAbcIMwUserParm, (LPVOID*) &pIUserParm);
    pIUserParm->Name("DeliveryChannelId");
    pIUserParm->Value("1");

    pIControlBlockAdmin->Extensions().append(pIUserParm);
    pIUserParm->Release();
    
    pIControlBlock = pIControlBlockAdmin;

    TestAccoutOwner( pIControlBlock );
    DumpMessages( pIControlBlock );

    pIControlBlockAdmin->Extensions().clear();
    pIControlBlockAdmin->Release();

    cout <<"After pIControlBlockAdmin->Release()" << endl;
    
   }

    BCDUMPCOMTRACETABLE
    cout << "before main return " << endl;
    return ReturnValue;
}

