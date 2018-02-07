/********************************************************************
   SYSTEMATICS INFORMATION SERVICES, INC

   Archive = 
   $Archive:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/apptbl.cpp-arc  $
   Workfile = $Workfile:   apptbl.cpp  $
   Revision = $Revision:   1.1  $
   Check-In Date = $Date:   02 May 2002 14:10:10  $
   Time of Last Modification = 
   $Modtime:   02 May 2002 14:08:20  $

   THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG TO SYSTEMATICS
   INFORMATION SERVICES, INC. AND IS LICENSED BY AN AGREEMENT.  ANY
   UNATHORIZED ACCESS, USE, DUPLICATION OR DISCLOSURE IS UNLAWFUL.

   COPYRIGHT SYSTEMATICS INFORMATION SERVICES, INC.
   1993, 1994 ALL RIGHTS RESERVED.

*********************************************************************/

#include <stdio.h>
#include <string.h>
#include <fstream.h>
#include "apptbl.h"
tbl appTbl[] = { {"IM", "50", 10}, 
                 {"ST", "60", 14},
                 {"AC", "05", 14},
                 {"AL", "10", 14},
                 {"CC", "35", 10},
                 {"DC", "75", 16},  /* TMB Debit Card    */
                 {"LB", "15", 16},  /* TMB Loan Bills    */
                 {"OT", "85", 16},  /* TMB Others        */
                 {"TF", "20", 16},  /* TMB Trade Finance */
                 {"TP", "30", 16},  /* TMB Treasury      */
        /*         {"IC", "25", 12},  by RLD 17July2002 TMB */
        /*         {"XL", "50", 23},  by RLD 17July2002 TMB */
        /*         {"RE", "20", 10},  by RLD 17July2002 TMB */
        /*         {"RF", "55", 19},  by RLD 17July2002 TMB */
                 {"","",-1}  };

//////////////////////////////////////////////////////////
// findMatch - returns a number equivalent of the
// application in the second argument
// Parameters: szAppID - the application id
//             szCode - the number equivalent of the appid
//             nAcctNumLen - the acct number length
//////////////////////////////////////////////////////////
int findMatch(char const * szAppID, char* szCode, int& nAcctNumLen)
{
   int i=0;

   while(appTbl[i].length != -1)
   {
      if (strcmp(appTbl[i].appid, szAppID) == 0)
      {
         strcpy(szCode, appTbl[i].code);
         nAcctNumLen = appTbl[i].length;
         return(1);
      }
      else
         i++;
   }

   //fprintf(stdout,"INSIDE APPTBL.CPP : NO MATCH FOUND-%s-\n", szAppID);
   cout << "INSIDE APPTBL.CPP : NO MATCH FOUND -" << szAppID << "-" << endl;

   return (0);
}

