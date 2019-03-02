//---------------------------------------------------------------------------

#ifndef Form_MainH
#define Form_MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Plus_Vcl_PageControlFactory.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *Button1;
	TActionList *ActionList1;
	TAction *actProductsCatalog;
	TAction *Action2;
	TAction *Action3;
	TAction *Action4;
	TPageControl *PageControl1;
	TSplitter *Splitter1;
	TTimer *tmrReady;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tmrReadyTimer(TObject *Sender);
	void __fastcall actProductsCatalogExecute(TObject *Sender);
private:
	TPageControlFactory* PageControlFactory;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
