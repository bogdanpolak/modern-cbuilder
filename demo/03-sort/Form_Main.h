//---------------------------------------------------------------------------

#ifndef Form_MainH
#define Form_MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox *PaintBox1;
	TTimer *tmrReady;
	TTimer *Timer1;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TPaintBox *PaintBox2;
	void __fastcall tmrReadyTimer(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall PaintBox2Paint(TObject *Sender);
private:	// User declarations
	unsigned long enlapsedMsQuickSort;
	unsigned long enlapsedMsBubbleSort;
	void __fastcall ThreadTerminated(TObject *Sender);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
