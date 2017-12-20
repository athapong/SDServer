
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <atmi.h>
#include <userlog.h>
#include <rw/db/db.h>
#include <rw/db/dbmgr.h>

#include "bcObjBase.h"         // Xplatform header file

#include "bcCommonGuid.h"      
#include "bcMwServicesGuid.h"  
#include "bcErrors.h"

// Control block information
#include "bcIControlBlock.h"
#include "bcIPControlBlockTran.h"
#include "bcIPControlBlockAdmin.h"
#include "bcIMessage.h"

// includes from other shared libraries
#include "bcCommonGuid.h"
//#include "bcServicingGuid.h"
                     
#include "ControlBlockSupport.h"
#include "twSupport.h"
 
AbcIControlBlock* SetControlBlock( char* pHostLogonId, 
                                   char* pUserID, 
                                   char* pProcessingCenterId,  
                                   char* pDeliveryChannelId )       
{
    AbcIPControlBlockAdminSp spIControlBlockAdmin;
    AbcIControlBlockSp spIControlBlock;

    HRESULT hresult = spIControlBlock.CreateInstance(CLSID_AbcPControlBlock, NULL, CLSCTX_INPROC_SERVER );    
    
    if (FAILED(hresult))
    {
        return NULL;
    }

    spIControlBlockAdmin = spIControlBlock;
    
    if ( spIControlBlockAdmin->ConnectToDatabase( "bc.ini" ) == FALSE )
    {
        return NULL;
    }
                   
    spIControlBlockAdmin->HostLogonId( pHostLogonId );
    
    if (!FAILED(hresult))
    {
        AddUserParam( spIControlBlock, "UserID", pUserID );
        AddUserParam( spIControlBlock, "ProcessingCenterId", pProcessingCenterId );
        AddUserParam( spIControlBlock, "DeliveryChannelId", pDeliveryChannelId );
    }
    
    AbcIControlBlock *pIControlBlock = spIControlBlock;
    pIControlBlock->AddRef();

    return pIControlBlock;
}
