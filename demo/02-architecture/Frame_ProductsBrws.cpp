//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Frame_ProductsBrws.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameProductsBrws *FrameProductsBrws;
//---------------------------------------------------------------------------
__fastcall TFrameProductsBrws::TFrameProductsBrws(TComponent* Owner)
	: TFrame(Owner)
{
	DBGrid1->Align = alClient;
    DataSource1->DataSet = DataModule1->dsProductsBrws;
	DataSource1->DataSet->Open();
	// ----------------------------------------------------------
    // CloseAction
	CloseAction = new TCloseSheetAction(this);
	CloseAction->Caption = "Zamknij";
	Button2->Action = CloseAction;
}
//---------------------------------------------------------------------------


