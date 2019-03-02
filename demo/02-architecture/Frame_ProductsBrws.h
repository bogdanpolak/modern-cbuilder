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
//---------------------------------------------------------------------------
class TFrameProductsBrws : public TFrame
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
private:	// User declarations
public:		// User declarations
	__fastcall TFrameProductsBrws(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrameProductsBrws *FrameProductsBrws;
//---------------------------------------------------------------------------
#endif
