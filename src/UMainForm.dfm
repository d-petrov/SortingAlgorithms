object MainForm: TMainForm
  Left = 392
  Top = 183
  Width = 828
  Height = 403
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 353
    Height = 185
    Caption = 'Input'
    TabOrder = 0
    object ImportDataSetButton: TButton
      Left = 8
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Import'
      TabOrder = 0
      OnClick = ImportDataSetButtonClick
    end
    object GenerateRandomButton: TButton
      Left = 208
      Top = 24
      Width = 81
      Height = 25
      Caption = 'Generate Rand'
      TabOrder = 1
    end
    object GroupBox2: TGroupBox
      Left = 8
      Top = 64
      Width = 337
      Height = 105
      Caption = 'Preview'
      TabOrder = 2
      object DataPreviewRichEdit: TRichEdit
        Left = 8
        Top = 16
        Width = 321
        Height = 81
        TabOrder = 0
      end
    end
    object GenerateSpecificButton: TButton
      Left = 96
      Top = 24
      Width = 97
      Height = 25
      Caption = 'Generate Specific'
      TabOrder = 3
    end
  end
  object GroupBox3: TGroupBox
    Left = 0
    Top = 184
    Width = 713
    Height = 185
    Caption = 'Output '
    TabOrder = 1
    object Button1: TButton
      Left = 56
      Top = 32
      Width = 75
      Height = 25
      Caption = 'Button1'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 360
    Top = 0
    Width = 353
    Height = 185
    Caption = 'Compute'
    TabOrder = 2
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 16
      Width = 185
      Height = 153
      Caption = 'Algorithm'
      Items.Strings = (
        'Insertion sort'
        'Merge sort')
      TabOrder = 0
    end
  end
  object OpenDialog: TOpenDialog
    Left = 320
    Top = 8
  end
end
