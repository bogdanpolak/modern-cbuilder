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
    ExplicitLeft = 0
    ExplicitTop = -2
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 175
      Height = 25
      Action = actProductCatalog
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
    object actProductCatalog: TAction
      Category = 'Commands'
      Caption = 'Katalog Produkt'#243'w'
      OnExecute = actProductCatalogExecute
    end
    object actLogin: TAction
      Category = 'Commands'
      Caption = 'Zaloguj'
    end
    object actLogout: TAction
      Category = 'Commands'
      Caption = 'Wyloguj'
    end
    object actApplicationAbout: TAction
      Category = 'Commands'
      Caption = 'O Programie'
    end
  end
  object tmrReady: TTimer
    Interval = 1
    OnTimer = tmrReadyTimer
    Left = 88
    Top = 240
  end
end
