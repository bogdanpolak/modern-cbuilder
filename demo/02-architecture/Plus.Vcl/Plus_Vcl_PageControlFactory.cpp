//---------------------------------------------------------------------------

#pragma hdrstop

#include "Plus_Vcl_PageControlFactory.h"
#include "Plus_Vcl_CloseSheetAction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <assert.h>
#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include "Plus_Vcl_PageControlFactory.h"


__fastcall TPageControlFactory::TPageControlFactory(TComponent* Owner)
	: TComponent(Owner)
{};

void TPageControlFactory::SetPageControl (TPageControl* aPageControl)
{
	FPageControl = aPageControl;
};

TFrame* TPageControlFactory::AddNewFrame (const String& Caption, TFrame* aFrame)
{
	assert (this->PageControl &&  "Required PageControl component");
	// ------------------------------------------------------
	// Create new TabSheet
	TTabSheet* TabSheet = new TTabSheet(this->PageControl);
	TabSheet->Caption = Caption;
	TabSheet->PageControl = PageControl;
	PageControl->ActivePage = TabSheet;
	// ------------------------------------------------------
	// Show aFrame inside TabSheet
	// InsertComponent = change Owner of the parameter
	TabSheet->InsertComponent(aFrame);
	aFrame->Parent = TabSheet;
	aFrame->Align = alClient;
	// ------------------------------------------------------
	//
	for (int i = 0; i < aFrame->ComponentCount; i++) {
		TCloseSheetAction* CloseAction = dynamic_cast<TCloseSheetAction*>(
			aFrame->Components[i]);
		if (CloseAction) {
			CloseAction->SetSheetData(TabSheet, aFrame);
		}
	}
	return aFrame;
};

void TPageControlFactory::RegisterFrameCloseAction (TAction* aCloseAction)
{
	/*
	FCloseActionExecute = aCloseAction->OnExecute
	aCloseAction->OnExecute
	if (Assign()) {

	}
    */
}

