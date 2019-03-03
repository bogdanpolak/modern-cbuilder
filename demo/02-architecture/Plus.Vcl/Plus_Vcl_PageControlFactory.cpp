//---------------------------------------------------------------------------

#pragma hdrstop

#include "Plus_Vcl_PageControlFactory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <System.SysUtils.hpp>
#include <Vcl.Controls.hpp>
#include "Plus_Vcl_PageControlFactory.h"


void GuardComponentIsAssigned (TComponent* elem, const String message){
};

__fastcall TPageControlFactory::TPageControlFactory(TComponent* Owner)
	: TComponent(Owner)
{};

void TPageControlFactory::SetPageControl (TPageControl* aPageControl)
{
	FPageControl = aPageControl;
};

TFrame* TPageControlFactory::AddNewFrame (const String& Caption, TFrame* aFrame)
{
	GuardComponentIsAssigned (FPageControl, "Required PageControl component");
	TTabSheet* TabSheet = new TTabSheet(PageControl);
	TabSheet->Caption = Caption;
	TabSheet->PageControl = PageControl;
	PageControl->ActivePage = TabSheet;
	TabSheet->InsertComponent(aFrame);
	aFrame->Parent = TabSheet;
	aFrame->Align = alClient;
	return aFrame;
};

void TPageControlFactory::RegisterFrameCloseAction (TAction* aCloseAction)
{
	FCloseActionExecute = aCloseAction->OnExecute
	aCloseAction->OnExecute
	if (Assign()) {

	}
}

