object MainForm: TMainForm
  Left = 350
  Top = 261
  Width = 371
  Height = 479
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
    object GroupBox2: TGroupBox
      Left = 8
      Top = 64
      Width = 337
      Height = 105
      Caption = 'Preview'
      TabOrder = 1
      object DataPreviewRichEdit: TRichEdit
        Left = 8
        Top = 16
        Width = 321
        Height = 81
        TabOrder = 0
      end
    end
  end
  object GroupBox3: TGroupBox
    Left = 0
    Top = 264
    Width = 353
    Height = 177
    Caption = 'Output '
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 128
      Width = 81
      Height = 13
      Caption = 'Runtime(msec):'
    end
    object ResultRichEdit: TRichEdit
      Left = 8
      Top = 16
      Width = 321
      Height = 81
      TabOrder = 0
    end
    object RuntimeStaticText: TStaticText
      Left = 80
      Top = 129
      Width = 20
      Height = 15
      TabOrder = 1
    end
    object OutputResultStaticText: TStaticText
      Left = 8
      Top = 104
      Width = 35
      Height = 17
      Caption = 'Ready'
      TabOrder = 2
    end
  end
  object GroupBox4: TGroupBox
    Left = 0
    Top = 184
    Width = 353
    Height = 81
    Caption = 'Compute'
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 39
      Height = 13
      Caption = 'Method:'
    end
    object BoundaryLabel: TLabel
      Left = 8
      Top = 48
      Width = 48
      Height = 13
      Caption = 'Boundary:'
      Visible = False
    end
    object MethodComboBox: TComboBox
      Left = 64
      Top = 24
      Width = 145
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = '--select--'
      OnChange = MethodComboBoxChange
      Items.Strings = (
        '--select--'
        'Selection sort'
        'Insertion sort'
        'Bubble sort'
        'Shellsort'
        'Combsort'
        'Mergesort'
        'Quicksort')
    end
    object GoButton: TButton
      Left = 238
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Go'
      TabOrder = 1
      OnClick = GoButtonClick
    end
    object BoundaryEditBox: TEdit
      Left = 64
      Top = 48
      Width = 65
      Height = 21
      TabOrder = 2
      Visible = False
    end
  end
  object OpenDialog: TOpenDialog
    Left = 320
    Top = 8
  end
end
