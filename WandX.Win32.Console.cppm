module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.Console.h"

export module WandX.Win32.Console;

import WandX;
import WandX.Win32;
import WandX.Win32.String;
import WandX.Win32.Types;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.Console");

export namespace WandX {
namespace Native {

#pragma region ProcessEnv.h (part)
wapi_ret_validhd(GetStdHandle);
wapi_ret_true(SetStdHandle);
wapi_ret_true(SetStdHandleEx);
#pragma endregion

#pragma region ConsoleApi.h
wapi_ret_true(AllocConsole);
// AllocConsoleWithOptions 
wapi_ret_true(FreeConsole);
wapi_ret_true(AttachConsole);
wapi_ret_positive(GetConsoleCP);
wapi_ret_positive(GetConsoleOutputCP);
wapi_ret_true(GetConsoleMode);
wapi_ret_true(SetConsoleMode);
wapi_ret_true(GetNumberOfConsoleInputEvents);
wapi_ret_true_WAT(ReadConsoleInput);
wapi_ret_true_WAT(PeekConsoleInput);
wapi_ret_true_WAT(ReadConsole);
wapi_ret_true_WAT(WriteConsole);
wapi_ret_true(SetConsoleCtrlHandler);
#pragma endregion

#pragma region ConsoleApi2.h
wapi_ret_true_WAT(FillConsoleOutputCharacter);
wapi_ret_true(FillConsoleOutputAttribute);
wapi_ret_true(GenerateConsoleCtrlEvent);
wapi_ret_validhd(CreateConsoleScreenBuffer);
wapi_ret_true(SetConsoleActiveScreenBuffer);
wapi_ret_true(FlushConsoleInputBuffer);
wapi_ret_true(SetConsoleCP);
wapi_ret_true(SetConsoleOutputCP);
wapi_ret_true(GetConsoleCursorInfo);
wapi_ret_true(SetConsoleCursorInfo);
wapi_ret_true(GetConsoleScreenBufferInfo);
wapi_ret_true(GetConsoleScreenBufferInfoEx);
wapi_ret_true(SetConsoleScreenBufferInfoEx);
wapi_ret_true(SetConsoleScreenBufferSize);
wapi_ret_true(SetConsoleCursorPosition);
// GetLargestConsoleWindowSize
inline COORD GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
safe_ret_as(auto c = ::GetLargestConsoleWindowSize(hConsoleOutput); c.X &&c.Y, c);
wapi_ret_true(SetConsoleTextAttribute);
wapi_ret_true(SetConsoleWindowInfo);
wapi_ret_true_WAO(WriteConsoleOutputCharacter);
wapi_ret_true(WriteConsoleOutputAttribute);
wapi_ret_true_WAO(ReadConsoleOutputCharacter);
wapi_ret_true(ReadConsoleOutputAttribute);
wapi_ret_true_WAT(WriteConsoleInput);
wapi_ret_true_WAT(ScrollConsoleScreenBuffer);
wapi_ret_true_WAT(WriteConsoleOutput);
wapi_ret_true_WAT(ReadConsoleOutput);
wapi_ret_positive_WAO(GetConsoleTitle);
wapi_ret_positive_WAO(GetConsoleOriginalTitle);
wapi_ret_true_WAO(SetConsoleTitle);
#pragma endregion

#pragma region ConsoleApi3.h
wapi_ret_positive(GetNumberOfConsoleMouseButtons);
// GetConsoleFontSize
inline COORD GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont)
safe_ret_as(auto c = ::GetConsoleFontSize(hConsoleOutput, nFont); c.X &&c.Y, c);
wapi_ret_true(GetCurrentConsoleFont);
wapi_ret_true(GetCurrentConsoleFontEx);
wapi_ret_true(SetCurrentConsoleFontEx);
wapi_ret_true(GetConsoleSelectionInfo);
wapi_ret_true(GetConsoleHistoryInfo);
wapi_ret_true(SetConsoleHistoryInfo);
wapi_ret_true(GetConsoleDisplayMode);
wapi_ret_true(SetConsoleDisplayMode);
wapi_ret_direct(GetConsoleWindow);
wapi_ret_true_WAO(AddConsoleAlias);
wapi_ret_true_WAO(GetConsoleAlias);
wapi_ret_true_WAO(GetConsoleAliasesLength);
wapi_ret_direct_WAT(GetConsoleAliasExesLength);
wapi_ret_true_WAO(GetConsoleAliases);
wapi_ret_true_WAO(GetConsoleAliasExes);
wapi_ret_positive(GetConsoleProcessList);
#pragma endregion

}

#include "WandX.Win32.Console.idl"

}
