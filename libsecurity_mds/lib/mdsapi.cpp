/*
 * Copyright (c) 2000-2001 Apple Computer, Inc. All Rights Reserved.
 * 
 * The contents of this file constitute Original Code as defined in and are
 * subject to the Apple Public Source License Version 1.2 (the 'License').
 * You may not use this file except in compliance with the License. Please obtain
 * a copy of the License at http://www.apple.com/publicsource and read it before
 * using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. Please see the License for the
 * specific language governing rights and limitations under the License.
 */


/*

   File:      mds.h

   Contains:  Module Directory Services Data Types and API.

   Copyright: (c) 1999 Apple Computer, Inc., all rights reserved.

   This is the C API wrapper for the C++ MDS implementation.  Most of this file
   could also be generated by the same perl script that generates the plugin
   C wrapper code.

 */

#include "MDSSession.h"
#include "mdspriv.h"
#include <security_cdsa_utilities/cssmbridge.h>
#include <memory>
#include <security_utilities/globalizer.h>
#include <security_utilities/threading.h>

#define MSApiDebug(args...)	secdebug("MDS_API", ## args)

/* Protects access to AppleDataBase */
ModuleNexus<Mutex> adbMutex;

using namespace std;

static CSSM_RETURN CSSMAPI mds_DataGetFirst(CSSM_DL_DB_HANDLE DLDBHandle,
         const CSSM_QUERY *Query,
         CSSM_HANDLE_PTR ResultsHandle,
         CSSM_DB_RECORD_ATTRIBUTE_DATA_PTR Attributes,
         CSSM_DATA_PTR Data,
         CSSM_DB_UNIQUE_RECORD_PTR *UniqueId)
{
  BEGIN_API
  MSApiDebug("mds_DataGetFirst");
  StLock<Mutex> _(adbMutex());
  if (!(Required(ResultsHandle) = HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataGetFirst(DLDBHandle.DBHandle,
			CssmQuery::optional(Query),
			Attributes,
			CssmData::optional(Data),
			Required(UniqueId))))
	return CSSMERR_DL_ENDOFDATA;
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataModify(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_DB_RECORDTYPE RecordType,
         CSSM_DB_UNIQUE_RECORD_PTR UniqueRecordIdentifier,
         const CSSM_DB_RECORD_ATTRIBUTE_DATA *AttributesToBeModified,
         const CSSM_DATA *DataToBeModified,
         CSSM_DB_MODIFY_MODE ModifyMode)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataModify(DLDBHandle.DBHandle,
			RecordType,
			Required(UniqueRecordIdentifier),
			AttributesToBeModified,
			CssmData::optional(DataToBeModified),
			ModifyMode);
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_GetDbNameFromHandle(CSSM_DL_DB_HANDLE DLDBHandle,
         char **DbName)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).GetDbNameFromHandle(DLDBHandle.DBHandle,
			DbName);
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataAbortQuery(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_HANDLE ResultsHandle)
{
  BEGIN_API
  MSApiDebug("mds_DataAbortQuery");
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataAbortQuery(DLDBHandle.DBHandle,
			ResultsHandle);
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DestroyRelation(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_DB_RECORDTYPE RelationID)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DestroyRelation(DLDBHandle.DBHandle,
			RelationID);
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataDelete(CSSM_DL_DB_HANDLE DLDBHandle,
         const CSSM_DB_UNIQUE_RECORD *UniqueRecordIdentifier)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataDelete(DLDBHandle.DBHandle,
			Required(UniqueRecordIdentifier));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataInsert(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_DB_RECORDTYPE RecordType,
         const CSSM_DB_RECORD_ATTRIBUTE_DATA *Attributes,
         const CSSM_DATA *Data,
         CSSM_DB_UNIQUE_RECORD_PTR *UniqueId)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataInsert(DLDBHandle.DBHandle,
			RecordType,
			Attributes,
			CssmData::optional(Data),
			Required(UniqueId));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataGetFromUniqueRecordId(CSSM_DL_DB_HANDLE DLDBHandle,
         const CSSM_DB_UNIQUE_RECORD *UniqueRecord,
         CSSM_DB_RECORD_ATTRIBUTE_DATA_PTR Attributes,
         CSSM_DATA_PTR Data)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataGetFromUniqueRecordId(DLDBHandle.DBHandle,
			Required(UniqueRecord),
            Attributes,
			CssmData::optional(Data));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_CreateRelation(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_DB_RECORDTYPE RelationID,
         const char *RelationName,
         uint32 NumberOfAttributes,
         const CSSM_DB_SCHEMA_ATTRIBUTE_INFO *pAttributeInfo,
         uint32 NumberOfIndexes,
         const CSSM_DB_SCHEMA_INDEX_INFO *pIndexInfo)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).CreateRelation(DLDBHandle.DBHandle,
			RelationID,
			RelationName,
			NumberOfAttributes,
			pAttributeInfo,
			NumberOfIndexes,
			Required(pIndexInfo));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_FreeUniqueRecord(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_DB_UNIQUE_RECORD_PTR UniqueRecord)
{
  BEGIN_API
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).FreeUniqueRecord(DLDBHandle.DBHandle,
			Required(UniqueRecord));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DbOpen(CSSM_DL_HANDLE DLHandle,
         const char *DbName,
         const CSSM_NET_ADDRESS *DbLocation,
         CSSM_DB_ACCESS_TYPE AccessRequest,
         const CSSM_ACCESS_CREDENTIALS *AccessCred,
         const void *OpenParameters,
         CSSM_DB_HANDLE *DbHandle)
{
  BEGIN_API
  MSApiDebug("mds_DbOpen %s", DbName);
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DbOpen(DbName,
			DbLocation,
			AccessRequest,
			AccessCredentials::optional(AccessCred),
			OpenParameters,
			Required(DbHandle));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DataGetNext(CSSM_DL_DB_HANDLE DLDBHandle,
         CSSM_HANDLE ResultsHandle,
         CSSM_DB_RECORD_ATTRIBUTE_DATA_PTR Attributes,
         CSSM_DATA_PTR Data,
         CSSM_DB_UNIQUE_RECORD_PTR *UniqueId)
{
  BEGIN_API
  MSApiDebug("mds_DataGetNext");
  StLock<Mutex> _(adbMutex());
  if (!HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DataGetNext(DLDBHandle.DBHandle,
			ResultsHandle,
			Attributes,
			CssmData::optional(Data),
			Required(UniqueId)))
	return CSSMERR_DL_ENDOFDATA;
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_GetDbNames(CSSM_DL_HANDLE DLHandle,
         CSSM_NAME_LIST_PTR *NameList)
{
  BEGIN_API
  HandleObject::find<MDSSession>(DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).GetDbNames(Required(NameList));
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_DbClose(CSSM_DL_DB_HANDLE DLDBHandle)
{
  BEGIN_API
  MSApiDebug("mds_DbClose");
  StLock<Mutex> _(adbMutex());
  HandleObject::find<MDSSession>(DLDBHandle.DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).DbClose(DLDBHandle.DBHandle);
  END_API(MDS)
}

static CSSM_RETURN CSSMAPI mds_FreeNameList(CSSM_DL_HANDLE DLHandle,
         CSSM_NAME_LIST_PTR NameList)
{
  BEGIN_API
  HandleObject::find<MDSSession>(DLHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).FreeNameList(Required(NameList));
  END_API(MDS)
}

static MDS_FUNCS gMDSFunctionTable =
{
    mds_DbOpen,
    mds_DbClose,
    mds_GetDbNames,
    mds_GetDbNameFromHandle,
    mds_FreeNameList,
    mds_DataInsert,
    mds_DataDelete,
    mds_DataModify,
    mds_DataGetFirst,
    mds_DataGetNext,
    mds_DataAbortQuery,
    mds_DataGetFromUniqueRecordId,
    mds_FreeUniqueRecord,
    mds_CreateRelation,
    mds_DestroyRelation,
};


CSSM_RETURN CSSMAPI
MDS_Initialize (const CSSM_GUID *inCallerGuid,
                const CSSM_MEMORY_FUNCS *inMemoryFunctions,
                MDS_FUNCS_PTR outDlFunctions,
                MDS_HANDLE *outMDSHandle)
{
    BEGIN_API
    Required (outDlFunctions);
    Required (outMDSHandle) = (new MDSSession (Guid::optional(inCallerGuid),
                                               Required(inMemoryFunctions)))->handle ();
    *outDlFunctions = gMDSFunctionTable;
    END_API(MDS)
}

CSSM_RETURN CSSMAPI
MDS_Terminate (MDS_HANDLE inMDSHandle)
{
    BEGIN_API
    auto_ptr<MDSSession> aMDSSession (&HandleObject::findAndKill<MDSSession> (inMDSHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE));
    aMDSSession->terminate (); // Even if terminate throws the MDSSession object will be deleted.
    END_API(MDS)
}

CSSM_RETURN CSSMAPI
MDS_Install (MDS_HANDLE inMDSHandle)
{
    BEGIN_API
    HandleObject::find<MDSSession> (inMDSHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).install ();
    END_API(MDS)
}

CSSM_RETURN CSSMAPI
MDS_Uninstall (MDS_HANDLE inMDSHandle)
{
    BEGIN_API
    HandleObject::find<MDSSession> (inMDSHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).uninstall ();
    END_API(MDS)
}


//
// Private APIs for subsystem registration (called from securityd as root ONLY)
//
CSSM_RETURN CSSMAPI
MDS_InstallFile(MDS_HANDLE inMDSHandle, const MDS_InstallDefaults *defaults,
	const char *bundlePath, const char *subdir, const char *file)	// file(s)
{
  BEGIN_API
  HandleObject::find<MDSSession>(inMDSHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).installFile(defaults, bundlePath, subdir, file);
  END_API(MDS)
}


//
// Remove 
CSSM_RETURN CSSMAPI
MDS_RemoveSubservice(MDS_HANDLE inMDSHandle, const char *guid, uint32 ssid)
{
  BEGIN_API
  HandleObject::find<MDSSession>(inMDSHandle, CSSMERR_CSSM_INVALID_ADDIN_HANDLE).removeSubservice(guid, ssid);
  END_API(MDS)
}