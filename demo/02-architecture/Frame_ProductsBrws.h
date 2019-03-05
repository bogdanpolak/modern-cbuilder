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
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include "Data_Connection.h"
#include "Plus_Vcl_CloseSheetAction.h"
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
private:	// User declarations
public:		// User declarations
    TCloseSheetAction* CloseAction;
	__fastcall TFrameProductsBrws(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameProductsBrws *FrameProductsBrws;
//---------------------------------------------------------------------------
#endif
