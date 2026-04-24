module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.h"

export module WandX.Win32;

import WandX;

export namespace WandX {

#pragma region WandX.Win32 API Wrappers

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnDirect = BridgeAPI<file, name, decltype(fn)>
	::template Ref<fn>
	::Passby;

template<auto file, auto name, auto fn,
	AssertOperatorType auto assert,
	class NewRet = ReturnTypeOf<fn>,
	auto GetLastError = ::GetLastError>
using RefReturnAssert = BridgeAPI<file, name, decltype(fn)>
	::template Ref<fn>
	::template AssertReturn<assert, NewRet, GetLastError>;

inline bool HandleNotInvalid(HANDLE h) { return h != INVALID_HANDLE_VALUE; }
constexpr auto AssertHandleNotInvalid = AssertOperator<
	HANDLE, AssertOps::CustomTest, HandleNotInvalid,
	LiString(" == INVALID_HANDLE_VALUE")>();
template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
	requires(IsSame<ReturnTypeOf<fn>, HANDLE>)
using RefReturnHandle = RefReturnAssert<
	file, name, fn,
	AssertHandleNotInvalid,
	HANDLE, GetLastError>;

inline bool ResultSuccess(HRESULT hr) {
	if (SUCCEEDED(hr)) return true;
	SetLastError(hr);
	return false;
}
constexpr auto AssertResultSuccess = AssertOperator<
	HRESULT, AssertOps::CustomTest, ResultSuccess,
	LiString(" is failed")>();
template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
	requires(IsSameSize<ReturnTypeOf<fn>, HRESULT>)
using RefReturnSuccess = RefReturnAssert<
	file, name, fn,
	AssertResultSuccess,
	HRESULT, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnTrue = RefReturnAssert<
	file, name, fn,
	AssertTrue<ReturnTypeOf<fn>>,
	void, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnNotZero = RefReturnAssert<
	file, name, fn,AssertNotZero<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnNotNull = RefReturnAssert<
	file, name, fn,AssertNotNull<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	auto GetLastError = ::GetLastError>
using RefReturnPositive = RefReturnAssert<
	file, name, fn,AssertPositive<ReturnTypeOf<fn>>,
	ReturnTypeOf<fn>, GetLastError>;

template<auto file, auto name, auto fn,
	ReturnTypeOf<fn> fault_val, auto fault_str,
	auto GetLastError = ::GetLastError>
using RefReturnFault = RefReturnAssert<
	file, name, fn,
	AssertFaultValue<ReturnTypeOf<fn>, fault_val, fault_str>,
	ReturnTypeOf<fn>, GetLastError>;

///

template<auto fnW, auto fnA>
concept WinAPIPair =
	IsSame<ReturnTypeOf<fnW>, ReturnTypeOf<fnA>> &&
	ParaCountOf(fnW) == ParaCountOf(fnA) &&
	!InvokableAmbiguous<fnW, fnA>;

template<
	template<auto file, auto name, auto fn, auto GetLastError> class RefReturnType,
	auto file, auto name, auto fnW, auto fnA,
	auto GetLastError = ::GetLastError>
	requires(WinAPIPair<fnW, fnA>)
using RefReturnWA = OverrideFunctor<
	RefReturnType<file, name + "W", fnW, GetLastError>,
	RefReturnType<file, name + "A", fnA, GetLastError>>;

#pragma endregion

}

static constexpr auto ThisFile = WandX::LiString("WandX.Win32");

export namespace WandX::Native {

constexpr bool IsUnicode =
#ifdef UNICODE
	UNICODE;
#elif defined(_UNICODE)
	_UNICODE;
#else
	false;
#endif

#pragma region WinBase.h
// GlobalAlloc
// GlobalReAlloc
// GlobalSize
// GlobalUnlock
// GlobalLock
// GlobalFlags
// GlobalHandle
// GlobalFree
// GlobalMemoryStatus
// LocalAlloc
// LocalReAlloc
// LocalLock
// LocalHandle
// LocalUnlock
// LocalSize
// LocalFlags
// LocalFree
// GetBinaryType
wapi_ret_true_WAO(GetBinaryType);
wapi_ret_positive_WAO(GetLongPathNameTransacted);
// GetProcessAffinityMask
// SetProcessAffinityMask
// GetProcessIoCounters
// FatalExit
// SwitchToFiber
// DeleteFiber
// ConvertFiberToThread
// CreateFiberEx
// ConvertThreadToFiberEx
// CreateFiber
// ConvertThreadToFiber
// CreateUmsCompletionList
// DequeueUmsCompletionListItems
// GetUmsCompletionListEvent
// ExecuteUmsThread
// UmsThreadYield
// DeleteUmsCompletionList
// GetCurrentUmsThread
// GetNextUmsListItem
// QueryUmsThreadInformation
// SetUmsThreadInformation
// DeleteUmsThreadContext
// CreateUmsThreadContext
// EnterUmsSchedulingMode
// GetUmsSystemThreadInformation
// SetThreadAffinityMask
// SetProcessDEPPolicy
// GetProcessDEPPolicy
// RequestWakeupLatency
// IsSystemResumeAutomatic
// GetThreadSelectorEntry
// SetThreadExecutionState
// PowerCreateRequest
// PowerSetRequest
// PowerClearRequest
// SetFileCompletionNotificationModes
// Wow64GetThreadSelectorEntry
// DebugSetProcessKillOnExit
// DebugBreakProcess
wapi_ret_true(PulseEvent);
wapi_ret_true(GlobalDeleteAtom);
// InitAtomTable
wapi_ret_true(DeleteAtom);
// SetHandleCount
// GetDevicePowerState
wapi_ret_true_WAO(SetFileShortName);
// LoadModule
// WinExec
wapi_ret_true(ClearCommBreak);
wapi_ret_true(ClearCommError);
wapi_ret_true(SetupComm);
wapi_ret_true(EscapeCommFunction);
wapi_ret_true(GetCommConfig);
wapi_ret_true(GetCommMask);
wapi_ret_true(GetCommProperties);
wapi_ret_true(GetCommModemStatus);
wapi_ret_true(GetCommState);
wapi_ret_true(GetCommTimeouts);
wapi_ret_true(PurgeComm);
wapi_ret_true(SetCommBreak);
wapi_ret_true(SetCommConfig);
wapi_ret_true(SetCommMask);
wapi_ret_true(SetCommState);
wapi_ret_true(SetCommTimeouts);
wapi_ret_true(TransmitCommChar);
wapi_ret_true(WaitCommEvent);
#if (NTDDI_VERSION >= NTDDI_WIN10_RS3)
wapi_ret_validhd(OpenCommPort);
wapi_ret_success(GetCommPorts);
#endif
// SetTapePosition
// GetTapePosition
// PrepareTape
// EraseTape
// CreateTapePartition
// WriteTapemark
// GetTapeStatus
// GetTapeParameters
// SetTapeParameters
// GetSystemDEPPolicy
// GetSystemRegistryQuota
// FileTimeToDosDateTime
// DosDateTimeToFileTime
wapi_ret_positive_WAO(FormatMessage);
wapi_ret_notnull_WAO(CreateMailslot);
// GetMailslotInfo
// SetMailslotInfo
wapi_ret_true_WAO(EncryptFile);
wapi_ret_true_WAO(DecryptFile);
wapi_ret_true_WAO(FileEncryptionStatus);
wapi_ret_success_WAO(OpenEncryptedFileRaw);
// ReadEncryptedFileRaw
// WriteEncryptedFileRaw
// CloseEncryptedFileRaw
// OpenFile
// IsTextUnicode
// BackupRead
// BackupSeek
// BackupWrite
// CreateFileMapping
inline HANDLE CreateFileMapping(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName)
	safe_ret_as(auto h = ::CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName), h);
// from fileapi.h
inline HANDLE CreateFileMapping(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName)
	safe_ret_as(auto h = ::CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName), h);
// CreateFileMappingNuma
inline HANDLE CreateFileMappingNuma(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName, DWORD nndPreferred)
	safe_ret_as(auto h = ::CreateFileMappingNumaA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred), h);
// from fileapi.h
inline HANDLE CreateFileMappingNuma(HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes, DWORD flProtect,DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName, DWORD nndPreferred)
	safe_ret_as(auto h = ::CreateFileMappingNumaW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred), h);
// OpenFileMapping
inline HANDLE OpenFileMapping(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
	safe_ret_as(auto h = ::OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName), h);
// from fileapi.h
inline HANDLE OpenFileMapping(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName)
	safe_ret_as(auto h = ::OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName), h);
// GetLogicalDriveStrings
inline DWORD GetLogicalDriveStrings(LPSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto h = ::GetLogicalDriveStringsA(nSize, lpBuffer), h);
// from fileapi.h
inline DWORD GetLogicalDriveStrings(LPWSTR lpBuffer, DWORD nSize)
	safe_ret_as(auto h = ::GetLogicalDriveStringsW(nSize, lpBuffer), h);
// LoadPackagedLibrary
wapi_ret_true_WAO(QueryFullProcessImageName);
wapi_ret_positive_WAO(GetFirmwareEnvironmentVariable);
wapi_ret_positive_WAO(GetFirmwareEnvironmentVariableEx);
wapi_ret_true_WAO(SetFirmwareEnvironmentVariable);
wapi_ret_true_WAO(SetFirmwareEnvironmentVariableEx);
// GetFirmwareType
// IsNativeVhdBoot
wapi_ret_true_WAO(EnumResourceTypes);
wapi_ret_true_WAO(EnumResourceLanguages);
wapi_ret_notnull_WAO(BeginUpdateResource);
wapi_ret_true_WAO(UpdateResource);
wapi_ret_true_WAT(EndUpdateResource);
wapi_ret_positive_WAO(GlobalAddAtom);
wapi_ret_positive_WAO(GlobalAddAtomEx);
wapi_ret_positive_WAO(GlobalFindAtom);
wapi_ret_positive_WAO(GlobalGetAtomName);
wapi_ret_positive_WAO(AddAtom);
wapi_ret_positive_WAO(FindAtom);
wapi_ret_positive_WAO(GetAtomName);
wapi_ret_direct_WAO(GetProfileInt);
wapi_ret_direct_WAO(GetProfileString);
wapi_ret_true_WAO(WriteProfileString);
wapi_ret_direct_WAO(GetProfileSection);
wapi_ret_true_WAO(WriteProfileSection);
wapi_ret_direct_WAO(GetPrivateProfileInt);
wapi_ret_positive_WAO(GetPrivateProfileString);
wapi_ret_true_WAO(WritePrivateProfileString);
wapi_ret_positive_WAO(GetPrivateProfileSection);
wapi_ret_true_WAO(WritePrivateProfileSection);
wapi_ret_positive_WAO(GetPrivateProfileSectionNames);
wapi_ret_true_WAO(GetPrivateProfileStruct);
wapi_ret_true_WAO(WritePrivateProfileStruct);
wapi_ret_true_WAO(SetDllDirectory);
wapi_ret_positive_WAO(GetDllDirectory);
// SetSearchPathMode
wapi_ret_true_WAO(CreateDirectoryEx);
wapi_ret_true_WAO(CreateDirectoryTransacted);
// RemoveDirectory
// from fileapi.h
inline void RemoveDirectory(LPCSTR lpPathName)
	safe_ret_as(::RemoveDirectoryA(lpPathName));
// from fileapi.h
inline void RemoveDirectory(LPCWSTR lpPathName)
	safe_ret_as(::RemoveDirectoryW(lpPathName));
wapi_ret_true_WAO(RemoveDirectoryTransacted);
// GetFullPathName
// from fileapi.h
inline DWORD GetFullPathName(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart)
	safe_ret_as(auto h = ::GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart), h);
// from fileapi.h
inline DWORD GetFullPathName(LPCWSTR lpFileName, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart)
	safe_ret_as(auto h = ::GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart), h);
wapi_ret_positive_WAO(GetFullPathNameTransacted);
// DefineDosDevice
inline void DefineDosDevice(DWORD dwFlags, LPCSTR lpDeviceName, LPCSTR lpTargetPath)
	safe_ret_as(::DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath));
// from fileapi.h
inline void DefineDosDevice(DWORD dwFlags, LPCWSTR lpDeviceName, LPCWSTR lpTargetPath)
	safe_ret_as(::DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath));
// QueryDosDevice
inline DWORD QueryDosDevice(LPCSTR lpDeviceName, LPSTR lpTargetPath, DWORD ucchMax)
	safe_ret_as(auto h = ::QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax), h);
// from fileapi.h
inline DWORD QueryDosDevice(LPCWSTR lpDeviceName, LPWSTR lpTargetPath, DWORD ucchMax)
	safe_ret_as(auto h = ::QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax), h);
// CreateFileTransacted
inline HANDLE CreateFileTransacted(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile, HANDLE hTransaction, PUSHORT pusMiniVersion, PVOID  lpExtendedParameter)
	safe_ret_as(auto h = ::CreateFileTransactedA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile,hTransaction, pusMiniVersion, lpExtendedParameter); h != INVALID_HANDLE_VALUE, h);
inline HANDLE CreateFileTransacted(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile, HANDLE hTransaction, PUSHORT pusMiniVersion, PVOID  lpExtendedParameter)
	safe_ret_as(auto h = ::CreateFileTransactedW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile,hTransaction, pusMiniVersion, lpExtendedParameter); h != INVALID_HANDLE_VALUE, h);
// ReOpenFile
// SetFileAttributes
// from fileapi.h
inline void SetFileAttributes(LPCSTR lpFileName, DWORD dwFileAttributes)
	safe_ret_as(::SetFileAttributesA(lpFileName, dwFileAttributes));
// from fileapi.h
inline void SetFileAttributes(LPCWSTR lpFileName, DWORD dwFileAttributes)
	safe_ret_as(::SetFileAttributesW(lpFileName, dwFileAttributes));
wapi_ret_true_WAO(SetFileAttributesTransacted);
// GetFileAttributes
// from fileapi.h
inline DWORD GetFileAttributes(LPCSTR lpFileName)
	safe_ret_as(auto h = ::GetFileAttributesA(lpFileName); h != INVALID_FILE_ATTRIBUTES, h);
// from fileapi.h
inline DWORD GetFileAttributes(LPCWSTR lpFileName)
	safe_ret_as(auto h = ::GetFileAttributesW(lpFileName); h != INVALID_FILE_ATTRIBUTES, h);
wapi_ret_true_WAO(GetFileAttributesEx);
wapi_ret_true_WAO(GetFileAttributesTransacted);
// GetCompressedFileSize
// from fileapi.h
inline DWORD GetCompressedFileSize(LPCSTR lpFileName, LPDWORD lpFileSizeHigh)
	safe_ret_as(auto h = ::GetCompressedFileSizeA(lpFileName, lpFileSizeHigh); h != INVALID_FILE_SIZE, h);
// from fileapi.h
inline DWORD GetCompressedFileSize(LPCWSTR lpFileName, LPDWORD lpFileSizeHigh)
	safe_ret_as(auto h = ::GetCompressedFileSizeW(lpFileName, lpFileSizeHigh); h != INVALID_FILE_SIZE, h);
// GetCompressedFileSizeTransacted
inline DWORD GetCompressedFileSizeTransacted(LPCSTR lpFileName, LPDWORD lpFileSizeHigh, HANDLE hTransaction)
	safe_ret_as(auto h = ::GetCompressedFileSizeTransactedA(lpFileName, lpFileSizeHigh, hTransaction); h != INVALID_FILE_SIZE, h);
inline DWORD GetCompressedFileSizeTransacted(LPCWSTR lpFileName, LPDWORD lpFileSizeHigh, HANDLE hTransaction)
	safe_ret_as(auto h = ::GetCompressedFileSizeTransactedW(lpFileName, lpFileSizeHigh, hTransaction); h != INVALID_FILE_SIZE, h);
wapi_ret_true_WAO(DeleteFileTransacted);
wapi_ret_true_WAO(CheckNameLegalDOS8Dot3);
// FindFirstFile
// from fileapi.h
inline HANDLE FindFirstFile(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
	safe_ret_as(auto h = ::FindFirstFileA(lpFileName, lpFindFileData); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstFile(LPCWSTR lpFileName, LPWIN32_FIND_DATAW lpFindFileData)
	safe_ret_as(auto h = ::FindFirstFileW(lpFileName, lpFindFileData); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileEx
// from fileapi.h
inline HANDLE FindFirstFile(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags)
	safe_ret_as(auto h = ::FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData,   fSearchOp, lpSearchFilter, dwAdditionalFlags); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstFile(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags)
	safe_ret_as(auto h = ::FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData,   fSearchOp, lpSearchFilter, dwAdditionalFlags); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileTransacted
inline HANDLE FindFirstFileTransacted(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileTransactedA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
inline HANDLE FindFirstFileTransacted(LPCWSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileTransactedW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
wapi_ret_true_WAO(CopyFile);
wapi_ret_true_WAO(CopyFileEx);
// CopyFileTransacted
// CopyFile2
wapi_ret_true_WAO(MoveFile);
wapi_ret_true_WAO(MoveFileEx);
wapi_ret_true_WAO(MoveFileWithProgress);
wapi_ret_true_WAO(ReplaceFile);
wapi_ret_true_WAO(CreateHardLink);
wapi_ret_true_WAO(CreateHardLinkTransacted);
// FindFirstStreamTransacted
inline HANDLE FindFirstStreamTransacted(LPCWSTR lpFileName, STREAM_INFO_LEVELS InfoLevel, LPVOID lpFindStreamData, DWORD dwFlags, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstStreamTransactedW(lpFileName, InfoLevel, lpFindStreamData, dwFlags, hTransaction); h != INVALID_HANDLE_VALUE, h);
// FindFirstFileName
inline HANDLE FindFirstFileNameTransacted(LPCWSTR lpFileName, DWORD dwFlags, LPDWORD StringLength, PWSTR LinkName, HANDLE hTransaction)
	safe_ret_as(auto h = ::FindFirstFileNameTransactedW(lpFileName, dwFlags, StringLength, LinkName, hTransaction); h != INVALID_HANDLE_VALUE, h);
// CreateNamedPipe
inline HANDLE CreateNamedPipe(LPCSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(auto h = ::CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); h != INVALID_HANDLE_VALUE, h);
// from namedpipeapi.h
inline HANDLE CreateNamedPipe(LPCWSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize,  DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
	safe_ret_as(auto h = ::CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); h != INVALID_HANDLE_VALUE, h);
// GetNamedPipeHandleState
inline void GetNamedPipeHandleState(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout, LPSTR lpUserName, DWORD nMaxUserNameSize)
	safe_ret_as(::GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount,  lpCollectDataTimeout, lpUserName, nMaxUserNameSize));
// from namedpipeapi.h
inline void GetNamedPipeHandleState(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout, LPWSTR lpUserName, DWORD nMaxUserNameSize)
	safe_ret_as(::GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount,  lpCollectDataTimeout, lpUserName, nMaxUserNameSize));
// CallNamedPipe
inline void CallNamedPipe(LPCSTR lpNamedPipeName, LPVOID lpInBuffer, DWORD nInBufferSize,  LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesRead, DWORD nTimeOut)
	safe_ret_as(::CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut));
// from namedpipeapi.h
inline void CallNamedPipe(LPCWSTR lpNamedPipeName, LPVOID lpInBuffer, DWORD nInBufferSize,  LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesRead, DWORD nTimeOut)
	safe_ret_as(::CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut));
// WaitNamedPipe
inline void WaitNamedPipe(LPCSTR lpNamedPipeName, DWORD nTimeOut)
	safe_ret_as(::WaitNamedPipeA(lpNamedPipeName, nTimeOut));
// from namedpipeapi.h
inline void WaitNamedPipe(LPCWSTR lpNamedPipeName, DWORD nTimeOut)
	safe_ret_as(::WaitNamedPipeW(lpNamedPipeName, nTimeOut));
// GetNamedPipeClientComputerName
inline void GetNamedPipeClientComputerName(HANDLE Pipe, LPSTR ClientComputerName, ULONG ClientComputerNameLength)
	safe_ret_as(::GetNamedPipeClientComputerNameA(Pipe, ClientComputerName, ClientComputerNameLength));
// from namedpipeapi.h
inline void GetNamedPipeClientComputerName(HANDLE Pipe, LPWSTR ClientComputerName, ULONG ClientComputerNameLength)
	safe_ret_as(::GetNamedPipeClientComputerNameW(Pipe, ClientComputerName, ClientComputerNameLength));
// GetNamedPipeClientProcessId
// GetNamedPipeClientSessionId
// GetNamedPipeServerProcessId
// GetNamedPipeServerSessionId
wapi_ret_true_WAO(SetVolumeLabel);
// SetFileBandwidthReservation
// GetFileBandwidthReservation
// ClearEventLog
wapi_ret_true_WAO(BackupEventLog);
// CloseEventLog
// DeregisterEventSource
// NotifyChangeEventLog
// GetNumberOfEventLogRecords
// GetOldestEventLogRecord
wapi_ret_notnull_WAO(OpenEventLog);
wapi_ret_notnull_WAO(RegisterEventSource);
wapi_ret_notnull_WAO(OpenBackupEventLog);
wapi_ret_positive_WAT(ReadEventLog);
wapi_ret_true_WAO(ReportEvent);
// GetEventLogInformation
// OperationStart
// OperationEnd
// AccessCheckAndAuditAlarm
inline void AccessCheckAndAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL GenerateOnClose)
	safe_ret_as(::AccessCheckAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName,   SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation,   GrantedAccess, AccessStatus, GenerateOnClose));
// from securitybaseapi.h
inline void AccessCheckAndAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPWSTR ObjectTypeName, LPWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL GenerateOnClose)
	safe_ret_as(::AccessCheckAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName,   SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation,   GrantedAccess, AccessStatus, GenerateOnClose));
// AccessCheckByTypeAndAuditAlarmA
// AccessCheckByTypeResultListAndAuditAlarm
inline void AccessCheckByTypeResultListAndAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPDWORD AccessStatus, LPBOOL pfGenerateOnClose)
	safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName,   SecurityDescriptor, PrincipalSelfSid, DesiredAccess,   AuditType, Flags, ObjectTypeList, ObjectTypeListLength,   GenericMapping, ObjectCreation, GrantedAccess,   AccessStatus, pfGenerateOnClose));
// from securitybaseapi.h
inline void AccessCheckByTypeResultListAndAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPWSTR ObjectTypeName, LPWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPDWORD AccessStatus, LPBOOL pfGenerateOnClose)
	safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName,   SecurityDescriptor, PrincipalSelfSid, DesiredAccess,   AuditType, Flags, ObjectTypeList, ObjectTypeListLength,   GenericMapping, ObjectCreation, GrantedAccess,   AccessStatus, pfGenerateOnClose));
// AccessCheckByTypeResultListAndAuditAlarmByHandle
inline void AccessCheckByTypeResultListAndAuditAlarmByHandle(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, LPCSTR ObjectTypeName, LPCSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPDWORD AccessStatusList, LPBOOL pfGenerateOnClose)
	safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmByHandleA(SubsystemName, HandleId, ClientToken,   ObjectTypeName, ObjectName, SecurityDescriptor,   PrincipalSelfSid, DesiredAccess, AuditType,   Flags, ObjectTypeList, ObjectTypeListLength,   GenericMapping, ObjectCreation, GrantedAccess,   AccessStatusList, pfGenerateOnClose));
// from securitybaseapi.h
inline void AccessCheckByTypeResultListAndAuditAlarmByHandle(LPCWSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, LPCWSTR ObjectTypeName, LPCWSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, PSID PrincipalSelfSid, DWORD DesiredAccess, AUDIT_EVENT_TYPE AuditType, DWORD Flags, POBJECT_TYPE_LIST ObjectTypeList, DWORD ObjectTypeListLength, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPDWORD AccessStatusList, LPBOOL pfGenerateOnClose)
	safe_ret_as(::AccessCheckByTypeResultListAndAuditAlarmByHandleW(SubsystemName, HandleId, ClientToken,   ObjectTypeName, ObjectName, SecurityDescriptor,   PrincipalSelfSid, DesiredAccess, AuditType,   Flags, ObjectTypeList, ObjectTypeListLength,   GenericMapping, ObjectCreation, GrantedAccess,   AccessStatusList, pfGenerateOnClose));
// ObjectOpenAuditAlarm
inline void ObjectOpenAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose)
	safe_ret_as(::ObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName,   pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess,   Privileges, ObjectCreation, AccessGranted, GenerateOnClose));
// from securitybaseapi.h
inline void ObjectOpenAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, LPWSTR ObjectTypeName, LPWSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose)
	safe_ret_as(::ObjectOpenAuditAlarmW(SubsystemName, HandleId, ObjectTypeName, ObjectName,   pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess,   Privileges, ObjectCreation, AccessGranted, GenerateOnClose));
// ObjectPrivilegeAuditAlarm
inline void ObjectPrivilegeAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken,  DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
	safe_ret_as(::ObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted));
// from securitybaseapi.h
inline void ObjectPrivilegeAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken,  DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
	safe_ret_as(::ObjectPrivilegeAuditAlarmW(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted));
// ObjectCloseAuditAlarm
inline void ObjectCloseAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
	safe_ret_as(::ObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose));
// from securitybaseapi.h
inline void ObjectCloseAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
	safe_ret_as(::ObjectCloseAuditAlarmW(SubsystemName, HandleId, GenerateOnClose));
// ObjectDeleteAuditAlarm
inline void ObjectDeleteAuditAlarm(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
	safe_ret_as(::ObjectDeleteAuditAlarmA(SubsystemName, HandleId, GenerateOnClose));
// from securitybaseapi.h
inline void ObjectDeleteAuditAlarm(LPCWSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
	safe_ret_as(::ObjectDeleteAuditAlarmW(SubsystemName, HandleId, GenerateOnClose));
// PrivilegedServiceAuditAlarm
inline void PrivilegedServiceAuditAlarm(LPCSTR SubsystemName, LPCSTR ServiceName, HANDLE ClientToken,PPRIVILEGE_SET Privileges, BOOL AccessGranted)
	safe_ret_as(::PrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted));
// from securitybaseapi.h
inline void PrivilegedServiceAuditAlarm(LPCWSTR SubsystemName, LPCWSTR ServiceName, HANDLE ClientToken,PPRIVILEGE_SET Privileges, BOOL AccessGranted)
	safe_ret_as(::PrivilegedServiceAuditAlarmW(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted));
// AddConditionalAce
// SetFileSecurity
inline void SetFileSecurity(LPCSTR lpFileName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor)
	safe_ret_as(::SetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor));
// from securitybaseapi.h
inline void SetFileSecurity(LPCWSTR lpFileName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor)
	safe_ret_as(::SetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor));
// GetFileSecurity
inline void GetFileSecurity(LPCSTR lpFileName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength, LPDWORD lpnLengthNeeded)
	safe_ret_as(::GetFileSecurityA(lpFileName, SecurityInformation, pSecurityDescriptor, nLength, lpnLengthNeeded));
// from securitybaseapi.h
inline void GetFileSecurity(LPCWSTR lpFileName, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength, LPDWORD lpnLengthNeeded)
	safe_ret_as(::GetFileSecurityW(lpFileName, SecurityInformation, pSecurityDescriptor, nLength, lpnLengthNeeded));
// ReadDirectoryChanges
inline void ReadDirectoryChanges(HANDLE hDirectory, LPVOID lpBuffer, DWORD nBufferLength, BOOL bWatchSubtree, DWORD dwNotifyFilter, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
	safe_ret_as(::ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree,   dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine));
#if (NTDDI_VERSION >= NTDDI_WIN10_RS3)
// ReadDirectoryChangesEx
inline void ReadDirectoryChangesEx(HANDLE hDirectory, LPVOID lpBuffer, DWORD nBufferLength, BOOL bWatchSubtree, DWORD dwNotifyFilter, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped, LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine, READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass)
	safe_ret_as(::ReadDirectoryChangesExW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine, ReadDirectoryNotifyInformationClass));
#endif
// MapViewOfFileExNuma
// IsBadReadPtr - deprecated
// IsBadWritePtr - deprecated
// IsBadCodePtr - deprecated
// IsBadStringPtr - deprecated
wapi_ret_true_WAO(LookupAccountSid);
wapi_ret_true_WAO(LookupAccountName);
wapi_ret_true_WAO(LookupAccountNameLocal);
wapi_ret_true_WAO(LookupAccountSidLocal);
wapi_ret_true_WAO(LookupPrivilegeValue);
wapi_ret_true_WAO(LookupPrivilegeName);
wapi_ret_true_WAO(LookupPrivilegeDisplayName);
wapi_ret_true_WAO(BuildCommDCB);
wapi_ret_true_WAO(BuildCommDCBAndTimeouts);
wapi_ret_true_WAO(CommConfigDialog);
wapi_ret_true_WAO(GetDefaultCommConfig);
wapi_ret_true_WAO(SetDefaultCommConfig);
wapi_ret_true_WAO(GetComputerName);
wapi_ret_true_WAO(DnsHostnameToComputerName);
wapi_ret_true_WAO(GetUserName);
wapi_ret_true_WAO(LogonUser);
wapi_ret_true_WAO(LogonUserEx);
// CreateProcessWithLogon
inline void CreateProcessWithLogon(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags,   LPCWSTR lpApplicationName, LPWSTR lpCommandLine,   DWORD dwCreationFlags, LPVOID lpEnvironment,   LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo,   LPPROCESS_INFORMATION lpProcessInformation)
	safe_ret_as(::CreateProcessWithLogonW(lpUsername, lpDomain, lpPassword, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation));
// CreateProcessWithToken
inline void CreateProcessWithToken(HANDLE hToken, DWORD dwLogonFlags, LPCWSTR lpApplicationName,   LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment,   LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo,   LPPROCESS_INFORMATION lpProcessInformation)
	safe_ret_as(::CreateProcessWithTokenW(hToken, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation));
wapi_ret_true(RegisterWaitForSingleObject);
wapi_ret_true(UnregisterWait);
// BindIoCompletionCallback
// CreatePrivateNamespace
inline HANDLE CreatePrivateNamespace(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes, LPVOID lpBoundaryDescriptor, LPCSTR lpAliasPrefix)
	safe_ret_as(auto h = ::CreatePrivateNamespaceA(lpPrivateNamespaceAttributes, lpBoundaryDescriptor, lpAliasPrefix), h);
// from namespaceapi.h
inline HANDLE CreatePrivateNamespace(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes, LPVOID lpBoundaryDescriptor, LPCWSTR lpAliasPrefix)
	safe_ret_as(auto h = ::CreatePrivateNamespaceW(lpPrivateNamespaceAttributes, lpBoundaryDescriptor, lpAliasPrefix), h);
// OpenPrivateNamespace
inline HANDLE OpenPrivateNamespace(LPVOID lpBoundaryDescriptor, LPCSTR lpAliasPrefix)
	safe_ret_as(auto h = ::OpenPrivateNamespaceA(lpBoundaryDescriptor, lpAliasPrefix), h);
// from namespaceapi.h
inline HANDLE OpenPrivateNamespace(LPVOID lpBoundaryDescriptor, LPCWSTR lpAliasPrefix)
	safe_ret_as(auto h = ::OpenPrivateNamespaceW(lpBoundaryDescriptor, lpAliasPrefix), h);
// CreateBoundaryDescriptor
inline HANDLE CreateBoundaryDescriptor(LPCSTR Name, DWORD Flags)
	safe_ret_as(auto h = ::CreateBoundaryDescriptorA(Name, Flags), h);
// namespaceapi.h
inline HANDLE CreateBoundaryDescriptor(LPCWSTR Name, DWORD Flags)
	safe_ret_as(auto h = ::CreateBoundaryDescriptorW(Name, Flags), h);
// AddIntegrityLabelToBoundaryDescriptor
wapi_ret_true_WAO(GetCurrentHwProfile);
// VerifyVersionInfo
//inline void VerifyVersionInfo(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
//	safe_ret_as(::VerifyVersionInfoA(lpVersionInfo, dwTypeMask, dwlConditionMask));
//inline void VerifyVersionInfo(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
//	safe_ret_as(::VerifyVersionInfoW(lpVersionInfo, dwTypeMask, dwlConditionMask));// SetSystemPowerState
// GetSystemPowerStatus
// MapUserPhysicalPagesScatter
// CreateJobObject
inline HANDLE CreateJobObject(LPSECURITY_ATTRIBUTES lpJobAttributes, LPCSTR lpName)
	safe_ret_as(auto h = ::CreateJobObjectA(lpJobAttributes, lpName), h);
// from jobapi2.h
inline HANDLE CreateJobObject(LPSECURITY_ATTRIBUTES lpJobAttributes, LPCWSTR lpName)
	safe_ret_as(auto h = ::CreateJobObjectW(lpJobAttributes, lpName), h);
// OpenJobObject
inline HANDLE OpenJobObject(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
	safe_ret_as(auto h = ::OpenJobObjectA(dwDesiredAccess, bInheritHandle, lpName), h);
// from jobapi2.h
inline HANDLE OpenJobObject(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName)
	safe_ret_as(auto h = ::OpenJobObjectW(dwDesiredAccess, bInheritHandle, lpName), h);
// FindFirstVolume
inline HANDLE FindFirstVolume(LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeA(lpszVolumeName, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
// from fileapi.h
inline HANDLE FindFirstVolume(LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeW(lpszVolumeName, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
// FindNextVolume
inline void FindNextVolume(HANDLE hFindVolume, LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::FindNextVolumeA(hFindVolume, lpszVolumeName, cchBufferLength));
// from fileapi.h
inline void FindNextVolume(HANDLE hFindVolume, LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::FindNextVolumeW(hFindVolume, lpszVolumeName, cchBufferLength));
// FindFirstVolumeMountPoint
inline HANDLE FindFirstVolumeMountPoint(LPCSTR lpszRootPathName, LPSTR lpszVolumeMountPoint, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeMountPointA(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
inline HANDLE FindFirstVolumeMountPoint(LPCWSTR lpszRootPathName, LPWSTR lpszVolumeMountPoint, DWORD cchBufferLength)
	safe_ret_as(auto h = ::FindFirstVolumeMountPointW(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); h != INVALID_HANDLE_VALUE, h);
wapi_ret_true_WAO(FindNextVolumeMountPoint);
// FindVolumeMountPointClose
wapi_ret_true_WAO(SetVolumeMountPoint);
// DeleteVolumeMountPoint
inline void DeleteVolumeMountPoint(LPCSTR lpszVolumeMountPoint)
	safe_ret_as(::DeleteVolumeMountPointA(lpszVolumeMountPoint));
// from fileapi.h
inline void DeleteVolumeMountPoint(LPCWSTR lpszVolumeMountPoint)
	safe_ret_as(::DeleteVolumeMountPointW(lpszVolumeMountPoint));
// GetVolumeNameForVolumeMountPoint
inline void GetVolumeNameForVolumeMountPoint(LPCSTR lpszVolumeMountPoint, LPSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumeNameForVolumeMountPointA(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength));
// from fileapi.h
inline void GetVolumeNameForVolumeMountPoint(LPCWSTR lpszVolumeMountPoint, LPWSTR lpszVolumeName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumeNameForVolumeMountPointW(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength));
// GetVolumePathName
inline void GetVolumePathName(LPCSTR lpszFileName, LPSTR lpszVolumePathName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumePathNameA(lpszFileName, lpszVolumePathName, cchBufferLength));
// from fileapi.h
inline void GetVolumePathName(LPCWSTR lpszFileName, LPWSTR lpszVolumePathName, DWORD cchBufferLength)
	safe_ret_as(::GetVolumePathNameW(lpszFileName, lpszVolumePathName, cchBufferLength));
// GetVolumePathNamesForVolumeName
inline void GetVolumePathNamesForVolumeName(LPCSTR lpszVolumeName, LPSTR lpszVolumePathNames, DWORD cchBufferLength,LPDWORD lpcchReturnLength)
	safe_ret_as(::GetVolumePathNamesForVolumeNameA(lpszVolumeName, lpszVolumePathNames, cchBufferLength,  lpcchReturnLength));
// from fileapi.h
inline void GetVolumePathNamesForVolumeName(LPCWSTR lpszVolumeName, LPWSTR lpszVolumePathNames, DWORD cchBufferLength,LPDWORD lpcchReturnLength)
	safe_ret_as(::GetVolumePathNamesForVolumeNameW(lpszVolumeName, lpszVolumePathNames, cchBufferLength,  lpcchReturnLength));
// CreateActCtx
inline HANDLE CreateActCtx(PCACTCTXA pActCtx)
	safe_ret_as(auto h = ::CreateActCtxA(pActCtx); h != INVALID_HANDLE_VALUE, h);
inline HANDLE CreateActCtx(PCACTCTXW pActCtx)
	safe_ret_as(auto h = ::CreateActCtxW(pActCtx); h != INVALID_HANDLE_VALUE, h);
// AddRefActCtx
// ReleaseActCtx
// ZombifyActCtx
// ActivateActCtx
// DeactivateActCtx
// GetCurrentActCtx
wapi_ret_true_WAO(FindActCtxSectionString);
// FindActCtxSectionGuid
// QueryActCtx
inline void QueryActCtx(DWORD dwFlags, HANDLE hActCtx,PVOID pvSubInstance, ULONG ulInfoClass,PVOID pvBuffer, SIZE_T cbBuffer, SIZE_T *pcbWrittenOrRequired)
	safe_ret_as(::QueryActCtxW(dwFlags, hActCtx,  pvSubInstance, ulInfoClass,  pvBuffer, cbBuffer, pcbWrittenOrRequired));
// WTSGetActiveConsoleSessionId
// GetActiveProcessorGroupCount
// GetMaximumProcessorGroupCount
// GetActiveProcessorCount
// GetMaximumProcessorCount
// GetNumaProcessorNode
// GetNumaNodeNumberFromHandle
// GetNumaProcessorNodeEx
// GetNumaNodeProcessorMask
// GetNumaAvailableMemoryNode
// GetNumaAvailableMemoryNodeEx
// GetNumaProximityNode
// RegisterApplicationRecoveryCallback
// UnregisterApplicationRecoveryCallback
// RegisterApplicationRestart
// UnregisterApplicationRestart
// GetApplicationRecoveryCallback
// GetApplicationRestartSettings
// ApplicationRecoveryInProgress
// ApplicationRecoveryFinished
// GetFileInformationByHandleEx
// GetFileInformationByName
// OpenFileById
wapi_ret_true_WAO(CreateSymbolicLink);
// QueryActCtxSettings
inline void QueryActCtxSettings(DWORD dwFlags, HANDLE hActCtx,PCWSTR settingsNameSpace, PCWSTR settingName,PWSTR pvBuffer, SIZE_T dwBuffer, SIZE_T *pdwWrittenOrRequired)
	safe_ret_as(::QueryActCtxSettingsW(dwFlags, hActCtx,  settingsNameSpace, settingName,  pvBuffer, dwBuffer, pdwWrittenOrRequired));
wapi_ret_true_WAO(CreateSymbolicLinkTransacted);
// AddSecureMemoryCacheCallback
// RemoveSecureMemoryCacheCallback
// CopyContext
// InitializeContext
// InitializeContext2
// GetEnabledXStateFeatures
// GetXStateFeaturesMask
// LocateXStateFeature
// SetXStateFeaturesMask
// GetThreadEnabledXStateFeatures
// EnableProcessOptionalXStateFeatures
// EnableThreadProfiling
// DisableThreadProfiling
// QueryThreadProfiling
// ReadThreadProfilingData
// DestroyThreadpoolEnvironment
// InitializeThreadpoolEnvironment
// InterlockedExchangeSubtract
// SetThreadpoolCallbackCleanupGroup
// SetThreadpoolCallbackLibrary
// SetThreadpoolCallbackPersistent
// SetThreadpoolCallbackPool
// SetThreadpoolCallbackPriority
// SetThreadpoolCallbackRunsLong
#pragma endregion

#pragma region WinUser.h
// wvsprintf - Deprecated
// wsprintf - Deprecated
wapi_ret_notnull_WAO(LoadKeyboardLayout);
wapi_ret_notnull(ActivateKeyboardLayout);
wapi_ret_direct(ToUnicodeEx);
wapi_ret_true(UnloadKeyboardLayout);
wapi_ret_true_WAO(GetKeyboardLayoutName);
// GetKeyboardLayoutList
inline int GetKeyboardLayoutList(int nBuff, HKL FAR *lpList)
	safe_ret_as(auto h = ::GetKeyboardLayoutList(nBuff, lpList), h);
wapi_ret_direct(GetKeyboardLayout);
// GetMouseMovePointsEx
inline int GetMouseMovePointsEx(UINT cbSize, LPMOUSEMOVEPOINT lppt, LPMOUSEMOVEPOINT lpptBuf, int nBufPoints, DWORD resolution)
	safe_ret_as(auto h = ::GetMouseMovePointsEx(cbSize, lppt, lpptBuf, nBufPoints, resolution), h);
wapi_ret_notnull_WAO(CreateDesktop);
wapi_ret_notnull_WAO(CreateDesktopEx);
wapi_ret_notnull_WAO(OpenDesktop);
wapi_ret_notnull(OpenInputDesktop);
wapi_ret_true_WAO(EnumDesktops);
wapi_ret_true(EnumDesktopWindows);
wapi_ret_true(SwitchDesktop);
wapi_ret_true(SetThreadDesktop);
wapi_ret_true(CloseDesktop);
wapi_ret_notnull(GetThreadDesktop);
wapi_ret_notnull_WAO(CreateWindowStation);
wapi_ret_notnull_WAO(OpenWindowStation);
wapi_ret_true_WAO(EnumWindowStations);
wapi_ret_true(CloseWindowStation);
wapi_ret_true(SetProcessWindowStation);
wapi_ret_notnull(GetProcessWindowStation);
wapi_ret_true(SetUserObjectSecurity);
wapi_ret_true(GetUserObjectSecurity);
wapi_ret_true_WAT(GetUserObjectInformation);
wapi_ret_true_WAT(SetUserObjectInformation);
wapi_ret_direct(IsHungAppWindow);
wapi_ret_direct(DisableProcessWindowsGhosting);
wapi_ret_positive_WAO(RegisterWindowMessage);
wapi_ret_true(TrackMouseEvent);
wapi_ret_true(DrawFrameControl);
wapi_ret_true(DrawCaption);
wapi_ret_true(DrawAnimatedRects);
// GetMessage
template<bool IsUnicode = Native::IsUnicode>
inline bool GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
	if_c (IsUnicode)
		 safe_ret_as(auto h = ::GetMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax); h >= 0, h)
	else safe_ret_as(auto h = ::GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax); h >= 0, h)
}
// TranslateMessage
inline bool TranslateMessage(CONST MSG *lpMsg)
	ret_as(::TranslateMessage(lpMsg));
wapi_ret_direct_WAT(DispatchMessage);
// SetMessageQueue
// PeekMessage
template<bool IsUnicode = Native::IsUnicode>
inline bool PeekMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
	if_c (IsUnicode)
		 ret_as(::PeekMessageW(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg))
	else ret_as(::PeekMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg))
}
wapi_ret_true(RegisterHotKey);
wapi_ret_true(UnregisterHotKey);
wapi_ret_true(ExitWindowsEx);
wapi_ret_direct(SwapMouseButton);
wapi_ret_direct(GetMessagePos);
wapi_ret_direct(GetMessageTime);
wapi_ret_direct(GetMessageExtraInfo);
wapi_ret_direct(GetUnpredictedMessagePos);
wapi_ret_direct(IsWow64Message);
wapi_ret_direct(SetMessageExtraInfo);
// SendMessage
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::SendMessageW(hWnd, Msg, wParam, lParam), h)
	else ret_safe_to(auto h = ::SendMessageA(hWnd, Msg, wParam, lParam), h)
}
// SendMessageTimeout
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendMessageTimeout(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::SendMessageTimeoutW(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult), h)
	else ret_safe_to(auto h = ::SendMessageTimeoutA(hWnd, Msg, wParam, lParam, fuFlags, uTimeout, lpdwResult), h)
}
wapi_ret_true_WAT(SendNotifyMessage);
wapi_ret_true_WAT(SendMessageCallback);
// BroadcastSystemMessageEx
template<bool IsUnicode = Native::IsUnicode>
inline long BroadcastSystemMessageEx(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
	if_c (IsUnicode)
		 safe_ret_as(auto h = ::BroadcastSystemMessageExW(flags, lpInfo, Msg, wParam, lParam, pbsmInfo), h)
	else safe_ret_as(auto h = ::BroadcastSystemMessageExA(flags, lpInfo, Msg, wParam, lParam, pbsmInfo), h)
}
// BroadcastSystemMessage
template<bool IsUnicode = Native::IsUnicode>
inline long BroadcastSystemMessage(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if_c (IsUnicode)
		 safe_ret_as(auto h = ::BroadcastSystemMessageW(flags, lpInfo, Msg, wParam, lParam), h)
	else safe_ret_as(auto h = ::BroadcastSystemMessageA(flags, lpInfo, Msg, wParam, lParam), h)
}
wapi_ret_notnull_WAT(RegisterDeviceNotification);
wapi_ret_true(UnregisterDeviceNotification);
wapi_ret_notnull(RegisterPowerSettingNotification);
wapi_ret_true(UnregisterPowerSettingNotification);
wapi_ret_notnull(RegisterSuspendResumeNotification);
wapi_ret_true(UnregisterSuspendResumeNotification);
wapi_ret_true_WAT(PostMessage);
wapi_ret_true_WAT(PostThreadMessage);
wapi_ret_true(AttachThreadInput);
wapi_ret_direct(ReplyMessage);
wapi_ret_true(WaitMessage);
wapi_ret_positive(WaitForInputIdle);
wapi_ret_direct_WAT(DefWindowProc);
wapi_ret_direct(PostQuitMessage);
wapi_ret_direct_WAT(CallWindowProc);
wapi_ret_direct(InSendMessage);
wapi_ret_direct(InSendMessageEx);
wapi_ret_direct(GetDoubleClickTime);
wapi_ret_true(SetDoubleClickTime);
wapi_ret_positive_WAO(RegisterClass);
wapi_ret_true_WAO(UnregisterClass);
wapi_ret_true_WAO(GetClassInfo);
wapi_ret_positive_WAO(RegisterClassEx);
wapi_ret_true_WAO(GetClassInfoEx);
wapi_ret_notnull_WAO(CreateWindowEx);
wapi_ret_direct(IsWindow);
wapi_ret_direct(IsMenu);
wapi_ret_direct(IsChild);
wapi_ret_true(DestroyWindow);
wapi_ret_direct(ShowWindow);
wapi_ret_true(AnimateWindow);
wapi_ret_true(UpdateLayeredWindow);
wapi_ret_true(UpdateLayeredWindowIndirect);
wapi_ret_true(GetLayeredWindowAttributes);
wapi_ret_direct(PrintWindow);
wapi_ret_true(SetLayeredWindowAttributes);
wapi_ret_direct(ShowWindowAsync);
wapi_ret_direct(FlashWindow);
wapi_ret_direct(FlashWindowEx);
wapi_ret_true(ShowOwnedPopups);
wapi_ret_true(OpenIcon);
wapi_ret_true(CloseWindow);
wapi_ret_true(MoveWindow);
wapi_ret_true(SetWindowPos);
wapi_ret_true(GetWindowPlacement);
wapi_ret_true(SetWindowPlacement);
wapi_ret_true(GetWindowDisplayAffinity);
wapi_ret_true(SetWindowDisplayAffinity);
wapi_ret_notnull(BeginDeferWindowPos);
wapi_ret_notnull(DeferWindowPos);
wapi_ret_true(EndDeferWindowPos);
wapi_ret_direct(IsWindowVisible);
wapi_ret_direct(IsIconic);
wapi_ret_direct(AnyPopup);
wapi_ret_true(BringWindowToTop);
wapi_ret_direct(IsZoomed);
wapi_ret_notnull_WAO(CreateDialogParam);
wapi_ret_notnull_WAT(CreateDialogIndirectParam);
#undef DialogBoxParam
inline INT_PTR DialogBoxParam(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
	ret_safe_to(auto h = ::DialogBoxParamA(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam), h);
inline INT_PTR DialogBoxParam(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
	ret_safe_to(auto h = ::DialogBoxParamW(hInstance, lpTemplateName, hWndParent, lpDialogFunc, dwInitParam), h);
#undef DialogBoxIndirectParam
template<bool IsUnicode = Native::IsUnicode>
inline INT_PTR DialogBoxIndirectParam(HINSTANCE hInstance, LPCDLGTEMPLATE hDialogTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::DialogBoxIndirectParamW(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam), h)
	else ret_safe_to(auto h = ::DialogBoxIndirectParamA(hInstance, hDialogTemplate, hWndParent, lpDialogFunc, dwInitParam), h)
}
wapi_ret_true(EndDialog);
wapi_ret_notnull(GetDlgItem);
wapi_ret_true(SetDlgItemInt);
// GetDlgItemInt
inline UINT GetDlgItemInt(HWND hDlg, int nIDDlgItem, BOOL *lpTranslated, BOOL bSigned)
	safe_ret_as(auto h = ::GetDlgItemInt(hDlg, nIDDlgItem, lpTranslated, bSigned); h != !*lpTranslated, h);
wapi_ret_true_WAO(SetDlgItemText);
wapi_ret_positive_WAO(GetDlgItemText);
wapi_ret_true(CheckDlgButton);
wapi_ret_true(CheckRadioButton);
wapi_ret_direct(IsDlgButtonChecked);
// SendDlgItemMessage
template<bool IsUnicode = Native::IsUnicode>
inline LRESULT SendDlgItemMessage(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::SendDlgItemMessageW(hDlg, nIDDlgItem, Msg, wParam, lParam), h)
	else ret_safe_to(auto h = ::SendDlgItemMessageA(hDlg, nIDDlgItem, Msg, wParam, lParam), h)
}
wapi_ret_notnull(GetNextDlgGroupItem);
wapi_ret_notnull(GetNextDlgTabItem);
// GetDlgCtrlID
inline int GetDlgCtrlID(HWND hWnd)
	safe_ret_as(auto h = ::GetDlgCtrlID(hWnd), h);
wapi_ret_direct(GetDialogBaseUnits);
wapi_ret_direct_WAT(DefDlgProc);
wapi_ret_true(SetDialogControlDpiChangeBehavior);
// GetDialogControlDpiChangeBehavior
inline DIALOG_CONTROL_DPI_CHANGE_BEHAVIORS GetDialogControlDpiChangeBehavior(HWND hWnd)
	safe_ret_as(auto h = ::GetDialogControlDpiChangeBehavior(hWnd), h);
wapi_ret_true(SetDialogDpiChangeBehavior);
// GetDialogDpiChangeBehavior
inline DIALOG_DPI_CHANGE_BEHAVIORS GetDialogDpiChangeBehavior(HWND hDlg)
	safe_ret_as(auto h = ::GetDialogDpiChangeBehavior(hDlg), h);
wapi_ret_direct_WAT(CallMsgFilter);
wapi_ret_true(OpenClipboard);
wapi_ret_true(CloseClipboard);
wapi_ret_direct(GetClipboardSequenceNumber);
wapi_ret_notnull(GetClipboardOwner);
wapi_ret_notnull(SetClipboardViewer);
wapi_ret_notnull(GetClipboardViewer);
wapi_ret_direct(ChangeClipboardChain);
wapi_ret_notnull(SetClipboardData);
wapi_ret_notnull(GetClipboardData);
// GetClipboardMetadata
wapi_ret_direct_WAO(RegisterClipboardFormat);
// CountClipboardFormats
inline int CountClipboardFormats()
	safe_ret_as(auto h = ::CountClipboardFormats(), h);
wapi_ret_positive(EnumClipboardFormats);
// GetClipboardFormatName
inline int GetClipboardFormatName(UINT format, LPSTR lpszFormatName, int cchMaxCount)
	safe_ret_as(auto h = ::GetClipboardFormatNameA(format, lpszFormatName, cchMaxCount), h);
inline int GetClipboardFormatName(UINT format, LPWSTR lpszFormatName, int cchMaxCount)
	safe_ret_as(auto h = ::GetClipboardFormatNameW(format, lpszFormatName, cchMaxCount), h);
wapi_ret_true(EmptyClipboard);
wapi_ret_direct(IsClipboardFormatAvailable);
// GetPriorityClipboardFormat
inline int GetPriorityClipboardFormat(UINT *paFormatPriorityList, int cFormats)
	safe_ret_as(auto h = ::GetPriorityClipboardFormat(paFormatPriorityList, cFormats), h);
inline HWND GetOpenClipboardWindow()
	safe_ret_as(auto h = ::GetOpenClipboardWindow(), h);
wapi_ret_true(AddClipboardFormatListener);
wapi_ret_true(RemoveClipboardFormatListener);
wapi_ret_true(GetUpdatedClipboardFormats);
// CharToOem - Deprecated
// OemToChar - Deprecated
// CharToOemBuff - Deprecated
// OemToCharBuff - Deprecated
// CharUpper - Deprecated
// CharUpperBuff - Deprecated
// CharLower - Deprecated
// CharLowerBuff - Deprecated
// CharNext - Deprecated
// CharPrev - Deprecated
// CharNextExA
// CharPrevExA
// IsCharAlpha - Deprecated
// IsCharAlphaNumeric - Deprecated
// IsCharUpper - Deprecated
// IsCharLower - Deprecated
wapi_ret_notnull(SetFocus);
wapi_ret_direct(GetActiveWindow);
wapi_ret_direct(GetFocus);
wapi_ret_direct(GetKBCodePage);
wapi_ret_direct(GetKeyState);
wapi_ret_direct(GetAsyncKeyState);
wapi_ret_true(GetKeyboardState);
wapi_ret_true(SetKeyboardState);
// GetKeyNameText
inline int GetKeyNameText(LONG lParam, LPSTR lpString, int cchSize)
	safe_ret_as(auto h = ::GetKeyNameTextA(lParam, lpString, cchSize), h);
inline int GetKeyNameText(LONG lParam, LPWSTR lpString, int cchSize)
	safe_ret_as(auto h = ::GetKeyNameTextW(lParam, lpString, cchSize), h);
// GetKeyboardType
inline int GetKeyboardType(int nTypeFlag)
	ret_safe_to(auto h = ::GetKeyboardType(nTypeFlag), h);
wapi_ret_direct(ToAscii);
wapi_ret_direct(ToAsciiEx);
wapi_ret_direct(ToUnicode);
wapi_ret_direct(OemKeyScan);
// VkKeyScan
inline SHORT VkKeyScan(CHAR ch)
	ret_as(::VkKeyScanA(ch));
inline SHORT VkKeyScan(WCHAR ch)
	ret_as(::VkKeyScanW(ch));
// VkKeyScanEx
inline SHORT VkKeyScanEx(CHAR ch, HKL dwhkl)
	ret_as(::VkKeyScanExA(ch, dwhkl));
inline SHORT VkKeyScanEx(WCHAR ch, HKL dwhkl)
	ret_as(::VkKeyScanExW(ch, dwhkl));
// keybd_event
// mouse_event
wapi_ret_positive(SendInput);
wapi_ret_true(GetTouchInputInfo);
wapi_ret_true(CloseTouchInputHandle);
wapi_ret_true(RegisterTouchWindow);
wapi_ret_true(UnregisterTouchWindow);
wapi_ret_direct(IsTouchWindow);
wapi_ret_true(InitializeTouchInjection);
wapi_ret_true(InjectTouchInput);
wapi_ret_true(GetPointerType);
wapi_ret_true(GetPointerCursorId);
wapi_ret_true(GetPointerInfo);
wapi_ret_true(GetPointerInfoHistory);
wapi_ret_true(GetPointerFrameInfo);
wapi_ret_true(GetPointerFrameInfoHistory);
wapi_ret_true(GetPointerTouchInfo);
wapi_ret_true(GetPointerTouchInfoHistory);
wapi_ret_true(GetPointerFrameTouchInfo);
wapi_ret_true(GetPointerFrameTouchInfoHistory);
wapi_ret_true(GetPointerPenInfo);
wapi_ret_true(GetPointerPenInfoHistory);
wapi_ret_true(GetPointerFramePenInfo);
wapi_ret_true(GetPointerFramePenInfoHistory);
wapi_ret_true(SkipPointerFrameMessages);
wapi_ret_true(RegisterPointerInputTarget);
wapi_ret_true(UnregisterPointerInputTarget);
// RegisterPointerInputTargetEx
// UnregisterPointerInputTargetEx
#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
wapi_ret_notnull(CreateSyntheticPointerDevice);
wapi_ret_true(InjectSyntheticPointerInput);
wapi_ret_direct(DestroySyntheticPointerDevice);
#endif
wapi_ret_true(EnableMouseInPointer);
wapi_ret_direct(IsMouseInPointerEnabled);
// EnableMouseInPointerForThread
wapi_ret_true(RegisterTouchHitTestingWindow);
wapi_ret_true(EvaluateProximityToRect);
wapi_ret_true(EvaluateProximityToPolygon);
// PackTouchHitTestingProximityEvaluation
inline LRESULT PackTouchHitTestingProximityEvaluation(const TOUCH_HIT_TESTING_INPUT *pHitTestingInput, const TOUCH_HIT_TESTING_PROXIMITY_EVALUATION *pProximityEval)
	ret_safe_to(auto h = ::PackTouchHitTestingProximityEvaluation(pHitTestingInput, pProximityEval), h);
wapi_ret_true(GetWindowFeedbackSetting);
wapi_ret_true(SetWindowFeedbackSetting);
// GetPointerInputTransform - Deprecated
//inline void GetPointerInputTransform(UINT32 pointerId, UINT32 historyCount, INPUT_TRANSFORM *inputTransform)
//	safe_ret_as(::GetPointerInputTransform(pointerId, historyCount, inputTransform));
wapi_ret_true(GetLastInputInfo);
wapi_ret_direct_WAT(MapVirtualKey);
wapi_ret_direct_WAT(MapVirtualKeyEx);
wapi_ret_direct(GetInputState);
wapi_ret_direct(GetQueueStatus);
wapi_ret_direct(GetCapture);
wapi_ret_direct(SetCapture);
wapi_ret_true(ReleaseCapture);
// MsgWaitForMultipleObjects
inline DWORD MsgWaitForMultipleObjects(DWORD nCount, CONST HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask)
	safe_ret_as(auto h = ::MsgWaitForMultipleObjects(nCount, pHandles, fWaitAll, dwMilliseconds, dwWakeMask), h);
// MsgWaitForMultipleObjectsEx
inline DWORD MsgWaitForMultipleObjectsEx(DWORD nCount, CONST HANDLE *pHandles, DWORD dwMilliseconds, DWORD dwWakeMask, DWORD dwFlags)
	safe_ret_as(auto h = ::MsgWaitForMultipleObjectsEx(nCount, pHandles, dwMilliseconds, dwWakeMask, dwFlags), h);
// SetTimer
inline UINT_PTR SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc)
	safe_ret_as(auto h = ::SetTimer(hWnd, nIDEvent, uElapse, lpTimerFunc), h);
// SetCoalescableTimer
inline UINT_PTR SetCoalescableTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc, ULONG uToleranceDelay)
	safe_ret_as(auto h = ::SetCoalescableTimer(hWnd, nIDEvent, uElapse, lpTimerFunc, uToleranceDelay), h);
wapi_ret_true(KillTimer);
wapi_ret_direct(IsWindowUnicode);
wapi_ret_direct(EnableWindow);
wapi_ret_direct(IsWindowEnabled);
wapi_ret_notnull_WAO(LoadAccelerators);
wapi_ret_notnull_WAT(CreateAcceleratorTable);
wapi_ret_true(DestroyAcceleratorTable);
wapi_ret_direct_WAT(CopyAcceleratorTable);
// TranslateAccelerator
template<bool IsUnicode = Native::IsUnicode>
inline int TranslateAccelerator(HWND hWnd, HACCEL hAccTable, LPMSG lpMsg) {
	if_c (IsUnicode)
		 safe_ret_as(auto h = ::TranslateAcceleratorW(hWnd, hAccTable, lpMsg), h)
	else safe_ret_as(auto h = ::TranslateAcceleratorA(hWnd, hAccTable, lpMsg), h)
}
// GetSystemMetrics
inline int GetSystemMetrics(int nIndex)
	safe_ret_as(auto h = ::GetSystemMetrics(nIndex), h);
// GetSystemMetricsForDpi
inline int GetSystemMetricsForDpi(int nIndex, UINT dpi)
	safe_ret_as(auto h = ::GetSystemMetricsForDpi(nIndex, dpi), h);
wapi_ret_notnull_WAO(LoadMenu);
wapi_ret_notnull_WAT(LoadMenuIndirect);
wapi_ret_direct(GetMenu);
wapi_ret_true(SetMenu);
// ChangeMenu - Undocumented
wapi_ret_direct(HiliteMenuItem);
// GetMenuString
inline int GetMenuString(HMENU hMenu, UINT uIDItem, LPSTR lpString, int cchMax, UINT flags)
	safe_ret_as(auto h = ::GetMenuStringA(hMenu, uIDItem, lpString, cchMax, flags), h);
inline int GetMenuString(HMENU hMenu, UINT uIDItem, LPWSTR lpString, int cchMax, UINT flags)
	safe_ret_as(auto h = ::GetMenuStringW(hMenu, uIDItem, lpString, cchMax, flags), h);
wapi_ret_direct(GetMenuState);
wapi_ret_true(DrawMenuBar);
wapi_ret_direct(GetSystemMenu);
wapi_ret_notnull(CreateMenu);
wapi_ret_notnull(CreatePopupMenu);
wapi_ret_true(DestroyMenu);
// CheckMenuItem
inline DWORD CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck)
	safe_ret_as(auto h = ::CheckMenuItem(hMenu, uIDCheckItem, uCheck), h);
wapi_ret_true(EnableMenuItem);
wapi_ret_direct(GetSubMenu);
wapi_ret_direct(GetMenuItemID);
// GetMenuItemCount
inline int GetMenuItemCount(HMENU hMenu)
	safe_ret_as(auto h = ::GetMenuItemCount(hMenu), h);
wapi_ret_true_WAO(InsertMenu);
wapi_ret_true_WAO(AppendMenu);
wapi_ret_true_WAO(ModifyMenu);
wapi_ret_true(RemoveMenu);
wapi_ret_true(DeleteMenu);
wapi_ret_true(SetMenuItemBitmaps);
wapi_ret_direct(GetMenuCheckMarkDimensions);
wapi_ret_true(TrackPopupMenu);
wapi_ret_true(TrackPopupMenuEx);
wapi_ret_true(CalculatePopupWindowPosition);
wapi_ret_true(GetMenuInfo);
wapi_ret_true(SetMenuInfo);
wapi_ret_true(EndMenu);
wapi_ret_true_WAO(InsertMenuItem);
wapi_ret_true_WAO(GetMenuItemInfo);
wapi_ret_true_WAO(SetMenuItemInfo);
// GetMenuDefaultItem
inline UINT GetMenuDefaultItem(HMENU hMenu, UINT fByPos, UINT gmdiFlags)
	safe_ret_as(auto h = ::GetMenuDefaultItem(hMenu, fByPos, gmdiFlags); h != -1, h);
wapi_ret_true(SetMenuDefaultItem);
wapi_ret_true(GetMenuItemRect);
wapi_ret_direct(MenuItemFromPoint);
// DragObject
wapi_ret_direct(DragDetect);
wapi_ret_true(UpdateWindow);
inline HWND SetActiveWindow(HWND hWnd)
	safe_ret_as(auto h = ::SetActiveWindow(hWnd), h);
wapi_ret_direct(GetForegroundWindow);
inline void SwitchToThisWindow(HWND hwnd, BOOL fUnknown)
	ret_as(::SwitchToThisWindow(hwnd, fUnknown));
wapi_ret_true(SetForegroundWindow);
wapi_ret_true(AllowSetForegroundWindow);
wapi_ret_true(LockSetForegroundWindow);
wapi_ret_notnull(GetDC);
wapi_ret_notnull(GetDCEx);
wapi_ret_notnull(GetWindowDC);
// ReleaseDC
inline int ReleaseDC(HWND hWnd, HDC hDC)
	safe_ret_as(auto h = ::ReleaseDC(hWnd, hDC), h);
wapi_ret_notnull(BeginPaint);
wapi_ret_true(EndPaint);
wapi_ret_direct(GetUpdateRect);
// GetUpdateRgn
inline int GetUpdateRgn(HWND hWnd, HRGN hRgn, BOOL bErase)
	safe_ret_as(auto h = ::GetUpdateRgn(hWnd, hRgn, bErase), h);
// SetWindowRgn
inline int SetWindowRgn(HWND hWnd, HRGN hRgn, BOOL bRedraw)
	safe_ret_as(auto h = ::SetWindowRgn(hWnd, hRgn, bRedraw), h);
// GetWindowRgn
inline int GetWindowRgn(HWND hWnd, HRGN hRgn)
	safe_ret_as(auto h = ::GetWindowRgn(hWnd, hRgn), h);
// GetWindowRgnBox
inline int GetWindowRgnBox(HWND hWnd, LPRECT lprc)
	safe_ret_as(auto h = ::GetWindowRgnBox(hWnd, lprc), h);
wapi_ret_true(InvalidateRect);
wapi_ret_true(ValidateRect);
wapi_ret_true(InvalidateRgn);
wapi_ret_true(ValidateRgn);
wapi_ret_true(RedrawWindow);
wapi_ret_true(LockWindowUpdate);
wapi_ret_true(ScrollWindow);
// ScrollWindowEx
inline int ScrollWindowEx(HWND hWnd, int dx, int dy, CONST RECT *prcScroll, CONST RECT *prcClip, HRGN hrgnUpdate, LPRECT prcUpdate, UINT flags)
	safe_ret_as(auto h = ::ScrollWindowEx(hWnd, dx, dy, prcScroll, prcClip, hrgnUpdate, prcUpdate, flags), h);
// SetScrollPos
inline int SetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw)
	safe_ret_as(auto h = ::SetScrollPos(hWnd, nBar, nPos, bRedraw), h);
// GetScrollPos
inline int GetScrollPos(HWND hWnd, int nBar)
	safe_ret_as(auto h = ::GetScrollPos(hWnd, nBar), h);
wapi_ret_true(SetScrollRange);
wapi_ret_true(GetScrollRange);
wapi_ret_true(ShowScrollBar);
wapi_ret_true(EnableScrollBar);
wapi_ret_true_WAO(SetProp);
wapi_ret_direct_WAO(GetProp);
// RemoveProp
inline HANDLE RemoveProp(HWND hWnd, LPCSTR lpString)
	ret_safe_to(auto h = ::RemovePropA(hWnd, lpString), h);
inline HANDLE RemoveProp(HWND hWnd, LPCWSTR lpString)
	ret_safe_to(auto h = ::RemovePropW(hWnd, lpString), h);
// EnumPropsEx
inline int EnumPropsEx(HWND hWnd, PROPENUMPROCEXA lpEnumFunc, LPARAM lParam)
	safe_ret_as(auto h = ::EnumPropsExA(hWnd, lpEnumFunc, lParam), h);
inline int EnumPropsEx(HWND hWnd, PROPENUMPROCEXW lpEnumFunc, LPARAM lParam)
	safe_ret_as(auto h = ::EnumPropsExW(hWnd, lpEnumFunc, lParam), h);
// EnumProps
inline int EnumProps(HWND hWnd, PROPENUMPROCA lpEnumFunc)
	safe_ret_as(auto h = ::EnumPropsA(hWnd, lpEnumFunc), h);
inline int EnumProps(HWND hWnd, PROPENUMPROCW lpEnumFunc)
	safe_ret_as(auto h = ::EnumPropsW(hWnd, lpEnumFunc), h);
wapi_ret_true_WAO(SetWindowText);
// GetWindowText
inline int GetWindowText(HWND hWnd, LPSTR lpString, int nMaxCount)
	ret_safe_to(auto h = ::GetWindowTextA(hWnd, lpString, nMaxCount), h);
inline int GetWindowText(HWND hWnd, LPWSTR lpString, int nMaxCount)
	ret_safe_to(auto h = ::GetWindowTextW(hWnd, lpString, nMaxCount), h);
// GetWindowTextLength
template<bool IsUnicode = Native::IsUnicode>
inline int GetWindowTextLength(HWND hWnd) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::GetWindowTextLengthW(hWnd), h)
	else ret_safe_to(auto h = ::GetWindowTextLengthA(hWnd), h)
}
wapi_ret_true(GetClientRect);
wapi_ret_true(GetWindowRect);
wapi_ret_true(AdjustWindowRect);
wapi_ret_true(AdjustWindowRectEx);
wapi_ret_true(AdjustWindowRectExForDpi);
wapi_ret_true(SetWindowContextHelpId);
wapi_ret_direct(GetWindowContextHelpId);
wapi_ret_true(SetMenuContextHelpId);
wapi_ret_direct(GetMenuContextHelpId);
wapi_ret_notzero_WAO(MessageBox);
wapi_ret_notzero_WAO(MessageBoxEx);
wapi_ret_notzero_WAO(MessageBoxIndirect);
wapi_ret_true(MessageBeep);
wapi_ret_direct(ShowCursor);
wapi_ret_true(SetCursorPos);
wapi_ret_true(SetPhysicalCursorPos);
wapi_ret_direct(SetCursor);
wapi_ret_true(GetCursorPos);
wapi_ret_true(GetPhysicalCursorPos);
wapi_ret_true(GetClipCursor);
wapi_ret_direct(GetCursor);
wapi_ret_true(CreateCaret);
// GetCaretBlinkTime
inline UINT GetCaretBlinkTime()
	safe_ret_as(auto h = ::GetCaretBlinkTime(), h);
wapi_ret_true(SetCaretBlinkTime);
wapi_ret_true(DestroyCaret);
wapi_ret_true(HideCaret);
wapi_ret_true(ShowCaret);
wapi_ret_true(SetCaretPos);
wapi_ret_true(GetCaretPos);
wapi_ret_true(ClientToScreen);
wapi_ret_true(ScreenToClient);
wapi_ret_true(LogicalToPhysicalPoint);
wapi_ret_true(PhysicalToLogicalPoint);
wapi_ret_true(LogicalToPhysicalPointForPerMonitorDPI);
wapi_ret_true(PhysicalToLogicalPointForPerMonitorDPI);
// MapWindowPoints
inline int MapWindowPoints(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoints, UINT cPoints)
	ret_safe_to(auto h = ::MapWindowPoints(hWndFrom, hWndTo, lpPoints, cPoints), h);
wapi_ret_direct(WindowFromPoint);
wapi_ret_direct(WindowFromPhysicalPoint);
wapi_ret_direct(ChildWindowFromPoint);
wapi_ret_true(ClipCursor);
wapi_ret_direct(ChildWindowFromPointEx);
wapi_ret_direct(GetSysColor);
wapi_ret_direct(GetSysColorBrush);
wapi_ret_true(SetSysColors);
// SetRect
// SetRectEmpty
// CopyRect
// InflateRect
// IntersectRect
// UnionRect
// SubtractRect
// OffsetRect
// IsRectEmpty
// EqualRect
// PtInRect
// GetWindowWord
inline WORD GetWindowWord(HWND hWnd, int nIndex)
	ret_safe_to(auto h = ::GetWindowWord(hWnd, nIndex), h);
// SetWindowWord
inline WORD SetWindowWord(HWND hWnd, int nIndex, WORD wNewWord)
	ret_safe_to(auto h = ::SetWindowWord(hWnd, nIndex, wNewWord), h);
// GetWindowLong - Deprecated
// SetWindowLong - Deprecated
// GetWindowLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline LONG_PTR GetWindowLongPtr(HWND hWnd, int nIndex) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::GetWindowLongPtrW(hWnd, nIndex), h)
	else ret_safe_to(auto h = ::GetWindowLongPtrA(hWnd, nIndex), h)
}
// SetWindowLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline LONG_PTR SetWindowLongPtr(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::SetWindowLongPtrW(hWnd, nIndex, dwNewLong), h)
	else ret_safe_to(auto h = ::SetWindowLongPtrA(hWnd, nIndex, dwNewLong), h)
}
// GetClassWord
inline WORD GetClassWord(HWND hWnd, int nIndex)
	ret_safe_to(auto h = ::GetClassWord(hWnd, nIndex), h);
// SetClassWord
inline WORD SetClassWord(HWND hWnd, int nIndex, WORD wNewWord)
	ret_safe_to(auto h = ::SetClassWord(hWnd, nIndex, wNewWord), h);
// GetClassLong - Deprecated
// SetClassLong - Deprecated
// GetClassLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline ULONG_PTR GetClassLongPtr(HWND hWnd, int nIndex) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::GetClassLongPtrW(hWnd, nIndex), h)
	else ret_safe_to(auto h = ::GetClassLongPtrA(hWnd, nIndex), h)
}
// SetClassLongPtr
template<bool IsUnicode = Native::IsUnicode>
inline ULONG_PTR SetClassLongPtr(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
	if_c (IsUnicode)
		 ret_safe_to(auto h = ::SetClassLongPtrW(hWnd, nIndex, dwNewLong), h)
	else ret_safe_to(auto h = ::SetClassLongPtrA(hWnd, nIndex, dwNewLong), h)
}
wapi_ret_true(GetProcessDefaultLayout);
wapi_ret_true(SetProcessDefaultLayout);
wapi_ret_direct(GetDesktopWindow);
// GetParent
inline HWND GetParent(HWND hWnd)
	ret_safe_to(auto h = ::GetParent(hWnd), h);
// SetParent
inline HWND SetParent(HWND hWndChild, HWND hWndNewParent)
	ret_safe_to(auto h = ::SetParent(hWndChild, hWndNewParent), h);
wapi_ret_direct(EnumChildWindows);
wapi_ret_direct_WAO(FindWindow);
wapi_ret_notnull_WAO(FindWindowEx);
wapi_ret_direct(GetShellWindow);
wapi_ret_true(RegisterShellHookWindow);
wapi_ret_true(DeregisterShellHookWindow);
wapi_ret_true(EnumWindows);
wapi_ret_direct(EnumThreadWindows);
// GetClassName
inline int GetClassName(HWND hWnd, LPSTR lpClassName, int nMaxCount)
	safe_ret_as(auto h = ::GetClassNameA(hWnd, lpClassName, nMaxCount), h);
inline int GetClassName(HWND hWnd, LPWSTR lpClassName, int nMaxCount)
	safe_ret_as(auto h = ::GetClassNameW(hWnd, lpClassName, nMaxCount), h);
inline HWND GetTopWindow(HWND hWnd)
	ret_safe_to(auto h = ::GetTopWindow(hWnd), h);
wapi_ret_direct(IsGUIThread);
wapi_ret_direct(GetLastActivePopup);
inline HWND GetWindow(HWND hWnd, UINT uCmd)
	ret_safe_to(auto h = ::GetWindow(hWnd, uCmd), h);
// SetWindowsHook - Undocumented
// UnhookWindowsHook
wapi_ret_notnull_WAT(SetWindowsHookEx);
wapi_ret_true(UnhookWindowsHookEx);
wapi_ret_direct(CallNextHookEx);
wapi_ret_true(CheckMenuRadioItem);
wapi_ret_notnull_WAO(LoadBitmap);
wapi_ret_notnull_WAO(LoadCursor);
wapi_ret_notnull_WAO(LoadCursorFromFile);
wapi_ret_notnull(CreateCursor);
wapi_ret_true(DestroyCursor);
wapi_ret_true(SetSystemCursor);
wapi_ret_notnull_WAO(LoadIcon);
// PrivateExtractIcons
inline UINT PrivateExtractIcons(LPCSTR szFileName, int nIconIndex, int cxIcon, int cyIcon, HICON *phicon, UINT *piconid, UINT nIcons, UINT flags)
	safe_ret_as(auto h = ::PrivateExtractIconsA(szFileName, nIconIndex, cxIcon, cyIcon, phicon, piconid, nIcons, flags); h != -1, h);
inline UINT PrivateExtractIcons(LPCWSTR szFileName, int nIconIndex, int cxIcon, int cyIcon, HICON *phicon, UINT *piconid, UINT nIcons, UINT flags)
	safe_ret_as(auto h = ::PrivateExtractIconsW(szFileName, nIconIndex, cxIcon, cyIcon, phicon, piconid, nIcons, flags); h != -1, h);
wapi_ret_notnull(CreateIcon);
wapi_ret_true(DestroyIcon);
// LookupIconIdFromDirectory
inline int LookupIconIdFromDirectory(PBYTE presbits, BOOL fIcon)
	safe_ret_as(auto h = ::LookupIconIdFromDirectory(presbits, fIcon), h);
// LookupIconIdFromDirectoryEx
inline int LookupIconIdFromDirectoryEx(PBYTE presbits, BOOL fIcon, int cxDesired, int cyDesired, UINT Flags)
	safe_ret_as(auto h = ::LookupIconIdFromDirectoryEx(presbits, fIcon, cxDesired, cyDesired, Flags), h);
wapi_ret_notnull(CreateIconFromResource);
wapi_ret_notnull(CreateIconFromResourceEx);
#if (NTDDI_VERSION >= NTDDI_WIN10_CO) && !__GNUC__
wapi_ret_direct(SetThreadCursorCreationScaling);
#endif
wapi_ret_notnull_WAO(LoadImage);
//// CopyImage
//inline HANDLE CopyImage(HANDLE h, UINT type, int cx, int cy, UINT flags)
//	safe_ret_as(auto h = ::CopyImage(h, type, cx, cy, flags), h);
wapi_ret_notnull(CreateIconIndirect);
wapi_ret_notnull(CopyIcon);
wapi_ret_true(GetIconInfo);
wapi_ret_true_WAO(GetIconInfoEx);
wapi_ret_direct_WAT(IsDialogMessage);
wapi_ret_true(MapDialogRect);
// DlgDirList
inline int DlgDirList(HWND hDlg, LPSTR lpPathSpec, int nIDListBox, int nIDStaticPath, UINT uFileType)
	safe_ret_as(auto h = ::DlgDirListA(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType), h);
inline int DlgDirList(HWND hDlg, LPWSTR lpPathSpec, int nIDListBox, int nIDStaticPath, UINT uFileType)
	safe_ret_as(auto h = ::DlgDirListW(hDlg, lpPathSpec, nIDListBox, nIDStaticPath, uFileType), h);
wapi_ret_true_WAO(DlgDirSelectEx);
// DlgDirListComboBox
inline int DlgDirListComboBox(HWND hDlg, LPSTR lpPathSpec, int nIDComboBox, int nIDStaticPath, UINT uFiletype)
	safe_ret_as(auto h = ::DlgDirListComboBoxA(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype), h);
inline int DlgDirListComboBox(HWND hDlg, LPWSTR lpPathSpec, int nIDComboBox, int nIDStaticPath, UINT uFiletype)
	safe_ret_as(auto h = ::DlgDirListComboBoxW(hDlg, lpPathSpec, nIDComboBox, nIDStaticPath, uFiletype), h);
wapi_ret_true_WAO(DlgDirSelectComboBoxEx);
wapi_ret_direct(SetScrollInfo);
wapi_ret_true(GetScrollInfo);
wapi_ret_direct_WAT(DefFrameProc);
wapi_ret_direct_WAT(DefMDIChildProc);
wapi_ret_direct(TranslateMDISysAccel);
wapi_ret_positive(ArrangeIconicWindows);
wapi_ret_notnull_WAO(CreateMDIWindow);
wapi_ret_positive(TileWindows);
wapi_ret_positive(CascadeWindows);
wapi_ret_true_WAO(WinHelp);
wapi_ret_positive(GetGuiResources);
wapi_ret_direct_WAO(ChangeDisplaySettings);
wapi_ret_direct_WAO(ChangeDisplaySettingsEx);
wapi_ret_true_WAO(EnumDisplaySettings);
wapi_ret_true_WAO(EnumDisplaySettingsEx);
wapi_ret_true_WAO(EnumDisplayDevices);
wapi_ret_direct(GetDisplayConfigBufferSizes);
wapi_ret_direct(SetDisplayConfig);
wapi_ret_direct(QueryDisplayConfig);
wapi_ret_direct(DisplayConfigGetDeviceInfo);
wapi_ret_direct(DisplayConfigSetDeviceInfo);
wapi_ret_true_WAT(SystemParametersInfo);
wapi_ret_true(SystemParametersInfoForDpi);
wapi_ret_true(SoundSentry);
// SetDebugErrorLevel
// SetLastErrorEx
// InternalGetWindowText
inline int InternalGetWindowText(HWND hWnd, LPWSTR pString, int cchMaxCount)
	ret_safe_to(auto h = ::InternalGetWindowText(hWnd, pString, cchMaxCount), h);
// EndTask
// CancelShutdown
wapi_ret_direct(MonitorFromPoint);
wapi_ret_direct(MonitorFromRect);
wapi_ret_direct(MonitorFromWindow);
wapi_ret_true_WAT(GetMonitorInfo);
wapi_ret_true(EnumDisplayMonitors);
wapi_ret_direct(NotifyWinEvent);
wapi_ret_notnull(SetWinEventHook);
wapi_ret_direct(IsWinEventHookInstalled);
wapi_ret_true(UnhookWinEvent);
wapi_ret_true(GetGUIThreadInfo);
wapi_ret_true(BlockInput);
wapi_ret_true(SetProcessDPIAware);
wapi_ret_direct(IsProcessDPIAware);
wapi_ret_notzero(SetThreadDpiAwarenessContext);
wapi_ret_notzero(GetWindowDpiAwarenessContext);
wapi_ret_notzero(GetAwarenessFromDpiAwarenessContext);
wapi_ret_direct(GetDpiFromDpiAwarenessContext);
wapi_ret_direct(AreDpiAwarenessContextsEqual);
wapi_ret_direct(IsValidDpiAwarenessContext);
wapi_ret_positive(GetDpiForWindow);
wapi_ret_direct(GetDpiForSystem);
wapi_ret_direct(GetSystemDpiForProcess);
wapi_ret_true(EnableNonClientDpiScaling);
wapi_ret_true(InheritWindowMonitor);
wapi_ret_true(SetProcessDpiAwarenessContext);
#if (NTDDI_VERSION >= NTDDI_WIN10_19H1)
wapi_ret_direct(GetDpiAwarenessContextForProcess);
#endif
wapi_ret_notzero(SetThreadDpiHostingBehavior);
wapi_ret_direct(GetThreadDpiHostingBehavior);
wapi_ret_direct(GetWindowDpiHostingBehavior);
wapi_ret_positive_WAO(GetWindowModuleFileName);
wapi_ret_true(GetCursorInfo);
wapi_ret_true(GetWindowInfo);
wapi_ret_true(GetTitleBarInfo);
wapi_ret_true(GetMenuBarInfo);
wapi_ret_true(GetScrollBarInfo);
wapi_ret_true(GetComboBoxInfo);
wapi_ret_direct(GetAncestor);
wapi_ret_direct(RealChildWindowFromPoint);
wapi_ret_positive_WAO(RealGetWindowClass);
wapi_ret_true_WAO(GetAltTabInfo);
wapi_ret_direct(GetListBoxInfo);
wapi_ret_true(LockWorkStation);
wapi_ret_true(UserHandleGrantAccess);
// GetRawInputData
inline UINT GetRawInputData(HRAWINPUT hRawInput, UINT uiCommand, LPVOID pData, PUINT pcbSize, UINT cbSizeHeader)
	safe_ret_as(auto h = ::GetRawInputData(hRawInput, uiCommand, pData, pcbSize, cbSizeHeader); h != -1, h);
// GetRawInputDeviceInfo
template<bool IsUnicode = Native::IsUnicode>
inline UINT GetRawInputDeviceInfo(HANDLE hDevice, UINT uiCommand, LPVOID pData, PUINT pcbSize) {
	if_c (IsUnicode)
		 safe_ret_as(auto h = ::GetRawInputDeviceInfoW(hDevice, uiCommand, pData, pcbSize); h != -1, h)
	else safe_ret_as(auto h = ::GetRawInputDeviceInfoA(hDevice, uiCommand, pData, pcbSize); h != -1, h)
}
// GetRawInputBuffer
inline UINT GetRawInputBuffer(PRAWINPUT pData, PUINT pcbSize, UINT cbSizeHeader)
	safe_ret_as(auto h = ::GetRawInputBuffer(pData, pcbSize, cbSizeHeader); h != -1, h);
wapi_ret_true(RegisterRawInputDevices);
// GetRegisteredRawInputDevices
inline UINT GetRegisteredRawInputDevices(PRAWINPUTDEVICE pRawInputDevices, PUINT puiNumDevices, UINT cbSize)
	safe_ret_as(auto h = ::GetRegisteredRawInputDevices(pRawInputDevices, puiNumDevices, cbSize); h != -1, h);
// GetRawInputDeviceList
inline UINT GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList, PUINT puiNumDevices, UINT cbSize)
	safe_ret_as(auto h = ::GetRawInputDeviceList(pRawInputDeviceList, puiNumDevices, cbSize); h != -1, h);
// DefRawInputProc
inline LRESULT DefRawInputProc(PRAWINPUT *paRawInput, INT nInput, UINT cbSizeHeader)
safe_ret_as(auto h = ::DefRawInputProc(paRawInput, nInput, cbSizeHeader); h >= 0, h);
wapi_ret_true(GetPointerDevices);
wapi_ret_true(GetPointerDevice);
wapi_ret_true(GetPointerDeviceProperties);
wapi_ret_true(RegisterPointerDeviceNotifications);
wapi_ret_true(GetPointerDeviceRects);
wapi_ret_true(GetPointerDeviceCursors);
wapi_ret_true(GetRawPointerDeviceData);
wapi_ret_true(ChangeWindowMessageFilter);
wapi_ret_true(ChangeWindowMessageFilterEx);
wapi_ret_true(GetGestureInfo);
wapi_ret_true(GetGestureExtraArgs);
wapi_ret_true(CloseGestureInfoHandle);
wapi_ret_true(SetGestureConfig);
wapi_ret_true(GetGestureConfig);
wapi_ret_true(ShutdownBlockReasonCreate);
wapi_ret_true(ShutdownBlockReasonQuery);
wapi_ret_true(ShutdownBlockReasonDestroy);
wapi_ret_true(GetCurrentInputMessageSource);
// GetCIMSSM
wapi_ret_true(GetAutoRotationState);
wapi_ret_true(GetDisplayAutoRotationPreferences);
wapi_ret_true(GetDisplayAutoRotationPreferencesByProcessId);
wapi_ret_true(SetDisplayAutoRotationPreferences);
// IsImmersiveProcess
inline bool IsImmersiveProcess(HANDLE hProcess)
	ret_safe_to(auto h = ::IsImmersiveProcess(hProcess), h);
wapi_ret_true(SetProcessRestrictionExemption);
// ApplyWindowAction
// SetAdditionalForegroundBoostProcesses - Deprecated
// RegisterForTooltipDismissNotification - Deprecated
// IsWindowArranged - Deprecated
// GetCurrentMonitorTopologyId
// RegisterCloakedNotification
#pragma endregion

}
