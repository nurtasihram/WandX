module;

#define autor auto&

#define wx_vprop_set(name, type, set)     inline auto&name(type value) ret_to_self(mx_kill_braces(set))
#define wx_vprop_get(name, type, get)     inline type name(          ) const { mx_kill_braces(get); }

#define wx_vprop_get_dir(name, type, get) wx_vprop_get(name, type, (return get))
#define wx_vprop_get_def(name, type, get) wx_vprop_get(name, type, (type value; mx_kill_braces(get); return value))

#define wx_vprop_map(name, type, set, get) \
		wx_vprop_set(name, type, set); \
		wx_vprop_get(name, type, get)
#define wx_vprop_map_dir(name, type, set, get) \
		wx_vprop_set(name, type, set); \
		wx_vprop_get_dir(name, type, get)
#define wx_vprop_map_def(name, type, set, get) \
		wx_vprop_set(name, type, set); \
		wx_vprop_get_def(name, type, get)

#define wx_method

#ifndef WX_IDL_IMPORT

#define WX_CPPM_CONSOLE
#include "wx_console"

export module wx.console;

import wx.win32;

namespace WX {

constexpr auto ThisFile = LiString("wx.console");

#pragma region ProcessEnv.h (part)
wapi_reflect_handle(GetStdHandle);
wapi_reflect_bool(SetStdHandle);
wapi_reflect_bool(SetStdHandleEx);
#pragma endregion

#pragma region ConsoleApi.h
wapi_reflect_bool(AllocConsole);
// AllocConsoleWithOptions 
wapi_reflect_bool(FreeConsole);
wapi_reflect_bool(AttachConsole);
wapi_reflect_bool(GetConsoleCP, UINT);
wapi_reflect_bool(GetConsoleOutputCP, UINT);
wapi_reflect_bool(GetConsoleMode);
wapi_reflect_bool(SetConsoleMode);
wapi_reflect_bool(GetNumberOfConsoleInputEvents);
#undef ReadConsoleInput
wapi_reflect_bool_WAT(ReadConsoleInput);
#undef PeekConsoleInput
wapi_reflect_bool_WAT(PeekConsoleInput);
#undef ReadConsole
wapi_reflect_bool_WAT(ReadConsole);
#undef WriteConsole
wapi_reflect_bool_WAT(WriteConsole);
wapi_reflect_bool(SetConsoleCtrlHandler);
#pragma endregion

#pragma region ConsoleApi2.h
#undef FillConsoleOutputCharacter
wapi_reflect_bool_WAT(FillConsoleOutputCharacter);
wapi_reflect_bool(FillConsoleOutputAttribute);
wapi_reflect_bool(GenerateConsoleCtrlEvent);
wapi_reflect_handle(CreateConsoleScreenBuffer);
wapi_reflect_bool(SetConsoleActiveScreenBuffer);
wapi_reflect_bool(FlushConsoleInputBuffer);
wapi_reflect_bool(SetConsoleCP);
wapi_reflect_bool(SetConsoleOutputCP);
wapi_reflect_bool(GetConsoleCursorInfo);
wapi_reflect_bool(SetConsoleCursorInfo);
wapi_reflect_bool(GetConsoleScreenBufferInfo);
wapi_reflect_bool(GetConsoleScreenBufferInfoEx);
wapi_reflect_bool(SetConsoleScreenBufferInfoEx);
wapi_reflect_bool(SetConsoleScreenBufferSize);
wapi_reflect_bool(SetConsoleCursorPosition);
// GetLargestConsoleWindowSize
inline COORD GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
	safe_ret_as(auto c = ::GetLargestConsoleWindowSize(hConsoleOutput); c.X && c.Y, c);
wapi_reflect_bool(SetConsoleTextAttribute);
wapi_reflect_bool(SetConsoleWindowInfo);
#undef WriteConsoleOutputCharacter
wapi_reflect_bool_WAO(WriteConsoleOutputCharacter);
wapi_reflect_bool(WriteConsoleOutputAttribute);
#undef ReadConsoleOutputCharacter
wapi_reflect_bool_WAO(ReadConsoleOutputCharacter);
wapi_reflect_bool(ReadConsoleOutputAttribute);
#undef WriteConsoleInput
wapi_reflect_bool_WAT(WriteConsoleInput);
#undef ScrollConsoleScreenBuffer
wapi_reflect_bool_WAT(ScrollConsoleScreenBuffer);
#undef WriteConsoleOutput
wapi_reflect_bool_WAT(WriteConsoleOutput);
#undef ReadConsoleOutput
wapi_reflect_bool_WAT(ReadConsoleOutput);
#undef GetConsoleTitle
wapi_reflect_bool_WAO(GetConsoleTitle, int);
#undef GetConsoleOriginalTitle
wapi_reflect_bool_WAO(GetConsoleOriginalTitle, int);
#undef SetConsoleTitle
wapi_reflect_bool_WAO(SetConsoleTitle);
#pragma endregion

#pragma region ConsoleApi3.h
wapi_reflect_bool(GetNumberOfConsoleMouseButtons, UINT);
// GetConsoleFontSize
inline COORD GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont)
	safe_ret_as(auto c = ::GetConsoleFontSize(hConsoleOutput, nFont); c.X && c.Y, c);
wapi_reflect_bool(GetCurrentConsoleFont);
wapi_reflect_bool(GetCurrentConsoleFontEx);
wapi_reflect_bool(SetCurrentConsoleFontEx);
wapi_reflect_bool(GetConsoleSelectionInfo);
wapi_reflect_bool(GetConsoleHistoryInfo);
wapi_reflect_bool(SetConsoleHistoryInfo);
wapi_reflect_bool(GetConsoleDisplayMode);
wapi_reflect_bool(SetConsoleDisplayMode);
wapi_reflect_pure(GetConsoleWindow);
#undef AddConsoleAlias
wapi_reflect_bool_WAO(AddConsoleAlias);
#undef GetConsoleAlias
wapi_reflect_bool_WAO(GetConsoleAlias);
#undef GetConsoleAliasesLength
wapi_reflect_bool_WAO(GetConsoleAliasesLength);
#undef GetConsoleAliasExesLength
wapi_reflect_pure_WAT(GetConsoleAliasExesLength);
#undef GetConsoleAliases
wapi_reflect_bool_WAO(GetConsoleAliases);
#undef GetConsoleAliasExes
wapi_reflect_bool_WAO(GetConsoleAliasExes);
wapi_reflect_bool(GetConsoleProcessList, DWORD);
#pragma endregion

}


export namespace WX {
#endif

enum_flags(ConsoleAttribute       , WORD                                                                       ,
		/* Foreground------------------------------------------------------------------------------------------*/
		   ForegroundRed          = FOREGROUND_RED                                                             ,
		   ForegroundGreen        =                  FOREGROUND_GREEN                                          ,
		   ForegroundBlue         =                                     FOREGROUND_BLUE                        ,
		   ForegroundIntensity    =                                                       FOREGROUND_INTENSITY ,
		/* Background------------------------------------------------------------------------------------------*/
		   BackgroundRed          = BACKGROUND_RED                                                             ,
		   BackgroundGreen        =                  BACKGROUND_GREEN                                          ,
		   BackgroundBlue         =                                     BACKGROUND_BLUE                        ,
		   BackgroundIntensity    =                                                       BACKGROUND_INTENSITY ,
		/* Aliases Foreground----------------------------------------------------------------------------------*/
		   Red                    = FOREGROUND_RED                                                             ,
		   Green                  =                  FOREGROUND_GREEN                                          ,
		   Blue                   =                                     FOREGROUND_BLUE                        ,
		   Gray                   =                                                       FOREGROUND_INTENSITY ,
		/* Aliases Background----------------------------------------------------------------------------------*/
		   BkRed                  = BACKGROUND_RED                                                             ,
		   BkGreen                =                  BACKGROUND_GREEN                                          ,
		   BkBlue                 =                                     BACKGROUND_BLUE                        ,
		   BkGray                 =                                                       BACKGROUND_INTENSITY ,
		/* Other Colors Forground------------------------------------------------------------------------------*/
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
		/* Other Colors Background-----------------------------------------------------------------------------*/
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
		/* Mask------------------------------------------------------------------------------------------------*/
		   Foreground             = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY ,
		   Background             = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
alias_of_type(ConsoleColor, ConsoleAttribute);
enum_flags(ConsoleSelectionFlag, DWORD                        ,
		   No                  = CONSOLE_NO_SELECTION         ,
		   InProgress          = CONSOLE_SELECTION_IN_PROGRESS,
		   NotEmpty            = CONSOLE_SELECTION_NOT_EMPTY  ,
		   MouseSelection      = CONSOLE_MOUSE_SELECTION      ,
		   MouseDown           = CONSOLE_MOUSE_DOWN           );
proxy_struct       (ConsoleSelectionInfo     , CONSOLE_SELECTION_INFO                             ) {
	proxy_prop_sync(Flags                    , dwFlags                     , ConsoleSelectionFlag );
	proxy_prop_sync(Anchor                   , dwSelectionAnchor           , LPoint               );
	proxy_prop_sync(Rect                     , srSelection                 , LRect                );};
proxy_struct       (ConsoleHistoryInfo       , CONSOLE_HISTORY_INFO                               ) {
	proxy_prop_size(                           cbSize                      , UINT                 );
	proxy_prop_sync(BufferSize               , HistoryBufferSize           , UINT                 );
	proxy_prop_sync(NumberOfBuffers          , HistoryBufferSize           , UINT                 );
	proxy_prop_sync(NoDuplication            , dwFlags                     , bool                 );};
proxy_struct       (ConsoleCursorInfo        , CONSOLE_CURSOR_INFO                                ) {
	proxy_prop_sync(Size                     , dwSize                      , DWORD                );
	proxy_prop_sync(Visible                  , bVisible                    , bool                 );};
proxy_struct       (ConsoleScreenBufferInfo  , CONSOLE_SCREEN_BUFFER_INFO                         ) {
	proxy_prop_sync(Size                     , dwSize                      , LSize                );
	proxy_prop_sync(CursorPosition           , dwCursorPosition            , LPoint               );
	proxy_prop_sync(Attributes               , wAttributes                 , ConsoleAttribute     );
	proxy_prop_sync(WindowRect               , srWindow                    , LRect                );
	proxy_prop_sync(MaximumWindowSize        , dwMaximumWindowSize         , LSize                );};
proxy_struct       (ConsoleScreenBufferInfoEx, CONSOLE_SCREEN_BUFFER_INFOEX                       ) {
	proxy_prop_size(                           cbSize                      , ULONG                );
	proxy_prop_sync(Size                     , dwSize                      , LSize                );
	proxy_prop_sync(CursorPosition           , dwCursorPosition            , LPoint               );
	proxy_prop_sync(Attributes               , wAttributes                 , ConsoleAttribute     );
	proxy_prop_sync(WindowRect               , srWindow                    , LRect                );
	proxy_prop_sync(MaximumWindowSize        , dwMaximumWindowSize         , LSize                );
	proxy_prop_sync(PopupAttributes          , wPopupAttributes            , ConsoleAttribute     );
	proxy_prop_sync(FullscreenSupported      , bFullscreenSupported        , bool                 );
	proxy_prop_arrc(ColorTable               , ColorTable                  , COLORREF             );};
enum_flags(ConsoleMode            , DWORD                                          ,
		   Default                = 0                                              ,
		/* Input modes-------------------------------------------------------------*/
		   InputProcessed         = ENABLE_PROCESSED_INPUT                         ,
		   InputLine              = ENABLE_LINE_INPUT                              ,
		   InputEcho              = ENABLE_ECHO_INPUT                              ,
		   InputWindow            = ENABLE_WINDOW_INPUT                            ,
		   InputMouse             = ENABLE_MOUSE_INPUT                             ,
		   InputInsertMode        = ENABLE_INSERT_MODE                             ,
		   InputQuickEdit         = ENABLE_QUICK_EDIT_MODE | ENABLE_EXTENDED_FLAGS ,
		   InputQuickEditDisable  = ENABLE_EXTENDED_FLAGS                          ,
		   AutoPosition           = ENABLE_AUTO_POSITION                           ,
		/* Output modes------------------------------------------------------------*/
		   OutputProcessed        = ENABLE_PROCESSED_OUTPUT                        ,
		   OutputWrapAtEol        = ENABLE_WRAP_AT_EOL_OUTPUT                      ,
		   OutputVirtualTerminal  = ENABLE_VIRTUAL_TERMINAL_PROCESSING             ,
		   OutputLvbGridWorldwide = ENABLE_LVB_GRID_WORLDWIDE                     );

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
	inline DWORD Fill(char ch, DWORD len, LPoint pos = 0) ret_as(WX::FillConsoleOutputCharacter<false>(self, ch, len, pos, &len), len);
	inline DWORD Fill(wchar_t ch, DWORD len, LPoint pos = 0) ret_as(WX::FillConsoleOutputCharacter<true>(self, ch, len, pos, &len), len);

	inline Int32 FillAttributes(Int16U attr, DWORD len, LPoint pos = 0) ret_as(WX::FillConsoleOutputAttribute(self, attr, len, pos, &len), len);
	inline Int32 FillAttributes(ConsoleAttribute attr, DWORD len, LPoint pos = 0) ret_as(FillAttributes(attr, len, pos));

	inline Int32 Write(const  char   *pStr, DWORD len) ret_as(WX::WriteConsole<false>(self, pStr, len, &len, O), len);
	inline Int32 Write(const wchar_t *pStr, DWORD len) ret_as(WX::WriteConsole<true>(self, pStr, len, &len, O), len);

	inline Int32 Write(const StringA& str) ret_as(Write((LPCSTR )str, (DWORD)str.Length()));
	inline Int32 Write(const StringW& str) ret_as(Write((LPCWSTR)str, (DWORD)str.Length()));
	
	template<SizeT Len>
	inline Int32 Write(const  char  (&arr)[Len]) ret_as(Write(arr, (DWORD)(Len - 1)));
	template<SizeT Len>
	inline Int32 Write(const wchar_t(&arr)[Len]) ret_as(Write(arr, (DWORD)(Len - 1)));

	template<SizeT Len>
	inline Int32 Write(const LiString< char  , Len> &lis) ret_as(Write(lis, (DWORD)(Len - 1)));
	template<SizeT Len>
	inline Int32 Write(const LiString<wchar_t, Len> &lis) ret_as(Write(lis, (DWORD)(Len - 1)));

	inline Int32 Write( char   ch) ret_as(Write(&ch, 1));
	inline Int32 Write(wchar_t ch) ret_as(Write(&ch, 1));

	//inline DWORD Write(LPCSTR pStr, DWORD len, LPoint pos) ret_as(WX::WriteConsoleOutputCharacter(self, pStr, len, pos, &len), len);
	//inline DWORD Write(LPCWSTR pStr, DWORD len, LPoint pos) ret_as(WX::WriteConsoleOutputCharacter(self, pStr, len, pos, &len), len);
	//inline DWORD Write(const StringA& str, LPoint pos) ret_as(Write((LPCSTR)str, (DWORD)str.Length(), pos));
	//inline DWORD Write(const StringW& str, LPoint pos) ret_as(Write((LPCWSTR)str, (DWORD)str.Length(), pos));
	//template<SizeT Len>
	//inline DWORD Write(const char(&pStr)[Len], LPoint pos) ret_as(Write(pStr, (DWORD)(Len - 1), pos));
	//template<SizeT Len>
	//inline DWORD Write(const wchar_t(&pStr)[Len], LPoint pos) ret_as(Write(pStr, (DWORD)(Len - 1), pos));

	inline DWORD WriteAttributes(const WORD* pAttr, DWORD len, LPoint pos = 0) ret_as(WX::WriteConsoleOutputAttribute(self, pAttr, len, pos, &len), len);
	inline DWORD WriteAttributes(const ConsoleAttribute * pAttr, DWORD len, LPoint pos = 0) ret_as(WriteAttributes((const WORD*)pAttr, len, pos));
	template<SizeT Len>
	inline DWORD WriteAttributes(const WORD(&pAttr)[Len], LPoint pos = 0) ret_as(WriteAttributes(pAttr, (DWORD)Len, pos));
	template<SizeT Len>
	inline DWORD WriteAttributes(const ConsoleAttribute(&pAttr)[Len], LPoint pos = 0) ret_as(WriteAttributes((const WORD*)pAttr, (DWORD)Len, pos));

	inline DWORD Log(const char *str, DWORD max_len = MaxLenNotice) ret_as(Write(CString(str, max_len)));
	inline DWORD Log(const wchar_t *str, DWORD max_len = MaxLenNotice) ret_as(Write(CString(str, max_len)));

	//inline DWORD Read(LPSTR pBuf, DWORD len, LPoint pos = 0) ret_as(WX::ReadConsoleOutputCharacter(self, pBuf, len, pos, &len), len);
	//inline DWORD Read(LPWSTR pBuf, DWORD len, LPoint pos = 0) ret_as(WX::ReadConsoleOutputCharacter(self, pBuf, len, pos, &len), len);
	//inline DWORD Read(StringA& str, LPoint pos = 0) ret_as(Read(str, (DWORD)str.Length(), pos));
	//inline DWORD Read(StringW& str, LPoint pos = 0) ret_as(Read(str, (DWORD)str.Length(), pos));
	//template<SizeT Len>
	//inline DWORD Read(char(&pBuf)[Len], LPoint pos = 0) ret_as(Read(pBuf, (DWORD)(Len - 1), pos));
	//template<SizeT Len>
	//inline DWORD Read(wchar_t(&pBuf)[Len], LPoint pos = 0) ret_as(Read(pBuf, (DWORD)(Len - 1), pos));

	//inline String  Read (DWORD len, LPoint pos = 0) ret_to(String buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_cast(buf));
	//inline StringA ReadA(DWORD len, LPoint pos = 0) ret_to(StringA buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_cast(buf));
	//inline StringW ReadW(DWORD len, LPoint pos = 0) ret_to(StringW buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_cast(buf));

	//inline DWORD Read(WORD* pAttr, DWORD len, LPoint pos = 0) ret_as(WX::ReadConsoleOutputAttribute(self, pAttr, len, pos, &len), len);
	//inline DWORD Read(ConsoleAttribute * pAttr, DWORD len, LPoint pos = 0) ret_as(Read((WORD*)pAttr, len, pos));
	//template<SizeT Len>
	//inline DWORD Read(WORD(&pAttr)[Len], LPoint pos = 0) ret_as(Read(pAttr, (DWORD)Len, pos));
	//template<SizeT Len>
	//inline DWORD Read(ConsoleAttribute(&pAttr)[Len], LPoint pos = 0) ret_as(Read((WORD*)pAttr, (DWORD)Len, pos));

#pragma region Properties
// WindowSize SetConsoleWindowInfo

public: // FullScreen
//	/ * A */ inline autor FullScreenHardware() ret_to_self(WX::SetConsoleDisplayMode(self, CONSOLE_FULLSCREEN_HARDWARE, O));
	/* W */ inline autor FullScreen( bool bFullScreen) ret_to_self(WX::SetConsoleDisplayMode(self, bFullScreen ? CONSOLE_FULLSCREEN_MODE : CONSOLE_WINDOWED_MODE, O));
	/* R */ inline bool  FullScreen() const ret_to(DWORD mode = 0; WX::GetConsoleDisplayMode(&mode), mode == CONSOLE_FULLSCREEN_MODE);

	wx_vprop_get_def(ScreenBufferInfo, ConsoleScreenBufferInfo,
					 (WX::GetConsoleScreenBufferInfo(self, &value)));
	wx_vprop_map_def(Modes, ConsoleMode,
					 (WX::SetConsoleMode(self, (DWORD)value)),
					 (WX::GetConsoleMode(self, &value)));
	wx_vprop_map_def(CursorInfo, ConsoleCursorInfo,
					 (WX::SetConsoleCursorInfo(self, &value)),
					 (WX::GetConsoleCursorInfo(self, &value)));
	wx_vprop_get_def(ScreenBufferInfoEx, ConsoleScreenBufferInfoEx,
					 (WX::GetConsoleScreenBufferInfoEx(self, &value)));
	wx_vprop_map_dir(ScreenBufferSize, LSize,
					 (WX::SetConsoleScreenBufferSize(self, value)),
					 (ScreenBufferInfo().Size()));
	wx_vprop_map_dir(Attributes, ConsoleAttribute,
					 (WX::SetConsoleTextAttribute(self, (WORD)value)),
					 (ScreenBufferInfo().Attributes()));
	wx_vprop_map_dir(CursorPosition, LPoint,
					 (WX::SetConsoleCursorPosition(self, value)),
					 (ScreenBufferInfo().CursorPosition()));
	wx_vprop_map_dir(CursorVisible, bool,
					 (CursorInfo(CursorInfo().Visible(value))),
					 (CursorInfo().Visible()));
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
	//inline void Clear() ret_to(Fill(T(' '), ScreenBufferInfo().Size().Square()); CursorPosition(0));
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

	//template<class TCHAR>
	///* W */ inline autor Title( const TCHAR *lpTitle) ret_to_self(WX::SetConsoleTitle(lpTitle));
	//template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	///* R */ inline auto Title() const {
	//	StringX<IsUnicode> str(MaxLen);
	//	auto len = WX::GetConsoleTitle(str, (int)MaxLen);
	//	return right_cast(str.Resize(len));
	//}
	//template<SizeT MaxLen = MaxLenTitle>
	///* R */ inline auto  TitleA() const ret_as(Title<false, MaxLen>());
	//template<SizeT MaxLen = MaxLenTitle>
	///* R */ inline auto  TitleW() const ret_as(Title<true, MaxLen>());

	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitle () const {
		StringX<IsUnicode> str(MaxLen);
		auto len = WX::GetConsoleOriginalTitle(str, (int)MaxLen);
		return right_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleA() const ret_as(OriginalTitle<false, MaxLen>());
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleW() const ret_as(OriginalTitle<true, MaxLen>());

	wx_vprop_map_dir(InputCodePage, UINT,
					 (WX::SetConsoleCP(value)),
					 (WX::GetConsoleCP()));
	wx_vprop_map_dir(OutputCodePage, UINT,
					 (WX::SetConsoleOutputCP(value)),
					 (WX::GetConsoleOutputCP()));
	wx_vprop_get_def(SelectionInfo, ConsoleSelectionInfo,
					 (WX::GetConsoleSelectionInfo(&value)));
	wx_vprop_map_def(HistoryInfo, ConsoleHistoryInfo,
					 (WX::SetConsoleHistoryInfo(&value)),
					 (WX::GetConsoleHistoryInfo(&value)));
#pragma endregion   

public:
	inline auto &operator[](LPoint p) ret_as(CursorPosition(p));
	inline auto &operator[](bool bCurVis) ret_as(CursorVisible(bCurVis));
} Console;

#ifndef WX_IDL_IMPORT
}
#endif
