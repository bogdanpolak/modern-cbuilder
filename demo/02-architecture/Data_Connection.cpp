//---------------------------------------------------------------------------


#pragma hdrstop

#include "Data_Connection.h"
#include <FireDAC.Stan.Error.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;


namespace dblogin {
	/* ------------------------------------------------------------
	 * Secure password for internal user
	 */
	const String SecureKey (L"modern-cbuilder");
	// SecurePassword = AES 128 (L"<null>",SecureKey)
	const String SecurePassword (L"EvUlRZOo3hzFEr/IRpHVMA==");
	/* ------------------------------------------------------------
	 * Database connectio error messages
	 */
	const String ErrorDBServerGone (
		L"Database server is gone");
	const String ErrorUserPwdInvalid (
		L"Invalid application configuration. Database access parameters are invalid.");
	const String ErrorNoConnection (
		L"Can't connect to database server. Unknown error.");
}
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}

void TDataModule1::LogConnectionInfo (const int level, const String& msg) {
    // TODO: Implement here
}

//---------------------------------------------------------------------------
bool TDataModule1::doDatabaseLogin (const String& UserName,
	const String& HashedPassword)
{
	// --------------------------------------------------------
	// TODO: Convert form Pascal code
	// UserName := FireDAC.Comp.Client.FDManager.ConnectionDefs.ConnectionDefByName
	// (FDConnection1.ConnectionDefName).Params.UserName;
	// password := AES128_Decrypt(SecurePassword, SecureKey);
	// if password = '<null>' then
	// password := '';
	// --------------------------------------------------------
	const String ApplicationUser ("");
	const String ApplicationPassword ("");
	try {
		FDConnection1->Open(ApplicationUser,ApplicationPassword);
		return true;
	} catch (EFDDBEngineException& e) {
        String msg1;
		switch (e.Kind) {
		ekUserPwdInvalid:
			msg1 = dblogin::ErrorUserPwdInvalid;
			break;
		ekServerGone:
			msg1 = dblogin::ErrorDBServerGone;
			break;
		default:
			msg1 = dblogin::ErrorNoConnection;
		}
		LogConnectionInfo(0, msg1);
		LogConnectionInfo(1, e.Message);
	}
    return false;
}

