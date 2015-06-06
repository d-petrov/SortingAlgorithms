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
#include "UDataOps.h"
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
  TRadioGroup *RadioGroup1;
  TButton *GenerateSpecificButton;
  TButton *Button1;
  void __fastcall ImportDataSetButtonClick(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
  DataOps* dataOps;
public:		// User declarations
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
