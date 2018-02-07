Attribute VB_Name = "modDLoadDatFrDisk"

Option Explicit

'TO DO:
'Define labels starting from 100
'Define information string literals starting from 300
'Define error string literals starting from 500

Public Enum eResourceStrings
   tpTabCompanySearch = 101
   tpTabDataValidation = 102
   tpTabJournalLogs = 103
   tpSelectCompanySalaryFile = 201
   tpCompanyCode = 202
   tpCompanySubCode = 203
   tpCompanyName = 204
   tpCompanySalaryFile = 205
   tpValidate = 206
   tpProcessResult = 207
   tpLoad = 208
   tpJournalLogs = 211
   tpFaultRecord = 212
   tpLogType = 213
   tpLogDate = 214
   tpLogDescription = 215
   tpFaultRecordNo = 216
   tpFaultData = 217
   tpEffectiveDate = 218
   
   tpTransactionCaption = 300    'Transaction Caption
   tpTotalItems = 301
   tpTotalAmount = 302
   tpDepositItems = 303
   tpDepositAmount = 304
   tpDeductItems = 305
   tpDeductAmount = 306
   tpOwnerBranch = 307
   
   tpValidateSuccess = 321
   tpValidateFailure = 322
   
   '====================================
   tpNoOfDRTransaction = 323
   tpTotalDRAmount = 324
   tpNoOfCRTransaction = 325
   tpTotalCRAmount = 326
   tpNoOfRejectDRTransaction = 327
   tpTotalRejectDRAmount = 328
   tpNoOfRejectcRTransaction = 329
   tpTotalRejectcRAmount = 330
   '====================================
   tpErrLoadResource = 500       'Error in loading resources
   tpErrFileNotFound = 901
End Enum

Public Type CompanySalary160_Header
   RecordType  As String * 1
   SequenceNumber  As String * 6
   BankCode  As String * 3
   CompanyAccountNo  As String * 12
   CompanyName  As String * 40
   PostDate  As String * 6
   Spare1  As String * 40
   SubCompanyCode  As String * 2
   CompanyID As String * 4
   tmbFlag As String * 6
   Spare2 As String * 40
End Type

Public Type CompanySalary160_Detail
   RecordType  As String * 1
   SequenceNumber  As String * 6
   BankCode  As String * 3
   AccountNumber   As String * 12
   TransactionCode   As String * 1
   Amount   As String * 12
   ServiceType  As String * 2
   status  As String * 1
   ReferenceArea1  As String * 20
   InserviceDate  As String * 6
   CompanyCode  As String * 4
   HomeBranch As String * 3
   ReferenceArea2 As String * 20
   tmbFlag As String * 6
   CompanyCode2 As String * 4
   SubCompanyCode As String * 2
   spare As String * 14
   Name As String * 35
   TellerID As String * 8
End Type


Public Type CompanySalary160_End
   RecordType  As String * 1
   SequenceNumber  As String * 6
   BankCode  As String * 3
   CompanyAccountNo  As String * 12
   NoOf_DR_Transaction As String * 7
   Total_DR_Amount As String * 15
   NoOf_CR_Transaction As String * 7
   Total_CR_Amount As String * 15
   NoOfReject_DR_Transaction As String * 7
   TotalReject_DR_Amount As String * 15
   NoOfReject_CR_Transaction As String * 7
   TotalReject_CR_Amount As String * 15
   CompanyID As String * 4
   tmbFlag As String * 6
   SubCompanyCode As String * 2
   spare As String * 38
End Type



Public Type CompanySalaryRecord
   CompanyCode As String * 4
   TransactionType As String * 2
   AccountNumber As String * 10
   HomeBranch As String * 3
   EmployeeNumber As String * 7
   RecordCode As String * 1
   Amount As String * 12
   ItemNumber As String * 2
End Type

Public Type AccoutRecord
   AccountNumber As String
   ItemNo As Integer
End Type

Public Enum eJournalLogType
   INFORMATION_LOG = 1
   WARNING_LOG = 2
   ERROR_LOG = 3
End Enum

Public Enum eDatabaseProcessing
   NONE_PROCESS = 0
   RETRIEVE_COMPANY = 1
   DELETE_SALARY = 2
   ADD_SALARY = 3
End Enum

Public Const P_TransactionCode_Debit    As String = "D"
Public Const P_TransactionCode_Credit    As String = "C"
Public Const P_TransactionCode_RejectDebit    As String = "E"
Public Const P_TransactionCode_RejectCredit    As String = "F"
Public IS_First_Record_Of_Data As Boolean
Public IS_Last_Record_Of_Data As Boolean
Public Const Divide100ForDicimalPoint As Integer = 100
Public StrPath As String




Public Function FileExist(ByVal fileName As String) As Boolean
   Dim fso, filFile

   On Error Resume Next
   
   Set fso = CreateObject("Scripting.FileSystemObject")
   Set filFile = fso.GetFile(fileName)
   If Err.Number <> 0 Then
      FileExist = False
   Else
      FileExist = True
   End If
End Function

Public Function IsNumericStr(ByVal S As String) As Boolean
   Dim i As Integer
   
   IsNumericStr = True
   
   S = Trim(S)
   For i = 1 To Len(S)
      If Asc(Mid(S, i, 1)) < 48 Or Asc(Mid(S, i, 1)) > 57 Then
         IsNumericStr = False
         Exit For
      End If
   Next i
End Function

