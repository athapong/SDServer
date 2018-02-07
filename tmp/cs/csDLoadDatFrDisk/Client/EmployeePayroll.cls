VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "EmployeePayroll"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
'******************************************************************
'Description :  EmployeePayroll Class use for function decrypt payroll file 160 characters
'Add Date     :  08/12/2009
'******************************************************************

'local variable(s) to hold property value(s)
Private mvarAccountNumber As String 'local copy
Private mvarEmpName As String 'local copy
Private mvarDebitCredit As String 'local copy
Private mvarAmount As Double 'local copy
Private mvarReference1 As String 'local copy
Private mvarReference2 As String 'local copy

Public Property Let Reference2(ByVal vData As String)
    mvarReference2 = vData
End Property

Public Property Get Reference2() As String
    Reference2 = mvarReference2
End Property

Public Property Let Reference1(ByVal vData As String)
    mvarReference1 = vData
End Property

Public Property Get Reference1() As String
    Reference1 = mvarReference1
End Property

Public Property Let Amount(ByVal vData As Double)
    mvarAmount = vData
End Property

Public Property Get Amount() As Double
    Amount = mvarAmount
End Property

Public Property Let DebitCredit(ByVal vData As String)
    mvarDebitCredit = vData
End Property

Public Property Get DebitCredit() As String
    DebitCredit = mvarDebitCredit
End Property

Public Property Let EmpName(ByVal vData As String)
    mvarEmpName = vData
End Property

Public Property Get EmpName() As String
    EmpName = mvarEmpName
End Property

Public Property Let AccountNumber(ByVal vData As String)
    mvarAccountNumber = vData
End Property

Public Property Get AccountNumber() As String
    AccountNumber = mvarAccountNumber
End Property



