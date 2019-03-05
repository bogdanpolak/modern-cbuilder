//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form_Main.h"
#include "Frame_ProductsBrws.h"
#include "Frame_Welcome.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	PageControlFactory = new TPageControlFactory(this);
	PageControlFactory->PageControl = PageControl1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
    grbxCommands->Visible = false;
	PageControlFactory->AddNewFrame( L"Dzieñ dobry",
		new TFrameWelcome(this) );
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
	// TODO: Implementation needed
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

