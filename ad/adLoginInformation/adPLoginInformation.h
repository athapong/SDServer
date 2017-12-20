//## begin module%377CDA3101AA.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/ad/adLoginInformation/adPLoginInformation.h-arc   1.0   13 Jun 2002 09:58:44   sddevl  $
//## end module%377CDA3101AA.cm

//## begin module%377CDA3101AA.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%377CDA3101AA.cp

//## Module: adPLoginInformation%377CDA3101AA; Package specification
//## Subsystem: adLoginInformation::adLoginInformation Process%37793ED6003A
//## Source file: U:\ad\adLoginInformation\adPLoginInformation.h

#ifndef adPLoginInformation
#define adPLoginInformation 1

//## begin module%377CDA3101AA.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcIControlBlock.h"
  //BC end module.additionalIncludes
//## end module%377CDA3101AA.additionalIncludes

//## begin module%377CDA3101AA.includes preserve=yes
//## end module%377CDA3101AA.includes

// adILoginInfo2
#include "adILoginInfo2.h"
// adILoginInformation
#include "adILoginInformation.h"
//## begin module%377CDA3101AA.declarations preserve=no
//## end module%377CDA3101AA.declarations

//## begin module%377CDA3101AA.additionalDeclarations preserve=yes
class AbcIPEncryption;
//## end module%377CDA3101AA.additionalDeclarations


//## begin AadPLoginInformation%37793EF6000C.preface preserve=yes
//## end AadPLoginInformation%37793EF6000C.preface

//## Class: AadPLoginInformation%37793EF6000C
//## Category: AadLoginInformation::AadLoginInformation Process%37793ED60031
//## Subsystem: adLoginInformation::adLoginInformation Process%37793ED6003A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class AadPLoginInformation : public AadILoginInformation, //## Inherits: <unnamed>%377CDA310146
                             	public AadILoginInfo2  //## Inherits: <unnamed>%3B3776A20071
{
  //## begin AadPLoginInformation%37793EF6000C.initialDeclarations preserve=yes
  //## end AadPLoginInformation%37793EF6000C.initialDeclarations

  public:
    //## Constructors (generated)
      AadPLoginInformation();

    //## Destructor (generated)
      virtual ~AadPLoginInformation();


    //## Other Operations (specified)
      //## Operation: Retrieve%37793F060308
      long Retrieve (AbcIControlBlock* pIControlBlock);

      //## Operation: QueryInterface%377CDA300271
      HRESULT STDMETHODCALLTYPE QueryInterface (REFIID riid, void** ppvObject);

      //## Operation: AddRef%377CDA3003BC
      ULONG STDMETHODCALLTYPE AddRef ();

      //## Operation: Release%377CDA310010
      ULONG STDMETHODCALLTYPE Release ();

      //## Operation: FinalConstruct%377CDA310056
      HRESULT FinalConstruct ();

    // Additional Public Declarations
      //## begin AadPLoginInformation%37793EF6000C.public preserve=yes
      //## end AadPLoginInformation%37793EF6000C.public

  protected:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: Password%37793FA4030F
      virtual RWCString& Password ();
      virtual void Password (const RWCString& value);

      //## Attribute: Login%37793FC70306
      virtual RWCString& Login ();
      virtual void Login (const RWCString& value);

      //## Attribute: SID%3B321ED200BA
      virtual RWCString& SID ();
      virtual void SID (const RWCString& value);

      //## Attribute: Port%3B321EEF02BA
      virtual long& Port ();
      virtual void Port (const long& value);

      //## Attribute: IPAddress%3B321EF900DE
      virtual RWCString& IPAddress ();
      virtual void IPAddress (const RWCString& value);

    // Additional Protected Declarations
      //## begin AadPLoginInformation%37793EF6000C.protected preserve=yes
      //## end AadPLoginInformation%37793EF6000C.protected

  private:
    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: RefCnt%377CDA300253
      virtual long& RefCnt ();
      virtual void RefCnt (const long& value);

    // Additional Private Declarations
      //## begin AadPLoginInformation%37793EF6000C.private preserve=yes
      long RetrieveLogin(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock);
      long RetrievePassword(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock);
      // MLC 06/25/01 begin - retreive SID, Port, and IPAddress from server
      long RetrieveSID(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock);
      long RetrievePort(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock);
      long RetrieveIPAddress(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock);
		// MLC 06/25/01 end - retreive SID, Port, and IPAddress from server

      BOOL InformationIsEncrypted(const RWCString& IniFileName);
      long DecipherInformation(AbcIControlBlock* pIControlBlock);
      long CipherInformation(AbcIControlBlock* pIControlBlock);
      BOOL EncryptCommunications(const RWCString& IniFileName);
      long DecipherPassword(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock);
      long DecipherLogin(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock);
      long CipherPassword(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock);
      long CipherLogin(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock);

      static char * const m_pCommunicationsIniKeyName;
      static char * const m_pOracleDatabaseIniKeyName;

      //, AbcIControlBlock* pControlBlock);
      //## end AadPLoginInformation%37793EF6000C.private
  private: //## implementation
    // Data Members for Class Attributes

      //## begin AadPLoginInformation::Password%37793FA4030F.attr preserve=no  protected: RWCString {U}
      RWCString m_Password;
      //## end AadPLoginInformation::Password%37793FA4030F.attr

      //## begin AadPLoginInformation::Login%37793FC70306.attr preserve=no  protected: RWCString {U}
      RWCString m_Login;
      //## end AadPLoginInformation::Login%37793FC70306.attr

      //## begin AadPLoginInformation::RefCnt%377CDA300253.attr preserve=no  private: long {V} 0
      long m_RefCnt;
      //## end AadPLoginInformation::RefCnt%377CDA300253.attr

      //## begin AadPLoginInformation::SID%3B321ED200BA.attr preserve=no  protected: RWCString {U}
      RWCString m_SID;
      //## end AadPLoginInformation::SID%3B321ED200BA.attr

      //## begin AadPLoginInformation::Port%3B321EEF02BA.attr preserve=no  protected: long {U} 0
      long m_Port;
      //## end AadPLoginInformation::Port%3B321EEF02BA.attr

      //## begin AadPLoginInformation::IPAddress%3B321EF900DE.attr preserve=no  protected: RWCString {U}
      RWCString m_IPAddress;
      //## end AadPLoginInformation::IPAddress%3B321EF900DE.attr

    // Additional Implementation Declarations
      //## begin AadPLoginInformation%37793EF6000C.implementation preserve=yes
      //## end AadPLoginInformation%37793EF6000C.implementation

};

//## begin AadPLoginInformation%37793EF6000C.postscript preserve=yes
//## end AadPLoginInformation%37793EF6000C.postscript

// Class AadPLoginInformation

//## Get and Set Operations for Class Attributes (inline)

inline RWCString& AadPLoginInformation::Password ()
{
  //## begin AadPLoginInformation::Password%37793FA4030F.get preserve=no
  return m_Password;
  //## end AadPLoginInformation::Password%37793FA4030F.get
}

inline void AadPLoginInformation::Password (const RWCString& value)
{
  //## begin AadPLoginInformation::Password%37793FA4030F.set preserve=no
  m_Password = value;
  //## end AadPLoginInformation::Password%37793FA4030F.set
}

inline RWCString& AadPLoginInformation::Login ()
{
  //## begin AadPLoginInformation::Login%37793FC70306.get preserve=no
  return m_Login;
  //## end AadPLoginInformation::Login%37793FC70306.get
}

inline void AadPLoginInformation::Login (const RWCString& value)
{
  //## begin AadPLoginInformation::Login%37793FC70306.set preserve=no
  m_Login = value;
  //## end AadPLoginInformation::Login%37793FC70306.set
}

inline long& AadPLoginInformation::RefCnt ()
{
  //## begin AadPLoginInformation::RefCnt%377CDA300253.get preserve=no
  return m_RefCnt;
  //## end AadPLoginInformation::RefCnt%377CDA300253.get
}

inline void AadPLoginInformation::RefCnt (const long& value)
{
  //## begin AadPLoginInformation::RefCnt%377CDA300253.set preserve=no
  m_RefCnt = value;
  //## end AadPLoginInformation::RefCnt%377CDA300253.set
}

inline RWCString& AadPLoginInformation::SID ()
{
  //## begin AadPLoginInformation::SID%3B321ED200BA.get preserve=no
  return m_SID;
  //## end AadPLoginInformation::SID%3B321ED200BA.get
}

inline void AadPLoginInformation::SID (const RWCString& value)
{
  //## begin AadPLoginInformation::SID%3B321ED200BA.set preserve=no
  m_SID = value;
  //## end AadPLoginInformation::SID%3B321ED200BA.set
}

inline long& AadPLoginInformation::Port ()
{
  //## begin AadPLoginInformation::Port%3B321EEF02BA.get preserve=no
  return m_Port;
  //## end AadPLoginInformation::Port%3B321EEF02BA.get
}

inline void AadPLoginInformation::Port (const long& value)
{
  //## begin AadPLoginInformation::Port%3B321EEF02BA.set preserve=no
  m_Port = value;
  //## end AadPLoginInformation::Port%3B321EEF02BA.set
}

inline RWCString& AadPLoginInformation::IPAddress ()
{
  //## begin AadPLoginInformation::IPAddress%3B321EF900DE.get preserve=no
  return m_IPAddress;
  //## end AadPLoginInformation::IPAddress%3B321EF900DE.get
}

inline void AadPLoginInformation::IPAddress (const RWCString& value)
{
  //## begin AadPLoginInformation::IPAddress%3B321EF900DE.set preserve=no
  m_IPAddress = value;
  //## end AadPLoginInformation::IPAddress%3B321EF900DE.set
}

//## begin module%377CDA3101AA.epilog preserve=yes
//## end module%377CDA3101AA.epilog


#endif
