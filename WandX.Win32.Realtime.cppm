module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Realtime.h"

export module WandX.Realtime;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Realtime");

export namespace WandX {
namespace Native {

#pragma region ProcessThreadsApi.h
wapi_ret_true(QueueUserAPC);
#if (NTDDI_VERSION >= NTDDI_WIN10_MN)
wapi_ret_true(QueueUserAPC2);
#endif
wapi_ret_true(GetProcessTimes);
wapi_ret_direct(GetCurrentProcess);
wapi_ret_direct(GetCurrentProcessId);
wapi_ret_direct(ExitProcess); // noreturn
wapi_ret_true(TerminateProcess);
wapi_ret_true(GetExitCodeProcess);
wapi_ret_true(SwitchToThread);
wapi_ret_notnull(CreateThread);
wapi_ret_notnull(CreateRemoteThread);
wapi_ret_direct(GetCurrentThread);
wapi_ret_direct(GetCurrentThreadId);
wapi_ret_notnull(OpenThread);
wapi_ret_true(SetThreadPriority);
wapi_ret_true(SetThreadPriorityBoost);
wapi_ret_true(GetThreadPriorityBoost);
inline int GetThreadPriority(HANDLE hThread)
safe_ret_as(auto res = ::GetThreadPriority(hThread); res != THREAD_PRIORITY_ERROR_RETURN, res);
wapi_ret_direct(ExitThread); // noreturn
wapi_ret_true(TerminateThread);
wapi_ret_true(GetExitCodeThread);
// SuspendThread
inline DWORD SuspendThread(HANDLE hThread)
safe_ret_as(auto res = ::SuspendThread(hThread); res >= 0, res);
// ResumeThread
inline DWORD ResumeThread(HANDLE hThread)
safe_ret_as(auto res = ::ResumeThread(hThread); res >= 0, res);
// TlsAlloc
inline DWORD TlsAlloc()
safe_ret_as(auto n = ::TlsAlloc(); n != TLS_OUT_OF_INDEXES, n);
wapi_ret_notnull(TlsGetValue);
wapi_ret_true(TlsSetValue);
wapi_ret_true(TlsFree);
wapi_ret_true_WAO(CreateProcess);
wapi_ret_direct_WAT(GetStartupInfo); // GetStartupInfoA from WinBase.h
wapi_ret_true(SetProcessShutdownParameters);
wapi_ret_notzero(GetProcessVersion);
wapi_ret_true_WAO(CreateProcessAsUser);
wapi_ret_direct(GetCurrentProcessToken);
wapi_ret_direct(GetCurrentThreadToken);
wapi_ret_direct(GetCurrentThreadEffectiveToken);
wapi_ret_true(SetThreadToken);
wapi_ret_true(OpenProcessToken);
wapi_ret_true(OpenThreadToken);
wapi_ret_true(SetPriorityClass);
wapi_ret_notzero(GetPriorityClass);
wapi_ret_true(SetThreadStackGuarantee);
wapi_ret_true(ProcessIdToSessionId);
wapi_ret_notzero(GetProcessId);
wapi_ret_notzero(GetThreadId);
wapi_ret_direct(FlushProcessWriteBuffers);
wapi_ret_notzero(GetProcessIdOfThread);
wapi_ret_true(InitializeProcThreadAttributeList);
wapi_ret_direct(DeleteProcThreadAttributeList);
wapi_ret_true(UpdateProcThreadAttribute);
#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
wapi_ret_true(SetProcessDynamicEHContinuationTargets);
#endif
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
wapi_ret_true(SetProcessDynamicEnforcedCetCompatibleRanges);
#endif
wapi_ret_true(SetProcessAffinityUpdateMode);
wapi_ret_true(QueryProcessAffinityUpdateMode);
wapi_ret_notnull(CreateRemoteThreadEx);
wapi_ret_direct(GetCurrentThreadStackLimits);
wapi_ret_true(GetThreadContext);
wapi_ret_true(GetProcessMitigationPolicy);
wapi_ret_true(SetThreadContext);
wapi_ret_true(SetProcessMitigationPolicy);
wapi_ret_true(FlushInstructionCache);
wapi_ret_true(GetThreadTimes);
wapi_ret_notnull(OpenProcess);
wapi_ret_direct(IsProcessorFeaturePresent);
wapi_ret_true(GetProcessHandleCount);
wapi_ret_direct(GetCurrentProcessorNumber);
wapi_ret_true(SetThreadIdealProcessorEx);
wapi_ret_true(GetThreadIdealProcessorEx);
wapi_ret_direct(GetCurrentProcessorNumberEx);
wapi_ret_true(GetProcessPriorityBoost);
wapi_ret_true(SetProcessPriorityBoost);
wapi_ret_true(GetThreadIOPendingFlag);
wapi_ret_true(GetSystemTimes);
wapi_ret_true(GetThreadInformation);
wapi_ret_true(SetThreadInformation);
wapi_ret_true(IsProcessCritical);
wapi_ret_true(SetProtectedPolicy);
wapi_ret_true(QueryProtectedPolicy);
// SetThreadIdealProcessor
inline DWORD SetThreadIdealProcessor(HANDLE hThread, DWORD dwIdealProcessor)
safe_ret_as(auto res = ::SetThreadIdealProcessor(hThread, dwIdealProcessor); res >= 0, res);
wapi_ret_true(SetProcessInformation);
wapi_ret_true(GetProcessInformation);
wapi_ret_true(GetProcessShutdownParameters);
// SetThreadDescription
// GetThreadDescription
#pragma endregion

#pragma region PsApi.h
#pragma endregion

#pragma region SynchApi.h
wapi_ret_direct(InitializeSRWLock);
wapi_ret_direct(ReleaseSRWLockExclusive);
wapi_ret_direct(ReleaseSRWLockShared);
wapi_ret_direct(AcquireSRWLockExclusive);
wapi_ret_direct(AcquireSRWLockShared);
wapi_ret_direct(TryAcquireSRWLockExclusive);
wapi_ret_direct(TryAcquireSRWLockShared);
wapi_ret_direct(InitializeCriticalSection);
wapi_ret_direct(EnterCriticalSection);
wapi_ret_direct(LeaveCriticalSection);
wapi_ret_true(InitializeCriticalSectionAndSpinCount);
wapi_ret_true(InitializeCriticalSectionEx);
wapi_ret_direct(SetCriticalSectionSpinCount);
wapi_ret_direct(TryEnterCriticalSection);
wapi_ret_direct(DeleteCriticalSection);
wapi_ret_direct(InitOnceInitialize);
wapi_ret_true(InitOnceExecuteOnce);
wapi_ret_true(InitOnceBeginInitialize);
wapi_ret_true(InitOnceComplete);
wapi_ret_direct(InitializeConditionVariable);
wapi_ret_direct(WakeConditionVariable);
wapi_ret_direct(WakeAllConditionVariable);
wapi_ret_true(SleepConditionVariableCS);
wapi_ret_true(SleepConditionVariableSRW);
wapi_ret_direct(SetEvent);
wapi_ret_direct(ResetEvent);
wapi_ret_direct(ReleaseSemaphore);
wapi_ret_direct(ReleaseMutex);
// WaitForSingleObject
inline DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
safe_ret_as(auto res = ::WaitForSingleObject(hHandle, dwMilliseconds); res != WAIT_FAILED, res);
wapi_ret_direct(Sleep);
wapi_ret_direct(SleepEx);
// WaitForSingleObjectEx
inline DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable)
safe_ret_as(auto res = ::WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable); res != WAIT_FAILED, res);
// WaitForMultipleObjectsEx
inline DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable)
safe_ret_as(auto res = ::WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable); res != WAIT_FAILED, res);
wapi_ret_true_WAO(CreateMutex);
wapi_ret_true_WAO(OpenMutex); // OpenMutexA from WinBase.h
wapi_ret_true_WAO(CreateEvent);
wapi_ret_true_WAO(OpenSemaphore); // OpenSemaphoreA from WinBase.h
wapi_ret_true_WAO(OpenWaitableTimer); // OpenWaitableTimerA from WinBase.h
wapi_ret_true(SetWaitableTimer);
wapi_ret_true(CancelWaitableTimer);
wapi_ret_notnull_WAO(CreateMutexEx);
wapi_ret_notnull_WAO(CreateEventEx);
// wapi_ret_fault(SignalObjectAndWait, WAIT_FAILED);
// WaitForMultipleObjects
inline DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds)
safe_ret_as(auto res = ::WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds); res != WAIT_FAILED, res);
wapi_ret_true_WAO(CreateSemaphore); // CreateSemaphoreA from WinBase.h
wapi_ret_true_WAO(CreateSemaphoreEx); // CreateSemaphoreExA from WinBase.h
wapi_ret_true_WAO(CreateWaitableTimer); // CreateWaitableTimerA from WinBase.h
wapi_ret_true_WAO(CreateWaitableTimerEx); // CreateWaitableTimerExA from WinBase.h
#pragma endregion

#pragma region NamespaceApi.h
wapi_ret_true_WAO(CreatePrivateNamespace); // CreatePrivateNamespaceA from WinBase.h
wapi_ret_true_WAO(OpenPrivateNamespace); // OpenPrivateNamespaceA from WinBase.h
wapi_ret_true(ClosePrivateNamespace);
wapi_ret_true_WAO(CreateBoundaryDescriptor); // CreateBoundaryDescriptorA from WinBase.h
wapi_ret_true(AddSIDToBoundaryDescriptor);
wapi_ret_direct(DeleteBoundaryDescriptor);
#pragma endregion

#pragma region JobApi.h
// IsProcessInJob
#pragma endregion

#pragma region JobApi2.h
wapi_ret_notnull_WAO(CreateJobObject); // CreateJobObjectA from WinBase.h
wapi_ret_direct(FreeMemoryJobObject);
wapi_ret_notnull_WAO(OpenJobObject); // OpenJobObject from WinBase.h
wapi_ret_true(AssignProcessToJobObject);
wapi_ret_true(TerminateJobObject);
wapi_ret_true(SetInformationJobObject);
wapi_ret_true(SetIoRateControlInformationJobObject);
wapi_ret_true(QueryInformationJobObject);
wapi_ret_true(QueryIoRateControlInformationJobObject);
#pragma endregion

}

}
