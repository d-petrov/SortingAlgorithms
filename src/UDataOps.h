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
static const AnsiString RESULT_FILE_NAME = "result.txt";
//---------------------------------------------------------------------------
class DataOps
{
  private:
    AnsiString appPath; 
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
    AnsiString GetAppPath();
    AnsiString GetResultFullFileName(); 
    //
    __fastcall DataOps()
    {
      dataSet = new TStringList;
      appPath = ExtractFilePath(ExpandFileName(ParamStr(0)));
    };
    __fastcall ~DataOps(){delete dataSet;};
};
//---------------------------------------------------------------------------
#endif
