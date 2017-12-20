#ifndef __CONTROL_BLOCK_SUPPORT_H__

#define __CONTROL_BLOCK_SUPPORT_H__

#include "bcIControlBlock.h"
#include "bcIPControlBlockTran.h"
#include "bcIPControlBlockAdmin.h"

AbcIControlBlock* SetControlBlock( char* pHostLogonId, 
                                   char* pUserID, 
                                   char* pProcessingCenterID,  
                                   char* pDeliveryChannelID );       

#endif
