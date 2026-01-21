module;

#define WX_CPPM_RESOURCE
#include "wx_resource"

export module wx.resource;

import wx.win32;

#pragma region Win32 Prototype Includes
namespace WX {

#pragma region LibLoaderApi.h
// DisableThreadLibraryCalls
inline void DisableThreadLibraryCalls(HMODULE hLibModule)
	safe_ret_as(::DisableThreadLibraryCalls(hLibModule));
#undef FindResource
// from WinBase.h
inline HRSRC FindResource(HINSTANCE hInstance, LPCSTR lpName, LPCSTR lpType)
	safe_ret_as(auto h = ::FindResourceA(hInstance, lpName, lpType), h);
inline HRSRC FindResource(HINSTANCE hInstance, LPCWSTR lpName, LPCWSTR lpType)
	safe_ret_as(auto h = ::FindResourceW(hInstance, lpName, lpType), h);
#undef FindResourceEx
// from WinBase.h
inline HRSRC FindResource(HINSTANCE hInstance, LPCSTR lpType, LPCSTR lpName, WORD wLanguage)
	safe_ret_as(auto h = ::FindResourceExA(hInstance, lpType, lpName, wLanguage), h);
inline HRSRC FindResource(HINSTANCE hInstance, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage)
	safe_ret_as(auto h = ::FindResourceExW(hInstance, lpType, lpName, wLanguage), h);
// FindStringOrdinal
inline int FindStringOrdinal(DWORD dwFindStringOrdinalFlags, LPCWSTR lpStringSource, int cchSource, LPCWSTR lpStringValue, int cchValue, BOOL bIgnoreCase)
	safe_ret_as(auto ret = ::FindStringOrdinal(dwFindStringOrdinalFlags, lpStringSource, cchSource, lpStringValue, cchValue, bIgnoreCase); ret >= 0, ret);
// FreeLibrary
inline void FreeLibrary(HMODULE hLibModule)
	safe_ret_as(::FreeLibrary(hLibModule));
// FreeLibraryAndExitThread
inline void FreeLibraryAndExitThread(HMODULE hLibModule, DWORD dwExitCode)
	ret_as(::FreeLibraryAndExitThread(hLibModule, dwExitCode));
// FreeResource
inline void FreeResource(HGLOBAL hResData)
	safe_ret_as(auto ret = ::FreeResource(hResData); ret == 0);
#undef GetModuleFileName
inline DWORD GetModuleFileName(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
	safe_ret_as(auto ret = ::GetModuleFileNameA(hModule, lpFilename, nSize), ret);
inline DWORD GetModuleFileName(HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
	safe_ret_as(auto ret = ::GetModuleFileNameW(hModule, lpFilename, nSize), ret);
#undef GetModuleHandle
inline HMODULE GetModuleHandle(LPCSTR lpModuleName)
	safe_ret_as(auto ret = ::GetModuleHandleA(lpModuleName), ret);
inline HMODULE GetModuleHandle(LPCWSTR lpModuleName)
	safe_ret_as(auto ret = ::GetModuleHandleW(lpModuleName), ret);
#undef GetModuleHandleEx
inline void GetModuleHandle(DWORD dwFlags, LPCSTR lpModuleName, HMODULE* phModule)
	safe_ret_as(::GetModuleHandleExA(dwFlags, lpModuleName, phModule));
inline void GetModuleHandle(DWORD dwFlags, LPCWSTR lpModuleName, HMODULE* phModule)
	safe_ret_as(::GetModuleHandleExW(dwFlags, lpModuleName, phModule));
// GetProcAddress
inline FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
	safe_ret_as(auto ret = ::GetProcAddress(hModule, lpProcName), ret);
#undef LoadLibrary
inline HMODULE LoadLibrary(LPCSTR lpLibFileName)
	safe_ret_as(auto ret = ::LoadLibraryA(lpLibFileName), ret);
inline HMODULE LoadLibrary(LPCWSTR lpLibFileName)
	safe_ret_as(auto ret = ::LoadLibraryW(lpLibFileName), ret);
#undef LoadLibraryEx
inline HMODULE LoadLibrary(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
	safe_ret_as(auto ret = ::LoadLibraryExA(lpLibFileName, hFile, dwFlags), ret);
inline HMODULE LoadLibrary(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
	safe_ret_as(auto ret = ::LoadLibraryExW(lpLibFileName, hFile, dwFlags), ret);
// LoadResource
inline HGLOBAL LoadResource(HMODULE hModule, HRSRC hResInfo)
	safe_ret_as(auto ret = ::LoadResource(hModule, hResInfo), ret);
#undef LoadString
// from WinUser.h
inline int LoadString(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax)
	safe_ret_as(auto ret = ::LoadStringA(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
inline int LoadString(HINSTANCE hInstance, UINT uID, PWSTR lpBuffer, int cchBufferMax)
	safe_ret_as(auto ret = ::LoadStringW(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
// LockResource
inline LPVOID LockResource(HGLOBAL hResData)
	safe_ret_as(auto ret = ::LockResource(hResData), ret);
// SizeofResource
inline DWORD SizeofResource(HMODULE hModule, HRSRC hResInfo)
	safe_ret_as(auto ret = ::SizeofResource(hModule, hResInfo), ret);
// AddDllDirectory
inline DLL_DIRECTORY_COOKIE AddDllDirectory(PCWSTR NewDirectory)
	safe_ret_as(auto ret = ::AddDllDirectory(NewDirectory), ret);
// RemoveDllDirectory
inline void RemoveDllDirectory(DLL_DIRECTORY_COOKIE Cookie)
	safe_ret_as(::RemoveDllDirectory(Cookie));
// SetDefaultDllDirectories
inline void SetDefaultDllDirectories(DWORD DirectoryFlags)
	safe_ret_as(::SetDefaultDllDirectories(DirectoryFlags));
#undef EnumResourceLanguagesEx
inline void EnumResourceLanguages(HMODULE hModule, LPCSTR lpType, LPCSTR lpName, ENUMRESLANGPROCA lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceLanguagesExA(hModule, lpType, lpName, lpEnumFunc, lParam, dwFlags, LangId));
inline void EnumResourceLanguages(HMODULE hModule, LPCWSTR lpType, LPCWSTR lpName, ENUMRESLANGPROCW lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceLanguagesExW(hModule, lpType, lpName, lpEnumFunc, lParam, dwFlags, LangId));
#undef EnumResourceTypesEx
inline void EnumResourceTypes(HMODULE hModule, ENUMRESTYPEPROCA lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceTypesExA(hModule, lpEnumFunc, lParam, dwFlags, LangId));
inline void EnumResourceTypes(HMODULE hModule, ENUMRESTYPEPROCW lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceTypesExW(hModule, lpEnumFunc, lParam, dwFlags, LangId));
#undef EnumResourceNames
inline void EnumResourceNames(HMODULE hModule, LPCSTR lpType, ENUMRESNAMEPROCA lpEnumFunc, LONG_PTR lParam)
	safe_ret_as(::EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam));
inline void EnumResourceNames(HMODULE hModule, LPCWSTR lpType, ENUMRESNAMEPROCW lpEnumFunc, LONG_PTR lParam)
	safe_ret_as(::EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam));
#undef EnumResourceNamesEx
inline void EnumResourceNames(HMODULE hModule, LPCSTR lpType, ENUMRESNAMEPROCA lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceNamesExA(hModule, lpType, lpEnumFunc, lParam, dwFlags, LangId));
inline void EnumResourceNames(HMODULE hModule, LPCWSTR lpType, ENUMRESNAMEPROCW lpEnumFunc, LONG_PTR lParam, DWORD dwFlags, LANGID LangId)
	safe_ret_as(::EnumResourceNamesExW(hModule, lpType, lpEnumFunc, lParam, dwFlags, LangId));
#pragma endregion

}
#pragma endregion

export namespace WX {

enum_class(ResourceTypes , LPTSTR          ,
		   Cursor        = RT_CURSOR       ,
		   Bitmap        = RT_BITMAP       ,
		   Icon          = RT_ICON         ,
		   Menu          = RT_MENU         ,
		   Dialog        = RT_DIALOG       ,
		   String        = RT_STRING       ,
		   FontDir       = RT_FONTDIR      ,
		   Font          = RT_FONT         ,
		   Accelerator   = RT_ACCELERATOR  ,
		   RCDATA        = RT_RCDATA       ,
		   MessageTable  = RT_MESSAGETABLE ,
		   GroupCursor   = RT_GROUP_CURSOR ,
		   GroupIcon     = RT_GROUP_ICON   ,
		   Version       = RT_VERSION      ,
		   DlgInclude    = RT_DLGINCLUDE   ,
		   PlugPlay      = RT_PLUGPLAY     ,
		   VXD           = RT_VXD          ,
		   AniCursor     = RT_ANICURSOR    ,
		   AniIcon       = RT_ANIICON      ,
		   HTML          = RT_HTML         ,
		   Manifest      = RT_MANIFEST     );

#pragma region Icon
class IconInfo : public StructShim<ICONINFO> {
public:
	using Super = StructShim<ICONINFO>;
public:
	IconInfo(bool fIcon = true) ret_to(self->fIcon = fIcon);
	IconInfo(const ICONINFO &i) : Super(i) {}
	~IconInfo() {
		Bitmap::AutoDelete(self->hbmMask);
		Bitmap::AutoDelete(self->hbmColor);
	}
public: // Property - Hotspot
	/* W */ inline auto &Hotspot(LPoint s) ret_to_self(self->xHotspot = s.x, self->yHotspot = s.y);
	/* R */ inline LPoint Hotspot() const ret_as({ (long)self->xHotspot, (long)self->yHotspot });
public: // Property - Masks
proxy_prop_set(Mask, HBITMAP, hbmMask);
	/* R */ inline Bitmap &Mask() const ret_as(Bitmap::Attach(const_cast<HBITMAP &>(self->hbmMask)));
public: // Property - Colors
proxy_prop_set(Colors, HBITMAP, hbmColor);
	/* R */ inline Bitmap &Colors() const ret_as(Bitmap::Attach(const_cast<HBITMAP &>(self->hbmColor)));
};
using CIconInfo = ProxyView<IconInfo>;
template<bool IsUnicode = WX::IsUnicode>
class IconInfoExX : public StructShim<std::conditional_t<IsUnicode, ICONINFOEXW, ICONINFOEXA>> {
	using ICONINFOEX = std::conditional_t<IsUnicode, ICONINFOEXW, ICONINFOEXA>;
	using String = StringX<IsUnicode>;
public:
	using Super = StructShim<ICONINFOEX>;
public:
	IconInfoExX() ret_to(self->cbSize = sizeof(self); self->fIcon = true);
	IconInfoExX(const ICONINFOEX &i) : Super(i) {}
	~IconInfoExX() {
		Bitmap::AutoDelete(self->hbmMask);
		Bitmap::AutoDelete(self->hbmColor);
	}
public: // Property - Hotspot
	/* W */ inline auto &Hotspot(LSize s) ret_to_self(self->xHotspot = s.cx, self->yHotspot = s.cy);
	/* R */ inline LSize Hotspot() const ret_as({ (long)self->xHotspot, (long)self->yHotspot });
public: // Property - Masks
proxy_prop_set(Masks, HBITMAP, hbmMask);
	/* R */ inline Bitmap &Masks() const ret_as(Bitmap::Attach(const_cast<HBITMAP &>(self->hbmMask)));
public: // Property - Colors
proxy_prop_set(Colors, HBITMAP, hbmColor);
	/* R */ inline Bitmap &Colors() const ret_as(Bitmap::Attach(const_cast<HBITMAP &>(self->hbmColor)));
	proxy_prop_sync(ResourceID,wResID,WORD);
public: // Property - ModuleName
	/* R */ inline const String ModuleName() const ret_as(CString(self->szModName, ArrayCountOf(self->szModName)));
public: // Property - ResourceName
	/* R */ inline const String ResourceName() const ret_as(CString(self->szResName, ArrayCountOf(self->szResName)));
};
using IconInfoEx = IconInfoExX<>;
using IconInfoExA = IconInfoExX<false>;
using IconInfoExW = IconInfoExX<true>;
class Icon {
protected:
	mutable HICON hIcon = O;
	friend_to_proxy(Icon);
	Icon(HICON h) : hIcon(h) {}
	Icon(const Icon &i) : hIcon(i.hIcon) ret_to(i.hIcon = O);
public:
	Icon() {}
	Icon(Nu) {}
	Icon(Icon &i) : hIcon(i.hIcon) ret_to(i.hIcon = O);
	Icon(Icon &&i) : hIcon(i.hIcon) ret_to(i.hIcon = O);
	~Icon() ret_to(Destroy());
public:
	class CreateStruct {
		HINSTANCE hInstance = GetModuleHandle((LPCTSTR)O);
		int nWidth, nHeight;
		BYTE nPlanes = 1, nBitsPerPixel = 32;
		LPCBYTE lpANDbits = O, lpXORbits = O;
	public:
		CreateStruct(LPCBYTE lpANDbits, LPCBYTE lpXORbits) :
			lpANDbits(lpANDbits), lpXORbits(lpXORbits) {}
	public:
		inline auto &Module(HINSTANCE hInstance) ret_to_self(this->hInstance = hInstance);
		inline auto &Width(LONG nWidth) ret_to_self(this->nWidth = nWidth);
		inline auto &Height(LONG nHeight) ret_to_self(this->nHeight = nHeight);
		inline auto &Size(LSize sz) ret_to_self(this->nWidth = sz.cx, this->nHeight = sz.cy);
		inline auto &Planes(UINT nPlanes) ret_to_self(this->nPlanes = nPlanes);
		inline auto &BitsPerPixel(UINT nBitsPerPixel) ret_to_self(this->nBitsPerPixel = nBitsPerPixel);
		inline auto &Mask(LPCVOID lpBits) ret_to_self(this->lpANDbits = (LPCBYTE)lpBits);
		inline auto &Colors(LPCVOID lpBits) ret_to_self(this->lpXORbits = (LPCBYTE)lpBits);
	public:
		inline Icon Create() const ret_as(WX::CreateIcon(hInstance, nWidth, nHeight, nPlanes, nBitsPerPixel, lpANDbits, lpXORbits));
		inline operator Icon() const ret_as(Create());
	};
	static inline CreateStruct Create(LPCBYTE lpANDbits, LPCBYTE lpXORbits = O) ret_as({ lpANDbits, lpXORbits });
	static inline Icon Create(HBITMAP hbmColor, HBITMAP hbmMask = O) ret_as(WX::CreateIcon(&CIconInfo(IconInfo())->Colors(hbmColor).Mask(hbmMask)));
	inline void Destroy() {
		if (self)
			WX::DestroyIcon(hIcon);
		hIcon = O;
	}
#pragma region Properties
public: // Property - Info
	/* R */ inline IconInfo Info() const ret_to(ICONINFO i, WX::GetIconInfo(hIcon, &i), i);
public: // Property - Masks
	/* R */ inline Bitmap Mask() const ret_as(Info().Mask());
public: // Property - Colors
	/* R */ inline Bitmap Colors() const ret_as(Info().Colors());
public: // Property - Hotspot
	/* R */ inline LPoint Hotspot() const ret_as(Info().Hotspot());
public: // Property - InfoEx
	template<bool IsUnicode = WX::IsUnicode>
	/* R */ inline IconInfoExX<IsUnicode> InfoEx() const ret_to(IconInfoExX<IsUnicode> i, WX::GetIconInfoEx(hIcon, &i), i);
	/* R */ inline IconInfoExA InfoExA() const ret_as(InfoEx<false>());
	/* R */ inline IconInfoExW InfoExW() const ret_as(InfoEx<true>());
#pragma endregion
public:
	inline operator HICON() const ret_as(hIcon);
	inline Icon operator+() const ret_as(WX::CopyIcon(hIcon));
	inline auto &operator=(Icon &i) ret_to_self(std::swap(hIcon, i.hIcon));
	inline auto &operator=(Icon &&i) ret_to_self(std::swap(hIcon, i.hIcon));
	inline auto &operator=(const Icon &i) const ret_to_self(std::swap(hIcon, i.hIcon));
public:
	static inline Icon &Attach(HICON &hIcon) ret_as(ref_cast<Icon>(hIcon));
	static inline const Icon &Attach(const HICON &hIcon) ret_as(ref_cast<const Icon>(hIcon));
};
using CIcon = ProxyView<Icon>;
#pragma endregion

#pragma region Cursor
class Cursor : public Icon {
public:
	using Super = Icon;
protected:
	friend_to_proxy(Cursor);
	Cursor(HCURSOR h) : Super((HICON)h) {}
	Cursor(const Cursor &c) : Icon(c) {}
public:
	Cursor() {}
	Cursor(Nu) {}
	Cursor(Cursor &i) : Super(i) {}
	Cursor(Cursor &&i) : Super(i) {}
	~Cursor() ret_to(Destroy());
public:
	class CreateStruct {
		HINSTANCE hInstance = GetModuleHandle((LPCTSTR)O);
		int nWidth = 0, nHeight = 0, xHotspot = 0, yHotspot = 0;
		LPCBYTE lpANDbits, lpXORbits;
	public:
		CreateStruct(LPCBYTE lpANDbits, LPCBYTE lpXORbits, LPoint Hotspot) :
			xHotspot(Hotspot.x), yHotspot(Hotspot.y), lpANDbits(lpANDbits), lpXORbits(lpXORbits) {}
	public:
		inline auto &Module(HINSTANCE hInstance) ret_to_self(this->hInstance = hInstance);
		inline auto &Hotspot(LSize s) ret_to_self(this->xHotspot = s.cx, this->yHotspot = s.cy);
		inline auto &Width(LONG nWidth) ret_to_self(this->nWidth = nWidth);
		inline auto &Height(LONG nHeight) ret_to_self(this->nHeight = nHeight);
		inline auto &Size(LSize sz) ret_to_self(this->nWidth = sz.cx, this->nHeight = sz.cy);
	public:
		inline Cursor Create() const ret_as(WX::CreateCursor(hInstance, xHotspot, yHotspot, nWidth, nHeight, lpANDbits, lpXORbits));
		inline operator Cursor() const ret_as(Create());
	};
	static inline CreateStruct Create(LPCBYTE lpANDbits, LPCBYTE lpXORbits = O, LPoint Hotspot = 0) ret_as({ lpANDbits, lpXORbits, Hotspot });
	static inline Cursor Create(HBITMAP hbmColor, HBITMAP hbmMask = O, LPoint Hotspot = 0) ret_as(WX::CreateIcon(&CIconInfo(IconInfo())->Colors(hbmColor).Mask(hbmMask)));
	inline void Destroy() {
		if (self) 
			WX::DestroyCursor(Super::hIcon);
		Super::hIcon = O;
	}
public:
	inline operator HCURSOR() const ret_as((HCURSOR)Super::hIcon);
	inline Cursor operator+() const ret_as(WX::CopyIcon(Super::hIcon));
	inline auto &operator=(Cursor &i) ret_to_self(std::swap(hIcon, i.hIcon));
	inline auto &operator=(Cursor &&i) ret_to_self(std::swap(hIcon, i.hIcon));
	inline auto &operator=(const Cursor &i) const ret_to_self(std::swap(hIcon, i.hIcon));
public:
	static inline Cursor &Attach(HCURSOR &hCursor) ret_as(ref_cast<Cursor>(hCursor));
	static inline const Cursor &Attach(const HCURSOR &hCursor) ret_as(ref_cast<const Cursor>(hCursor));
};
using CCursor = ProxyView<Cursor>;
struct CursorInfo : public StructShim<CURSORINFO> {
	using Super = StructShim<CURSORINFO>;
public:
	CursorInfo() ret_to(self->cbSize = sizeof(self));
	CursorInfo(const CURSORINFO &c) : Super(c) {}
public: // Property - Visible
	/* W */ inline auto &Visible(bool bVisible) ret_to_self(bVisible ? self->flags |= CURSOR_SHOWING : self->flags &= ~CURSOR_SHOWING);
	/* R */ inline bool Visible() const ret_as(self->flags &CURSOR_SHOWING);
	proxy_prop(Cursor,hCursor,HCURSOR,CCursor);
	proxy_prop_sync(Position,ptScreenPos,LPoint);
};
class CursorItf {
public:
	static inline void Show() ret_to(WX::ShowCursor(TRUE));
	static inline void Hide() ret_to(WX::ShowCursor(FALSE));
#pragma region Properties
public: // Property - Info
	/* R */ static inline CursorInfo Info() ret_to(CursorInfo ci; WX::GetCursorInfo(&ci), ci);
public: // Property - Visible
	/* W */ inline auto &Visible(bool bVisible) ret_to_self(WX::ShowCursor(bVisible));
public: // Property - Position
	/* W */ inline auto &Position(LPoint p) ret_to_self(WX::SetCursorPos(p.x, p.y));
	/* R */ static inline LPoint Position() ret_to(LPoint p; WX::GetCursorPos(&p), p);
public: // Property - PhysicalPosition
	/* W */ inline auto &PhysicalPosition(LPoint p) ret_to_self(WX::SetPhysicalCursorPos(p.x, p.y));
	/* R */ static inline LPoint PhysicalPosition() ret_to(LPoint p; WX::GetPhysicalCursorPos(&p), p);
public: // Property - ClipRect
	/* W */ inline auto &ClipRect(LRect r) ret_to_self(WX::ClipCursor(&r));
	/* R */ static inline LRect ClipRect() ret_to(LRect r; WX::GetClipCursor(&r), r);
#pragma endregion
public:
	inline operator CCursor() const ret_as(WX::GetCursor());
	inline auto &operator=(HCURSOR hCursor) ret_to_self(WX::SetCursor(hCursor));
} ICursor;
#pragma endregion

#pragma region Accelerators
enum_flags(VirtualKey , BYTE      ,
		   NoInvert   = FNOINVERT ,
		   Shift      = FSHIFT    ,
		   Control    = FCONTROL  ,
		   Alt        = FALT      );
class AccelEntry : public StructShim<ACCEL> {
public:
	using Super = StructShim<ACCEL>;
public:
	AccelEntry() {}
	AccelEntry(WX::VirtualKey vk, WORD key, WORD cmd) : Super(ACCEL{ vk.yield(), key, cmd }) {}
public: // Property - VirtualKey
	/* W */ inline auto&VirtualKey(WX::VirtualKey vk) ret_to_self(self->fVirt = vk.yield());
	/* R */ inline auto VirtualKey() const ret_as(reuse_cast<WX::VirtualKey>(self->fVirt));
	proxy_prop_sync(Key,key,WORD);
	proxy_prop_sync(CommandID,cmd,WORD);
};
class Accelerators {
protected:
	mutable HACCEL hAccel = O;
	friend_to_proxy(Accelerators);
	Accelerators(HACCEL h) : hAccel(h) {}
	Accelerators(const Accelerators &c) : hAccel(c.hAccel) ret_to(c.hAccel = O);
public:
	Accelerators() {}
	Accelerators(const std::vector<AccelEntry> &entries) : hAccel() {}
	~Accelerators() ret_to(Destroy());
public:
	static inline Accelerators Create(const std::vector<AccelEntry> &entries)
		ret_as(WX::CreateAcceleratorTable((ACCEL *)entries.data(), (int)entries.size()));
	inline void Destroy() {
		if (hAccel)
			WX::DestroyAcceleratorTable(hAccel);
		hAccel = O;
	}
public:
	inline operator bool() const ret_as(hAccel);
	inline operator HACCEL() const ret_as(hAccel);
	inline auto &operator=(Accelerators &a) ret_to_self(std::swap(hAccel, a.hAccel));
	inline auto &operator=(const Accelerators &a) const ret_to_self(std::swap(hAccel, a.hAccel));
};
using Accel = Accelerators;
using CAccelerators = ProxyView<Accelerators>;
using CAccel = ProxyView<Accelerators>;
#pragma endregion

#pragma region Menu
class Menu;
using CMenu = ProxyView<Menu>;
//enum_class(MenuBmp, HBITMAP,
//	Callback      = HBMMENU_CALLBACK,
//	System        = HBMMENU_SYSTEM,
//	BarRestore    = HBMMENU_MBAR_RESTORE,
//	BarMinimize   = HBMMENU_MBAR_MINIMIZE,
//	BarClose      = HBMMENU_MBAR_CLOSE,
//	BarCloseD     = HBMMENU_MBAR_CLOSE_D,
//	BarMinimizeD  = HBMMENU_MBAR_MINIMIZE_D,
//	PopupClose    = HBMMENU_POPUP_CLOSE,
//	PopupRestore  = HBMMENU_POPUP_RESTORE,
//	PopupMaximize = HBMMENU_POPUP_MAXIMIZE,
//	PopupMinimize = HBMMENU_POPUP_MINIMIZE);
enum_flags(MenuItemType  , UINT             ,
		   String        = MFT_STRING       ,
		   Bitmap        = MFT_BITMAP       ,
		   BarBreak      = MFT_MENUBARBREAK ,
		   Break         = MFT_MENUBREAK    ,
		   OwnerDraw     = MFT_OWNERDRAW    ,
		   RadioCheck    = MFT_RADIOCHECK   ,
		   Separator     = MFT_SEPARATOR    ,
		   RightOrder    = MFT_RIGHTORDER   ,
		   RightJustify  = MFT_RIGHTJUSTIFY );
enum_flags(MenuItemState , UINT             ,
		   Default       = MFS_DEFAULT      ,
		   Grayed        = MFS_GRAYED       ,
		   Enabled       = MFS_ENABLED      ,
		   Disabled      = MFS_DISABLED     ,
		   Checked       = MFS_CHECKED      ,
		   Unchecked     = MFS_UNCHECKED    ,
		   Hilite        = MFS_HILITE       ,
		   Unhilite      = MFS_UNHILITE     );
enum_flags(MenuStyle     , DWORD            ,
		   NoCheck       = MNS_NOCHECK      ,
		   Modeless      = MNS_MODELESS     ,
		   DragDrop      = MNS_DRAGDROP     ,
		   AutoDismiss   = MNS_AUTODISMISS  ,
		   NotifyByPos   = MNS_NOTIFYBYPOS  ,
		   CheckOrBmp    = MNS_CHECKORBMP   );
class MenuIItems {
	friend class Menu;
	HMENU hMenu;
//	UINT uID, flags;
protected:
	MenuIItems(HMENU hMenu) : hMenu(hMenu) {}
public:
//	inline void Delete(UINT uID) ret_to(WX::DeleteMenu(hMenu, uID, flags));
//	inline void Remove(UINT uID) ret_to(WX::RemoveMenu(hMenu, uID, flags));
//	inline auto&Hilite(HWND hWnd, bool bHilite = true) ret_to_self(HiliteMenuItem(hWnd, hMenu, uID, flags | (bHilite ? MF_HILITE : MF_UNHILITE)));
//	CMenu Sub(int nPos);
public: // Property - Count
	inline auto Count() const ret_as(WX::GetMenuItemCount(hMenu));
//public: // Property - Enable
//	/* W */ inline auto &Enable(bool bEnable) ret_to_self(WX::EnableMenuItem(hMenu, uID, flags | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED))));
//public: // Property - Check
//	/* W */ inline auto &Check(bool bChecked) ret_to_self(WX::CheckMenuItem(hMenu, uID, flags | (bChecked ? MF_CHECKED : MF_UNCHECKED)));
};
enum_flags(MenuTrack        , UINT                ,
		   LeftButton       = TPM_LEFTBUTTON      ,
		   RightButton      = TPM_RIGHTBUTTON     ,
		   LeftAlign        = TPM_LEFTALIGN       ,
		   CenterAlign      = TPM_CENTERALIGN     ,
		   RightAlign       = TPM_RIGHTALIGN      ,
		   TopAlign         = TPM_TOPALIGN        ,
		   VCenterAlign     = TPM_VCENTERALIGN    ,
		   BottomAlign      = TPM_BOTTOMALIGN     ,
		   Horizontal       = TPM_HORIZONTAL      ,
		   Vertical         = TPM_VERTICAL        ,
		   NoNotify         = TPM_NONOTIFY        ,
		   ReturnCmd        = TPM_RETURNCMD       ,
		   Recurse          = TPM_RECURSE         ,
		   HorPosAnimation  = TPM_HORPOSANIMATION ,
		   HorNegAnimation  = TPM_HORNEGANIMATION ,
		   VerPosAnimation  = TPM_VERPOSANIMATION ,
		   VerNegAnimation  = TPM_VERNEGANIMATION ,
		   NoAnimation      = TPM_NOANIMATION     ,
		   LayoutRtl        = TPM_LAYOUTRTL       ,
		   WorkArea         = TPM_WORKAREA        );
class Menu {
protected:
	mutable HMENU hMenu = O;
	friend_to_proxy(Menu);
	Menu(HMENU h) : hMenu(h) {}
	Menu(const Menu &m) : hMenu(m.hMenu) ret_to(m.hMenu = O);
public:
	Menu() : Menu(Create()) {}
	Menu(Nu) {}
	Menu(Menu &m) : hMenu(m) ret_to(m.hMenu = O);
	Menu(Menu &&m) : hMenu(m) ret_to(m.hMenu = O);
	~Menu() ret_to(Destroy());
public:
	static inline Menu Create() ret_as(WX::CreateMenu());
	static inline Menu CreatePopup() ret_as(WX::CreatePopupMenu());
	inline void Destroy() {
		if (self)
			WX::DestroyMenu(hMenu);
		hMenu = O;
	}
public:
	inline auto&String(LPCSTR lpString, UINT_PTR uID = 0, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, MF_STRING | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), uID, lpString));
	inline auto&String(LPCWSTR lpString, UINT_PTR uID = 0, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, MF_STRING | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), uID, lpString));
	inline auto&Popup(LPCSTR lpString, HMENU hPopup, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, MF_POPUP | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), (UINT_PTR)hPopup, lpString));
	inline auto&Popup(LPCWSTR lpString, HMENU hPopup, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, MF_POPUP | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), (UINT_PTR)hPopup, lpString));
	inline auto&Check(LPCSTR lpString, UINT_PTR uID = 0, bool bChecked = false, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, (bChecked ? MF_CHECKED : MF_UNCHECKED) | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), uID, lpString));
	inline auto&Check(LPCWSTR lpString, UINT_PTR uID = 0, bool bChecked = false, bool bEnable = true) ret_to_self(WX::AppendMenu(hMenu, (bChecked ? MF_CHECKED : MF_UNCHECKED) | (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)), uID, lpString));
	inline auto&Separator() ret_to_self(WX::AppendMenu(hMenu, MF_SEPARATOR, 0, (LPCTSTR)O));

	inline auto&String(UINT uPosition, LPCTSTR lpString, UINT_PTR uID = 0, bool bEnable = true) ret_to_self(WX::InsertMenu(hMenu, uPosition, MF_STRING | (bEnable ? MF_ENABLED : MF_DISABLED), uID, lpString));
	inline auto&Popup(UINT uPosition, LPCTSTR lpString, HMENU hPopup) ret_to_self(WX::InsertMenu(hMenu, uPosition, MF_POPUP, (UINT_PTR)hPopup, lpString));
	inline auto&Check(UINT uPosition, LPCTSTR lpString, UINT_PTR uID = 0, bool bChecked = false) ret_to_self(WX::InsertMenu(hMenu, uPosition, (bChecked ? MF_CHECKED : MF_UNCHECKED), uID, lpString));
	inline auto&Separator(UINT uPosition) ret_to_self(WX::InsertMenu(hMenu, uPosition, MF_SEPARATOR, 0, (LPCTSTR)O));

	inline auto&Radio(UINT idFirst, UINT idLast, UINT idCheck) ret_to_self(WX::CheckMenuRadioItem(hMenu, idFirst, idLast, idCheck, MF_BYCOMMAND));
	inline auto&RadioIndex(UINT indFirst, UINT indLast, UINT indCheck) ret_to_self(WX::CheckMenuRadioItem(hMenu, indFirst, indLast, indCheck, MF_BYPOSITION));
public:	
	inline void Track(MenuTrack tt, POINT pt, HWND hParent) const ret_to(WX::TrackPopupMenu(hMenu, tt.yield(), pt.x, pt.y, 0, hParent, O));
	//inline auto Modify(UINT uID) ret_as(ModifyMenu(hMenu, uID, MF_BYCOMMAND, ));

public:
	inline operator bool() const ret_as(WX::IsMenu(hMenu));
	inline operator HMENU() const ret_as(hMenu);
	inline operator LPARAM() const ret_as((LPARAM)hMenu);
	inline auto &operator=(Menu &m) ret_to_self(std::swap(hMenu, m.hMenu));
	inline auto &operator=(const Menu &m) const ret_to_self(std::swap(hMenu, m.hMenu));
public:
	static inline Menu &Attach(HMENU &hMenu) ret_as(ref_cast<Menu>(hMenu));
	static inline const Menu &Attach(const HMENU &hMenu) ret_as(ref_cast<const Menu>(hMenu));
};
//inline CMenu MenuItem::Sub(int nPos) ret_as({ WX::GetSubMenu(hMenu, nPos) });
inline Menu MenuPopup() ret_as(Menu::CreatePopup());
#undef MENUITEM_PROPERTY
#pragma endregion

#pragma region Module
class Module {
protected:
	mutable HINSTANCE hInst = O;
	friend_to_proxy(Module);
	Module(HINSTANCE h) : hInst(h) {}
	Module(const Module &m) : hInst(m.hInst) ret_to(m.hInst = O);
public:
	Module() : hInst(GetModuleHandle((LPCTSTR)O)) {}
	Module(Nu) {}
	Module(Module &m) : hInst(m) ret_to(m.hInst = O);
	Module(Module &&m) : hInst(m) ret_to(m.hInst = O);
	Module(LPCSTR lpModuleName) : hInst(Handle(lpModuleName)) {}
	Module(LPCWSTR lpModuleName) : hInst(Handle(lpModuleName)) {}
	~Module() ret_to(Free());
public:
	static inline Module Handle(LPCSTR lpModuleName) ret_as(WX::GetModuleHandle(lpModuleName));
	static inline Module Handle(LPCWSTR lpModuleName) ret_as(WX::GetModuleHandle(lpModuleName));
	static inline Module Library(LPCSTR lpLibFileName) ret_as(WX::LoadLibrary(lpLibFileName));
	static inline Module Library(LPCWSTR lpLibFileName) ret_as(WX::LoadLibrary(lpLibFileName));
//	static inline Module Load(LPCSTR lpModuleName, LPVOID lpParameterBlock = O) ret_as(LoadModule(lpModuleName, lpParameterBlock));
public:
	inline void Free() {
		if (hInst)
			WX::FreeLibrary(hInst);
		hInst = O;
	}
public: // Property - Menu
	/* R */ inline CMenu Menu(LPCSTR lpszName) const ret_as(WX::LoadMenu(self, lpszName));
	/* R */ inline CMenu Menu(LPCWSTR lpszName) const ret_as(WX::LoadMenu(self, lpszName));
	/* R */ inline CMenu Menu(WORD wID) const ret_as(WX::LoadMenu(self, MAKEINTRESOURCE(wID)));
public: // Property - Accelerators
	/* R */ inline CAccel Accelerators(LPCSTR lpszName) const ret_as(WX::LoadAccelerators(self, lpszName));
	/* R */ inline CAccel Accelerators(LPCWSTR lpszName) const ret_as(WX::LoadAccelerators(self, lpszName));
	/* R */ inline CAccel Accelerators(WORD wID) const ret_as(WX::LoadAccelerators(self, MAKEINTRESOURCE(wID)));
public: // Property - Bitmap
	/* R */ inline CBitmap Bitmap(LPCSTR lpszName) const ret_as(WX::LoadBitmap(self, lpszName));
	/* R */ inline CBitmap Bitmap(LPCWSTR lpszName) const ret_as(WX::LoadBitmap(self, lpszName));
	/* R */ inline CBitmap Bitmap(WORD wID) const ret_as(WX::LoadBitmap(self, MAKEINTRESOURCE(wID)));
public: // Property - Icon
	/* R */ inline CIcon Icon(LPCSTR lpszName) const ret_as(WX::LoadIcon(self, lpszName));
	/* R */ inline CIcon Icon(LPCWSTR lpszName) const ret_as(WX::LoadIcon(self, lpszName));
	/* R */ inline CIcon Icon(WORD wID) const ret_as(WX::LoadIcon(self, MAKEINTRESOURCE(wID)));
public: // Property - Cursor
	/* R */ inline CCursor Cursor(LPCSTR lpszName) const ret_as(WX::LoadCursor(self, lpszName));
	/* R */ inline CCursor Cursor(LPCWSTR lpszName) const ret_as(WX::LoadCursor(self, lpszName));
	/* R */ inline CCursor Cursor(WORD wID) const ret_as(WX::LoadCursor(self, MAKEINTRESOURCE(wID)));
public: // Property - String
	template<bool IsUnicode = WX::IsUnicode>
	inline StringX<IsUnicode> String(WORD wID) const {
		if_c (IsUnicode)
			 return StringW(wID);
		else return StringA(wID);
	}
	inline WX::StringA StringA(WORD wID) const {
		auto len = StringW(wID).Length();
		WX::StringA str(len);
		WX::LoadString(self, wID, str, (int)len);
		return right_hand_cast(str);
	}
	inline const WX::StringW StringW(WORD wID) const {
		LPCWSTR lpString = O;
		int len = WX::LoadString(self, wID, (LPWSTR)&lpString, 0);
		return CString(len, lpString);
	}
public: // Property - Symbol
	template<class AnyType>
	inline AnyType *Symbol(LPCSTR lpName) ret_as((AnyType *)::GetProcAddress(self, lpName));
public: // Property - FileName
	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenPath>
	/* R */ inline StringX<IsUnicode> FileName() const {
		StringX<IsUnicode> str(MaxLen);
		auto len = WX::GetModuleFileName(self, str, (int)MaxLen);
		return right_hand_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenPath>
	/* R */ inline WX::StringA FileNameA() const ret_as(FileName<false, MaxLen>());
	template<SizeT MaxLen = MaxLenPath>
	/* R */ inline WX::StringW FileNameW() const ret_as(FileName<true, MaxLen>());
public:
	inline operator bool() const ret_as(hInst);
	inline operator HINSTANCE() const ret_as(hInst);
	inline operator LPARAM() const ret_as((LPARAM)hInst);
	inline auto &operator=(Module &m) ret_to_self(std::swap(hInst, m.hInst));
	inline auto &operator=(Module &&m) ret_to_self(std::swap(hInst, m.hInst));
	inline auto &operator=(const Module &m) const ret_to_self(std::swap(hInst, m.hInst));
public:
	static inline Module &Attach(HINSTANCE &hInst) ret_as(ref_cast<Module>(hInst));
	static inline const Module &Attach(const HINSTANCE &hInst) ret_as(ref_cast<const Module>(hInst));
};
using CModule = ProxyView<Module>;
#pragma endregion

inline Bitmap ClipBitmap(const Bitmap &bmp, LRect rc) {
	auto &&size = rc.size();
	Bitmap nBmp = Bitmap::Create(size).BitsPerPixel(bmp.Log().BitsPerPixel());
	DC srcDC = DC::CreateCompatible(), dstDC = DC::CreateCompatible();
	srcDC.Select(nBmp);
	dstDC.Select(bmp);
	srcDC.BltBit(0, size, dstDC);
	return nBmp;
}

//inline void SaveToFile(DC &dc, const Palette &pal, const Bitmap &bmp, File &file) {
//	auto &&log = bmp.Log();
//	bool usePal = log.BitsPerPixel() < 24 && pal;
//	auto usage = usePal ? DIB_PAL_COLORS : DIB_RGB_COLORS;
//	auto palSize = usePal ? (DWORD)std::min(pal.Size(), (SizeT)4 << log.BitsPerPixel()) : 0;
//	BitmapHeader header;
//	header.Size(log.Size());
//	header.Planes(log.Planes());
//	header.BitsPerPixel(log.BitsPerPixel());
//	nt_assert(GetDIBits(dc, bmp, 0, log.Height(), O, header, usage));
//	header.PaletteSize(palSize);
//	header.ColorsSize(header.SizeImage());
//	nt_assert(file.Write(&header, sizeof(header) - 4) == sizeof(header) - 4);
//	nt_assert(file.Write(pal.Entries().data(), palSize) == palSize);
//	HeapPointer<> hBits(header.SizeImage());
//	nt_assert(GetDIBits(dc, bmp, 0, log.Height(), &hBits, header, usage));
//	nt_assert(file.Write(&hBits, header.SizeImage()) == header.SizeImage());
//}
//
//inline void SaveToFile(DC &dc, const Palette &pal, const Bitmap &bmp, File &&file) ret_to(SaveToFile(dc, pal, bmp, file));

}
