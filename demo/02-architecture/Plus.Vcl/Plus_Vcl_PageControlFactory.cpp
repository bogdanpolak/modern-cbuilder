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


/*
uses
  System.SysUtils,
  Vcl.Controls;

{ TPageControlFactory }

procedure TPageControlFactory.AddNewFrame<T>(const Caption: string);
var
  TabSheet: TTabSheet;
  AFrame: TFrame;
begin
  if FPageControl=nil then
	raise Exception.Create('Required PageControl component')
  else begin
	TabSheet := TTabSheet.Create(PageControl);
	TabSheet.Caption := Caption;
	TabSheet.PageControl := PageControl;
	PageControl.ActivePage := TabSheet;
	AFrame := T.Create(TabSheet);
	AFrame.Parent := TabSheet;
	AFrame.Align := alClient;
  end;
end;

procedure TPageControlFactory.SetPageControl(const aPageControl: TPageControl);
begin
  FPageControl := aPageControl;
end;

*/