//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "UMainForm.h"
//---------------------------------------------------------------------------
#include "UDataOps.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
  dataOps = new DataOps;
  FillSelectionDropDown();
}
//---------------------------------------------------------------------------
void TMainForm::FillSelectionDropDown()
{
  MethodComboBox->Items->Clear();
  //
  int arrSize = sizeof(ALGO_NAMES)/sizeof(ALGO_NAMES[0]);
  for (int i = 0; i < arrSize ; i++)
  {
    MethodComboBox->Items->Add(ALGO_NAMES[i]);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ImportDataSetButtonClick(TObject *Sender)
{
  if(OpenDialog->Execute())
  {
    dataOps->dataSet->Clear();
    if(!dataOps->LoadFromFile(OpenDialog->FileName))
    {
      Application->MessageBoxA("Error","File could not be read.",MB_OK|MB_ICONERROR);
      return;
    }
    DataPreviewRichEdit->Text = dataOps->dataSet->Text;
  }
}
//---------------------------------------------------------------------------
void TMainForm::ShowResult(vector<int> aInput,RuntimeResult* aRunRes)
{
  TStringList* outList = dataOps->ArrayToDataSet(aInput);
  //
  if(outList)
  {
    AnsiString resultFileName = dataOps->GetResultFullFileName();
    ResultRichEdit->Text = dataOps->FormatOutputText(outList->Text);
    if(dataOps->SaveToFile(resultFileName,outList))
    {
      OutputResultStaticText->Caption = "Saved to " + resultFileName;
    }
    else
    {
      OutputResultStaticText->Caption = "Failed to save to " + resultFileName;
    }
  }
  delete outList;
  //
  if(aRunRes)
  {
    RuntimeStaticText->Caption = aRunRes->ticks;
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GoButtonClick(TObject *Sender)
{
  SortBase* sort = NULL;
  int boundary = -1;
  switch(MethodComboBox->ItemIndex)
  {
    case IDX_SEL : sort = new SelectionSort;
      break;
    case IDX_INS : sort = new InsertionSort;
      break;
    case IDX_BBL : sort = new BubbleSort;
      break;
    case IDX_SHL : sort = new Shellsort;
      break;
    case IDX_CMB : sort = new Combsort;
      break;
    case IDX_MRG : sort = new Mergesort;
      break;
    case IDX_QCK : sort = new Quicksort;
      break;
    case IDX_HPS : sort = new Heapsort;
      break;
    case IDX_CNT :
      if(ConvertBoundary(boundary))sort = new Countingsort(boundary);else return;
      break;
    default: Application->MessageBoxA("Selection is invalid","Error",MB_OK|MB_ICONERROR);
     return;
  }
  vector<int> input = dataOps->DataSetToArray();
  RuntimeResult result = sort->Sort(input);
  //
  ShowResult(input,&result);
  //
  delete sort;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MethodComboBoxChange(TObject *Sender)
{
  BoundaryEditBox->Visible = (MethodComboBox->ItemIndex == IDX_CNT);
  BoundaryLabel->Visible = BoundaryEditBox->Visible;
}
//---------------------------------------------------------------------------
bool TMainForm::ConvertBoundary(int& aBoundary)
{
  AnsiString text = BoundaryEditBox->Text;
  if(text != "")
  {
    if((aBoundary = text.ToIntDef(0)) > 0)
    {
      return true;
    }
  }
  Application->MessageBoxA("Boundary should be a natural number","Error",MB_OK|MB_ICONERROR);
  return false;
}
//---------------------------------------------------------------------------



