//---------------------------------------------------------------------------

#ifndef Plus_Vcl_PageControlFactoryH
#define Plus_Vcl_PageControlFactoryH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ActnList.hpp>

//---------------------------------------------------------------------------
class TPageControlFactory : public TComponent {
private:
	TPageControl* FPageControl;
	void SetPageControl(TPageControl* aPageControl);
public:
	 __fastcall TPageControlFactory(TComponent* Owner);
	TFrame* AddNewFrame (const String& Caption, TFrame* aFrame);
	void RegisterFrameCloseAction (TAction* aCloseAction);
	__property TPageControl* PageControl = {read = FPageControl, write = SetPageControl};
};
//---------------------------------------------------------------------------


#endif
