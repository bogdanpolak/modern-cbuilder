//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form_Main.h"
#include "Frame_ProductsBrws.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    FrameWelcome = 0;
	PageControlFactory = new TPageControlFactory(this);
	PageControlFactory->PageControl = PageControl1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
	grbxCommands->Visible = false;
	TFrame* fr = PageControlFactory->AddNewFrame( L"Dzieñ dobry",
		new TFrameWelcome(this) );
	FrameWelcome = dynamic_cast<TFrameWelcome*>(fr);
	FrameWelcome->btnLogin->Action = actLogin;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actProductCatalogExecute(TObject *Sender)
{
	PageControlFactory->AddNewFrame( L"Katalog produktów",
		new TFrameProductsBrws(this) );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actLoginExecute(TObject *Sender)
{
	bool isLogIn = DataModule1->doDatabaseLogin (FrameWelcome->edtLogin->Text,
		FrameWelcome->edtPassword->Text);
	if (isLogIn) {
		grbxCommands->Visible = true;
        FrameWelcome->UpdateLoginStatus(isLogIn);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actLogoutExecute(TObject *Sender)
{
	// TODO: Implementation needed
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actApplicationAboutExecute(TObject *Sender)
{
	// TODO: Implementation needed
}
//---------------------------------------------------------------------------

