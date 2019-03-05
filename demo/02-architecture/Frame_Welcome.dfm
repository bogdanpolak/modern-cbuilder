object Frame1: TFrame1
  Left = 0
  Top = 0
  Width = 483
  Height = 345
  TabOrder = 0
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 50
    Top = 20
    Width = 383
    Height = 85
    Margins.Left = 50
    Margins.Top = 20
    Margins.Right = 50
    Align = alTop
    BevelKind = bkFlat
    BevelOuter = bvNone
    BorderWidth = 1
    Caption = 'Application logo placeholder'
    TabOrder = 0
  end
  object grbxLogin: TGroupBox
    AlignWithMargins = True
    Left = 50
    Top = 118
    Width = 383
    Height = 195
    Margins.Left = 50
    Margins.Top = 10
    Margins.Right = 50
    Align = alTop
    Caption = 'Logowanie do bazy'
    TabOrder = 1
    ExplicitTop = 126
    ExplicitWidth = 386
    DesignSize = (
      383
      195)
    object pnLogin: TPanel
      Left = 46
      Top = 32
      Width = 297
      Height = 153
      Anchors = [akTop]
      BevelOuter = bvLowered
      Caption = ' '
      Padding.Left = 5
      Padding.Top = 5
      Padding.Right = 5
      TabOrder = 0
      ExplicitLeft = 48
      object lblLogin: TLabel
        AlignWithMargins = True
        Left = 9
        Top = 9
        Width = 279
        Height = 13
        Margins.Bottom = 0
        Align = alTop
        Caption = 'U'#380'ytkownik:'
        ExplicitWidth = 58
      end
      object lblPassword: TLabel
        AlignWithMargins = True
        Left = 9
        Top = 52
        Width = 279
        Height = 13
        Margins.Bottom = 0
        Align = alTop
        Caption = 'Has'#322'o:'
        ExplicitWidth = 31
      end
      object btnLogin: TButton
        AlignWithMargins = True
        Left = 9
        Top = 102
        Width = 279
        Height = 25
        Margins.Top = 10
        Align = alTop
        Caption = 'btnLogin'
        TabOrder = 0
        ExplicitLeft = 4
        ExplicitTop = 135
        ExplicitWidth = 297
      end
      object edtLogin: TEdit
        AlignWithMargins = True
        Left = 9
        Top = 25
        Width = 279
        Height = 21
        Align = alTop
        TabOrder = 1
        Text = 'edtLogin'
        ExplicitLeft = 5
        ExplicitTop = 34
        ExplicitWidth = 376
      end
      object edtPassword: TEdit
        AlignWithMargins = True
        Left = 9
        Top = 68
        Width = 279
        Height = 21
        Align = alTop
        TabOrder = 2
        Text = 'edtPassword'
        ExplicitLeft = 5
        ExplicitTop = 50
        ExplicitWidth = 376
      end
    end
  end
end
