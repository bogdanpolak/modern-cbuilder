//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frame_Welcome.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrameWelcome *FrameWelcome;
//---------------------------------------------------------------------------
__fastcall TFrameWelcome::TFrameWelcome(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void TFrameWelcome::UpdateLoginStatus (bool isLogIn) {
    grbxLogin->Visible = !isLogIn;
}
//---------------------------------------------------------------------------

