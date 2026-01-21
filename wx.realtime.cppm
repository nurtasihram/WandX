module;

#define WX_CPPM_REALTIME
#include "wx_realtime"

export module wx.realtime;

import wx.win32;

#pragma region Win32 Prototype Includes
namespace WX {

constexpr auto ThisFile = LiString("wx.realtimec");

#pragma region ProcessEnv.h
#undef SetEnvironmentStrings
wapi_reflect_bool_WAO(SetEnvironmentStrings); // SetEnvironmentStringsA from WinBase.h
#undef GetCommandLine
wapi_reflect_bool_WAT(GetCommandLine);
#undef GetEnvironmentStrings
//wapi_reflect_bool_WAT(GetEnvironmentStrings);
#undef FreeEnvironmentStrings
wapi_reflect_bool_WAO(FreeEnvironmentStrings);
#undef GetEnvironmentVariable
wapi_reflect_bool_WAO(GetEnvironmentVariable, DWORD);
#undef SetEnvironmentVariable
wapi_reflect_bool_WAO(SetEnvironmentVariable);
#undef ExpandEnvironmentStrings
wapi_reflect_bool_WAO(ExpandEnvironmentStrings, DWORD);
#undef SetCurrentDirectory
wapi_reflect_bool_WAO(SetCurrentDirectory);
#undef GetCurrentDirectory
wapi_reflect_bool_WAO(GetCurrentDirectory, DWORD);
//#undef SearchPath
//inline DWORD SearchPath(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension,
//						DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
//	safe_ret_as(::SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength,
//									 lpBuffer, lpFilePart));
//inline DWORD SearchPath(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension,
//						DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
//	safe_ret_as(::SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength,
//									 lpBuffer, lpFilePart));
#undef NeedCurrentDirectoryForExePath
wapi_reflect_bool_WAO(NeedCurrentDirectoryForExePath);
#pragma endregion

#pragma region ProcessThreadsApi.h
wapi_reflect_bool(QueueUserAPC);
#if (NTDDI_VERSION >= NTDDI_WIN10_MN)
wapi_reflect_bool(QueueUserAPC2);
#endif
wapi_reflect_bool(GetProcessTimes);
// GetCurrentProcess
inline HANDLE GetCurrentProcess()
	ret_as(::GetCurrentProcess());
// GetCurrentProcessId
inline DWORD GetCurrentProcessId()
	ret_as(::GetCurrentProcessId());
// ExitProcess
inline void ExitProcess(UINT uExitCode)
	ret_to(::ExitProcess(uExitCode));
wapi_reflect_bool(TerminateProcess);
wapi_reflect_bool(GetExitCodeProcess);
wapi_reflect_bool(SwitchToThread);
wapi_reflect_bool(CreateThread, HANDLE);
wapi_reflect_bool(CreateRemoteThread, HANDLE);
// GetCurrentThread
inline HANDLE GetCurrentThread()
	ret_as(::GetCurrentThread());
// GetCurrentThreadId
inline DWORD GetCurrentThreadId()
	ret_as(::GetCurrentThreadId());
wapi_reflect_bool(OpenThread, HANDLE);
wapi_reflect_bool(SetThreadPriority);
wapi_reflect_bool(SetThreadPriorityBoost);
wapi_reflect_bool(GetThreadPriorityBoost);
inline int GetThreadPriority(HANDLE hThread)
	safe_ret_as(auto res = ::GetThreadPriority(hThread); res != THREAD_PRIORITY_ERROR_RETURN, res);
// ExitThread
inline void ExitThread(DWORD dwExitCode)
	ret_as(::ExitThread(dwExitCode));
wapi_reflect_bool(TerminateThread);
wapi_reflect_bool(GetExitCodeThread);
// SuspendThread
inline DWORD SuspendThread(HANDLE hThread)
	safe_ret_as(auto res = ::SuspendThread(hThread); res >= 0, res);
// ResumeThread
inline DWORD ResumeThread(HANDLE hThread)
	safe_ret_as(auto res = ::ResumeThread(hThread); res >= 0, res);
// TlsAlloc
inline DWORD TlsAlloc()
	safe_ret_as(auto n = ::TlsAlloc(); n != TLS_OUT_OF_INDEXES, n);
wapi_reflect_bool(TlsGetValue, LPVOID);
wapi_reflect_bool(TlsSetValue);
wapi_reflect_bool(TlsFree);
#undef CreateProcess
wapi_reflect_bool_WAO(CreateProcess);
#undef GetStartupInfo
// wapi_reflect_bool_WAO(GetStartupInfo); // GetStartupInfoA from WinBase.h
wapi_reflect_bool(SetProcessShutdownParameters);
wapi_reflect_bool(GetProcessVersion, DWORD);
#undef CreateProcessAsUser
wapi_reflect_bool_WAO(CreateProcessAsUser);
// GetCurrentProcessToken
inline HANDLE GetCurrentProcessToken()
	ret_as(::GetCurrentProcessToken());
// GetCurrentThreadToken
inline HANDLE GetCurrentThreadToken()
	ret_as(::GetCurrentThreadToken());
// GetCurrentThreadEffectiveToken
inline HANDLE GetCurrentThreadEffectiveToken()
	ret_as(::GetCurrentThreadEffectiveToken());
wapi_reflect_bool(SetThreadToken);
wapi_reflect_bool(OpenProcessToken);
wapi_reflect_bool(OpenThreadToken);
wapi_reflect_bool(SetPriorityClass);
wapi_reflect_bool(GetPriorityClass, DWORD);
wapi_reflect_bool(SetThreadStackGuarantee);
wapi_reflect_bool(ProcessIdToSessionId);
wapi_reflect_bool(GetProcessId, DWORD);
wapi_reflect_bool(GetThreadId, DWORD);
// wapi_reflect_void(FlushProcessWriteBuffers);
wapi_reflect_bool(GetProcessIdOfThread, DWORD);
wapi_reflect_bool(InitializeProcThreadAttributeList);
// wapi_reflect_void(DeleteProcThreadAttributeList);
wapi_reflect_bool(UpdateProcThreadAttribute);
#if (NTDDI_VERSION >= NTDDI_WIN10_VB)
wapi_reflect_bool(SetProcessDynamicEHContinuationTargets);
#endif
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
wapi_reflect_bool(SetProcessDynamicEnforcedCetCompatibleRanges);
#endif
wapi_reflect_bool(SetProcessAffinityUpdateMode);
wapi_reflect_bool(QueryProcessAffinityUpdateMode);
wapi_reflect_bool(CreateRemoteThreadEx, HANDLE);
// wapi_reflect_void(GetCurrentThreadStackLimits);
wapi_reflect_bool(GetThreadContext);
wapi_reflect_bool(GetProcessMitigationPolicy);
wapi_reflect_bool(SetThreadContext);
wapi_reflect_bool(SetProcessMitigationPolicy);
wapi_reflect_bool(FlushInstructionCache);
wapi_reflect_bool(GetThreadTimes);
wapi_reflect_bool(OpenProcess, HANDLE);
// IsProcessorFeaturePresent
inline bool IsProcessorFeaturePresent(DWORD ProcessorFeature)
	ret_as(::IsProcessorFeaturePresent(ProcessorFeature));
wapi_reflect_bool(GetProcessHandleCount);
// GetCurrentProcessorNumber
inline DWORD GetCurrentProcessorNumber()
	ret_as(::GetCurrentProcessorNumber());
wapi_reflect_bool(SetThreadIdealProcessorEx);
wapi_reflect_bool(GetThreadIdealProcessorEx);
// wapi_reflect_void(GetCurrentProcessorNumberEx);
wapi_reflect_bool(GetProcessPriorityBoost);
wapi_reflect_bool(SetProcessPriorityBoost);
wapi_reflect_bool(GetThreadIOPendingFlag);
wapi_reflect_bool(GetSystemTimes);
wapi_reflect_bool(GetThreadInformation);
wapi_reflect_bool(SetThreadInformation);
wapi_reflect_bool(IsProcessCritical);
wapi_reflect_bool(SetProtectedPolicy);
wapi_reflect_bool(QueryProtectedPolicy);
// SetThreadIdealProcessor
inline DWORD SetThreadIdealProcessor(HANDLE hThread, DWORD dwIdealProcessor)
	safe_ret_as(auto res = ::SetThreadIdealProcessor(hThread, dwIdealProcessor); res >= 0, res);
wapi_reflect_bool(SetProcessInformation);
wapi_reflect_bool(GetProcessInformation);
wapi_reflect_bool(GetProcessShutdownParameters);
//// SetThreadDescription
//inline void SetThreadDescription(HANDLE hThread, PCWSTR lpDescription)
//	safe_ret_as(::SetThreadDescription(hThread, lpDescription));
//// GetThreadDescription
//inline void GetThreadDescription(HANDLE hThread, PWSTR* lpDescription)
//	safe_ret_as(::GetThreadDescription(hThread, lpDescription));
// TlsGetValue2 - Deprecated
#pragma endregion

#pragma region PsApi.h
#pragma endregion

#pragma region SynchApi.h
// InitializeSRWLock
inline void InitializeSRWLock(PSRWLOCK SRWLock)
	ret_to(::InitializeSRWLock(SRWLock));
// ReleaseSRWLockExclusive
inline void ReleaseSRWLockExclusive(PSRWLOCK SRWLock)
	ret_to(::ReleaseSRWLockExclusive(SRWLock));
// ReleaseSRWLockShared
inline void ReleaseSRWLockShared(PSRWLOCK SRWLock)
	ret_to(::ReleaseSRWLockShared(SRWLock));
// AcquireSRWLockExclusive
inline void AcquireSRWLockExclusive(PSRWLOCK SRWLock)
	ret_to(::AcquireSRWLockExclusive(SRWLock));
// AcquireSRWLockShared
inline void AcquireSRWLockShared(PSRWLOCK SRWLock)
	ret_to(::AcquireSRWLockShared(SRWLock));
// TryAcquireSRWLockExclusive
inline bool TryAcquireSRWLockExclusive(PSRWLOCK SRWLock)
	ret_as(::TryAcquireSRWLockExclusive(SRWLock));
// TryAcquireSRWLockShared
inline bool TryAcquireSRWLockShared(PSRWLOCK SRWLock)
	ret_as(::TryAcquireSRWLockShared(SRWLock));
// InitializeCriticalSection
inline void InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
	ret_to(::InitializeCriticalSection(lpCriticalSection));
// EnterCriticalSection
inline void EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
	ret_to(::EnterCriticalSection(lpCriticalSection));
// LeaveCriticalSection
inline void LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
	ret_to(::LeaveCriticalSection(lpCriticalSection));
wapi_reflect_bool(InitializeCriticalSectionAndSpinCount);
wapi_reflect_bool(InitializeCriticalSectionEx);
// SetCriticalSectionSpinCount
inline DWORD SetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount)
	ret_as(::SetCriticalSectionSpinCount(lpCriticalSection, dwSpinCount));
// TryEnterCriticalSection
inline bool TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
	ret_as(::TryEnterCriticalSection(lpCriticalSection));
// DeleteCriticalSection
inline void DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
	ret_to(::DeleteCriticalSection(lpCriticalSection));
// InitOnceInitialize
inline void InitOnceInitialize(PINIT_ONCE InitOnce)
	ret_to(::InitOnceInitialize(InitOnce));
wapi_reflect_bool(InitOnceExecuteOnce);
wapi_reflect_bool(InitOnceBeginInitialize);
wapi_reflect_bool(InitOnceComplete);
// InitializeConditionVariable
inline void InitializeConditionVariable(PCONDITION_VARIABLE ConditionVariable)
	ret_to(::InitializeConditionVariable(ConditionVariable));
// WakeConditionVariable
inline void WakeConditionVariable(PCONDITION_VARIABLE ConditionVariable)
	ret_to(::WakeConditionVariable(ConditionVariable));
// WakeAllConditionVariable
inline void WakeAllConditionVariable(PCONDITION_VARIABLE ConditionVariable)
	ret_to(::WakeAllConditionVariable(ConditionVariable));
wapi_reflect_bool(SleepConditionVariableCS);
wapi_reflect_bool(SleepConditionVariableSRW);
// SetEvent
inline void SetEvent(HANDLE hEvent)
	ret_to(::SetEvent(hEvent));
// ResetEvent
inline void ResetEvent(HANDLE hEvent)
	ret_to(::ResetEvent(hEvent));
// ReleaseSemaphore
inline void ReleaseSemaphore(HANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount)
	ret_to(::ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount));
// ReleaseMutex
inline void ReleaseMutex(HANDLE hMutex)
	ret_to(::ReleaseMutex(hMutex));
// WaitForSingleObject
inline DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
	safe_ret_as(auto res = ::WaitForSingleObject(hHandle, dwMilliseconds); res != WAIT_FAILED, res);
// SleepEx
inline DWORD Sleep(DWORD dwMilliseconds, BOOL bAlertable)
	ret_as(::SleepEx(dwMilliseconds, bAlertable));
// WaitForSingleObjectEx
inline DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable)
	safe_ret_as(auto res = ::WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable); res != WAIT_FAILED, res);
// WaitForMultipleObjectsEx
inline DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable)
	safe_ret_as(auto res = ::WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable); res != WAIT_FAILED, res);
#undef CreateMutex
wapi_reflect_bool_WAO(CreateMutex);
#undef OpenMutex
wapi_reflect_bool_WAO(OpenMutex); // OpenMutexA from WinBase.h
#undef CreateEvent
wapi_reflect_bool_WAO(CreateEvent);
#undef OpenSemaphore
wapi_reflect_bool_WAO(OpenSemaphore); // OpenSemaphoreA from WinBase.h
#undef OpenWaitableTimer
wapi_reflect_bool_WAO(OpenWaitableTimer); // OpenWaitableTimerA from WinBase.h
wapi_reflect_bool(SetWaitableTimer);
wapi_reflect_bool(CancelWaitableTimer);
#undef CreateMutexEx
wapi_reflect_bool_WAO(CreateMutexEx, HANDLE);
#undef CreateEventEx
wapi_reflect_bool_WAO(CreateEventEx, HANDLE);
// Sleep
inline void Sleep(DWORD dwMilliseconds)
	ret_to(::Sleep(dwMilliseconds));
// SignalObjectAndWait
inline DWORD SignalObjectAndWait(HANDLE hObjectToSignal, HANDLE hObjectToWaitOn, DWORD dwMilliseconds, BOOL bAlertable)
	safe_ret_as(auto res = ::SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable); res != WAIT_FAILED, res);
// WaitForMultipleObjects
inline DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds)
	safe_ret_as(auto res = ::WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds); res != WAIT_FAILED, res);
#undef CreateSemaphore
wapi_reflect_bool_WAO(CreateSemaphore); // CreateSemaphoreA from WinBase.h
#undef CreateSemaphoreEx
wapi_reflect_bool_WAO(CreateSemaphoreEx); // CreateSemaphoreExA from WinBase.h
#undef CreateWaitableTimer
wapi_reflect_bool_WAO(CreateWaitableTimer); // CreateWaitableTimerA from WinBase.h
#undef CreateWaitableTimerEx
wapi_reflect_bool_WAO(CreateWaitableTimerEx); // CreateWaitableTimerExA from WinBase.h
#pragma endregion

}
#pragma endregion

#if 0
export namespace WX {

template<class AnyChild>
class WaitableBase : public HandleBase<AnyChild> {
public:
	using Super = HandleBase<AnyChild>;
protected:
	WaitableBase(HANDLE h) : Super(h) {}
	WaitableBase(const WaitableBase &w) : Super(w) {}
public:
	WaitableBase() {}
	WaitableBase(Nu) {}
public:
	inline DWORD Wait(DWORD dwMilliseconds = INFINITE) const ret_as(WX::WaitForSingleObject(self, dwMilliseconds) == WAIT_OBJECT_0);
};

#pragma region Event
enum_flags(EventAccess , HandleAccess       ,
		   All         = EVENT_ALL_ACCESS   ,
		   Modify      = EVENT_MODIFY_STATE );
class BaseOf_Waitable(Event) {
public:
	using Super = WaitableBase<Event>;
	using Access = EventAccess;
protected:
	Event(HANDLE h) : Super(h) {}
	Event(const Event &evt) : Super(evt) {}
public:
	Event() : Event(Create()) {}
	Event(Nu) {}
	Event(Event &evt) : Super(evt) {}
	Event(Event &&evt) : Super(evt) {}
public: // Create
	template<class LPCTSTR>
	class CreateStruct {
		friend class Event;
		LPSECURITY_ATTRIBUTES lpAttributes = O;
		bool bManualReset = false;
		bool bInitialState = false;
		LPCTSTR lpName;
		CreateStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Preset(bool bInitialState = true) ret_to_self(this->bInitialState = bInitialState);
		inline auto &AutoReset(bool bAutoReset = true) ret_to_self(this->bManualReset = !bAutoReset);
		inline auto &ManualReset(bool bManualReset = true) ret_to_self(this->bManualReset = bManualReset);
		inline auto &Security(LPSECURITY_ATTRIBUTES pSA) ret_to_self(this->lpAttributes = pSA);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Event() const ret_as(WX::CreateEvent(lpAttributes, bManualReset, bInitialState, lpName));
	};
	static inline CreateStruct<LPCTSTR> Create() ret_as(O);
	static inline CreateStruct<LPCSTR> Create(LPCSTR lpName) ret_as(lpName);
	static inline CreateStruct<LPCWSTR> Create(LPCWSTR lpName) ret_as(lpName);
public: // Open
	template<class LPCTSTR>
	class OpenStruct {
		friend class Event;
		Access dwDesiredAccess = Access::Modify;
		BOOL bInheritHandle = false;
		LPCTSTR lpName;
		OpenStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(bool bInheritHandle = true) ret_to_self(this->bInheritHandle = bInheritHandle);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Event() const ret_as(WX::OpenEvent(dwDesiredAccess.yield(), bInheritHandle, lpName));
	};
	static inline OpenStruct<LPCTSTR> Open() ret_as(O);
	static inline OpenStruct<LPCSTR> Open(LPCSTR lpName) ret_as(lpName);
	static inline OpenStruct<LPCWSTR> Open(LPCWSTR lpName) ret_as(lpName);
public:
	inline void Set() ret_to(WX::SetEvent(self));
	inline void Reset() ret_to(WX::ResetEvent(self));
	inline void Pulse() ret_to(WX::PulseEvent(self));
public:
	using Super::operator=;
	inline auto &operator=(bool bState) ret_to_self(if (bState) Set(); else Reset(););
};
using CEvent = ProxyView<Event>;
#pragma endregion

#pragma region Mutex
enum_flags(MutexAccess  , HandleAccess       ,
		   All          = MUTEX_ALL_ACCESS   ,
		   Modify       = MUTEX_MODIFY_STATE );
class BaseOf_Waitable(Mutex) {
public:
	using Super = WaitableBase<Mutex>;
	using Access = MutexAccess;
protected:
	Mutex(HANDLE h) : Super(h) {}
	Mutex(const Mutex &m) : Super(m.hObject) ret_to(m.hObject = O);
public:
	Mutex() : Mutex(Create()) {}
	Mutex(Nu) {}
	Mutex(Mutex &m) : Super(m) {}
	Mutex(Mutex &&m) : Super(m) {}
public: // Create
	template<class LPCTSTR>
	class CreateStruct {
		friend class Mutex;
		LPSECURITY_ATTRIBUTES lpMutexAttributes = O;
		bool bInitialState = false;
		LPCTSTR lpName;
	protected:
		CreateStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Preset(bool bInitialState = true) ret_to_self(this->bInitialState = bInitialState);
		inline auto &Security(LPSECURITY_ATTRIBUTES lpMutexAttributes) ret_to_self(this->lpMutexAttributes = lpMutexAttributes);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Mutex() const ret_as(WX::CreateMutex(lpMutexAttributes, bInitialState, lpName));
	};
	static inline CreateStruct<LPCTSTR> Create() ret_as(O);
	static inline CreateStruct<LPCSTR> Create(LPCSTR lpName) ret_as(lpName);
	static inline CreateStruct<LPCWSTR> Create(LPCWSTR lpName) ret_as(lpName);
public: // Open
	template<class LPCTSTR>
	class OpenStruct {
		friend class Mutex;
		Access dwDesiredAccess = Access::Modify;
		bool bInheritHandle = false;
		LPCTSTR lpName;
	protected:
		OpenStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(bool bInheritHandle = true) ret_to_self(this->bInheritHandle = bInheritHandle);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Mutex() const ret_as(WX::OpenMutex(dwDesiredAccess.yield(), bInheritHandle, lpName));
	};
	static inline OpenStruct<LPCTSTR> Open() ret_as(O);
	static inline OpenStruct<LPCSTR> Open(LPCSTR lpName) ret_as(lpName);
	static inline OpenStruct<LPCWSTR> Open(LPCWSTR lpName) ret_as(lpName);
public:
	inline void Release() ret_to(WX::ReleaseMutex(self));
public:
	using Super::operator=;
};
using CMutex = ProxyView<Mutex>;
#pragma endregion

#pragma region Semaphore
enum_flags(SemaphoreAccess , HandleAccess           ,
		   All             = SEMAPHORE_ALL_ACCESS   ,
		   Modify          = SEMAPHORE_MODIFY_STATE );
class BaseOf_Waitable(Semaphore) {
public:
	using Super = WaitableBase<Semaphore>;
	using Access = SemaphoreAccess;
protected:
	Semaphore(HANDLE h) : Super(h) {}
	Semaphore(const Semaphore & s) : Super(s.hObject) ret_to(s.hObject = O);
#if 0
public:
	Semaphore() : Semaphore(Create()) {}
	Semaphore(Nu) {}
	Semaphore(Semaphore & s) : Super(s) {}
	Semaphore(Semaphore && s) : Super(s) {}
public: // Create
	template<class LPCTSTR>
	class CreateStruct {
		friend class Semaphore;
		LPSECURITY_ATTRIBUTES lpSemaphoreAttributes = O;
		LONG lInitialCount = 0;
		LONG lMaximumCount = 1;
		LPCTSTR lpName;
	protected:
		CreateStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &InitialCount(LONG lInitialCount) ret_to_self(this->lInitialCount = lInitialCount);
		inline auto &MaximumCount(LONG lMaximumCount) ret_to_self(this->lMaximumCount = lMaximumCount);
		inline auto &Security(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes) ret_to_self(this->lpSemaphoreAttributes = lpSemaphoreAttributes);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Semaphore() const safe_ret_as(CreateSemaphore(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName), h);
	};
	static inline CreateStruct<LPCTSTR> Create() ret_as(O);
	static inline CreateStruct<LPCSTR> Create(LPCSTR lpName) ret_as(lpName);
	static inline CreateStruct<LPCWSTR> Create(LPCWSTR lpName) ret_as(lpName);
public: // Open
	template<class LPCTSTR>
	class OpenStruct {
		friend class Semaphore;
		Access dwDesiredAccess = Access::Modify;
		bool bInheritHandle = false;
		LPCTSTR lpName;
	protected:
		OpenStruct(LPCTSTR lpName) : lpName(lpName) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(bool bInheritHandle = true) ret_to_self(this->bInheritHandle = bInheritHandle);
		inline auto &Name(LPCTSTR lpName) ret_to_self(this->lpName = lpName);
	public:
		inline operator Semaphore() const ret_as(WX::OpenSemaphore(dwDesiredAccess.yield(), bInheritHandle, lpName));
	};
	static inline OpenStruct<LPCTSTR> Open() ret_as(O);
	static inline OpenStruct<LPCSTR> Open(LPCSTR lpName) ret_as(lpName);
	static inline OpenStruct<LPCWSTR> Open(LPCWSTR lpName) ret_as(lpName);
#endif
public:
	using Super::operator=;
};
#pragma endregion

#pragma region WaitableTimer
enum_flags(TimerAccess , HandleAccess       ,
		   All         = TIMER_ALL_ACCESS   ,
		   Modify      = TIMER_MODIFY_STATE );
using WaitableTimerAccess = TimerAccess;
class BaseOf_Waitable(WaitableTimer) {
public:
	using Super = WaitableBase<WaitableTimer>;
	using Access = TimerAccess;
protected:
	WaitableTimer(HANDLE h) : Super(h) {}
	WaitableTimer(const WaitableTimer &t) : Super(t.hObject) ret_to(t.hObject = O);
#if 0
public:
	WaitableTimer() : WaitableTimer(Create()) {}
	WaitableTimer(Nu) {}
	WaitableTimer(WaitableTimer &t) : Super(t) {}
	WaitableTimer(WaitableTimer &&t) : Super(t) {}
public:
	template<class LPCTSTR>
	class CreateStruct {
		friend class WaitableTimer;
		LPSECURITY_ATTRIBUTES lpWaitableTimerAttributes = O;
		bool bManualReset = false;
		LPCTSTR lpWaitableTimerName = O;
	protected:
		CreateStruct(LPCTSTR lpWaitableTimerName) : lpWaitableTimerName(lpWaitableTimerName) {}
	public:
		inline auto &ManualReset(bool bManualReset = true) ret_to_self(this->bManualReset = bManualReset);
		inline auto &Security(LPSECURITY_ATTRIBUTES lpWaitableTimerAttributes) ret_to_self(this->lpWaitableTimerAttributes = lpWaitableTimerAttributes);
		inline auto &Name(LPCTSTR lpWaitableTimerName) ret_to_self(this->lpWaitableTimerName = lpWaitableTimerName);
	public:
		inline operator WaitableTimer() const ret_as(WX::CreateWaitableWaitableTimer(lpWaitableTimerAttributes, bManualReset, lpWaitableTimerName));
	};
	static inline CreateStruct<LPCTSTR> Create() ret_as(O);
	static inline CreateStruct<LPCSTR> Create(LPCSTR lpWaitableTimerName) ret_as(lpWaitableTimerName);
	static inline CreateStruct<LPCWSTR> Create(LPCWSTR lpWaitableTimerName) ret_as(lpWaitableTimerName);
public:
	template<class LPCTSTR>
	class OpenStruct {
		friend class WaitableTimer;
		Access dwDesiredAccess = Access::Modify;
		BOOL bInheritHandle = FALSE;
		LPCTSTR lpWaitableTimerName;
	protected:
		OpenStruct(LPCTSTR lpWaitableTimerName) : lpWaitableTimerName(lpWaitableTimerName) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(BOOL bInheritHandle = TRUE) ret_to_self(this->bInheritHandle = bInheritHandle);
		inline auto &Name(LPCTSTR lpWaitableTimerName) ret_to_self(this->lpWaitableTimerName = lpWaitableTimerName);
	public:
		inline operator WaitableTimer() const ret_as(WX::OpenWaitableWaitableTimer(dwDesiredAccess.yield(), bInheritHandle, lpWaitableTimerName));
	};
	static inline OpenStruct<LPCTSTR> Open() ret_as(O);
	static inline OpenStruct<LPCSTR> Open(LPCSTR lpWaitableTimerName) ret_as(lpWaitableTimerName);
	static inline OpenStruct<LPCWSTR> Open(LPCWSTR lpWaitableTimerName) ret_as(lpWaitableTimerName);
#endif
public:
	using Super::operator=;
};
using Timer = WaitableTimer;
#pragma endregion

#pragma region PrivateNamespace
class BaseOf_Handle(PrivateNamespace) {
public:
	using Super = HandleBase<PrivateNamespace>;
protected:
	PrivateNamespace(HANDLE h) : Super(h) {}
	PrivateNamespace(const PrivateNamespace & t) : Super(t.hObject) ret_to(t.hObject = O);
public:
	PrivateNamespace() {}
	PrivateNamespace(PrivateNamespace &t) : Super(t) {}
	PrivateNamespace(PrivateNamespace &&t) : Super(t) {}
};
using Namespace = PrivateNamespace;
#pragma endregion

struct PTTimes { FileTime CreationTime, ExitTime, KernelTime, UserTime; };

#pragma region ThreadBase
enum_flags(ThreadAccess       , HandleAccess                     ,
		   Resume             = THREAD_RESUME                    ,
		   Terminate          = THREAD_TERMINATE                 ,
		   SuspendResume      = THREAD_SUSPEND_RESUME            ,
		   GetContext         = THREAD_GET_CONTEXT               ,
		   SetContext         = THREAD_SET_CONTEXT               ,
		   QueryInfo          = THREAD_QUERY_INFORMATION         ,
		   QueryInfoLimit     = THREAD_QUERY_LIMITED_INFORMATION ,
		   SetInfo            = THREAD_SET_INFORMATION           ,
		   SetInfoLimit       = THREAD_SET_LIMITED_INFORMATION   ,
		   SetToken           = THREAD_SET_THREAD_TOKEN          ,
		   Impersonate        = THREAD_IMPERSONATE               ,
		   ImpersonateDirect  = THREAD_DIRECT_IMPERSONATION      ,
		   All                = THREAD_ALL_ACCESS                );
template<class AnyChild = void>
class ThreadBase;
using Thread = ThreadBase<>;
using CThread = ProxyView<Thread>;
template<>
class BaseOf_Waitable(ThreadBase<>) {
	friend class Process;
public:
	using Super = WaitableBase<ThreadBase<>>;
	using Access = ThreadAccess;
protected:
	friend_to_proxy(Thread);
	ThreadBase(HANDLE h) : Super(h) {}
	ThreadBase(const ThreadBase &t) : Super(t.hObject) ret_to(t.hObject = O);
public:
	ThreadBase() {}
	ThreadBase(Nu) {}
	ThreadBase(ThreadBase &t) : Super(t.hObject) {}
	ThreadBase(ThreadBase &&t) : Super(t.hObject) {}
public:
	template<class AnyChild = void>
	class CreateStruct : public ChildBridge<AnyChild, CreateStruct> {
		friend class ThreadBase;
		LPSECURITY_ATTRIBUTES lpThreadAttributes = O;
		SIZE_T dwStackSize = 0;
		LPTHREAD_START_ROUTINE lpStartAddress;
		LPVOID lpParameter;
		DWORD dwCreationFlags = STACK_SIZE_PARAM_IS_A_RESERVATION;
	protected:
		CreateStruct(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter) : lpStartAddress(lpStartAddress), lpParameter(lpParameter) {}
		CreateStruct(const CreateStruct &) = default;
	public:
		inline auto &Param(LPVOID lpParameter) ret_to_child(this->lpParameter = lpParameter);
		inline auto &Security(LPSECURITY_ATTRIBUTES lpThreadAttributes) ret_to_child(this->lpThreadAttributes = lpThreadAttributes);
		inline auto &StackSize(SizeT dwStackSize) ret_to_child(this->dwStackSize = dwStackSize, this->dwCreationFlags &= ~STACK_SIZE_PARAM_IS_A_RESERVATION);
		inline auto &Suspend(bool bSuspend = true) ret_to_child(this->dwCreationFlags = bSuspend ? (this->dwCreationFlags | CREATE_SUSPENDED) : (this->dwCreationFlags & ~CREATE_SUSPENDED));
	public:
		template<class Child>
		inline ProxyView<ThreadBase<Child>> Create() ret_as(WX::CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, O));
	};
	static inline CreateStruct<> Create(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter = O) ret_as({ lpStartAddress, lpParameter });
	class OpenStruct {
		friend class ThreadBase;
		Access dwDesiredAccess = Access::All;
		bool bInheritHandle = false;
		DWORD dwThreadId;
		OpenStruct(DWORD dwThreadId) : dwThreadId(dwThreadId) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(bool bInheritHandle) ret_to_self(this->bInheritHandle = bInheritHandle);
	public:
		inline operator ThreadBase() const ret_as(WX::OpenThread(dwDesiredAccess.yield(), bInheritHandle, dwThreadId));
	};
	static inline OpenStruct Open(DWORD dwProcessId) ret_as(dwProcessId);
	static inline Thread Current() ret_as(WX::GetCurrentThread());
	static inline void Exit(DWORD dwExitCode = 0) ret_to(WX::ExitThread(dwExitCode));
public:
	inline DWORD Suspend() ret_as(WX::SuspendThread(self));
	inline DWORD Resume() ret_as(WX::ResumeThread(self));
	inline void Terminate(DWORD dwExitCode = 0) ret_to(WX::TerminateThread(this->hObject, dwExitCode));
	template<class MsgType = UINT, class WParam = WPARAM, class LParam = LPARAM>
	inline void Post(MsgType msgid, WParam wParam = 0, LParam lParam = 0) ret_to(WX::PostThreadMessage<>(ID(), reuse_cast<UINT>(msgid), small_cast<WPARAM>(wParam), small_cast<LPARAM>(lParam)));
	template<class MsgType = UINT, class WParam = WPARAM, class LParam = LPARAM>
	inline void PostA(MsgType msgid, WParam wParam = 0, LParam lParam = 0) ret_to(WX::PostThreadMessage<false>(ID(), reuse_cast<UINT>(msgid), small_cast<WPARAM>(wParam), small_cast<LPARAM>(lParam)));
	template<class MsgType = UINT, class WParam = WPARAM, class LParam = LPARAM>
	inline void PostW(MsgType msgid, WParam wParam = 0, LParam lParam = 0) ret_to(WX::PostThreadMessage<true>(ID(), reuse_cast<UINT>(msgid), small_cast<WPARAM>(wParam), small_cast<LPARAM>(lParam)));
#pragma region Properties
public: // Property - ID
	/* W */ inline DWORD ID() const ret_as(WX::GetThreadId(self));
public: // Property - ExitCode
	/* W */ inline DWORD ExitCode() const ret_to(DWORD dwExitCode; WX::GetExitCodeThread(self, &dwExitCode), dwExitCode);
public: // Property - StillActive
	/* W */ inline bool StillActive() const {
		if (self)
			if (ExitCode() == STILL_ACTIVE)
				return !Super::Wait(0);
		return false;
	}
public: // Property - ProcessID
	/* R */ inline auto ProcessID() const ret_as(WX::GetProcessIdOfThread(self));
public: // Property - Times
	/* R */ inline auto Times() ret_to(PTTimes t; WX::GetThreadTimes(self, &t.CreationTime, &t.ExitTime, &t.KernelTime, &t.UserTime), t);
#pragma endregion
public:
	using Super::operator=;
};
template<class AnyChild>
class ThreadBase : public Thread, public ChildBridge<AnyChild, ThreadBase> {
	friend class ThreadBase<>;
public:
	using Super = Thread;
	using typename ChildBridge<AnyChild, ThreadBase>::Child;
	using ChildBridge<AnyChild, ThreadBase>::__child__;
protected:
	friend_to_proxy(ThreadBase);
	ThreadBase(HANDLE h) : Super(h) {}
	ThreadBase(const ThreadBase &t) : Super(t) {}
public:
	ThreadBase() {}
	ThreadBase(Nu) {}
	ThreadBase(ThreadBase &t) : Super(t) {}
	ThreadBase(ThreadBase &&t) : Super(t) {}
public:
	class CreateStruct : public Thread::CreateStruct<CreateStruct> {
	public:
		using Super = Thread::CreateStruct<CreateStruct>;
	protected:
		friend class ThreadBase;
		Child &_this;
		CreateStruct(Child &c) : Super(_ThrProc, &c), _this(c) {}
	public:
		~CreateStruct() ret_to(Create());
	public:
		inline void Create() {
			if (!_this) 
				_this.hObject = Super::template Create<AnyChild>();
		}
	public: // Remove properties
		inline auto &Param(LPVOID) = delete;
	};
	inline CreateStruct Create() retchild;
protected: // Thread Procedure
	use_member(OnRun);
	static DWORD WINAPI _ThrProc(LPVOID lpChild) {
		auto pChild = static_cast<Child *>(lpChild);
	retry:
		try {
			misdef_assert(member_OnRun_of<AnyChild>::is_addressable,
						  "Member OnRun uncallable, unexisted or undefined");
			if_c (member_OnRun_of<AnyChild>::template compatible_to<DWORD()>)
				ret_as(pChild->OnRun())
			else {
				misdef_assert(member_OnRun_of<AnyChild>::template compatible_to<void()>,
							  "Member OnRun must be compatible to DWORD() or void()");
				ret_as((pChild->OnRun(), 0L))
			}
		} catch (Exception err) {
			if (Catch(pChild, err))
				goto retry;
			return Final(pChild, err);
		}
		return -2; // unreachable
	}
protected: // Thread Procedure Exception System
	use_member(OnCatch);
	static inline wx_answer Catch(Child *pChild, const Exception &err) {
		if_c (member_OnCatch_of<AnyChild>::template compatible_to<wx_answer(Exception)>)
			ret_as(pChild->OnCatch(err))
		elif_c (member_OnCatch_of<AnyChild>::template compatible_to<wx_answer()>)
			ret_as(pChild->OnCatch())
		elif_c (member_OnCatch_of<AnyChild>::template compatible_to<void(Exception)>)
			ret_as((pChild->OnCatch(err), false))
		elif_c (member_OnCatch_of<AnyChild>::template compatible_to<void()>)
			ret_as((pChild->OnCatch(), false))
		else {
			misdef_assert(!member_OnCatch_of<AnyChild>::is_addressable,
						  "Member OnCatch must be compatible to wx_answer(Exception), wx_answer(), void(Exception) or void()");
			switch (MsgBox(Q(T("Thread[PID:"), (*(ThreadBase *)pChild).ID(), T("] error")), toString(err))) {
				case IDIGNORE:
					wx_answer_ignore;
				case IDRETRY:
					wx_answer_retry;
				case IDABORT:
					break;
			}
			wx_answer_abort(err);
		}
	}
	use_member(OnFinal);
	static inline DWORD Final(Child *pChild, const Exception &err) {
		if_c (member_OnFinal_of<AnyChild>::template compatible_to<DWORD(Exception)>)
			ret_as(pChild->OnFinal(err))
		elif_c (member_OnFinal_of<AnyChild>::template compatible_to<DWORD()>)
			ret_as(pChild->OnFinal())
		elif_c (member_OnFinal_of<AnyChild>::template compatible_to<void(Exception)>)
			ret_as((pChild->OnFinal(err), -1))
		elif_c (member_OnFinal_of<AnyChild>::template compatible_to<void()>)
			ret_as((pChild->OnFinal(), -1))
		else {
			misdef_assert(!member_OnFinal_of<AnyChild>::is_addressable,
						  "Member OnFinal must be compatible to DWORD(Exception), DWORD(), void(Exception), void()");
			ret_as(-3)
		}
	}
};
class BaseOf_Thread(LThread) {
	SFINAE_Thread(LThread);
protected:
	struct StartClosure {
		virtual ~StartClosure() {}
		virtual DWORD operator()() = 0;
	};
	template<class AnyCallable>
	struct InlineStartClosure : StartClosure {
		AnyCallable f;
		InlineStartClosure(const AnyCallable &f) : f(f) {}
		DWORD operator()() override {
			if_c (static_compatible<AnyCallable, DWORD()>)
				ret_as(f())
			else {
				misdef_assert((static_compatible<AnyCallable, void()>),
							  "Lambda closure must be compatible to DWORD() or void()");
				ret_as((f(), 0L))
			}
		}
	};
	StartClosure *lpStart = O;
	inline DWORD OnRun() ret_as((*lpStart)());
#pragma region Thread Procedure Exception System
protected:
	struct ExceptionClosure {
		virtual ~ExceptionClosure() {}
		virtual bool OnCatch(const Exception &err) = 0;
	};
	template<class AnyCatch>
	struct InlineExceptionClosure : ExceptionClosure {
		AnyCatch lOnCatch;
		InlineExceptionClosure(const AnyCatch &lOnCatch) : lOnCatch(lOnCatch) {}
		bool OnCatch(const Exception &err) override {
			if_c (static_compatible<AnyCatch, wx_answer(Exception)>)
				ret_as(lOnCatch(err))
			elif_c (static_compatible<AnyCatch, wx_answer()>)
				ret_as(lOnCatch())
			elif_c (static_compatible<AnyCatch, void(Exception)>)
				ret_as((lOnCatch(err), false))
			else {
				misdef_assert((static_compatible<AnyCatch, void()>),
							  "Member OnCatch must be compatible to wx_answer(Exception), wx_answer(), void(Exception) or void()");
				ret_as((lOnCatch(err), false))
			}
		}
	};
	ExceptionClosure *lpException = O;
	inline bool OnCatch(const Exception &err) ret_as(lpException ? lpException->OnCatch(err) : false);
public:
	template<class AnyCatch>
	void SetOnCatch(const AnyCatch &Catch) ret_to(lpException = new InlineExceptionClosure<AnyCatch>(Catch));
#pragma endregion
public:
	template<class AnyCallable>
	LThread(const AnyCallable &OnRun) : lpStart(new InlineStartClosure<AnyCallable>(OnRun)) {}
	~LThread() {
		if (StillActive())
			Terminate();
		if (lpStart)
			delete lpStart,
			lpStart = O;
		if (lpException)
			delete lpException,
			lpException = O;
	}
};
#pragma endregion

#pragma region Environment
template<bool IsUnicode = WX::IsUnicode>
class EnvironmentsX {
	using TCHAR = XCHAR<IsUnicode>;
	using LPTCH = TCHAR *;
	using LPCTSTR = const TCHAR *;
	using String = StringBase<TCHAR>;
private:
	LPTCH lpEnv = O;
public:
	class Variable {
		friend class EnvironmentsX;
		const String name;
		const String value;
	public:
		Variable() {}
		Variable(const String &entry) {
			LPCTSTR lpName = entry, pName = lpName;
			while (*pName++ != '=');
			name = +CString(pName - lpName - 1, lpName);
			value = +CString(pName, entry.Length() - name.Length());
		}
		Variable(const String &name, const String &value) ret_to(this->name = name; this->value = value);
	public: // Property - Name
		/* W */ inline Variable &Name(const String &name) ret_to_self(this->name = name);
		/* R */ inline const String &Name() const ret_as(this->name);
	public: // Property - Value
		/* W */ inline Variable &Value(const String &value) ret_to_self(this->value = value);
		/* R */ inline const String &Value() const ret_as(this->value);
	public: // Property - ValueExpend
		inline String ValueExpend() const {
			if (!value) return O;
			auto len = WX::ExpandEnvironmentStrings(value, O, 0);
			if (len - 1 == value.Length()) return &value;
			String str((SizeT)len - 1);
			WX::ExpandEnvironmentStrings(value, str, len);
			return right_hand_cast(str);
		}
	public:
		inline auto &operator=(const String &value) ret_to_self(Value(value));
		inline operator bool() const ret_as(name);
		inline operator String() const ret_as(&Value());
		inline String operator+() const ret_as(ValueExpend());
		inline bool operator!=(Nu) const ret_as(name);
		inline bool operator==(Nu) const ret_as(!name);
	};
protected:
	EnvironmentsX(LPTCH lpEnv) : lpEnv(lpEnv) {}
public:
	EnvironmentsX() {}
	EnvironmentsX(Nu) {}
	EnvironmentsX(EnvironmentsX &env) : lpEnv(env.lpEnv) ret_to(env.lpEnv = O);
	EnvironmentsX(EnvironmentsX &&env) : lpEnv(env.lpEnv) ret_to(env.lpEnv = O);
	~EnvironmentsX() ret_to(Free());
public:
	static inline EnvironmentsX From(std::initializer_list<const String> envs) {
		SizeT maxlen = 1;
		for (const String &env : envs)
			if (env.Length())
				maxlen += env.Length() + 1;
		if (maxlen <= 1) return O;
		LPTCH lpEnv = (LPTCH)ThisHeap->Alloc(maxlen * sizeof(TCHAR)), pEnv = lpEnv;
		for (const String &env : envs)
			if (auto len = env.Length()) {
				CopyMemory(pEnv, (LPCTSTR)env, len * sizeof(TCHAR));
				pEnv += len;
				*pEnv++ = '\0';
			}
		*pEnv = '\0';
		return lpEnv;
	}
	static inline EnvironmentsX From(std::initializer_list<const Variable> vars) {
		SizeT maxlen = 1;
		for (const Variable &var : vars)
			if (var)
				maxlen += var.name.Length() + var.value.Length() + 2;
		if (maxlen <= 1) return O;
		LPTCH lpEnv = (LPTCH)ThisHeap->Alloc(maxlen * sizeof(TCHAR)), pEnv = lpEnv;
		for (const Variable &var : vars)
			if (var) {
				CopyMemory(pEnv, (LPCTSTR)var.name, var.name.Length() * sizeof(TCHAR));
				pEnv += var.name.Length();
				*pEnv++ = '=';
				CopyMemory(pEnv, (LPCTSTR)var.value, var.value.Length() * sizeof(TCHAR));
				pEnv += var.value.Length();
				*pEnv++ = '\0';
			}
		*pEnv = '\0';
		return lpEnv;
	}
	static inline EnvironmentsX Current() ret_as(GetEnvironmentStrings<IsUnicode>());
public:
	inline void Free() {
		if (lpEnv)
			FreeEnvironmentStrings(lpEnv);
		lpEnv = O;
	}
public:
	inline void Use() const ret_to(SetEnvironmentStrings(lpEnv));
#pragma region Properties
public: // Property - Count
	/* R */ inline SizeT Count() const {
		if (!lpEnv) return 0;
		SizeT count = 0;
		for (auto ch = lpEnv; *ch != '\0'; ++ch) {
			while (*ch != '\0')
				++ch;
			++count;
		}
		return count;
	}
public: // Property - Entries
	template<SizeT MaxLen = MaxLenNotice>
	/* R */ inline std::vector<String> Entries() const {
		SizeT count = Count();
		std::vector<String> list(count);
		auto lpEnv = this->lpEnv;
		for (const String &e : list)
			lpEnv += (e = CString(lpEnv, MaxLen)).Length() + 1;
		return list;
	}
public: // Property - Variables
	template<SizeT MaxLen = MaxLenNotice>
	/* R */ inline std::vector<Variable> Variables() const {
		SizeT count = Count();
		std::vector<Variable> list(count);
		auto lpEnv = this->lpEnv;
		for (const Variable &e : list) {
			auto lpName = lpEnv;
			while (*lpEnv++ != '=');
			e.name = CString(lpEnv - lpName - 1, lpName);
			e.value = CString(lpEnv, MaxLen);
			lpEnv += e.value.Length() + 1;
		}
		return list;
	}
#pragma endregion
public:
	inline operator bool() const ret_as(lpEnv);
	inline operator LPTCH() const ret_as(lpEnv);
};
using Environments = EnvironmentsX<IsUnicode>;
using EnvironmentsA = EnvironmentsX<false>;
using EnvironmentsW = EnvironmentsX<true>;
class CurrentEnvironment {
	template<class TCHAR>
	class Variable {
		using LPCTSTR = const TCHAR *;
		using String = StringBase<TCHAR>;
	private:
		LPCTSTR lpName;
	public:
		Variable(LPCTSTR lpName) : lpName(lpName) {}
	public: // Property - Value
		/* W */ inline auto &Value(LPCTSTR lpValue) 
			ret_to_self(WX::SetEnvironmentVariable(lpName, lpValue));
		/* R */ inline String Value() const {
			auto len = WX::GetEnvironmentVariable(lpName, O, 0);
			String str((SizeT)len - 1);
			WX::SetEnvironmentVariable(lpName, str, len);
			return right_hand_cast(str);
		}
	public: // Property - Expand
		/* R */ inline String Expand() const {
			auto &&val = Value();
			auto len = WX::ExpandEnvironmentStrings(val, O, 0);
			if (val.Length() == len) return val;
			String str((SizeT)len - 1);
			WX::ExpandEnvironmentStrings(val, str, len);
			return right_hand_cast(str);
		}
	public:
		inline auto &operator=(LPCTSTR lpValue) ret_to_self(Value(lpValue));
		inline operator bool() const ret_as(GetEnvironmentVariable(lpName, O, 0));
		inline operator String() const ret_as(Value());
		inline String operator+() const ret_as(Expand());
		inline bool operator!=(Nu) const ret_as(GetEnvironmentVariable(lpName, O, 0) != 0);
		inline bool operator==(Nu) const ret_as(GetEnvironmentVariable(lpName, O, 0) == 0);
	};
public:
///	inline operator Environments() ret_as(Environments::Current());
//	inline void operator=(const Environments &env) ret_to(env.Use());
	template<class TCHAR>
	inline Variable<TCHAR> operator[](const TCHAR *lpName) ret_as(lpName);
} inline Environment;
#pragma endregion

#pragma region Process
enum_flags(StartupFlag       , DWORD                   ,
		   UseShowWindow     = STARTF_USESHOWWINDOW    ,
		   UseSize           = STARTF_USESIZE          ,
		   UsePosition       = STARTF_USEPOSITION      ,
		   UseCountChars     = STARTF_USECOUNTCHARS    ,
		   UseFillAttribute  = STARTF_USEFILLATTRIBUTE ,
		   UseStdHandles     = STARTF_USESTDHANDLES    ,
		   UseHotKey         = STARTF_USEHOTKEY        ,
		   RunFullScreen     = STARTF_RUNFULLSCREEN    ,
		   ForceOnFeedback   = STARTF_FORCEONFEEDBACK  ,
		   ForceOffFeedback  = STARTF_FORCEOFFFEEDBACK ,
		   TitleIsLinkName   = STARTF_TITLEISLINKNAME  ,
		   TitleIsAppID      = STARTF_TITLEISAPPID     ,
		   PreventPinning    = STARTF_PREVENTPINNING   ,
		   UntrustedSource   = STARTF_UNTRUSTEDSOURCE  );
template<bool IsUnicode = WX::IsUnicode>
class StartupInfoX : public StructShim<structx(STARTUPINFO)> {
	using_structx(WNDCLASSEX);
	using LPTSTR = LPXSTR<IsUnicode>;
	using String = StringX<IsUnicode>;
public:
	using Super = StructShim<STARTUPINFO>;
public:
	StartupInfoX() ret_to(WX::GetStartupInfo(this));
	StartupInfoX(Nu) ret_to(self->cb = sizeof(*self));
	StartupInfoX(const STARTUPINFO &si) : Super(si) {}
public: // Property - Desktop
proxy_prop_set(Desktop, lpDesktop, LPTSTR);
	template<SizeT MaxLen = MaxLenTitle>
 	/* R */ inline const String Desktop() const ret_as(CString(self->lpDesktop, MaxLen));
public: // Property - Title
proxy_prop_set(Title, lpTitle, LPTSTR);
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline const String Title() const ret_as(CString(self->lpTitle, MaxLen));
public: // Property - Position
	/* W */ inline auto  &Position(LPoint pos) ret_to_self(self->dwFlags |= STARTF_USEPOSITION, self->dwX = pos.x, self->dwY = pos.y);
	/* R */ inline LPoint Position() const ret_as({ (LONG)self->dwX, (LONG)self->dwY });
public: // Property - Size
	/* W */ inline auto &Size(LSize size) ret_to_self(self->dwFlags |= STARTF_USESIZE, self->dwXSize = size.cx, self->dwYSize = size.cy);
	/* R */ inline LSize Size() const ret_as({ (LONG)self->dwXSize, (LONG)self->dwYSize });
public: // Property - CountCmhars
	/* W */ inline auto &CountChars(LSize size) ret_to_self(self->dwFlags |= STARTF_USECOUNTCHARS, self->dwXCountChars = size.cx, self->dwYCountChars = size.cy);
	/* R */ inline LSize CountChars() const ret_as({ (LONG)self->dwXCountChars, (LONG)self->dwYCountChars });
public: // Property - FillAttribute
	/* W */ inline auto &FillAttribute(DWORD dwFillAttribute) ret_to_self(self->dwFlags |= STARTF_USEFILLATTRIBUTE, self->dwFillAttribute = dwFillAttribute);
//proxy_prop_get(FillAttribute,dwFillAttribute,auto);
public: // Property - Flags
	/* R */ inline StartupFlag Flags() const ret_as(reuse_cast<StartupFlag>(self->dwFlags));
public: // Property - Show
	/* W */ inline auto  &Show(WX::SW wShow) ret_to_self(self->dwFlags |= STARTF_USESHOWWINDOW, self->wShowWindow = wShow.yield());
	/* R */ inline WX::SW Show() const ret_as(reuse_cast<WX::SW>((DWORD)self->wShowWindow));
public: // Property - StdInput
	/* W */ inline auto &StdInput(HANDLE hStdInput) ret_to_self(self->dwFlags |= STARTF_USESTDHANDLES, self->hStdInput = hStdInput);
proxy_prop_get(StdInput,hStdInput, Handle);
public: // Property - StdOutput
	/* W */ inline auto &StdOutput(HANDLE hStdOutput) ret_to_self(self->dwFlags |= STARTF_USESTDHANDLES, self->hStdOutput = hStdOutput);
proxy_prop_get(StdOutput,hStdOutput,Handle);
public: // Property - StdError
	/* W */ inline auto &StdError(HANDLE hStdError) ret_to_self(self->dwFlags |= STARTF_USESTDHANDLES, self->hStdError = hStdError);
proxy_prop_get(StdError,hStdError, Handle);
};
using StartupInfo = StartupInfoX<IsUnicode>;
using StartupInfoA = StartupInfoX<false>;
using StartupInfoW = StartupInfoX<true>;
enum_flags(ProcessCreateFlag            , DWORD                            ,
		   Default                      = 0                                ,
		   DebugProcess                 = DEBUG_PROCESS                    ,
		   DebugOnlyThisProcess         = DEBUG_ONLY_THIS_PROCESS          ,
		   CreateSuspended              = CREATE_SUSPENDED                 ,
		   DetachedProcess              = DETACHED_PROCESS                 ,
		   CreateNewConsole             = CREATE_NEW_CONSOLE               ,
		   NormalPriorityClass          = NORMAL_PRIORITY_CLASS            ,
		   IdlePriorityClass            = IDLE_PRIORITY_CLASS              ,
		   HighPriorityClass            = HIGH_PRIORITY_CLASS              ,
		   RealtimePriorityClass        = REALTIME_PRIORITY_CLASS          ,
		   CreateNewProcessGroup        = CREATE_NEW_PROCESS_GROUP         ,
		   CreateUnicodeEnvironment     = CREATE_UNICODE_ENVIRONMENT       ,
		   CreateSeparateWowVdm         = CREATE_SEPARATE_WOW_VDM          ,
		   CreateSharedWowVdm           = CREATE_SHARED_WOW_VDM            ,
		   CreateForceDos               = CREATE_FORCEDOS                  ,
		   BelowNormalPriorityClass     = BELOW_NORMAL_PRIORITY_CLASS      ,
		   AboveNormalPriorityClass     = ABOVE_NORMAL_PRIORITY_CLASS      ,
		   InheritParentAffinity        = INHERIT_PARENT_AFFINITY          ,
		   InheritCallerPriority        = INHERIT_CALLER_PRIORITY          ,
		   CreateProtectedProcess       = CREATE_PROTECTED_PROCESS         ,
		   ExtendedStartupInfoPresent   = EXTENDED_STARTUPINFO_PRESENT     ,
		   ProcessModeBackgroundBegin   = PROCESS_MODE_BACKGROUND_BEGIN    ,
		   ProcessModeBackgroundEnd     = PROCESS_MODE_BACKGROUND_END      ,
		   CreateSecureProcess          = CREATE_SECURE_PROCESS            ,
		   CreateBreakawayFromJob       = CREATE_BREAKAWAY_FROM_JOB        ,
		   CreatePreserveCodeAuthzLevel = CREATE_PRESERVE_CODE_AUTHZ_LEVEL ,
		   CreateDefaultErrorMode       = CREATE_DEFAULT_ERROR_MODE        ,
		   CreateNoWindow               = CREATE_NO_WINDOW                 ,
		   ProfileUser                  = PROFILE_USER                     ,
		   ProfileKernel                = PROFILE_KERNEL                   ,
		   ProfileServer                = PROFILE_SERVER                   ,
		   CreateIgnoreSystemDefault    = CREATE_IGNORE_SYSTEM_DEFAULT     );
enum_flags(ProcessAccess            , DWORD                             ,
		   Terminate                = PROCESS_TERMINATE                 ,
		   CreateThread             = PROCESS_CREATE_THREAD             ,
		   SetSessionid             = PROCESS_SET_SESSIONID             ,
		   VmOperation              = PROCESS_VM_OPERATION              ,
		   VmRead                   = PROCESS_VM_READ                   ,
		   VmWrite                  = PROCESS_VM_WRITE                  ,
		   DupHandle                = PROCESS_DUP_HANDLE                ,
		   CreateProcess            = PROCESS_CREATE_PROCESS            ,
		   SetQuota                 = PROCESS_SET_QUOTA                 ,
		   SetInformation           = PROCESS_SET_INFORMATION           ,
		   QueryInformation         = PROCESS_QUERY_INFORMATION         ,
		   SuspendResume            = PROCESS_SUSPEND_RESUME            ,
		   QueryLimitedInformation  = PROCESS_QUERY_LIMITED_INFORMATION ,
		   SetLimitedInformation    = PROCESS_SET_LIMITED_INFORMATION   ,
		   All                      = PROCESS_ALL_ACCESS                );
class BaseOf_Waitable(Process) {
public:
	using Super = WaitableBase<Process>;
	using Access = ProcessAccess;
	using CreateFlag = ProcessCreateFlag;
protected:
	Process(HANDLE h) : Super(h) {}
	Process(const Process &p) : Super(p) {}
public:
	Process() {}
	Process(Nu) {}
	Process(Process &p) : Super(p) {}
	Process(Process &&p) : Super(p) {}
public:
	class CreateStruct {
		LPCTSTR lpApplicationName;
		mutable LPTSTR lpCommandLine;
		LPSECURITY_ATTRIBUTES lpProcessAttributes = O;
		LPSECURITY_ATTRIBUTES lpThreadAttributes = O;
		bool bInheritHandles = false;
		CreateFlag dwCreationFlags = CreateFlag::Default;
		LPVOID lpEnvironment = O;
		LPCTSTR lpCurrentDirectory = O;
		StartupInfo startupInfo;
		PROCESS_INFORMATION processInfo = { O };
	public:
		CreateStruct(const CreateStruct &cs) { *this = cs, cs.lpCommandLine = O; }
		CreateStruct(LPCTSTR lpApplicationName, const String &Cmdl) : lpApplicationName(lpApplicationName), lpCommandLine(*Cmdl) {}
		~CreateStruct() ret_to(String::AutoFree(lpCommandLine));
	public:
		inline auto &Security(LPSECURITY_ATTRIBUTES lpProcessAttributes) ret_to_self(this->lpProcessAttributes = lpProcessAttributes);
		inline auto &SecurityThread(LPSECURITY_ATTRIBUTES lpThreadAttributes) ret_to_self(this->lpThreadAttributes = lpThreadAttributes);
		inline auto &InheritHandles(bool bInheritHandles = true) ret_to_self(this->bInheritHandles = bInheritHandles);
	public:
		inline auto &DebugProcess() ret_to_self(this->dwCreationFlags |= CreateFlag::DebugProcess);
		inline auto &DebugOnlyThisProcess() ret_to_self(this->dwCreationFlags |= CreateFlag::DebugOnlyThisProcess);
		inline auto &Suspended() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateSuspended);
		inline auto &DetachedProcess() ret_to_self(this->dwCreationFlags |= CreateFlag::DetachedProcess);

		inline auto &NewConsole() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateNewConsole);
		inline auto &NormalPriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::NormalPriorityClass);
		inline auto &IdlePriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::IdlePriorityClass);
		inline auto &HighPriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::HighPriorityClass);

		inline auto &RealtimePriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::RealtimePriorityClass);
		inline auto &NewProcessGroup() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateNewProcessGroup);
		inline auto &UnicodeEnvironment() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateUnicodeEnvironment);
		inline auto &SeparateWowVdm() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateSeparateWowVdm);

		inline auto &SharedWowVdm() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateSharedWowVdm);
		inline auto &ForceDos() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateForceDos);
		inline auto &BelowNormalPriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::BelowNormalPriorityClass);
		inline auto &AboveNormalPriorityClass() ret_to_self(this->dwCreationFlags |= CreateFlag::AboveNormalPriorityClass);

		inline auto &InheritParentAffinity() ret_to_self(this->dwCreationFlags |= CreateFlag::InheritParentAffinity);
		inline auto &InheritCallerPriority() ret_to_self(this->dwCreationFlags |= CreateFlag::InheritCallerPriority);
		inline auto &ProtectedProcess() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateProtectedProcess);
		inline auto &ExtendedStartupInfoPresent() retself;

		inline auto &ProcessModeBackgroundBegin() ret_to_self(this->dwCreationFlags |= CreateFlag::ProcessModeBackgroundBegin);
		inline auto &ProcessModeBackgroundEnd() ret_to_self(this->dwCreationFlags |= CreateFlag::ProcessModeBackgroundEnd);
		inline auto &SecureProcess() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateSecureProcess);

		inline auto &BreakawayFromJob() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateBreakawayFromJob);
		inline auto &PreserveCodeAuthzLevel() ret_to_self(this->dwCreationFlags |= CreateFlag::CreatePreserveCodeAuthzLevel);
		inline auto &DefaultErrorMode() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateDefaultErrorMode);
		inline auto &NoWindow() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateNoWindow);

		inline auto &ProfileUser() ret_to_self(this->dwCreationFlags |= CreateFlag::ProfileUser);
		inline auto &ProfileKernel() ret_to_self(this->dwCreationFlags |= CreateFlag::ProfileKernel);
		inline auto &ProfileServer() ret_to_self(this->dwCreationFlags |= CreateFlag::ProfileServer);
		inline auto &IgnoreSystemDefault() ret_to_self(this->dwCreationFlags |= CreateFlag::CreateIgnoreSystemDefault);
	public:
		inline auto &StartupInfo(const WX::StartupInfo &si) ret_to_self(this->startupInfo = si, this->dwCreationFlags |= CreateFlag::ExtendedStartupInfoPresent);
		inline auto &CurrentDirectory(LPCTSTR lpCurrentDirectory) ret_to_self(this->lpCurrentDirectory = lpCurrentDirectory);
	public:
		inline auto &Create() ret_to(CreateProcess(
			lpApplicationName, lpCommandLine,
			lpProcessAttributes, lpThreadAttributes, bInheritHandles,
			dwCreationFlags.yield(), lpEnvironment, lpCurrentDirectory,
			&startupInfo, &processInfo), processInfo);
		inline operator Process() ret_as(processInfo.hProcess ? processInfo.hProcess : Create().hProcess);
		inline operator Thread() ret_as(processInfo.hProcess ? processInfo.hThread : Create().hThread);
	};
	static inline CreateStruct Create(LPCTSTR lpApplicationName, const String &CommandLine = O) ret_as({lpApplicationName, CommandLine});
	class OpenStruct {
		friend class Process;
		Access dwDesiredAccess = Access::All;
		bool bInheritHandle = false;
		DWORD dwProcessId;
		OpenStruct(DWORD dwProcessId) : dwProcessId(dwProcessId) {}
	public:
		inline auto &Accesses(Access dwDesiredAccess) ret_to_self(this->dwDesiredAccess = dwDesiredAccess);
		inline auto &Inherit(bool bInheritHandle = true) ret_to_self(this->bInheritHandle = bInheritHandle);
	public:
		inline operator Process() ret_as(OpenProcess(dwDesiredAccess.yield(), bInheritHandle, dwProcessId));
	};
	static inline OpenStruct Open(DWORD dwProcessId) ret_as(dwProcessId);
	static inline Process Current() ret_as(WX::GetCurrentProcess());
	static inline void Exit(UINT uExitCode = 0) ret_to(WX::ExitProcess(uExitCode));
public:
	inline void Terminate(UINT uExitCode = 0) {
		if (Super::hObject)
			TerminateProcess(Super::hObject, uExitCode);
		Super::hObject = O;
	}
#pragma region Properties
public: // Property - ExitCode
	/* R */ inline auto ExitCode() const ret_to(DWORD dwCode; WX::GetExitCodeProcess(self, &dwCode), dwCode);
public: // Property - ID
	/* R */ inline auto ID() const ret_as(WX::GetProcessId(self));
public: // Property - SysDPI
	/* R */ inline UINT SysDPI() const ret_as(WX::GetSystemDpiForProcess(self));
public: // Property - Memory
//	/* W */ inline auto Memory() const ret_to(PROCESS_MEMORY_COUNTERS pmc; GetProcessMemoryInfo(self, &pmc, sizeof(pmc)), pmc);
public: // Property - Times
	/* R */ inline auto Times() ret_to(PTTimes t; WX::GetProcessTimes(self, &t.CreationTime, &t.ExitTime, &t.KernelTime, &t.UserTime), t);
public: // Property - WorkingSetSize
	/* W */ inline auto &WorkingSetSize(SIZE_T Min, SIZE_T Max) safe_ret_as_self(SetProcessWorkingSetSize(self, Min, Max));
	/* R */ inline auto  WorkingSetSize() const safe_ret_to(struct mx_b2(SIZE_T Min, Max;) size, GetProcessWorkingSetSize(self, &size.Min, &size.Max), size);
public: // Property - HandleCount
	/* R */ inline DWORD HandleCount() const ret_to(DWORD dwHandleCount; GetProcessHandleCount(self, &dwHandleCount), dwHandleCount);
public: // Property - Immersive
	/* R */ inline bool Immersive() const ret_as(WX::IsImmersiveProcess(self));
#pragma endregion
public:
	using Super::operator=;
};
using CProcess = ProxyView<Process>;
#pragma endregion

// Property - CommandLine
template<bool IsUnicode = WX::IsUnicode>
/* R */ inline StringX<IsUnicode> CommandLine() ret_as(+CString(GetCommandLine<IsUnicode>(), 0x1ff));
/* R */ inline StringA CommandLineA() ret_as(CommandLine<false>());
/* R */ inline StringW CommandLineW() ret_as(CommandLine<true>());
// Property - Directory
template<class TCHAR>
/* W */ inline void CurrentDirectory(const TCHAR *lpPath) ret_to(SetCurrentDirectory(lpPath));
template<bool IsUnicode>
/* R */ inline StringX<IsUnicode> CurrentDirectory() {
	auto len = WX::GetCurrentDirectory(0, (LPXSTR<IsUnicode>)O);
	StringX<IsUnicode> str((SizeT)len);
	WX::GetCurrentDirectory(len, str);
	return right_hand_cast(str);
}
/* R */ inline StringA CurrentDirectoryA() ret_as(CurrentDirectory<false>());
/* R */ inline StringW CurrentDirectoryW() ret_as(CurrentDirectory<true>());
// Property - UserName
template<bool IsUnicode>
/* R */ inline StringX<IsUnicode> CurrentUserName() {
	DWORD len = 0;
	WX::GetUserName((LPXSTR<IsUnicode>)O, &len);
	StringX<IsUnicode> str((SizeT)len);
	WX::GetUserName(str, &len);
	return right_hand_cast(str);
}
inline StringA CurrentUserNameA() ret_as(CurrentUserName<false>());
inline StringW CurrentUserNameW() ret_as(CurrentUserName<true>());
// Property - ComputerName
template<bool IsUnicode>
/* R */ inline StringX<IsUnicode> CurrentComputerName() {
	DWORD len = 0;
	WX::GetComputerName((LPXSTR<IsUnicode>)O, &len);
	StringX<IsUnicode> str((SizeT)len);
	WX::GetComputerName(str, &len);
	return right_hand_cast(str);
}
/* R */ inline StringA CurrentComputerNameA() ret_as(CurrentComputerName<false>());
/* R */ inline StringW CurrentComputerNameW() ret_as(CurrentComputerName<true>());
// Property - ProcessID
/* R */ inline DWORD CurrentProcessID() ret_as(GetCurrentProcessId());
// Property - ThreadID
/* R */ inline DWORD CurrentThreadID() ret_as(GetCurrentThreadId());

}
#endif
