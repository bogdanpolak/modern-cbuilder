//---------------------------------------------------------------------------

#ifndef Plus_Vcl_CloseSheetActionH
#define Plus_Vcl_CloseSheetActionH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Forms.hpp>


class TCloseSheetAction : public TAction {
private:
	TNotifyEvent FAfterClose;
	TCloseQueryEvent FBeforeClose;
	TTabSheet* FSheet;
	TFrame* FFrame;
protected:
	void __fastcall Notification(TComponent * AComponent, TOperation Operation);
public:
	void SetSheetData (TTabSheet* aSheet, TFrame* aFrame);
	virtual bool __fastcall HandlesTarget(TObject* Target);
	virtual void __fastcall ExecuteTarget(TObject* Target);
	virtual void __fastcall UpdateTarget(TObject* Target);
	__property TNotifyEvent AfterClose = {read=FAfterClose, write=FAfterClose};
	__property TCloseQueryEvent BeforeClose = {read=FBeforeClose,
		write=FBeforeClose};
};

#endif
