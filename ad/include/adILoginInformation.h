
#ifndef __ADILOGININFORMATION_H__
#define __ADILOGININFORMATION_H__


/************************************************
   RogueWave C++ Header
   Interface Header File : U:\ad\include\adILoginInformation.h
   Generated - Fri Jul 02 14:37:48 1999
   AisIdl2 Version 2.2.9
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
// Dictionary Object AadILoginInformation
// Generated Fri Jul 02 14:37:48 1999
//////////////////////////////////////////////////////////////////////
DEFINE_GUID(IID_IAadILoginInformation, 0x6f78a472, 0x3092, 0x11d3, 0xa2, 0x4f, 0x0, 0x0, 0xf6, 0x4e, 0x57, 0x88);


#ifdef MANGLE_AadILoginInformation
#define MANGLEATTRIBUTE_AadILoginInformation
#define MANGLEMETHOD_AadILoginInformation
#endif


class AadILoginInformation : public AbcObject
{

public: 

// User specified attributes for this class
#ifdef MANGLEATRIBUTE_AadILoginInformation
   virtual RWCString& AadILoginInformation_Password() = 0;
   virtual void  AadILoginInformation_Password(const RWCString& Value) = 0;
   virtual RWCString& AadILoginInformation_Login() = 0;
   virtual void  AadILoginInformation_Login(const RWCString& Value) = 0;
#else
   virtual RWCString& Password() = 0;
   virtual void  Password(const RWCString& Value) = 0;
   virtual RWCString& Login() = 0;
   virtual void  Login(const RWCString& Value) = 0;
#endif

   // User specified methods for this class
#ifdef MANGLEMETHOD_AadILoginInformation
   virtual long AadILoginInformation_Retrieve(AbcIControlBlock* pIControlBlock) = 0;
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

      // Marshalling Code For: AadILoginInformation
      guid = IID_IAadILoginInformation;
      cppGuidToWire(guid, buf);
      cppStringToWire(Password(),buf);
      cppStringToWire(Login(),buf);
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


      // Marshalling Code For: AadILoginInformation
      if(!err) cppGuidFromWire(buf, IidGuid);

      // If the object is not what we expected return error
      if(IidGuid != IID_IAadILoginInformation)
      {

         err = MW_GUID_MISMATCH;

         #if defined(_DEBUG) && !defined(DB_NO_COUT)
         RWCString IfaceGuid;
         RWCString WireGuid;
         AbcStringFromCLSID(IID_IAadILoginInformation,IfaceGuid);
         AbcStringFromCLSID(IidGuid,WireGuid);
         cout << "GUID Mismatch for Interface: AadILoginInformation" << endl;
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

      return err;

   };

   /////////////////////////////////////////////////////////
   // wireSize
   /////////////////////////////////////////////////////////
   long wireSize()
   {
      long ifaceSize = 0;


      // WireSize Code For: AadILoginInformation
      ifaceSize += sizeof(GUID);  // Object Id
      ifaceSize += Password().length() + 1;  // Password
      ifaceSize += Login().length() + 1;  // Login
       return ifaceSize;
   };

};

#ifndef NO_SMART_POINTER
typedef AbcComQiPtr<AadILoginInformation, &IID_IAadILoginInformation> AadILoginInformationSp;
#endif

//=================================================
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
// Interface Marshalling Helper Classes
//=================================================

#endif // __ADILOGININFORMATION_H__

