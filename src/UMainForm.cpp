//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "UMainForm.h"
//---------------------------------------------------------------------------
#include "UDataOps.h"
#include "USorting.h"
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
void TMainForm::ShowResult(vector<int> aInput)
{
  TStringList* outList = dataOps->ArrayToDataSet(aInput);
  if(outList)
  {
    ResultRichEdit->Text = FormatOutputText(outList->Text);
    dataOps->SaveToFile("D:\\result.txt",outList);
  }
  delete outList;
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
    default: Application->MessageBoxA("Selection is invalid","Error",MB_OK|MB_ICONERROR);return;
  }
  vector<int> input = dataOps->DataSetToArray();
  sort->Sort(input);
  //
  ShowResult(input);
  //
  delete sort;
}
//---------------------------------------------------------------------------


