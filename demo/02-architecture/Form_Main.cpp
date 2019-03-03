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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	PageControlFactory = new TPageControlFactory(this);
    PageControlFactory->PageControl = PageControl1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::tmrReadyTimer(TObject *Sender)
{
    tmrReady->Enabled = false;
	// x
}
//---------------------------------------------------------------------------

void __fastcall TForm1::actProductsCatalogExecute(TObject *Sender)
{
	TFrameProductsBrws* frm = dynamic_cast<TFrameProductsBrws*>(
		PageControlFactory->AddNewFrame( L"Katalog produktów",
		new TFrameProductsBrws(this) ));
	frm->CloseAction->SetSheetData(PageControl1->ActivePage, frm);
}
//---------------------------------------------------------------------------


