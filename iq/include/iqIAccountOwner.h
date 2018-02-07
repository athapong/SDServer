
#ifndef __IQIACCOUNTOWNER_H__
#define __IQIACCOUNTOWNER_H__


/************************************************
   RogueWave C++ Header
   Interface Header File : Server\iqIAccountOwner.h
   Generated - Thu Nov 11 14:03:09 1999
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
#include "bcIUserParam.h"



//////////////////////////////////////////////////////////////////////
// Dictionary Object AiqIAccountOwner
// Generated Thu Nov 11 14:03:09 1999
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAiqIAccountOwner, 0x5739a9c3, 0x97b3, 0x11d3, 0xa2, 0xcd, 0x0, 0x0, 0xf6, 0x4e, 0x57, 0x88);


#ifdef MANGLE_AiqIAccountOwner
#define MANGLEATTRIBUTE_AiqIAccountOwner
#define MANGLEMETHOD_AiqIAccountOwner
#endif


class AiqIAccountOwner : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AiqIAccountOwner
   virtual AbcIAccountKey* AiqIAccountOwner_CustomerKey() = 0;
   virtual void  AiqIAccountOwner_CustomerKey(AbcIAccountKey* Value) = 0;
   virtual RWCString& AiqIAccountOwner_NameLine1() = 0;
   virtual void  AiqIAccountOwner_NameLine1(const RWCString& Value) = 0;
   virtual RWCString& AiqIAccountOwner_Ownership() = 0;
   virtual void  AiqIAccountOwner_Ownership(const RWCString& Value) = 0;
#else
   virtual AbcIAccountKey* CustomerKey() = 0;
   virtual void  CustomerKey(AbcIAccountKey* Value) = 0;
   virtual RWCString& NameLine1() = 0;
   virtual void  NameLine1(const RWCString& Value) = 0;
   virtual RWCString& Ownership() = 0;
   virtual void  Ownership(const RWCString& Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AiqIAccountOwner
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

      // Marshalling Code For: AiqIAccountOwner
      guid = IID_IAiqIAccountOwner;
      cppGuidToWire(guid, buf);
      { // scoped to reduce compiler warnings
         AbcObject *pObj;
         pObj = (AbcObject*)CustomerKey();
         pObj->toWire(buf);
         pObj->Release();
      }
      cppStringToWire(NameLine1(),buf);
      cppStringToWire(Ownership(),buf);
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


      // Marshalling Code For: AiqIAccountOwner
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAiqIAccountOwner)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAiqIAccountOwner,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AiqIAccountOwner" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
      }

      if(!err)
      {
         AbcObject *pObj;
         pObj = (AbcObject*)CustomerKey();
         err = pObj->fromWire(buf);
         pObj->Release();
      }
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         NameLine1(strValue);
      }
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         Ownership(strValue);
      }

      return err;

   };

   /////////////////////////////////////////////////////////
   // wireSize
   /////////////////////////////////////////////////////////
   long wireSize()
   {
      long ifaceSize = 0;


      // WireSize Code For: AiqIAccountOwner
      ifaceSize += sizeof(GUID);  // Object Id
      { // scope variables when processing Objects
         AbcObject *pObj;
         pObj = (AbcObject*)CustomerKey();
         ifaceSize += pObj->wireSize();
         pObj->Release();
      }
      ifaceSize += NameLine1().length() + 1;  // NameLine1
      ifaceSize += Ownership().length() + 1;  // Ownership
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AiqIAccountOwner, &IID_IAiqIAccountOwner> AiqIAccountOwnerSp;
#endif
typedef AbcList<AiqIAccountOwner> AiqIAccountOwnerList;

//////////////////////////////////////////////////////////////////////
// Dictionary Object AiqIAccountOwners
// Generated Thu Nov 11 14:03:09 1999
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAiqIAccountOwners, 0x5739a9c5, 0x97b3, 0x11d3, 0xa2, 0xcd, 0x0, 0x0, 0xf6, 0x4e, 0x57, 0x88);


#ifdef MANGLE_AiqIAccountOwners
#define MANGLEATTRIBUTE_AiqIAccountOwners
#define MANGLEMETHOD_AiqIAccountOwners
#endif

EXTERN_C const GUID CLSID_AiqPAccountOwner;

class AiqIAccountOwners : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AiqIAccountOwners
   virtual AiqIAccountOwnerList& AiqIAccountOwners_AccountOwnerList() = 0;
   virtual void  AiqIAccountOwners_AccountOwnerList(const AiqIAccountOwnerList& Value) = 0;
#else
   virtual AiqIAccountOwnerList& AccountOwnerList() = 0;
   virtual void  AccountOwnerList(const AiqIAccountOwnerList& Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AiqIAccountOwners
   virtual long AiqIAccountOwners_Get(AbcIAccountKey* pIAccountKey, AbcIControlBlock* pControlBlock) = 0;
#else
   virtual long Get(AbcIAccountKey* pIAccountKey, AbcIControlBlock* pControlBlock) = 0;
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

      // Marshalling Code For: AiqIAccountOwners
      guid = IID_IAiqIAccountOwners;
      cppGuidToWire(guid, buf);
      { // scoped to reduce compiler warnings
         short rowCount = AccountOwnerList().entries();
         cppShortToWire(&rowCount, buf);
         for(short ndx=0; ndx < rowCount; ndx++)
         {
            AiqIAccountOwner* ifacePtr;
            ifacePtr = AccountOwnerList().at(ndx);
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


      // Marshalling Code For: AiqIAccountOwners
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAiqIAccountOwners)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAiqIAccountOwners,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AiqIAccountOwners" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
      }


      if (!err)
      {
         AiqIAccountOwner* pifAiqIAccountOwner;
         HRESULT hresult;
         short rowCount;
         AccountOwnerList().clear();
         cppShortFromWire(buf, &rowCount);
         for (short cnt = 0;(cnt < rowCount) && (err == 0); cnt++)
         {
            hresult = AbcCoCreateInstance(CLSID_AiqPAccountOwner,
               NULL,CLSCTX_INPROC_SERVER,IID_IAiqIAccountOwner,(LPVOID*) &pifAiqIAccountOwner);
            if (FAILED(hresult))
            {
               err = hresult;
            } else 
            {
               err = pifAiqIAccountOwner->fromWire(buf);
               if (err == 0)
                  AccountOwnerList().append(pifAiqIAccountOwner);
               pifAiqIAccountOwner->Release();
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


      // WireSize Code For: AiqIAccountOwners
      ifaceSize += sizeof(GUID);  // Object Id
      { // scope variables when processing lists
         // wireSize of AccountOwnerList
         ifaceSize += 2; // list count and list of AccountOwnerList
         unsigned int cnt = AccountOwnerList().entries();
         AbcObject* pIface;
         for(unsigned int ii = 0; ii < cnt; ii++)  // wireSize of AccountOwnerList
         {
            pIface = AccountOwnerList().at(ii);
            ifaceSize += pIface->wireSize();
            pIface->Release();
         }
      }
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AiqIAccountOwners, &IID_IAiqIAccountOwners> AiqIAccountOwnersSp;
#endif

//=================================================
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
//=================================================

#endif // __IQIACCOUNTOWNER_H__

