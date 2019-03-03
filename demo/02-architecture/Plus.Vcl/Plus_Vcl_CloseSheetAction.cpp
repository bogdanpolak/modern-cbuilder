//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Plus_Vcl_CloseSheetAction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


void __fastcall TCloseSheetAction::Notification(TComponent* AComponent,
TOperation Operation) {
	TBasicAction::Notification(AComponent, Operation);
};

void TCloseSheetAction::SetSheetData (TTabSheet* aSheet, TFrame* aFrame) {
	FSheet = aSheet;
	FFrame = aFrame;
};

bool __fastcall TCloseSheetAction::HandlesTarget(TObject* Target) {
	return true;
};

void __fastcall TCloseSheetAction::ExecuteTarget(TObject* Target) {
	bool CanClose = true;
	if (FBeforeClose) {
		FBeforeClose(Target, CanClose);
	}
	FFrame->Close();
	if (CanClose && FAfterClose ) {
		FAfterClose (Target);
	}
	FSheet->Free();
};

void __fastcall TCloseSheetAction::UpdateTarget(TObject* Target) {
};

/*
procedure TDataSetFirstAction.ExecuteTarget(Target: TObject);
begin
  DataSource.DataSet.First;
end;

procedure TDataSetFirstAction.UpdateTarget(Target: TObject);
begin
  Enabled := (DataSource <> nil) and DataSource.DataSet.Active and
	not DataSource.DataSet.Bof;
end;

// TDataSource specyfic code

function TDataSetFirstAction.HandlesTarget(Target: TObject): Boolean;
var
  isAccepted: Boolean;
begin
  isAccepted := (DataSource <> nil) and (Target = DataSource) and
    (DataSource.DataSet <> nil);
  if isAccepted then
    FCountHandlesTarget := FCountHandlesTarget + 1;
  Result := isAccepted;
end;

procedure TDataSetFirstAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = DataSource) then
    DataSource := nil;
end;

procedure TDataSetFirstAction.SetDataSource(DataSource: TDataSource);
begin
  if DataSource <> FDataSource then
  begin
    FDataSource := DataSource;
    // TODO: Check this. Not sure why it's required
    if DataSource <> nil then
      DataSource.FreeNotification(Self);
  end;
end;
*/
