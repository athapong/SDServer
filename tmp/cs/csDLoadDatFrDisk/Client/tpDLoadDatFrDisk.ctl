VERSION 5.00
Object = "{3B008041-905A-11D1-B4AE-444553540000}#1.0#0"; "vsocx6.ocx"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "mscomctl.ocx"
Object = "{8FE000BE-47E4-4701-94B8-CC63160A770E}#1.0#0"; "csCmpySearch.ocx"
Begin VB.UserControl tpDLoadDatFrDisk 
   ClientHeight    =   6495
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   9000
   ScaleHeight     =   6495
   ScaleWidth      =   9000
   Begin vsOcx6LibCtl.vsIndexTab tabLoadSalary 
      Height          =   6495
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   9000
      _ExtentX        =   15875
      _ExtentY        =   11456
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   222
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Enabled         =   -1  'True
      Appearance      =   1
      MousePointer    =   0
      _ConvInfo       =   1
      Version         =   600
      BackColor       =   -2147483633
      ForeColor       =   -2147483630
      FrontTabColor   =   -2147483633
      BackTabColor    =   -2147483633
      TabOutlineColor =   0
      FrontTabForeColor=   -2147483630
      Caption         =   "&Company Search|&Data Validation|Journal &Logs"
      Align           =   5
      Appearance      =   1
      CurrTab         =   0
      FirstTab        =   0
      Style           =   2
      Position        =   0
      AutoSwitch      =   -1  'True
      AutoScroll      =   -1  'True
      TabPreview      =   -1  'True
      ShowFocusRect   =   -1  'True
      TabsPerPage     =   5
      BorderWidth     =   5
      BoldCurrent     =   0   'False
      DogEars         =   -1  'True
      MultiRow        =   0   'False
      MultiRowOffset  =   200
      CaptionStyle    =   0
      TabHeight       =   0
      Begin csCmpySearch.tpCmpySearch tpCmpySearch 
         Height          =   5970
         Left            =   120
         TabIndex        =   21
         Top             =   405
         Width           =   8760
         _ExtentX        =   15452
         _ExtentY        =   10530
         Enabled         =   -1  'True
      End
      Begin vsOcx6LibCtl.vsElastic elaLoadSalary 
         Height          =   5970
         Index           =   0
         Left            =   9720
         TabIndex        =   2
         TabStop         =   0   'False
         Top             =   405
         Width           =   8760
         _ExtentX        =   15452
         _ExtentY        =   10530
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   222
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Enabled         =   -1  'True
         Appearance      =   0
         MousePointer    =   0
         _ConvInfo       =   1
         Version         =   600
         BackColor       =   -2147483633
         ForeColor       =   -2147483630
         FloodColor      =   192
         ForeColorDisabled=   -2147483631
         Caption         =   ""
         Align           =   0
         Appearance      =   0
         AutoSizeChildren=   0
         BorderWidth     =   6
         ChildSpacing    =   4
         Splitter        =   0   'False
         FloodDirection  =   0
         FloodPercent    =   0
         CaptionPos      =   1
         WordWrap        =   -1  'True
         MaxChildSize    =   0
         MinChildSize    =   0
         TagWidth        =   0
         TagPosition     =   0
         Style           =   0
         TagSplit        =   0   'False
         PicturePos      =   4
         CaptionStyle    =   0
         ResizeFonts     =   0   'False
         GridRows        =   0
         GridCols        =   0
         _GridInfo       =   ""
         Begin VB.Frame fraSelectCompaySalaryFile 
            Caption         =   "Select Company Salary File"
            Height          =   1935
            Left            =   120
            TabIndex        =   4
            Top             =   120
            Width           =   8415
            Begin VB.CommandButton cmdBrowse 
               Caption         =   "..."
               Height          =   375
               Left            =   5400
               TabIndex        =   7
               Top             =   1155
               Width           =   375
            End
            Begin VB.TextBox txtCompanySalaryFile 
               Height          =   315
               Left            =   1920
               TabIndex        =   6
               Top             =   1200
               Width           =   3375
            End
            Begin VB.CommandButton cmdValidate 
               Caption         =   "Validate"
               Height          =   375
               Left            =   6360
               TabIndex        =   5
               Top             =   1155
               Width           =   975
            End
            Begin VB.Label nfoCompanySubCode 
               Caption         =   "- None -"
               ForeColor       =   &H8000000D&
               Height          =   375
               Left            =   4920
               TabIndex        =   14
               Top             =   360
               Width           =   855
            End
            Begin VB.Label nfoCompanyCode 
               Caption         =   "- None -"
               ForeColor       =   &H8000000D&
               Height          =   375
               Left            =   1920
               TabIndex        =   13
               Top             =   360
               Width           =   855
            End
            Begin VB.Label lblCompanyCode 
               Caption         =   "Company Code"
               Height          =   375
               Left            =   240
               TabIndex        =   12
               Top             =   360
               Width           =   1455
            End
            Begin VB.Label lblCompanyName 
               Caption         =   "Company Name"
               Height          =   375
               Left            =   240
               TabIndex        =   11
               Top             =   795
               Width           =   1335
            End
            Begin VB.Label nfoCompanyName 
               Caption         =   "- None -"
               ForeColor       =   &H8000000D&
               Height          =   375
               Left            =   1920
               TabIndex        =   10
               Top             =   800
               Width           =   5655
            End
            Begin VB.Label lblCompanySalaryFile 
               Caption         =   "Company Salary File"
               Height          =   375
               Left            =   240
               TabIndex        =   9
               Top             =   1245
               Width           =   1695
            End
            Begin VB.Label lblCompanySubCode 
               Caption         =   "Sub Code"
               Height          =   375
               Left            =   3360
               TabIndex        =   8
               Top             =   360
               Width           =   1335
            End
         End
         Begin VB.TextBox txtResult 
            Height          =   3255
            Left            =   120
            Locked          =   -1  'True
            MultiLine       =   -1  'True
            ScrollBars      =   3  'Both
            TabIndex        =   3
            Top             =   2520
            Width           =   8415
         End
         Begin VB.Label lblProcessResult 
            Caption         =   "Result"
            Height          =   315
            Left            =   120
            TabIndex        =   15
            Top             =   2280
            Width           =   1455
         End
      End
      Begin vsOcx6LibCtl.vsElastic elaLoadSalary 
         Height          =   5970
         Index           =   1
         Left            =   10020
         TabIndex        =   16
         TabStop         =   0   'False
         Top             =   405
         Width           =   8760
         _ExtentX        =   15452
         _ExtentY        =   10530
         BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
            Name            =   "MS Sans Serif"
            Size            =   8.25
            Charset         =   222
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Enabled         =   -1  'True
         Appearance      =   0
         MousePointer    =   0
         _ConvInfo       =   1
         Version         =   600
         BackColor       =   -2147483633
         ForeColor       =   -2147483630
         FloodColor      =   192
         ForeColorDisabled=   -2147483631
         Caption         =   ""
         Align           =   0
         Appearance      =   0
         AutoSizeChildren=   0
         BorderWidth     =   6
         ChildSpacing    =   4
         Splitter        =   0   'False
         FloodDirection  =   0
         FloodPercent    =   0
         CaptionPos      =   1
         WordWrap        =   -1  'True
         MaxChildSize    =   0
         MinChildSize    =   0
         TagWidth        =   0
         TagPosition     =   0
         Style           =   0
         TagSplit        =   0   'False
         PicturePos      =   4
         CaptionStyle    =   0
         ResizeFonts     =   0   'False
         GridRows        =   0
         GridCols        =   0
         _GridInfo       =   ""
         Begin MSComctlLib.ListView lvwJournalLog 
            Height          =   3200
            Left            =   120
            TabIndex        =   17
            Top             =   360
            Width           =   8055
            _ExtentX        =   14208
            _ExtentY        =   5636
            LabelEdit       =   1
            LabelWrap       =   -1  'True
            HideSelection   =   0   'False
            FullRowSelect   =   -1  'True
            _Version        =   393217
            ForeColor       =   -2147483640
            BackColor       =   -2147483643
            BorderStyle     =   1
            Appearance      =   1
            NumItems        =   0
         End
         Begin MSComctlLib.ListView lvwFaultRecord 
            Height          =   1400
            Left            =   120
            TabIndex        =   18
            Top             =   3960
            Width           =   8055
            _ExtentX        =   14208
            _ExtentY        =   2461
            LabelEdit       =   1
            LabelWrap       =   -1  'True
            HideSelection   =   0   'False
            FullRowSelect   =   -1  'True
            _Version        =   393217
            ForeColor       =   -2147483640
            BackColor       =   -2147483643
            BorderStyle     =   1
            Appearance      =   1
            NumItems        =   0
         End
         Begin VB.Label nfoLoadResult 
            Caption         =   "nfoLoadResult"
            ForeColor       =   &H8000000D&
            Height          =   375
            Left            =   120
            TabIndex        =   1
            Top             =   5445
            Width           =   7935
         End
         Begin VB.Label lblFaultRecord 
            Caption         =   "Fault Records"
            Height          =   315
            Left            =   120
            TabIndex        =   20
            Top             =   3720
            Width           =   1455
         End
         Begin VB.Label lblJournalLogs 
            Caption         =   "Journal Logs"
            Height          =   315
            Left            =   120
            TabIndex        =   19
            Top             =   120
            Width           =   1455
         End
      End
   End
   Begin MSComctlLib.ImageList iilsLoglIcon 
      Left            =   0
      Top             =   0
      _ExtentX        =   1005
      _ExtentY        =   1005
      BackColor       =   -2147483643
      ImageWidth      =   16
      ImageHeight     =   16
      MaskColor       =   12632256
      _Version        =   393216
      BeginProperty Images {2C247F25-8591-11D1-B16A-00C0F0283628} 
         NumListImages   =   4
         BeginProperty ListImage1 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "tpDLoadDatFrDisk.ctx":0000
            Key             =   "Error"
         EndProperty
         BeginProperty ListImage2 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "tpDLoadDatFrDisk.ctx":0552
            Key             =   "Warning"
         EndProperty
         BeginProperty ListImage3 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "tpDLoadDatFrDisk.ctx":0AA4
            Key             =   "Information"
         EndProperty
         BeginProperty ListImage4 {2C247F27-8591-11D1-B16A-00C0F0283628} 
            Picture         =   "tpDLoadDatFrDisk.ctx":0FF6
            Key             =   ""
         EndProperty
      EndProperty
   End
   Begin MSComDlg.CommonDialog dlgFileOpen 
      Left            =   720
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
End
Attribute VB_Name = "tpDLoadDatFrDisk"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
'******************************************************************
'Transaction Code    :  CS-007
'Description         :  Company Salary 160 Char  - Load Data from Diskette
'Database            :  Add/Delete data in CompanySalary table
'Version:           :  1.0.0
'Create Date   :  01/09/2006
'Author              :  buncha  sangbuakaew
'Enhance         :  08/12/2009 Wanidol & Bancha enhance decrypt payroll file
'******************************************************************
 
Option Explicit
 
Implements AtpACommon
Implements AtpADatabase

Public Event ButtonCaption(ByVal ButtonId As Long, ByVal Caption As String)
Public Event ButtonStatus(ByVal ButtonId As Long, ByVal Enabled As Boolean, ByVal Visible As Boolean)
Public Event ButtonClick(ByVal ButtonId As Long)
Public Event DisplayMessage(ByVal ErrorObject As AtpOError)
Public Event GetAttribute(ByVal AttributeName As Long, ByRef AttributeValue As Variant)

Private Const RESOURCE_PROGID As String = "csRDLoadDatFrDisk.AcsRDLoadDatFrDisk"
Private Const SERVICE_ID As Long = 5116

Private Const SEARCH_TAB As Long = 0
Private Const VALIDATION_TAB As Long = 1
Private Const JOURNAL_LOG_TAB As Long = 2

Private m_Resource As AtpAResources
Private m_Error As AtpOError
Private m_Isdirty  As Boolean

Private m_ProcBranch
Private m_RePrint As Boolean
Private m_DbStatus As String
Private m_TotalRecord As Integer
Private m_CurRecord As Integer
Private m_RecordLoaded As Long
Private m_LoadError As Boolean

Private m_ValidFile As Boolean
Private m_RecErrKey As Long

Private m_OwnerBranch As String
Private m_TotalItem As Integer

Private m_TotalAmount As Currency
Private m_DepositItem As Integer
Private m_DepositAmount As Currency
Private m_DeductItem As Integer
Private m_DeductAmount As Currency

Private m_NoOf_DR_Transaction As Long
Private m_Total_DR_Amount As Currency
Private m_NoOf_CR_Transaction  As Long
Private m_Total_CR_Amount As Currency
Private m_NoOfReject_DR_Transaction As Long
Private m_TotalReject_DR_Amount As Currency
Private m_NoOfReject_CR_Transaction As Long
Private m_TotalReject_CR_Amount As Currency

Private m_TransDate As String

Private m_ProcessingDate As Date

Private m_DbProcess As eDatabaseProcessing

Private CompSalaryRec() As CompanySalaryRecord
Private CompSalary160_H As CompanySalary160_Header
Private CompSalary160_D()  As CompanySalary160_Detail
Private CompSalary160_E As CompanySalary160_End
Private AccountRec() As AccoutRecord
Private M_TELLER_ID
Dim LoginUserId As String




Private Property Get AtpACommon_Application() As String
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "AtpACommon_Application"
    
   AtpACommon_Application = APPL_COMPANY_SALARY
   
   Exit Property
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Function AtpACommon_GetPrintData(PrintData As tpSupport.AtpIUserParams) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpACommon_GetPrintData"
   Const lvwText = 0
   Const lvwSubitem = 1
   Const lvwTag = 2
   Const lvwWholeWord = 0
   
   Const ALLDOCS_REF As String = "ALL"
   Const DOC1_REF As String = "770"
   Const DOC2_REF As String = "771"
   
   Dim itmFound As ListItem
   Dim c As Integer
   Dim l As Integer
   
    
   PrintData.Add SD_PRINT_SERVICE_ID, CStr(SERVICE_ID)
    If m_RePrint Then
        PrintData.Add SD_REPRINT, "YES"
    End If
   
    If tabLoadSalary.CurrTab = SEARCH_TAB Then
        AtpACommon_GetPrintData = tpCmpySearch.CmpyInfo_GetPrintData(PrintData)
    Else
        If tabLoadSalary.CurrTab = VALIDATION_TAB Then
            PrintData.Add SD_PRINT_REFERENCE_NUMBER, DOC1_REF
            PrintData.Add "LINE1", m_Resource.LoadString(eResourceStrings.tpValidateSuccess)
            PrintData.Add "LINE2", m_Resource.LoadString(eResourceStrings.tpOwnerBranch) & " : " & m_OwnerBranch
            PrintData.Add "LINE3", nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " " & nfoCompanyName.Caption
            PrintData.Add "LINE4", m_Resource.LoadString(eResourceStrings.tpNoOfDRTransaction) & " = " & Format(m_NoOf_DR_Transaction, "#,##0")
            PrintData.Add "LINE5", m_Resource.LoadString(eResourceStrings.tpTotalDRAmount) & " = " & Format(m_Total_DR_Amount, "#,##0.00")
            PrintData.Add "LINE6", m_Resource.LoadString(eResourceStrings.tpNoOfCRTransaction) & " = " & Format(m_NoOf_CR_Transaction, "#,##0")
            PrintData.Add "LINE7", m_Resource.LoadString(eResourceStrings.tpTotalCRAmount) & " = " & Format(m_Total_CR_Amount, "#,##0.00")
            PrintData.Add "LINE8", m_Resource.LoadString(eResourceStrings.tpNoOfRejectDRTransaction) & " = " & Format(m_NoOfReject_DR_Transaction, "#,##0")
            PrintData.Add "LINE9", m_Resource.LoadString(eResourceStrings.tpTotalRejectDRAmount) & " = " & Format(m_TotalReject_DR_Amount, "#,##0.00")
            PrintData.Add "LINE10", m_Resource.LoadString(eResourceStrings.tpNoOfRejectcRTransaction) & " = " & Format(m_NoOfReject_CR_Transaction, "#,##0")
            PrintData.Add "LINE11", m_Resource.LoadString(eResourceStrings.tpTotalRejectcRAmount) & " = " & Format(m_TotalReject_CR_Amount, "#,##0.00")
                  
'         PrintData.Add "LINE4", m_Resource.LoadString(eResourceStrings.tpTotalItems) & " = " & Format(m_TotalItem, "#,##0")
'         PrintData.Add "LINE5", m_Resource.LoadString(eResourceStrings.tpTotalAmount) & " = " & Format(m_TotalAmount, "#,##0.00")
'         PrintData.Add "LINE6", m_Resource.LoadString(eResourceStrings.tpDeductItems) & " = " & Format(m_DeductItem, "#,##0")
'         PrintData.Add "LINE7", m_Resource.LoadString(eResourceStrings.tpDeductAmount) & " = " & Format(m_DeductAmount, "#,##0.00")
'         PrintData.Add "LINE8", m_Resource.LoadString(eResourceStrings.tpDepositItems) & " = " & Format(m_DepositItem, "#,##0")
'         PrintData.Add "LINE9", m_Resource.LoadString(eResourceStrings.tpDepositAmount) & " = " & Format(m_DepositAmount, "#,##0.00")
        Else
            If tabLoadSalary.CurrTab = JOURNAL_LOG_TAB Then
                PrintData.Add SD_PRINT_REFERENCE_NUMBER, DOC2_REF
                l = 0
                For c = 1 To lvwJournalLog.ListItems.Count
                    With lvwJournalLog.ListItems(c)
                        l = l + 1
                        If m_RePrint Then
                     'In case of Work Queue show only date no time
                            PrintData.Add "M2PROW_" & CStr(l) & "_LOGMESSAGE", .Text & " " & m_TransDate & " " & .SubItems(2)
                        Else
                            PrintData.Add "M2PROW_" & CStr(l) & "_LOGMESSAGE", .Text & " " & .SubItems(1) & " " & .SubItems(2)
                        End If
                     
                        Set itmFound = lvwFaultRecord.FindItem(.Tag, lvwTag, , lvwWholeWord)
                    End With

               If itmFound Is Nothing Then      ' If no match, inform user and exit.
               Else
                  l = l + 1
                  With itmFound
                     PrintData.Add "M2PROW_" & CStr(l) & "_LOGMESSAGE", "-> " & .SubItems(1)
                  End With
               End If
            Next
            
         End If
      End If
   End If
   
   AtpACommon_GetPrintData = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   AtpACommon_GetPrintData = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpACommon_Initialize(ByVal TPResource As tpInterfaces.AtpAResources, TPError As tpSupport.AtpOError, Optional ByVal ObjectIn As Object) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpACommon_Initialize"
   
   Dim ErrDescription As String
   Dim AllIswell As Boolean
   
   Set m_Resource = TPResource
   Set m_Error = TPError
      
   AllIswell = True
      
   Call InitializeMemberVariables
   
   m_ProcessingDate = ProcessingDate()
      
   If (Len(m_ProcessingDate) = 0) Then
      AllIswell = False
   End If
   
   If (AllIswell) Then
      AllIswell = LoadResources()
   End If
      
   If (AllIswell) Then
      Call SetBaseButtons
      Call InitializeControls
   Else
      ErrDescription = m_Resource.LoadString(eResourceStrings.tpErrLoadResource)
      AllIswell = False
      Call SetError(m_Error, TYPE_WARNING, ErrDescription, SUBROUTINE)
   End If

   If (AllIswell) Then
      Call InitialJournalLog
      Call InitialFaultRecord
   End If
   
   AtpACommon_Initialize = AllIswell
   
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   AtpACommon_Initialize = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Property Get AtpACommon_IsDirty() As Boolean
   On Error GoTo ErrorHandler
  
   Const SUBROUTINE As String = "AtpACommon_IsDirty"
   
   AtpACommon_IsDirty = m_Isdirty

   Exit Property
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Property Let AtpACommon_PrintResult(RHS As Boolean)
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpACommon_PrintResult"
   
   If RHS Then
      RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
   Else
      RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
   End If
   
   Exit Property
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Property Get AtpACommon_ResourceProgId() As String
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "AtpACommon_ResourceProgId"

   AtpACommon_ResourceProgId = RESOURCE_PROGID
   
   Exit Property
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Function AtpACommon_Terminate() As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpACommon_Terminate"
   
   Call CleanupMemberVariables
   
   AtpACommon_Terminate = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   AtpACommon_Terminate = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Property Get AtpACommon_TransactionCaption() As String
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "AtpACommon_TransactionCaption"

   AtpACommon_TransactionCaption = m_Resource.LoadString(eResourceStrings.tpTransactionCaption)

   Exit Property
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Function AtpACommon_Validate(ByVal ButtonId As Integer) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpACommon_Validate"
   
   Dim Validated As Boolean

   Select Case ButtonId
      Case RETRIEVE_BUTTON
         Validated = ValidateRetrieve()
      Case ADD_BUTTON
         Validated = ValidateAdd()
      Case DELETE_BUTTON
         Validated = ValidateDelete()
      Case Else
         Validated = True
   End Select
   
   AtpACommon_Validate = Validated
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   AtpACommon_Validate = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Property Get AtpADatabase_ServiceId() As Long
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_ServiceId"

   AtpADatabase_ServiceId = SERVICE_ID
   
   Exit Property
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Property

Private Function AtpADatabase_Add(DBTransactions As tpSupport.AtpODBTransactions, _
                                  ScreenDetails As tpSupport.AtpIUserParams) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_Add"
   Const MAX_KB As Long = 64
   Const MAX_DBINPUT_SIZE As Long = MAX_KB * 1024
   Const SQL_PREFIX As String = "insert into Company_Salary_160 (" & _
                                " COMPANY_CODE,SUB_COMPANY_CODE," & _
                                " BRANCH_ID,RECORD_TYPE,RECORD_DATA," & _
                                " LAST_UPDATE_DTM,LAST_UPDATE_USER,SEQUENCE_NO  ) values "
   
   Dim DBTransaction As AtpODBTransaction
   Dim SqlVal As String
   Dim i As Long
   Dim DBInputSize As Long
   Dim DBOverSize As Boolean
    Dim StrData160C As String
   'Before loading new data, delete old data only first time
   If m_RecordLoaded = 0 Then
      nfoLoadResult.Caption = ""
      txtCompanySalaryFile.Enabled = False
      cmdBrowse.Enabled = False
      cmdValidate.Enabled = False
      RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
      
      m_DbProcess = DELETE_SALARY
      RaiseEvent ButtonClick(DELETE_BUTTON)
   End If

   Do While m_DbProcess <> NONE_PROCESS
      DoEvents
   Loop
    
   m_DbProcess = ADD_SALARY
      
   DBOverSize = False
   DBInputSize = 0
       
   Do While m_CurRecord <= m_TotalRecord And Not DBOverSize

      Set DBTransaction = New AtpODBTransaction
      
        If IS_First_Record_Of_Data = True Then
            'ทำการส่งรายการ Header ออกไปก่อน
            With CompSalary160_H
                StrData160C = .RecordType & .SequenceNumber & .BankCode & .CompanyAccountNo _
                    & .CompanyName & .PostDate & .Spare1 & .SubCompanyCode & .CompanyID & .tmbFlag & .Spare2
                
                SqlVal = "'" & nfoCompanyCode & "','" & nfoCompanySubCode & "','" & m_ProcBranch & "','" & .RecordType _
                    & "','" & StrData160C & "',sysdate,'" & LoginUserId & "'," & .SequenceNumber
                    
                DBTransaction.DBInput = SQL_PREFIX & "(" & SqlVal & ")"
                DBInputSize = DBInputSize + Len(DBTransaction.DBInput)
                If DBInputSize <= MAX_DBINPUT_SIZE Then
                   Call DBTransactions.Add(DBTransaction)
                    IS_First_Record_Of_Data = False
                Else
                   IS_First_Record_Of_Data = True
                End If
            End With
        Else
            'ส่งรายการ Detail ออกไปหลังจากส่งรายการ Header แล้ว
            With CompSalary160_D(m_CurRecord)
               StrData160C = .RecordType & .SequenceNumber & .BankCode & .AccountNumber & .TransactionCode _
                    & .Amount & .ServiceType & .status & .ReferenceArea1 & .InserviceDate & .CompanyCode & .HomeBranch _
                    & .ReferenceArea2 & .tmbFlag & .CompanyCode2 & .SubCompanyCode & .spare & .Name & .TellerID
                    
                    SqlVal = "'" & nfoCompanyCode & "','" & nfoCompanySubCode & "','" & m_ProcBranch & "','" & .RecordType _
                    & "','" & StrData160C & "',sysdate,'" & LoginUserId & "'," & .SequenceNumber
            End With
              
            DBTransaction.DBInput = SQL_PREFIX & "(" & SqlVal & ")"
            
            DBInputSize = DBInputSize + Len(DBTransaction.DBInput)
            
            If DBInputSize <= MAX_DBINPUT_SIZE Then
               Call DBTransactions.Add(DBTransaction)
               m_CurRecord = m_CurRecord + 1
            Else
               DBOverSize = True
            End If
        End If
   Loop
    'รายการสุดท้ายแล้วต้องส่งรายการปิดท้ายอีก 1 รายการ
    If m_CurRecord >= m_TotalRecord Then
        If IS_Last_Record_Of_Data = False Then
            Set DBTransaction = New AtpODBTransaction
            With CompSalary160_E
                StrData160C = .RecordType & .SequenceNumber & .BankCode & .CompanyAccountNo & .NoOf_DR_Transaction _
                    & .Total_DR_Amount & .NoOf_CR_Transaction & .Total_CR_Amount & .NoOfReject_DR_Transaction & .TotalReject_DR_Amount _
                    & .NoOfReject_CR_Transaction & .TotalReject_CR_Amount & .CompanyID & .tmbFlag & .SubCompanyCode & .spare
                SqlVal = "'" & nfoCompanyCode & "','" & nfoCompanySubCode & "','" & m_ProcBranch & "','" & .RecordType _
                        & "','" & StrData160C & "',sysdate,'" & LoginUserId & "'," & .SequenceNumber
                DBTransaction.DBInput = SQL_PREFIX & "(" & SqlVal & ")"
                DBInputSize = DBInputSize + Len(DBTransaction.DBInput)
                If DBInputSize <= MAX_DBINPUT_SIZE Then
                   Call DBTransactions.Add(DBTransaction)
                   IS_Last_Record_Of_Data = True
                Else
                   IS_Last_Record_Of_Data = False
                End If
            End With
        End If
    End If
    
   Call ControlsToScreenDetails(ScreenDetails, DBTransactions)
   
'    ++++Aui Edit++++++++++
'    If Dir(App.path & "\*.DEC") <> "" Then Kill (App.path & "\*.DEC")
'    +++++++++++++++++++++
   
   AtpADatabase_Add = True
   Exit Function

ErrorHandler:
   Debug.Assert False
   AtpADatabase_Add = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpADatabase_Update(DBTransactions As tpSupport.AtpODBTransactions, _
                                     ScreenDetails As tpSupport.AtpIUserParams) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_Update"
        
   AtpADatabase_Update = True
   Exit Function
    
ErrorHandler:
   Debug.Assert False
   AtpADatabase_Update = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpADatabase_Delete(DBTransactions As tpSupport.AtpODBTransactions, _
                                     ScreenDetails As tpSupport.AtpIUserParams) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_Delete"
   Const SQL_PREFIX As String = "delete Company_Salary_160  where "
   
   Dim DBTransaction As AtpODBTransaction
   Dim SqlVal As String
   
   Set DBTransaction = New AtpODBTransaction
   
   DBTransaction.DBInput = SQL_PREFIX & "Branch_Id='" & m_ProcBranch & _
                           "'  and Company_Code='" & nfoCompanyCode.Caption & _
                           "'  and Sub_Company_Code= '" & nfoCompanySubCode.Caption & "'"
      
   Call DBTransactions.Add(DBTransaction)
     
   Call ControlsToScreenDetails(ScreenDetails, DBTransactions)
     
   AtpADatabase_Delete = True
   Exit Function
    
ErrorHandler:
   Debug.Assert False
   AtpADatabase_Delete = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpADatabase_Retrieve(DBTransactions As tpSupport.AtpODBTransactions) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_Retrieve"
   
   Dim DBTransaction As AtpODBTransaction
   Dim SqlVal As String
   
   If tabLoadSalary.CurrTab = SEARCH_TAB Then m_DbProcess = RETRIEVE_COMPANY
   
   Select Case m_DbProcess
      Case RETRIEVE_COMPANY
         AtpADatabase_Retrieve = tpCmpySearch.CmpyInfo_Retrieve(DBTransactions)
      Case Else
         AtpADatabase_Retrieve = True
   End Select
   
   Exit Function

ErrorHandler:
   Debug.Assert False
   AtpADatabase_Retrieve = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpADatabase_DisplayResults(ByVal DBTransactions As tpSupport.AtpODBTransactions) As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "AtpADatabase_DisplayResults"
 
   Dim DBTransaction As AtpODBTransaction
   Dim Output As AtpIUserParam
   Dim i As Integer
   
   Select Case m_DbProcess
      Case RETRIEVE_COMPANY
         AtpADatabase_DisplayResults = tpCmpySearch.CmpyInfo_DisplayResults(DBTransactions)
         If tpCmpySearch.PrintEnabled Then
            RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
         Else
            RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
         End If
         m_DbProcess = NONE_PROCESS
         
      Case DELETE_SALARY
         For Each DBTransaction In DBTransactions
            For Each Output In DBTransaction.DBOutput
               Call InsertJournalLog(INFORMATION_LOG, "Delete Company Salary database for " & _
                    m_ProcBranch & ":" & nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " [" & Output.Name & "=" & Output.value & "]")
            Next
         Next
         m_DbProcess = NONE_PROCESS
         AtpADatabase_DisplayResults = True
         
      Case ADD_SALARY
         For Each DBTransaction In DBTransactions
            m_RecordLoaded = m_RecordLoaded + 1
            If DBTransaction.DBOutput.Count = 0 Then
               Call InsertJournalLog(ERROR_LOG, "Rec#" & CStr(m_RecordLoaded) & " Failure add record to database.")
               Call InsertFaultRecordStr(m_RecordLoaded, "INSERT_DB" & Mid(DBTransaction.DBInput, InStr(1, DBTransaction.DBInput, "values") + 6))
               m_LoadError = True
            Else
               For Each Output In DBTransaction.DBOutput
                    Debug.Print Output.value
               Next
            End If
         Next
      
         If m_CurRecord <= m_TotalRecord And m_DbProcess = ADD_SALARY Then
            m_DbProcess = NONE_PROCESS
            RaiseEvent ButtonClick(ADD_BUTTON)
         Else
            If IS_Last_Record_Of_Data = False Then
                m_DbProcess = NONE_PROCESS
                RaiseEvent ButtonClick(ADD_BUTTON)
            Else
                Call InsertJournalLog(INFORMATION_LOG, "Finish loading Company Salary information into database.")
                If Not m_LoadError Then
                    nfoLoadResult.Caption = "Load transaction completed."
                    '    ++++++++Aui Edit+++++++
                    If Dir(App.path & "\*.DEC") <> "" Then Kill (App.path & "\*.DEC")
                    '    +++++++++++++++++++++
                End If
                tabLoadSalary.CurrTab = JOURNAL_LOG_TAB
            End If
         End If
         m_DbProcess = NONE_PROCESS
         AtpADatabase_DisplayResults = True
      
      Case Else
         AtpADatabase_DisplayResults = True
   End Select
                                     
   Exit Function

ErrorHandler:
   Debug.Assert False
   AtpADatabase_DisplayResults = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function AtpADatabase_DoExisting(ByVal DBTransactions As tpSupport.AtpODBTransactions, _
                                         ByVal ScreenDetails As tpSupport.AtpIUserParams) As Boolean
   On Error GoTo ErrorHandler
    
   Const SUBROUTINE As String = "AtpADatabase_DoExisting"

   m_RePrint = True
   
   lvwJournalLog.ListItems.Clear
   lvwFaultRecord.ListItems.Clear

   Call ScreenDetailsToControls(ScreenDetails, DBTransactions)
   Call DisableAllControls
   
   m_ValidFile = True
   tabLoadSalary.Enabled = True
   tabLoadSalary.TabEnabled(0) = False
   tabLoadSalary.TabEnabled(1) = True
   tabLoadSalary.TabEnabled(2) = True
   tabLoadSalary.CurrTab = VALIDATION_TAB
   lvwJournalLog.Enabled = True
   
   RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
    
   AtpADatabase_DoExisting = True
   Exit Function

ErrorHandler:
   Debug.Assert False
   AtpADatabase_DoExisting = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function LoadResources() As Boolean
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "LoadResources"
   
   tabLoadSalary.Caption = m_Resource.LoadString(eResourceStrings.tpTabCompanySearch) & "|" & _
                           m_Resource.LoadString(eResourceStrings.tpTabDataValidation) & "|" & _
                           m_Resource.LoadString(eResourceStrings.tpTabJournalLogs)
   fraSelectCompaySalaryFile.Caption = m_Resource.LoadString(eResourceStrings.tpSelectCompanySalaryFile)
   lblCompanyCode.Caption = m_Resource.LoadString(eResourceStrings.tpCompanyCode)
   lblCompanySubCode.Caption = m_Resource.LoadString(eResourceStrings.tpCompanySubCode)
   lblCompanyName.Caption = m_Resource.LoadString(eResourceStrings.tpCompanyName)
   lblCompanySalaryFile.Caption = m_Resource.LoadString(eResourceStrings.tpCompanySalaryFile)
   lblProcessResult.Caption = m_Resource.LoadString(eResourceStrings.tpProcessResult)
   cmdValidate.Caption = m_Resource.LoadString(eResourceStrings.tpValidate)
    
   lblJournalLogs.Caption = m_Resource.LoadString(eResourceStrings.tpJournalLogs)
   lblFaultRecord.Caption = m_Resource.LoadString(eResourceStrings.tpFaultRecord)
    
   LoadResources = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   LoadResources = False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

Private Sub SetBaseButtons()
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "SetBaseButtons"

   RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(CANCEL_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
   
   RaiseEvent ButtonCaption(ADD_BUTTON, m_Resource.LoadString(eResourceStrings.tpLoad))
   
   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub InitializeMemberVariables()
   On Error GoTo ErrorHandler
   Dim XX
   Const SUBROUTINE As String = "InitializeMemberVariables"
      
   m_Isdirty = False
   m_DbProcess = RETRIEVE_COMPANY
       
   RaiseEvent GetAttribute(BRANCH_ID_ATTRIB, m_ProcBranch)
   RaiseEvent GetAttribute(TELLER_ID_ATTRIB, M_TELLER_ID)
   tpCmpySearch.BranchId = m_ProcBranch
   m_ProcBranch = Format(m_ProcBranch, "0000")
    IS_First_Record_Of_Data = True
    IS_Last_Record_Of_Data = False
   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub CleanupMemberVariables()
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "CleanupMemberVariables"

   'TO DO: Add any additional clean up in here
   Set m_Error = Nothing
   Set m_Resource = Nothing
   
   Exit Sub
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub DisableAllControls()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "DisableAllControls"

   Dim Ctl As Control

   For Each Ctl In Controls
      If TypeOf Ctl Is ImageList Or _
         TypeOf Ctl Is CommonDialog Then
         'none
      Else
         Ctl.Enabled = False
      End If
   Next

   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub InitializeControls()
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "InitializeControls"
    tabLoadSalary.CurrTab = 0
   tabLoadSalary.TabEnabled(1) = False
   tabLoadSalary.TabEnabled(2) = False
   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Function ControlsToScreenDetails(ByVal ScreenDetails As AtpIUserParams, ByVal DBTransactions As AtpODBTransactions) As Boolean
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ControlsToScreenDetails"
 
   Call ScreenDetails.Add("DB_PROCESS", CStr(m_DbProcess))
   Call ScreenDetails.Add("PROC_BRANCH", CStr(m_ProcBranch))
   Call ScreenDetails.Add("COMPANY_CODE", nfoCompanyCode.Caption)
   Call ScreenDetails.Add("COMPANY_SUBCODE", nfoCompanySubCode.Caption)
   Call ScreenDetails.Add("COMPANY_NAME", nfoCompanyName.Caption)
   Call ScreenDetails.Add("COMPANY_SALARY_FILE", txtCompanySalaryFile.Text)
   Call ScreenDetails.Add("OWNER_BRANCH", m_OwnerBranch)
   Call ScreenDetails.Add("VALIDATE_RESULT", txtResult.Text)
   
   Call ScreenDetails.Add("m_NoOf_DR_Transaction", Format(m_NoOf_DR_Transaction, "#,##0"))
   Call ScreenDetails.Add("m_Total_DR_Amount", Format(m_Total_DR_Amount, "#,##0.00"))
   Call ScreenDetails.Add("m_NoOf_CR_Transaction", Format(m_NoOf_CR_Transaction, "#,##0"))
   Call ScreenDetails.Add("m_Total_CR_Amount", Format(m_Total_CR_Amount, "#,##0.00"))
   Call ScreenDetails.Add("m_NoOfReject_DR_Transaction", Format(m_NoOfReject_DR_Transaction, "#,##0"))
   Call ScreenDetails.Add("m_TotalReject_DR_Amount", Format(m_TotalReject_DR_Amount, "#,##0.00"))
   Call ScreenDetails.Add("m_NoOfReject_CR_Transaction", Format(m_NoOfReject_CR_Transaction, "#,##0"))
   Call ScreenDetails.Add("m_TotalReject_CR_Amount", Format(m_TotalReject_CR_Amount, "#,##0.00"))
      
   Call ScreenDetails.Add("TRANSACTION_DATE", Format(m_ProcessingDate, "dd/mm/yyyy"))
   ControlsToScreenDetails = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   ControlsToScreenDetails = False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

Private Function ScreenDetailsToControls(ByRef ScreenDetails As AtpIUserParams, ByRef DBTransactions As tpSupport.AtpODBTransactions) As Boolean
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ScreenDetailsToControls"
    
   Dim ScreenDetail As AtpIUserParam
   Dim DBTransaction As AtpODBTransaction
   Dim Output As AtpIUserParam
   Dim p_DbProcess As eDatabaseProcessing
   Dim HasError As Boolean
   
   p_DbProcess = NONE_PROCESS
   
   For Each ScreenDetail In ScreenDetails
      With ScreenDetail
         If .Name = "DB_PROCESS" Then
            p_DbProcess = CInt(.value)
         Else
            Select Case .Name
               Case "PROC_BRANCH"
                  m_ProcBranch = .value
               Case "COMPANY_CODE"
                  nfoCompanyCode.Caption = .value
               Case "COMPANY_SUBCODE"
                  nfoCompanySubCode.Caption = .value
               Case "COMPANY_NAME"
                  nfoCompanyName.Caption = .value
               Case "COMPANY_SALARY_FILE"
                  txtCompanySalaryFile.Text = .value
               Case "VALIDATE_RESULT"
                  txtResult.Text = .value
               Case "OWNER_BRANCH"
                  m_OwnerBranch = .value
                              
               Case "m_NoOf_DR_Transaction"
                  m_NoOf_DR_Transaction = CLng(.value)
               Case "m_Total_DR_Amount"
                  m_Total_DR_Amount = CCur(.value)
               Case "m_NoOf_CR_Transaction"
                  m_NoOf_CR_Transaction = CLng(.value)
               Case "m_Total_CR_Amount"
                  m_Total_CR_Amount = CCur(.value)
               Case "m_NoOfReject_DR_Transaction"
                  m_NoOfReject_DR_Transaction = CLng(.value)
               Case "m_TotalReject_DR_Amount"
                  m_TotalReject_DR_Amount = CCur(.value)
               Case "m_NoOfReject_CR_Transaction"
                  m_NoOfReject_CR_Transaction = CLng(.value)
               Case "m_TotalReject_CR_Amount"
                  m_TotalReject_CR_Amount = CCur(.value)
               
               Case "TRANSACTION_DATE"
                  m_TransDate = .value
            End Select
         End If
         
      End With
   Next
                 
   Select Case p_DbProcess
      Case DELETE_SALARY
         For Each DBTransaction In DBTransactions
            For Each Output In DBTransaction.DBOutput
               Call InsertJournalLog(INFORMATION_LOG, "Delete Company Salary database for " & _
                                       m_ProcBranch & ":" & nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " [" & Output.Name & "=" & Output.value & "]")
            Next
         Next
         nfoLoadResult.Caption = ""
         
      Case ADD_SALARY
         Call InsertJournalLog(INFORMATION_LOG, "Start reading Company Salary data from diskette.")
         Call InsertJournalLog(INFORMATION_LOG, "Finish reading " & txtCompanySalaryFile.Text & " for " & nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " from diskette.")
                  
         HasError = False
         For Each DBTransaction In DBTransactions
            If Left(DBTransaction.DBInput, 6) = "insert" Then
               If DBTransaction.DBOutput.Count = 0 Then
                  HasError = True
                  Call InsertJournalLog(ERROR_LOG, "INSERT_DB" & Mid(DBTransaction.DBInput, InStr(1, DBTransaction.DBInput, "values") + 6))
               Else
                  For Each Output In DBTransaction.DBOutput
                     '
                  Next
               End If
            End If
         Next
         
         If Not HasError Then
            Call InsertJournalLog(INFORMATION_LOG, "Finish loading Company Salary information into database.")
            nfoLoadResult.Caption = "Load transaction completed."
         End If
   End Select
     
   ScreenDetailsToControls = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   ScreenDetailsToControls = False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

Private Function ValidateAdd() As Boolean
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ValidateAdd"
   
   ValidateAdd = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   ValidateAdd = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function ValidateRetrieve() As Boolean
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ValidateRetrieve"
   
   ValidateRetrieve = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   ValidateRetrieve = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Function ValidateDelete() As Boolean
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ValidateDelete"
   
   ValidateDelete = True
   Exit Function
   
ErrorHandler:
   Debug.Assert False
   ValidateDelete = False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Function

Private Sub cmdValidate_Click()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "cmdValidate_Click"
   
   m_ValidFile = False
   If FileExist(StrPath) Then
      lvwJournalLog.ListItems.Clear
      lvwFaultRecord.ListItems.Clear
      IS_First_Record_Of_Data = True
      IS_Last_Record_Of_Data = False
      m_ValidFile = ReadSalaryFile()
      
      If m_ValidFile Then
         m_CurRecord = 1
         m_RecordLoaded = 0
         m_LoadError = False
         Call ShowSalaryDataSummary
         RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
         RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
         If m_TotalRecord >= 2 Then
            m_TotalRecord = m_TotalRecord - 2
         Else
            m_TotalRecord = 0
         End If
      Else
         txtResult.Text = m_Resource.LoadString(eResourceStrings.tpValidateFailure) & vbCrLf
         tabLoadSalary.CurrTab = JOURNAL_LOG_TAB
      End If
      tabLoadSalary.TabEnabled(2) = True
      
   Else
      m_Error.Source = "cmdValidate_Click()"
      m_Error.Number = TYPE_FATALTRANSACTION
      m_Error.Description = m_Resource.LoadString(eResourceStrings.tpErrFileNotFound)
      RaiseEvent DisplayMessage(m_Error)
   End If
   
   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call SetError(m_Error, TYPE_WARNING, Err.Description, SUBROUTINE)
End Sub

Private Sub ShowSalaryDataSummary()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ShowSalaryDataSummary"
   
   txtResult.Text = m_Resource.LoadString(eResourceStrings.tpValidateSuccess) & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpOwnerBranch) & " : " & m_OwnerBranch & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " " & nfoCompanyName.Caption & vbCrLf & vbCrLf
   
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpNoOfDRTransaction) & " = " & Format(m_NoOf_DR_Transaction, "#,##0") & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpTotalDRAmount) & " = " & Format(m_Total_DR_Amount, "#,##0.00") & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpNoOfCRTransaction) & " = " & Format(m_NoOf_CR_Transaction, "#,##0") & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpTotalCRAmount) & " = " & Format(m_Total_CR_Amount, "#,##0.00") & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpNoOfRejectDRTransaction) & " = " & Format(m_NoOfReject_DR_Transaction, "#,##0") & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpTotalRejectDRAmount) & " = " & Format(m_TotalReject_DR_Amount, "#,##0.00") & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpNoOfRejectcRTransaction) & " = " & Format(m_NoOfReject_CR_Transaction, "#,##0") & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpTotalRejectcRAmount) & " = " & Format(m_TotalReject_CR_Amount, "#,##0.00") & vbCrLf & vbCrLf
   txtResult.Text = txtResult.Text & m_Resource.LoadString(eResourceStrings.tpEffectiveDate) & " = " & Format(CompSalary160_H.PostDate, "00/00/00") & vbCrLf & vbCrLf
   
   'CompSalary160_H.PostDate

   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub cmdBrowse_Click()
   dlgFileOpen.CancelError = True
   dlgFileOpen.InitDir = "A:\"
   
   On Error GoTo ErrHandler
   ' Set flags
   dlgFileOpen.Flags = cdlOFNHideReadOnly Or cdlOFNFileMustExist Or cdlOFNNoChangeDir
   ' Set filters
   dlgFileOpen.Filter = "(*.ENC)|*.ENC"
   
   ' Specify default filter
   dlgFileOpen.FilterIndex = 2
   ' Display the Open dialog box
   dlgFileOpen.ShowOpen
   
'    ++++Aui Edit++++++++++
    If Dir(App.path & "\*.DEC") <> "" Then Kill (App.path & "\*.DEC")
'    +++++++++++++++++++++
    
    objPayroll.Payrolls.Clear
    objPayroll.loadFixedFi dlgFileOpen.fileName
    StrPath = App.path & "\" & Replace(dlgFileOpen.FileTitle, ".ENC", "") & "_" & Format(Time(), "hhmmss") & ".DEC"
    objPayroll.export StrPath, False, False
    
    txtCompanySalaryFile.Text = dlgFileOpen.fileName
   
   cmdValidate.Enabled = True
   Exit Sub
   
ErrHandler:
   'User pressed the Cancel button
   Exit Sub
End Sub



Private Sub lvwJournalLog_ItemClick(ByVal Item As MSComctlLib.ListItem)
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "lvwJournalLog_ItemClick"
   
   Const lvwText = 0
   Const lvwSubitem = 1
   Const lvwTag = 2
   Const lvwWholeWord = 0
   
   Dim itmFound As ListItem         ' FoundItem variable.
      
   Set itmFound = lvwFaultRecord.FindItem(Item.Tag, lvwTag, , lvwWholeWord)
   
   If itmFound Is Nothing Then      ' If no match, inform user and exit.
      lvwFaultRecord.HideSelection = True
      Exit Sub
   Else
      itmFound.EnsureVisible       ' Scroll ListView to show found ListItem.
      lvwFaultRecord.HideSelection = False
      itmFound.Selected = True     ' Select the ListItem.
   End If

   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub lvwFaultRecord_ItemClick(ByVal Item As MSComctlLib.ListItem)
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "lvwFaultRecord_ItemClick"
   
   Const lvwText = 0
   Const lvwSubitem = 1
   Const lvwTag = 2
   Const lvwWholeWord = 0
   
   Dim itmFound As ListItem
      
   Set itmFound = lvwJournalLog.FindItem(Item.Tag, lvwTag, , lvwWholeWord)
   
   If itmFound Is Nothing Then
      lvwJournalLog.HideSelection = True
      Exit Sub
   Else
      itmFound.EnsureVisible
      lvwJournalLog.HideSelection = False
      itmFound.Selected = True
   End If

   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub tabLoadSalary_Click()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "tabLoadSalary_Click"
   
   If tabLoadSalary.CurrTab = SEARCH_TAB Then
      RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
      RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
      If tpCmpySearch.PrintEnabled Then
         RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
      Else
         RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
      End If
   Else
      If tabLoadSalary.CurrTab = VALIDATION_TAB Then
         RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
         If m_ValidFile Then
            If cmdValidate.Enabled Then RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
            RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
         Else
            RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
         End If
      Else
         'lvwJournalLog.SetFocus
         RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
         RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
         RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_ENABLED, BUTTON_VISIBLE)
      End If
   End If

   Exit Sub
   
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub tpCmpySearch_OnError(sSubroutine As String, sDescription As String)
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "tpCmpySearch_OnError"

   Call SetError(m_Error, TYPE_FATALTRANSACTION, sDescription, sSubroutine)
   Exit Sub
        
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub tpCmpySearch_SelectedCmpy(CompanyCode As String, SubCompanyCode As String, CompanyName As String, ADDRESS1 As String, ADDRESS2 As String, ADDRESS3 As String)
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "tpCmpySearch_SelectedCmpy"
   
   RaiseEvent ButtonStatus(RETRIEVE_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(ADD_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)
   RaiseEvent ButtonStatus(PRINT_BUTTON, BUTTON_DISABLED, BUTTON_VISIBLE)

   nfoCompanyCode.Caption = CompanyCode
   nfoCompanySubCode.Caption = SubCompanyCode
   nfoCompanyName.Caption = CompanyName
      
   tabLoadSalary.TabEnabled(1) = True
   tabLoadSalary.TabEnabled(2) = False
   tabLoadSalary.CurrTab = VALIDATION_TAB
   
   txtCompanySalaryFile.Text = ""
   txtResult.Text = ""
   cmdValidate.Enabled = False
   cmdBrowse.Enabled = True
   txtCompanySalaryFile.Enabled = True

   lvwJournalLog.ListItems.Clear
   lvwFaultRecord.ListItems.Clear
   
   nfoLoadResult.Caption = ""
   
   m_ValidFile = False

   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub tpCmpySearch_SearchEnter()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "tpCmpySearch_SearchEnter"

   RaiseEvent ButtonClick(RETRIEVE_BUTTON)
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Function ProcessingDate() As Date
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "ProcessingDate"
   
   Const YEAR_LENGTH = 4
   Const MONTH_START = YEAR_LENGTH + 1
   Const MONTH_LENGTH = 2
   Const DAY_LENGTH = 2

   Dim AttributeValue As Variant
   
   Dim ServerDate As String
   Dim Year As String
   Dim Month As String
   Dim Day As String
   
   RaiseEvent GetAttribute(CURRENT_PROCESSING_DATE_ATTRIB, AttributeValue)
   
   ServerDate = CStr(AttributeValue)
   Year = Left$(ServerDate, YEAR_LENGTH)
   Month = Mid$(ServerDate, MONTH_START, MONTH_LENGTH)
   Day = Right$(ServerDate, DAY_LENGTH)

   ProcessingDate = DateSerial(CInt(Year), CInt(Month), CInt(Day))

   Exit Function
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

Private Sub InitialJournalLog()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "InitialJournalLog"

   Dim clmAdd As ColumnHeader
   Dim imgX As ListImage
     
   lvwJournalLog.Icons = iilsLoglIcon        ' Set Icons property.
   lvwJournalLog.SmallIcons = iilsLoglIcon   ' Set Small Icons property.
   
   'Add two Column Headers to the ListView control
   
   Set clmAdd = lvwJournalLog.ColumnHeaders.Add(Text:=m_Resource.LoadString(eResourceStrings.tpLogType), Width:=1300)
   Set clmAdd = lvwJournalLog.ColumnHeaders.Add(Text:=m_Resource.LoadString(eResourceStrings.tpLogDate), Width:=1800)
   Set clmAdd = lvwJournalLog.ColumnHeaders.Add(Text:=m_Resource.LoadString(eResourceStrings.tpLogDescription), Width:=4850)
   
   'Set the view property of the Listview control to Report view
   lvwJournalLog.View = lvwReport

   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub
       
Private Sub InsertJournalLog(LogType As eJournalLogType, ByVal LogMessage As String)
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "InsertJournalLog"
   
   Dim itmAdd As ListItem
        
   'Add data to the ListView control
   Select Case LogType
      Case INFORMATION_LOG
         Set itmAdd = lvwJournalLog.ListItems.Add(Text:="Information", SmallIcon:="Information")
      Case WARNING_LOG
         Set itmAdd = lvwJournalLog.ListItems.Add(Text:="Warning", SmallIcon:="Warning")
         m_RecErrKey = m_RecErrKey + 1
         itmAdd.Tag = CStr(m_RecErrKey)
      Case ERROR_LOG
         Set itmAdd = lvwJournalLog.ListItems.Add(Text:="Error", SmallIcon:="Error")
         m_RecErrKey = m_RecErrKey + 1
         itmAdd.Tag = CStr(m_RecErrKey)
   End Select
      
   itmAdd.SubItems(1) = Format(m_ProcessingDate, "dd/mm/yyyy hh:mm:ss")
   itmAdd.SubItems(2) = LogMessage
   
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub txtCompanySalaryFile_Change()
   On Error GoTo ErrorHandler

   Const SUBROUTINE As String = "txtCompanySalaryFile_Change"
   
   If Len(Trim(txtCompanySalaryFile.Text)) = 0 Then
      cmdValidate.Enabled = False
   Else
      cmdValidate.Enabled = True
   End If
   
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Sub InsertFaultRecord(RNo As Long, DataStr As String)
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "InsertFaultRecord"
   
   Dim itmAdd As ListItem
   
   Set itmAdd = lvwFaultRecord.ListItems.Add(Text:=CStr(RNo))
   'With RInfo(RNo)
      'itmAdd.SubItems(1) = .CompanyCode & " " & .TransactionType & " " & .AccountNumber & " " & _
                           .HomeBranch & " " & .EmployeeNumber & " " & .RecordCode & " " & _
                           .Amount & " " & .ItemNumber
    itmAdd.SubItems(1) = DataStr
   'End With
   itmAdd.Tag = CStr(m_RecErrKey)
   
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub
            
Private Sub InsertFaultRecordStr(RNo As Long, ByVal RText As String)
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "InsertFaultRecordStr"
   
   Dim itmAdd As ListItem
   
   Set itmAdd = lvwFaultRecord.ListItems.Add(Text:=CStr(RNo))
   itmAdd.SubItems(1) = RText
   itmAdd.Tag = CStr(m_RecErrKey)
   
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub
            
Private Sub InitialFaultRecord()
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "InitialFaultRecord"
   
   Dim clmAdd As ColumnHeader
    
   Set clmAdd = lvwFaultRecord.ColumnHeaders.Add(Text:=m_Resource.LoadString(eResourceStrings.tpFaultRecordNo), Width:=600)
   Set clmAdd = lvwFaultRecord.ColumnHeaders.Add(Text:=m_Resource.LoadString(eResourceStrings.tpFaultData), Width:=7100)
   
   'Set the view property of the Listview control to Report view
   lvwFaultRecord.View = lvwReport
   
   Exit Sub
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Sub

Private Function ReadSalaryFile() As Boolean
   On Error GoTo ErrorHandler
   Const SUBROUTINE As String = "ReadSalaryFile"

   Const ForReading = 1, ForWriting = 2, ForAppending = 8
   Const REC_SIZE As Long = 162
   Const MAX_REC As Long = 100000
   Const MAX_ARRAY As Long = 1000
   Dim SkipRecordCount As Integer
   Dim fso, ts, filFile
   Dim fz As Long
   Dim i As Long
   Dim PercentRead As Integer
   Dim S As String
   Dim DataValid As Boolean
   Dim AccountValid As Boolean
   Dim AIndex As Integer
   Dim ACount As Integer
   Dim T_RecordType As String * 1
   ReDim CompSalaryRec(1 To MAX_ARRAY)
   ReDim CompSalary160_D(1 To MAX_ARRAY)
   ReDim AccountRec(1 To MAX_ARRAY)
   Dim T_LastSequenceNo As String * 6
   Dim CountDetail As Long
   Set fso = CreateObject("Scripting.FileSystemObject")
   Set filFile = fso.GetFile(StrPath)
   ' Open file as text stream for reading.
   Set ts = filFile.OpenAsTextStream(ForReading)
    LoginUserId = Right(m_ProcBranch, 3) & M_TELLER_ID & "S"
   fz = filFile.Size
   If fz = 0 Then
      Call InsertJournalLog(WARNING_LOG, txtCompanySalaryFile.Text & " no data.")
      ReadSalaryFile = False
      Exit Function
   End If
   If CLng(fz / REC_SIZE) < 3 Then
      Call InsertJournalLog(WARNING_LOG, txtCompanySalaryFile.Text & " Data In file must more than or equal 3 record .....")
      ReadSalaryFile = False
      Exit Function
   End If
   SkipRecordCount = 0
   m_OwnerBranch = ""
   m_TotalItem = 0
   m_TotalAmount = 0#
   m_DepositItem = 0
   m_DepositAmount = 0#
   m_DeductItem = 0
   m_DeductAmount = 0#
    CountDetail = 0
    m_RecErrKey = 0
    
    m_NoOf_DR_Transaction = 0
    m_Total_DR_Amount = 0
    m_NoOf_CR_Transaction = 0
    m_Total_CR_Amount = 0
    
    m_NoOfReject_DR_Transaction = 0
    m_TotalReject_DR_Amount = 0
    m_NoOfReject_CR_Transaction = 0
    m_TotalReject_CR_Amount = 0
    
   i = 1
   ACount = 1
   DataValid = True
   txtResult.Text = ""
   Call InsertJournalLog(INFORMATION_LOG, "Start reading Company Salary 160C  data from diskette.")
   
   'Loop while not at the end of the file.
   Do While Not ts.AtEndOfStream
        S = ts.ReadLine
        
        If Len(S) <> REC_SIZE - 2 Then
            'buncha modify on date 17/06/2004
            ' Skip the last Data record if data is space (char(20))
            If i > Int(fz / REC_SIZE) Then
                If Trim(S) = "" Then
                    'Skip this Line
                    SkipRecordCount = SkipRecordCount + 1
                Else
                    Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Record.")
                    Call InsertFaultRecordStr(i, S)
                    DataValid = False
                End If
            '------------------------------------------------------
            Else
                Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Record.")
                Call InsertFaultRecordStr(i, S)
                DataValid = False
            End If
        Else
             '================================================
            T_RecordType = Left(S, 1)
            Select Case UCase(T_RecordType)
                Case "H"  'ส่วนของ Header
                    CompSalary160_H.RecordType = "H"
                    CompSalary160_H.SequenceNumber = Mid(S, 2, 6)
                    CompSalary160_H.BankCode = Mid(S, 8, 3)
                    CompSalary160_H.CompanyAccountNo = Mid(S, 11, 12)
                    CompSalary160_H.CompanyName = Mid(S, 23, 40)
                    CompSalary160_H.PostDate = Mid(S, 63, 6)
                    CompSalary160_H.Spare1 = Mid(S, 69, 40)
                    CompSalary160_H.SubCompanyCode = Mid(S, 109, 2)
                    CompSalary160_H.CompanyID = Mid(S, 111, 4)
                    CompSalary160_H.tmbFlag = Mid(S, 115, 6)
                    CompSalary160_H.Spare2 = Mid(S, 121, 40)
                    'Validate Data
                    'SequenceNumber must be "000001"
                    If CompSalary160_H.SequenceNumber <> "000001" Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Sequence Number for Header Record")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If
                    If CompSalary160_H.CompanyID <> nfoCompanyCode.Caption Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Company Code.")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If
                    'Valid  Sub Company Code
                    If CompSalary160_H.SubCompanyCode <> nfoCompanySubCode.Caption Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Sub Company Code in Heder  record .")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If

                    
                    'Valid Account Number
                    'AccountValid = False
                    If Len(Trim(CompSalary160_H.CompanyAccountNo)) <> 12 Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Lenght of Account. (Header) ")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    Else
                        'buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                        If Mid(CompSalary160_H.CompanyAccountNo, 6, 1) <> "1" And Mid(CompSalary160_H.CompanyAccountNo, 6, 1) <> "2" And Mid(CompSalary160_H.CompanyAccountNo, 6, 1) <> "7" And Mid(CompSalary160_H.CompanyAccountNo, 6, 1) <> "9" Then
                        'End buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Type.(Header) ")
                           Call InsertFaultRecord(i, S)
                           DataValid = False
                        Else
                           If Not IsNumericStr(CompSalary160_H.CompanyAccountNo) Then
                              Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number. (Header) ")
                              Call InsertFaultRecord(i, S)
                              DataValid = False
                           Else
                              If Not ValidCheckDigit(NUMTYPE_ACCOUNT, Right(CompSalary160_H.CompanyAccountNo, 10)) Then
                                 Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number. (Header) ")
                                 Call InsertFaultRecord(i, S)
                                 DataValid = False
                                 'DataValid = True
                              Else
                                 'AccountValid = True
                              End If
                           End If
                        End If
                    End If
                    
                    
                    T_LastSequenceNo = "000001"
                Case "D" 'Detail
                    CountDetail = CountDetail + 1
                    With CompSalary160_D(CountDetail)
                        .RecordType = Mid(S, 1, 1)
                        .SequenceNumber = Mid(S, 2, 6)
                        .BankCode = Mid(S, 8, 3)
                        .AccountNumber = Mid(S, 11, 12)
                        .TransactionCode = Mid(S, 23, 1)
                        .Amount = Mid(S, 24, 12)
                        .ServiceType = Mid(S, 36, 2)
                        .status = Mid(S, 38, 1)
                        .ReferenceArea1 = Mid(S, 39, 20)
                        .InserviceDate = Mid(S, 59, 6)
                        .CompanyCode = Mid(S, 65, 4)
                        .HomeBranch = Mid(S, 69, 3)
                        .ReferenceArea2 = Mid(S, 72, 20)
                        .tmbFlag = Mid(S, 92, 6)
                        .CompanyCode2 = Mid(S, 98, 4)
                        .SubCompanyCode = Mid(S, 102, 2)
                        .spare = Mid(S, 104, 14)
                        .Name = Mid(S, 118, 35)
                        .TellerID = Mid(S, 153, 8)
                        
                        'Validate  Data
                        'Valid Sequence Number Must start with "000002"
                        If .SequenceNumber <> Format(Val(T_LastSequenceNo) + 1, "000000") Then
                            Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Sequence Number for Detail  Record")
                            Call InsertFaultRecord(i, S)
                            DataValid = False
                        End If
                        
''                        'Valid Bank Code
''                        If .BankCode <> "001" Then
''                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Bank Code.")
''                           Call InsertFaultRecord(i, s)
''                           DataValid = False
''                        End If
                        

                        'Valid Account Number
                        'AccountValid = False
                        If Len(Trim(.AccountNumber)) <> 12 Then
                            Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Lenght of Account. ")
                            Call InsertFaultRecord(i, S)
                            DataValid = False
                        Else
                            'buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                            If Mid(.AccountNumber, 6, 1) <> "1" And Mid(.AccountNumber, 6, 1) <> "2" And Mid(.AccountNumber, 6, 1) <> "7" And Mid(.AccountNumber, 6, 1) <> "9" Then
                            ' end buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Type.")
                               Call InsertFaultRecord(i, S)
                               DataValid = False
                            Else
                               If Not IsNumericStr(.AccountNumber) Then
                                  Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.")
                                  Call InsertFaultRecord(i, S)
                                  DataValid = False
                               Else
                                  If Not ValidCheckDigit(NUMTYPE_ACCOUNT, Right(.AccountNumber, 10)) Then
                                  'If Not ValidCheckDigit(NUMTYPE_ACCOUNT, .AccountNumber) Then
                                     Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.")
                                     Call InsertFaultRecord(i, S)
                                     DataValid = False
                                  Else
                                     'AccountValid = True
                                  End If
                               End If
                            End If
                        End If
                        
                        'Transaction Code
                        If .TransactionCode <> P_TransactionCode_Credit And .TransactionCode <> P_TransactionCode_Debit Then
                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Transaction  Code.")
                           Call InsertFaultRecord(i, S)
                           DataValid = False
                        End If
                        
                        'Validate Header.PostDate  must equal Detail.InserviceDate
                        If CompSalary160_H.PostDate <> FormatStrDateYYMMDDtoDDMMYY(.InserviceDate) Then
                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Header.PostDate <> Detail.InserviceDate")
                           Call InsertFaultRecord(i, S)
                           DataValid = False
                        End If
                        
                        'Valid Amount
                        If Not IsNumericStr(.Amount) Then
                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Amount.")
                           Call InsertFaultRecord(i, S)
                           DataValid = False
                        Else
                           If Len(Trim(.Amount)) <> 12 Then
                              Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Amount.")
                              Call InsertFaultRecord(i, S)
                              DataValid = False
                           Else
                              If CCur(.Amount) <= 0 Then
                                 Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Amount cannot be zero.")
                                 Call InsertFaultRecord(i, S)
                                 DataValid = False
                              Else
                                Select Case .TransactionCode
                                    Case P_TransactionCode_Debit    '"D"
                                        m_NoOf_DR_Transaction = m_NoOf_DR_Transaction + 1
                                        m_Total_DR_Amount = m_Total_DR_Amount + CCur(.Amount) / Divide100ForDicimalPoint
                                    Case P_TransactionCode_Credit   '"C"
                                        m_NoOf_CR_Transaction = m_NoOf_CR_Transaction + 1
                                        m_Total_CR_Amount = m_Total_CR_Amount + CCur(.Amount) / Divide100ForDicimalPoint
                                    Case P_TransactionCode_RejectDebit  '
                                        m_NoOfReject_DR_Transaction = m_NoOfReject_DR_Transaction + 1
                                        m_TotalReject_DR_Amount = m_TotalReject_DR_Amount + CCur(.Amount) / Divide100ForDicimalPoint
                                    Case P_TransactionCode_RejectCredit '
                                        m_NoOfReject_DR_Transaction = m_NoOfReject_DR_Transaction + 1
                                        m_TotalReject_DR_Amount = m_TotalReject_DR_Amount + CCur(.Amount) / Divide100ForDicimalPoint
                                End Select
                              End If
                           End If
                        End If

''                        'Valid Service Type
''                        If .ServiceType <> "08" Or .ServiceType <> "08" Then
''                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Service Type  Code.")
''                           Call InsertFaultRecord(i, s)
''                           DataValid = False
''                        End If
                        
                        'Valid  Company Code
                        If .CompanyCode <> nfoCompanyCode.Caption Then
                            Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Company Code in detail record .")
                            Call InsertFaultRecord(i, S)
                            DataValid = False
                        End If
                        
                        'Valid Home Branch
                        ' User Id 0011997S and 0011998S  not Check HomeBranch
                        If Val(.HomeBranch) > 0 Then
                            If LoginUserId = "0011997S" Or LoginUserId = "0011998S" Then
                                'Can do Next Step
                                m_OwnerBranch = Format(m_ProcBranch, "000")
                            Else
                                ' Processing Branch = "001" Not Allow to Process Company Code "7100" to "7110"
                                 m_OwnerBranch = .HomeBranch
                                If Right(m_ProcBranch, 3) = "001" And Val(.CompanyCode) >= Val("7100") And Val(.CompanyCode) <= Val("7110") Then
                                    'Not Allow to Load this File
                                    Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Not Allow To Load This Company Code ")
                                    Call InsertFaultRecord(i, S)
                                    Call InsertJournalLog(INFORMATION_LOG, "Error : This Company Code not allow to load for this user ")
                                    DataValid = False
                                    ts.Close
                                    ReadSalaryFile = DataValid
                                    Exit Function
                                Else
                                    ' verify if m_ProcBranch <>  home_Branch in data then not allow to load data
                                    If Right(m_ProcBranch, 3) <> .HomeBranch Then
                                       Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Home Branch.")
                                       Call InsertFaultRecord(i, S)
                                       Call InsertJournalLog(INFORMATION_LOG, "Error : Home Branch in your Data not equal Current Processing Branch ")
                                        DataValid = False
                                       'DataValid = True
                                       ts.Close
                                       ReadSalaryFile = DataValid
                                       Exit Function
                                    End If
                                End If
                            End If
                        Else ' home Branch Is 0
                            Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Home Branch.")
                            Call InsertFaultRecord(i, S)
                            Call InsertJournalLog(INFORMATION_LOG, "Error : Home Branch in your Data Is equal 0 Or Less than 0 ")
                            DataValid = False
                        End If
                                                
                        'Valid  Sub Company Code
                        If .SubCompanyCode <> nfoCompanySubCode.Caption Then
                            Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Sub Company Code in detail record .")
                            Call InsertFaultRecord(i, S)
                            DataValid = False
                        End If
                        
                        

                    End With
                    T_LastSequenceNo = Format(Val(T_LastSequenceNo) + 1, "000000")
                Case "T" ' End
                    CompSalary160_E.RecordType = Mid(S, 1, 1)
                    CompSalary160_E.SequenceNumber = Mid(S, 2, 6)
                    CompSalary160_E.BankCode = Mid(S, 8, 3)
                    CompSalary160_E.CompanyAccountNo = Mid(S, 11, 12)
                    CompSalary160_E.NoOf_DR_Transaction = Mid(S, 23, 7)
                    CompSalary160_E.Total_DR_Amount = Mid(S, 30, 15)
                    CompSalary160_E.NoOf_CR_Transaction = Mid(S, 45, 7)
                    CompSalary160_E.Total_CR_Amount = Mid(S, 52, 15)
                    CompSalary160_E.NoOfReject_DR_Transaction = Mid(S, 67, 7)
                    CompSalary160_E.TotalReject_DR_Amount = Mid(S, 74, 15)
                    CompSalary160_E.NoOfReject_CR_Transaction = Mid(S, 89, 7)
                    CompSalary160_E.TotalReject_CR_Amount = Mid(S, 96, 15)
                    CompSalary160_E.CompanyID = Mid(S, 111, 4)
                    CompSalary160_E.tmbFlag = Mid(S, 115, 6)
                    CompSalary160_E.SubCompanyCode = Mid(S, 121, 2)
                    CompSalary160_E.spare = Mid(S, 123, 38)
                    
                    'Validate Data
                    'Valid Account Number
                    If Len(Trim(CompSalary160_E.CompanyAccountNo)) <> 12 Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Lenght of Account. (Trailer) ")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    Else
                        'buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                        If Mid(CompSalary160_E.CompanyAccountNo, 6, 1) <> "1" And Mid(CompSalary160_E.CompanyAccountNo, 6, 1) <> "2" And Mid(CompSalary160_E.CompanyAccountNo, 6, 1) <> "7" And Mid(CompSalary160_E.CompanyAccountNo, 6, 1) <> "9" Then
                        'End buncha Modify on Date 13/07/2007 Bank Add New  Account  Type 9 for Saving Account
                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Type.(Trailer)  ")
                           Call InsertFaultRecord(i, S)
                           DataValid = False
                        Else
                           If Not IsNumericStr(CompSalary160_E.CompanyAccountNo) Then
                              Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.(Trailer)  ")
                              Call InsertFaultRecord(i, S)
                              DataValid = False
                           Else
                              If Not ValidCheckDigit(NUMTYPE_ACCOUNT, Right(CompSalary160_E.CompanyAccountNo, 10)) Then
                                 Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.(Trailer)  ")
                                 Call InsertFaultRecord(i, S)
                                 DataValid = False
                              Else
                                 'AccountValid = True
                              End If
                           End If
                        End If
                    End If

                    
                    'SequenceNumber must be  Last SequenceNumber+1
                    If CompSalary160_E.SequenceNumber <> Format(Val(T_LastSequenceNo) + 1, "000000") Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Sequence Number for Trailer  Record")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If
                    If CompSalary160_E.CompanyID <> nfoCompanyCode.Caption Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Company Code.")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If
                    If m_NoOf_DR_Transaction <> CompSalary160_E.NoOf_DR_Transaction Or m_Total_DR_Amount <> CCur(CompSalary160_E.Total_DR_Amount) / Divide100ForDicimalPoint _
                     Or m_NoOf_CR_Transaction <> CompSalary160_E.NoOf_CR_Transaction Or m_Total_CR_Amount <> CCur(CompSalary160_E.Total_CR_Amount) / Divide100ForDicimalPoint _
                     Or m_NoOfReject_DR_Transaction <> CompSalary160_E.NoOfReject_DR_Transaction Or m_TotalReject_DR_Amount <> CCur(CompSalary160_E.TotalReject_DR_Amount) / Divide100ForDicimalPoint _
                     Or m_NoOfReject_CR_Transaction <> CompSalary160_E.NoOfReject_CR_Transaction Or m_TotalReject_CR_Amount <> CCur(CompSalary160_E.TotalReject_CR_Amount) / Divide100ForDicimalPoint Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Summary Data of detail and trial not Equal ")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If
                    
                    If CompSalary160_E.CompanyAccountNo <> CompSalary160_H.CompanyAccountNo Then
                        Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Account No Header not equal Trailer Account No")
                        Call InsertFaultRecord(i, S)
                        DataValid = False
                    End If

                Case Else
                    DataValid = False
            End Select
        End If
                
        '-================================================
        
        
'''         With CompSalaryRec(i)
'''            .CompanyCode = Mid(s, 1, 4)
'''            .TransactionType = Mid(s, 5, 2)
'''            .AccountNumber = Mid(s, 7, 10)
'''            .HomeBranch = Mid(s, 17, 3)
'''            .EmployeeNumber = Mid(s, 20, 7)
'''            .RecordCode = Mid(s, 27, 1)
'''            .Amount = Mid(s, 28, 12)
'''            .ItemNumber = Mid(s, 40, 2)
'''            '----------------------------------------------------------------------
'''            'buncha Modify on date 12/07/2006 User "0011997S","0011998S" Not check HomeBranch
'''            LoginUserId = Right(m_ProcBranch, 3) & M_TELLER_ID & "S"
'''            If LoginUserId = "0011997S" Or LoginUserId = "0011998S" Then
'''                'Can do Next Step
'''            Else
'''            '-------------------------------------------------------------------------
'''                'buncha Modify on date 14/07/2006 Processing Branch = "001" Not Allow to Process Company Code "7100" to "7110"
'''                If Right(m_ProcBranch, 3) = "001" And Val(.CompanyCode) >= Val("7100") And Val(.CompanyCode) <= Val("7110") Then
'''                    'Not Allow to Load this File
'''                    Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Not Allow To Load This Company Code ")
'''                    Call InsertFaultRecord(i, CompSalaryRec())
'''                    Call InsertJournalLog(INFORMATION_LOG, "Error : This Company Code not allow to load for this user ")
'''                    DataValid = False
'''                    ts.Close
'''                    ReadSalaryFile = DataValid
'''                    Exit Function
'''                Else
'''                'buncha Modify on date 14/07/2006 Processing Branch = "001" Not Allow to Process Company Code "7100" to "7110"
'''                    '-----------------------------------------------------------------------
'''                    'Buncha add on date 03/10/2003 verify if m_ProcBranch <>  home_Branch in data then not allow to load data
'''                    If Right(m_ProcBranch, 3) <> .HomeBranch Then
'''                       Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Home Branch.")
'''                       Call InsertFaultRecord(i, CompSalaryRec())
'''                       Call InsertJournalLog(INFORMATION_LOG, "Error : Home Branch in your Data not equal Current Processing Branch ")
'''                       DataValid = False
'''                       ts.Close
'''                       ReadSalaryFile = DataValid
'''                       Exit Function
'''                    End If
'''                    '-----------------------------------------------------------------------
'''                End If
'''                '-----------------------------------------------------------------------
'''            End If
'''            '----------------------End  buncha Modify on date 12/07/2006 User "0011997S","0011998S" Not check HomeBranch------------------------------------------------
'''
'''            If .CompanyCode <> nfoCompanyCode.Caption Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Company Code.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            End If
'''
'''            If .TransactionType <> "08" And .TransactionType <> "06" Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Transaction Type.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            End If
'''
'''            AccountValid = False
'''            If Mid(.AccountNumber, 4, 1) <> "1" And Mid(.AccountNumber, 4, 1) <> "2" And Mid(.AccountNumber, 4, 1) <> "7" Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Type.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            Else
'''               If Not IsNumericStr(.AccountNumber) Then
'''                  Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.")
'''                  Call InsertFaultRecord(i, CompSalaryRec())
'''                  DataValid = False
'''               Else
'''                  If Not ValidCheckDigit(NUMTYPE_ACCOUNT, .AccountNumber) Then
'''                     Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Account Number.")
'''                     Call InsertFaultRecord(i, CompSalaryRec())
'''                     DataValid = False
'''                  Else
'''                     AccountValid = True
'''                  End If
'''               End If
'''            End If
'''
'''            '----------------------------------------------------------------------
'''            'buncha Modify on date 12/07/2006 User "0011997S","0011998S" Not check HomeBranch
'''            If LoginUserId = "0011997S" Or LoginUserId = "0011998S" Then
'''                'Can do Next Step
'''                m_OwnerBranch = Format(m_ProcBranch, "000")
'''            Else
'''                If i = 1 Then
'''                    m_OwnerBranch = .HomeBranch
'''                Else
'''                    If .HomeBranch <> m_OwnerBranch Then
'''                       Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Home Branch.")
'''                       Call InsertFaultRecord(i, CompSalaryRec())
'''                       DataValid = False
'''                    End If
'''               End If
'''            End If
'''
'''            If Not IsNumericStr(.EmployeeNumber) Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Employee Number.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            Else
'''               If .EmployeeNumber = Space(7) Then
'''                  .EmployeeNumber = "0000000"
'''               End If
'''            End If
'''
'''            If .RecordCode <> "1" And .RecordCode <> "2" Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Record Code.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            End If
'''
'''            If Not IsNumericStr(.Amount) Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Amount.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            Else
'''               If Len(Trim(.Amount)) <> 12 Then
'''                  Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Amount.")
'''                  Call InsertFaultRecord(i, CompSalaryRec())
'''                  DataValid = False
'''               Else
'''                  If CDbl(.Amount) <= 0 Then
'''                     Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Amount cannot be zero.")
'''                     Call InsertFaultRecord(i, CompSalaryRec())
'''                     DataValid = False
'''                  Else
'''                     If .RecordCode = "1" Then
'''                        m_DeductItem = m_DeductItem + 1
'''                        m_DeductAmount = m_DeductAmount + CDbl(.Amount) / 100
'''                     ElseIf .RecordCode = "2" Then
'''                           m_DepositItem = m_DepositItem + 1
'''                           m_DepositAmount = m_DepositAmount + CDbl(.Amount) / 100
'''                     End If
'''                  End If
'''               End If
'''            End If
'''
'''
'''            If Not IsNumericStr(.ItemNumber) Then
'''               Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Item Number.")
'''               Call InsertFaultRecord(i, CompSalaryRec())
'''               DataValid = False
'''            Else
'''               If CInt(.ItemNumber) <= 0 Then
'''                  Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid Item Number.")
'''                  Call InsertFaultRecord(i, CompSalaryRec())
'''                  DataValid = False
'''               Else
'''                  If AccountValid Then
'''                     AIndex = GetAccountIndex(AccountRec(), .AccountNumber, ACount)
'''
'''                     If AIndex = 0 Then
'''                        AccountRec(ACount).AccountNumber = .AccountNumber
'''                        AccountRec(ACount).ItemNo = 1
'''                        ACount = ACount + 1
'''                        If (.ItemNumber) <> "01" Then
'''                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid sequence of Item Number.")
'''                           Call InsertFaultRecord(i, CompSalaryRec())
'''                           DataValid = False
'''                        End If
'''                     Else
'''                        AccountRec(AIndex).ItemNo = AccountRec(AIndex).ItemNo + 1
'''                        If (.ItemNumber) <> Format(AccountRec(AIndex).ItemNo, "00") Then
'''                           Call InsertJournalLog(WARNING_LOG, "Rec#" & CStr(i) & " Invalid sequence of Item Number.")
'''                           Call InsertFaultRecord(i, CompSalaryRec())
'''                           DataValid = False
'''                        End If
'''                     End If
'''
'''                     If ACount Mod MAX_ARRAY = 0 Then
'''                        ReDim Preserve AccountRec(1 To UBound(AccountRec) + MAX_ARRAY)
'''                     End If
'''                  End If 'Validate Item Number
'''
'''               End If
'''            End If
'''
'''         End With
      
'''      End If
       
        PercentRead = Int(((i * REC_SIZE) * 100) / fz)
        If PercentRead > 100 Then PercentRead = 100
        txtResult.Text = "Processing... " & CStr(PercentRead) & "%"
      
        DoEvents
      
        i = i + 1
        If i >= MAX_REC Then
            Call InsertJournalLog(ERROR_LOG, "Total records over maximum.")
            DataValid = False
            Exit Do
        End If
      
        If i Mod MAX_ARRAY = 0 Then
            'ReDim Preserve CompSalaryRec(1 To UBound(CompSalaryRec) + MAX_ARRAY)
            ReDim Preserve CompSalary160_D(1 To UBound(CompSalary160_D) + MAX_ARRAY)
        End If
    Loop
   
    m_TotalRecord = (i - 1) - SkipRecordCount
   
    m_TotalItem = m_DepositItem + m_DeductItem
    m_TotalAmount = m_DepositAmount + m_DeductAmount
            
   'Close the file.
    ts.Close
   
    Call InsertJournalLog(INFORMATION_LOG, "Finish reading " & txtCompanySalaryFile.Text & " for " & nfoCompanyCode.Caption & "/" & nfoCompanySubCode.Caption & " from diskette.")
    ReadSalaryFile = DataValid
    
    
    Exit Function
   
ErrorHandler:
    'Debug.Assert False
    ReadSalaryFile = False
    'Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
    Dim m_Error As New AtpOError
    m_Error.Source = SUBROUTINE
    m_Error.Number = TYPE_FATALTRANSACTION
    m_Error.Description = str(Err.Number) & "  " & Err.Description
    RaiseEvent DisplayMessage(m_Error)
    
   ' Resume Next
End Function

Private Function GetAccountIndex(AccountList() As AccoutRecord, ByVal AccountNumber As String, n As Integer) As Integer
   On Error GoTo ErrorHandler
   
   Const SUBROUTINE As String = "GetAccountIndex"
   
   Dim i As Integer
   Dim bFound As Boolean
   
   GetAccountIndex = 0
   bFound = False
   i = 1
   Do While i < n And Not bFound
      If AccountList(i).AccountNumber = AccountNumber Then
         GetAccountIndex = i
         bFound = True
      Else
         i = i + 1
      End If
   Loop

   Exit Function
    
ErrorHandler:
   Debug.Assert False
   Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

Private Function FormatStrDateYYMMDDtoDDMMYY(ByVal StrDateYYMMDD As String) As String
    On Error GoTo ErrorHandler
   
    Const SUBROUTINE As String = "GetAccountIndex"
   
    Dim i As Integer
    Dim bFound As Boolean
    If Len(StrDateYYMMDD) <> 6 Then
        FormatStrDateYYMMDDtoDDMMYY = ""
    Else
        FormatStrDateYYMMDDtoDDMMYY = Right(StrDateYYMMDD, 2) & Mid(StrDateYYMMDD, 3, 2) & Left(StrDateYYMMDD, 2)
    End If
   

    Exit Function
    
ErrorHandler:
    FormatStrDateYYMMDDtoDDMMYY = ""
    Debug.Assert False
    Call Err.Raise(Err.Number, SUBROUTINE, Err.Description)
End Function

