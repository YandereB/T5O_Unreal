#include "NI2SDatabase.h"
#include "NI2SDatabaseConnection.h"

DEFINE_LOG_CATEGORY_STATIC(LogNI2SDatabase, Log, All);

class FNI2SDatabase : public INI2SDatabase
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** IADOSupport implementation */
	virtual FNI2SDatabaseConnection* CreateInstance() const override;
};

IMPLEMENT_MODULE(FNI2SDatabase, NI2SDatabase);

void FNI2SDatabase::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}

void FNI2SDatabase::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

FNI2SDatabaseConnection* FNI2SDatabase::CreateInstance() const
{
//#if USE_ADO_INTEGRATION
//	return new FADODataBaseConnection();
//#else
	return new FNI2SDatabaseConnection();
//#endif
}
