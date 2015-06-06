//---------------------------------------------------------------------------
//      class:          SIGeneral
//
//      version:        1.2.2.0
//      created on:     Dec 27, 2009
//      last update:    May 09, 2013
//      authors:        Iassen Bojilov, Dimitar Petrov
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#define NO_ZIP
//---------------------------------------------------------------------------
#include "UIGeneral.h"
#ifndef NO_ZIP
  #include "gunzip_PO.h"
#endif
#include <stdio.h>
//---------------------------------------------------------------------------
__fastcall SIGeneral::SIGeneral()
{
  //
}
//---------------------------------------------------------------------------
__fastcall SIGeneral::~SIGeneral()
{
  //
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::AddLastDelimiter(AnsiString path, bool unixMode)
{
  AnsiString res=path;
  if (res.Length()>0)
  {
    char pathdlm='\\';
    if (unixMode)
      pathdlm='/';
    if (res[res.Length()]!=pathdlm)
      res+=pathdlm;
  }
  return(res);
}
//---------------------------------------------------------------------------
void __fastcall SIGeneral::DeleteFiles(AnsiString path, AnsiString mask)
{
  if (path=="") return;
  if (!DirectoryExists(path)) return;
  AnsiString pathF=AddLastDelimiter(path);
  TSearchRec sr;
  int fileAttr = faAnyFile;
  if (FindFirst(pathF+mask, fileAttr, sr) == 0)
  {
    do
    {
      if (FileExists(pathF+sr.Name))
      {
        for (int i=0; i<_FILEOPSRETRY; i++)
        {
          if (DeleteFile(pathF+sr.Name))
            break;
          ::Sleep(_FILEOPSPAUSE);
        }
      }
    } while (FindNext(sr) == 0);
  }
  FindClose(sr);
}
//---------------------------------------------------------------------------
int __fastcall SIGeneral::CopyFiles(AnsiString aSrcPath, AnsiString aTrgPath, AnsiString aMask)
{
  int res=0;
  if (!DirectoryExists(aSrcPath))
    return(res);
  //
  if (!DirectoryExists(aTrgPath))
  {
    try
    {
      ForceDirectories(aTrgPath);
    }
    catch (Exception &e)
    {
    }
  }
  //
  AnsiString pathS=AddLastDelimiter(aSrcPath);
  AnsiString pathT=AddLastDelimiter(aTrgPath);
  TSearchRec sr;
  int fileAttr = faAnyFile;
  if (FindFirst(pathS+aMask, fileAttr, sr) == 0)
  {
    do
    {
      AnsiString fnameS=pathS+sr.Name;
      AnsiString fnameT=pathT+sr.Name;
      if (FileExists(fnameS))
      {
        for (int i=0; i<_FILEOPSRETRY; i++)
        {
          if (::CopyFile(fnameS.c_str(),fnameT.c_str(),false))
          {
            res++;
            break;
          }
          ::Sleep(_FILEOPSPAUSE);
        }
      }
    } while (FindNext(sr) == 0);
  }
  FindClose(sr);
  //
  return(res);  
}
//---------------------------------------------------------------------------
void __fastcall SIGeneral::AddFilesToList(TStringList *tsl, AnsiString aPath, AnsiString aMask)
{
  if (!tsl) return;
  if (aPath=="") return;
  //
  if (aMask=="")
    aMask="*.*";
  aPath=AddLastDelimiter(aPath);
  //
  TSearchRec sr;
  int fileAttr = faAnyFile;
  if (FindFirst(aPath+aMask, fileAttr, sr) == 0)
  {
    do
    {
      AnsiString fnameS=aPath+sr.Name;
      if (FileExists(fnameS))
        tsl->Add(fnameS);
    } while (FindNext(sr) == 0);
  }
  FindClose(sr);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::FlushFileToDisk(AnsiString fName)
{
  bool res=false;
  if (!FileExists(fName))
    return(res);
  //
  OFSTRUCT ofs;
  HFILE h=::OpenFile(fName.c_str(),&ofs,OF_WRITE);
  res=::FlushFileBuffers((HANDLE)h);
  ::CloseHandle((HANDLE)h);
  //
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::SaveTextToFile(AnsiString sText, AnsiString fName, bool unixMode,
                                          bool addToFile, bool aImmediateWrite)
{
  bool res=false;
  //
  if (unixMode)
  {
    while (sText.Pos('\r')>0)
      sText.Delete(sText.Pos('\r'),1);
  }
  //
  AnsiString path=::ExtractFilePath(fName);
  if (!DirectoryExists(path))
  {
    try
    {
      ForceDirectories(path);
    }
    catch (Exception &e)
    {
    }
  }
  //
  DWORD dwCreationDistribution = CREATE_ALWAYS;
  if (addToFile)
    dwCreationDistribution = OPEN_ALWAYS;
  //
  int origtextlength=sText.Length();
  for (int i=0; i<_FILEOPSRETRY; i++)
  {
    int cnt=0;
    HANDLE hFile=::CreateFile(fName.c_str(),FILE_GENERIC_WRITE,0,NULL,dwCreationDistribution,
                              FILE_FLAG_WRITE_THROUGH,NULL);
    if (hFile)
    {
      ::SetFilePointer(hFile,0,0,FILE_END);
      while (cnt<origtextlength)
      {
        int savelength=_FILEBUFFSIZE;
        if (sText.Length()<_FILEBUFFSIZE)
          savelength=sText.Length();
        //
        DWORD cw=0;
        ::WriteFile(hFile,sText.c_str(),savelength,&cw,NULL);
        //
        cnt+=cw;
        if (cw>0)
          sText.Delete(1,cw);
        else
          break;
      }
      //
      if (aImmediateWrite)
        ::FlushFileBuffers(hFile);
      //
      ::CloseHandle(hFile);
      //
      if (cnt>=origtextlength)
      {
        res=true;
        break;
      }  
    }
    else
    {
      ::Sleep(_FILEOPSPAUSE);
    }
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::SaveStringToFile(AnsiString sText, AnsiString fName,
                                            bool unixMode, bool aImmediateWrite)
{
  bool res=SaveTextToFile(sText,fName,unixMode,false,aImmediateWrite);
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::AddStringToFile(AnsiString sText, AnsiString fName,
                                           bool unixMode, bool aImmediateWrite)
{
  bool res=SaveTextToFile(sText,fName,unixMode,true,aImmediateWrite);
  return(res);
}
//---------------------------------------------------------------------------
void __fastcall SIGeneral::ChangeListFilesPath(TStringList *tsl, AnsiString aNewPath)
{
  if (!tsl) return;
  //
  for (int i=0; i<tsl->Count; i++)
  {
    AnsiString fname=Trim(tsl->Strings[i]);
    if (fname!="")
    {
      if (aNewPath!="")
        tsl->Strings[i]=SIGeneral::AddLastDelimiter(aNewPath)+::ExtractFileName(fname);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall SIGeneral::DeleteListFiles(TStringList *tsl)
{
  if (!tsl) return;
  //
  for (int i=0; i<tsl->Count; i++)
  {
    AnsiString fnm=tsl->Strings[i];
    if (FileExists(fnm))
    {
      for (int q=0; q<_FILEOPSRETRY; q++)
      {
        if (DeleteFile(fnm))
          break;
        ::Sleep(_FILEOPSPAUSE);
      }
    }
  }
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::SaveListToFile(TStringList *tsl, AnsiString fName, bool aImmediateWrite)
{
  bool res=false;
  if (!tsl) return(res);
  if (fName=="") return(res);
  //
  res=SaveStringToFile(tsl->Text,fName,false,aImmediateWrite);
  //
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::LoadListFromFile(TStringList *tsl, AnsiString fName)
{
  bool res=false;
  if (!tsl) return(res);
  if (!FileExists(fName)) return(res);
  for (int i=0; i<_FILEOPSRETRY; i++)
  {
    try
    {
      tsl->LoadFromFile(fName);
      res=true;
      break;
    }
    catch (Exception &e)
    {
      ::Sleep(_FILEOPSPAUSE);
    }
  }
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::ExtractLineParam(AnsiString code, AnsiString record,
                                                      int param, AnsiString &result)
{
  bool res=false;
  if (code=="") return(res);
  if (record=="") return(res);
  if (param<0) return(res);
  if (record.Pos(code)!=1) return(res);
  //
  record.Delete(1,code.Length());
  record=Trim(record);
  //
  char dlm='|';
  //
  int cnt=0;
  while (record.Pos(dlm)>0)
  {
    int pos=record.Pos(dlm);
    if (pos>0)
    {
      if (cnt==param)
      {
        result=record.SubString(1,pos-1);
        res=true;
        break;
      }
      record.Delete(1,pos);
      cnt++;
    }
  }
  if ((!res) && (cnt==param))
  {
    result=record;
    res=true;
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::FormatDateStr(AnsiString record)
{
  if (record.Length()!=8) return(record);
  AnsiString res="";
  for (int i=0; i<2; i++)
  {
    res+=record.SubString(record.Length()-1,2)+".";
    record.Delete(record.Length()-1,2);
  }
  res+=record;
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::FormatTimeStr(AnsiString record)
{
  if (record.Length()!=6) return(record);
  AnsiString res="";
  for (int i=0; i<2; i++)
  {
    res+=record.SubString(1,2)+":";
    record.Delete(1,2);
  }
  res+=record;
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::FormatDigits(AnsiString record, bool noZero, int decimalPrecision)
{
  AnsiString res="";
  if (record=="")
    return(res);
  res=Trim(record);
  //
  if (noZero)
  {
    int v=0;
    try
    {
      v=StrToInt(Trim(res));
    }
    catch (Exception &e)
    {
    }
    if (v==0)
      return("");
  }
  //
  bool negative=false;
  int posminus=res.Pos("-");
  if (posminus>0)
  {
    negative=true;
    res.Delete(posminus,1);
  }
  //
  if ((res=="0") || (res=="00"))
    res="000";
  while (res.Length()<3)
    res="0"+res;
  //
  if (decimalPrecision>0)
  {
    if (res.Pos(".")==0)
      res.Insert(".",res.Length()-decimalPrecision+1);
  }
  //
  if (res.Pos(".")==1)
    res="0"+res;
  //
  if (negative)
    res="-"+res;
  //
  return(res);
}
//---------------------------------------------------------------------------
double __fastcall SIGeneral::ConvertToDouble(AnsiString record, int divOffset)
{
  double res=0;
  if (record=="") return(res);
  //
  res=StrToFloatDef(record,0);
  if (res==0) return(res);
  //
  int decDiv=1;
  for (int i=0; i<divOffset; i++)
    decDiv=decDiv*10;
  res=res/(double)decDiv;
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::AsciiToAnsi(AnsiString record)
{
  AnsiString res="";
  if (record=="") return(res);
  //
  for (int i=1; i<=record.Length(); i++)
  {
    unsigned char chr=record[i];
    int acode=(int)chr;
    if (acode>=0x80 && acode<0xC0)
       acode+=64;
    res+=char(acode);
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::AnsiToAscii(AnsiString record)
{
  AnsiString res="";
  if (record=="") return(res);
  //
  for (int i=1; i<=record.Length(); i++)
  {
    unsigned char chr=record[i];
    int acode=(int)chr;
    if (acode>=0xC0 && acode<=0xFF)
       acode-=64;
    res+=char(acode);
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::ReplaceChar(AnsiString record, char oldChar, char newChar)
{
  AnsiString res=record;
  if (record.Length()==0)
    return(res);
  //
  for (int i=1; i<=res.Length(); i++)
  {
    if (res[i]==oldChar)
       res[i]=newChar;
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
#ifndef NO_ZIP
bool __fastcall SIGeneral::UnzipFile(AnsiString sSource, AnsiString &newName)
{
  bool res = false;
  if (sSource == "") return(res);
  if (!FileExists(sSource)) return(res);
  AnsiString sTarget = sSource;
  AnsiString text=".tmp";
  AnsiString sext=".gz";
  AnsiString ext=::ExtractFileExt(sSource);
  if (ext==sext)
  {
    sTarget=sTarget.SubString(1,sTarget.Length()-ext.Length());
    sTarget+=text;
  }
  int r=nsCompressTools::DoUnzip(sSource.c_str(),sTarget.c_str());
  if (r==1)
  {
    DeleteFile(sSource);
    AnsiString nfname=ChangeFileExt(sTarget,"");
    if (FileExists(nfname))
      DeleteFile(nfname);
    if (RenameFile(sTarget,nfname))
    {
      newName=nfname;
      res=true;
    }
  }
  return(res);
}
#endif
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::CreateFixedRecord(AnsiString sSource, int aLength,
                                                   bool alignLeft, char fillChar)
{
  AnsiString res=Trim(sSource);
  //
  if (res.Length()>aLength)
  {
    res=res.SubString(1,aLength);
    return(res);
  }
  //
  while (res.Length()<aLength)
  {
    if (alignLeft)
      res+=(AnsiString)fillChar;
    else
      res=(AnsiString)fillChar+res;
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall SIGeneral::AddFileToFile(AnsiString srcFile, AnsiString trgFile, bool aImmediateWrite)
{
  bool res=false;
  if (!FileExists(srcFile)) return(false);
  if (!FileExists(trgFile)) return(false);
  //
  BYTE buffer[_FILEBUFFSIZE];
  //
  FILE *sf=fopen(srcFile.c_str(),"rb");
  FILE *tf=fopen(trgFile.c_str(),"ab");
  if (sf && tf)
  {
    while (1)
    {
      int scnt=fread(buffer,1,_FILEBUFFSIZE,sf);
      if (scnt>0)
      {
        fwrite(buffer,1,scnt,tf);
        if (!res)
          res=true;
      }
      else
        break;  
    }
  }
  if (sf)
    fclose(sf);
  if (tf)
    fclose(tf);
  //
  if (aImmediateWrite)
    FlushFileToDisk(trgFile);
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::EncodeHex(AnsiString aText)
{
  AnsiString res="";
  //
  for (int i=1; i<=aText.Length(); i++)
  {
    char txtC=(char)aText[i];
    res+=IntToHex((BYTE)txtC,2);
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
AnsiString __fastcall SIGeneral::DecodeHex(AnsiString aText)
{
  AnsiString res="";
  //
  for(int i=1; i<=aText.Length(); i+=2)
  {
    AnsiString s=aText.SubString(i,2);
    if (s.Length()==2)
    {
      int v=StrToIntDef("0x"+s,-1);
      if (v>-1)
        res+=(AnsiString)(char(v));
    }
  }
  //
  return(res);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

