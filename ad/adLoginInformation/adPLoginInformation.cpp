//## begin module%377CDA3101B4.cm preserve=no
//	$Header:   /u02/pvcsarch/tmb804/archives/develop/ad/adLoginInformation/adPLoginInformation.cpp-arc   1.0   13 Jun 2002 09:58:44   sddevl  $
//## end module%377CDA3101B4.cm

//## begin module%377CDA3101B4.cp preserve=no
//	*********************************************************
//	*  THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG
//	*  TO ALLTEL INFORMATION SERVICES, INC. AND IS
//	*  LICENSED BY AN AGREEMENT.  ANY UNAUTHORIZED ACCESS,
//	*  USE, DUPLICATION, OR DISCLOSURE IS UNLAWFUL.
//	*  COPYRIGHT ALLTEL INFORMATION SERVICES, INC.
//	*  1999, ALL RIGHTS RESERVED.
//	*********************************************************
//## end module%377CDA3101B4.cp

//## Module: adPLoginInformation%377CDA3101B4; Package body
//## Subsystem: adLoginInformation::adLoginInformation Process%37793ED6003A
//## Source file: U:\ad\adLoginInformation\adPLoginInformation.cpp

//## begin module%377CDA3101B4.additionalIncludes preserve=yes
  //BC begin module.additionalIncludes DO NOT ADD CODE BETWEEN THESE BC TAGS
  //BC - If you must preserve a BC section,
  //BC - change "DO NOT ADD CODE BETWEEN THESE BC TAGS"
  //BC - on "BC begin" lines to "bcPreserve=yes"
#include "bcErrors.h"
#include "bcIPControlBlockTran.h"
  //BC end module.additionalIncludes
//## end module%377CDA3101B4.additionalIncludes

//## begin module%377CDA3101B4.includes preserve=yes
#include "bcIPEncryption.h"
#include "ControlBlockSupport.h"
//## end module%377CDA3101B4.includes

// adPLoginInformation
#include "adPLoginInformation.h"
//## begin module%377CDA3101B4.declarations preserve=no
//## end module%377CDA3101B4.declarations

//## begin module%377CDA3101B4.additionalDeclarations preserve=yes
  //BC begin guid.externDeclare DO NOT ADD CODE BETWEEN THESE BC TAGS
BC_EXTERN_GUID(CLSID_AbcPControlBlock)
  //BC end guid.externDeclare
  //BC begin guid.ole bcPreserve=yes

// {38C01D25-2EF1-11D3-A24D-0000F64E5788}
ABCIMPLEMENT_OLECREATE2(AadPLoginInformation, "AadPLoginInformation.1", 0x38C01D25, 0x2EF1, 0x11D3, 0xA2, 0x4D, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);
// Pre-converted guid for cutting-and-pasting into the shared-lib guid file.
// {38C01D25-2EF1-11D3-A24D-0000F64E5788}
// DEFINE_GUID(CLSID_AadPLoginInformation, 0x38C01D25, 0x2EF1, 0x11D3, 0xA2, 0x4D, 0x00, 0x00, 0xF6, 0x4E, 0x57, 0x88);

  //BC end guid.ole
BC_EXTERN_GUID(CLSID_AbcPEncryption)

char * const AadPLoginInformation::m_pCommunicationsIniKeyName = "BCKEYFILE";
char * const AadPLoginInformation::m_pOracleDatabaseIniKeyName = "ADKEYFILE";

//## end module%377CDA3101B4.additionalDeclarations


// Class AadPLoginInformation







AadPLoginInformation::AadPLoginInformation()
  //## begin AadPLoginInformation::AadPLoginInformation%.hasinit preserve=no
      : m_RefCnt(0), m_Port(0)
  //## end AadPLoginInformation::AadPLoginInformation%.hasinit
  //## begin AadPLoginInformation::AadPLoginInformation%.initialization preserve=yes
  //## end AadPLoginInformation::AadPLoginInformation%.initialization
{
  //## begin AadPLoginInformation::AadPLoginInformation%.body preserve=yes
  //BC begin traceCom.ctor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_CONSTRUCTOR(AadPLoginInformation)
  AbcOleLockApp();
  //BC end traceCom.ctor
  //## end AadPLoginInformation::AadPLoginInformation%.body
}


AadPLoginInformation::~AadPLoginInformation()
{
  //## begin AadPLoginInformation::~AadPLoginInformation%.body preserve=yes
  //BC begin traceCom.dtor DO NOT ADD CODE BETWEEN THESE BC TAGS
  BC_TRACE_COM_DESTRUCTOR(AadPLoginInformation)
  AbcOleUnlockApp();
  //BC end traceCom.dtor
  //## end AadPLoginInformation::~AadPLoginInformation%.body
}



//## Other Operations (implementation)
long AadPLoginInformation::Retrieve (AbcIControlBlock* pIControlBlock)
{
  //## begin AadPLoginInformation::Retrieve%37793F060308.body preserve=yes
   long Status = BC_FATAL;

   if (pIControlBlock != NULL )
   {
      Status = BC_NO_ERRORS;

      RWCString IniFileName = "bc.ini";
      Status = RetrieveLogin(IniFileName, pIControlBlock);
      #ifdef _DEBUG
      cout << "RetrieveLogin returns " << Status << endl;
      #endif
      if (Status == BC_NO_ERRORS)
      {
          Status = RetrievePassword(IniFileName, pIControlBlock);
          #ifdef _DEBUG
          cout << "RetrievePassword returns " << Status << endl;
          #endif
      }
      // MLC 06/25/01 begin - retreive SID, Port, and IPAddress from server
      if (Status == BC_NO_ERRORS)
	  	{
		 	Status = RetrieveSID(IniFileName, pIControlBlock);
	      #ifdef _DEBUG
	      cout << "RetrieveSID returns " << Status << endl;
	      #endif
      }
      if (Status == BC_NO_ERRORS)
		{
			Status = RetrieveIPAddress(IniFileName, pIControlBlock);
			#ifdef _DEBUG
			cout << "RetrieveIPAddress returns " << Status << endl;
			#endif
      }
      if (Status == BC_NO_ERRORS)
		{
			Status = RetrievePort(IniFileName, pIControlBlock);
			#ifdef _DEBUG
			cout << "RetrievePort returns " << Status << endl;
			#endif
      }
		// MLC 06/25/01 end - retreive SID, Port, and IPAddress from server
      if (Status == BC_NO_ERRORS && InformationIsEncrypted(IniFileName) == TRUE)
      {
          Status = DecipherInformation( pIControlBlock);
          #ifdef _DEBUG
          cout << "DecipherInformation returns " << Status << endl;
          #endif
      }

      if (Status == BC_NO_ERRORS && EncryptCommunications(IniFileName) == TRUE)
      {
          Status = CipherInformation( pIControlBlock );
          #ifdef _DEBUG
          cout << "CipherInformation returns " << Status << endl;
          #endif
      }

      //short Dumped = DumpMessages(pIControlBlock);
   }

   return Status;
  //## end AadPLoginInformation::Retrieve%37793F060308.body
}

HRESULT STDMETHODCALLTYPE AadPLoginInformation::QueryInterface (REFIID riid, void** ppvObject)
{
  //## begin AadPLoginInformation::QueryInterface%377CDA300271.body preserve=yes
  //BC begin com.queryInterface DO NOT ADD CODE BETWEEN THESE BC TAGS
  if (riid == IID_IUnknown)
      *ppvObject = (LPUNKNOWN) (AadILoginInformation*) this;
  else
      if (riid == IID_IAadILoginInformation)
          *ppvObject = (AadILoginInformation* ) this;
  else
      if (riid == IID_IAadILoginInfo2)
          *ppvObject = (AadILoginInfo2* ) this;
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
  //## end AadPLoginInformation::QueryInterface%377CDA300271.body
}

ULONG STDMETHODCALLTYPE AadPLoginInformation::AddRef ()
{
  //## begin AadPLoginInformation::AddRef%377CDA3003BC.body preserve=yes
  //BC begin com.addRef DO NOT ADD CODE BETWEEN THESE BC TAGS
  return ++m_RefCnt;
  //BC end com.addRef
  //## end AadPLoginInformation::AddRef%377CDA3003BC.body
}

ULONG STDMETHODCALLTYPE AadPLoginInformation::Release ()
{
  //## begin AadPLoginInformation::Release%377CDA310010.body preserve=yes
  //BC begin com.release DO NOT ADD CODE BETWEEN THESE BC TAGS
  long rv;
  rv = --m_RefCnt;
  if (!m_RefCnt)
      delete this;
  return rv;
  //BC end com.release
  //## end AadPLoginInformation::Release%377CDA310010.body
}

HRESULT AadPLoginInformation::FinalConstruct ()
{
  //## begin AadPLoginInformation::FinalConstruct%377CDA310056.body preserve=yes
  //BC begin com.finalConstruct DO NOT ADD CODE BETWEEN THESE BC TAGS
  HRESULT hresult = S_OK;
  return hresult;
  //BC end com.finalConstruct
  //## end AadPLoginInformation::FinalConstruct%377CDA310056.body
}

// Additional Declarations
  //## begin AadPLoginInformation%37793EF6000C.declarations preserve=yes
long AadPLoginInformation::RetrieveLogin(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;
    if (pIControlBlock != NULL )
    {

        static const int MAX_USERNAMELEN = 300;
        char szUserName[MAX_USERNAMELEN] ;

        long Length = GetPrivateProfileString(  "DATABASE_SECTION",
                                                "USERNAME",
                                                "",
                                                szUserName,
                                                sizeof(szUserName)-1,
                                                (char *)(const char *)IniFileName ) ;

        if ( Length > 0 )
        {
            m_Login = szUserName;
            Status = BC_NO_ERRORS;

            #ifdef _DEBUG
            cout << "login in bc.ini is -- " << m_Login << endl;
            #endif
        }
        else
        {
            Status = BC_INI_HOSED;

            cout << "bc.ini file is missing the database username/Login" << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
               cout << "AadPLoginInformation::RetrieveLogin() - ControlBlockTran invalid" << endl;
            }
            else
            {
               spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                               MSG_BC_INVALID_VALUE,
                                               Status,
                                               "AadLoginInformation::RetrieveLogin - GetProfileString failed, bc.ini file missing username");
            }
        }
    }

    return Status;
}

long AadPLoginInformation::RetrievePassword(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if (pIControlBlock != NULL )
    {
        static const int MAX_PASSWORDLEN = 300;
        char szPassword[MAX_PASSWORDLEN] ;

        long Length = GetPrivateProfileString("DATABASE_SECTION",
                                                "PASSWORD",
                                                "",
                                                szPassword,
                                                sizeof(szPassword)-1,
                                                (char *)(const char *)IniFileName) ;

        if (Length > 0 )
        {
            m_Password = szPassword;
            Status = BC_NO_ERRORS;
            #ifdef _DEBUG
            cout << "password in bc.ini is -- " << m_Password << endl;
            #endif
        }
        else
        {
            Status = BC_INI_HOSED;
            cout << "bc.ini file is missing the database password" << endl;

            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
               cout << "RetrievePassword() - ControlBlockTran invalid" << endl;
            }
            else
            {
                   spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                           MSG_BC_INVALID_VALUE,
                                           Status,
                                           "AadLoginInformation::Retrieve password - GetProfileString failed, bc.ini missing password");
            }
        }
    }
    return Status;
}

// MLC 06/25/01 begin - retrieve SID, Port, and IPAddress from server
long AadPLoginInformation::RetrieveSID(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;
    if (pIControlBlock != NULL )
    {

        static const int MAX_SIDLEN = 300;

		char *pSID = getenv( "ORACLE_SID" );

        long Length = strlen( pSID );

        if ( Length > 0 )
        {
            m_SID = pSID;
            Status = BC_NO_ERRORS;

            #ifdef _DEBUG
            cout << "SID in bc.ini is -- " << m_SID << endl;
            #endif
        }
        else
        {
            Status = BC_INI_HOSED;

            cout << "bc.ini file is missing the database SID" << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
               cout << "AadPLoginInformation::RetrieveSID() - ControlBlockTran invalid" << endl;
            }
            else
            {
               spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                               MSG_BC_INVALID_VALUE,
                                               Status,
                                               "AadLoginInformation::RetrieveSID - GetProfileString failed, bc.ini file missing username");
            }
        }
    }

    return Status;
}

long AadPLoginInformation::RetrieveIPAddress(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;
    if (pIControlBlock != NULL )
    {

        static const int MAX_IPLEN = 300;
        char szIPAddress[MAX_IPLEN] ;

        long Length = GetPrivateProfileString(  "ADMIN_LOGIN",
                                                "IPADDRESS",
                                                "",
                                                szIPAddress,
                                                sizeof(szIPAddress)-1,
                                                (char *)(const char *)IniFileName ) ;

        if ( Length > 0 )
        {
            m_IPAddress = szIPAddress;
            Status = BC_NO_ERRORS;

            #ifdef _DEBUG
            cout << "IPAddress in bc.ini is -- " << m_IPAddress << endl;
            #endif
        }
        else
        {
            Status = BC_INI_HOSED;

            cout << "bc.ini file is missing the database IPAddress" << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
               cout << "AadPLoginInformation::RetrieveIPAddress() - ControlBlockTran invalid" << endl;
            }
            else
            {
               spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                               MSG_BC_INVALID_VALUE,
                                               Status,
                                               "AadLoginInformation::RetrieveIPAddress - GetProfileString failed, bc.ini file missing username");
            }
        }
    }

    return Status;
}

long AadPLoginInformation::RetrievePort(const RWCString& IniFileName, AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;
    if (pIControlBlock != NULL )
    {

        static const int MAX_PORTLEN = 300;
        char szPort[MAX_PORTLEN] ;

		long Length = GetPrivateProfileString(  "ADMIN_LOGIN",
                                                "PORT",
                                                "",
                                                szPort,
                                                sizeof(szPort)-1,
                                                (char *)(const char *)IniFileName ) ;
        if ( Length > 0 )
        {
            m_Port = atol( szPort );
            Status = BC_NO_ERRORS;

            #ifdef _DEBUG
            cout << "Port in bc.ini is -- " << m_Port << endl;
            #endif
        }
        else
        {
            Status = BC_INI_HOSED;

            cout << "bc.ini file is missing the database Port" << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
               cout << "AadPLoginInformation::RetrievePort() - ControlBlockTran invalid" << endl;
            }
            else
            {
               spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                               MSG_BC_INVALID_VALUE,
                                               Status,
                                               "AadLoginInformation::RetrievePort - GetProfileString failed, bc.ini file missing username");
            }
        }
    }

    return Status;
}

// MLC 06/25/01 end - retrieve SID, Port, and IPAddress from server

BOOL AadPLoginInformation::InformationIsEncrypted(const RWCString& IniFileName)
{
    long sectionPos     = -1;
    static const int MAX_KEYFILELEN = 80;
    char szKeyFileName[MAX_KEYFILELEN] ;

     long Length = GetPrivateProfileString( "ENCRYPTION",
                                            m_pOracleDatabaseIniKeyName,
                                            "",
                                            szKeyFileName,
                                            sizeof(szKeyFileName)-1,
                                            (char *)(const char *)IniFileName) ;
    if ( Length > 0 )
    {
        return TRUE;
    }
    else
    {
        cout << m_pOracleDatabaseIniKeyName << " not found" << endl;
        return FALSE;
    }
}

BOOL AadPLoginInformation::EncryptCommunications(const RWCString& IniFileName)
{
    long sectionPos     = -1;
    static const int MAX_KEYFILELEN = 80;
    char szKeyFileName[MAX_KEYFILELEN];

    long Length = GetPrivateProfileString( "ENCRYPTION",
                                            m_pCommunicationsIniKeyName,
                                            "",
                                            szKeyFileName,
                                            sizeof(szKeyFileName)-1,
                                            (char *)(const char *)IniFileName) ;

    if ( Length > 0 )
    {
        return TRUE;
    }
    else
    {
        cout << m_pCommunicationsIniKeyName << " not found" << endl;
        return FALSE;
    }
}

long AadPLoginInformation::DecipherInformation(AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if (pIControlBlock != NULL )
    {
        AbcIPEncryption *pIPEncryption;
        HRESULT hresult = AbcCoCreateInstance(CLSID_AbcPEncryption,                                             NULL,
                                              CLSCTX_INPROC_SERVER,
                                              IID_IAbcIPEncryption,
                                              (LPVOID*)& pIPEncryption);

        if (SUCCEEDED(hresult))
        {

            Status = DecipherPassword( pIPEncryption, pIControlBlock );

            if (Status == BC_NO_ERRORS)
            {
                Status = DecipherLogin( pIPEncryption, pIControlBlock );
            }


            pIPEncryption->Release();
        }
        else
        {
            cout << "Unable to create Encryption object" << endl;

            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
                cout << "DecipherInformation() - ControlBlockTran invalid" << endl;
            }
            else
            {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                          MSG_BC_INTERFACE_CREATE_FAILED,
                                          BC_FATAL, "AadLoginInformation::Cipher - Unable to create Encryption object");
            }
            Status = BC_FATAL;
        }
    }
    return Status;
}

long AadPLoginInformation::DecipherPassword(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if (pIPEncryption != NULL && pIControlBlock != NULL )
    {
        char Password[300];
        char *pPassword = (char *)Password;
        strcpy(Password, m_Password);

        RWCString IniKeyName( m_pOracleDatabaseIniKeyName );
        Status = pIPEncryption->DecipherString( IniKeyName,
                                                &pPassword,
                                                pIControlBlock);

        if (Status == BC_NO_ERRORS)
        {
            m_Password = Password;
        }
        else
        {
            cout << "Decipher failed on password; returned " << Status << endl;

            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
                cout << "DecipherPassword() - ControlBlockTran invalid" << endl;
            }
            else
            {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                          MSG_BC_INTERFACE_CREATE_FAILED,
                                          Status, "AadLoginInformation::Decipher - DecipherString() failed on password");
            }
        }

    }

   return Status;
}

long AadPLoginInformation::DecipherLogin(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if ( pIPEncryption != NULL && pIControlBlock != NULL )
    {
        char Login[300];
        char *pLogin = (char *)Login;
        strcpy(Login, m_Login);

        RWCString IniKeyName( m_pOracleDatabaseIniKeyName );
        Status = pIPEncryption->DecipherString( IniKeyName,
                                                &pLogin,
                                                pIControlBlock);

        if (Status == 0)
        {
            m_Login = Login;
        }
        else
        {
            cout << "Decipher failed on Login; returned " << Status << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
                cout << "DecipherLogin() - ControlBlockTran invalid" << endl;
            }
            else
            {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                            MSG_BC_UNABLE_TO_COMPLETE_FUNCTION,
                                            Status, "AadLoginInformation::Decipher - DecipherString() failed on login");
            }
        }
    }

    return Status;
}

long AadPLoginInformation::CipherInformation(AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if (pIControlBlock != NULL )
    {
        AbcIPEncryption *pIPEncryption;
        HRESULT hresult = AbcCoCreateInstance(CLSID_AbcPEncryption,                                             NULL,
                                              CLSCTX_INPROC_SERVER,
                                              IID_IAbcIPEncryption,
                                              (LPVOID*)& pIPEncryption);

        if (SUCCEEDED(hresult))
        {
            Status = CipherPassword( pIPEncryption, pIControlBlock );

            if (Status == BC_NO_ERRORS)
            {
                Status = CipherLogin( pIPEncryption, pIControlBlock );
            }

            pIPEncryption->Release();
        }
        else
        {
            cout << "Unable to create Encryption object" << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
                cout << "CipherInformation() - ControlBlockTran invalid" << endl;
            }
            else
            {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                          MSG_BC_INTERFACE_CREATE_FAILED,
                                          BC_FATAL, "AadLoginInformation::Cipher - Unable to create Encryption object");
            }
            Status = BC_FATAL;
        }

    }

    return Status;
}

long AadPLoginInformation::CipherPassword(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if ( pIPEncryption != NULL && pIControlBlock != NULL )
    {
        char Password[300];
        char *pPassword = (char *)Password;
        strcpy(Password, m_Password.data());

        RWCString IniKeyName( m_pCommunicationsIniKeyName );
        Status = pIPEncryption->CipherString( IniKeyName,
                                              &pPassword,
                                              pIControlBlock);

        if (Status == BC_NO_ERRORS)
        {
            m_Password = pPassword;
        }
        else
        {
            cout << "Cipher failed on m_Password; returned " << Status << endl;
            AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
            if ( !spControlBlockTran )
            {
                cout << "CipherPassword() - ControlBlockTran invalid" << endl;
            }
            else
            {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                                MSG_BC_UNABLE_TO_COMPLETE_FUNCTION,
                                                Status,
                                               "AadLoginInformation::Cipher - CipherString() failed on password");
            }
        }
    }

    return Status;
}

long AadPLoginInformation::CipherLogin(AbcIPEncryption* pIPEncryption , AbcIControlBlock* pIControlBlock)
{
    long Status = BC_FATAL;

    if ( pIPEncryption != NULL && pIControlBlock != NULL )
    {
       char Login[300];
       char *pLogin = (char *)Login;
       strcpy(Login, m_Login.data());

       RWCString IniKeyName( m_pCommunicationsIniKeyName );
       Status = pIPEncryption->CipherString( IniKeyName,
                                             &pLogin,
                                             pIControlBlock);

       if (Status == BC_NO_ERRORS)
       {
           m_Login = pLogin;
       }
       else
       {
           cout << "Cipher failed on Login; returned " << Status << endl;
           AbcIPControlBlockTranSp spControlBlockTran( pIControlBlock );
           if ( !spControlBlockTran )
           {
               cout << "CipherLogin() - ControlBlockTran invalid" << endl;
           }
           else
           {
                spControlBlockTran->AddMessage(BUSINESS_COMPONENT,
                                                MSG_BC_UNABLE_TO_COMPLETE_FUNCTION,
                                                Status,
                                               "AadLoginInformation::Cipher - CipherString() failed on Login");
           }
       }
    }

    return Status;
}


  //## end AadPLoginInformation%37793EF6000C.declarations
//## begin module%377CDA3101B4.epilog preserve=yes
//## end module%377CDA3101B4.epilog
