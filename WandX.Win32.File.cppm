module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.File.h"

export module WandX.File;

import WandX;
import WandX.Win32;
import WandX.Win32.String;
import WandX.Win32.Type;
// import WandX.Resource;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.File");

export namespace WandX {
namespace Native {

#pragma region FileApi.h
wapi_ret_validhd_WAO(FindFirstChangeNotification);
wapi_ret_true_WAO(FindNextFile);
wapi_ret_true_WAO(GetDiskFreeSpace);
wapi_ret_true_WAO(GetDiskFreeSpaceEx);
wapi_ret_success_WAO(GetDiskSpaceInformation);
wapi_ret_direct_WAO(GetDriveType);
wapi_ret_positive_WAO(GetFinalPathNameByHandle);
wapi_ret_positive_WAO(GetLongPathName);
wapi_ret_positive_WAO(GetShortPathName); // GetShortPathNameA from WinBase.h
wapi_ret_positive_WAO(GetTempFileName);
// GetVolumeInformationByHandle
wapi_ret_true_WAO(GetVolumeInformation);
// FindFirstStream
// FindNextStream
wapi_ret_positive_WAO(GetTempPath);
// FindFirstFileName
// FindNextFileName
#if (NTDDI_VERSION >= NTDDI_WIN10_FE)
wapi_ret_positive_WAO(GetTempPath2);
#endif
wapi_ret_validhd_WAO(CreateFile);
wapi_ret_true_WAO(CreateDirectory);
#if defined(NTDDI_WIN11_GE) && (NTDDI_VERSION >= NTDDI_WIN11_GE) && !__GNUC__
wapi_ret_true_WAO(CreateDirectory2);
wapi_ret_true_WAO(RemoveDirectory2);
wapi_ret_true_WAO(DeleteFile);
wapi_ret_true_WAO(DeleteFile2);
#endif
#pragma endregion

#pragma region WinBase.h (part)
#pragma endregion

}

//#include "wx.file.inl"

}
