//---------------------------------------------------------------------------

#ifndef UMainFormH
#define UMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
enum COMBO_INDEX {IDX_BAD,IDX_SEL,IDX_INS,IDX_BBL,IDX_SHL,IDX_CMB};
//---------------------------------------------------------------------------
#include "UDataOps.h"
#include "USorting.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TOpenDialog *OpenDialog;
  TButton *ImportDataSetButton;
  TButton *GenerateRandomButton;
  TGroupBox *GroupBox2;
  TRichEdit *DataPreviewRichEdit;
  TGroupBox *GroupBox3;
  TGroupBox *GroupBox4;
  TButton *GenerateSpecificButton;
  TComboBox *MethodComboBox;
  TLabel *Label1;
  TButton *GoButton;
  TRichEdit *ResultRichEdit;
  TLabel *Label2;
  TStaticText *RuntimeStaticText;
  void __fastcall ImportDataSetButtonClick(TObject *Sender);
  void __fastcall GoButtonClick(TObject *Sender);
private:	// User declarations
  DataOps* dataOps;
  //
  void ShowResult(vector<int> aInput,RuntimeResult* aRunRes = NULL);
public:		// User declarations
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
