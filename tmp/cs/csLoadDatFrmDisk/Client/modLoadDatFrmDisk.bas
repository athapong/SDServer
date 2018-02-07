Attribute VB_Name = "modLoadDatFrmDisk"

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
   
   tpErrLoadResource = 500       'Error in loading resources
   tpErrFileNotFound = 901
End Enum

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

Public Function FileExist(ByVal FileName As String) As Boolean
   Dim fso, filFile

   On Error Resume Next
   
   Set fso = CreateObject("Scripting.FileSystemObject")
   Set filFile = fso.GetFile(FileName)
   If Err.Number <> 0 Then
      FileExist = False
   Else
      FileExist = True
   End If
End Function

Public Function IsNumericStr(ByVal s As String) As Boolean
   Dim i As Integer
   
   IsNumericStr = True
   
   s = Trim(s)
   For i = 1 To Len(s)
      If Asc(Mid(s, i, 1)) < 48 Or Asc(Mid(s, i, 1)) > 57 Then
         IsNumericStr = False
         Exit For
      End If
   Next i
End Function

