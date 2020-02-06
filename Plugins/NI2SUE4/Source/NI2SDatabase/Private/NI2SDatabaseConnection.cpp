#include "..\Public\NI2SDatabaseConnection.h"

FNI2SDatabaseConnection::FNI2SDatabaseConnection()
{
}

FNI2SDatabaseConnection::~FNI2SDatabaseConnection()
{
}

bool FNI2SDatabaseConnection::Open(const TCHAR * ConnectionString, const TCHAR * RemoteConnectionIP, const TCHAR * RemoteConnectionStringOverride)
{
	return false;
}

void FNI2SDatabaseConnection::Close()
{
}

bool FNI2SDatabaseConnection::Execute(const TCHAR * CommandString)
{
	return false;
}

bool FNI2SDatabaseConnection::Execute(const TCHAR * CommandString, FDataBaseRecordSet *& RecordSet)
{
	return false;
}

bool FNI2SDatabaseConnection::SetConnectionString(const TCHAR * ConnectionString)
{
	return false;
}
