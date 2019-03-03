//---------------------------------------------------------------------------

#ifndef Frame_ProductsBrwsH
#define Frame_ProductsBrwsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "Data_Connection.h"
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
//---------------------------------------------------------------------------
class TFrameProductsBrws : public TFrame
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TGroupBox *GroupBox1;
	TButton *Button1;
	TButton *Button2;
	TActionList *ActionList1;
	TAction *actClose;
	void __fastcall actCloseExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFrameProductsBrws(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameProductsBrws *FrameProductsBrws;
//---------------------------------------------------------------------------
#endif
