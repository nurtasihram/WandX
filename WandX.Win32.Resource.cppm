module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Resource.h"

export module WandX.Resource;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Resource");

export namespace WandX {
namespace Native {

#pragma region LibLoaderApi.h
wapi_ret_true(DisableThreadLibraryCalls);
wapi_ret_notnull_WAO(FindResource); // FindResourceA from WinBase.h
wapi_ret_notnull_WAO(FindResourceEx); // FindResourceExA from WinBase.h
inline int FindStringOrdinal(DWORD dwFindStringOrdinalFlags, LPCWSTR lpStringSource, int cchSource, LPCWSTR lpStringValue, int cchValue, BOOL bIgnoreCase)
safe_ret_as(auto ret = ::FindStringOrdinal(dwFindStringOrdinalFlags, lpStringSource, cchSource, lpStringValue, cchValue, bIgnoreCase); ret >= 0, ret);
wapi_ret_true(FreeLibrary);
wapi_ret_direct(FreeLibraryAndExitThread);
wapi_ret_true(FreeResource);
wapi_ret_positive_WAO(GetModuleFileName);
wapi_ret_notnull_WAO(GetModuleHandle);
wapi_ret_true_WAO(GetModuleHandleEx);
wapi_ret_notnull(GetProcAddress);
wapi_ret_notnull_WAO(LoadLibrary);
wapi_ret_notnull_WAO(LoadLibraryEx);
wapi_ret_notnull(LoadResource);
#undef LoadString
// from WinUser.h
inline int LoadString(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax)
safe_ret_as(auto ret = ::LoadStringA(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
inline int LoadString(HINSTANCE hInstance, UINT uID, PWSTR lpBuffer, int cchBufferMax)
safe_ret_as(auto ret = ::LoadStringW(hInstance, uID, lpBuffer, cchBufferMax); ret >= 0, ret);
wapi_ret_notnull(LockResource);
wapi_ret_positive(SizeofResource);
wapi_ret_notnull(AddDllDirectory);
wapi_ret_true(RemoveDllDirectory);
wapi_ret_true(SetDefaultDllDirectories);
wapi_ret_true_WAO(EnumResourceLanguagesEx);
wapi_ret_true_WAO(EnumResourceTypesEx);
wapi_ret_true_WAO(EnumResourceNames);
wapi_ret_true_WAO(EnumResourceNamesEx);
#pragma endregion

}

//#include "WandX.Win32.Resource.idl"

}
