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
  if(outList)
  {
    ResultRichEdit->Text = dataOps->FormatOutputText(outList->Text);
    dataOps->SaveToFile("D:\\result.txt",outList);
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
  SortBase* sort;
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
    default: Application->MessageBoxA("Selection is invalid","Error",MB_OK|MB_ICONERROR);return;
  }
  vector<int> input = dataOps->DataSetToArray();
  RuntimeResult result = sort->Sort(input);
  //
  ShowResult(input,&result);
  //
  delete sort;
}
//---------------------------------------------------------------------------


