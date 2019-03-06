object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 577
  ClientWidth = 798
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    AlignWithMargins = True
    Left = 3
    Top = 58
    Width = 792
    Height = 206
    Align = alTop
    OnPaint = PaintBox1Paint
    ExplicitLeft = -2
  end
  object GroupBox1: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 792
    Height = 49
    Align = alTop
    Caption = 'GroupBox1'
    Padding.Bottom = 1
    TabOrder = 0
    object Button1: TButton
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 124
      Height = 25
      Action = actRunQuickSort
      Align = alLeft
      Caption = 'Sortuj szybko'
      TabOrder = 0
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 135
      Top = 18
      Width = 124
      Height = 25
      Action = actRunBubbleSort
      Align = alLeft
      TabOrder = 1
    end
    object Button3: TButton
      AlignWithMargins = True
      Left = 265
      Top = 18
      Width = 124
      Height = 25
      Action = actShuflleData
      Align = alLeft
      TabOrder = 2
    end
  end
  object tmrReady: TTimer
    Interval = 1
    OnTimer = tmrReadyTimer
    Left = 32
    Top = 88
  end
  object ActionList1: TActionList
    Left = 104
    Top = 88
    object actRunQuickSort: TAction
      Caption = 'Action1'
      OnExecute = actRunQuickSortExecute
    end
    object actRunBubbleSort: TAction
      Caption = 'Sortuj b'#261'belkowo'
      OnExecute = actRunBubbleSortExecute
    end
    object actShuflleData: TAction
      Caption = 'Losuj dane'
      OnExecute = actShuflleDataExecute
    end
  end
end
