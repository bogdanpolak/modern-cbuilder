//---------------------------------------------------------------------------

#ifndef Frame_WelcomeH
#define Frame_WelcomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame1 : public TFrame
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TGroupBox *grbxLogin;
	TLabel *lblLogin;
	TEdit *edtLogin;
	TLabel *lblPassword;
	TEdit *edtPassword;
	TButton *btnLogin;
	TPanel *pnLogin;
private:	// User declarations
public:		// User declarations
	__fastcall TFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame1 *Frame1;
//---------------------------------------------------------------------------
#endif
