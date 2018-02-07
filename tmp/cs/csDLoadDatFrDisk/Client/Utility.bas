Attribute VB_Name = "Utility"

Public Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
Public Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long

Public objPayroll As New Payroll

Public Type EmpPayroll_Type

    record_type As String * 1
    sequence_number As String * 6
    bank_code As String * 3
    account_number As String * 12
    transaction_code As String * 1
    strAmount As String * 12
    service_type As String * 2
    status As String * 1
    reference_area1 As String * 20
    inservice_date As String * 6
    company_code As String * 4
    home_branch As String * 3
    reference_area2 As String * 20
    tmb_flag As String * 6
    compID As String * 4
    subComp As String * 2
    spare As String * 14
    account_name As String * 35
    teller_id As String * 8
    
End Type
Public Type EmpPayroll_Type_41

    company_code As String * 4
    service_type As String * 2
    account_number As String * 10
    home_branch As String * 3
    reference_area1 As String * 7
    transaction_code As String * 1
    strAmount As String * 12
    reference_area2 As String * 2
    
    'company_code As String * 4
    'service_type As String * 2
    'account_number As String * 12
    'home_branch As String * 3
    'reference_area1 As String * 20
    'transaction_code As String * 1
    'strAmount As String * 12
    'reference_area2 As String * 20
End Type

' Code From microsoft (http://support.microsoft.com/kb/146022/EN-US/)

Private Type Rect
   Left As Long
   Top As Long
   Right As Long
   Bottom As Long
End Type

Private Type CharRange
  cpMin As Long     ' First character of range (0 for start of doc)
  cpMax As Long     ' Last character of range (-1 for end of doc)
End Type

Private Type FormatRange
  hdc As Long       ' Actual DC to draw on
  hdcTarget As Long ' Target DC for determining text formatting
  rc As Rect        ' Region of the DC to draw to (in twips)
  rcPage As Rect    ' Region of the entire DC (page size) (in twips)
  chrg As CharRange ' Range of text to draw (see above declaration)
End Type

Private Const WM_USER As Long = &H400
Private Const EM_FORMATRANGE As Long = WM_USER + 57
Private Const EM_SETTARGETDEVICE As Long = WM_USER + 72
Private Const PHYSICALOFFSETX As Long = 112
Private Const PHYSICALOFFSETY As Long = 113

Private Declare Function GetDeviceCaps Lib "gdi32" (ByVal hdc As Long, ByVal nIndex As Long) As Long
Private Declare Function SendMessage Lib "USER32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal msg As Long, ByVal wp As Long, lp As Any) As Long
Private Declare Function CreateDC Lib "gdi32" Alias "CreateDCA" (ByVal lpDriverName As String, ByVal lpDeviceName As String, ByVal lpOutput As Long, ByVal lpInitData As Long) As Long

''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
' WYSIWYG_RTF - Sets an RTF control to display itself the same as it
'               would print on the default printer
'
' RTF - A RichTextBox control to set for WYSIWYG display.
'
' LeftMarginWidth - Width of desired left margin in twips
'
' RightMarginWidth - Width of desired right margin in twips
'
' Returns - The length of a line on the printer in twips
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



Public Function padTab(str As String, tabWidth As Integer, Optional maxWidth As Integer = 0, Optional tabSize As Integer = 7) As String
    Dim res As String
    Dim cnt As Integer
    If maxWidth <> 0 Then
        If Len(str) > maxWidth Then
            str = Left(str, maxWidth) & "..."
        End If
    End If
    res = str
    If tabWidth * tabSize > Len(str) Then
        Dim tabCnt As Integer
        tabCnt = ((tabWidth * tabSize) - Len(str)) \ tabSize
        If Len(str) Mod tabSize > 0 Then tabCnt = tabCnt + 1
        For cnt = 1 To tabCnt
            res = res & vbTab
        Next cnt
    End If
    padTab = res
End Function

Public Function changeINIString(str As String) As String
    changeINIString = Replace(Trim(str), Chr$(0), "")
End Function

Public Function padStringWith(exp As String, padStr As String, fullLen As Integer, Optional isLeftJust = True) As String
    exp = Trim(exp)
    If fullLen >= Len(exp) Then
        If isLeftJust Then
            padStringWith = exp & String(fullLen - Len(exp), padStr)
        Else
            padStringWith = String(fullLen - Len(exp), padStr) & exp
        End If
    Else
        If isLeftJust Then
            padStringWith = Left(exp, fullLen)
        Else
            padStringWith = Right(exp, fullLen)
        End If
    End If
End Function

Public Function checkdigit(str As String) As Boolean
    str = Replace(str, "-", "")
    If Len(str) <> 10 Then
        checkdigit = False
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
            checkdigit = True
        Else
            checkdigit = False
        End If
    End If
End Function

Public Function EncryptINI(Strg As String, Optional pwd As String = "") As String
    Dim b As String, S As String, i As Long, j As Long
    Dim A1 As Long, A2 As Long, A3 As Long
    Dim p As String
    
    j = 1
    If pwd = "" Then
        pwd = password
    End If
    For i = 1 To Len(pwd)
    p = p & Asc(Mid(pwd, i, 1))
    Next
    
    For i = 1 To Len(Strg)
        A1 = Asc(Mid(p, j, 1))
        j = j + 1: If j > Len(p) Then j = 1
        A2 = Asc(Mid(Strg, i, 1))
        A3 = A1 Xor A2
        b$ = Hex(A3)
        If Len(b) < 2 Then b = "0" + b
        S = S + b
    Next
    EncryptINI = S
End Function

Public Function DecryptINI(Strg As String, Optional pwd As String = "") As String
    Dim b As String, S As String, i As Long, j As Long
    Dim A1 As Long, A2 As Long, A3 As Long
    Dim p As String
    j = 1
    If pwd = "" Then
        pwd = password
    End If
    For i = 1 To Len(pwd)
        p = p & Asc(Mid(pwd, i, 1))
    Next
    
    For i = 1 To Len(Strg) Step 2
        A1 = Asc(Mid(p, j, 1))
        j = j + 1: If j > Len(p) Then j = 1
        b = Mid(Strg, i, 2)
        A3 = Val("&H" + b)
        A2 = A1 Xor A3
        S = S + Chr(A2)
    Next
    DecryptINI = S
End Function

Public Function getProperty(sectionName As String, PropertyName As String, strFiPath, Optional defValue As String = "") As String
Dim str As String
Dim tmp As Long
    str = String(1024, " ")
    tmp = GetPrivateProfileString(sectionName, PropertyName, defValue, str, 1024, strFiPath)
    getProperty = changeINIString(str)
End Function

Public Sub setEncryptProperty(sectionName As String, PropertyName As String, strFiPath, value As String, Optional password As String = "")
Dim tmp As Long
    tmp = WritePrivateProfileString(sectionName, PropertyName, EncryptINI(value, password), strFiPath)
End Sub

Public Function CTMBFlag(tmbFlag As String) As String
    Select Case Trim(tmbFlag)
        Case "000001"
            CTMBFlag = "11:00"
        Case "000002"
            CTMBFlag = "15:30"
        Case "000003"
            CTMBFlag = "17:30"
        Case "000004"
            CTMBFlag = "09:30"
        Case "000005"
            CTMBFlag = "13:30"
        Case ""
            CTMBFlag = "Morning"
    End Select
End Function

Public Function crdrFlag(flag As String) As String
    If StrComp(flag, "D", vbTextCompare) = 0 Then
        crdrFlag = "Debit"
    Else
        crdrFlag = "Credit"
    End If
End Function


