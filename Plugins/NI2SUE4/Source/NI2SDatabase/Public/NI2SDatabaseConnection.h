// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Database.h"
#include "RemoteDatabaseConnection.h"

/**
* This class allows for connections to a remote database proxy that allows any platform, regardless of native DB support, to talk to a DB.
*/
class NI2SDATABASE_API FNI2SDatabaseConnection : public FRemoteDatabaseConnection
{
public:
	/**
	 * Constructor.
	 */
	FNI2SDatabaseConnection();

	/**
	 * Destructor.
	 */
	~FNI2SDatabaseConnection() override;

	/**
	 * Opens a connection to the database.
	 *
	 * @param	ConnectionString	Connection string passed to database layer
	 * @param   RemoteConnectionIP  The IP address which the RemoteConnection should connect to
	 * @param   RemoteConnectionStringOverride  The connection string which the RemoteConnection is going to utilize
	 *
	 * @return	true if connection was successfully established, false otherwise
	 */
	bool Open(const TCHAR* ConnectionString, const TCHAR* RemoteConnectionIP, const TCHAR* RemoteConnectionStringOverride) override;

	/**
	* Closes connection to database.
	*/
	void Close() override;

	/**
	* Executes the passed in command on the database.
	*
	* @param CommandString		Command to execute
	*
	* @return true if execution was successful, false otherwise
	*/
	bool Execute(const TCHAR* CommandString) override;

	/**
	 * Executes the passed in command on the database. The caller is responsible for deleting
	 * the created RecordSet.
	 *
	 * @param CommandString		Command to execute
	 * @param RecordSet			Reference to recordset pointer that is going to hold result
	 *
	 * @return true if execution was successful, false otherwise
	 */
	bool Execute(const TCHAR* CommandString, FDataBaseRecordSet*& RecordSet) override;
};