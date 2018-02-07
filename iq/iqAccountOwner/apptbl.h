/********************************************************************
   SYSTEMATICS INFORMATION SERVICES, INC

   Archive = $Archive:   /u02/pvcsarch/tmb804/archives/develop/iq/iqAccountOwner/apptbl.h-arc  $
   Workfile = $Workfile:   apptbl.h  $
   Revision = $Revision:   1.0  $
   Check-In Date = $Date:   13 Jun 2002 10:17:22  $
   Time of Last Modification = $Modtime:   08 Apr 2000 04:42:36  $

   THIS PROGRAM CONTAINS TRADE SECRETS THAT BELONG TO SYSTEMATICS
   INFORMATION SERVICES, INC. AND IS LICENSED BY AN AGREEMENT.  ANY
   UNATHORIZED ACCESS, USE, DUPLICATION OR DISCLOSURE IS UNLAWFUL.

   COPYRIGHT SYSTEMATICS INFORMATION SERVICES, INC.
   1993, 1994 ALL RIGHTS RESERVED.

*********************************************************************/
#ifndef __APPTBL_H__
#define __APPTBL_H__



struct tbl {
   char * appid;
   char * code;
   int    length;
};


int extern findMatch(char const *, char *, int&);
extern tbl appTbl[];
#endif
