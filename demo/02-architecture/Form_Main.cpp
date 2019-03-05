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
	PageControlFactory = new TPageControlFactory(this);
	PageControlFactory->PageControl = PageControl1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
	tmrReady->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actProductCatalogExecute(TObject *Sender)
{
	PageControlFactory->AddNewFrame( L"Katalog produktów",
		new TFrameProductsBrws(this) );
}
//---------------------------------------------------------------------------


