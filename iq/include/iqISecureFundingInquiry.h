
#ifndef __IQISECUREFUNDINGINQUIRY_H__
#define __IQISECUREFUNDINGINQUIRY_H__


/************************************************
   RogueWave C++ Header
   Interface Header File : U:\iq\include\iqISecureFundingInquiry.h
   Generated - Thu Jan 09 14:18:06 2003
   AisIdl2 Version 2.3.0
************************************************/

#include <rw/compiler.h>
#include <rw/cstring.h>
#include <rw/gdlist.h>
#include "bcObjBase.h"
#include "bcMwErr.h"
#include "bcMwMrsh.h"

// Include files caused by IDL dependencies
#include "bcIControlBlock.h"
#include "bcICurrency.h"
#include "bcIAccountKey.h"
#include "iqISecureFundingAccount.h"



//////////////////////////////////////////////////////////////////////
// Dictionary Object AiqISecureFundingInquiry
// Generated Thu Jan 09 14:18:06 2003
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAiqISecureFundingInquiry, 0xb9e8e0f6, 0x13b5, 0x49d1, 0xb4, 0xbf, 0xeb, 0x6c, 0xc9, 0x4c, 0x21, 0x8f);


#ifdef MANGLE_AiqISecureFundingInquiry
#define MANGLEATTRIBUTE_AiqISecureFundingInquiry
#define MANGLEMETHOD_AiqISecureFundingInquiry
#endif


class AiqISecureFundingInquiry : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AiqISecureFundingInquiry
   virtual AbcICurrency* AiqISecureFundingInquiry_TotalCollateralAmount() = 0;
   virtual void  AiqISecureFundingInquiry_TotalCollateralAmount(AbcICurrency* Value) = 0;
   virtual AbcIAccountKey* AiqISecureFundingInquiry_AccountKey() = 0;
   virtual void  AiqISecureFundingInquiry_AccountKey(AbcIAccountKey* Value) = 0;
   virtual AiqISecureFundingAccounts* AiqISecureFundingInquiry_SecureFundingAccounts() = 0;
   virtual void  AiqISecureFundingInquiry_SecureFundingAccounts(AiqISecureFundingAccounts* Value) = 0;
#else
   virtual AbcICurrency* TotalCollateralAmount() = 0;
   virtual void  TotalCollateralAmount(AbcICurrency* Value) = 0;   
   virtual AbcIAccountKey* AccountKey() = 0;
   virtual void  AccountKey(AbcIAccountKey* Value) = 0;
   virtual AiqISecureFundingAccounts* SecureFundingAccounts() = 0;
   virtual void  SecureFundingAccounts(AiqISecureFundingAccounts* Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AiqISecureFundingInquiry
   virtual long AiqISecureFundingInquiry_Get(AbcIAccountKey* AccountKey, AbcIControlBlock* ControlBlock) = 0;
#else
   virtual long Get(AbcIAccountKey* AccountKey, AbcIControlBlock* ControlBlock) = 0;
#endif

   /////////////////////////////////////////////////////////
   // Marshalling support
   /////////////////////////////////////////////////////////

   /////////////////////////////////////////////////////////
   // toWire
   /////////////////////////////////////////////////////////
   long toWire(void*& buf)
   {
      GUID guid;

      // Marshalling Code For: AiqISecureFundingInquiry
      guid = IID_IAiqISecureFundingInquiry;
      cppGuidToWire(guid, buf);      
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)TotalCollateralAmount();
         pObj->toWire(buf);
         pObj->Release();
      }
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)AccountKey();
         pObj->toWire(buf);
         pObj->Release();
      }      
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)SecureFundingAccounts();
         pObj->toWire(buf);
         pObj->Release();
      }
      return 0;
   };

   /////////////////////////////////////////////////////////
   // fromWire
   /////////////////////////////////////////////////////////
   long fromWire(void*& buf)
   {
      long err = 0;
      RWCString strValue = "";
      GUID IidGuid;


      // Marshalling Code For: AiqISecureFundingInquiry
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAiqISecureFundingInquiry)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAiqISecureFundingInquiry,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AiqISecureFundingInquiry" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
      }

      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)TotalCollateralAmount();
         err = pObj->fromWire(buf);
         pObj->Release();
      }      
      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)AccountKey();
         err = pObj->fromWire(buf);
         pObj->Release();
      }
      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)SecureFundingAccounts();
         err = pObj->fromWire(buf);
         pObj->Release();
      }

      return err;

   };

   /////////////////////////////////////////////////////////
   // wireSize
   /////////////////////////////////////////////////////////
   long wireSize()
   {
      long ifaceSize = 0;


      // WireSize Code For: AiqISecureFundingInquiry
      ifaceSize += sizeof(GUID);  // Object Id
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)TotalCollateralAmount();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }      
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)AccountKey();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }      
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)SecureFundingAccounts();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AiqISecureFundingInquiry, &IID_IAiqISecureFundingInquiry> AiqISecureFundingInquirySp;
#endif

//=================================================
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
//=================================================

#endif // __IQISECUREFUNDINGINQUIRY_H__

