#include "NI2SDatabaseConnection.h"


FNI2SDatabaseConnection::FNI2SDatabaseConnection()
{
}

FNI2SDatabaseConnection::~FNI2SDatabaseConnection()
{
}

bool FNI2SDatabaseConnection::Open(const TCHAR * ConnectionString, const TCHAR * RemoteConnectionIP, const TCHAR * RemoteConnectionStringOverride)
{
	return FRemoteDatabaseConnection::Open(ConnectionString, RemoteConnectionIP, RemoteConnectionStringOverride);
}

void FNI2SDatabaseConnection::Close()
{
	FRemoteDatabaseConnection::Close();
}

bool FNI2SDatabaseConnection::Execute(const TCHAR * CommandString)
{
	return FRemoteDatabaseConnection::Execute(CommandString);
}

bool FNI2SDatabaseConnection::Execute(const TCHAR * CommandString, FDataBaseRecordSet *& RecordSet)
{
	return FRemoteDatabaseConnection::Execute(CommandString, RecordSet);
}
