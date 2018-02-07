#include <bcObjBase.h>
#include <bcInitGuid.h>

// required for all servers
#include "bcMwServicesGuid.h"

// define the clsid for our objects
#include "iqSecureFundingGuid.h"

// includes from other shared libraries
#include "bcCommonGuid.h"


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

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllRegisterServer(void)
{
	//COleObjectFactory::UpdateRegistryAll();
    AbcClassFactoryMgr::RegisterServer();
	return S_OK;
}

// by exporting DllRegisterServer, you can use regsvr.exe
STDAPI DllUnRegisterServer(void)
{
	//COleObjectFactory::UpdateRegistryAll();
    AbcClassFactoryMgr::UnregisterServer();
	return S_OK;
}

