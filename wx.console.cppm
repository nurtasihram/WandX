module;

#define WX_CPPM_CONSOLE
#include "wx_console"

export module wx.console;

import wx.win32;

#define  wx_api_reflect_bool1(name)          BoolReflectorOf<ThisFile, LiString(#name), ::name> name
#define  wx_api_reflect_bool2(name, new_ret) BoolReflectorOf<ThisFile, LiString(#name), ::name, new_ret> name
#define  wx_api_reflect_bool(...)            mx_funcN(wx_api_reflect_bool, __VA_ARGS__)

#ifndef WX_REMOVE_WIN32_PROTOTYPES
namespace WX {

constexpr auto ThisFile = LiString("wx.console");


#pragma region ProcessEnv.h (part)
// GetStdHandle
inline HANDLE GetStdHandle(DWORD nStdHandle)
	safe_ret_as(auto h = ::GetStdHandle(nStdHandle); h != INVALID_HANDLE_VALUE, h);
wx_api_reflect_bool(SetStdHandle);
// SetStdHandleEx
inline void SetStdHandleEx(DWORD nStdHandle, HANDLE hHandle, PHANDLE phPrevValue)
	safe_ret_as(::SetStdHandleEx(nStdHandle, hHandle, phPrevValue));
#pragma endregion

#pragma region ConsoleApi.h
wx_api_reflect_bool(AllocConsole);
// AllocConsoleWithOptions 

wx_api_reflect_bool(FreeConsole);
wx_api_reflect_bool(AttachConsole);
// GetConsoleCP
inline UINT GetConsoleCP()
	safe_ret_as(auto n = ::GetConsoleCP(), n);
// GetConsoleOutputCP
inline UINT GetConsoleOutputCP()
	safe_ret_as(auto n = ::GetConsoleOutputCP(), n);
wx_api_reflect_bool(GetConsoleMode);
wx_api_reflect_bool(SetConsoleMode);
wx_api_reflect_bool(GetNumberOfConsoleInputEvents);
#undef ReadConsoleInput
// ReadConsoleInput
template<bool IsUnicode = WX::IsUnicode>
inline void ReadConsoleInput(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead) {
	if_c (IsUnicode)
		 safe_ret_as(::ReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead))
	else safe_ret_as(::ReadConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead))
}
#undef PeekConsoleInput
// PeekConsoleInput
template<bool IsUnicode = WX::IsUnicode>
inline void PeekConsoleInput(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead) {
	if_c (IsUnicode)
		 safe_ret_as(::PeekConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead))
	else safe_ret_as(::PeekConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead))
}
#undef ReadConsole
// ReadConsole
template<bool IsUnicode = WX::IsUnicode>
inline void ReadConsole(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, PCONSOLE_READCONSOLE_CONTROL pInputControl) {
	if_c (IsUnicode)
		 safe_ret_as(::ReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, pInputControl))
	else safe_ret_as(::ReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, pInputControl))
}
#undef WriteConsole
// WriteConsole
inline void WriteConsole(HANDLE hConsoleOutput, LPCSTR lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
	safe_ret_as(::WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved));
inline void WriteConsole(HANDLE hConsoleOutput, LPCWSTR lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
	safe_ret_as(::WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved));
wx_api_reflect_bool(SetConsoleCtrlHandler);
#pragma endregion

#pragma region ConsoleApi2.h
#undef FillConsoleOutputCharacter
// FillConsoleOutputCharacter
inline void FillConsoleOutputCharacter(HANDLE hConsoleOutput, CHAR cCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten)
	safe_ret_as(::FillConsoleOutputCharacterA(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten));
inline void FillConsoleOutputCharacter(HANDLE hConsoleOutput, WCHAR cCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten)
	safe_ret_as(::FillConsoleOutputCharacterW(hConsoleOutput, cCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten));
wx_api_reflect_bool(FillConsoleOutputAttribute);
wx_api_reflect_bool(GenerateConsoleCtrlEvent);
// CreateConsoleScreenBuffer
inline HANDLE CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwFlags, HANDLE *lpBuffer)
	safe_ret_as(auto h = ::CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpBuffer); h != INVALID_HANDLE_VALUE, h);
wx_api_reflect_bool(SetConsoleActiveScreenBuffer);
wx_api_reflect_bool(FlushConsoleInputBuffer);
wx_api_reflect_bool(SetConsoleCP);
wx_api_reflect_bool(SetConsoleOutputCP);
wx_api_reflect_bool(GetConsoleCursorInfo);
wx_api_reflect_bool(SetConsoleCursorInfo);
wx_api_reflect_bool(GetConsoleScreenBufferInfo);
// GetConsoleScreenBufferInfoEx
inline void GetConsoleScreenBufferInfoEx(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx)
	safe_ret_as(::GetConsoleScreenBufferInfoEx(hConsoleOutput, lpConsoleScreenBufferInfoEx));
// SetConsoleScreenBufferInfoEx
inline void SetConsoleScreenBufferInfo(HANDLE hConsoleOutput, PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx)
	safe_ret_as(::SetConsoleScreenBufferInfoEx(hConsoleOutput, lpConsoleScreenBufferInfoEx));
wx_api_reflect_bool(SetConsoleScreenBufferSize);
wx_api_reflect_bool(SetConsoleCursorPosition);
// GetLargestConsoleWindowSize
inline COORD GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
	safe_ret_as(auto c = ::GetLargestConsoleWindowSize(hConsoleOutput); c.X && c.Y, c);
wx_api_reflect_bool(SetConsoleTextAttribute);
wx_api_reflect_bool(SetConsoleWindowInfo);
#undef WriteConsoleOutputCharacter
// WriteConsoleOutputCharacter
inline void WriteConsoleOutputCharacter(HANDLE hConsoleOutput, LPCSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten)
	safe_ret_as(::WriteConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten));
inline void WriteConsoleOutputCharacter(HANDLE hConsoleOutput, LPCWSTR lpCharacter, DWORD nLength, COORD dwWriteCoord, LPDWORD lpNumberOfCharsWritten)
	safe_ret_as(::WriteConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwWriteCoord, lpNumberOfCharsWritten));
wx_api_reflect_bool(WriteConsoleOutputAttribute);
#undef ReadConsoleOutputCharacter
inline void ReadConsoleOutputCharacter(HANDLE hConsoleOutput, LPSTR lpCharacter, DWORD nLength, COORD dwReadCoord, LPDWORD lpNumberOfCharsRead)
	safe_ret_as(::ReadConsoleOutputCharacterA(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead));
inline void ReadConsoleOutputCharacter(HANDLE hConsoleOutput, LPWSTR lpCharacter, DWORD nLength, COORD dwReadCoord, LPDWORD lpNumberOfCharsRead)
	safe_ret_as(::ReadConsoleOutputCharacterW(hConsoleOutput, lpCharacter, nLength, dwReadCoord, lpNumberOfCharsRead));
wx_api_reflect_bool(ReadConsoleOutputAttribute);
#undef WriteConsoleInput
// WriteConsoleInput
template<bool IsUnicode = WX::IsUnicode>
inline void WriteConsoleInput(HANDLE hConsoleInput, const INPUT_RECORD *lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsWritten) {
	if_c (IsUnicode)
		 safe_ret_as(::WriteConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten))
	else safe_ret_as(::WriteConsoleInputA(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsWritten))
}
#undef ScrollConsoleScreenBuffer
// ScrollConsoleScreenBuffer
template<bool IsUnicode = WX::IsUnicode>
inline void ScrollConsoleScreenBuffer(HANDLE hConsoleOutput, const SMALL_RECT *lpScrollRectangle, const SMALL_RECT *lpClipRectangle,
									  COORD dwDestinationOrigin, const CHAR_INFO *lpFill) {
	if_c (IsUnicode)
		 safe_ret_as(::ScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill))
	else safe_ret_as(::ScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRectangle, lpClipRectangle, dwDestinationOrigin, lpFill))
}
#undef WriteConsoleOutput
// WriteConsoleOutput
template<bool IsUnicode = WX::IsUnicode>
inline void WriteConsoleOutput(HANDLE hConsoleOutput, const CHAR_INFO *lpBuffer, COORD dwBufferSize, COORD dwBufferCoord,
							   PSMALL_RECT lpWriteRegion) {
	if_c (IsUnicode)
		 safe_ret_as(::WriteConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion))
	else safe_ret_as(::WriteConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpWriteRegion))
}
#undef ReadConsoleOutput
// ReadConsoleOutput
template<bool IsUnicode = WX::IsUnicode>
inline void ReadConsoleOutput(HANDLE hConsoleOutput, CHAR_INFO *lpBuffer, COORD dwBufferSize, COORD dwBufferCoord,
							  PSMALL_RECT lpReadRegion) {
	if_c (IsUnicode)
		 safe_ret_as(::ReadConsoleOutputW(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion))
	else safe_ret_as(::ReadConsoleOutputA(hConsoleOutput, lpBuffer, dwBufferSize, dwBufferCoord, lpReadRegion))
}
#undef GetConsoleTitle
// GetConsoleTitle
inline DWORD GetConsoleTitle(LPSTR lpConsoleTitle, DWORD nSize)
	safe_ret_as(auto n = ::GetConsoleTitleA(lpConsoleTitle, nSize), n);
inline DWORD GetConsoleTitle(LPWSTR lpConsoleTitle, DWORD nSize)
	safe_ret_as(auto n = ::GetConsoleTitleW(lpConsoleTitle, nSize), n);
#undef GetConsoleOriginalTitle
// GetConsoleOriginalTitle
inline DWORD GetConsoleOriginalTitle(LPSTR lpConsoleTitle, DWORD nSize)
	safe_ret_as(auto n = ::GetConsoleOriginalTitleA(lpConsoleTitle, nSize), n);
inline DWORD GetConsoleOriginalTitle(LPWSTR lpConsoleTitle, DWORD nSize)
	safe_ret_as(auto n = ::GetConsoleOriginalTitleW(lpConsoleTitle, nSize), n);
#undef SetConsoleTitle
// SetConsoleTitle
inline void SetConsoleTitle(LPCSTR lpConsoleTitle)
	safe_ret_as(::SetConsoleTitleA(lpConsoleTitle));
inline void SetConsoleTitle(LPCWSTR lpConsoleTitle)
	safe_ret_as(::SetConsoleTitleW(lpConsoleTitle));
#pragma endregion

#pragma region ConsoleApi3.h
// GetNumberOfConsoleMouseButtons
inline UINT GetNumberOfConsoleMouseButtons(LPDWORD lpNumberOfMouseButtons)
	safe_ret_as(auto n = ::GetNumberOfConsoleMouseButtons(lpNumberOfMouseButtons), n);
// GetConsoleFontSize
inline COORD GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont)
	safe_ret_as(auto c = ::GetConsoleFontSize(hConsoleOutput, nFont); c.X && c.Y, c);
wx_api_reflect_bool(GetCurrentConsoleFont);
// GetCurrentConsoleFontEx
inline void GetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFont)
	safe_ret_as(::GetCurrentConsoleFontEx(hConsoleOutput, bMaximumWindow, lpConsoleCurrentFont));
// SetCurrentConsoleFontEx
inline void SetCurrentConsoleFont(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX lpConsoleCurrentFont)
	safe_ret_as(::SetCurrentConsoleFontEx(hConsoleOutput, bMaximumWindow, lpConsoleCurrentFont));
wx_api_reflect_bool(GetConsoleSelectionInfo);
wx_api_reflect_bool(GetConsoleHistoryInfo);
wx_api_reflect_bool(SetConsoleHistoryInfo);
wx_api_reflect_bool(GetConsoleDisplayMode);
wx_api_reflect_bool(SetConsoleDisplayMode);
// GetConsoleWindow
inline HWND GetConsoleWindow()
	ret_as(::GetConsoleWindow());
#undef AddConsoleAlias
// AddConsoleAlias
inline void AddConsoleAlias(LPSTR Source, LPSTR Target, LPSTR ExeName)
	safe_ret_as(::AddConsoleAliasA(Source, Target, ExeName));
inline void AddConsoleAlias(LPWSTR Source, LPWSTR Target, LPWSTR ExeName)
	safe_ret_as(::AddConsoleAliasW(Source, Target, ExeName));
#undef GetConsoleAlias
// GetConsoleAlias
inline DWORD GetConsoleAlias(LPSTR Source, LPSTR TargetBuffer, DWORD TargetBufferLength, LPSTR ExeName)
	safe_ret_as(auto n = ::GetConsoleAliasA(Source, TargetBuffer, TargetBufferLength, ExeName), n);
inline DWORD GetConsoleAlias(LPWSTR Source, LPWSTR TargetBuffer, DWORD TargetBufferLength, LPWSTR ExeName)
	safe_ret_as(auto n = ::GetConsoleAliasW(Source, TargetBuffer, TargetBufferLength, ExeName), n);
#undef GetConsoleAliasesLength
// GetConsoleAliasesLength
inline DWORD GetConsoleAliasesLength(LPSTR ExeName)
	ret_as(::GetConsoleAliasesLengthA(ExeName));
inline DWORD GetConsoleAliasesLength(LPWSTR ExeName)
	ret_as(::GetConsoleAliasesLengthW(ExeName));
#undef GetConsoleAliasExesLength
// GetConsoleAliasExesLength
template<bool IsUnicode = WX::IsUnicode>
inline DWORD GetConsoleAliasExesLength() {
	if_c (IsUnicode)
		 ret_as(::GetConsoleAliasExesLengthA())
	else ret_as(::GetConsoleAliasExesLengthA())
}
#undef GetConsoleAliases
// GetConsoleAliases
inline DWORD GetConsoleAliases(LPSTR AliasBuffer, DWORD AliasBufferLength, LPSTR ExeName)
	safe_ret_as(auto n = ::GetConsoleAliasesA(AliasBuffer, AliasBufferLength, ExeName), n);
inline DWORD GetConsoleAliases(LPWSTR AliasBuffer, DWORD AliasBufferLength, LPWSTR ExeName)
	safe_ret_as(auto n = ::GetConsoleAliasesW(AliasBuffer, AliasBufferLength, ExeName), n);
#undef GetConsoleAliasExes
// GetConsoleAliasExes
inline DWORD GetConsoleAliasExes(LPSTR ExeNameBuffer, DWORD ExeNameBufferLength)
	safe_ret_as(auto n = ::GetConsoleAliasExesA(ExeNameBuffer, ExeNameBufferLength), n);
inline DWORD GetConsoleAliasExes(LPWSTR ExeNameBuffer, DWORD ExeNameBufferLength)
	safe_ret_as(auto n = ::GetConsoleAliasExesW(ExeNameBuffer, ExeNameBufferLength), n);
// GetConsoleProcessList
inline DWORD GetConsoleProcessList(LPDWORD lpdwProcessList, DWORD dwProcessCount)
	safe_ret_as(auto n = ::GetConsoleProcessList(lpdwProcessList, dwProcessCount), n);
#pragma endregion

}
#endif
export namespace WX {

enum_flags(ConsoleAttribute, WORD,
/*	Foreground------------------------------------------------------------------------------------------*/
	ForegroundRed          = FOREGROUND_RED                                                             ,
	ForegroundGreen        =                  FOREGROUND_GREEN                                          ,
	ForegroundBlue         =                                     FOREGROUND_BLUE                        ,
	ForegroundIntensity    =                                                       FOREGROUND_INTENSITY ,
/*	Background------------------------------------------------------------------------------------------*/
	BackgroundRed          = BACKGROUND_RED                                                             ,
	BackgroundGreen        =                  BACKGROUND_GREEN                                          ,
	BackgroundBlue         =                                     BACKGROUND_BLUE                        ,
	BackgroundIntensity    =                                                       BACKGROUND_INTENSITY ,
/*	Aliases Foreground----------------------------------------------------------------------------------*/
	Red                    = FOREGROUND_RED                                                             ,
	Green                  =                  FOREGROUND_GREEN                                          ,
	Blue                   =                                     FOREGROUND_BLUE                        ,
	Gray                   =                                                       FOREGROUND_INTENSITY ,
/*	Aliases Background----------------------------------------------------------------------------------*/	
	BkRed                  = BACKGROUND_RED                                                             ,
	BkGreen                =                  BACKGROUND_GREEN                                          ,
	BkBlue                 =                                     BACKGROUND_BLUE                        ,
	BkGray                 =                                                       BACKGROUND_INTENSITY ,
/*	Other Colors Forground------------------------------------------------------------------------------*/
	Black                  = 0                                                                          ,
	Aqua                   =                  FOREGROUND_GREEN | FOREGROUND_BLUE                        ,
	Purple                 = FOREGROUND_RED |                    FOREGROUND_BLUE                        ,
	Yellow                 = FOREGROUND_RED | FOREGROUND_GREEN                                          ,
	White                  = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE                        ,
	LightBlue              =                                     FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
	LightGreen             =                  FOREGROUND_GREEN |                   FOREGROUND_INTENSITY ,
	LightAqua              =                  FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
	LightRed               = FOREGROUND_RED |                                      FOREGROUND_INTENSITY ,
	LightPurple            = FOREGROUND_RED |                    FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
	LightYellow            = FOREGROUND_RED | FOREGROUND_GREEN |                   FOREGROUND_INTENSITY ,
	BrightWhite            = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
/*	Other Colors Background-----------------------------------------------------------------------------*/
	BkBlack                = 0                                                                          ,
	BkAqua                 =                  BACKGROUND_GREEN | BACKGROUND_BLUE                        ,
	BkPurple               = BACKGROUND_RED |                    BACKGROUND_BLUE                        ,
	BkYellow               = BACKGROUND_RED | BACKGROUND_GREEN                                          ,
	BkWhite                = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE                        ,
	BkLightBlue            =                                     BACKGROUND_BLUE | BACKGROUND_INTENSITY ,
	BkLightGreen           =                  BACKGROUND_GREEN |                   BACKGROUND_INTENSITY ,
	BkLightAqua            =                  BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY ,
	BkLightRed             = BACKGROUND_RED |                                      BACKGROUND_INTENSITY ,
	BkLightPurple          = BACKGROUND_RED |                    BACKGROUND_BLUE | BACKGROUND_INTENSITY ,
	BkLightYellow          = BACKGROUND_RED | BACKGROUND_GREEN |                   BACKGROUND_INTENSITY ,
	BkBrightWhite          = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY ,
/*	Mask------------------------------------------------------------------------------------------------*/
	Foreground             = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
	Background             = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
alias_of_type(ConsoleColor, ConsoleAttribute);
enum_flags(
	ConsoleSelectionFlag, DWORD                        ,
	No                  = CONSOLE_NO_SELECTION         ,
	InProgress          = CONSOLE_SELECTION_IN_PROGRESS,
	NotEmpty            = CONSOLE_SELECTION_NOT_EMPTY  ,
	MouseSelection      = CONSOLE_MOUSE_SELECTION      ,
	MouseDown           = CONSOLE_MOUSE_DOWN           );
proxy_struct       (ConsoleSelectionInfo     , CONSOLE_SELECTION_INFO                            ) {
	proxy_prop_sync(Flags                    , dwFlags                     , ConsoleSelectionFlag);
	proxy_prop_sync(Anchor                   , dwSelectionAnchor           , LPoint              );
	proxy_prop_sync(Rect                     , srSelection                 , LRect               );};
proxy_struct       (ConsoleHistoryInfo       , CONSOLE_HISTORY_INFO, cbSize                      ) {
	proxy_prop_sync(BufferSize               , HistoryBufferSize           , UINT                );
	proxy_prop_sync(NumberOfBuffers          , HistoryBufferSize           , UINT                );
	proxy_prop_sync(NoDuplication            , dwFlags                     , bool                );};
proxy_struct       (ConsoleCursorInfo        , CONSOLE_CURSOR_INFO                               ) {
	proxy_prop_sync(Size                     , dwSize                      , DWORD               );
	proxy_prop_sync(Visible                  , bVisible                    , bool                );};
proxy_struct       (ConsoleScreenBufferInfo  , CONSOLE_SCREEN_BUFFER_INFO                        ) {
	proxy_prop_sync(Size                     , dwSize                      , LSize               );
	proxy_prop_sync(CursorPosition           , dwCursorPosition            , LPoint              );
	proxy_prop_sync(Attributes               , wAttributes                 , ConsoleAttribute    );
	proxy_prop_sync(WindowRect               , srWindow                    , LRect               );
	proxy_prop_sync(MaximumWindowSize        , dwMaximumWindowSize         , LSize               );};
proxy_struct       (ConsoleScreenBufferInfoEx, CONSOLE_SCREEN_BUFFER_INFOEX, cbSize              ) {
	proxy_prop_sync(Size                     , dwSize                      , LSize               );
	proxy_prop_sync(CursorPosition           , dwCursorPosition            , LPoint              );
	proxy_prop_sync(Attributes               , wAttributes                 , ConsoleAttribute    );
	proxy_prop_sync(WindowRect               , srWindow                    , LRect               );
	proxy_prop_sync(MaximumWindowSize        , dwMaximumWindowSize         , LSize               );
	proxy_prop_sync(PopupAttributes          , wPopupAttributes            , ConsoleAttribute    );
	proxy_prop_sync(FullscreenSupported      , bFullscreenSupported        , bool                );
public: // Property      ColorTable
	/* W */ inline auto &ColorTable                                   (const COLORREF *lpColorTable) {
		for (int i = 0; i < 16; ++i)
			self->ColorTable[i] = lpColorTable[i];
		return *this;
	}
	/* R */ inline const COLORREF *ColorTable                                   () const { return self->ColorTable; }
};
enum_flags(
	ConsoleMode            , DWORD                                          ,
/*	Input modes-------------------------------------------------------------*/
	InputProcessed         = ENABLE_PROCESSED_INPUT                         ,
	InputLine              = ENABLE_LINE_INPUT                              ,
	InputEcho              = ENABLE_ECHO_INPUT                              ,
	InputWindow            = ENABLE_WINDOW_INPUT                            ,
	InputMouse             = ENABLE_MOUSE_INPUT                             ,
	InputInsertMode        = ENABLE_INSERT_MODE                             ,
	InputQuickEdit         = ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS ,
	InputQuickEditDisable  = ENABLE_EXTENDED_FLAGS                          ,
	AutoPosition           = ENABLE_AUTO_POSITION                           ,
/*	Output modes------------------------------------------------------------*/
	OutputProcessed        = ENABLE_PROCESSED_OUTPUT                        ,
	OutputWrapAtEol        = ENABLE_WRAP_AT_EOL_OUTPUT                      ,
	OutputVirtualTerminal  = ENABLE_VIRTUAL_TERMINAL_PROCESSING             ,
	OutputLvbGridWorldwide = ENABLE_LVB_GRID_WORLDWIDE                     );

	#define autor auto&
class ConsoleHandleOutput : public HandleBase<ConsoleHandleOutput> {
public:
	using Super = HandleBase<ConsoleHandleOutput>;
protected:
	friend_to_proxy(ConsoleHandleOutput);
	ConsoleHandleOutput(HANDLE h) : Super(h) {}
public:
	ConsoleHandleOutput() : Super(WX::GetStdHandle(STD_OUTPUT_HANDLE)) {}
	ConsoleHandleOutput(Nu) {}
public:
	inline void ActiveScreenBuffer() ret_to(WX::SetConsoleActiveScreenBuffer(self));
public:
	inline DWORD Fill(CHAR cCharacter, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(WX::FillConsoleOutputCharacter(self, cCharacter, nLength, dwWriteCoord, &nLength), nLength);
	inline DWORD Fill(WCHAR cCharacter, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(WX::FillConsoleOutputCharacter(self, cCharacter, nLength, dwWriteCoord, &nLength), nLength);

	inline DWORD FillAttributes(WORD wAttributes, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(WX::FillConsoleOutputAttribute(self, wAttributes, nLength, dwWriteCoord, &nLength), nLength);
	inline DWORD FillAttributes(ConsoleAttribute wAttributes, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(FillAttributes(wAttributes, nLength, dwWriteCoord));

	inline DWORD Write(LPCSTR lpszString, DWORD nLength)
		ret_as(WX::WriteConsole(self, lpszString, nLength, &nLength, O), nLength);
	inline DWORD Write(LPCWSTR lpszString, DWORD nLength)
		ret_as(WX::WriteConsole(self, lpszString, nLength, &nLength, O), nLength);
	inline DWORD Write(const StringA& str)
		ret_as(Write((LPCSTR)str, (DWORD)str.Length()));
	inline DWORD Write(const StringW& str)
		ret_as(Write((LPCWSTR)str, (DWORD)str.Length()));
	template<SizeT len>
	inline DWORD Write(const CHAR(&lpszString)[len])
		ret_as(Write(lpszString, (DWORD)(len - 1)));
	template<SizeT len>
	inline DWORD Write(const WCHAR(&lpszString)[len])
		ret_as(Write(lpszString, (DWORD)(len - 1)));
	inline DWORD Write(WCHAR ch)
		ret_as(Write(&ch, 1));
	inline DWORD Write(CHAR ch)
		ret_as(Write(&ch, 1));

	inline DWORD Write(LPCSTR lpszString, DWORD nLength, LPoint dwWriteCoord)
		ret_as(WX::WriteConsoleOutputCharacter(self, lpszString, nLength, dwWriteCoord, &nLength), nLength);
	inline DWORD Write(LPCWSTR lpszString, DWORD nLength, LPoint dwWriteCoord)
		ret_as(WX::WriteConsoleOutputCharacter(self, lpszString, nLength, dwWriteCoord, &nLength), nLength);
	inline DWORD Write(const StringA& str, LPoint dwWriteCoord)
		ret_as(Write((LPCSTR)str, (DWORD)str.Length(), dwWriteCoord));
	inline DWORD Write(const StringW& str, LPoint dwWriteCoord)
		ret_as(Write((LPCWSTR)str, (DWORD)str.Length(), dwWriteCoord));
	template<SizeT len>
	inline DWORD Write(const CHAR(&lpszString)[len], LPoint dwWriteCoord)
		ret_as(Write(lpszString, (DWORD)(len - 1), dwWriteCoord));
	template<SizeT len>
	inline DWORD Write(const WCHAR(&lpszString)[len], LPoint dwWriteCoord)
		ret_as(Write(lpszString, (DWORD)(len - 1), dwWriteCoord));

	inline DWORD WriteAttributes(const WORD* lpAttributes, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(WX::WriteConsoleOutputAttribute(self, lpAttributes, nLength, dwWriteCoord, &nLength), nLength);
	inline DWORD WriteAttributes(const ConsoleAttribute * lpAttributes, DWORD nLength, LPoint dwWriteCoord = 0)
		ret_as(WriteAttributes((const WORD*)lpAttributes, nLength, dwWriteCoord));
	template<SizeT len>
	inline DWORD WriteAttributes(const WORD(&lpAttributes)[len], LPoint dwWriteCoord = 0)
		ret_as(WriteAttributes(lpAttributes, (DWORD)len, dwWriteCoord));
	template<SizeT len>
	inline DWORD WriteAttributes(const ConsoleAttribute(&lpAttributes)[len], LPoint dwWriteCoord = 0)
		ret_as(WriteAttributes((const WORD*)lpAttributes, (DWORD)len, dwWriteCoord));

	inline DWORD Read(LPSTR lpszBuffer, DWORD nLength, LPoint dwReadCoord = 0)
		ret_as(WX::ReadConsoleOutputCharacter(self, lpszBuffer, nLength, dwReadCoord, &nLength), nLength);
	inline DWORD Read(LPWSTR lpszBuffer, DWORD nLength, LPoint dwReadCoord = 0)
		ret_as(WX::ReadConsoleOutputCharacter(self, lpszBuffer, nLength, dwReadCoord, &nLength), nLength);
	inline DWORD Read(StringA& str, LPoint dwReadCoord = 0) ret_as(Read(str, (DWORD)str.Length(), dwReadCoord));
	inline DWORD Read(StringW& str, LPoint dwReadCoord = 0) ret_as(Read(str, (DWORD)str.Length(), dwReadCoord));
	template<SizeT len>
	inline DWORD Read(CHAR(&lpszBuffer)[len], LPoint dwReadCoord = 0)
		ret_as(Read(lpszBuffer, (DWORD)(len - 1), dwReadCoord));
	template<SizeT len>
	inline DWORD Read(WCHAR(&lpszBuffer)[len], LPoint dwReadCoord = 0)
		ret_as(Read(lpszBuffer, (DWORD)(len - 1), dwReadCoord));

	inline String Read(DWORD nLength, LPoint dwReadCoord = 0)
		ret_to(String buf{ (SizeT)nLength }; buf.Resize(Read(buf, dwReadCoord)), right_hand_cast(buf));
	inline StringA ReadA(DWORD nLength, LPoint dwReadCoord = 0)
		ret_to(StringA buf{ (SizeT)nLength }; buf.Resize(Read(buf, dwReadCoord)), right_hand_cast(buf));
	inline StringW ReadW(DWORD nLength, LPoint dwReadCoord = 0)
		ret_to(StringW buf{ (SizeT)nLength }; buf.Resize(Read(buf, dwReadCoord)), right_hand_cast(buf));

	inline DWORD Read(WORD* lpAttributes, DWORD nLength, LPoint dwReadCoord = 0)
		ret_as(WX::ReadConsoleOutputAttribute(self, lpAttributes, nLength, dwReadCoord, &nLength), nLength);
	inline DWORD Read(ConsoleAttribute * lpAttributes, DWORD nLength, LPoint dwReadCoord = 0)
		ret_as(Read((WORD*)lpAttributes, nLength, dwReadCoord));
	template<SizeT len>
	inline DWORD Read(WORD(&lpAttributes)[len], LPoint dwReadCoord = 0)
		ret_as(Read(lpAttributes, (DWORD)len, dwReadCoord));
	template<SizeT len>
	inline DWORD Read(ConsoleAttribute(&lpAttributes)[len], LPoint dwReadCoord = 0)
		ret_as(Read((WORD*)lpAttributes, (DWORD)len, dwReadCoord));
#pragma region Properties
public: // Property      WindowSize
//	/ * W */ inline autor     WindowSize                                   (LRect rect) ret_to_self(SetConsoleWindowInfo(self, TRUE, ));
//	/ * R */ inline auto  WindowSize            () const ret_as(ScreenBufferInfo().WindowRect().size());
public: // Property      FullScreen
//	/ * A */ inline autor     FullScreenHardware                                   () ret_to_self(WX::SetConsoleDisplayMode(self, CONSOLE_FULLSCREEN_HARDWARE, O));
	/* W */ inline autor FullScreen            ( bool bFullScreen) ret_to_self(WX::SetConsoleDisplayMode(self, bFullScreen ? CONSOLE_FULLSCREEN_MODE : CONSOLE_WINDOWED_MODE, O));
	/* R */ inline bool  FullScreen            () const ret_to(DWORD mode = 0; WX::GetConsoleDisplayMode(&mode), mode == CONSOLE_FULLSCREEN_MODE);
public: // Property      Mode
	/* W */ inline autor Modes                 ( ConsoleMode modes) ret_to_self(WX::SetConsoleMode(self, (DWORD)modes));
	/* R */ inline auto  Modes                 () const ret_to(DWORD modes, WX::GetConsoleMode(self, &modes), reuse_cast<ConsoleMode>(modes));
public: // Property      CursorInfo
	/* W */ inline autor CursorInfo            ( ConsoleCursorInfo cci) ret_to_self(WX::SetConsoleCursorInfo(self, &cci));
	/* R */ inline auto  CursorInfo            () const ret_to(ConsoleCursorInfo cci, WX::GetConsoleCursorInfo(self, &cci), cci);
public: // Property      ScreenBufferInfo
//    / * W */ inline autor ScreenBufferInfo      ( ConsoleScreenBufferInfoEx sbiex) ret_to_self(WX::SetConsoleScreenBufferInfo(self, &sbiex));
	/* R */ inline auto  ScreenBufferInfo      () const ret_to(ConsoleScreenBufferInfo sbi, WX::GetConsoleScreenBufferInfo(self, &sbi), sbi);
public: // Property      ScreenBufferInfoEx
	/* R */ inline auto  ScreenBufferInfoEx    () const ret_to(ConsoleScreenBufferInfoEx sbiex, WX::GetConsoleScreenBufferInfoEx(self, &sbiex), sbiex);
	
#define wx_vprop_set(name, type, setter) inline auto&name(type) ret_to_self(setter)
#define wx_vprop_get(name, getter) inline auto name(    ) const ret_as     (getter)
#define wx_vprop_map(name, type, setter, getter) \
		wx_vprop_set(name, type, setter); \
		wx_vprop_get(name, getter)

	wx_vprop_map(ScreenBufferSize, LSize                   size, WX::SetConsoleScreenBufferSize(self, size)          , ScreenBufferInfo().Size()          );
	wx_vprop_map(Attributes      , ConsoleAttribute wAttributes, WX::SetConsoleTextAttribute(self, (WORD)wAttributes), ScreenBufferInfo().Attributes()    );
	wx_vprop_map(CursorPosition  , LPoint                     p, WX::SetConsoleCursorPosition(self, p)               , ScreenBufferInfo().CursorPosition());
	wx_vprop_map(CursorVisible   , bool                bVisible, CursorInfo(CursorInfo().Visible(bVisible))          , CursorInfo().Visible()             );
#pragma endregion
};
class ConsoleHandleInput : public HandleBase<ConsoleHandleInput> {
public:
	using Super = HandleBase<ConsoleHandleInput>;
protected:
	friend_to_proxy(ConsoleHandleInput);
	ConsoleHandleInput(HANDLE h) : Super(h) {}
public:
	ConsoleHandleInput() : Super(WX::GetStdHandle(STD_INPUT_HANDLE)) {}
	ConsoleHandleInput(Nu) {}
public:
	inline void FlushInputBuffer() ret_to(WX::FlushConsoleInputBuffer(self));
};
class IConsole : public ConsoleHandleOutput {
protected:
	HANDLE hError = O;
public:
public:
	IConsole(Nu) {}
	IConsole() : hError(WX::GetStdHandle(STD_ERROR_HANDLE)) {}
	IConsole(DWORD pid) ret_to(Attach(pid));
public:
	inline void Attach(DWORD pid) ret_to(WX::AttachConsole(pid));
	inline void Alloc() ret_to(WX::AllocConsole());
	inline void Free() ret_to(WX::FreeConsole());

	inline void Select() {
		static FILE* fout = O, * ferr = O, * fin = O;
		freopen_s(&fout, "CONOUT$", "w+t", stdout);
		freopen_s(&ferr, "CONERR$", "w+t", stderr);
		freopen_s(&fin, "CONIN$", "r+t", stdin);
	}
public:
	inline void Clear() ret_to(Fill(T(' '), ScreenBufferInfo().Size().Square()); CursorPosition(0));
	inline void Color(ConsoleAttribute wAttributes) ret_to(FillAttributes(wAttributes, ScreenBufferInfo().Size().Square()); Attributes(wAttributes));
public:
	inline DWORD Format(LPCSTR lpFormat, ...) {
		va_list argList;
		va_start(argList, lpFormat);
		auto bytes = Write(format(lpFormat, argList));
		va_end(argList);
		return bytes;
	}
	inline DWORD Format(LPCWSTR lpFormat, ...) {
		va_list argList;
		va_start(argList, lpFormat);
		auto bytes = Write(format(lpFormat, argList));
		va_end(argList);
		return bytes;
	}
//public: // Property      Window
//	inline CWindow Window() const ret_as(WX::GetConsoleWindow());
#pragma region Properties
public: // Property      Title
	template<class TCHAR>
	/* W */ inline autor Title                 ( const TCHAR *lpTitle) ret_to_self(WX::SetConsoleTitle(lpTitle));
	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto Title                                   () const {
		StringX<IsUnicode> str(MaxLen);
		auto len = WX::GetConsoleTitle(str, (int)MaxLen);
		return right_hand_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto  TitleA                () const ret_as(Title<false, MaxLen>());
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto  TitleW                () const ret_as(Title<true, MaxLen>());
public: // Property      OriginalTitle

	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitle () const {
		StringX<IsUnicode> str(MaxLen);
		auto len = WX::GetConsoleOriginalTitle(str, (int)MaxLen);
		return right_hand_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleA        () const ret_as(OriginalTitle<false, MaxLen>());
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleW        () const ret_as(OriginalTitle<true, MaxLen>());

public: // Property      CodePage
	/* W */ inline autor CodePage              ( UINT uCodePage) ret_to_self(WX::SetConsoleCP(uCodePage));
	/* R */ inline UINT  CodePage              () const ret_as(WX::GetConsoleCP());
public: // Property      OutputCodePage
	/* W */ inline autor OutputCodePage        ( UINT uCodePage) ret_to_self(WX::SetConsoleOutputCP(uCodePage));
	/* R */ inline UINT  OutputCodePage        () const ret_as(WX::GetConsoleOutputCP());
public: // Property      SelectionInfo
	/* R */ inline auto  SelectionInfo         () const ret_to(ConsoleSelectionInfo csi, WX::GetConsoleSelectionInfo(&csi), csi);
public: // Property      HistoryInfo
	/* W */ inline autor HistoryInfo           ( CONSOLE_HISTORY_INFO chi) ret_to_self(WX::SetConsoleHistoryInfo(&chi));
	/* R */ inline auto  HistoryInfo           () const ret_to(ConsoleHistoryInfo chi, WX::GetConsoleHistoryInfo(&chi), chi);
#pragma endregion   

public:
	inline auto &operator[](LPoint p) ret_as(CursorPosition(p));
	inline auto &operator[](bool bCurVis) ret_as(CursorVisible(bCurVis));
} Console;

}
