VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Payroll"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Member0" ,"Payrolls"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Attribute VB_Ext_KEY = "Member1" ,"Users"
'******************************************************************
'Description :  Payroll Class use for function decrypt payroll file 160 characters
'Add Date     :  08/12/2009
'******************************************************************

Option Explicit
'local variable(s) to hold property value(s)
Private mvarpayRollClientInfo As ClientInfo 'local copy
Private mvarPayrolls As Payrolls
Public Enum Month
    JANUARY = 1
    FEBUARY = 2
    MARCH = 3
    APRIL = 4
    MAY = 5
    JUNE = 6
    JULY = 7
    AUGUST = 8
    SEPTEMBER = 9
    OCTOBER = 10
    NOVEMBER = 11
    DECEMBER = 12
End Enum
'Private mvarUsers As Users
Private mvarcurYear As Integer 'local copy
Private mvarcurMonth As Month 'local copy
'local variable(s) to hold property value(s)
Private mvarbatchNo As Integer 'local copy
'local variable(s) to hold property value(s)
'Private mvarcurrentUser As TMBUser 'local copy
'local variable(s) to hold property value(s)
Private mvareffectiveDate As String  'local copy

Public exportedFiPath As String

Private savedFiPath As String
Private USERTYPE_USER As String



Public Property Let effectiveDate(ByVal vData As String)
'used when assigning a value to the property, on the left side of an assignment.
'Syntax: X.effectiveDate = 5
    mvareffectiveDate = vData
End Property

Public Property Get effectiveDate() As String
'used when retrieving value of a property, on the right side of an assignment.
'Syntax: Debug.Print X.effectiveDate
    effectiveDate = mvareffectiveDate
End Property

'Public Property Set currentUser(ByVal vData As TMBUser)
''used when assigning an Object to the property, on the left side of a Set statement.
''Syntax: Set x.currentUser = Form1
''    Set mvarcurrentUser = vData
'End Property
'
'
'Public Property Get currentUser() As TMBUser
''used when retrieving value of a property, on the right side of an assignment.
''Syntax: Debug.Print X.currentUser
' '   Set currentUser = mvarcurrentUser
'End Property

Public Property Let batchNo(ByVal vData As Integer)
'used when assigning a value to the property, on the left side of an assignment.
'Syntax: X.batchNo = 5
    mvarbatchNo = vData
End Property

Public Property Get batchNo() As Integer
'used when retrieving value of a property, on the right side of an assignment.
'Syntax: Debug.Print X.batchNo
    batchNo = mvarbatchNo
End Property

Public Property Let curMonth(ByVal vData As Month)
    mvarcurMonth = vData
End Property

Public Property Get curMonth() As Month
    curMonth = mvarcurMonth
End Property

Public Property Let curYear(ByVal vData As Integer)
    mvarcurYear = vData
End Property

Public Property Get curYear() As Integer
    curYear = mvarcurYear
End Property

Public Property Get fileName(Optional extention = "TMB") As String
    fileName = mvarcurMonth & "_" & mvarcurYear & "_" & padStringWith(CStr(mvarbatchNo), "0", 2, False) & "." & extention
End Property

Public Property Get expFileName(Optional extention = "ENC") As String
    expFileName = mvarpayRollClientInfo.CompanyCode & _
    padStringWith((Split(mvareffectiveDate, "/")(0)), "0", 2, False) & _
    padStringWith((Split(mvareffectiveDate, "/")(1)), "0", 2, False) & _
    padStringWith(Right((Split(mvareffectiveDate, "/")(2)), 2), "0", 2, False) & _
    padStringWith(CStr(mvarbatchNo), "0", 2, False) & "." & extention
End Property

Public Function Save(Optional path As String = "") As Boolean
    'just save only details
    Dim cnt As Integer
    Dim fiNum
    fiNum = FreeFile
    If path = "" Then path = savedFiPath

On Error Resume Next
    MkDir path ' create new folder if not exist
    Kill path & fileName
On Error GoTo fail:
    Open path & fileName For Random As fiNum Len = 160
    For cnt = 1 To Payrolls.Count
        Put #fiNum, , getPayrollStruct(cnt, cnt + 1)
    Next cnt
    Save = True
    GoTo succees
fail:
    MsgBox "Can't save Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    Save = False
succees:
On Error Resume Next
    Close fiNum
On Error GoTo 0
End Function

Private Function getHeader() As String
    Dim str As String
    Dim effDate As String
    effDate = padStringWith((Split(mvareffectiveDate, "/")(0)), "0", 2, False) & _
              padStringWith((Split(mvareffectiveDate, "/")(1)), "0", 2, False) & _
              padStringWith(Right((Split(mvareffectiveDate, "/")(2)), 2), "0", 2, False)

    str = "H"
    str = str & "000001"
    str = str & "011"
    str = str & padStringWith(Replace(payRollClientInfo.AccountNumber, "-", ""), "0", 12, False)
    str = str & padStringWith(payRollClientInfo.CompanyName, " ", 40)
    str = str & effDate
    str = str & String(40, " ")
    str = str & padStringWith(CStr(batchNo), "0", 2, False)
    str = str & padStringWith(payRollClientInfo.CompanyCode, "0", 4, False)
    str = str & padStringWith(payRollClientInfo.tmbFlag, " ", 6)
    str = str & String(40, " ")
    
    getHeader = str
End Function

Private Function getFooter(Optional id As String = "0") As String
    Dim str As String
    Dim cntDebit As Integer
    Dim cntCredit As Integer
    Dim debitAmt
    Dim creditAmt
    Dim cnt As Integer

    cntDebit = 0
    cntCredit = 0
    debitAmt = 0
    creditAmt = 0
    
    For cnt = 1 To objPayroll.Payrolls.Count
        If objPayroll.Payrolls(cnt).DebitCredit = "D" Then
            cntDebit = cntDebit + 1
            debitAmt = Round(debitAmt + objPayroll.Payrolls(cnt).Amount, 2)
        Else
            cntCredit = cntCredit + 1
            creditAmt = Round(creditAmt + objPayroll.Payrolls(cnt).Amount, 2)
        End If
    Next cnt
    
    str = "T"
    str = str & padStringWith(id, "0", 6, False)
    str = str & "011"
    str = str & padStringWith(Replace(payRollClientInfo.AccountNumber, "-", ""), "0", 12, False)
    str = str & padStringWith(CStr(cntDebit), "0", 7, False)
    str = str & padStringWith(CStr(debitAmt * 100), "0", 15, False)
    str = str & padStringWith(CStr(cntCredit), "0", 7, False)
    str = str & padStringWith(CStr(creditAmt * 100), "0", 15, False)
    
    str = str & padStringWith("0", "0", 7, False)
    str = str & padStringWith("0", "0", 15, False)
    str = str & padStringWith("0", "0", 7, False)
    str = str & padStringWith("0", "0", 15, False)

    str = str & padStringWith(payRollClientInfo.CompanyCode, "0", 4, False)
    str = str & padStringWith(payRollClientInfo.tmbFlag, " ", 6)
    str = str & padStringWith(CStr(batchNo), "0", 2, False)
    
    str = str & String(38, " ")
    
    getFooter = str
End Function

Public Function export(Optional path As String = "", Optional defFileName As Boolean = True, Optional encrypted As Boolean = True) As Boolean
    'just save only details
    Dim fiName As String
    If defFileName Then fiName = expFileName
    Dim cnt As Integer
    Dim fiNum
    fiNum = FreeFile
    If path = "" Then path = exportedFiPath
On Error Resume Next
    If defFileName Then MkDir path ' create new folder if not exist
    Kill path & fiName
On Error GoTo fail:
    Open path & fiName For Output As fiNum
    If encrypted Then
        Print #fiNum, EncryptINI(getHeader, "TMBPAYROLL")
    Else
        Print #fiNum, getHeader
    End If
    For cnt = 1 To Payrolls.Count
        Dim str As String
        str = getFixed(cnt, cnt + 1)
        If encrypted Then
            Print #fiNum, EncryptINI(str, "TMBPAYROLL")
        Else
            Print #fiNum, str
        End If
    Next cnt
    If encrypted Then
        Print #fiNum, EncryptINI(getFooter(CStr(cnt + 1)), "TMBPAYROLL")
    Else
        Print #fiNum, getFooter(CStr(cnt + 1))
    End If
    
    export = True
    GoTo succees
fail:
    MsgBox "Can't save Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    export = False
succees:
On Error Resume Next
    Close fiNum
On Error GoTo 0

End Function

Public Function importFromFi41(Optional fiName As String = "") As Boolean
'*************************************************************************
' Development by:chalermpon sompavana
' Description: Load a fixed-length file (41 bytes) and transform it to a fixed-length file (160 bytes)
'*************************************************************************
On Error GoTo fail3:
    Dim cnt As Integer
    Dim str As String
    Dim fiNum As Integer
    fiNum = FreeFile
    cnt = 1
    If fiName = "" Then
        fiName = fileName
    Else
        fiName = fiName
        
    End If
    Open fiName For Random As fiNum Len = 43
    
    For cnt = 1 To LOF(fiNum) / 43
        Dim p As EmpPayroll_Type_41
        Dim drcr As String
        ''While EOF(fiNum)
        ''Wend
        Get #fiNum, cnt, p
       ' If Not ((checkdigitAccNum(p.account_number)) And (p.transaction_code = 2) And (IsNumeric(p.strAmount)) And (CDbl(p.strAmount) < 9999999999.99) And (CDbl(p.strAmount) > 0) And (p.home_branch = objPayroll.payRollClientInfo.HomeBRCode)) Then
           If Not ((checkdigitAccNum(p.account_number)) And (p.transaction_code = 2) And (IsNumeric(p.strAmount)) And (CDbl(p.strAmount) < 9999999999.99) And (CDbl(p.strAmount) > 0)) Then
              GoTo failIncorrectformate:
        End If
        
        Payrolls.Add _
        Trim(p.account_number), _
        "-", _
        "C", _
        CDbl(p.strAmount) / 100, _
        Trim(p.reference_area1), _
        Trim(p.reference_area2)
    Next cnt
        
    importFromFi41 = True
    GoTo succees3
fail3:
    MsgBox "Can't load Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    importFromFi41 = False
failIncorrectformate:
    MsgBox "Can't load Payroll!!!(Incorrect format data)" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    importFromFi41 = False
succees3:
    Close fiNum
On Error GoTo 0
End Function
'
'Public Function importFromFiExcel(Optional fiName As String = "") As Boolean
''*************************************************************************
'' Development by:chalermpon sompavana
'' Description: Load a fixed-length file (41 bytes) and transform it to a fixed-length file (160 bytes)
''*************************************************************************
'On Error GoTo fail3:
'    Dim str As Integer
'    Dim exApp As New Excel.Application
'    Dim exWork As New Excel.Workbook
'    Dim accountNum, Reference1, credit, Amount As String
'
'    str = 2 'start line 2 in excel file
'    If fiName = "" Then
'        fiName = fileName
'    Else
'        fiName = fiName
'    End If
'    Set exWork = exApp.Workbooks.Open(fiName, True)
'    While (exWork.ActiveSheet.Cells(str, 3).value) > 0
'        accountNum = CStr(exWork.ActiveSheet.Cells(str, 2).value)
'        Reference1 = Trim(exWork.ActiveSheet.Cells(str, 4).value)
'        credit = UCase(Trim(exWork.ActiveSheet.Cells(str, 5).value))
'        Amount = Trim(exWork.ActiveSheet.Cells(str, 3).value)
'        If Not (checkdigitAccNum(CStr(accountNum)) And credit = "C" And (IsNumeric(Amount)) And (CDbl(Amount) < 9999999999.99) And (CDbl(Amount) > 0)) Then
'            GoTo failIncorrectformate:
'        End If
'        Payrolls.Add _
'        Trim(accountNum), _
'        "-", _
'        "C", _
'        CDbl(Amount) / 100, _
'        Trim(Reference1), _
'        ""
'        str = str + 1  'running number
'    Wend
'
'    importFromFiExcel = True
'    GoTo succees3
'fail3:
'    MsgBox "Can't load Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
'    Set exApp = Nothing
'    Set exWork = Nothing
'    importFromFiExcel = False
'failIncorrectformate:
'    Set exApp = Nothing
'    Set exWork = Nothing
'    MsgBox "Can't load Payroll!!!(Incorrect format data)" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
'   ' 14/09/09  by supansa
'   ' importFromFi41 = False
'succees3:
'    Set exApp = Nothing
'    Set exWork = Nothing
'On Error GoTo 0
'End Function

Public Function checkdigitAccNum(str As String) As Boolean
    If IsNumeric(str) And Val(str) > 0 Then
        str = Replace(str, "-", "")
        If Len(str) <> 10 Then
            checkdigitAccNum = False
        Else
            Dim iArray(9) As Integer
            Dim cnt As Integer
            Dim sum As Integer
            sum = 0
            For cnt = 0 To 8
                iArray(cnt) = CInt(Mid(str, cnt + 1, 1))
                iArray(cnt) = iArray(cnt) Mod 10
                If cnt Mod 2 = 0 Then
                    iArray(cnt) = iArray(cnt) * 2
                End If
                If iArray(cnt) > 9 Then
                    iArray(cnt) = iArray(cnt) - 10 + 1
                End If
                sum = sum + iArray(cnt)
            Next cnt
            Dim chkDigit As Integer
            chkDigit = sum Mod 10
            chkDigit = (10 - chkDigit) Mod 10
            Dim acctType As String
            acctType = Mid(str, 4, 1)
            If (Mid(str, 10, 1) = chkDigit) And (acctType = "1" Or acctType = "2" Or acctType = "7" Or acctType = "9") Then
                checkdigitAccNum = True
            Else
                checkdigitAccNum = False
            End If
        End If
    Else
         checkdigitAccNum = False
    End If
    
End Function

Public Function loadFromFi(Optional fiName As String = "") As Boolean
On Error GoTo fail:
    Dim cnt As Integer
    Dim str As String
    Dim fiNum As Integer
    fiNum = FreeFile
    cnt = 1
    If fiName = "" Then
        fiName = savedFiPath & fileName
    Else
        fiName = savedFiPath & fiName
    End If
    Open fiName For Random As fiNum Len = 160
    For cnt = 1 To LOF(fiNum) / 160
        Dim p As EmpPayroll_Type
        Dim drcr As String
        Get #fiNum, cnt, p
'***************************************************************************************************
' change value

        p.account_number = Right(p.account_number, 10) ' cut useless zero on the left side out

'***************************************************************************************************
        Payrolls.Add _
        Trim(p.account_number), _
        Trim(p.account_name), _
        Trim(p.transaction_code), _
        CDbl(Trim(p.strAmount)) / 100, _
        Trim(p.reference_area1), _
        Trim(p.reference_area2)
    Next cnt
    loadFromFi = True
    GoTo succees
fail:
    MsgBox "Can't load Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    loadFromFi = False
succees:
    Close fiNum
On Error GoTo 0
End Function

Public Sub copyFromOldFi(sourceFi As String, destFi As String)
    If sourceFi <> destFi Then
        FileCopy savedFiPath & sourceFi, savedFiPath & destFi
    End If
End Sub

'Public Property Get Users() As Users
''    If mvarUsers Is Nothing Then
''        Set mvarUsers = New Users
''    End If
''
''    Set Users = mvarUsers
'End Property
'
'
'Public Property Set Users(vData As Users)
''    Set mvarUsers = vData
'End Property

Public Property Get Payrolls() As Payrolls
    If mvarPayrolls Is Nothing Then
        Set mvarPayrolls = New Payrolls
    End If

    Set Payrolls = mvarPayrolls
End Property

Public Property Set Payrolls(vData As Payrolls)
    Set mvarPayrolls = vData
End Property

Private Sub Class_Terminate()
 ' Set mvarUsers = Nothing
    Set mvarPayrolls = Nothing
End Sub

Private Sub Class_Initialize()
    Set mvarpayRollClientInfo = New ClientInfo
End Sub

Private Function cIsFirst(expression As String) As Boolean
    If expression = "0" Then ' this is the first time
        cIsFirst = True
    Else
        cIsFirst = False
    End If
End Function

Public Property Set payRollClientInfo(ByVal vData As ClientInfo)
    Set mvarpayRollClientInfo = vData
End Property

Public Property Get payRollClientInfo() As ClientInfo
    Set payRollClientInfo = mvarpayRollClientInfo
End Property

'Public Sub loadSettingFromFile(strFiPath As String)
'' for load setting from Company Header file (Pls. check file path in payroll.ini)
'    Dim str As String
'    Dim tmp As Long
'    Dim userName As String
'    Dim password As String
'    Dim isFirst As Boolean
'
'    userName = getProperty("TMBUserData", "UserName1", strFiPath, "user1")
'    password = getProperty("TMBUserData", "Password1", strFiPath, "password")
'    isFirst = cIsFirst(getProperty("TMBUserData", "UserStatus1", strFiPath))
'    Me.Users.Add userName, password, USERTYPE_USER, isFirst, 1, UCase(Trim(userName)) ' user ID = 1
'
'    userName = getProperty("TMBUserData", "UserName2", strFiPath, "user2")
'    password = getProperty("TMBUserData", "Password2", strFiPath, "password")
'    isFirst = cIsFirst(getProperty("TMBUserData", "UserStatus2", strFiPath))
'    Me.Users.Add userName, password, USERTYPE_USER, isFirst, 2, UCase(Trim(userName)) ' user ID = 2
'
'    userName = getProperty("TMBUserData", "SuperUserName", strFiPath, "user1")
'    password = getProperty("TMBUserData", "SuperPassword", strFiPath, "password")
'    isFirst = cIsFirst(getProperty("TMBUserData", "SuperUserStatus", strFiPath))
'    Me.Users.Add userName, password, USERTYPE_USER, isFirst, 0, UCase(Trim(userName)) ' user ID = 0
'End Sub

Private Function getPayrollStruct(empID, Optional sequence_number As Integer = 1) As EmpPayroll_Type
    Dim tmp As String
    Dim res As EmpPayroll_Type
    Dim emp As EmployeePayroll
    Set emp = Payrolls(empID)
    
    res.record_type = "D"
    res.sequence_number = padStringWith(Trim(str(sequence_number)), "0", 6, False)
    res.bank_code = "011"
    res.account_number = padStringWith(Replace(emp.AccountNumber, "-", ""), "0", 12, False)
    res.transaction_code = emp.DebitCredit
    tmp = Trim(Replace(str(emp.Amount), ",", ""))
    If InStr(1, tmp, ".") > 0 Then
        tmp = Format(tmp, "#.00")
        res.strAmount = Replace(tmp, ".", "")
    Else
        res.strAmount = tmp & "00"
    End If
    res.strAmount = padStringWith(res.strAmount, "0", 12, False)
    res.service_type = "08"
    res.status = "9"
    res.reference_area1 = padStringWith(emp.Reference1, " ", 20)
    res.inservice_date = "991231"
    res.company_code = padStringWith(mvarpayRollClientInfo.CompanyCode, " ", 4)
    res.home_branch = payRollClientInfo.HomeBRCode
    res.reference_area2 = padStringWith(emp.Reference2, " ", 20)
    res.tmb_flag = String(6, " ")
    res.compID = String(4, " ")
    res.subComp = padStringWith(CStr(mvarbatchNo), "0", 2, False)
    res.spare = String(14, " ")
    res.account_name = padStringWith(emp.EmpName, " ", 35)
    res.teller_id = String(8, " ")

    getPayrollStruct = res
End Function

Public Function loadFixedFi(fiStr As String) As Boolean
On Error GoTo fail:
    Dim cnt As Integer
    Dim str As String
    Dim fiNum As Integer
    Dim tmp As String
    
    fiNum = FreeFile

    Open fiStr For Input As fiNum
    Do Until EOF(fiNum)
        Input #fiNum, str
        str = DecryptINI(str, "TMBPAYROLL")
        Select Case Left(str, 1)
            Case "H"
                tmp = Mid(str, 8, 3) 'bank code
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.BankCode = tmp
                
                tmp = Trim(Mid(str, 111, 4)) ' company code
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.CompanyCode = tmp
                
                tmp = Trim(Mid(str, 23, 40)) 'company name
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.CompanyName = tmp
                
                tmp = Mid(str, 63, 6) 'effectivedate
                tmp = Replace(tmp, vbNewLine, "")
                effectiveDate = Mid(tmp, 1, 2) & "/" & Mid(tmp, 3, 2) & "/" & Mid(tmp, 5, 2)
                
                tmp = Mid(str, 115, 6) ' TMB Flag
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.tmbFlag = tmp
                
                tmp = Mid(str, 109, 2) ' batch No
                tmp = Replace(tmp, vbNewLine, "")
                batchNo = CInt(tmp)
            
            Case "D"
                Dim emp As EmpPayroll_Type
                emp = readFixed(str, False)
                Payrolls.Add emp.account_number, Trim(emp.account_name), Trim(emp.transaction_code), CDbl(emp.strAmount) / 100, Trim(emp.reference_area1), Trim(emp.reference_area2)
                tmp = Mid(str, 69, 3) 'br Code
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.HomeBRCode = tmp
            Case "T"
                tmp = Mid(str, 13, 10) 'bank code
                tmp = Replace(tmp, vbNewLine, "")
                payRollClientInfo.AccountNumber = tmp
                
        End Select
    Loop
        
    GoTo succees
fail:
    MsgBox "Can't load Payroll!!!" & vbNewLine & Err.Description, vbOKOnly Or vbCritical, "Error"
    loadFixedFi = False
succees:
    Close fiNum
On Error GoTo 0
End Function

Private Function readFixed(str As String, Optional isEncrypted As Boolean = False, Optional pwd As String = "TMBPAYROLL") As EmpPayroll_Type
    If isEncrypted Then str = DecryptINI(str, pwd)
    
    Dim tmp As String
    Dim pos As Integer
    Dim res As EmpPayroll_Type

    pos = 1
    
    res.record_type = Replace(Mid(str, pos, Len(res.record_type)), vbNewLine, "")
    pos = pos + Len(res.record_type)
    
    res.sequence_number = Replace(Mid(str, pos, Len(res.sequence_number)), vbNewLine, "")
    pos = pos + Len(res.sequence_number)
    
    res.bank_code = Replace(Mid(str, pos, Len(res.bank_code)), vbNewLine, "")
    pos = pos + Len(res.bank_code)
    
    res.account_number = Replace(Mid(str, pos, Len(res.account_number)), vbNewLine, "")
    pos = pos + Len(res.account_number)
    
    res.transaction_code = Replace(Mid(str, pos, Len(res.transaction_code)), vbNewLine, "")
    pos = pos + Len(res.transaction_code)
    
    res.strAmount = Replace(Mid(str, pos, Len(res.strAmount)), vbNewLine, "")
    pos = pos + Len(res.strAmount)
    
    res.service_type = Replace(Mid(str, pos, Len(res.service_type)), vbNewLine, "")
    pos = pos + Len(res.service_type)
    
    res.status = Replace(Mid(str, pos, Len(res.status)), vbNewLine, "")
    pos = pos + Len(res.status)
    
    res.reference_area1 = Replace(Mid(str, pos, Len(res.reference_area1)), vbNewLine, "")
    pos = pos + Len(res.reference_area1)
    
    res.inservice_date = Replace(Mid(str, pos, Len(res.inservice_date)), vbNewLine, "")
    pos = pos + Len(res.inservice_date)
    
    res.company_code = Replace(Mid(str, pos, Len(res.company_code)), vbNewLine, "")
    pos = pos + Len(res.company_code)
    
    res.home_branch = Replace(Mid(str, pos, Len(res.home_branch)), vbNewLine, "")
    pos = pos + Len(res.home_branch)
    
    res.reference_area2 = Replace(Mid(str, pos, Len(res.reference_area2)), vbNewLine, "")
    pos = pos + Len(res.reference_area2)
    
    res.tmb_flag = Replace(Mid(str, pos, Len(res.tmb_flag)), vbNewLine, "")
    pos = pos + Len(res.tmb_flag)
    
    res.compID = Replace(Mid(str, pos, Len(res.compID)), vbNewLine, "")
    pos = pos + Len(res.compID)
    
    res.subComp = Replace(Mid(str, pos, Len(res.subComp)), vbNewLine, "")
    pos = pos + Len(res.subComp)
    
    res.spare = Replace(Mid(str, pos, Len(res.spare)), vbNewLine, "")
    pos = pos + Len(res.spare)
    
    res.account_name = Replace(Mid(str, pos, Len(res.account_name)), vbNewLine, "")
    pos = pos + Len(res.account_name)
    
    res.teller_id = Replace(Mid(str, pos, Len(res.teller_id)), vbNewLine, "")
    pos = pos + Len(res.teller_id)
    
    readFixed = res
End Function

Public Function getFixed(empID As Variant, Optional sequence_number As Integer = 1) As String
    Dim emp As EmpPayroll_Type
    emp = getPayrollStruct(empID, sequence_number)
    Dim DCFlag As String
    DCFlag = Left(emp.transaction_code, 1)
    emp.transaction_code = UCase(DCFlag)
    Dim effDate As String
    effDate = padStringWith(Right((Split(mvareffectiveDate, "/")(2)), 2), "0", 2, False) & _
                padStringWith((Split(mvareffectiveDate, "/")(1)), "0", 2, False) & _
                padStringWith((Split(mvareffectiveDate, "/")(0)), "0", 2, False)


    getFixed = _
    emp.record_type & _
    emp.sequence_number & _
    emp.bank_code & _
    emp.account_number & _
    emp.transaction_code & _
    emp.strAmount & _
    emp.service_type & _
    emp.status & _
    emp.reference_area1 & _
    effDate & _
    emp.company_code & _
    emp.home_branch & _
    emp.reference_area2 & _
    emp.tmb_flag & _
    emp.compID & _
    padStringWith(CStr(batchNo), "0", 2, False) & _
    emp.spare & _
    emp.account_name & _
    emp.teller_id
End Function
