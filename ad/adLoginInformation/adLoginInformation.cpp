
#include <bcObjBase.h>
#include <bcInitGuid.h> // Cause DEFINE_GUID to actually define storage

// Dependent guid.h files go here
#include "bcMwServicesGuid.h"
#include "bcCommonGuid.h"

#include "adLoginInformationGuid.h"

//=======================================================================
// Well known entry point to allow Com to query this server and see
// if is OK to unload
//=======================================================================
STDAPI 
DllCanUnloadNow(void)
{
  HRESULT hresult;
  hresult = AbcClassFactoryMgr::CanUnloadNow();
  return hresult;
}


//=======================================================================
// Well known entry point to allow Com to ask this object to create
// a class factory for the associated Com Class.
//=======================================================================
STDAPI
DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID FAR*ppv)
{
  HRESULT hresult;

  hresult = AbcClassFactoryMgr::GetClassObject(rclsid, riid, ppv);
  return hresult;
}

STDAPI DllRegisterServer(void)
{
    return AbcClassFactoryMgr::RegisterServer();
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllUnRegisterServer(void)
{
   return AbcClassFactoryMgr::UnregisterServer();
}



