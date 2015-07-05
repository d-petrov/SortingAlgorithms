//---------------------------------------------------------------------------

#ifndef UDataOpsH
#define UDataOpsH
//---------------------------------------------------------------------------
#include "UIGeneral.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
#include <vector>
//---------------------------------------------------------------------------
static const AnsiString SEPARATOR = ",";
//---------------------------------------------------------------------------
class DataOps
{
  private:
  
  public:
  TStringList* dataSet;
  //
  bool LoadFromFile(AnsiString aFileName);
  AnsiString FormatOutputText(AnsiString aData);
  bool SaveToFile(AnsiString aFileName,TStringList* aData);
  //
  vector<int> DataSetToArray();
  TStringList* ArrayToDataSet(vector<int> aInputData);
  //
  __fastcall DataOps(){dataSet = new TStringList;};
  __fastcall ~DataOps(){delete dataSet;};
};
//---------------------------------------------------------------------------
#endif
