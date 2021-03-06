/*##############################################################################

    Copyright (C) 2011 HPCC Systems.

    All rights reserved. This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
############################################################################## */

#ifndef _FILESERVICES_INCL
#define _FILESERVICES_INCL

#ifdef _WIN32
#define FILESERVICES_CALL _cdecl
#ifdef FILESERVICES_EXPORTS
#define FILESERVICES_API __declspec(dllexport)
#else
#define FILESERVICES_API __declspec(dllimport)
#endif
#else
#define FILESERVICES_CALL
#define FILESERVICES_API
#endif

#include "hqlplugins.hpp"
#include "workunit.hpp"
#include "eclhelper.hpp"

extern "C" {
FILESERVICES_API bool getECLPluginDefinition(ECLPluginDefinitionBlock *pb);
FILESERVICES_API void setPluginContext(IPluginContext * _ctx);
FILESERVICES_API char * FILESERVICES_CALL fsGetBuildInfo(void);

FILESERVICES_API bool FILESERVICES_CALL fsFileExists(ICodeContext *ctx, const char *name, bool physical);
FILESERVICES_API void FILESERVICES_CALL fsDeleteLogicalFile(ICodeContext *ctx, const char *name, bool ifexists);
FILESERVICES_API bool FILESERVICES_CALL fsFileValidate(ICodeContext *ctx, const char *name);
FILESERVICES_API void FILESERVICES_CALL fsSetReadOnly(ICodeContext *ctx, const char *name, bool ro);
FILESERVICES_API void FILESERVICES_CALL fsRenameLogicalFile(ICodeContext *ctx, const char *oldname, const char *newname);
FILESERVICES_API void FILESERVICES_CALL fsSendEmail(ICodeContext * ctx, const char *to, const char * subject, const char * body, const char * mailServer, unsigned port, const char * sender);
FILESERVICES_API void FILESERVICES_CALL fsSendEmailAttachText(ICodeContext * ctx, const char * to, const char * subject, const char * body, const char * attachment, const char * mimeType, const char * attachmentName, const char * mailServer, unsigned int port, const char * sender);
FILESERVICES_API void FILESERVICES_CALL fsSendEmailAttachData(ICodeContext * ctx, const char * to, const char * subject, const char * body, size32_t lenAttachment, const void * attachment, const char * mimeType, const char * attachmentName, const char * mailServer, unsigned int port, const char * sender);
FILESERVICES_API char * FILESERVICES_CALL fsCmdProcess(const char *prog, const char *src);
FILESERVICES_API void FILESERVICES_CALL fsSprayFixed(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int recordSize, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false, bool replicate=false, bool compress=false);
FILESERVICES_API void FILESERVICES_CALL fsSprayVariable(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int sourceMaxRecordSize, const char * sourceCsvSeparate, const char * sourceCsvTerminate, const char * sourceCsvQuote, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false, bool replicate=false, bool compress=false);
FILESERVICES_API void FILESERVICES_CALL fsSprayXml(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int sourceMaxRecordSize, const char *sourceRowTag, const char *sourceEncoding, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite, bool replicate, bool compress=false);
FILESERVICES_API void FILESERVICES_CALL fsDespray(ICodeContext *ctx, const char * sourceLogicalName, const char * destinationIP, const char * destinationPath, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false);
FILESERVICES_API void FILESERVICES_CALL fsCopy(ICodeContext *ctx, const char * sourceLogicalName, const char *destinationGroup, const char * destinationLogicalName, const char * sourceDali, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite, bool replicate, bool asSuperfile, bool compress, bool forcePush, int transferBufferSize);
FILESERVICES_API void FILESERVICES_CALL fsDkc(ICodeContext *ctx, const char * sourceLogicalName, const char * destinationIP, const char * destinationPath, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite);
FILESERVICES_API void FILESERVICES_CALL fsReplicate(ICodeContext *ctx, const char * sourceLogicalName, int timeOut, const char * espServerIpPort);
FILESERVICES_API void FILESERVICES_CALL fsCreateSuperFile(ICodeContext *ctx, const char *lsuperfn, bool sequentialparts, bool ifdoesnotexist);
FILESERVICES_API bool FILESERVICES_CALL fsSuperFileExists(ICodeContext *ctx, const char *lsuperfn);
FILESERVICES_API void FILESERVICES_CALL fsDeleteSuperFile(ICodeContext *ctx, const char *lsuperfn,bool deletesub=false);
FILESERVICES_API unsigned FILESERVICES_CALL fsGetSuperFileSubCount(ICodeContext *ctx, const char *lsuperfn);
FILESERVICES_API char *  FILESERVICES_CALL fsGetSuperFileSubName(ICodeContext *ctx, const char *lsuperfn,unsigned filenum,bool abspath);
FILESERVICES_API unsigned FILESERVICES_CALL fsFindSuperFileSubName(ICodeContext *ctx, const char *lsuperfn,const char *_lfn);
FILESERVICES_API void FILESERVICES_CALL fsStartSuperFileTransaction(IGlobalCodeContext *ctx);
FILESERVICES_API void FILESERVICES_CALL fsAddSuperFile(IGlobalCodeContext *ctx, const char *lsuperfn,const char *_lfn,unsigned atpos=0,bool addcontents=false, bool strict=false);
FILESERVICES_API void FILESERVICES_CALL fsRemoveSuperFile(IGlobalCodeContext *ctx, const char *lsuperfn,const char *_lfn,bool del=false,bool remcontents=false);
FILESERVICES_API void FILESERVICES_CALL fsClearSuperFile(IGlobalCodeContext *ctx, const char *lsuperfn,bool del=false);
FILESERVICES_API void FILESERVICES_CALL fsSwapSuperFile(IGlobalCodeContext *ctx, const char *lsuperfn1,const char *lsuperfn2);
FILESERVICES_API void FILESERVICES_CALL fsReplaceSuperFile(IGlobalCodeContext *ctx, const char *lsuperfn,const char *lfn,const char *bylfn);
FILESERVICES_API void FILESERVICES_CALL fsFinishSuperFileTransaction(IGlobalCodeContext *ctx, bool rollback=false);
FILESERVICES_API char *  FILESERVICES_CALL fsForeignLogicalFileName(ICodeContext *ctx, const char *_lfn,const char *foreigndali,bool abspath);
FILESERVICES_API char *  FILESERVICES_CALL fsWaitDfuWorkunit(IGlobalCodeContext *ctx, const char *wuid, int timeout, const char * espServerIpPort);
FILESERVICES_API void FILESERVICES_CALL fsAbortDfuWorkunit(IGlobalCodeContext *ctx, const char *wuid, const char * espServerIpPort);
FILESERVICES_API void  FILESERVICES_CALL fsMonitorLogicalFileName(ICodeContext *ctx, const char *eventname, const char *_lfn,int shotcount, const char * espServerIpPort);
FILESERVICES_API void  FILESERVICES_CALL fsMonitorFile(ICodeContext *ctx, const char *eventname, const char *ip, const char *filename, bool sub, int shotcount, const char * espServerIpPort);
FILESERVICES_API char * FILESERVICES_CALL fsfSprayFixed(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int recordSize, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false, bool replicate=false, bool compress=false);
FILESERVICES_API char * FILESERVICES_CALL fsfSprayVariable(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int sourceMaxRecordSize, const char * sourceCsvSeparate, const char * sourceCsvTerminate, const char * sourceCsvQuote, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false, bool replicate=false, bool compress=false);
FILESERVICES_API char * FILESERVICES_CALL fsfSprayXml(ICodeContext *ctx, const char * sourceIP, const char * sourcePath, int sourceMaxRecordSize, const char *sourceRowTag, const char *sourceEncoding, const char * destinationGroup, const char * destinationLogicalName, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite, bool replicate, bool compress=false);
FILESERVICES_API char * FILESERVICES_CALL fsfDespray(ICodeContext *ctx, const char * sourceLogicalName, const char * destinationIP, const char * destinationPath, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite=false);
FILESERVICES_API char * FILESERVICES_CALL fsfCopy(ICodeContext *ctx, const char * sourceLogicalName, const char *destinationGroup, const char * destinationLogicalName, const char * sourceDali, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite, bool replicate, bool asSuperfile, bool compress, bool forcePush, int transferBufferSize);
FILESERVICES_API char * FILESERVICES_CALL fsfDkc(ICodeContext *ctx, const char * sourceLogicalName, const char * destinationIP, const char * destinationPath, int timeOut, const char * espServerIpPort, int maxConnections, bool overwrite);
FILESERVICES_API char * FILESERVICES_CALL fsfReplicate(ICodeContext *ctx, const char * sourceLogicalName, int timeOut, const char * espServerIpPort);
FILESERVICES_API char *  FILESERVICES_CALL fsfMonitorLogicalFileName(ICodeContext *ctx, const char *eventname, const char *_lfn,int shotcount, const char * espServerIpPort);
FILESERVICES_API char *  FILESERVICES_CALL fsfMonitorFile(ICodeContext *ctx, const char *eventname, const char *ip, const char *filename, bool sub, int shotcount, const char * espServerIpPort);
FILESERVICES_API void FILESERVICES_CALL fsSetFileDescription(ICodeContext *ctx, const char *logicalfilename, const char *value);
FILESERVICES_API char *  FILESERVICES_CALL fsGetFileDescription(ICodeContext *ctx, const char *logicalfilename);
FILESERVICES_API void FILESERVICES_CALL fsRemoteDirectory(size32_t & __lenResult,void * & __result, const char *machineip, const char *dir, const char *mask, bool sub);
FILESERVICES_API void FILESERVICES_CALL fsLogicalFileList(ICodeContext *ctx,size32_t & __lenResult,void * & __result, const char *mask, bool includenormal, bool includesuper, bool unknownszero,const char *foreigndali);
FILESERVICES_API void FILESERVICES_CALL fsSuperFileContents(ICodeContext *ctx,size32_t & __lenResult,void * & __result, const char *lsuperlfn, bool recurse);
FILESERVICES_API void FILESERVICES_CALL fsLogicalFileSuperOwners(ICodeContext *ctx,size32_t & __lenResult,void * & __result, const char *lfn);
FILESERVICES_API char *  FILESERVICES_CALL fsExternalLogicalFileName(const char *location, const char *path,bool abspath);
FILESERVICES_API int  FILESERVICES_CALL fsCompareFiles(ICodeContext *ctx,const char *lfn1, const char *lfn2,bool logicalonly, bool usecrcs);
FILESERVICES_API char *  FILESERVICES_CALL fsVerifyFile(ICodeContext *ctx,const char *lfn,bool usecrcs);
FILESERVICES_API void FILESERVICES_CALL fsRemotePull(ICodeContext *ctx, const char * remoteEspFsURL, const char * sourceLogicalName, const char *destinationGroup, const char * destinationLogicalName, int timeOut, int maxConnections, bool overwrite, bool replicate, bool asSuperfile, bool forcePush, int transferBufferSize,bool wrap,bool compress);
FILESERVICES_API char * FILESERVICES_CALL fsfRemotePull(ICodeContext *ctx, const char * remoteEspFsURL, const char * sourceLogicalName, const char *destinationGroup, const char * destinationLogicalName, int timeOut, int maxConnections, bool overwrite, bool replicate, bool asSuperfile, bool forcePush, int transferBufferSize,bool wrap,bool compress);
FILESERVICES_API void FILESERVICES_CALL fsLogicalFileSuperSubList(ICodeContext *ctx,size32_t & __lenResult,void * & __result);
FILESERVICES_API void FILESERVICES_CALL fslStartSuperFileTransaction(ICodeContext *ctx);
FILESERVICES_API void FILESERVICES_CALL fslAddSuperFile(ICodeContext *ctx, const char *lsuperfn,const char *_lfn,unsigned atpos=0,bool addcontents=false, bool strict=false);
FILESERVICES_API void FILESERVICES_CALL fslRemoveSuperFile(ICodeContext *ctx, const char *lsuperfn,const char *_lfn,bool del=false,bool remcontents=false);
FILESERVICES_API void FILESERVICES_CALL fslClearSuperFile(ICodeContext *ctx, const char *lsuperfn,bool del=false);
FILESERVICES_API void FILESERVICES_CALL fslSwapSuperFile(ICodeContext *ctx, const char *lsuperfn1,const char *lsuperfn2);
FILESERVICES_API void FILESERVICES_CALL fslReplaceSuperFile(ICodeContext *ctx, const char *lsuperfn,const char *lfn,const char *bylfn);
FILESERVICES_API void FILESERVICES_CALL fslFinishSuperFileTransaction(ICodeContext *ctx, bool rollback=false);
FILESERVICES_API char * FILESERVICES_CALL fslWaitDfuWorkunit(ICodeContext *ctx, const char *wuid, int timeout, const char * espServerIpPort);
FILESERVICES_API void FILESERVICES_CALL fslAbortDfuWorkunit(ICodeContext *ctx, const char *wuid, const char * espServerIpPort);
FILESERVICES_API void FILESERVICES_CALL fsPromoteSuperFileList(ICodeContext * ctx,bool isAllLsuperfns,size32_t  lenLsuperfns,const void * lsuperfns,const char * addhead,bool deltail,bool createonlyonesuperfile,bool reverse);
FILESERVICES_API char * FILESERVICES_CALL fsfPromoteSuperFileList(ICodeContext * ctx,bool isAllLsuperfns,size32_t  lenLsuperfns,const void * lsuperfns,const char * addhead,bool deltail,bool createonlyonesuperfile,bool reverse);
FILESERVICES_API unsigned __int64 FILESERVICES_CALL fsGetUniqueInteger(const char *foreigndali);
FILESERVICES_API void FILESERVICES_CALL fsAddFileRelationship(ICodeContext * ctx,const char *primary, const char *secondary, const char *primflds, const char *secflds, const char *kind, const char *cardinality, bool payload, const char *description);
FILESERVICES_API void FILESERVICES_CALL fsFileRelationshipList(ICodeContext * ctx,size32_t & __lenResult,void * & __result,const char *primary, const char *secondary, const char *primflds, const char *secflds, const char *kind);
FILESERVICES_API void FILESERVICES_CALL fsRemoveFileRelationship(ICodeContext * ctx,const char *primary, const char *secondary, const char *primflds, const char *secflds, const char *kind);
FILESERVICES_API void FILESERVICES_CALL fsSetColumnMapping(ICodeContext * ctx,const char *filename, const char *mapping);
FILESERVICES_API char *  FILESERVICES_CALL fsfGetColumnMapping(ICodeContext * ctx,const char *filename);
FILESERVICES_API char *  FILESERVICES_CALL fsfRfsQuery(const char *server, const char *query);
FILESERVICES_API void FILESERVICES_CALL fsRfsAction(const char *server, const char *query);
FILESERVICES_API char *  FILESERVICES_CALL fsfGetHostName(const char *ipaddress);
FILESERVICES_API char *  FILESERVICES_CALL fsfResolveHostName(const char *hostname);
FILESERVICES_API void  FILESERVICES_CALL fsMoveExternalFile(ICodeContext * ctx,const char *location,const char *frompath,const char *topath);
FILESERVICES_API void  FILESERVICES_CALL fsDeleteExternalFile(ICodeContext * ctx,const char *location,const char *path);
FILESERVICES_API void  FILESERVICES_CALL fsCreateExternalDirectory(ICodeContext * ctx,const char *location,const char *path);
FILESERVICES_API char * FILESERVICES_CALL fsfGetLogicalFileAttribute(ICodeContext * ctx,const char *lfn,const char *attrname);
FILESERVICES_API void FILESERVICES_CALL fsProtectLogicalFile(ICodeContext * ctx,const char *lfn,bool set);
FILESERVICES_API void FILESERVICES_CALL fsDfuPlusExec(ICodeContext * ctx,const char *_cmd);

}

#endif

