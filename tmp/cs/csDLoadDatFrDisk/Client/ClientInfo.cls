VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ClientInfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
'******************************************************************
'Description :  ClientInfo Class use for function decrypt payroll file 160 characters
'Add Date     :  08/12/2009
'******************************************************************
'local variable(s) to hold property value(s)
Private mvarCompanyCode As String 'local copy
Private mvarCompanyName As String 'local copy
Private mvarBankCode As String 'local copy
Private mvarAccountNumber As String 'local copy
Private mvarTMBFlag As String 'local copy
Private mvarHomeBRCode As String 'local copy
Private mvarHomeBRName As String 'local copy

Public Property Let HomeBRName(ByVal vData As String)
    mvarHomeBRName = vData
End Property


Public Property Get HomeBRName() As String
    HomeBRName = mvarHomeBRName
End Property


Public Property Let HomeBRCode(ByVal vData As String)
    mvarHomeBRCode = vData
End Property


Public Property Get HomeBRCode() As String
    HomeBRCode = mvarHomeBRCode
End Property


Public Property Let tmbFlag(ByVal vData As String)
    mvarTMBFlag = vData
End Property


Public Property Get tmbFlag() As String
    tmbFlag = mvarTMBFlag
End Property


Public Property Let AccountNumber(ByVal vData As String)
    mvarAccountNumber = vData
End Property


Public Property Get AccountNumber() As String
    AccountNumber = mvarAccountNumber
End Property


Public Property Let BankCode(ByVal vData As String)
    mvarBankCode = vData
End Property


Public Property Get BankCode() As String
    BankCode = mvarBankCode
End Property


Public Property Let CompanyName(ByVal vData As String)
    mvarCompanyName = vData
End Property


Public Property Get CompanyName() As String
    CompanyName = mvarCompanyName
End Property


Public Property Let CompanyCode(ByVal vData As String)
    mvarCompanyCode = vData
End Property


Public Property Get CompanyCode() As String
    CompanyCode = mvarCompanyCode
End Property

Public Sub exportToFile(Optional strFiPath As String = "TMB.DAT")
End Sub


Public Function loadFromFile(strFiPath As String) As Boolean
    Dim str As String
    Dim tmp As String
    
    mvarCompanyCode = DecryptINI(getProperty("TMBAppData", "CompCode", strFiPath, "-"), "TMBAppData")
    mvarCompanyName = DecryptINI(getProperty("TMBAppData", "CompName", strFiPath, "-"), "TMBAppData")
    mvarBankCode = DecryptINI(getProperty("TMBAppData", "BankCode", strFiPath, "-"), "TMBAppData")
    mvarAccountNumber = DecryptINI(getProperty("TMBAppData", "AcctNo", strFiPath, "-"), "TMBAppData")
    mvarTMBFlag = DecryptINI(getProperty("TMBAppData", "TMBFlag", strFiPath, "      "), "TMBAppData")
    mvarHomeBRCode = DecryptINI(getProperty("TMBAppData", "HomeBrCode", strFiPath, "-"), "TMBAppData")
    mvarHomeBRName = DecryptINI(getProperty("TMBAppData", "HomeBrName", strFiPath, "-"), "TMBAppData")

End Function

