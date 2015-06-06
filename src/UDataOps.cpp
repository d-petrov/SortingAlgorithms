//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "UDataOps.h"
#include <vcl.h>
//---------------------------------------------------------------------------
bool DataOps::LoadFromFile(AnsiString aFileName)
{
  if(!dataSet)
  {
    return false;
  }
  if(!FileExists(aFileName))
  {
    return false;
  }
  return SIGeneral::LoadListFromFile(dataSet,aFileName);
}
//---------------------------------------------------------------------------
bool DataOps::SaveToFile(AnsiString aFileName,TStringList* aData)
{
  if(!aData)
  {
    return false;
  }
  AnsiString text = StringReplace(aData->Text,"\r\n",SEPARATOR,TReplaceFlags()<<rfReplaceAll);
  text = text.SubString(1,text.Length() - 1);
  //
  return SIGeneral::SaveStringToFile(text,aFileName,false);
}
//---------------------------------------------------------------------------
vector<int> DataOps::DataSetToArray()
{
  vector<int> dataVector;
  size_t size = 0;
  //
  if(!dataSet || dataSet->Count < 1)
  {
    return dataVector;
  }
  //
  TStringList* data = new TStringList;
  data->Text = StringReplace(dataSet->Text,SEPARATOR,"\r\n",TReplaceFlags()<<rfReplaceAll);
  //
  size = (unsigned)data->Count;
  //
  for (unsigned i = 0; i < size ; ++i)
  {
    AnsiString this_char = data->Strings[i].Trim();
    //
    dataVector.push_back(StrToIntDef(this_char,0));
  }
  delete data;
  //
  return dataVector;
}
//---------------------------------------------------------------------------
TStringList* DataOps::ArrayToDataSet(vector<int> aInputData)
{
  TStringList* retlist = new TStringList;
  //
  size_t size = aInputData.size();
  //
  for (unsigned i = 0; i < size ; ++i)
  {
    retlist->Add(IntToStr(aInputData[i]));
  }
  //
  return retlist;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
