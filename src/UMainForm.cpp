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
    if(!dataOps->LoadFromFile(OpenDialog->FileName))
    {
      Application->MessageBoxA("Error","File could not be read.",MB_OK|MB_ICONERROR);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
  vector<int> input = dataOps->DataSetToArray();
  //
  InsertionSort sort;
  sort.Sort(input);
  //
  TStringList* outList = dataOps->ArrayToDataSet(input);
  if(outList)
  {
    dataOps->SaveToFile("D:\\result.txt",outList);
  }
  delete outList;
  //
}
//---------------------------------------------------------------------------

