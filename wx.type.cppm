module;

#define WX_CPPM_TYPE
#include "wx_type"

export module wx.type;

import wx.win32;

#ifndef REMOVE_DEF_PROTO_API
namespace WX {

constexpr auto ThisFile = LiString("wx.type");

#pragma region DateTimeApi.h
#undef GetDateFormat
// GetDateFormat
inline int GetDateFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate)
	safe_ret_as(auto res = ::GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate); res > 0, res);
inline int GetDateFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCWSTR lpFormat, LPWSTR lpDateStr, int cchDate)
	safe_ret_as(auto res = ::GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate); res > 0, res);
#undef GetTimeFormat
// GetTimeFormat
inline int GetTimeFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime)
	safe_ret_as(auto res = ::GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); res > 0, res);
inline int GetTimeFormat(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, int cchTime)
	safe_ret_as(auto res = ::GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); res > 0, res);
#undef GetTimeFormatEx
// GetTimeFormatEx
inline int GetTimeFormat(LPCWSTR lpLocaleName, DWORD dwFlags, const SYSTEMTIME *lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, int cchTime)
	safe_ret_as(auto res = ::GetTimeFormatEx(lpLocaleName, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); res > 0, res);
#undef GetDateFormatEx
// GetDateFormatEx
inline int GetDateFormat(LPCWSTR lpLocaleName, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCWSTR lpFormat, LPWSTR lpDateStr, int cchDate, LPCWSTR lpCalendar)
	safe_ret_as(auto res = ::GetDateFormatEx(lpLocaleName, dwFlags, lpDate, lpFormat, lpDateStr, cchDate, lpCalendar); res > 0, res);
// GetDurationFormatEx - Deprecated
#pragma endregion

#pragma region HandleApi.h
wapi_reflect_bool(CloseHandle);
wapi_reflect_bool(DuplicateHandle);
// CompareObjectHandles
inline bool CompareObjectHandles(HANDLE hObject1, HANDLE hObject2)
	ret_as(::CompareObjectHandles(hObject1, hObject2));
wapi_reflect_bool(GetHandleInformation);
wapi_reflect_bool(SetHandleInformation);
#pragma endregion

}
#endif

export namespace WX {

#pragma region HandleBase
enum_flags(HandleAccess   , DWORD           ,
	       Delete         = DELETE          ,
	       ReadCtl        = READ_CONTROL    ,
	       WriteDAC       = WRITE_DAC       ,
	       WriteOwner     = WRITE_OWNER     ,
	       Sync           = SYNCHRONIZE     ,
	       GenericRead    = GENERIC_READ    ,
	       GenericWrite   = GENERIC_WRITE   ,
	       GenericExecute = GENERIC_EXECUTE ,
	       GenericAll     = GENERIC_ALL     );
template<class AnyChild>
class HandleBase;
using Handle = HandleBase<void>;
template<class AnyChild>
class HandleBase : public ChildBridge<AnyChild, HandleBase> {
protected:
	mutable HANDLE hObject = O;
public:
	using Access = HandleAccess;
protected:
	HandleBase(HANDLE h) : hObject(h) {}
	HandleBase(const HandleBase &h) : hObject(h.hObject) ret_to(h.hObject = O);
public:
	HandleBase() {}
	HandleBase(Nu) {}
	HandleBase(HandleBase &obj) : hObject(obj.hObject) ret_to(obj.hObject = O);
	HandleBase(HandleBase &&obj) : hObject(obj.hObject) ret_to(obj.hObject = O);
	~HandleBase() ret_to(Close());
public:
	inline void Close() ret_to(if (hObject) (WX::CloseHandle(hObject), hObject = O));
public:
	inline bool Compare(HANDLE h) const ret_as(WX::CompareObjectHandles(self, h));
	//inline auto CopyTo() {
	//		DuplicateHandle(GetCurrentProcess(), self, 
	//			_In_ HANDLE hTargetProcessHandle,
	//			_Outptr_ LPHANDLE lpTargetHandle,
	//			_In_ DWORD dwDesiredAccess,
	//			_In_ BOOL bInheritHandle,
	//			_In_ DWORD dwOptions
	//		);
	//}

	//class Duplication {
	//	using AnyAccess = typename Child::Access;
	//	HANDLE hSourceProcessHandle = GetCurrentProcess();
	//	HANDLE hSourceHandle;
	//	HANDLE hTargetProcessHandle;
	//	DWORD dwDesiredAccess;
	//	bool bInheritHandle = false;
	//	DWORD dwOptions = DUPLICATE_SAME_ACCESS;
	//public:
	//	Duplication(HANDLE hSourceHandle, HANDLE hTargetProcessHandle) :
	//		hSourceHandle(hSourceHandle),
	//		hTargetProcessHandle(hTargetProcessHandle) {}
	//public:
	//	inline auto &SourceProcess(HANDLE hSourceHandle) ret_to_self(this->hSourceHandle = hSourceHandle);
	//	inline auto &Accesses(AnyAccess acs) ret_to_self(this->dwDesiredAccess = acs.yield(), this->dwOptions &= ~DUPLICATE_SAME_ACCESS);
	//	inline auto &Inherit(bool bInheritHandle = true) ret_to_self(this->bInheritHandle = bInheritHandle);
	//public:
	//	inline operator Child() const safe_ret_to(
	//		HANDLE hTargetHandle = O,
	//		DuplicateHandle(
	//			hSourceProcessHandle, hSourceHandle,
	//			hTargetProcessHandle, &hTargetHandle,
	//			dwDesiredAccess, bInheritHandle,
	//			dwOptions), reuse_cast<Child>(hTargetHandle));
	//};
	//inline Duplication Duplicate(HANDLE hTargetProcessHandle) ret_as({ hObject, hTargetProcessHandle });

	//inline auto Wait(DWORD dwMillisecond = INFINITE) ret_as(::WaitForSingleObject)

public: // Property - Information
	/* W */ inline auto &Information(DWORD dwMask, DWORD dwFlags) ret_to_child(WX::SetHandleInformation(self, dwMask, dwFlags));
	/* R */ inline DWORD Information(DWORD dwMask) const ret_to(DWORD dwFlags = 0, WX::GetHandleInformation(self, &dwFlags), dwFlags &dwMask);
public: // Property - Inherit
	/* W */ inline auto &Inherit(bool bInherit) ret_to_child(Information(HANDLE_FLAG_INHERIT, bInherit ? HANDLE_FLAG_INHERIT : 0));
	/* R */ inline bool Inherit() const ret_as(Information(HANDLE_FLAG_INHERIT));
public: // Property - ProtectFromClose
	/* W */ inline auto &ProtectFromClose(bool bProtected) ret_to_child(Information(HANDLE_FLAG_PROTECT_FROM_CLOSE, bProtected ? HANDLE_FLAG_PROTECT_FROM_CLOSE : 0));
	/* R */ inline bool ProtectFromClose() const ret_as(Information(HANDLE_FLAG_PROTECT_FROM_CLOSE));

public:
	inline operator bool() const ret_as(hObject && hObject != INVALID_HANDLE_VALUE);
	inline operator HANDLE() const ret_as(hObject);
	inline operator const Handle() const ret_as(ref_cast<Handle>(self));
};
#pragma endregion

#pragma region Heaps
#pragma region Local
enum_flags(LocalAllocFlags, UINT          ,
		   Fixed          = LMEM_FIXED    ,
		   Modify         = LMEM_MODIFY   ,
		   Moveable       = LMEM_MOVEABLE ,
		   ZeroInit       = LMEM_ZEROINIT );
using LAF = LocalAllocFlags;
class Local {
public:
	using AllocFlags = LAF;
	static inline void *Alloc(SizeT size, LAF flags = LAF::Fixed) ret_to(auto ptr = LocalAlloc(flags.yield(), size), ptr);
	template<class AnyType>
	static inline AnyType *Alloc(LAF flags = LAF::Fixed) ret_to(auto ptr = (AnyType *)LocalAlloc(flags.yield(), sizeof(AnyType)), ptr);
	static inline void *Realloc(void *ptr, SizeT size, LAF flags = LAF::Fixed) ret_as(LocalReAlloc(ptr, size, flags.yield()));
	static inline void  Free(void *ptr) {
		if (ptr)
			nt_assert(!LocalFree(ptr));
	}
	static inline void *Lock(void *ptr) ret_as(LocalLock(ptr));
	static inline void Unlock(void *ptr) safe_ret_as(LocalUnlock(ptr));
	static inline void AutoFree(void *&ptr) ret_to(if (ptr) (Free(ptr), ptr = O));
} inline LocalHeap;
#pragma endregion

#pragma region Heap

proxy_struct       (HeapSummaries, HEAP_SUMMARY        ) {
	proxy_prop_size(               cb           , DWORD);
	proxy_prop_sync(Allocated    , cbAllocated  , SizeT);
	proxy_prop_sync(Committed    , cbCommitted  , SizeT);
	proxy_prop_sync(Reserved     , cbReserved   , SizeT);
	proxy_prop_sync(MaxReserve   , cbMaxReserve , SizeT);
};
enum_flags(HeapAllocFlag      , UINT                     ,
		   Fixed              = 0                        ,
		   GenerateExceptions = HEAP_GENERATE_EXCEPTIONS ,
		   NoSerialize        = HEAP_NO_SERIALIZE        ,
		   ZeroInit           = HEAP_ZERO_MEMORY         );
using HAF = HeapAllocFlag;
class BaseOf_Handle(Heap) {
public:
	using Super = HandleBase<Heap>;
	using AllocFlags = HeapAllocFlag;
protected:
	friend_to_proxy(Heap);
	Heap(HANDLE hHeap) : Super(hHeap) {}
public:
	Heap() : Super(GetProcessHeap()) {}
	Heap(Nu) {}
	Heap(Heap & h) : Super(h) {}
	Heap(Heap && h) : Super(h) {}
	Heap(const Heap &) = delete;
	~Heap() ret_to(Destroy());
public:
	class CreateStruct {
		DWORD flOptions = 0;
		SIZE_T dwInitialSize = 0;
		SIZE_T dwMaximumSize = 0;
	public:
		CreateStruct() {}
	public:
		inline auto &MaximumSize(SIZE_T dwMaximumSize) ret_to_self(this->dwMaximumSize = dwMaximumSize);
		inline auto &InitialSize(SIZE_T dwInitialSize) ret_to_self(this->dwInitialSize = dwInitialSize);
		inline auto &Excutable() ret_to_self(this->flOptions |= HEAP_CREATE_ENABLE_EXECUTE);
		inline auto &GenerateException() ret_to_self(this->flOptions |= HEAP_GENERATE_EXCEPTIONS);
		inline auto &NoSerialize() ret_to_self(this->flOptions |= HEAP_NO_SERIALIZE);
	public:
		inline operator Heap() ret_as(HeapCreate(flOptions, dwInitialSize, dwMaximumSize));
	};
	static inline CreateStruct Create() ret_as({});
public:
	//	DWORD GetProcessHeaps(_In_ DWORD NumberOfHeaps, _Out_writes_to_(NumberOfHeaps, return) PHANDLE ProcessHeaps);
	inline bool Destroy() {
		if (Super::hObject && Super::hObject != GetProcessHeap())
			if (!HeapDestroy(Super::hObject))
				return false;
		Super::hObject = O;
		return true;
	}
	inline void *Alloc(SizeT size, AllocFlags flags = AllocFlags::Fixed) safe_ret_as(auto h = HeapAlloc(self, flags.yield(), size), h);
	inline void *Realloc(void *ptr, SizeT nSize, DWORD flags = 0) safe_ret_as((ptr = HeapReAlloc(self, flags, ptr, nSize)), ptr);
	inline bool Free(void *ptr, DWORD flags = 0) ret_as(HeapFree(self, flags, ptr));
	inline SizeT Size(const void *ptr, DWORD flags) const safe_ret_as(auto size = HeapSize(self, flags, ptr), size);
	inline bool IsValid(const void *ptr, DWORD flags) const ret_as(HeapValidate(self, flags, ptr));
	inline auto &Lock() safe_ret_as_self(HeapLock(self));
	inline auto &Unlock() safe_ret_as_self(HeapUnlock(self));
	//	HeapWalk();
	//	SIZE_T HeapCompact(HANDLE hHeap, DWORD dwFlags);
public: // Property - Summaries
	//inline HeapSummaries Summaries(DWORD dwFlags = 0) const safe_ret_to(HeapSummaries s, ::HeapSummary(self, dwFlags, &s), s);
	//BOOL HeapSetInformation(
	//	_In_opt_ HANDLE HeapHandle,
	//	_In_ HEAP_INFORMATION_CLASS HeapInformationClass,
	//	_In_reads_bytes_opt_(HeapInformationLength) PVOID HeapInformation,
	//	_In_ SIZE_T HeapInformationLength);
	//BOOL HeapQueryInformation(
	//	_In_opt_ HANDLE HeapHandle,
	//	_In_ HEAP_INFORMATION_CLASS HeapInformationClass,
	//	_Out_writes_bytes_to_opt_(HeapInformationLength, *ReturnLength) PVOID HeapInformation,
	//	_In_ SIZE_T HeapInformationLength,
	//	_Out_opt_ PSIZE_T ReturnLength);
	using Super::operator=;
};
using CHeap = ProxyView<Heap>;
CHeap ThisHeap = Heap{};
#pragma endregion

template<class HeapType, class AnyType = void>
class AutoPointer {
	HeapType &heap;
	mutable AnyType *p = O;
public:
	using AllocFlags = typename HeapType::AllocFlags;
	AutoPointer() : heap(ThisHeap) {}
	explicit AutoPointer(SizeT size) : heap(ThisHeap), p(heap.Alloc(size)) {}
	AutoPointer(AllocFlags flags, SizeT size = SizeOf<AnyType>) : heap(ThisHeap), p((AnyType *)heap.Alloc(size, flags)) {}
	explicit AutoPointer(HeapType &heap) : heap(heap) {}
	~AutoPointer() ret_to(Free());
public:
	inline AnyType *Alloc(SizeT size = SizeOf<AnyType>) {
		if (size <= 0)
			Free();
		return (AnyType *)(p ? heap.Realloc(p, size) : heap.Alloc(size));
	}
	template<class AnyFlags>
	inline AnyType *Alloc(SizeT size, AnyFlags flags) {
		return (AnyType *)(p ? heap.Realloc(p, size, flags) : heap.Alloc(size, flags));
	}
	inline void Free() {
		if (p)
			heap.Free(p);
		p = O;
	}
public:
	inline AnyType *&operator*() ret_as(p);
	inline const AnyType *&operator*() const ret_as(p);
	inline AnyType *operator&() ret_as(p);
	inline const AnyType *operator&() const ret_as(p);
	inline AnyType *operator->() ret_as(p);
	inline const AnyType *operator->() const ret_as(p);
};
template<class AnyType = void>
using LocalPointer = AutoPointer<Local, AnyType>;
template<class AnyType = void>
using HeapPointer = AutoPointer<Heap, AnyType>;
#pragma endregion

#pragma region Time Types
enum_class(Locales                , LCID                      ,
		   Default                = LOCALE_CUSTOM_DEFAULT     ,
		   Unspecified            = LOCALE_CUSTOM_UNSPECIFIED ,
		   UIDefault              = LOCALE_CUSTOM_UI_DEFAULT  ,
		   Neutral                = LOCALE_NEUTRAL            ,
		   Invariant              = LOCALE_INVARIANT          );
enum_flags(TimeFormat             , DWORD                     ,
		   Default                = 0                         ,
		   NoMinutesOrSeconds     = TIME_NOMINUTESORSECONDS   ,
		   NoSecond               = TIME_NOSECONDS            ,
		   NoTimeMarker           = TIME_NOTIMEMARKER         ,
		   Force24H               = TIME_FORCE24HOURFORMAT    );
enum_flags(DateFormat             , DWORD                     ,
		   Default                = 0                         ,
		   ShortDate              = DATE_SHORTDATE            ,
		   LongDate               = DATE_LONGDATE             ,
		   UseAltCalendar         = DATE_USE_ALT_CALENDAR     ,
		   YearMonth              = DATE_YEARMONTH            ,
		   LTRReading             = DATE_LTRREADING           ,
		   RTLReading             = DATE_RTLREADING           ,
		   AutoLayout             = DATE_AUTOLAYOUT           ,
		   MonthDay               = DATE_MONTHDAY             );
proxy_struct(SystemTime, SYSTEMTIME) {
	SystemTime(Nu) {}
	SystemTime() ret_to(GetSystemTime(&self));
	SystemTime(const SYSTEMTIME &st) : Super(st) {}
public:
	proxy_prop_sync(Year         , wYear         , WORD);
	proxy_prop_sync(Month        , wMonth        , WORD);
	proxy_prop_sync(Day          , wDay          , WORD);
	proxy_prop_sync(Hour         , wHour         , WORD);
	proxy_prop_sync(Minute       , wMinute       , WORD);
	proxy_prop_sync(Second       , wSecond       , WORD);
	proxy_prop_sync(MilliSeconds , wMilliseconds , WORD);
public:
	static inline SystemTime LocalTime() ret_to(SystemTime st; GetLocalTime(&st), st);
public: // FormatDate
	template<bool IsUnicode = WX::IsUnicode>
	inline StringX<IsUnicode> FormatDate(Locales locale = Locales::Default, DateFormat df = DateFormat::Default, LPCXSTR<IsUnicode> lpFormat = O) const {
		int len = WX::GetDateFormat(locale.yield(), df.yield(), &self, lpFormat, O, 0);
		StringX<IsUnicode> str((SizeT)len - 1);
		WX::GetDateFormat(locale.yield(), df.yield(), &self, lpFormat, str, len);
		return right_cast(str);
	}
	inline StringA FormatDate(Locales locale, DateFormat df, LPCSTR lpFormat) const ret_as(FormatDate<false>(locale, df, lpFormat));
	inline StringW FormatDate(Locales locale, DateFormat df, LPCWSTR lpFormat) const ret_as(FormatDate<true>(locale, df, lpFormat));
	inline StringA FormatDateA(Locales locale = Locales::Default, DateFormat df = DateFormat::Default, LPCSTR lpFormat = O) const ret_as(FormatDate<false>(locale, df, lpFormat));
	inline StringW FormatDateW(Locales locale = Locales::Default, DateFormat df = DateFormat::Default, LPCWSTR lpFormat = O) const ret_as(FormatDate<true>(locale, df, lpFormat));
	inline StringW FormatDate(LPCWSTR lpLocaleName, DateFormat df = DateFormat::Default, LPCWSTR lpFormat = O) const {
		int len = WX::GetDateFormat(lpLocaleName, df.yield(), &self, lpFormat, O, 0, O);
		StringW str((SizeT)len - 1);
		WX::GetDateFormat(lpLocaleName, df.yield(), &self, lpFormat, str, len, O);
		return right_cast(str);
	}
public: // FormatTime
	template<bool IsUnicode = WX::IsUnicode>
	inline StringX<IsUnicode> FormatTime(Locales locale = Locales::Default, TimeFormat tf = TimeFormat::Default, LPCXSTR<IsUnicode> lpFormat = O) const {
		int len = WX::GetTimeFormat(locale.yield(), tf.yield(), &self, lpFormat, O, 0);
		StringX<IsUnicode> str((SizeT)len - 1);
		GetTimeFormat(locale.yield(), tf.yield(), &self, lpFormat, str, len);
		return right_cast(str);
	}
	inline StringA FormatTime(Locales locale, TimeFormat tf, LPCSTR lpFormat) const ret_as(FormatTime<false>(locale, tf, lpFormat));
	inline StringW FormatTime(Locales locale, TimeFormat tf, LPCWSTR lpFormat) const ret_as(FormatTime<true>(locale, tf, lpFormat));
	inline StringA FormatTimeA(Locales locale = Locales::Default, TimeFormat tf = TimeFormat::Default, LPCSTR lpFormat = O) const ret_as(FormatTime<false>(locale, tf, lpFormat));
	inline StringW FormatTimeW(Locales locale = Locales::Default, TimeFormat tf = TimeFormat::Default, LPCWSTR lpFormat = O) const ret_as(FormatTime<true>(locale, tf, lpFormat));
	inline StringW FormatTime(LPCWSTR lpLocaleName, TimeFormat tf = TimeFormat::Default, LPCWSTR lpFormat = O) const {
		int len = WX::GetTimeFormat(lpLocaleName, tf.yield(), &self, lpFormat, O, 0);
		StringW str((SizeT)len - 1);
		WX::GetTimeFormat(lpLocaleName, tf.yield(), &self, lpFormat, str, len);
		return right_cast(str);
	}
public:
	template<bool IsUnicode = WX::IsUnicode>
	inline StringX<IsUnicode> toString() const {
		int lenDate = WX::GetDateFormat(LOCALE_CUSTOM_DEFAULT, 0, &self, (LPCXSTR<IsUnicode>)O, O, 0),
			lenTime = WX::GetTimeFormat(LOCALE_CUSTOM_DEFAULT, 0, &self, (LPCXSTR<IsUnicode>)O, O, 0);
		StringX<IsUnicode> str((SizeT)lenDate + lenTime - 1);
		WX::GetDateFormat(LOCALE_CUSTOM_DEFAULT, 0, &self, O, str, lenDate);
		WX::GetTimeFormat(LOCALE_CUSTOM_DEFAULT, 0, &self, O, ((LPXSTR<IsUnicode>)str) + lenDate, lenTime);
		str[lenDate - 1] = ' ';
		return right_cast(str);
	}
	inline StringA toStringA() const ret_as(toString<false>());
	inline StringW toStringW() const ret_as(toString<true>());

public:
	inline operator FILETIME() const safe_ret_to(FILETIME ft, SystemTimeToFileTime(&self, &ft), ft);
};
alias_of_type(SysTime, SystemTime);
proxy_struct(FileTime, FILETIME) {
	FileTime(Nu) {}
	FileTime() {}
	FileTime(const FILETIME &ft) : Super(ft) {}
	FileTime(const SYSTEMTIME &st) nt_assert(SystemTimeToFileTime(&st, &self));
	FileTime(LARGE_INTEGER li) : Super(reuse_cast<FILETIME>(li)){}
public:
	static inline FileTime SystemTime() ret_to(FileTime ft; GetSystemTimeAsFileTime(&ft), ft);
public:
	inline FileTime ToLocal() safe_ret_to(FILETIME ft, FileTimeToLocalFileTime(&self, &ft), ft);
	inline FileTime ToUniversal() safe_ret_to(FILETIME ft, LocalFileTimeToFileTime(&self, &ft), ft);
public:
	template<bool IsUnicode = WX::IsUnicode>
	inline StringX<IsUnicode> toString() const ret_as(((SysTime)self).toString<IsUnicode>());
	inline StringA toStringA() const ret_as(toString<false>());
	inline StringW toStringW() const ret_as(toString<true>());

public:
	inline operator SYSTEMTIME() const safe_ret_to(SYSTEMTIME st, FileTimeToSystemTime(&self, &st), st);
	inline operator LARGE_INTEGER() const ret_as(reuse_cast<LARGE_INTEGER>(self));
};
#pragma endregion

#pragma region Point Size Rect
struct LPoint : public POINT {
public:
	LPoint() : POINT{ 0 } {}
	LPoint(const POINT &p) : POINT(p) {}
	LPoint(const LPoint &p) : POINT(p) {}
	LPoint(LONG a) : POINT{ a, a } {}
	LPoint(LONG x, LONG y) : POINT{ x, y } {}
	LPoint(const SIZE &s) : POINT{ s.cx, s.cy } {}
	LPoint(COORD c) : POINT{ c.X, c.Y } {}
public:
	template<bool IsUnicode>
	inline StringX<IsUnicode> toString() const {
		auto_stringx(fmt, "{ x: %d, y: %d }");
		return format(fmt, x, y);
	}
	inline StringA toStringA() const ret_as(toString<false>());
	inline StringW toStringW() const ret_as(toString<true>());
public:
	inline operator LPARAM() const ret_as((LPARAM)this);
	inline operator COORD() const ret_as({ (SHORT)x, (SHORT)y });
	inline operator SIZE() const ret_as({ x, y });
	inline LPoint  operator+ () const retself;
	inline LPoint  operator~ () const ret_as({ y,  x });
	inline LPoint  operator* (double l) const ret_as({ LONG((double)x * l), LONG((double)y * l) });
	inline LPoint  operator/ (double l) const ret_as({ LONG((double)x / l), LONG((double)y / l) });
	inline LPoint  operator* (int l) const ret_as({ x * l, y * l });
	inline LPoint  operator/ (int l) const ret_as({ x / l, y / l });
	inline LPoint  operator- () const ret_as({ -x, -y });
	inline LPoint  operator+ (POINT s) const ret_as({ x + s.x, y + s.y });
	inline LPoint  operator- (POINT s) const ret_as({ x - s.x, y - s.y });
	inline LPoint &operator*=(double p) ret_to_self(x = LONG((double)x * p), y = LONG((double)y * p));
	inline LPoint &operator/=(double p) ret_to_self(x = LONG((double)x / p), y = LONG((double)y / p));
	inline LPoint &operator+=(POINT p) ret_to_self(x += p.x, y += p.y);
	inline LPoint &operator-=(POINT p) ret_to_self(x -= p.x, y -= p.y);
	inline LPoint &operator =(POINT p) ret_to_self(x = p.x, y = p.y);
	inline bool    operator==(POINT pt) const ret_as(pt.x == x && pt.y == y);
	inline bool    operator!=(POINT pt) const ret_as(pt.x != x || pt.y != y);
};
struct LSize : public SIZE {
public:
	LSize() : SIZE{ 0 } {}
	LSize(const SIZE &s) : SIZE(s) {}
	LSize(const LSize &s) : SIZE(s) {}
	LSize(LONG c) : SIZE{ c, c } {}
	LSize(LONG cx, LONG cy) : SIZE{ cx, cy } {}
	LSize(COORD c) : SIZE{ c.X, c.Y } {}
	LSize(POINT p) : SIZE{ p.x, p.y } {}
public:
	inline auto Square() const ret_as(cx * cy);
public:
	template<bool IsUnicode>
	inline StringX<IsUnicode> toString() const {
		auto_stringx(fmt, "{ cx: %d, cy: %d }");
		return format(fmt, cx, cy);
	}
	inline StringA toStringA() const ret_as(toString<false>());
	inline StringW toStringW() const ret_as(toString<true>());
public:
	inline operator LPARAM() const ret_as((LPARAM)this);
	inline operator COORD() const ret_as({ (SHORT)cx, (SHORT)cy });
	inline LSize  operator+ () const retself;
	inline LSize  operator- () const ret_as({ -cx, -cy });
	inline LSize  operator~ () const ret_as({ cy,  cx });
	inline LSize  operator* (double l) const ret_as({ LONG((double)cx * l), LONG((double)cy * l) });
	inline LSize  operator/ (double l) const ret_as({ LONG((double)cx / l), LONG((double)cy / l) });
	inline LSize  operator* (int l) const ret_as({ cx * l, cy * l });
	inline LSize  operator/ (int l) const ret_as({ cx / l, cy / l });
	inline LSize  operator+ (const LSize &s) const ret_as({ cx + s.cx, cy + s.cy });
	inline LSize  operator- (const LSize &s) const ret_as({ cx - s.cx, cy - s.cy });
	inline LSize &operator*=(double p) ret_to_self(cx = LONG((double)cx * p), cy = LONG((double)cy * p));
	inline LSize &operator/=(double p) ret_to_self(cx = LONG((double)cx / p), cy = LONG((double)cy / p));
	inline LSize &operator+=(const LSize &p) ret_to_self(cx += p.cx, cy += p.cy);
	inline LSize &operator-=(const LSize &p) ret_to_self(cx -= p.cx, cy -= p.cy);
	inline LSize &operator =(const LSize &p) ret_to_self(cx = p.cx, cy = p.cy);
	inline bool   operator==(LSize sz) const ret_as(sz.cx == cx && sz.cy == cy);
	inline bool   operator!=(LSize sz) const ret_as(sz.cx != cx || sz.cy != cy);
};
enum_flags(LAlign   , BYTE   ,
		   Left     = 1 << 0 ,
		   Right    = 2 << 0 ,
		   HCenter  = 3 << 0 ,
		   Top      = 1 << 2 ,
		   Bottom   = 2 << 2 ,
		   VCenter  = 3 << 2 );
struct LRect : public RECT { 
public:
	LRect() : RECT{ 0 } {}
	LRect(const RECT &rc) : RECT(rc) {}
	LRect(const LRect &rc) : RECT(rc) {}
	LRect(LONG a) : RECT{ a, a, a, a } {}
	LRect(LONG left, LONG top, LONG right, LONG bottom) : RECT{ left, top, right, bottom } {}
//	LRect(const MARGINS &m) : RECT({ m.cxLeftWidth, m.cyTopHeight, m.cxRightWidth, m.cyBottomHeight }) {}
	LRect(SMALL_RECT s) : RECT{ s.Left, s.Top, s.Right, s.Bottom } {}
	LRect(SIZE sz) : RECT{ 0, 0, sz.cx - 1, sz.cy - 1 } {}
	LRect(POINT p0,  POINT p1) : RECT{ p0.x, p0.y, p1.x, p1.y } {}
public:
	static inline LRect left_top(LPoint lt, LSize sz) ret_as({ lt.x, lt.y, lt.x + sz.cx - 1, lt.y + sz.cy - 1 });
public:
	inline auto xsize() const ret_as(right - left + 1);
	inline auto ysize() const ret_as(bottom - top + 1);
	inline LSize size() const ret_as({ xsize(), ysize() });
	inline auto  dx() const ret_as(right - left);
	inline auto  dy() const ret_as(bottom - top);
	inline LSize d() const ret_as({ dx(), dy() });
	inline auto &xmove(LONG dx) ret_to_self(right += dx, left += dx);
	inline auto &ymove(LONG dy) ret_to_self(bottom += dy, top += dy);
	LRect &align(LAlign a, const LRect &r2) {
		if (a == LAlign::HCenter)
			xmove((r2.left + r2.right - left - right) / 2);
		elif (a <= LAlign::Right) {
			left += r2.right - right;
			right = r2.right;
		}
		else /* if (a <= LAlign::Left) */ {
			right += r2.left - left;
			left = r2.left;
		}
		if (a == LAlign::VCenter)
			ymove((r2.top + r2.bottom - top - bottom) / 2);
		elif (a <= LAlign::Bottom) {
			top += r2.bottom - bottom;
			bottom = r2.bottom;
		}
		else /* if (a & LAlign::Top) */ {
			bottom += r2.top - top;
			top = r2.top;
		}
		retself;
	}
public:
	inline auto x0() const ret_as(left);
	inline auto y0() const ret_as(top);
	inline auto x1() const ret_as(right);
	inline auto y1() const ret_as(bottom);
public:
	template<bool IsUnicode>
	inline StringX<IsUnicode> toString() const {
		auto_stringx(fmt, "{ left: %d, top: %d, right: %d, bottom: %d }");
		return format(fmt, left, top, right, bottom);
	}
	inline StringA toStringA() const ret_as(toString<false>());
	inline StringW toStringW() const ret_as(toString<true>());
public: // Property - left_top
	inline LPoint left_top()     const ret_as({ left,  top });
	inline auto   &left_top(LPoint lt) ret_to_self(left = lt.x, top = lt.y);
public: // Property - left_bottom
	inline LPoint left_bottom()    const ret_as({ left,  bottom });
	inline auto  &left_bottom(LPoint lt) ret_to_self(left = lt.x, bottom = lt.y);
public: // Property - right_top
	inline LPoint right_top()    const ret_as({ right, top });
	inline auto  &right_top(LPoint rt) ret_to_self(right = rt.x, top = rt.y);
public: // Property - right_bottom
	inline LPoint right_bottom() const ret_as({ right, bottom });
	inline auto  &right_bottom(LPoint rb) ret_to_self(right = rb.x, bottom = rb.y);
public:
	inline operator StringA() const ret_as(toStringA());
	inline operator StringW() const ret_as(toStringW());
	inline operator SIZE()   const ret_as({ right - left + 1, bottom - top + 1 });
	inline operator LSize()   const ret_as({ right - left + 1, bottom - top + 1 });
	inline operator LPRECT()        ret_as(this);
	inline operator LPCRECT() const ret_as(this);
	inline operator LPARAM()  const ret_as((LPARAM)this);
//	inline operator MARGINS() const ret_as({ left, right, top, bottom });
	inline operator SMALL_RECT() const ret_as({ (SHORT)left, (SHORT)top, (SHORT)right, (SHORT)bottom });
	inline LRect  operator+ () const retself;
	inline LRect  operator- () const ret_as({ -left,   -top, -right, -bottom });
	inline LRect  operator~ () const ret_as({ right, bottom,   left,     top });
	inline LRect  operator+ (const RECT &r) const ret_as({ left + r.left, top + r.top, right + r.right, bottom + r.bottom });
	inline LRect  operator- (const RECT &r) const ret_as({ left - r.left, top - r.top, right - r.right, bottom - r.bottom });
	inline LRect  operator+ (POINT p) const ret_as({ left + p.x, top + p.y, right + p.x, bottom + p.y });
	inline LRect  operator- (POINT p) const ret_as({ left - p.x, top - p.y, right - p.x, bottom - p.y });
	inline LRect  operator* (double l) const ret_as({ LONG((double)left * l), LONG((double)top * l), LONG((double)right * l), LONG((double)bottom * l) });
	inline LRect  operator/ (double l) const ret_as({ LONG((double)left / l), LONG((double)top / l), LONG((double)right / l), LONG((double)bottom / l) });
	inline LRect  operator* (int l ) const ret_as({ left * l, top * l, right * l, bottom * l });
	inline LRect  operator/ (int l) const ret_as({ left / l, top / l, right / l, bottom / l });
	inline LRect &operator*=(double l) ret_to_self(left = LONG((double)left * l), top = LONG((double)top * l), right = LONG((double)right * l), bottom = LONG((double)bottom * l));
	inline LRect &operator/=(double l) ret_to_self(left = LONG((double)left / l), top = LONG((double)top / l), right = LONG((double)right / l), bottom = LONG((double)bottom / l));
	inline LRect &operator/=(int l) ret_to_self(left /= l, top /= l, right /= l, bottom /= l);
	inline LRect &operator*=(int l) ret_to_self(left *= l; top *= l, right *= l, bottom *= l);
	inline LRect &operator+=(const RECT &r) ret_to_self(left += r.left, top += r.top, right += r.right, bottom += r.bottom);
	inline LRect &operator-=(const RECT &r) ret_to_self(left -= r.left, top -= r.top, right -= r.right, bottom -= r.bottom);
	inline LRect &operator+=(POINT p) ret_to_self(left += p.x, top += p.y, right += p.x, bottom += p.y);
	inline LRect &operator-=(POINT p) ret_to_self(left -= p.x, top -= p.y, right -= p.x, bottom -= p.y);
};
inline LRect operator+(LPoint p, const LRect &r) ret_as(r + p);
inline LRect operator-(LPoint p, const LRect &r) ret_as(-(r - p));
#pragma endregion

#pragma region Message Wrapper
proxy_struct(Message, MSG) {
	Message() {}
	Message(const MSG &msg) : Super(msg) {}
	Message(HWND hwnd, UINT  message, WPARAM wParam, LPARAM lParam) : Super(MSG{ hwnd, message, wParam, lParam }) {}
public: // Property - Window
	/* W */ inline auto&Window(HWND hwnd) ret_as(self->hwnd);
public: // Property - ID
	proxy_prop_set(ID,message,UINT);
	template<class AnyEnum = UINT>
	/* R */ inline AnyEnum ID() const ret_as(reuse_cast<AnyEnum>(self->message));
public: // Property - ParamW
	template<class AnyType = WPARAM>
	/* W */ inline auto&ParamW(AnyType wParam) ret_to_self(self->wParam = small_cast<WPARAM>(wParam));
	template<class AnyType = WPARAM>
	/* R */ inline AnyType ParamW() const ret_as(big_cast<AnyType>(self->wParam));
public: // Property - ParamL
	template<class AnyType = WPARAM>
	/* W */ inline auto&ParamL(AnyType lParam) ret_to_self(self->lParam = small_cast<LPARAM>(lParam));
	template<class AnyType = WPARAM>
	/* R */ inline AnyType ParamL() const ret_as(big_cast<AnyType>(self->lParam));
public: // Property - Param
	template<class WParam = WPARAM, class LParam = LPARAM>
	/* W */ inline auto&Param(WParam wParam, LParam lParam) ret_to_self(self->wParam = small_cast<WPARAM>(wParam), self->lParam = small_cast<LPARAM>(lParam));
	proxy_prop_sync(Time,time,DWORD);
	inline auto &Point(POINT value) {
		(*this)->pt = (POINT)value; return (*this);
	} inline auto Point() const {
		return safe_c_cast<LPoint>((*this)->pt);
	};
public:
	inline bool Translate() const ret_as(WX::TranslateMessage(&self));
public:
	template<class RetType = LRESULT, bool IsUnicode = WX::IsUnicode>
	inline RetType Dispatch() const ret_as((RetType)DispatchMessage<IsUnicode>(&self));
public:
	template<class RetType = LRESULT, bool IsUnicode = WX::IsUnicode>
	inline RetType Send() const ret_as((RetType)SendMessage<IsUnicode>(self->hwnd, self->message, self->wParam, self->lParam));
public:
	template<bool IsUnicode = WX::IsUnicode>
	inline void Post() ret_to(WX::PostMessage<IsUnicode>(self->hwnd, self->message, self->wParam, self->lParam));
public:
	template<bool IsUnicode = WX::IsUnicode>
	inline bool Get(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, O, wMsgFilterMin, wMsgFilterMax));
	template<bool IsUnicode = WX::IsUnicode>
	inline bool Get(HWND hwnd, UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, hwnd, wMsgFilterMin, wMsgFilterMax));
	template<bool IsUnicode = WX::IsUnicode>
	inline bool GetThread(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, (HWND)-1, wMsgFilterMin, wMsgFilterMax));
public:
	template<bool IsUnicode = WX::IsUnicode>
	inline bool GetSafe(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, O, wMsgFilterMin, wMsgFilterMax));
	template<bool IsUnicode = WX::IsUnicode>
	inline bool GetSafe(HWND hwnd, UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, hwnd, wMsgFilterMin, wMsgFilterMax));
	template<bool IsUnicode = WX::IsUnicode>
	inline bool GetThreadSafe(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as(WX::GetMessage<IsUnicode>(&self, (HWND)-1, wMsgFilterMin, wMsgFilterMax));
public:
	class Peeks {
		LPMSG lpMsg;
		HWND hwnd;
		UINT wMsgFilterMin;
		UINT wMsgFilterMax;
		UINT wRemoveMsg = PM_NOREMOVE;
	public:
		Peeks(LPMSG lpMsg, HWND hwnd, UINT wMsgFilterMin, UINT wMsgFilterMax) :
			lpMsg(lpMsg), hwnd(hwnd), wMsgFilterMin(wMsgFilterMin), wMsgFilterMax(wMsgFilterMax) {}
	public:
		inline auto&Remove() ret_to_self(this->wRemoveMsg |= PM_REMOVE);
		inline auto&NoYield() ret_to_self(this->wRemoveMsg |= PM_NOYIELD);
		inline auto&Input() ret_to_self(this->wRemoveMsg |= PM_QS_INPUT);
		inline auto&Paint() ret_to_self(this->wRemoveMsg |= PM_QS_PAINT);
		inline auto&MessagePost() ret_to_self(this->wRemoveMsg |= PM_QS_POSTMESSAGE);
		inline auto&MessageSend() ret_to_self(this->wRemoveMsg |= PM_QS_SENDMESSAGE);
	public:
		inline operator bool() ret_as(WX::PeekMessage<IsUnicode>(lpMsg, hwnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg));
	};
	inline Peeks Peek(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as({ &self, O, wMsgFilterMin, wMsgFilterMax });
	inline Peeks Peek(HWND hwnd, UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as({ &self, hwnd, wMsgFilterMin, wMsgFilterMax });
	inline Peeks PeekThread(UINT wMsgFilterMin = 0, UINT wMsgFilterMax = 0) ret_as({ &self, (HWND)-1, wMsgFilterMin, wMsgFilterMax });
};
alias_of_type(Msg, Message);
class MessageException : public Exception {
	Message msg;
public:
	using Super = Exception;
public:
	MessageException(const Exception &err, const Message &msg) : 
		Super(err), msg(msg) {}
public:
	inline const WX::Msg &Msg() const ret_as(msg);
	inline const WX::Msg &Message() const ret_as(msg);
public:
	inline operator const WX::Msg &() const ret_as(msg);
};
alias_of_type(MsgException, MessageException);
#pragma endregion

#pragma region MsgBox
enum_flags(MB, int,
	Ok                  = MB_OK,
	OkCancel            = MB_OKCANCEL,
	AbortRetryIgnore    = MB_ABORTRETRYIGNORE,
	YesNoCancel         = MB_YESNOCANCEL,
	YesNo               = MB_YESNO,
	RetryCancel         = MB_RETRYCANCEL,
	CancelTryContinue   = MB_CANCELTRYCONTINUE,
	IconHand            = MB_ICONHAND,
	IconQuestion        = MB_ICONQUESTION,
	IconExclamation     = MB_ICONEXCLAMATION,
	IconAsterisk        = MB_ICONASTERISK,
	UserIcon            = MB_USERICON,
	IconWarning         = MB_ICONWARNING,
	IconError           = MB_ICONERROR,
	IconInformation     = MB_ICONINFORMATION,
	IconStop            = MB_ICONSTOP,
	DefButton1          = MB_DEFBUTTON1,
	DefButton2          = MB_DEFBUTTON2,
	DefButton3          = MB_DEFBUTTON3,
	DefButton4          = MB_DEFBUTTON4,
	ApplModal           = MB_APPLMODAL,
	SystemModal         = MB_SYSTEMMODAL,
	TaskModal           = MB_TASKMODAL,
	Help                = MB_HELP,
	NoFocus             = MB_NOFOCUS,
	SetForeground       = MB_SETFOREGROUND,
	DefaultDesktopOnly  = MB_DEFAULT_DESKTOP_ONLY,
	TopMost             = MB_TOPMOST,
	Right               = MB_RIGHT,
	RtlReading          = MB_RTLREADING,
	ServiceNotification = MB_SERVICE_NOTIFICATION);
inline auto MsgBox(LPCSTR lpCaption, LPCSTR lpText = O, MB type = MB::Ok, HWND hParent = O)
	ret_as(WX::MessageBox(hParent, lpText, lpCaption, type.yield()));
inline auto MsgBox(LPCWSTR lpCaption = O, LPCWSTR lpText = O, MB type = MB::Ok, HWND hParent = O)
	ret_as(WX::MessageBox(hParent, lpText, lpCaption, type.yield()));
inline int MsgBox(LPCSTR lpCaption, const Exception &err, HWND hParent = O)
	ret_as(MsgBox(lpCaption, toStringA(err), MB::IconError | MB::AbortRetryIgnore, hParent));
inline int MsgBox(LPCWSTR lpCaption, const Exception &err, HWND hParent = O)
	ret_as(MsgBox(lpCaption, toStringW(err), MB::IconError | MB::AbortRetryIgnore, hParent));
#pragma endregion

enum_class(WindowShowFlags  , int                ,
		   Hide             = SW_HIDE            ,
		   ShowNormal       = SW_SHOWNORMAL      ,
		   Normal           = SW_NORMAL          ,
		   ShowMinimized    = SW_SHOWMINIMIZED   ,
		   ShowMaximized    = SW_SHOWMAXIMIZED   ,
		   Maximize         = SW_MAXIMIZE        ,
		   ShowNoActivate   = SW_SHOWNOACTIVATE  ,
		   Show             = SW_SHOW            ,
		   Minimize         = SW_MINIMIZE        ,
		   ShowMinNoActive  = SW_SHOWMINNOACTIVE ,
		   ShowNA           = SW_SHOWNA          ,
		   Restore          = SW_RESTORE         ,
		   ShowDefault      = SW_SHOWDEFAULT     ,
		   ForceMinimize    = SW_FORCEMINIMIZE   ,
		   Max              = SW_MAX             );
using SW = WindowShowFlags;

class RGBColor {
protected:
	COLORREF cr;
public:
	RGBColor(COLORREF color) : cr(color) {}
	RGBColor(BYTE red, BYTE green, BYTE blue) :
		cr(RGB(red, green, blue)) {}
public:
	inline BYTE Red() const ret_as(GetRValue(self));
	inline BYTE Green() const ret_as(GetGValue(self));
	inline BYTE Blue() const ret_as(GetBValue(self));
public:
	template<SizeT len>
	static inline ArrayOf<RGBColor, len> &Attach(ArrayOf<COLORREF, len> &ary) ret_as(ref_cast<ArrayOf<RGBColor, len>>(ary));
	inline operator COLORREF() const { return cr; }
	static inline RGBColor &Attach(COLORREF &clr) ret_as(*(RGBColor *)&clr);
};

template<class AnyType>
struct RangeOf {
	AnyType min, max;
public:
	RangeOf(const AnyType &a) : min(a), max(a) {}
	RangeOf(const AnyType &low, const AnyType &high) : min(low), max(high) {}
public: // Property - Low
	/* W */ inline auto&Low(const AnyType &low) ret_to_self(this->min = low);
	/* R */ inline auto Low() const ret_as(this->min);
public: // Property - High
	/* W */ inline auto&High(const AnyType &high) ret_to_self(this->min = high);
	/* R */ inline auto High() const ret_as(this->min);
public: // Property - Min
	/* W */ inline auto&Min(const AnyType &min) ret_to_self(this->min = min);
	/* R */ inline auto Min() const ret_as(this->min);
public: // Property - Max
	/* W */ inline auto&Max(const AnyType &max) ret_to_self(this->max = max);
	/* R */ inline auto Max() const ret_as(this->max);
public:	// Property - Start
	/* W */ inline auto&Start(const AnyType &start) ret_to_self(this->min = start);
	/* R */ inline auto Start() const ret_as(this->min);
public:	// Property - End
	/* W */ inline auto&End(const AnyType &end) ret_to_self(this->max = end);
	/* R */ inline auto End() const ret_as(this->max);
};

}
