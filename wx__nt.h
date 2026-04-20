#pragma once

#include <Windows.h>

#include "wx__rm.inl"

#pragma region Compilation Informations
//----------- _WX_COMPILED_TIME ----------------------------------------------------------//
#      define _WX_COMPILED_TIME               __DATE__ " " __TIME__                       //
//----------- _WX_CPP_STANDARD -----------------------------------------------------------//
#      define _WX_CPP_STANDARD                mx_str(__cplusplus)                         //
//----------- _WX_CHAR_MODE --------------------------------------------------------------//
#if   defined                                 UNICODE                                     //
#      define _WX_CHAR_MODE                   "Unicode"                                   //
#else                                                                                     //
#      define _WX_CHAR_MODE                   "MultiByte"                                 //
#endif                                                                                    //
//----------- _WX_BUILD_MODE -------------------------------------------------------------//
#if   defined                                 _DEBUG                                      //
#      define _WX_BUILD_MODE                  "Debug"                                     //
#else                                                                                     //
#      define _WX_BUILD_MODE                  "Release"                                   //
#endif                                                                                    //
//----------- _WX_PLATFORM_BITS ----------------------------------------------------------//
#if   defined                                 _WIN64                                      //
#      define _WX_PLATFORM_BITS               "64-bits"                                   //
#elif defined                                 _WIN32                                      //
#      define _WX_PLATFORM_BITS               "32-bits"                                   //
#else                                                                                     //
#      define _WX_PLATFORM_BITS               "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_ARCHITECTURE -----------------------------------------------------------//
#if   defined                                 _M_X64                                      //
#      define _WX_ARCHITECTURE                "x64"                                       //
#elif defined                                 _M_IX86                                     //
#      define _WX_ARCHITECTURE                "x86"                                       //
#elif defined                                 _M_AMD64                                    //
#      define _WX_ARCHITECTURE                "AMD64"                                     //
#elif defined                                 _M_ARM64                                    //
#      define _WX_ARCHITECTURE                "ARM64"                                     //
#elif defined                                 _M_ARM                                      //
#      define _WX_ARCHITECTURE                "ARM"                                       //
#elif defined                                 _M_ARM64EC                                  //
#      define _WX_ARCHITECTURE                "ARM64EC"                                   //
#else                                                                                     //
#      define _WX_ARCHITECTURE                "Unknown"                                   //
#endif                                                                                    //
//----------- _WX_COMPILER ---------------------------------------------------------------//
#if   defined                                 __clang__                                   //
#      define _WX_COMPILER                    "Clang "       mx_str(__clang_version__)    //
#elif defined                                 __GNUC__                                    //
#      define _WX_COMPILER                    "GCC "         mx_str(__VERSION__)          //
#elif defined                                 _MSC_VER                                    //
#      define _WX_COMPILER                    "MSVC "        mx_str(_MSC_FULL_VER)        //
#else                                                                                     //
#      define _WX_COMPILER                    "Unknown"                                   //
#endif                                                                                    //
//----------- _NTDDI_ --------------------------------------------------------------------//
#if            NTDDI_VERSION >=               NTDDI_WIN11_GE                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Germanium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_GA                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Gallium'"                      //
#elif          NTDDI_VERSION >=               NTDDI_WIN11_ZN                              //
#      define _WX_NTDDI_NAME                  "Windows 11 'Zinc'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CU                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Copper'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_NI                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Nickel'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_CO                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Cobalt'"                       //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_FE                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Iron'"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_MN                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Manganese'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_VB                              //
#      define _WX_NTDDI_NAME                  "Windows 10 'Vibranium'"                    //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_19H1                            //
#      define _WX_NTDDI_NAME                  "Windows 10 1903 '19H1''"                   //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS5                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1809 'Redstone 5'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS4                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1803 'Redstone 4'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS3                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1709 'Redstone 3'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1703 'Redstone 2'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_RS1                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1607 'Redstone 1'"              //
#elif          NTDDI_VERSION >=               NTDDI_WIN10_TH2                             //
#      define _WX_NTDDI_NAME                  "Windows 10 1511 'Threshold 2'"             //
#elif          NTDDI_VERSION >=               NTDDI_WIN10                                 //
#      define _WX_NTDDI_NAME                  "Windows 10 1507 'Threshold'"               //
#elif          NTDDI_VERSION >=               NTDDI_WINBLUE                               //
#      define _WX_NTDDI_NAME                  "Windows 8.1"                               //
#elif          NTDDI_VERSION >=               NTDDI_WIN8                                  //
#      define _WX_NTDDI_NAME                  "Windows 8"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN7                                  //
#      define _WX_NTDDI_NAME                  "Windows 7"                                 //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP4"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP3"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP2"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Vista SP1"                         //
#elif          NTDDI_VERSION >=               NTDDI_WIN6                                  //
#      define _WX_NTDDI_NAME                  "Windows Vista"                             //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP4                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP4"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP3                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP3"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP2                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP2"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03SP1                               //
#      define _WX_NTDDI_NAME                  "Windows Server 2003 SP1"                   //
#elif          NTDDI_VERSION >=               NTDDI_WS03                                  //
#      define _WX_NTDDI_NAME                  "Windows Server 2003"                       //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP4                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP4"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP3                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP3"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP2                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP2"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXPSP1                              //
#      define _WX_NTDDI_NAME                  "Windows XP SP1"                            //
#elif          NTDDI_VERSION >=               NTDDI_WINXP                                 //
#      define _WX_NTDDI_NAME                  "Windows XP"                                //
#else                                                                                     //
#      define _WX_NTDDI_NAME                  "Windows Unknown"                           //
#endif                                                                                    //
#      define _NTDDI_INFO                     _WX_NTDDI_NAME " - " mx_str(NTDDI_VERSION)  //
//-------------------------------- _WX_COMPILATION_INFO ----------------------------------//
#             define                          _WX_COMPILATION_INFO                         \
              "Compiled Date: "               _WX_COMPILED_TIME                       "\n" \
              "C++ Standard:  "               _WX_CPP_STANDARD                        "\n" \
              "Char Mode:     "               _WX_CHAR_MODE                           "\n" \
              "Build Mode:    "               _WX_BUILD_MODE                          "\n" \
              "Platform Bits: "               _WX_PLATFORM_BITS                       "\n" \
              "Architecture:  "               _WX_ARCHITECTURE                        "\n" \
              "Compiler:      "               _WX_COMPILER                            "\n" \
              "NTDDI Version: "               _WX_NTDDI_NAME                              //
#pragma endregion //////////////////////////////////////////////////////////////////////////

/* Macro Windows API reflectors */

#define wapi_reflect_pure(name)               constexpr ReflectOfPure<ThisFile, LiString(#name), ::name> name

#define wapi_reflect_bool1(name)              constexpr ReflectOfReturnBool<ThisFile, LiString(#name), ::name> name
#define wapi_reflect_bool2(name, new_ret)     constexpr ReflectOfReturnBool<ThisFile, LiString(#name), ::name, new_ret> name
#define wapi_reflect_bool(...)                mx_funcN(wapi_reflect_bool, __VA_ARGS__)

#define wapi_reflect_handle(name)             constexpr ReflectOfReturnHandle<ThisFile, LiString(#name), ::name> name

/* Macro Windows API reflectors W/A Overload In One */

#define wapi_reflect_pure_WAO(name)           constexpr ReflectorOfPureWA<ThisFile, LiString(#name), ::name##W, ::name##A> name

#define wapi_reflect_bool_WAO1(name)          constexpr ReflectorOfBoolReturnWA<ThisFile, LiString(#name), ::name##W, ::name##A> name
#define wapi_reflect_bool_WAO2(name, new_ret) constexpr ReflectorOfBoolReturnWA<ThisFile, LiString(#name), ::name##W, ::name##A, new_ret> name
#define wapi_reflect_bool_WAO(...)            mx_funcN(wapi_reflect_bool_WAO, __VA_ARGS__)

/* Macro Windows API reflectors A Version */

#define wapi_reflect_pure_A(name)             wapi_reflect_pure(name##A)

#define wapi_reflect_bool_A1(name)            wapi_reflect_bool1(name##A)
#define wapi_reflect_bool_A2(name, new_ret)   wapi_reflect_bool2(name##A, new_ret)
#define wapi_reflect_bool_A(...)              mx_funcN(wapi_reflect_bool_A, __VA_ARGS__)

/* Macro Windows API reflectors W Version */

#define wapi_reflect_pure_W(name)             wapi_reflect_pure(name##W)

#define wapi_reflect_bool_W1(name)            wapi_reflect_bool1(name##W)
#define wapi_reflect_bool_W2(name, new_ret)   wapi_reflect_bool2(name##W, new_ret)
#define wapi_reflect_bool_W(...)              mx_funcN(wapi_reflect_bool_W, __VA_ARGS__)

/* Macro Windows API reflectors W&A Versions */

#define wapi_reflect_pure_WA(name)            wapi_reflect_pure_W(name); \
											  wapi_reflect_pure_A(name)

#define wapi_reflect_bool_WA1(name)           wapi_reflect_bool1(name##W); \
											  wapi_reflect_bool1(name##A)
#define wapi_reflect_bool_WA2(name, new_ret)  wapi_reflect_bool2(name##W, new_ret); \
											  wapi_reflect_bool2(name##A, new_ret)
#define wapi_reflect_bool_WA(...)             mx_funcN(wapi_reflect_bool_WA, __VA_ARGS__)

/* Macro Windows API reflectors W&A Versions With Template Selector */

#define WAT_selector(name)					  template<bool IsUnicode = WX::IsUnicode> \
											  constexpr auto name = ValueIf<IsUnicode, name##W, name##A>;

#define wapi_reflect_pure_WAT(name)           wapi_reflect_pure_WA(name); \
											  WAT_selector(name)

#define wapi_reflect_bool_WAT1(name)          wapi_reflect_bool_WA1(name); \
											  WAT_selector(name)
#define wapi_reflect_bool_WAT2(name, new_ret) wapi_reflect_bool_WA2(name, new_ret); \
											  WAT_selector(name)
#define wapi_reflect_bool_WAT(...)            mx_funcN(wapi_reflect_bool_WAT, __VA_ARGS__)

/* Macro exception system reflect for Windows */

#define wx_throw_line_nt(sent) throw WX::Exception(__FILE__, __FUNCTION__, #sent, __LINE__, GetLastError())
#define nt_assert(sent) { using namespace WX; if (!(sent)) wx_throw_line_nt(sent); }

///////////////////////////////////////////// !!!!DEPRECATE SOON!!!! /////////////////////////////////////////////

#define safe_ret_as(sent, ...) { if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#define safe_ret_as_self(sent)  safe_ret_as(sent, self)
#define safe_ret_as_child(sent) safe_ret_as(sent, child)

#define safe_ret_to(defs, sent, ...) { defs; if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#define safe_ret_to_self(defs, sent)  safe_ret_to(defs, sent, self)
#define safe_ret_to_child(defs, sent) safe_ret_to(defs, sent, child)

#define ret_safe_to(sent, ...) { SetLastError(ERROR_SUCCESS); sent; if (GetLastError()) wx_throw_line_nt(sent); return __VA_ARGS__; }
#define ret_safe_to_self(sent)  ret_safe_to(sent, self)
#define ret_safe_to_child(sent) ret_safe_to(sent, child)
