
#ifndef __ADILOGININFO2_H__
#define __ADILOGININFO2_H__


/************************************************
   RogueWave C++ Header
   Interface Header File : U:\ad\include\adILoginInfo2.h
   Generated - Mon Jun 25 10:44:14 2001
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



//////////////////////////////////////////////////////////////////////
// Dictionary Object AadILoginInfo2
// Generated Mon Jun 25 10:44:14 2001
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAadILoginInfo2, 0xb7dfb4cb, 0xbb9a, 0x4e87, 0x93, 0xe, 0x89, 0x43, 0x3, 0x63, 0xf6, 0xde);


#ifdef MANGLE_AadILoginInfo2
#define MANGLEATTRIBUTE_AadILoginInfo2
#define MANGLEMETHOD_AadILoginInfo2
#endif


class AadILoginInfo2 : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AadILoginInfo2
   virtual RWCString& AadILoginInfo2_Password() = 0;
   virtual void  AadILoginInfo2_Password(const RWCString& Value) = 0;
   virtual RWCString& AadILoginInfo2_Login() = 0;
   virtual void  AadILoginInfo2_Login(const RWCString& Value) = 0;
   virtual RWCString& AadILoginInfo2_SID() = 0;
   virtual void  AadILoginInfo2_SID(const RWCString& Value) = 0;
   virtual long& AadILoginInfo2_Port() = 0;
   virtual void  AadILoginInfo2_Port(const long& Value) = 0;
   virtual RWCString& AadILoginInfo2_IPAddress() = 0;
   virtual void  AadILoginInfo2_IPAddress(const RWCString& Value) = 0;
#else
   virtual RWCString& Password() = 0;
   virtual void  Password(const RWCString& Value) = 0;
   virtual RWCString& Login() = 0;
   virtual void  Login(const RWCString& Value) = 0;
   virtual RWCString& SID() = 0;
   virtual void  SID(const RWCString& Value) = 0;
   virtual long& Port() = 0;
   virtual void  Port(const long& Value) = 0;
   virtual RWCString& IPAddress() = 0;
   virtual void  IPAddress(const RWCString& Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AadILoginInfo2
   virtual long AadILoginInfo2_Retrieve(AbcIControlBlock* pIControlBlock) = 0;
#else
   virtual long Retrieve(AbcIControlBlock* pIControlBlock) = 0;
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

      // Marshalling Code For: AadILoginInfo2
      guid = IID_IAadILoginInfo2;
      cppGuidToWire(guid, buf);
      cppStringToWire(Password(),buf);
      cppStringToWire(Login(),buf);
      cppStringToWire(SID(),buf);
      cppLongToWire(Port(),buf);
      cppStringToWire(IPAddress(),buf);
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


      // Marshalling Code For: AadILoginInfo2
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAadILoginInfo2)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAadILoginInfo2,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AadILoginInfo2" << endl;
         cout << "GUID Interface is: " << IfaceGuid <<  endl;
         cout << "GUID on wire is  : " << WireGuid << endl;
         #endif
      }

      if(!err)
      {
         cppStringFromWire(buf, strValue);
         Password(strValue);
      }
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         Login(strValue);
      }
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         SID(strValue);
      }
      if(!err)
      {
         long lValue;
         cppLongFromWire(buf, &lValue);
         Port(lValue);
      }
      if(!err)
      {
         cppStringFromWire(buf, strValue);
         IPAddress(strValue);
      }

      return err;

   };

   /////////////////////////////////////////////////////////
   // wireSize
   /////////////////////////////////////////////////////////
   long wireSize()
   {
      long ifaceSize = 0;


      // WireSize Code For: AadILoginInfo2
      ifaceSize += sizeof(GUID);  // Object Id
      ifaceSize += Password().length() + 1;  // Password
      ifaceSize += Login().length() + 1;  // Login
      ifaceSize += SID().length() + 1;  // SID
      ifaceSize += sizeof(long);  // Port
      ifaceSize += IPAddress().length() + 1;  // IPAddress
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AadILoginInfo2, &IID_IAadILoginInfo2> AadILoginInfo2Sp;
#endif

//=================================================
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
//=================================================

#endif // __ADILOGININFO2_H__

