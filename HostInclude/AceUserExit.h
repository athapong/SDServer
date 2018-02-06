
// Service Delivery specific additions Included by generated ACE headers.

public:

#define HOST_ABEND_RETURN_CODE 900
#define HOST_TIME_OUT_RETURN_CODE -2
//Begin LN 15-June-2004 Display error message to user
#define TRANSACTION_TIMEOUT_RETURN_CODE 745
#define ACE_SERVER_UNAVAILABLE_RETURN_CODE -100
#define ACE_OUT_OF_MEMORY_RETURN_CODE -700
#define SESSION_OPEN_FAILED_RETURN_CODE 1
#define SERVER_UNAVAILABLE_RETURN_CODE 100
#define SESSION_TIMEOUT_RETURN_CODE 212
#define SERVER_PAUSED_RETURN_CODE 215
#define SESSION_NOT_FOUND_RETURN_CODE 211
#define HOST_COMMUNICATION_TIMEOUT_RETURN_CODE 111
#define LU_UNAVAILABLE_RETURN_CODE 221
#define LU_UNAVAILABLE_2_RETURN_CODE 216
#define LU_UNAVAILABLE_IN_SESSION_RETURN_CODE 213
#define STANDARD_HOST_ERROR_RETURN_CODE 10
//End LN 15-June-2004 Display error message to user

//Remote TP Names
#define REMOTETP    "REMOTETP"
#define REMOTETP_ST "REMOTETP_ST"
#define REMOTETP_IM "REMOTETP_IM"
#define REMOTETP_TW "REMOTETP_TW"
#define REMOTETP_SD "REMOTETP_SD"
#define REMOTETP_PC "REMOTETP_PC"
#define REMOTETP_SC "REMOTETP_SC"
#define REMOTETP_AM "REMOTETP_AM"
#define REMOTETP_CB "REMOTETP_CB"

// *********************************************************************************************
long Execute (AbcIControlBlock* pIControlBlock)
{
    long NativeExecuteReturnCode = Execute();
    long Status = RetrieveHostErrors( NativeExecuteReturnCode, pIControlBlock );

    return Status;
}

// *********************************************************************************************
long SessionExecute (AbcIControlBlock* pIControlBlock)
{
    long NativeExecuteReturnCode = SessionExecute();
    long Status = RetrieveHostErrors( NativeExecuteReturnCode, pIControlBlock );

    return Status;
}

// *********************************************************************************************
bool DuplicateMdaMsgPriorToCurrentIndexMdaMsg(int CurrentIndex)
{
    bool DuplicateMdaMsg = false;

	long MaxNumberMessages = CTSMDA.MdaOccurrenceInProc();

    if ( MaxNumberMessages > CTSMDA.MdaMaxPossibleMsgs() )
    {
       MaxNumberMessages = CTSMDA.MdaMaxPossibleMsgs();
    }
    
    if ( ( CurrentIndex >= 1 ) && ( CurrentIndex < MaxNumberMessages ) )
	{
		RWCString AccountKey = CTSMDA.CMdaTrmMsg.CMdaMsg[ CurrentIndex ].MdaAcctKey();
		RWCString MessageCode = CTSMDA.CMdaTrmMsg.CMdaMsg[ CurrentIndex ].MdaMessageCode();

		AccountKey.strip();
		MessageCode.strip();

		for ( int Index = 0; Index < CurrentIndex; Index++)
		{
			RWCString AccountKeyToCompare = CTSMDA.CMdaTrmMsg.CMdaMsg[ Index ].MdaAcctKey();
			RWCString MessageCodeToCompare = CTSMDA.CMdaTrmMsg.CMdaMsg[ Index ].MdaMessageCode();

			AccountKeyToCompare.strip();
			MessageCodeToCompare.strip();

			if ( ( AccountKey == AccountKeyToCompare ) && ( MessageCode == MessageCodeToCompare ) )
			{
				DuplicateMdaMsg = true;
				break;
			}
		}
	}

	return DuplicateMdaMsg;
}

void DumpMessages( AbcIControlBlock* pIControlBlock)
{
   AbcIMessagesSp pIMessages = pIControlBlock->Messages();
   int Count = pIMessages->MessageList().entries();

   cout << "\n*** AceUserExit.h - HOST TRANSACTION FAILED ***" << endl;
   for (int i = 0; i < Count; i++)
   {
      AbcIMessageSp pIMessage = pIMessages->MessageList().at(i);
      cout << "Message = " << " " << pIMessage->MessageNumber() << " " << pIMessage->Severity() << " " << pIMessage->Description() << endl;
      cout << "\tSymbolic Parameter3: " << pIMessage->SymbolicParameter1() << endl;
   }
   cout << "*******************************\n" << endl;
}

// *********************************************************************************************

void SetTranStatus( RWCString NextDay = "N",
                    RWCString StoreAndForward = "N",
                    RWCString PassbookRebid = "N",
                    RWCString TellerOverride = "N",
                    RWCString SupervisorOverride = "N",
                    RWCString Correction = "N",
                    RWCString TrainingMode = "N",
                    RWCString InquiryRebid = "N",
                    RWCString PhysicalLocation = ""
                  )
{
  CTSHeader.LandFill0( PhysicalLocation );

   if ( CTSHeader.OverrideTellerId() == "" && CTSHeader.TranSeq() == "" &&
       CTSHeader.TranTime() == "" && PhysicalLocation == "" &&
       StoreAndForward == "N" && PassbookRebid == "N" &&
       TellerOverride == "N" && SupervisorOverride == "N" &&
       Correction == "N" && NextDay == "N" &&
       TrainingMode == "N" && InquiryRebid == "N")
   {
      CTSHeader.TranStatus(0, 0);
      CTSHeader.TranStatus(0, 1);
      CTSHeader.TranStatus(0, 2);
   }
   else
   {
       // byte 0
       int nStoreAndForward = 0x08;
       int nPassbookRebid = 0x04;
       int nTellerOverride = 0x02;
       int nSupervisorOverride = 0x01;

       // byte 1 of bit flags
       int nCorrection = 0x08;
       int nNextDay = 0x04;
       int nTraining = 0x02;

       // byte 2 of the bit flags
       int nInquiryRebid = 0x08;

       short Byte0 = 0xf0;        // turn on high order bits
       short Byte1 = 0xf0;        // turn on high order bits
       short Byte2 = 0xf0;        // turn on high order bits

       if (toUpper(StoreAndForward) == "Y")
           Byte0 |= nStoreAndForward;
       if (toUpper(PassbookRebid) == "Y")
           Byte0 |= nPassbookRebid;
       if (toUpper(TellerOverride) == "Y")
           Byte0 |= nTellerOverride;
       if (toUpper(SupervisorOverride) == "Y")
           Byte0 |= nSupervisorOverride;

       if (toUpper(Correction) == "Y")
           Byte1 |= nCorrection;
       if (toUpper(NextDay) == "Y")
           Byte1 |= nNextDay;
       if (toUpper(TrainingMode) == "Y")
           Byte1 |= nTraining;

       if (toUpper(InquiryRebid) == "Y")
           Byte2 |= nInquiryRebid;

       CTSHeader.TranStatus( Byte0, 0 );
       CTSHeader.TranStatus( Byte1, 1 );
       CTSHeader.TranStatus( Byte1, 2 );

       //cout << "TranStatus[0] = " << CTSHeader.TranStatus(0) << endl;
       //cout << "TranStatus[1] = " << CTSHeader.TranStatus(1) << endl;
       //cout << "TranStatus[2] = " << CTSHeader.TranStatus(2) << endl;
   }
}

// *********************************************************************************************

void GetTranStatus( RWCString& TellerOverride,
                    RWCString& SupervisorOverride,
                    RWCString& PassbookRebid
                  )
{
        int OutputTellerOverride = 0x08;
        int OutputSupervisorOverride = 0x04;
        int OutputPassbookRebid = 0x02;
        int OutputFatalError = 0x01;

        if (CTSHeader.TranStatus(0) & OutputTellerOverride)
            TellerOverride = "Y";

        if (CTSHeader.TranStatus(0) & OutputSupervisorOverride)
            SupervisorOverride = "Y";

        if (CTSHeader.TranStatus(0) & OutputPassbookRebid)
            PassbookRebid = "Y";
}

// *********************************************************************************************

RWCString GetRemoteTpName( const RWCString& RemoteTP )
{
   int         ParameterLength;
   char        szRemoteTPName[80] =  "";
   char        szRemoteTP[80];
   const char  INIFile[] =           "bc.ini";
   const char  SectionName[] =       "LU6.2";

   strcpy( szRemoteTP, RemoteTP.data() );

   if ( !RemoteTP.isNull() )
   {
      ParameterLength = GetPrivateProfileString( (char*)SectionName, szRemoteTP, "", szRemoteTPName, sizeof(szRemoteTPName)-1, (char*)INIFile );

	  if ( ParameterLength == 0 )
	  {
		 cout << "Unable to find a \"" << RemoteTP << "\" entry in the ["
			  << SectionName << "] section of the " << INIFile << " file" << endl;
	  }
   }

   return szRemoteTPName;
}

// *********************************************************************************************

EXPORTDECL RWCString StripComp3(RWCString SrcString)
{
    SrcString = SrcString.strip( RWCString::both );

    int Sign=0;
    if (SrcString.length() > 1)
    {
        if (SrcString.data()[0] == '-')
            Sign = 1;

        SrcString = SrcString(1, SrcString.length() - 1);
        SrcString = SrcString.strip(RWCString::leading, '0');

        if (Sign)
            SrcString = "-" + SrcString;
    }
    return SrcString;
}

// *********************************************************************************************

long RetrieveHostErrors(const long& HostReturnCode, AbcIControlBlock* pIControlBlock)
{
	cout << "AceUserExit.h - RetrieveHostErrors" << endl;
	cout << "AceUserExit.h - HostReturnCode: " << HostReturnCode << endl;
   long Status = BC_NO_ERRORS;

   AbcIMessagesSp pIMessages = pIControlBlock->Messages();
   AbcIMessageTableKeySp pIMessageTableKey;
   AbcIMessageTableSp pIMessageTable;

   RWCString ProgId, Dag, FieldId, Message, ErrorCode, SeverityLvl, SeverityCode;
   RWCString MessageCode, LastMessageCode, ApplicationID, MessageNumber, RequestingComponent;
   RWCString AcctKey;

   unsigned short MessageType = 0;
   AbcIMessageSp pIMessage;
   HRESULT hresult;
   RWCString Description;

   //Begin LN 15-June-2004 Display error message to user
   //if ( HostReturnCode == HOST_ABEND_RETURN_CODE )
   //{
   //    pIMessages->Add("SD", BC_HOST_ABEND, BC_FATAL, "HOST ABEND" );
   //    Status = BC_FATAL;
   //}
   //else if ( HostReturnCode == HOST_TIME_OUT_RETURN_CODE )
   //{
   //   pIMessages->Add("SD", SD_HOST_TIME_OUT, BC_FATAL, "");
   //   Status = BC_FATAL;
   //}
   //else if ( HostReturnCode != 0 )
   //{
   //    pIMessages->Add("SD", TRANSACTION, BC_FATAL, "ACE System Error" );
   //    Status = BC_FATAL;
   //}
   if ( HostReturnCode != 0 )
   {   
       switch ( HostReturnCode )
       {
 	 case HOST_ABEND_RETURN_CODE:
 	 	cout << "Host Abend Code - Ping = " << HOST_ABEND_RETURN_CODE << endl;
		pIMessages->Add("SD", BC_HOST_ABEND, BC_FATAL, "HOST ABEND");
		break;
	 case HOST_TIME_OUT_RETURN_CODE:
		pIMessages->Add("SD", HOST_TIME_OUT_RETURN_CODE, BC_FATAL, "" );
		break;
	 case TRANSACTION_TIMEOUT_RETURN_CODE:
		pIMessages->Add("SD", TRANSACTION_TIMEOUT_RETURN_CODE, BC_FATAL, "Transaction Timeout" );
		break;
	 case ACE_SERVER_UNAVAILABLE_RETURN_CODE:
		pIMessages->Add("SD", ACE_SERVER_UNAVAILABLE_RETURN_CODE, BC_FATAL, "ACE Server Unavailable" );
	        break;
	 case ACE_OUT_OF_MEMORY_RETURN_CODE:
	        pIMessages->Add("SD", ACE_OUT_OF_MEMORY_RETURN_CODE, BC_FATAL, "ACE Out Of Memory" );
		break;
	 case SESSION_OPEN_FAILED_RETURN_CODE:
	        pIMessages->Add("SD", SESSION_OPEN_FAILED_RETURN_CODE, BC_FATAL, "Session Open Failed" );
		break;
	 case SERVER_UNAVAILABLE_RETURN_CODE:
		pIMessages->Add("SD", SERVER_UNAVAILABLE_RETURN_CODE, BC_FATAL, "Server Unavailble" );
		break;
	 case SESSION_TIMEOUT_RETURN_CODE:
	        pIMessages->Add("SD", SESSION_TIMEOUT_RETURN_CODE, BC_FATAL, "Session Timeout" );
	        break;
	 case SERVER_PAUSED_RETURN_CODE:
		pIMessages->Add("SD", SERVER_PAUSED_RETURN_CODE, BC_FATAL, "Server Paused" );
	        break;
	 case SESSION_NOT_FOUND_RETURN_CODE:
	        pIMessages->Add("SD", SESSION_NOT_FOUND_RETURN_CODE, BC_FATAL, "Session Not Found" );
		break;
	 case HOST_COMMUNICATION_TIMEOUT_RETURN_CODE:
		pIMessages->Add("SD", HOST_COMMUNICATION_TIMEOUT_RETURN_CODE, BC_FATAL, "Host Communication Timeout" );
	        break;
	 case LU_UNAVAILABLE_RETURN_CODE:
		pIMessages->Add("SD", LU_UNAVAILABLE_RETURN_CODE, BC_FATAL, "LU Unavailable" );
		break;
	 case LU_UNAVAILABLE_2_RETURN_CODE:
		pIMessages->Add("SD", LU_UNAVAILABLE_2_RETURN_CODE, BC_FATAL, "LU Unavailable2" );
	        break;
	 case LU_UNAVAILABLE_IN_SESSION_RETURN_CODE:
		pIMessages->Add("SD", LU_UNAVAILABLE_IN_SESSION_RETURN_CODE, BC_FATAL, "LU Unavailable In Session" );
	        break;
	 case STANDARD_HOST_ERROR_RETURN_CODE:
	        pIMessages->Add("SD", STANDARD_HOST_ERROR_RETURN_CODE, BC_FATAL, "Standard Host Error" );
	        break;
       }
       Status = BC_FATAL;
   }
   //End LN 15-June-2004 Display error message to user
   else
   {
       long MessageCount = CTSMDA.MdaOccurrenceInProc();

       if ( MessageCount > CTSMDA.MdaMaxPossibleMsgs() )
       {
           MessageCount = CTSMDA.MdaMaxPossibleMsgs();
           pIMessages->Add( "SD", BC_INFORMATIONAL, BC_INFORMATIONAL, "The host has returned more messages than allowed by the DAG" );
       }

       for ( short i = 0; i < MessageCount; i++ )
       {
           ApplicationID = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMessageCode();
           MessageCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMessageCode();

           if ( DuplicateMdaMsgPriorToCurrentIndexMdaMsg ( i ) )
           {
               continue;
           }

           if (MessageCode == "TS0449") //SIGNED ON
               continue;
           if (MessageCode == "ST4200") //Processing Complete
               continue;

           LastMessageCode = MessageCode;

           // RWCSubString will set the length of the destination RWCString to the size of the number
           // of characters we request to copy even though it sets the string itself empty (no spaces).
           // This later confuses oracle when we do the bcDMessageTable::Get and causes oracle to
           // issue a console error.  Doing this check here avoids setting up the RWCString incorrectly.
           //    --Michael Stanley
           if ( MessageCode.isNull() )
           {
               ApplicationID = RWCString("");
               MessageNumber = RWCString("");
           }
           else
           {
               ApplicationID = MessageCode(0,2);
               MessageNumber = MessageCode(2,4);
           }

           SeverityLvl = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaSeverityLvl();
           ErrorCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMessageCode();

           Message = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaVariable1();
           Message.strip() ;
           Message += CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaVariable2();
           Message.strip() ;

           AcctKey = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaAcctKey();
           AcctKey.strip();

           if (AcctKey != "")
           {
               //cout << "AccountKey in DHost = " << AcctKey << endl;
               Message += "~" + AcctKey + "~";
               Message.strip() ;
           }

           Dag = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaDag();
           ProgId = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaProgramId();
           FieldId = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaFieldId();
           SeverityCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMsgSeverityCode();
           RequestingComponent = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaProgramId();

           switch ( SeverityCode.data()[0] )
           {
               case 'A':
               case 'F':
               case 'E':
               case 'S':
               case 'O':
                   MessageType = BC_FATAL ;
                   pIMessages->MaxSeverity(BC_FATAL) ;
                   break;
               default:
                   if (pIMessages->MaxSeverity() < BC_INFORMATIONAL)
                       pIMessages->MaxSeverity(BC_INFORMATIONAL) ;
                       MessageType = BC_INFORMATIONAL ;
           }

           hresult = pIMessage.CreateInstance(CLSID_AbcPMessage, NULL, CLSCTX_INPROC_SERVER);
           pIMessage->ApplicationId( ApplicationID ) ;
           pIMessage->MessageNumber(atol(MessageNumber)) ;
           pIMessage->Severity(MessageType) ;
           pIMessage->ProcessInd(BC_MSG_PROCESSED) ;
           pIMessage->Description(Message) ;

           pIMessages->MessageList().append(pIMessage) ;
       }
   }

   pIMessages->ProcessMessages();
   Status = pIMessages->MaxSeverity();

   if ( Status == BC_FATAL )
   {
       DumpMessages( pIControlBlock );
   }

   return Status;
}

#ifdef SUPPORT_WV

long FillHostError( const long& HostReturnCode, CSSCODERec& ptr, const char * AppId )
{
   long Status = S_OK;

   char szSeverityLvl[3];
   char szErrorCode[8];
   char szMessage[52];

   //Begin LN 15-June-2004 Display error message to user
   //if ( HostReturnCode == HOST_ABEND_RETURN_CODE )
   //{
   //   ptr.FacilityCode = sdTSMDA;
   //   ptr.SeverityLevel = 99;
   //   ptr.MessageType   = "F";
   //   ptr.ErrorCode     = "ABEND1";
   //   ptr.ErrorMessage = "HOST ABEND";
   //   Status = ErrObjToRetCode( ptr );
   //}
   //else if ( HostReturnCode == HOST_TIME_OUT_RETURN_CODE )
   //{
   //   ptr.FacilityCode = SD_HOST_TIME_OUT;
   //   ptr.SeverityLevel = 99;
   //   ptr.MessageType = "F";
   //   ptr.ErrorCode = "Host Time-out";
   //   ptr.ErrorMessage = "Host transaction has timed out";
   //   Status = ErrObjToRetCode( ptr );
   //}
   //else if ( HostReturnCode != 0 )
   //{
   //   ptr.FacilityCode = TRANSACTION;
   //   ptr.SeverityLevel = 99;
   //   ptr.ErrorCode     = "ACE System Error";
   //   ptr.ErrorMessage = "ACE System Error";
   //   Status = ErrObjToRetCode( ptr );
   //}
   if ( HostReturnCode != 0 )
   {
      ptr.SeverityLevel = 99;
      ptr.MessageType = "F";
 
      switch ( HostReturnCode )
      {
	 case HOST_ABEND_RETURN_CODE:
	          ptr.FacilityCode = sdTSMDA;
	          ptr.ErrorCode    = "ABEND1";
	          ptr.ErrorMessage = "HOST ABEND";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case HOST_TIME_OUT_RETURN_CODE:
	          ptr.FacilityCode = SD_HOST_TIME_OUT;
	          ptr.ErrorCode    = "Host Timeout";
	          ptr.ErrorMessage = "Host transaction has timed out";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case TRANSACTION_TIMEOUT_RETURN_CODE:
	          ptr.FacilityCode = TRANSACTION_TIMEOUT_RETURN_CODE;
	          ptr.ErrorCode    = "Transaction Timeout";
	          ptr.ErrorMessage = "Transaction has timed out";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case ACE_SERVER_UNAVAILABLE_RETURN_CODE:
	          ptr.FacilityCode = ACE_SERVER_UNAVAILABLE_RETURN_CODE;
	          ptr.ErrorCode    = "ACE Server Unavailable";
	          ptr.ErrorMessage = "ACE Server Unavailable";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case ACE_OUT_OF_MEMORY_RETURN_CODE:
	          ptr.FacilityCode = ACE_OUT_OF_MEMORY_RETURN_CODE;
	          ptr.ErrorCode     = "ACE Out Of Memory";
	          ptr.ErrorMessage = "ACE Out Of Memory";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case SESSION_OPEN_FAILED_RETURN_CODE:
	          ptr.FacilityCode = SESSION_OPEN_FAILED_RETURN_CODE;
	          ptr.ErrorCode     = "Session Open Failed";
	          ptr.ErrorMessage = "Session Open Failed";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case SERVER_UNAVAILABLE_RETURN_CODE:
	          ptr.FacilityCode = SERVER_UNAVAILABLE_RETURN_CODE;
	          ptr.ErrorCode     = "Server Unavailable";
	          ptr.ErrorMessage = "Server Unavailable";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case SESSION_TIMEOUT_RETURN_CODE:
	          ptr.FacilityCode = SESSION_TIMEOUT_RETURN_CODE;
	          ptr.ErrorCode     = "Session Timeout";
	          ptr.ErrorMessage = "Session Timeout";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case SERVER_PAUSED_RETURN_CODE:
	          ptr.FacilityCode = SERVER_PAUSED_RETURN_CODE;
	          ptr.ErrorCode     = "Server Paused";
	          ptr.ErrorMessage = "Server Paused";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case SESSION_NOT_FOUND_RETURN_CODE:
	          ptr.FacilityCode = SESSION_NOT_FOUND_RETURN_CODE;
	          ptr.ErrorCode     = "Session Not Found";
	          ptr.ErrorMessage = "Session Not Found";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case HOST_COMMUNICATION_TIMEOUT_RETURN_CODE:
	          ptr.FacilityCode = HOST_COMMUNICATION_TIMEOUT_RETURN_CODE;
	          ptr.ErrorCode     = "Host Communication Timeout";
	          ptr.ErrorMessage = "Host Communication Timeout";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case LU_UNAVAILABLE_RETURN_CODE:
	          ptr.FacilityCode = LU_UNAVAILABLE_RETURN_CODE;
	          ptr.ErrorCode     = "LU Unavailable";
	          ptr.ErrorMessage = "LU Unavailable";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case LU_UNAVAILABLE_2_RETURN_CODE:
	          ptr.FacilityCode = LU_UNAVAILABLE_2_RETURN_CODE;
	          ptr.ErrorCode     = "LU Unavailable 2";
	          ptr.ErrorMessage = "LU Unavailable 2";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case LU_UNAVAILABLE_IN_SESSION_RETURN_CODE:
	          ptr.FacilityCode = LU_UNAVAILABLE_IN_SESSION_RETURN_CODE;
	          ptr.ErrorCode     = "LU Unavailable In Session";
	          ptr.ErrorMessage = "LU Unavailable In Session";
		  Status = ErrObjToRetCode( ptr );
		  break;
	 case STANDARD_HOST_ERROR_RETURN_CODE:
	          ptr.FacilityCode = STANDARD_HOST_ERROR_RETURN_CODE;
	          ptr.ErrorCode     = "Standard Host Error";
	          ptr.ErrorMessage = "Standard Host Error";
		  Status = ErrObjToRetCode( ptr );
		  break;
      }
   }
   //End LN 15-June-2004 Display error message to user   
   else
   {
      RWCString ProgId, Dag, FieldId, Message, ErrorCode, SeverityLvl, SeverityCode;
      unsigned short nOccurs = 0;

      ptr.FacilityCode = sdTSMDA ;
      ptr.AppId     = AppId;
      ptr.MdaMessageSeverityCode = "";
      ptr.MdaHiSeverityCode = CTSMDA.MdaHiSeverityCode();

      nOccurs = CTSMDA.MdaOccurrenceInProc();

      if ( nOccurs > CTSMDA.MdaMaxPossibleMsgs() )
      {
         nOccurs = CTSMDA.MdaMaxPossibleMsgs();
      }

      if ( nOccurs >= 1 )
      {
         for ( int i=0; i < nOccurs; i++ )
         {
            SeverityLvl = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaSeverityLvl();
            ErrorCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMessageCode();
            Message = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaVariable1() + CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaVariable2();
            Dag = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaDag();
            ProgId = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaProgramId();
            FieldId = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaFieldId();
            ErrorCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMessageCode();
            SeverityCode = CTSMDA.CMdaTrmMsg.CMdaMsg[i].MdaMsgSeverityCode();

            if ( ( SeverityCode == "A" ) ||
                 ( SeverityCode == "F" ) ||
                 ( SeverityCode == "E" ) )
            {
                ptr.MessageType = "F";
                ptr.SeverityLevel = atol(SeverityLvl.data());
                ptr.ErrorCode = ErrorCode;
                ptr.ErrorMessage = Message;
                ptr.MdaDag = Dag;
                ptr.MdaFieldId = FieldId;
                ptr.MdaMessageSeverityCode = SeverityCode;
                ptr.MdaProgramId = ProgId;
            }
            else
            {
                if (ptr.MdaMessageSeverityCode == "")
                {
                    ptr.MessageType = "I";
                    ptr.SeverityLevel = atol(SeverityLvl.data());
                    ptr.ErrorCode = ErrorCode;
                    ptr.ErrorMessage = Message;
                    ptr.MdaDag = Dag;
                    ptr.MdaFieldId = FieldId;
                    ptr.MdaMessageSeverityCode = SeverityCode;
                    ptr.MdaProgramId = ProgId;
                }
            }

            #ifdef SERVER_TRACE
               cout << "ProgId = " << ProgId << endl;
               cout << "Dag = " << Dag << endl;
               cout << "FieldId = " << FieldId << endl;
               cout << "ErrorCode = " << ErrorCode << endl;
               cout << "SeverityCode = " << SeverityCode << endl;
               cout << "Message = " << Message << endl;
            #endif
         }

         Status = ErrObjToRetCode( ptr );
      }
   }

   return Status;
}

int ErrorsOnTransaction( const char* pszApplID, long& lRetCode )
{
  int Error = FALSE;
  CSSCODERec aCSSCodeRec;
  lRetCode = FillHostError( lRetCode, aCSSCodeRec, pszApplID );

  if ( lRetCode != 0 )
  {
     Error = TRUE;
  }

  return Error;
}

#endif
