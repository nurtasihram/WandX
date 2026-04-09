module;

#define WX_CPPM_CONSOLE
#include "wx_console"

export module wx.console;

import wx.win32;

#ifndef WX_REMOVE_WIN32_PROTOTYPES
namespace WX::Win32 {

constexpr auto ThisFile = LiString("wx.console");

#pragma region ProcessEnv.h (part)
wapi_reflect_valid(GetStdHandle);
wapi_reflect_true(SetStdHandle);
wapi_reflect_true(SetStdHandleEx);
#pragma endregion

#pragma region ConsoleApi.h
wapi_reflect_true(AllocConsole);
// AllocConsoleWithOptions 
wapi_reflect_true(FreeConsole);
wapi_reflect_true(AttachConsole);
wapi_reflect_true(GetConsoleCP, UINT);
wapi_reflect_true(GetConsoleOutputCP, UINT);
wapi_reflect_true(GetConsoleMode);
wapi_reflect_true(SetConsoleMode);
wapi_reflect_true(GetNumberOfConsoleInputEvents);
#undef ReadConsoleInput
wapi_reflect_true_WAT(ReadConsoleInput);
#undef PeekConsoleInput
wapi_reflect_true_WAT(PeekConsoleInput);
#undef ReadConsole
wapi_reflect_true_WAT(ReadConsole);
#undef WriteConsole
// WriteConsole
inline void WriteConsole(HANDLE hConsoleOutput, LPCSTR lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
	safe_ret_as(::WriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved));
inline void WriteConsole(HANDLE hConsoleOutput, LPCWSTR lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
	safe_ret_as(::WriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved));
wapi_reflect_true(SetConsoleCtrlHandler);
#pragma endregion

#pragma region ConsoleApi2.h
static_assert(NotSame<ProtoOf<decltype(FillConsoleOutputCharacterA)>,
                      ProtoOf<decltype(FillConsoleOutputCharacterW)>>);
#undef FillConsoleOutputCharacter
wapi_reflect_true_WAO(FillConsoleOutputCharacter);
wapi_reflect_true(FillConsoleOutputAttribute);
wapi_reflect_true(GenerateConsoleCtrlEvent);
// CreateConsoleScreenBuffer
inline HANDLE CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwFlags, HANDLE *lpBuffer)
	safe_ret_as(auto h = ::CreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlags, lpBuffer); h != INVALID_HANDLE_VALUE, h);
wapi_reflect_true(SetConsoleActiveScreenBuffer);
wapi_reflect_true(FlushConsoleInputBuffer);
wapi_reflect_true(SetConsoleCP);
wapi_reflect_true(SetConsoleOutputCP);
wapi_reflect_true(GetConsoleCursorInfo);
wapi_reflect_true(SetConsoleCursorInfo);
wapi_reflect_true(GetConsoleScreenBufferInfo);
wapi_reflect_true(GetConsoleScreenBufferInfoEx);
wapi_reflect_true(SetConsoleScreenBufferInfoEx);
wapi_reflect_true(SetConsoleScreenBufferSize);
wapi_reflect_true(SetConsoleCursorPosition);
// GetLargestConsoleWindowSize
inline COORD GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
	safe_ret_as(auto c = ::GetLargestConsoleWindowSize(hConsoleOutput); c.X && c.Y, c);
wapi_reflect_true(SetConsoleTextAttribute);
wapi_reflect_true(SetConsoleWindowInfo);
#undef WriteConsoleOutputCharacter
wapi_reflect_true_WAO(WriteConsoleOutputCharacter);
wapi_reflect_true(WriteConsoleOutputAttribute);
#undef ReadConsoleOutputCharacter
wapi_reflect_true_WAO(ReadConsoleOutputCharacter);
wapi_reflect_true(ReadConsoleOutputAttribute);
#undef WriteConsoleInput
wapi_reflect_true_WAT(WriteConsoleInput);
#undef ScrollConsoleScreenBuffer
wapi_reflect_true_WAT(ScrollConsoleScreenBuffer);
#undef WriteConsoleOutput
wapi_reflect_true_WAT(WriteConsoleOutput);
#undef ReadConsoleOutput
wapi_reflect_true_WAT(ReadConsoleOutput);
#undef GetConsoleTitle
wapi_reflect_true_WAO(GetConsoleTitle, int);
#undef GetConsoleOriginalTitle
wapi_reflect_true_WAO(GetConsoleOriginalTitle, int);
#undef SetConsoleTitle
wapi_reflect_true_WAO(SetConsoleTitle);
#pragma endregion

#pragma region ConsoleApi3.h
wapi_reflect_true(GetNumberOfConsoleMouseButtons, UINT);
// GetConsoleFontSize
inline COORD GetConsoleFontSize(HANDLE hConsoleOutput, DWORD nFont)
	safe_ret_as(auto c = ::GetConsoleFontSize(hConsoleOutput, nFont); c.X && c.Y, c);
wapi_reflect_true(GetCurrentConsoleFont);
wapi_reflect_true(GetCurrentConsoleFontEx);
wapi_reflect_true(SetCurrentConsoleFontEx);
wapi_reflect_true(GetConsoleSelectionInfo);
wapi_reflect_true(GetConsoleHistoryInfo);
wapi_reflect_true(SetConsoleHistoryInfo);
wapi_reflect_true(GetConsoleDisplayMode);
wapi_reflect_true(SetConsoleDisplayMode);
//wapi_reflect_proto(GetConsoleWindow);
#undef AddConsoleAlias
wapi_reflect_true_WAO(AddConsoleAlias);
#undef GetConsoleAlias
wapi_reflect_true_WAO(GetConsoleAlias);
#undef GetConsoleAliasesLength
wapi_reflect_true_WAO(GetConsoleAliasesLength);
#undef GetConsoleAliasExesLength
wapi_reflect_WAT(GetConsoleAliasExesLength);
#undef GetConsoleAliases
wapi_reflect_true_WAO(GetConsoleAliases);
#undef GetConsoleAliasExes
wapi_reflect_true_WAO(GetConsoleAliasExes);
wapi_reflect_true(GetConsoleProcessList, DWORD);
#pragma endregion

}
#endif
export namespace WX {

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
static_assert(IsPureEnum<ConsoleSelectionFlag>);
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
public: // Property      ColorTable
	/* W */ inline auto &ColorTable (const COLORREF *lpColorTable) {
		for (int i = 0; i < 16; ++i)
			self->ColorTable[i] = lpColorTable[i];
		return *this;
	}
	/* R */ inline const COLORREF *ColorTable () const { return self->ColorTable; }
};
enum_flags(ConsoleMode            , DWORD                                          ,
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

#define autor auto&
class ConsoleHandleOutput : public HandleBase<ConsoleHandleOutput> {
public:
	using Super = HandleBase<ConsoleHandleOutput>;
protected:
	friend_to_proxy(ConsoleHandleOutput);
	ConsoleHandleOutput(HANDLE h) : Super(h) {}
public:
	ConsoleHandleOutput() : Super(Win32::GetStdHandle(STD_OUTPUT_HANDLE)) {}
	ConsoleHandleOutput(Nu) {}
public:
	inline void ActiveScreenBuffer() ret_to(Win32::SetConsoleActiveScreenBuffer(self));
public:
	inline DWORD Fill(CHAR ch, DWORD len, LPoint pos = 0) ret_as(Win32::FillConsoleOutputCharacter(self, ch, len, pos, &len), len);
	inline DWORD Fill(WCHAR ch, DWORD len, LPoint pos = 0) ret_as(Win32::FillConsoleOutputCharacter(self, ch, len, pos, &len), len);

	inline DWORD FillAttributes(WORD attr, DWORD len, LPoint pos = 0) ret_as(Win32::FillConsoleOutputAttribute(self, attr, len, pos, &len), len);
	inline DWORD FillAttributes(ConsoleAttribute attr, DWORD len, LPoint pos = 0) ret_as(FillAttributes(attr, len, pos));

	inline DWORD Write(LPCSTR pStr, DWORD len) ret_as(Win32::WriteConsole(self, pStr, len, &len, O), len);
	inline DWORD Write(LPCWSTR pStr, DWORD len) ret_as(Win32::WriteConsole(self, pStr, len, &len, O), len);
	inline DWORD Write(const StringA& str) ret_as(Write((LPCSTR)str, (DWORD)str.Length()));
	inline DWORD Write(const StringW& str) ret_as(Write((LPCWSTR)str, (DWORD)str.Length()));
	template<SizeT Len>
	inline DWORD Write(const CHAR(&pStr)[Len]) ret_as(Write(pStr, (DWORD)(Len - 1)));
	template<SizeT Len>
	inline DWORD Write(const WCHAR(&pStr)[Len]) ret_as(Write(pStr, (DWORD)(Len - 1)));
	inline DWORD Write(WCHAR ch) ret_as(Write(&ch, 1));
	inline DWORD Write(CHAR ch) ret_as(Write(&ch, 1));

	inline DWORD Write(LPCSTR pStr, DWORD len, LPoint pos) ret_as(Win32::WriteConsoleOutputCharacter(self, pStr, len, pos, &len), len);
	inline DWORD Write(LPCWSTR pStr, DWORD len, LPoint pos) ret_as(Win32::WriteConsoleOutputCharacter(self, pStr, len, pos, &len), len);
	inline DWORD Write(const StringA& str, LPoint pos) ret_as(Write((LPCSTR)str, (DWORD)str.Length(), pos));
	inline DWORD Write(const StringW& str, LPoint pos) ret_as(Write((LPCWSTR)str, (DWORD)str.Length(), pos));
	template<SizeT Len>
	inline DWORD Write(const CHAR(&pStr)[Len], LPoint pos) ret_as(Write(pStr, (DWORD)(Len - 1), pos));
	template<SizeT Len>
	inline DWORD Write(const WCHAR(&pStr)[Len], LPoint pos) ret_as(Write(pStr, (DWORD)(Len - 1), pos));

	inline DWORD WriteAttributes(const WORD* pAttr, DWORD len, LPoint pos = 0) ret_as(Win32::WriteConsoleOutputAttribute(self, pAttr, len, pos, &len), len);
	inline DWORD WriteAttributes(const ConsoleAttribute* pAttr, DWORD len, LPoint pos = 0) ret_as(WriteAttributes((const WORD*)pAttr, len, pos));
	template<SizeT Len>
	inline DWORD WriteAttributes(const WORD(&pAttr)[Len], LPoint pos = 0) ret_as(WriteAttributes(pAttr, (DWORD)Len, pos));
	template<SizeT Len>
	inline DWORD WriteAttributes(const ConsoleAttribute(&pAttr)[Len], LPoint pos = 0) ret_as(WriteAttributes((const WORD*)pAttr, (DWORD)Len, pos));

	inline DWORD Read(LPSTR pBuf, DWORD len, LPoint pos = 0) ret_as(Win32::ReadConsoleOutputCharacter(self, pBuf, len, pos, &len), len);
	inline DWORD Read(LPWSTR pBuf, DWORD len, LPoint pos = 0) ret_as(Win32::ReadConsoleOutputCharacter(self, pBuf, len, pos, &len), len);
	inline DWORD Read(StringA& str, LPoint pos = 0) ret_as(Read(str, (DWORD)str.Length(), pos));
	inline DWORD Read(StringW& str, LPoint pos = 0) ret_as(Read(str, (DWORD)str.Length(), pos));
	template<SizeT Len>
	inline DWORD Read(CHAR(&pBuf)[Len], LPoint pos = 0) ret_as(Read(pBuf, (DWORD)(Len - 1), pos));
	template<SizeT Len>
	inline DWORD Read(WCHAR(&pBuf)[Len], LPoint pos = 0) ret_as(Read(pBuf, (DWORD)(Len - 1), pos));

	inline String Read(DWORD len, LPoint pos = 0) ret_to(String buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_hand_cast(buf));
	inline StringA ReadA(DWORD len, LPoint pos = 0) ret_to(StringA buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_hand_cast(buf));
	inline StringW ReadW(DWORD len, LPoint pos = 0) ret_to(StringW buf{ (SizeT)len }; buf.Resize(Read(buf, pos)), right_hand_cast(buf));

	inline DWORD Read(WORD* pAttr, DWORD len, LPoint pos = 0) ret_as(Win32::ReadConsoleOutputAttribute(self, pAttr, len, pos, &len), len);
	inline DWORD Read(ConsoleAttribute* pAttr, DWORD len, LPoint pos = 0) ret_as(Read((WORD*)pAttr, len, pos));
	template<SizeT Len>
	inline DWORD Read(WORD(&pAttr)[Len], LPoint pos = 0) ret_as(Read(pAttr, (DWORD)Len, pos));
	template<SizeT Len>
	inline DWORD Read(ConsoleAttribute(&pAttr)[Len], LPoint pos = 0) ret_as(Read((WORD*)pAttr, (DWORD)Len, pos));

#pragma region Properties
public: // Property WindowSize
//	/ * W */ inline autor WindowSize (LRect rect) ret_to_self(SetConsoleWindowInfo(self, TRUE, ));
//	/ * R */ inline auto WindowSize () const ret_as(ScreenBufferInfo().WindowRect().size());
public: // Property FullScreen
//	/ * A */ inline autor FullScreenHardware () ret_to_self(Win32::SetConsoleDisplayMode(self, CONSOLE_FULLSCREEN_HARDWARE, O));
	/* W */ inline autor FullScreen ( bool bFullScreen) ret_to_self(Win32::SetConsoleDisplayMode(self, bFullScreen ? CONSOLE_FULLSCREEN_MODE : CONSOLE_WINDOWED_MODE, O));
	/* R */ inline bool FullScreen () const ret_to(DWORD mode = 0; Win32::GetConsoleDisplayMode(&mode), mode == CONSOLE_FULLSCREEN_MODE);
public: // Property Mode
	/* W */ inline autor Modes ( ConsoleMode modes) ret_to_self(Win32::SetConsoleMode(self, (DWORD)modes));
	/* R */ inline auto Modes () const ret_to(DWORD modes, Win32::GetConsoleMode(self, &modes), reuse_cast<ConsoleMode>(modes));
public: // Property CursorInfo
	/* W */ inline autor CursorInfo ( ConsoleCursorInfo cci) ret_to_self(Win32::SetConsoleCursorInfo(self, &cci));
	/* R */ inline auto CursorInfo () const ret_to(ConsoleCursorInfo cci, Win32::GetConsoleCursorInfo(self, &cci), cci);
public: // Property ScreenBufferInfo
// / * W */ inline autor ScreenBufferInfo ( ConsoleScreenBufferInfoEx sbiex) ret_to_self(Win32::SetConsoleScreenBufferInfo(self, &sbiex));
	/* R */ inline auto ScreenBufferInfo () const ret_to(ConsoleScreenBufferInfo sbi, Win32::GetConsoleScreenBufferInfo(self, &sbi), sbi);
public: // Property ScreenBufferInfoEx
	/* R */ inline auto ScreenBufferInfoEx () const ret_to(ConsoleScreenBufferInfoEx sbiex, Win32::GetConsoleScreenBufferInfoEx(self, &sbiex), sbiex);
	
#define wx_vprop_set(name, type, setter) inline auto&name(type) ret_to_self(setter)
#define wx_vprop_get(name, getter) inline auto name(    ) const ret_as     (getter)
#define wx_vprop_map(name, type, setter, getter) \
		wx_vprop_set(name, type, setter); \
		wx_vprop_get(name, getter)

	wx_vprop_map(ScreenBufferSize, LSize                   size, Win32::SetConsoleScreenBufferSize(self, size)          , ScreenBufferInfo().Size()          );
	wx_vprop_map(Attributes      , ConsoleAttribute wAttributes, Win32::SetConsoleTextAttribute(self, (WORD)wAttributes), ScreenBufferInfo().Attributes()    );
	wx_vprop_map(CursorPosition  , LPoint                     p, Win32::SetConsoleCursorPosition(self, p)               , ScreenBufferInfo().CursorPosition());
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
	ConsoleHandleInput() : Super(Win32::GetStdHandle(STD_INPUT_HANDLE)) {}
	ConsoleHandleInput(Nu) {}
public:
	inline void FlushInputBuffer() ret_to(Win32::FlushConsoleInputBuffer(self));
};
class IConsole : public ConsoleHandleOutput {
protected:
	HANDLE hError = O;
public:
public:
	IConsole(Nu) {}
	IConsole() : hError(Win32::GetStdHandle(STD_ERROR_HANDLE)) {}
	IConsole(DWORD pid) ret_to(Attach(pid));
public:
	inline void Attach(DWORD pid) ret_to(Win32::AttachConsole(pid));
	inline void Alloc() ret_to(Win32::AllocConsole());
	inline void Free() ret_to(Win32::FreeConsole());

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
//public: // Property Window
//	inline CWindow Window() const ret_as(Win32::GetConsoleWindow());
#pragma region Properties
public: // Property Title
	template<class TCHAR>
	/* W */ inline autor Title ( const TCHAR *lpTitle) ret_to_self(Win32::SetConsoleTitle(lpTitle));
	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto Title() const {
		StringX<IsUnicode> str(MaxLen);
		auto len = Win32::GetConsoleTitle(str, (int)MaxLen);
		return right_hand_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto TitleA () const ret_as(Title<false, MaxLen>());
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto TitleW () const ret_as(Title<true, MaxLen>());
public: // Property OriginalTitle

	template<bool IsUnicode = WX::IsUnicode, SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitle () const {
		StringX<IsUnicode> str(MaxLen);
		auto len = Win32::GetConsoleOriginalTitle(str, (int)MaxLen);
		return right_hand_cast(str.Resize(len));
	}
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleA () const ret_as(OriginalTitle<false, MaxLen>());
	template<SizeT MaxLen = MaxLenTitle>
	/* R */ inline auto OriginalTitleW () const ret_as(OriginalTitle<true, MaxLen>());

public: // Property CodePage
	/* W */ inline autor CodePage ( UINT uCodePage) ret_to_self(Win32::SetConsoleCP(uCodePage));
	/* R */ inline UINT CodePage () const ret_as(Win32::GetConsoleCP());
public: // Property OutputCodePage
	/* W */ inline autor OutputCodePage ( UINT uCodePage) ret_to_self(Win32::SetConsoleOutputCP(uCodePage));
	/* R */ inline UINT OutputCodePage () const ret_as(Win32::GetConsoleOutputCP());
public: // Property SelectionInfo
	/* R */ inline auto SelectionInfo () const ret_to(ConsoleSelectionInfo csi, Win32::GetConsoleSelectionInfo(&csi), csi);
public: // Property HistoryInfo
	/* W */ inline autor HistoryInfo ( CONSOLE_HISTORY_INFO chi) ret_to_self(Win32::SetConsoleHistoryInfo(&chi));
	/* R */ inline auto HistoryInfo () const ret_to(ConsoleHistoryInfo chi, Win32::GetConsoleHistoryInfo(&chi), chi);
#pragma endregion 

public:
	inline auto &operator[](LPoint p) ret_as(CursorPosition(p));
	inline auto &operator[](bool bCurVis) ret_as(CursorVisible(bCurVis));
} Console;

}
