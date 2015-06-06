//---------------------------------------------------------------------------
//      Class:          SIGeneral
//
//      version:        1.2.2.0
//      created on:     Dec 27, 2009
//      last update:    May 09, 2013
//      authors:        Iassen Bojilov
//---------------------------------------------------------------------------
#ifndef UIGeneralH
#define UIGeneralH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#define _FILEOPSRETRY 20
#define _FILEOPSPAUSE 10
#define _FILEBUFFSIZE 4096
//---------------------------------------------------------------------------
class SIGeneral
{
  private:
    static bool __fastcall FlushFileToDisk(AnsiString fName);
    static bool __fastcall SaveTextToFile(AnsiString sText, AnsiString fName, bool unixMode,
                                          bool addToFile, bool aImmediateWrite);
  protected:
  public:
    __fastcall SIGeneral();
    __fastcall ~SIGeneral();
    static AnsiString __fastcall AddLastDelimiter(AnsiString path, bool unixMode=false);
    static void __fastcall DeleteFiles(AnsiString path, AnsiString mask);
    static int __fastcall CopyFiles(AnsiString aSrcPath, AnsiString aTrgPath, AnsiString aMask);
    static void __fastcall AddFilesToList(TStringList *tsl, AnsiString aPath, AnsiString aMask);
    static void __fastcall ChangeListFilesPath(TStringList *tsl, AnsiString aNewPath);
    static void __fastcall DeleteListFiles(TStringList *tsl);
    static bool __fastcall SaveStringToFile(AnsiString sText, AnsiString fName,
                                            bool unixMode, bool aImmediateWrite=false);
    static bool __fastcall AddStringToFile(AnsiString sText, AnsiString fName,
                                            bool unixMode, bool aImmediateWrite=false);
    static bool __fastcall SaveListToFile(TStringList *tsl, AnsiString fName, bool aImmediateWrite=false);
    static bool __fastcall LoadListFromFile(TStringList *tsl, AnsiString fName);
    static bool __fastcall ExtractLineParam(AnsiString code, AnsiString record,
                                            int param, AnsiString &result);
    static AnsiString __fastcall FormatDateStr(AnsiString record);
    static AnsiString __fastcall FormatTimeStr(AnsiString record);
    static AnsiString __fastcall FormatDigits(AnsiString record, bool noZero, int decimalPrecision);
    static double __fastcall ConvertToDouble(AnsiString record, int divOffset);
    static AnsiString __fastcall AsciiToAnsi(AnsiString record);
    static AnsiString __fastcall AnsiToAscii(AnsiString record);
    static AnsiString __fastcall ReplaceChar(AnsiString record, char oldChar, char newChar);
    static bool __fastcall UnzipFile(AnsiString sSource, AnsiString &newName);
    static AnsiString __fastcall CreateFixedRecord(AnsiString sSource, int aLength,
                                                   bool alignLeft, char fillChar=' ');
    static bool __fastcall AddFileToFile(AnsiString srcFile, AnsiString trgFile, bool aImmediateWrite=false);
    static AnsiString __fastcall EncodeHex(AnsiString aText);
    static AnsiString __fastcall DecodeHex(AnsiString aText);
};
//---------------------------------------------------------------------------
#endif
 