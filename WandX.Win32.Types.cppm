module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Types.h"

export module WandX.Win32.Types;

import WandX;
import WandX.Win32;
import WandX.Win32.String;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Types");

export namespace WandX {
namespace Native {

#pragma region DateTimeApi.h
wapi_ret_positive_WAO(GetDateFormat);
wapi_ret_positive_WAO(GetTimeFormat);
wapi_ret_positive(GetTimeFormatEx);
wapi_ret_positive(GetDateFormatEx);
// GetDurationFormatEx - Deprecated
#pragma endregion

#pragma region HandleApi.h
wapi_ret_true(CloseHandle);
wapi_ret_true(DuplicateHandle);
wapi_ret_direct(CompareObjectHandles);
wapi_ret_true(GetHandleInformation);
wapi_ret_true(SetHandleInformation);
#pragma endregion

}

#include "WandX.Win32.Types.idl"

}
