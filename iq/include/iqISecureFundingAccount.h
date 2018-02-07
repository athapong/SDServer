
#ifndef __IQISECUREFUNDINGACCOUNT_H__
#define __IQISECUREFUNDINGACCOUNT_H__


/************************************************
   RogueWave C++ Header
   Interface Header File : U:\iq\include\iqISecureFundingAccount.h
   Generated - Thu Jan 09 14:17:42 2003
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
#include "bcIAccountKey.h"
#include "bcICurrency.h"
#include "bcIDateTime.h"


   
//////////////////////////////////////////////////////////////////////
// Dictionary Object AiqISecureFundingAccount
// Generated Thu Jan 09 14:17:42 2003
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAiqISecureFundingAccount, 0xbbc19811, 0x12b1, 0x445d, 0x87, 0x70, 0x9, 0x8d, 0x3a, 0xcd, 0xee, 0xf0);


#ifdef MANGLE_AiqISecureFundingAccount
#define MANGLEATTRIBUTE_AiqISecureFundingAccount
#define MANGLEMETHOD_AiqISecureFundingAccount
#endif


class AiqISecureFundingAccount : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AiqISecureFundingAccount
   virtual AbcIAccountKey* AiqISecureFundingAccount_AccountKey() = 0;
   virtual void  AiqISecureFundingAccount_AccountKey(AbcIAccountKey* Value) = 0;
   virtual AbcICurrency* AiqISecureFundingAccount_CollateralAmount() = 0;
   virtual void  AiqISecureFundingAccount_CollateralAmount(AbcICurrency* Value) = 0;   
   virtual RWCString& AiqISecureFundingAccount_Rate() = 0;
   virtual void  AiqISecureFundingAccount_Rate(const RWCString& Value) = 0;
   virtual AbcIDateTime* AiqISecureFundingAccount_EffectiveDate() = 0;
   virtual void  AiqISecureFundingAccount_EffectiveDate(AbcIDateTime* Value) = 0;
   virtual AbcIDateTime* AiqISecureFundingAccount_MaturityDate() = 0;
   virtual void  AiqISecureFundingAccount_MaturityDate(AbcIDateTime* Value) = 0;
#else
   virtual AbcIAccountKey* AccountKey() = 0;
   virtual void  AccountKey(AbcIAccountKey* Value) = 0;
   virtual AbcICurrency* CollateralAmount() = 0;
   virtual void  CollateralAmount(AbcICurrency* Value) = 0;   
   virtual RWCString& Rate() = 0;
   virtual void  Rate(const RWCString& Value) = 0;
   virtual AbcIDateTime* EffectiveDate() = 0;
   virtual void  EffectiveDate(AbcIDateTime* Value) = 0;
   virtual AbcIDateTime* MaturityDate() = 0;
   virtual void  MaturityDate(AbcIDateTime* Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AiqISecureFundingAccount
#else
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

      // Marshalling Code For: AiqISecureFundingAccount
      guid = IID_IAiqISecureFundingAccount;
      cppGuidToWire(guid, buf);
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)AccountKey();
         pObj->toWire(buf);
         pObj->Release();
      }
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)CollateralAmount();
         pObj->toWire(buf);
         pObj->Release();
      }           
      cppStringToWire(Rate(),buf);
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)EffectiveDate();
         pObj->toWire(buf);
         pObj->Release();
      }
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)MaturityDate();
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


      // Marshalling Code For: AiqISecureFundingAccount
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAiqISecureFundingAccount)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAiqISecureFundingAccount,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AiqISecureFundingAccount" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
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
         pObj = (AbcObject*)CollateralAmount();
         err = pObj->fromWire(buf);
         pObj->Release();
      }      
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         Rate(strValue);
      }
      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)EffectiveDate();
         err = pObj->fromWire(buf);
         pObj->Release();
      }
      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)MaturityDate();
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


      // WireSize Code For: AiqISecureFundingAccount
      ifaceSize += sizeof(GUID);  // Object Id
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)AccountKey();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }      
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)CollateralAmount();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }      
      ifaceSize += Rate().length() + 1;  // Rate
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)EffectiveDate();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)MaturityDate();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }      
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AiqISecureFundingAccount, &IID_IAiqISecureFundingAccount> AiqISecureFundingAccountSp;
#endif
typedef AbcList<AiqISecureFundingAccount> AiqISecureFundingAccountList;

//////////////////////////////////////////////////////////////////////
// Dictionary Object AiqISecureFundingAccounts
// Generated Thu Jan 09 14:17:42 2003
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAiqISecureFundingAccounts, 0xe6e8034b, 0x1b4, 0x45e9, 0xa9, 0x8c, 0x6f, 0x70, 0xfe, 0x5, 0xe6, 0x21);


#ifdef MANGLE_AiqISecureFundingAccounts
#define MANGLEATTRIBUTE_AiqISecureFundingAccounts
#define MANGLEMETHOD_AiqISecureFundingAccounts
#endif

EXTERN_C const GUID CLSID_AiqPSecureFundingAccount;

class AiqISecureFundingAccounts : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AiqISecureFundingAccounts
   virtual AiqISecureFundingAccountList& AiqISecureFundingAccounts_SecureFundingAccountList() = 0;
   virtual void  AiqISecureFundingAccounts_SecureFundingAccountList(const AiqISecureFundingAccountList& Value) = 0;
#else
   virtual AiqISecureFundingAccountList& SecureFundingAccountList() = 0;
   virtual void  SecureFundingAccountList(const AiqISecureFundingAccountList& Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AiqISecureFundingAccounts
   virtual long AiqISecureFundingAccounts_Get(AbcIControlBlock* pControlBlock) = 0;
#else
   virtual long Get(AbcIControlBlock* pControlBlock) = 0;
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

      // Marshalling Code For: AiqISecureFundingAccounts
      guid = IID_IAiqISecureFundingAccounts;
      cppGuidToWire(guid, buf);
      { // scoped to reduce compiler warnings
         short rowCount = SecureFundingAccountList().entries();
         cppShortToWire(&rowCount, buf);
         for(short ndx=0; ndx < rowCount; ndx++)
         {
            AiqISecureFundingAccount* ifacePtr;
            ifacePtr = SecureFundingAccountList().at(ndx);
            ifacePtr->toWire(buf);
            ifacePtr->Release();
         }
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


      // Marshalling Code For: AiqISecureFundingAccounts
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAiqISecureFundingAccounts)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAiqISecureFundingAccounts,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AiqISecureFundingAccounts" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
      }


      if (!err)
      {
         AiqISecureFundingAccount* pifAiqISecureFundingAccount;
         HRESULT hresult;
         short rowCount;
         SecureFundingAccountList().clear();
         cppShortFromWire(buf, &rowCount);
         for (short cnt = 0;(cnt < rowCount) && (err == 0); cnt++)
         {
            hresult = AbcCoCreateInstance(CLSID_AiqPSecureFundingAccount,
               NULL,CLSCTX_INPROC_SERVER,IID_IAiqISecureFundingAccount,(LPVOID*) &pifAiqISecureFundingAccount);
            if (FAILED(hresult))
            {
               err = hresult;
            } else 
            {
               err = pifAiqISecureFundingAccount->fromWire(buf);
               if (err == 0)
                  SecureFundingAccountList().append(pifAiqISecureFundingAccount);
               pifAiqISecureFundingAccount->Release();
            }
         }
      }

      return err;

   };

   /////////////////////////////////////////////////////////
   // wireSize
   /////////////////////////////////////////////////////////
   long wireSize()
   {
      long ifaceSize = 0;


      // WireSize Code For: AiqISecureFundingAccounts
      ifaceSize += sizeof(GUID);  // Object Id
      { // scope variables when processing lists
         // wireSize of SecureFundingAccountList
         ifaceSize += 2; // list count and list of SecureFundingAccountList
         unsigned int cnt = SecureFundingAccountList().entries();
         AbcObject* pIface;
         for(unsigned int ii = 0; ii < cnt; ii++)  // wireSize of SecureFundingAccountList
         {
            pIface = SecureFundingAccountList().at(ii);
            ifaceSize += pIface->wireSize();
            pIface->Release();
         }
      }
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AiqISecureFundingAccounts, &IID_IAiqISecureFundingAccounts> AiqISecureFundingAccountsSp;
#endif

//=================================================
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
//=================================================

#endif // __IQISECUREFUNDINGACCOUNT_H__

