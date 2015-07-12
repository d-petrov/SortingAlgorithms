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
enum COMBO_INDEX {IDX_SEL,IDX_INS,IDX_BBL,IDX_SHL,IDX_CMB,IDX_MRG,IDX_QCK,IDX_HPS,IDX_CNT};
static const AnsiString ALGO_NAMES[] =
{
  "Selection sort","Insertion sort","Bubble sort","Shell sort",
  "Comb sort","Merge sort","Quick sort","Heap sort","Counting sort"
};

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
  TStaticText *OutputResultStaticText;
  TEdit *BoundaryEditBox;
  TLabel *BoundaryLabel;
  void __fastcall ImportDataSetButtonClick(TObject *Sender);
  void __fastcall GoButtonClick(TObject *Sender);
  void __fastcall MethodComboBoxChange(TObject *Sender);
private:	// User declarations
  void FillSelectionDropDown();
  bool ConvertBoundary(int& aBoundary);
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
