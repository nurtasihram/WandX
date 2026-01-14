#pragma once

#include "wx__rm.inl"

/* Macro exception system reflect for Windows  */
#define wx_throw_line_nt(sent) throw WX::Exception(__FILE__, __FUNCTION__, #sent, __LINE__, GetLastError())
#define nt_assert(sent) { using namespace WX; if (!(sent)) wx_throw_line_nt(sent); }

#define safe_ret_as(sent, ...) { if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#define safe_ret_as_self(sent)  safe_ret_as(sent, self)
#define safe_ret_as_child(sent) safe_ret_as(sent, child)

#define safe_ret_to(defs, sent, ...) { defs; if (sent) return __VA_ARGS__; wx_throw_line_nt(sent); }
#define safe_ret_to_self(defs, sent)  safe_ret_to(defs, sent, self)
#define safe_ret_to_child(defs, sent) safe_ret_to(defs, sent, child)

#define ret_safe_to(sent, ...) { SetLastError(ERROR_SUCCESS); sent; if (GetLastError()) wx_throw_line_nt(sent); return __VA_ARGS__; }
#define ret_safe_to_self(sent)  ret_safe_to(sent, self)
#define ret_safe_to_child(sent) ret_safe_to(sent, child)
