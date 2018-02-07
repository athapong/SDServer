VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "AcsRDLoadDatFrDiskENU"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Implements AtpAResources
  
Private Enum eResourceType
   tpBitmapResource = 0
   tpIconResource = 1
End Enum
 
Private m_InTestMode

Private Property Let AtpAResources_InTestMode(ByVal RHS As Boolean)
   m_InTestMode = RHS
End Property

Private Property Get AtpAResources_InTestMode() As Boolean
   AtpAResources_InTestMode = m_InTestMode
End Property

Private Function AtpAResources_LoadBitmap(ByVal ResourceID As Integer) As stdole.Picture
   Set AtpAResources_LoadBitmap = LoadResPicture(ResourceID, eResourceType.tpBitmapResource)
End Function

Private Function AtpAResources_LoadIcon(ByVal ResourceID As Integer) As stdole.Picture
   Set AtpAResources_LoadIcon = LoadResPicture(ResourceID, eResourceType.tpIconResource)
End Function

Private Function AtpAResources_LoadString(ByVal ResourceID As Integer) As String
   Const TEST_PREFIX As String = "T="

   If m_InTestMode Then
      AtpAResources_LoadString = TEST_PREFIX & LoadResString(ResourceID)
   Else
      AtpAResources_LoadString = LoadResString(ResourceID)
   End If
End Function

Private Sub Class_Initialize()
   m_InTestMode = False

End Sub

