//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Plus_Vcl_CloseSheetAction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


void __fastcall TCloseSheetAction::Notification(TComponent* AComponent,
TOperation Operation) {
	TBasicAction::Notification(AComponent, Operation);
	if (Operation == opRemove && AComponent == FSheet)
		FSheet = 0;
	if (Operation == opRemove && AComponent == FFrame)
		FFrame = 0;
};

void TCloseSheetAction::SetSheetData (TTabSheet* aSheet, TFrame* aFrame) {
	FSheet = aSheet;
	FFrame = aFrame;
};

bool __fastcall TCloseSheetAction::HandlesTarget(TObject* Target) {
	return (FSheet && FFrame);
};

void __fastcall TCloseSheetAction::ExecuteTarget(TObject* Target) {
	bool CanClose = true;
	if (FBeforeClose) {
		FBeforeClose(Target, CanClose);
	}
	FFrame->Visible = false;
	if (CanClose && FAfterClose ) {
		FAfterClose (Target);
	}
	FSheet->Free();
};

void __fastcall TCloseSheetAction::UpdateTarget(TObject* Target) {
	Enabled =  (FSheet && FFrame);
};

