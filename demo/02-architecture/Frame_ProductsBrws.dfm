object FrameProductsBrws: TFrameProductsBrws
  Left = 0
  Top = 0
  Width = 517
  Height = 307
  TabOrder = 0
  object DBGrid1: TDBGrid
    Left = 16
    Top = 16
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
  object DataSource1: TDataSource
    DataSet = DataModule2.dsProductsBrws
    Left = 248
    Top = 136
  end
end
