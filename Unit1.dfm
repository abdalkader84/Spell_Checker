object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 299
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
  object Memo1: TMemo
    Left = 24
    Top = 16
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    Visible = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 264
    Width = 635
    Height = 35
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitLeft = -54
    ExplicitWidth = 689
    object Button1: TButton
      AlignWithMargins = True
      Left = 557
      Top = 5
      Width = 75
      Height = 25
      Margins.Top = 5
      Margins.Bottom = 5
      Align = alRight
      Caption = 'check'
      TabOrder = 0
      OnClick = Button1Click
      ExplicitLeft = 560
      ExplicitTop = 8
    end
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 0
    Width = 635
    Height = 264
    Align = alClient
    Font.Charset = ARABIC_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 2
    Zoom = 100
    ExplicitLeft = -54
    ExplicitWidth = 689
  end
end
