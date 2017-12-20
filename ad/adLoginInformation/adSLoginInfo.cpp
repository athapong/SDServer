
/************************************************
   Tuxedo Service File : U:\ad\adLoginInformation\adSLoginInfo.cpp
   Generated - Fri Jul 02 14:37:48 1999
   AisIdl2 Version 2.2.9
************************************************/


#include "rw/compiler.h"
#include "rw/cstring.h"

#include <stdio.h>
#include "atmi.h"      // Tuxedo
#include "userlog.h"   // Tuxedo
#include "bcMwErr.h"   // Error Information
#include "bcMwMrsh.h"  // MiddleWare Support

#include "bcObjBase.h" // MiddleWare Support

// Header files for IDL defined interface objects
#include "adILoginInformation.h"

//CLSIDs for created objects
EXTERN_C const GUID CLSID_AadPLoginInformation;
EXTERN_C const GUID CLSID_AbcPControlBlock;
EXTERN_C const GUID CLSID_AbcPMessage;
EXTERN_C const GUID CLSID_AbcPMessages;
EXTERN_C const GUID CLSID_AbcPMwUserParm;


/**************************************************
**  Generated Tuxedo Service - adSLoginInfo
**************************************************/
extern RWCString g_ComTraceSource;
extern "C" void adSLoginInfo(TPSVCINFO *rqst)
{
   void *pData;                   // Pointer to data segment
   char *obuff;                   // Output/Return buffer
   long olen = 0;                 // Output/Return buffer length
   long userRetCode = 0;          // User defined return code
   long err = 0;    // Marshalling Error
   long TranSignature = 0;        // Transaction signature used by this generator
   HRESULT hresult;

   // Initialize the input and output pointers
   pData = rqst->data;
   obuff = NULL;

   // Declare a MiddleWare object
   AbcMwMarshal *middleWare;
   middleWare = new AbcMwMarshal((char *) pData);

   // Get the transaction signature off of the wire
   middleWare->FromWire(TranSignature);


   // Check the buffer for the correct transaction signature
   if(TranSignature != 732)
   {
      userRetCode = MW_SIG_INVALID;
      delete middleWare;
      obuff = NULL;
      olen = 0;
      BC_DUMP_COM_TRACE_TABLE;
      tpreturn(TPSUCCESS, userRetCode, obuff, olen, 0L);
   }

   {   // scope block so that RWCString ImplMethod will call destructor before tpreturn
      GUID TranGuid;          // Guid identifying this transaction
      RWCString ImplMethod = "";        // Implementation method to call

      // Get the transaction guid off of the wire
      if (!err) middleWare->FromWire(TranGuid);

      // Get the implementation method we will call off of the wire
      if (!err) middleWare->FromWire(ImplMethod);
      g_ComTraceSource = RWCString("adSLoginInfo") + RWCString(":") + ImplMethod;

      // Set the return code to GUID mismatch
      if (!err)
        userRetCode = MW_TRANGUID_INVALID;
      else
        userRetCode = err;

      // Implementation of  Interface: AadILoginInformation
      if (TranGuid == IID_IAadILoginInformation)
      {

         userRetCode = MW_METHOD_INVALID;

         // Check the Implementation method to verify we support it
         if(ImplMethod == "Retrieve")
         {

            // Declare all necessary variables and objects
            // to be used as parameters to methods

            // Create an interface and implementation object
            AadILoginInformation *IntObject;
            hresult = AbcCoCreateInstance(CLSID_AadPLoginInformation,NULL,CLSCTX_INPROC_SERVER,IID_IAadILoginInformation,(LPVOID*) &IntObject);
            err = hresult;
            if(FAILED(hresult))
            {
               RWCString sCLSID;
               RWCString sIID;
               AbcStringFromCLSID(CLSID_AadPLoginInformation,sCLSID);
               AbcStringFromCLSID(IID_IAadILoginInformation,sIID);
               userlog("Error Creating Object {%s}, CLSID={%s}, Interface {%s}, IID={%s}, HRESULT=%ld","AadPLoginInformation",sCLSID,"AadILoginInformation", sIID, hresult);
               IntObject = NULL;
            }
            if (!err) err = middleWare->FromWire(IntObject);

            //  Define Variables for parameters

            AbcIControlBlock* pIControlBlock = NULL;

            if (!err) { 
               hresult = AbcCoCreateInstance(CLSID_AbcPControlBlock,NULL,CLSCTX_INPROC_SERVER,IID_IAbcIControlBlock,(LPVOID*) &pIControlBlock);
               err = hresult;
               if (FAILED(hresult))
               {
                  RWCString sCLSID;
                  RWCString sIID;
                  AbcStringFromCLSID(CLSID_AbcPControlBlock,sCLSID);
                  AbcStringFromCLSID(IID_IAbcIControlBlock,sIID);
                  userlog("Error Creating Object {%s}, CLSID={%s}, Interface {%s}, IID={%s}, HRESULT=%ld","AbcPControlBlock",sCLSID,"AbcIControlBlock", sIID, hresult);
                  pIControlBlock = NULL;
               }
            }

            // Move the IN and IN/OUT parameters from the wire to their place holders
            if(!err) err = middleWare->FromWire(pIControlBlock);

            // Make the call to the implementation object
            long methodRetValue;
            if(!err)
               methodRetValue = IntObject->Retrieve(pIControlBlock);

            // Calculate the size needed for the the return buffer
            if(!err)
            {
               olen = 0;
               olen += middleWare->WireSize(TranSignature);
               olen += sizeof(TranGuid);
               olen += middleWare->WireSize(ImplMethod);
               olen += middleWare->WireSize(IntObject);
               //  Size of Return Type
               olen += middleWare->WireSize(methodRetValue);

               //  Size of the OUT and IN/OUT parameters
               olen += middleWare->WireSize(pIControlBlock);
            }

            if(!err)
            {
               // Allocate and assign a return buffer
               obuff = tpalloc("CARRAY",NULL,olen);
               middleWare->SetOutputBuffer( (char *) obuff);

               // Move the transaction signature on to the wire
               middleWare->ToWire(TranSignature);

               // Move the transaction guid on to the wire
               middleWare->ToWire(TranGuid);

               // Move the implementation method we called on to the wire 
               middleWare->ToWire(ImplMethod);

               // Move the data from the interface object to the wire
               middleWare->ToWire(IntObject);

               //  Move the implementation return data on to the wire 
               middleWare->ToWire(methodRetValue);

               //  Move the OUT and IN/OUT parameters on to the wire
               middleWare->ToWire(pIControlBlock);
            }

            // Delete the newly create objects
            if (IntObject != NULL) IntObject->Release();

            if (pIControlBlock != NULL) pIControlBlock->Release();

            
            userRetCode = err;

         }// End of if(ImplMethod ==....)


      }  // End of if( (TranGuid == ...) )



      delete middleWare;
   }  // end scope for RWCString ImplMethod 
   BC_DUMP_COM_TRACE_TABLE;
   tpreturn(TPSUCCESS, userRetCode, obuff, olen, 0L);

}  // End of tux service 

