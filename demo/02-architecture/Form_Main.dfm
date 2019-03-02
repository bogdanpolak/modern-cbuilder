object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 336
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 188
    Top = 0
    Width = 5
    Height = 336
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 185
    Height = 330
    Margins.Right = 0
    Align = alLeft
    Caption = 'GroupBox1'
    TabOrder = 0
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 175
      Height = 25
      Action = actProductsCatalog
      Align = alTop
      TabOrder = 0
    end
  end
  object PageControl1: TPageControl
    AlignWithMargins = True
    Left = 193
    Top = 3
    Width = 439
    Height = 330
    Margins.Left = 0
    Align = alClient
    TabOrder = 1
  end
  object ActionList1: TActionList
    Left = 88
    Top = 192
    object actProductsCatalog: TAction
      Category = 'Commands'
      Caption = 'Products'
      OnExecute = actProductsCatalogExecute
    end
    object Action2: TAction
      Category = 'Commands'
      Caption = 'Action2'
    end
    object Action3: TAction
      Category = 'Commands'
      Caption = 'Action3'
    end
    object Action4: TAction
      Category = 'Commands'
      Caption = 'Action4'
    end
  end
  object tmrReady: TTimer
    Interval = 1
    OnTimer = tmrReadyTimer
    Left = 88
    Top = 240
  end
end
