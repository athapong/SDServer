//=========================================================================
// trCustomerTest
//
//=========================================================================

#include <stdio.h>

//
// Standard support                     
//
#include "bcObjBase.h"
#include "bcIControlBlock.h"
#include "adILoginInformation.h"       // object to be tested

#include "bcInitGuid.h"

//
// Consumed interfaces
//
#include "bcCommonGuid.h"      // 
//
// Consumed Guid definitions
//

#include "bcMwServicesGuid.h" // Connection to resource
#include "adLoginInformationGuid.h"
#include "bcErrors.h"

int main(int, char**)
{
   HRESULT hresult;
   AbcIControlBlock* pIControlBlock;

   //normally Should connect to database using ControlBlockAdmin, then QI for pIControlBlock
   //but it won't work if the bc.ini file is encrypted

   //Test by changing the ini file.  But if try to add a message it core dumps. oops.  
   //If run from the VB test app then it works only it doesn't read the database for message error desciptions
   
   hresult = AbcCoCreateInstance(CLSID_AbcPControlBlock,
                                 NULL,CLSCTX_INPROC_SERVER,
                                 IID_IAbcIControlBlock, 
                                 (LPVOID*) &pIControlBlock);

   if (FAILED(hresult))
   {
      cout << "main: QI failed for IID_IAbcIControlBlock)" << hex << endl;
      return hresult;
   }
   
   AadILoginInformation *pILoginInformation;
   hresult = AbcCoCreateInstance(CLSID_AadPLoginInformation,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_IAadILoginInformation, 
                                  (void**) &pILoginInformation);
   if ( SUCCEEDED( hresult) )
   {
   
       
      long Result = pILoginInformation->Retrieve(pIControlBlock);

       cout << "pILoginInformation->Retrieve() returns " << Result << endl;
       
       if ( Result == BC_NO_ERRORS )
       {
            cout << "Login        " << "*" << pILoginInformation->Login() << "*" << endl;
            cout << "Password     " << "*" << pILoginInformation->Password() << "*" << endl;
       }
       else
       {
           cout << "There are errors:  unable to read from the database." << endl;
       }
           
       
       pILoginInformation->Release();
       pILoginInformation = NULL;
   }
   else
   {
       cout <<"CocreateInstance failed" << endl;
   }

   pIControlBlock->Release();
   
   //
   // DEBUG - Dump table of objects with outstanding references
   //
   BC_DUMP_COM_TRACE_TABLE

   return 0;
}

