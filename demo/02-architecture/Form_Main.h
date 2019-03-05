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
	TGroupBox *grbxCommands;
	TButton *Button1;
	TActionList *ActionList1;
	TAction *actProductCatalog;
	TAction *actLogin;
	TPageControl *PageControl1;
	TSplitter *Splitter1;
	TTimer *tmrReady;
	TAction *actLogout;
	TAction *actApplicationAbout;
	TBevel *Bevel1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall tmrReadyTimer(TObject *Sender);
	void __fastcall actProductCatalogExecute(TObject *Sender);
	void __fastcall actLoginExecute(TObject *Sender);
	void __fastcall actLogoutExecute(TObject *Sender);
	void __fastcall actApplicationAboutExecute(TObject *Sender);
private:
	TPageControlFactory* PageControlFactory;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
