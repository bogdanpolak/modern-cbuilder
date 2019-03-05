object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 395
  ClientWidth = 696
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
    Height = 395
    ExplicitHeight = 336
  end
  object grbxCommands: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 185
    Height = 389
    Margins.Right = 0
    Align = alLeft
    Caption = 'Polecenia aplikacji'
    Padding.Top = 5
    TabOrder = 0
    ExplicitHeight = 330
    object Bevel1: TBevel
      AlignWithMargins = True
      Left = 5
      Top = 54
      Width = 175
      Height = 3
      Align = alTop
    end
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 23
      Width = 175
      Height = 25
      Action = actProductCatalog
      Align = alTop
      TabOrder = 0
      ExplicitTop = 18
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 5
      Top = 63
      Width = 175
      Height = 25
      Action = actApplicationAbout
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 56
      ExplicitTop = 184
      ExplicitWidth = 75
    end
    object Button3: TButton
      Left = 2
      Top = 91
      Width = 181
      Height = 25
      Action = actLogout
      Align = alTop
      TabOrder = 2
      ExplicitLeft = 64
      ExplicitTop = 215
      ExplicitWidth = 75
    end
  end
  object PageControl1: TPageControl
    AlignWithMargins = True
    Left = 193
    Top = 3
    Width = 500
    Height = 389
    Margins.Left = 0
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 439
    ExplicitHeight = 330
  end
  object ActionList1: TActionList
    Left = 72
    Top = 224
    object actProductCatalog: TAction
      Category = 'Commands'
      Caption = 'Katalog Produkt'#243'w'
      OnExecute = actProductCatalogExecute
    end
    object actLogin: TAction
      Category = 'Commands'
      Caption = 'Zaloguj'
      OnExecute = actLoginExecute
    end
    object actLogout: TAction
      Category = 'Commands'
      Caption = 'Wyloguj'
      OnExecute = actLogoutExecute
    end
    object actApplicationAbout: TAction
      Category = 'Commands'
      Caption = 'O Programie'
      OnExecute = actApplicationAboutExecute
    end
  end
  object tmrReady: TTimer
    Interval = 1
    OnTimer = tmrReadyTimer
    Left = 72
    Top = 280
  end
end
