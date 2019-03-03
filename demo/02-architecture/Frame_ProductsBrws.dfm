object FrameProductsBrws: TFrameProductsBrws
  Left = 0
  Top = 0
  Width = 517
  Height = 307
  TabOrder = 0
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 104
    Top = 63
    Width = 305
    Height = 185
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 511
    Height = 54
    Align = alTop
    Caption = 'GroupBox1'
    Padding.Top = 2
    Padding.Bottom = 2
    TabOrder = 1
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 20
      Width = 100
      Height = 27
      Align = alLeft
      Caption = 'Button1'
      TabOrder = 0
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 431
      Top = 20
      Width = 75
      Height = 27
      Align = alRight
      Caption = 'Zamknij'
      TabOrder = 1
      OnClick = actCloseExecute
    end
  end
  object DataSource1: TDataSource
    DataSet = DataModule2.dsProductsBrws
    Left = 40
    Top = 120
  end
  object ActionList1: TActionList
    Left = 40
    Top = 56
  end
end
