module;

#define WX_CPPM_GDI
#include "wx_gdi"

export module wx.gdi;

import wx.proto;

#pragma region Win32 Prototype Includes
namespace WX {

#pragma region WinGDI.h
// AddFontResource
#undef AddFontResource
inline int AddFontResource(LPCSTR lpFileName)
	safe_ret_as(auto ret = ::AddFontResourceA(lpFileName); ret > 0, ret);
inline int AddFontResource(LPCWSTR lpFileName)
	safe_ret_as(auto ret = ::AddFontResourceW(lpFileName); ret > 0, ret);
// AnimatePalette
inline void AnimatePalette(HPALETTE hPal, UINT iStartIndex, UINT cEntries, CONST PALETTEENTRY *ppe)
	safe_ret_as(::AnimatePalette(hPal, iStartIndex, cEntries, ppe));
// Arc
inline void Arc(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	safe_ret_as(::Arc(hdc, x1, y1, x2, y2, x3, y3, x4, y4));
// BitBlt
inline void BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop)
	safe_ret_as(::BitBlt(hdc, x, y, cx, cy, hdcSrc, x1, y1, rop));
// CancelDC
inline void CancelDC(HDC hdc)
	safe_ret_as(::CancelDC(hdc));
// Chord
inline void Chord(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	safe_ret_as(::Chord(hdc, x1, y1, x2, y2, x3, y3, x4, y4));
// ChoosePixelFormat
inline int ChoosePixelFormat(HDC hdc, CONST PIXELFORMATDESCRIPTOR *ppfd)
	safe_ret_as(auto ret = ::ChoosePixelFormat(hdc, ppfd); ret > 0, ret);
// CloseMetaFile
inline HMETAFILE CloseMetaFile(HDC hdc)
	safe_ret_as(auto ret = ::CloseMetaFile(hdc), ret);
// CombineRgn
inline int CombineRgn(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
	safe_ret_as(auto ret = ::CombineRgn(hrgnDst, hrgnSrc1, hrgnSrc2, iMode); ret != ERROR, ret);
// CopyMetaFile
#undef CopyMetaFile
inline HMETAFILE CopyMetaFile(HMETAFILE hMetaFile, LPCSTR lpFileName)
	safe_ret_as(auto ret = ::CopyMetaFileA(hMetaFile, lpFileName), ret);
inline HMETAFILE CopyMetaFile(HMETAFILE hMetaFile, LPCWSTR lpFileName)
	safe_ret_as(auto ret = ::CopyMetaFileW(hMetaFile, lpFileName), ret);
// CreateBitmap
inline HBITMAP CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitCount, CONST VOID *lpBits)
	safe_ret_as(auto ret = ::CreateBitmap(nWidth, nHeight, nPlanes, nBitCount, lpBits), ret);
// CreateBitmapIndirect
inline HBITMAP CreateBitmapIndirect(CONST BITMAP *pbm)
	safe_ret_as(auto ret = ::CreateBitmapIndirect(pbm), ret);
// CreateBrushIndirect
inline HBRUSH CreateBrushIndirect(CONST LOGBRUSH *plbrush)
	safe_ret_as(auto ret = ::CreateBrushIndirect(plbrush), ret);
// CreateCompatibleBitmap
inline HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy)
	safe_ret_as(auto ret = ::CreateCompatibleBitmap(hdc, cx, cy), ret);
// CreateDiscardableBitmap
inline HBITMAP CreateDiscardableBitmap(HDC hdc, int cx, int cy)
	safe_ret_as(auto ret = ::CreateDiscardableBitmap(hdc, cx, cy), ret);
// CreateCompatibleDC
inline HDC CreateCompatibleDC(HDC hdc)
	safe_ret_as(auto ret = ::CreateCompatibleDC(hdc), ret);
// CreateDC
#undef CreateDC
inline HDC CreateDC(LPCSTR pwszDriver, LPCSTR pwszDevice, LPCSTR pszPort, CONST DEVMODEA *pdm)
	safe_ret_as(auto ret = ::CreateDCA(pwszDriver, pwszDevice, pszPort, pdm), ret);
inline HDC CreateDC(LPCWSTR pwszDriver, LPCWSTR pwszDevice, LPCWSTR pszPort, CONST DEVMODEW *pdm)
	safe_ret_as(auto ret = ::CreateDCW(pwszDriver, pwszDevice, pszPort, pdm), ret);
// CreateDIBitmap
inline HBITMAP CreateDIBitmap(HDC hdc, CONST BITMAPINFOHEADER *pbmih, DWORD flInit, CONST VOID *pjBits, CONST BITMAPINFO *pbmi, UINT iUsage)
	safe_ret_as(auto ret = ::CreateDIBitmap(hdc, pbmih, flInit, pjBits, pbmi, iUsage), ret);
// CreateDIBPatternBrush
inline HBRUSH CreateDIBPatternBrush(HGLOBAL h, UINT iUsage)
	safe_ret_as(auto ret = ::CreateDIBPatternBrush(h, iUsage), ret);
// CreateDIBPatternBrushPt
inline HBRUSH CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB, UINT iUsage)
	safe_ret_as(auto ret = ::CreateDIBPatternBrushPt(lpPackedDIB, iUsage), ret);
// CreateEllipticRgn
inline HRGN CreateEllipticRgn(int x1, int y1, int x2, int y2)
	safe_ret_as(auto ret = ::CreateEllipticRgn(x1, y1, x2, y2), ret);
// CreateEllipticRgnIndirect
inline HRGN CreateEllipticRgnIndirect(CONST RECT *lprect)
	safe_ret_as(auto ret = ::CreateEllipticRgnIndirect(lprect), ret);
// CreateFontIndirect
#undef CreateFontIndirect
inline HFONT CreateFontIndirect(CONST LOGFONTA *lplf)
	safe_ret_as(auto ret = ::CreateFontIndirectA(lplf), ret);
inline HFONT CreateFontIndirect(CONST LOGFONTW *lplf)
	safe_ret_as(auto ret = ::CreateFontIndirectW(lplf), ret);
// CreateFont
#undef CreateFont
inline HFONT CreateFont(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName)
	safe_ret_as(auto ret = ::CreateFontA(cHeight, cWidth, cEscapement, cOrientation, cWeight, bItalic, bUnderline, bStrikeOut, iCharSet, iOutPrecision, iClipPrecision, iQuality, iPitchAndFamily, pszFaceName), ret);
inline HFONT CreateFont(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName)
	safe_ret_as(auto ret = ::CreateFontW(cHeight, cWidth, cEscapement, cOrientation, cWeight, bItalic, bUnderline, bStrikeOut, iCharSet, iOutPrecision, iClipPrecision, iQuality, iPitchAndFamily, pszFaceName), ret);
// CreateHatchBrush
inline HBRUSH CreateHatchBrush(int iHatch, COLORREF color)
	safe_ret_as(auto ret = ::CreateHatchBrush(iHatch, color), ret);
// CreateIC
#undef CreateIC
inline HDC CreateIC(LPCSTR pszDriver, LPCSTR pszDevice, LPCSTR pszPort, CONST DEVMODEA *pdm)
	safe_ret_as(auto ret = ::CreateICA(pszDriver, pszDevice, pszPort, pdm), ret);
inline HDC CreateIC(LPCWSTR pszDriver, LPCWSTR pszDevice, LPCWSTR pszPort, CONST DEVMODEW *pdm)
	safe_ret_as(auto ret = ::CreateICW(pszDriver, pszDevice, pszPort, pdm), ret);
// CreateMetaFile
#undef CreateMetaFile
inline HDC CreateMetaFile(LPCSTR pszFile)
	safe_ret_as(auto ret = ::CreateMetaFileA(pszFile), ret);
inline HDC CreateMetaFile(LPCWSTR pszFile)
	safe_ret_as(auto ret = ::CreateMetaFileW(pszFile), ret);
// CreatePalette
inline HPALETTE CreatePalette(CONST LOGPALETTE *plpal)
	safe_ret_as(auto ret = ::CreatePalette(plpal), ret);
// CreatePen
inline HPEN CreatePen(int iStyle, int cWidth, COLORREF color)
	safe_ret_as(auto ret = ::CreatePen(iStyle, cWidth, color), ret);
// CreatePenIndirect
inline HPEN CreatePenIndirect(CONST LOGPEN *plpen)
	safe_ret_as(auto ret = ::CreatePenIndirect(plpen), ret);
// CreatePolyPolygonRgn
inline HRGN CreatePolyPolygonRgn(CONST POINT *pptl, CONST INT *pc, int cPoly, int iMode)
	safe_ret_as(auto ret = ::CreatePolyPolygonRgn(pptl, pc, cPoly, iMode), ret);
// CreatePatternBrush
inline HBRUSH CreatePatternBrush(HBITMAP hbm)
	safe_ret_as(auto ret = ::CreatePatternBrush(hbm), ret);
// CreateRectRgn
inline HRGN CreateRectRgn(int x1, int y1, int x2, int y2)
	safe_ret_as(auto ret = ::CreateRectRgn(x1, y1, x2, y2), ret);
// CreateRectRgnIndirect
inline HRGN CreateRectRgnIndirect(CONST RECT *lprect)
	safe_ret_as(auto ret = ::CreateRectRgnIndirect(lprect), ret);
// CreateRoundRectRgn
inline HRGN CreateRoundRectRgn(int x1, int y1, int x2, int y2, int w, int h)
	safe_ret_as(auto ret = ::CreateRoundRectRgn(x1, y1, x2, y2, w, h), ret);
// CreateScalableFontResource
#undef CreateScalableFontResource
inline void CreateScalableFontResource(DWORD fdwHidden, LPCSTR lpszFont, LPCSTR lpszFile, LPCSTR lpszPath)
	safe_ret_as(::CreateScalableFontResourceA(fdwHidden, lpszFont, lpszFile, lpszPath));
inline void CreateScalableFontResource(DWORD fdwHidden, LPCWSTR lpszFont, LPCWSTR lpszFile, LPCWSTR lpszPath)
	safe_ret_as(::CreateScalableFontResourceW(fdwHidden, lpszFont, lpszFile, lpszPath));
// CreateSolidBrush
inline HBRUSH CreateSolidBrush(COLORREF color)
	safe_ret_as(auto ret = ::CreateSolidBrush(color), ret);
// DeleteDC
inline void DeleteDC(HDC hdc)
	safe_ret_as(::DeleteDC(hdc));
// DeleteMetaFile
inline void DeleteMetaFile(HMETAFILE hmf)
	safe_ret_as(::DeleteMetaFile(hmf));
// DeleteObject
inline void DeleteObject(HGDIOBJ ho)
	safe_ret_as(::DeleteObject(ho));
// DescribePixelFormat
inline int DescribePixelFormat(HDC hdc, int iPixelFormat, UINT nBytes, LPPIXELFORMATDESCRIPTOR ppfd)
	safe_ret_as(auto ret = ::DescribePixelFormat(hdc, iPixelFormat, nBytes, ppfd); ret > 0, ret);
// DeviceCapabilities
#undef DeviceCapabilities
inline int DeviceCapabilities(LPCSTR pDevice, LPCSTR pPort, WORD fwCapability, LPSTR pOutput, CONST DEVMODEA *pDevMode)
	safe_ret_as(auto ret = ::DeviceCapabilitiesA(pDevice, pPort, fwCapability, pOutput, pDevMode); ret >= 0, ret);
inline int DeviceCapabilities(LPCWSTR pDevice, LPCWSTR pPort, WORD fwCapability, LPWSTR pOutput, CONST DEVMODEW *pDevMode)
	safe_ret_as(auto ret = ::DeviceCapabilitiesW(pDevice, pPort, fwCapability, pOutput, pDevMode); ret >= 0, ret);
// DrawEscape
inline int DrawEscape(HDC hdc, int iEscape, int cjIn, LPCSTR lpIn)
	safe_ret_as(auto ret = ::DrawEscape(hdc, iEscape, cjIn, lpIn); ret >= 0, ret);
// Ellipse
inline void Ellipse(HDC hdc, int left, int top, int right, int bottom)
	safe_ret_as(::Ellipse(hdc, left, top, right, bottom));
// EnumFontFamiliesEx
#undef EnumFontFamiliesEx
inline int EnumFontFamiliesEx(HDC hdc, LPLOGFONTA lpLogfont, FONTENUMPROCA lpProc, LPARAM lParam, DWORD dwFlags)
	ret_as(::EnumFontFamiliesExA(hdc, lpLogfont, lpProc, lParam, dwFlags));
inline int EnumFontFamiliesEx(HDC hdc, LPLOGFONTW lpLogfont, FONTENUMPROCW lpProc, LPARAM lParam, DWORD dwFlags)
	ret_as(::EnumFontFamiliesExW(hdc, lpLogfont, lpProc, lParam, dwFlags));
// EnumFontFamilies
#undef EnumFontFamilies
inline int EnumFontFamilies(HDC hdc, LPCSTR lpLogfont, FONTENUMPROCA lpProc, LPARAM lParam)
	ret_as(::EnumFontFamiliesA(hdc, lpLogfont, lpProc, lParam));
inline int EnumFontFamilies(HDC hdc, LPCWSTR lpLogfont, FONTENUMPROCW lpProc, LPARAM lParam)
	ret_as(::EnumFontFamiliesW(hdc, lpLogfont, lpProc, lParam));
// EnumFonts
#undef EnumFonts
inline int EnumFonts(HDC hdc, LPCSTR lpLogfont, FONTENUMPROCA lpProc, LPARAM lParam)
	ret_as(::EnumFontsA(hdc, lpLogfont, lpProc, lParam));
inline int EnumFonts(HDC hdc, LPCWSTR lpLogfont, FONTENUMPROCW lpProc, LPARAM lParam)
	ret_as(::EnumFontsW(hdc, lpLogfont, lpProc, lParam));
// EnumObjects
inline int EnumObjects(HDC hdc, int nType, GOBJENUMPROC lpFunc, LPARAM lParam)
	ret_as(::EnumObjects(hdc, nType, lpFunc, lParam));
// EqualRgn
inline bool EqualRgn(HRGN hrgn1, HRGN hrgn2)
	ret_as(::EqualRgn(hrgn1, hrgn2));
// Escape
inline int Escape(HDC hdc, int iEscape, int cjIn, LPCSTR pvIn, LPVOID pvOut)
	safe_ret_as(auto ret = ::Escape(hdc, iEscape, cjIn, pvIn, pvOut); ret > 0, ret);
// ExtEscape
inline int ExtEscape(HDC hdc, int iEscape, int cjInput, LPCSTR lpInData, int cjOutput, LPSTR lpOutData)
	safe_ret_as(auto ret = ::ExtEscape(hdc, iEscape, cjInput, lpInData, cjOutput, lpOutData); ret > 0, ret);
// ExcludeClipRect
inline int ExcludeClipRect(HDC hdc, int left, int top, int right, int bottom)
	safe_ret_as(auto ret = ::ExcludeClipRect(hdc, left, top, right, bottom); ret != ERROR, ret);
// ExtCreateRegion
inline HRGN ExtCreateRegion(CONST XFORM *lpx, DWORD nCount, CONST RGNDATA *lpData)
	safe_ret_as(auto ret = ::ExtCreateRegion(lpx, nCount, lpData), ret);
// ExtFloodFill
inline void ExtFloodFill(HDC hdc, int x, int y, COLORREF color, UINT type)
	safe_ret_as(::ExtFloodFill(hdc, x, y, color, type));
// FillRgn
inline void FillRgn(HDC hdc, HRGN hrgn, HBRUSH hbr)
	safe_ret_as(::FillRgn(hdc, hrgn, hbr));
// FloodFill
inline void FloodFill(HDC hdc, int x, int y, COLORREF color)
	safe_ret_as(::FloodFill(hdc, x, y, color));
// FrameRgn
inline void FrameRgn(HDC hdc, HRGN hrgn, HBRUSH hbr, int w, int h)
	safe_ret_as(::FrameRgn(hdc, hrgn, hbr, w, h));
// GetROP2
inline int GetROP2(HDC hdc)
	safe_ret_as(auto ret = ::GetROP2(hdc); ret > 0, ret);
// GetAspectRatioFilterEx
inline void GetAspectRatioFilterEx(HDC hdc, LPSIZE lpsize)
	safe_ret_as(::GetAspectRatioFilterEx(hdc, lpsize));
// GetBkColor
inline COLORREF GetBkColor(HDC hdc)
	safe_ret_as(auto ret = ::GetBkColor(hdc); ret != CLR_INVALID, ret);
// GetDCBrushColor
inline COLORREF GetDCBrushColor(HDC hdc)
	safe_ret_as(auto ret = ::GetDCBrushColor(hdc); ret != CLR_INVALID, ret);
// GetDCPenColor
inline COLORREF GetDCPenColor(HDC hdc)
	safe_ret_as(auto ret = ::GetDCPenColor(hdc); ret != CLR_INVALID, ret);
// GetBkMode
inline int GetBkMode(HDC hdc)
	safe_ret_as(auto ret = ::GetBkMode(hdc); ret > 0, ret);
// GetBitmapBits
inline LONG GetBitmapBits(HBITMAP hbit, LONG cb, LPVOID lpvBits)
	safe_ret_as(auto ret = ::GetBitmapBits(hbit, cb, lpvBits), ret);
// GetBitmapDimensionEx
inline void GetBitmapDimensionEx(HBITMAP hbit, LPSIZE lpsize)
	safe_ret_as(::GetBitmapDimensionEx(hbit, lpsize));
// GetBoundsRect
inline UINT GetBoundsRect(HDC hdc, LPRECT lprect, UINT flags)
	safe_ret_as(auto ret = ::GetBoundsRect(hdc, lprect, flags), ret);
// GetBrushOrgEx
inline void GetBrushOrgEx(HDC hdc, LPPOINT lppt)
	safe_ret_as(::GetBrushOrgEx(hdc, lppt));
// GetCharWidth
#undef GetCharWidth
template<bool IsUnicode = WX::IsUnicode>
inline void GetCharWidth(HDC hdc, UINT iFirst, UINT iLast, LPINT lpBuffer) {
	if_c (IsUnicode)
		 safe_ret_as(::GetCharWidthA(hdc, iFirst, iLast, lpBuffer))
	else safe_ret_as(::GetCharWidthW(hdc, iFirst, iLast, lpBuffer))
}
// GetCharWidth32
#undef GetCharWidth32
template<bool IsUnicode = WX::IsUnicode>
inline void GetCharWidth32(HDC hdc, UINT iFirst, UINT iLast, LPINT lpBuffer) {
	if_c (IsUnicode)
		 safe_ret_as(::GetCharWidth32A(hdc, iFirst, iLast, lpBuffer))
	else safe_ret_as(::GetCharWidth32W(hdc, iFirst, iLast, lpBuffer))
}
// GetCharWidthFloat
#undef GetCharWidthFloat
template<bool IsUnicode = WX::IsUnicode>
inline void GetCharWidthFloat(HDC hdc, UINT iFirst, UINT iLast, PFLOAT lpBuffer) {
	if_c (IsUnicode)
		 safe_ret_as(::GetCharWidthFloatA(hdc, iFirst, iLast, lpBuffer))
	else safe_ret_as(::GetCharWidthFloatW(hdc, iFirst, iLast, lpBuffer))
}
// GetCharABCWidths
#undef GetCharABCWidths
template<bool IsUnicode = WX::IsUnicode>
inline void GetCharABCWidths(HDC hdc, UINT wFirst, UINT wLast, LPABC lpABC) {
	if_c (IsUnicode)
		 safe_ret_as(::GetCharABCWidthsA(hdc, wFirst, wLast, lpABC))
	else safe_ret_as(::GetCharABCWidthsW(hdc, wFirst, wLast, lpABC))
}
// GetCharABCWidthsFloat
#undef GetCharABCWidthsFloat
template<bool IsUnicode = WX::IsUnicode>
inline void GetCharABCWidthsFloat(HDC hdc, UINT iFirst, UINT iLast, LPABCFLOAT lpABC) {
	if_c (IsUnicode)
		 safe_ret_as(::GetCharABCWidthsFloatA(hdc, iFirst, iLast, lpABC))
	else safe_ret_as(::GetCharABCWidthsFloatW(hdc, iFirst, iLast, lpABC))
}
// GetClipBox
inline int GetClipBox(HDC hdc, LPRECT lprect)
	safe_ret_as(auto ret = ::GetClipBox(hdc, lprect); ret != ERROR, ret);
// GetClipRgn
inline int GetClipRgn(HDC hdc, HRGN hrgn)
	safe_ret_as(auto ret = ::GetClipRgn(hdc, hrgn); ret > 0, ret);
// GetMetaRgn
inline int GetMetaRgn(HDC hdc, HRGN hrgn)
	safe_ret_as(auto ret = ::GetMetaRgn(hdc, hrgn); ret > 0, ret);
// GetCurrentObject
inline HGDIOBJ GetCurrentObject(HDC hdc, UINT type)
	safe_ret_as(auto ret = ::GetCurrentObject(hdc, type), ret);
// GetCurrentPositionEx
inline void GetCurrentPositionEx(HDC hdc, LPPOINT lppt)
	safe_ret_as(::GetCurrentPositionEx(hdc, lppt));
// GetDeviceCaps
inline int GetDeviceCaps(HDC hdc, int index)
	ret_as(::GetDeviceCaps(hdc, index));
// GetDIBits
inline int GetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines, LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT usage)
	safe_ret_as(auto ret = ::GetDIBits(hdc, hbm, start, cLines, lpvBits, lpbmi, usage); ret > 0, ret);
// GetFontData
inline DWORD GetFontData(HDC hdc, DWORD dwTable, DWORD dwOffset, PVOID pvBuffer, DWORD cjBuffer)
	safe_ret_as(auto ret = ::GetFontData(hdc, dwTable, dwOffset, pvBuffer, cjBuffer); ret != GCP_ERROR, ret);
// GetGlyphOutline
#undef GetGlyphOutline
template<bool IsUnicode = WX::IsUnicode>
inline DWORD GetGlyphOutline(HDC hdc, UINT uChar, UINT fuFormat, LPGLYPHMETRICS lpgm, DWORD cjBuffer, LPVOID pvBuffer, CONST MAT2 *lpmat2) {
	if_c (IsUnicode)
		 ret_as(::GetGlyphOutlineA(hdc, uChar, fuFormat, lpgm, cjBuffer, pvBuffer, lpmat2))
	else ret_as(::GetGlyphOutlineW(hdc, uChar, fuFormat, lpgm, cjBuffer, pvBuffer, lpmat2))
}
// GetGraphicsMode
inline int GetGraphicsMode(HDC hdc)
	safe_ret_as(auto ret = ::GetGraphicsMode(hdc); ret > 0, ret);
// GetMapMode
inline int GetMapMode(HDC hdc)
	safe_ret_as(auto ret = ::GetMapMode(hdc); ret > 0, ret);
// GetMetaFileBitsEx
inline UINT GetMetaFileBitsEx(HMETAFILE hMF, UINT cbBuffer, LPVOID lpData)
	safe_ret_as(auto ret = ::GetMetaFileBitsEx(hMF, cbBuffer, lpData), ret);
// GetMetaFile
#undef GetMetaFile
inline HMETAFILE GetMetaFile(LPCSTR lpName)
	safe_ret_as(auto ret = ::GetMetaFileA(lpName), ret);
inline HMETAFILE GetMetaFile(LPCWSTR lpName)
	safe_ret_as(auto ret = ::GetMetaFileW(lpName), ret);
// GetNearestColor
inline COLORREF GetNearestColor(HDC hdc, COLORREF color)
	safe_ret_as(auto ret = ::GetNearestColor(hdc, color); ret != CLR_INVALID, ret);
// GetNearestPaletteIndex
inline UINT GetNearestPaletteIndex(HPALETTE h, COLORREF color)
	safe_ret_as(auto ret = ::GetNearestPaletteIndex(h, color); ret != CLR_INVALID, ret);
// GetObjectType
inline DWORD GetObjectType(HGDIOBJ h)
	safe_ret_as(auto ret = ::GetObjectType(h), ret);
// GetOutlineTextMetrics
#undef GetOutlineTextMetrics
inline UINT GetOutlineTextMetrics(HDC hdc, UINT cjCopy, LPOUTLINETEXTMETRICA potm)
	safe_ret_as(auto ret = ::GetOutlineTextMetricsA(hdc, cjCopy, potm), ret);
inline UINT GetOutlineTextMetrics(HDC hdc, UINT cjCopy, LPOUTLINETEXTMETRICW potm)
	safe_ret_as(auto ret = ::GetOutlineTextMetricsW(hdc, cjCopy, potm), ret);
// GetPaletteEntries
inline UINT GetPaletteEntries(HPALETTE hpal, UINT iStart, UINT cEntries, LPPALETTEENTRY pPalEntries)
	safe_ret_as(auto ret = ::GetPaletteEntries(hpal, iStart, cEntries, pPalEntries), ret);
// GetPixel
inline COLORREF GetPixel(HDC hdc, int x, int y)
	safe_ret_as(auto ret = ::GetPixel(hdc, x, y); ret != CLR_INVALID, ret);
// GetPixelFormat
inline int GetPixelFormat(HDC hdc)
	safe_ret_as(auto ret = ::GetPixelFormat(hdc); ret > 0, ret);
// GetPolyFillMode
inline int GetPolyFillMode(HDC hdc)
	safe_ret_as(auto ret = ::GetPolyFillMode(hdc); ret > 0, ret);
// GetRasterizerCaps
inline void GetRasterizerCaps(LPRASTERIZER_STATUS lpraststat, UINT cjBytes)
	safe_ret_as(::GetRasterizerCaps(lpraststat, cjBytes));
// GetRandomRgn
inline int GetRandomRgn(HDC hdc, HRGN hrgn, INT i)
	safe_ret_as(auto ret = ::GetRandomRgn(hdc, hrgn, i); ret > 0, ret);
// GetRegionData
inline DWORD GetRegionData(HRGN hrgn, DWORD nCount, LPRGNDATA lpRgnData)
	safe_ret_as(auto ret = ::GetRegionData(hrgn, nCount, lpRgnData), ret);
// GetRgnBox
inline int GetRgnBox(HRGN hrgn, LPRECT lprc)
	safe_ret_as(auto ret = ::GetRgnBox(hrgn, lprc); ret > 0, ret);
// GetStockObject
inline HGDIOBJ GetStockObject(int i)
	safe_ret_as(auto ret = ::GetStockObject(i), ret);
// GetStretchBltMode
inline int GetStretchBltMode(HDC hdc)
	safe_ret_as(auto ret = ::GetStretchBltMode(hdc); ret > 0, ret);
// GetSystemPaletteEntries
inline UINT GetSystemPaletteEntries(HDC hdc, UINT iStart, UINT cEntries, LPPALETTEENTRY pPalEntries)
	safe_ret_as(auto ret = ::GetSystemPaletteEntries(hdc, iStart, cEntries, pPalEntries), ret);
// GetSystemPaletteUse
inline UINT GetSystemPaletteUse(HDC hdc)
	safe_ret_as(auto ret = ::GetSystemPaletteUse(hdc); ret != SYSPAL_ERROR, ret);
// GetTextCharacterExtra
inline int GetTextCharacterExtra(HDC hdc)
	safe_ret_as(auto ret = ::GetTextCharacterExtra(hdc); ret != 0x8000000, ret);
// GetTextAlign
inline UINT GetTextAlign(HDC hdc)
	safe_ret_as(auto ret = ::GetTextAlign(hdc); ret != GCP_ERROR, ret);
// GetTextColor
inline COLORREF GetTextColor(HDC hdc)
	safe_ret_as(auto ret = ::GetTextColor(hdc); ret != CLR_INVALID, ret);
// GetTextExtentPoint
#undef GetTextExtentPoint
inline void GetTextExtentPoint(HDC hdc, LPCSTR lpString, int c, LPSIZE lpsz)
	safe_ret_as(::GetTextExtentPointA(hdc, lpString, c, lpsz));
inline void GetTextExtentPoint(HDC hdc, LPCWSTR lpString, int c, LPSIZE lpsz)
	safe_ret_as(::GetTextExtentPointW(hdc, lpString, c, lpsz));
// GetTextExtentPoint32
#undef GetTextExtentPoint32
inline void GetTextExtentPoint32(HDC hdc, LPCSTR lpString, int c, LPSIZE psizl)
	safe_ret_as(::GetTextExtentPoint32A(hdc, lpString, c, psizl));
inline void GetTextExtentPoint32(HDC hdc, LPCWSTR lpString, int c, LPSIZE psizl)
	safe_ret_as(::GetTextExtentPoint32W(hdc, lpString, c, psizl));
// GetTextExtentExPoint
#undef GetTextExtentExPoint
inline void GetTextExtentExPoint(HDC hdc, LPCSTR lpszString, int cchString, int nMaxExtent, LPINT lpnFit, LPINT lpnDx, LPSIZE lpSize)
	safe_ret_as(::GetTextExtentExPointA(hdc, lpszString, cchString, nMaxExtent, lpnFit, lpnDx, lpSize));
inline void GetTextExtentExPoint(HDC hdc, LPCWSTR lpszString, int cchString, int nMaxExtent, LPINT lpnFit, LPINT lpnDx, LPSIZE lpSize)
	safe_ret_as(::GetTextExtentExPointW(hdc, lpszString, cchString, nMaxExtent, lpnFit, lpnDx, lpSize));
// GetTextCharset
inline int GetTextCharset(HDC hdc)
	ret_as(::GetTextCharset(hdc));
// GetTextCharsetInfo
inline int GetTextCharsetInfo(HDC hdc, LPFONTSIGNATURE lpSig, DWORD dwFlags)
	ret_as(::GetTextCharsetInfo(hdc, lpSig, dwFlags));
// TranslateCharsetInfo
inline void TranslateCharsetInfo(DWORD FAR *lpSrc, LPCHARSETINFO lpCs, DWORD dwFlags)
	safe_ret_as(::TranslateCharsetInfo(lpSrc, lpCs, dwFlags));
// GetFontLanguageInfo
inline DWORD GetFontLanguageInfo(HDC hdc)
	safe_ret_as(auto ret = ::GetFontLanguageInfo(hdc); ret != GCP_ERROR, ret);
// GetCharacterPlacement
#undef GetCharacterPlacement
inline DWORD GetCharacterPlacement(HDC hdc, LPCSTR lpString, int nCount, int nMexExtent, LPGCP_RESULTSA lpResults, DWORD dwFlags)
	safe_ret_as(auto ret = ::GetCharacterPlacementA(hdc, lpString, nCount, nMexExtent, lpResults, dwFlags), ret);
inline DWORD GetCharacterPlacement(HDC hdc, LPCWSTR lpString, int nCount, int nMexExtent, LPGCP_RESULTSW lpResults, DWORD dwFlags)
	safe_ret_as(auto ret = ::GetCharacterPlacementW(hdc, lpString, nCount, nMexExtent, lpResults, dwFlags), ret);
// GetFontUnicodeRanges
inline DWORD GetFontUnicodeRanges(HDC hdc, LPGLYPHSET lpgs)
	safe_ret_as(auto ret = ::GetFontUnicodeRanges(hdc, lpgs), ret);
// GetGlyphIndices
#undef GetGlyphIndices
inline DWORD GetGlyphIndices(HDC hdc, LPCSTR lpstr, int c, LPWORD pgi, DWORD fl)
	safe_ret_as(auto ret = ::GetGlyphIndicesA(hdc, lpstr, c, pgi, fl); ret != GCP_ERROR, ret);
inline DWORD GetGlyphIndices(HDC hdc, LPCWSTR lpstr, int c, LPWORD pgi, DWORD fl)
	safe_ret_as(auto ret = ::GetGlyphIndicesW(hdc, lpstr, c, pgi, fl); ret != GCP_ERROR, ret);
// GetTextExtentPointI
inline void GetTextExtentPointI(HDC hdc, LPWORD pgiIn, int cgi, LPSIZE psize)
	safe_ret_as(::GetTextExtentPointI(hdc, pgiIn, cgi, psize));
// GetTextExtentExPointI
inline void GetTextExtentExPointI(HDC hdc, LPWORD lpwszString, int cwchString, int nMaxExtent, LPINT lpnFit, LPINT lpnDx, LPSIZE lpSize)
	safe_ret_as(::GetTextExtentExPointI(hdc, lpwszString, cwchString, nMaxExtent, lpnFit, lpnDx, lpSize));
// GetCharWidthI
inline void GetCharWidthI(HDC hdc, UINT giFirst, UINT cgi, LPWORD pgi, LPINT piWidths)
	safe_ret_as(::GetCharWidthI(hdc, giFirst, cgi, pgi, piWidths));
// GetCharABCWidthsI
inline void GetCharABCWidthsI(HDC hdc, UINT giFirst, UINT cgi, LPWORD pgi, LPABC pabc)
	safe_ret_as(::GetCharABCWidthsI(hdc, giFirst, cgi, pgi, pabc));
// AddFontResourceEx
#undef AddFontResourceEx
inline int AddFontResourceEx(LPCSTR name, DWORD fl, PVOID res)
	safe_ret_as(auto ret = ::AddFontResourceExA(name, fl, res); ret > 0, ret);
inline int AddFontResourceEx(LPCWSTR name, DWORD fl, PVOID res)
	safe_ret_as(auto ret = ::AddFontResourceExW(name, fl, res); ret > 0, ret);
// RemoveFontResourceEx
#undef RemoveFontResourceEx
inline void RemoveFontResourceEx(LPCSTR name, DWORD fl, PVOID pdv)
	safe_ret_as(::RemoveFontResourceExA(name, fl, pdv));
inline void RemoveFontResourceEx(LPCWSTR name, DWORD fl, PVOID pdv)
	safe_ret_as(::RemoveFontResourceExW(name, fl, pdv));
// AddFontMemResourceEx
inline HANDLE AddFontMemResourceEx(PVOID pFileView, DWORD cjSize, PVOID pvResrved, DWORD *pNumFonts)
	safe_ret_as(auto ret = ::AddFontMemResourceEx(pFileView, cjSize, pvResrved, pNumFonts), ret);
// RemoveFontMemResourceEx
inline void RemoveFontMemResourceEx(HANDLE h)
	safe_ret_as(::RemoveFontMemResourceEx(h));
// GetViewportExtEx
inline void GetViewportExtEx(HDC hdc, LPSIZE lpsize)
	safe_ret_as(::GetViewportExtEx(hdc, lpsize));
// GetViewportOrgEx
inline void GetViewportOrgEx(HDC hdc, LPPOINT lppoint)
	safe_ret_as(::GetViewportOrgEx(hdc, lppoint));
// GetWindowExtEx
inline void GetWindowExtEx(HDC hdc, LPSIZE lpsize)
	safe_ret_as(::GetWindowExtEx(hdc, lpsize));
// GetWindowOrgEx
inline void GetWindowOrgEx(HDC hdc, LPPOINT lppoint)
	safe_ret_as(::GetWindowOrgEx(hdc, lppoint));
// IntersectClipRect
inline int IntersectClipRect(HDC hdc, int left, int top, int right, int bottom)
	safe_ret_as(auto ret = ::IntersectClipRect(hdc, left, top, right, bottom); ret != ERROR, ret);
// InvertRgn
inline void InvertRgn(HDC hdc, HRGN hrgn)
	safe_ret_as(::InvertRgn(hdc, hrgn));
// LineDDA
inline void LineDDA(int xStart, int yStart, int xEnd, int yEnd, LINEDDAPROC lpProc, LPARAM data)
	safe_ret_as(::LineDDA(xStart, yStart, xEnd, yEnd, lpProc, data));
// LineTo
inline void LineTo(HDC hdc, int x, int y)
	safe_ret_as(::LineTo(hdc, x, y));
// MaskBlt
inline void MaskBlt(HDC hdcDest, int xDest, int yDest, int width, int height, HDC hdcSrc, int xSrc, int ySrc, HBITMAP hbmMask, int xMask, int yMask, DWORD rop)
	safe_ret_as(::MaskBlt(hdcDest, xDest, yDest, width, height, hdcSrc, xSrc, ySrc, hbmMask, xMask, yMask, rop));
// PlgBlt
inline void PlgBlt(HDC hdcDest, CONST POINT *lpPoint, HDC hdcSrc, int xSrc, int ySrc, int width, int height, HBITMAP hbmMask, int xMask, int yMask)
	safe_ret_as(::PlgBlt(hdcDest, lpPoint, hdcSrc, xSrc, ySrc, width, height, hbmMask, xMask, yMask));
// OffsetClipRgn
inline int OffsetClipRgn(HDC hdc, int x, int y)
	safe_ret_as(auto ret = ::OffsetClipRgn(hdc, x, y); ret != ERROR, ret);
// OffsetRgn
inline int OffsetRgn(HRGN hrgn, int x, int y)
	safe_ret_as(auto ret = ::OffsetRgn(hrgn, x, y); ret != ERROR, ret);
// PatBlt
inline void PatBlt(HDC hdc, int x, int y, int w, int h, DWORD rop)
	safe_ret_as(::PatBlt(hdc, x, y, w, h, rop));
// Pie
inline void Pie(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2)
	safe_ret_as(::Pie(hdc, left, top, right, bottom, xr1, yr1, xr2, yr2));
// PlayMetaFile
inline void PlayMetaFile(HDC hdc, HMETAFILE hmf)
	safe_ret_as(::PlayMetaFile(hdc, hmf));
// PaintRgn
inline void PaintRgn(HDC hdc, HRGN hrgn)
	safe_ret_as(::PaintRgn(hdc, hrgn));
// PolyPolygon
inline void PolyPolygon(HDC hdc, CONST POINT *apt, CONST INT *asz, int csz)
	safe_ret_as(::PolyPolygon(hdc, apt, asz, csz));
// PtInRegion
inline bool PtInRegion(HRGN hrgn, int x, int y)
	ret_as(::PtInRegion(hrgn, x, y));
// PtVisible
inline bool PtVisible(HDC hdc, int x, int y)
	safe_ret_as(auto ret = ::PtVisible(hdc, x, y); ret >= 0, ret);
// RectInRegion
inline bool RectInRegion(HRGN hrgn, CONST RECT *lprect)
	ret_as(::RectInRegion(hrgn, lprect));
// RectVisible
inline int RectVisible(HDC hdc, CONST RECT *lprect)
	ret_as(::RectVisible(hdc, lprect));
// Rectangle
inline void Rectangle(HDC hdc, int left, int top, int right, int bottom)
	safe_ret_as(::Rectangle(hdc, left, top, right, bottom));
// RestoreDC
inline void RestoreDC(HDC hdc, int nSavedDC)
	safe_ret_as(::RestoreDC(hdc, nSavedDC));
// ResetDC
#undef ResetDC
inline HDC ResetDC(HDC hdc, CONST DEVMODEA *lpdm)
	safe_ret_as(auto ret = ::ResetDCA(hdc, lpdm), ret);
inline HDC ResetDC(HDC hdc, CONST DEVMODEW *lpdm)
	safe_ret_as(auto ret = ::ResetDCW(hdc, lpdm), ret);
// RealizePalette
inline UINT RealizePalette(HDC hdc)
	safe_ret_as(auto ret = ::RealizePalette(hdc); ret != GCP_ERROR, ret);
// RemoveFontResource
#undef RemoveFontResource
inline void RemoveFontResource(LPCSTR lpFileName)
	safe_ret_as(::RemoveFontResourceA(lpFileName));
inline void RemoveFontResource(LPCWSTR lpFileName)
	safe_ret_as(::RemoveFontResourceW(lpFileName));
// RoundRect
inline void RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height)
	safe_ret_as(::RoundRect(hdc, left, top, right, bottom, width, height));
// ResizePalette
inline void ResizePalette(HPALETTE hpal, UINT n)
	safe_ret_as(::ResizePalette(hpal, n));
// SaveDC
inline int SaveDC(HDC hdc)
	safe_ret_as(auto ret = ::SaveDC(hdc); ret > 0, ret);
// SelectClipRgn
inline int SelectClipRgn(HDC hdc, HRGN hrgn)
	safe_ret_as(auto ret = ::SelectClipRgn(hdc, hrgn); ret != ERROR, ret);
// ExtSelectClipRgn
inline int ExtSelectClipRgn(HDC hdc, HRGN hrgn, int mode)
	safe_ret_as(auto ret = ::ExtSelectClipRgn(hdc, hrgn, mode); ret != ERROR, ret);
// SetMetaRgn
inline int SetMetaRgn(HDC hdc)
	safe_ret_as(auto ret = ::SetMetaRgn(hdc); ret != ERROR, ret);
// SelectObject
static inline HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h)
	safe_ret_as(auto ret = ::SelectObject(hdc, h); ret != HGDI_ERROR, ret);
// SelectPalette
inline HPALETTE SelectPalette(HDC hdc, HPALETTE hPal, BOOL bForceBkgd)
	safe_ret_as(auto ret = ::SelectPalette(hdc, hPal, bForceBkgd), ret);
// SetBkColor
inline COLORREF SetBkColor(HDC hdc, COLORREF color)
	safe_ret_as(auto ret = ::SetBkColor(hdc, color); ret != CLR_INVALID, ret);
// SetDCBrushColor
inline COLORREF SetDCBrushColor(HDC hdc, COLORREF color)
	safe_ret_as(auto ret = ::SetDCBrushColor(hdc, color); ret != CLR_INVALID, ret);
// SetDCPenColor
inline COLORREF SetDCPenColor(HDC hdc, COLORREF color)
	safe_ret_as(auto ret = ::SetDCPenColor(hdc, color); ret != GCP_ERROR, ret);
// SetBkMode
inline int SetBkMode(HDC hdc, int mode)
	safe_ret_as(auto ret = ::SetBkMode(hdc, mode); ret > 0, ret);
// SetBitmapBits
inline LONG SetBitmapBits(HBITMAP hbm, DWORD cb, CONST VOID *pvBits)
	safe_ret_as(auto ret = ::SetBitmapBits(hbm, cb, pvBits), ret);
// SetBoundsRect
inline UINT SetBoundsRect(HDC hdc, CONST RECT *lprect, UINT flags)
	safe_ret_as(auto ret = ::SetBoundsRect(hdc, lprect, flags), ret);
// SetDIBits
inline int SetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines, CONST VOID *lpBits, CONST BITMAPINFO *lpbmi, UINT ColorUse)
	safe_ret_as(auto ret = ::SetDIBits(hdc, hbm, start, cLines, lpBits, lpbmi, ColorUse); ret > 0, ret);
// SetDIBitsToDevice
inline int SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h, int xSrc, int ySrc, UINT StartScan, UINT cLines, CONST VOID *lpvBits, CONST BITMAPINFO *lpbmi, UINT ColorUse)
	ret_as(::SetDIBitsToDevice(hdc, xDest, yDest, w, h, xSrc, ySrc, StartScan, cLines, lpvBits, lpbmi, ColorUse));
// SetMapperFlags
inline DWORD SetMapperFlags(HDC hdc, DWORD flags)
	safe_ret_as(auto ret = ::SetMapperFlags(hdc, flags); ret != GCP_ERROR, ret);
// SetGraphicsMode
inline int SetGraphicsMode(HDC hdc, int iMode)
	safe_ret_as(auto ret = ::SetGraphicsMode(hdc, iMode); ret > 0, ret);
// SetMapMode
inline int SetMapMode(HDC hdc, int iMode)
	safe_ret_as(auto ret = ::SetMapMode(hdc, iMode); ret > 0, ret);
// SetLayout
inline DWORD SetLayout(HDC hdc, DWORD l)
	safe_ret_as(auto ret = ::SetLayout(hdc, l); ret != GCP_ERROR, ret);
// GetLayout
inline DWORD GetLayout(HDC hdc)
	safe_ret_as(auto ret = ::GetLayout(hdc); ret != GCP_ERROR, ret);
// SetMetaFileBitsEx
inline HMETAFILE SetMetaFileBitsEx(UINT cbBuffer, CONST BYTE *lpData)
	safe_ret_as(auto ret = ::SetMetaFileBitsEx(cbBuffer, lpData), ret);
// SetPaletteEntries
inline UINT SetPaletteEntries(HPALETTE hpal, UINT iStart, UINT cEntries, CONST PALETTEENTRY *pPalEntries)
	safe_ret_as(auto ret = ::SetPaletteEntries(hpal, iStart, cEntries, pPalEntries), ret);
// SetPixel
inline COLORREF SetPixel(HDC hdc, int x, int y, COLORREF color)
	safe_ret_as(auto ret = ::SetPixel(hdc, x, y, color); ret != CLR_INVALID, ret);
// SetPixelV
inline void SetPixelV(HDC hdc, int x, int y, COLORREF color)
	safe_ret_as(::SetPixelV(hdc, x, y, color));
// SetPixelFormat
inline void SetPixelFormat(HDC hdc, int format, CONST PIXELFORMATDESCRIPTOR *ppfd)
	safe_ret_as(::SetPixelFormat(hdc, format, ppfd));
// SetPolyFillMode
inline int SetPolyFillMode(HDC hdc, int mode)
	safe_ret_as(auto ret = ::SetPolyFillMode(hdc, mode); ret > 0, ret);
// StretchBlt
inline void StretchBlt(HDC hdcDest, int xDest, int yDest, int wDest, int hDest, HDC hdcSrc, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop)
	safe_ret_as(::StretchBlt(hdcDest, xDest, yDest, wDest, hDest, hdcSrc, xSrc, ySrc, wSrc, hSrc, rop));
// SetRectRgn
inline void SetRectRgn(HRGN hrgn, int left, int top, int right, int bottom)
	safe_ret_as(::SetRectRgn(hrgn, left, top, right, bottom));
// StretchDIBits
inline int StretchDIBits(HDC hdc, int xDest, int yDest, int DestWidth, int DestHeight, int xSrc, int ySrc, int SrcWidth, int SrcHeight, CONST VOID *lpBits, CONST BITMAPINFO *lpbmi, UINT iUsage, DWORD rop)
	ret_as(::StretchDIBits(hdc, xDest, yDest, DestWidth, DestHeight, xSrc, ySrc, SrcWidth, SrcHeight, lpBits, lpbmi, iUsage, rop));
// SetROP2
inline int SetROP2(HDC hdc, int rop2)
	safe_ret_as(auto ret = ::SetROP2(hdc, rop2); ret > 0, ret);
// SetStretchBltMode
inline int SetStretchBltMode(HDC hdc, int mode)
	safe_ret_as(auto ret = ::SetStretchBltMode(hdc, mode); ret > 0, ret);
// SetSystemPaletteUse
inline UINT SetSystemPaletteUse(HDC hdc, UINT use)
	safe_ret_as(auto ret = ::SetSystemPaletteUse(hdc, use); ret != SYSPAL_ERROR, ret);
// SetTextCharacterExtra
inline int SetTextCharacterExtra(HDC hdc, int extra)
	safe_ret_as(auto ret = ::SetTextCharacterExtra(hdc, extra); ret != 0x8000000, ret);
// SetTextColor
inline COLORREF SetTextColor(HDC hdc, COLORREF color)
	safe_ret_as(auto ret = ::SetTextColor(hdc, color); ret != CLR_INVALID, ret);
// SetTextAlign
inline UINT SetTextAlign(HDC hdc, UINT align)
	safe_ret_as(auto ret = ::SetTextAlign(hdc, align); ret != GCP_ERROR, ret);
// SetTextJustification
inline void SetTextJustification(HDC hdc, int extra, int count)
	safe_ret_as(::SetTextJustification(hdc, extra, count));
// UpdateColors
inline void UpdateColors(HDC hdc)
	safe_ret_as(::UpdateColors(hdc));
// GdiRegisterDdraw - Undocument
// GdiMarshalSize - Undocument
// GdiMarshal - Undocument
// GdiUnmarshal - Undocument
// AlphaBlend
inline void AlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
	safe_ret_as(::AlphaBlend(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, ftn));
// TransparentBlt
inline void TransparentBlt(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, UINT crTransparent)
	safe_ret_as(::TransparentBlt(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, crTransparent));
// GradientFill
inline void GradientFill(HDC hdc, PTRIVERTEX pVertex, ULONG nVertex, PVOID pMesh, ULONG nMesh, ULONG ulMode)
	safe_ret_as(::GradientFill(hdc, pVertex, nVertex, pMesh, nMesh, ulMode));
// GdiAlphaBlend
inline void GdiAlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
	safe_ret_as(::GdiAlphaBlend(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, ftn));
// GdiTransparentBlt
inline void GdiTransparentBlt(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, UINT crTransparent)
	safe_ret_as(::GdiTransparentBlt(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, crTransparent));
// GdiGradientFill
inline void GdiGradientFill(HDC hdc, PTRIVERTEX pVertex, ULONG nVertex, PVOID pMesh, ULONG nCount, ULONG ulMode)
	safe_ret_as(::GdiGradientFill(hdc, pVertex, nVertex, pMesh, nCount, ulMode));
// PlayMetaFileRecord
inline void PlayMetaFileRecord(HDC hdc, LPHANDLETABLE lpHandleTable, LPMETARECORD lpMR, UINT noObjs)
	safe_ret_as(::PlayMetaFileRecord(hdc, lpHandleTable, lpMR, noObjs));
// EnumMetaFile
inline void EnumMetaFile(HDC hdc, HMETAFILE hmf, MFENUMPROC proc, LPARAM param)
	safe_ret_as(::EnumMetaFile(hdc, hmf, proc, param));
// CloseEnhMetaFile
inline HENHMETAFILE CloseEnhMetaFile(HDC hdc)
	safe_ret_as(auto ret = ::CloseEnhMetaFile(hdc), ret);
// CopyEnhMetaFile
#undef CopyEnhMetaFile
inline HENHMETAFILE CopyEnhMetaFile(HENHMETAFILE hEnh, LPCSTR lpFileName)
	safe_ret_as(auto ret = ::CopyEnhMetaFileA(hEnh, lpFileName), ret);
inline HENHMETAFILE CopyEnhMetaFile(HENHMETAFILE hEnh, LPCWSTR lpFileName)
	safe_ret_as(auto ret = ::CopyEnhMetaFileW(hEnh, lpFileName), ret);
// CreateEnhMetaFile
#undef CreateEnhMetaFile
inline HDC CreateEnhMetaFile(HDC hdc, LPCSTR lpFilename, CONST RECT *lprc, LPCSTR lpDesc)
	safe_ret_as(auto ret = ::CreateEnhMetaFileA(hdc, lpFilename, lprc, lpDesc), ret);
inline HDC CreateEnhMetaFile(HDC hdc, LPCWSTR lpFilename, CONST RECT *lprc, LPCWSTR lpDesc)
	safe_ret_as(auto ret = ::CreateEnhMetaFileW(hdc, lpFilename, lprc, lpDesc), ret);
// DeleteEnhMetaFile
inline void DeleteEnhMetaFile(HENHMETAFILE hmf)
	safe_ret_as(::DeleteEnhMetaFile(hmf));
// EnumEnhMetaFile
inline void EnumEnhMetaFile(HDC hdc, HENHMETAFILE hmf, ENHMFENUMPROC proc, LPVOID param, CONST RECT *lpRect)
	safe_ret_as(::EnumEnhMetaFile(hdc, hmf, proc, param, lpRect));
// GetEnhMetaFile
#undef GetEnhMetaFile
inline HENHMETAFILE GetEnhMetaFile(LPCSTR lpName)
	safe_ret_as(auto ret = ::GetEnhMetaFileA(lpName), ret);
inline HENHMETAFILE GetEnhMetaFile(LPCWSTR lpName)
	safe_ret_as(auto ret = ::GetEnhMetaFileW(lpName), ret);
// GetEnhMetaFileBits
inline UINT GetEnhMetaFileBits(HENHMETAFILE hEMF, UINT nSize, LPBYTE lpData)
	safe_ret_as(auto ret = ::GetEnhMetaFileBits(hEMF, nSize, lpData), ret);
// GetEnhMetaFileDescription
#undef GetEnhMetaFileDescription
inline UINT GetEnhMetaFileDescription(HENHMETAFILE hemf, UINT cchBuffer, LPSTR lpDescription)
	safe_ret_as(auto ret = ::GetEnhMetaFileDescriptionA(hemf, cchBuffer, lpDescription); ret != GCP_ERROR, ret);
inline UINT GetEnhMetaFileDescription(HENHMETAFILE hemf, UINT cchBuffer, LPWSTR lpDescription)
	safe_ret_as(auto ret = ::GetEnhMetaFileDescriptionW(hemf, cchBuffer, lpDescription); ret != GCP_ERROR, ret);
// GetEnhMetaFileHeader
inline UINT GetEnhMetaFileHeader(HENHMETAFILE hemf, UINT nSize, LPENHMETAHEADER lpEnhMetaHeader)
	safe_ret_as(auto ret = ::GetEnhMetaFileHeader(hemf, nSize, lpEnhMetaHeader), ret);
// GetEnhMetaFilePaletteEntries
inline UINT GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf, UINT nNumEntries, LPPALETTEENTRY lpPaletteEntries)
	safe_ret_as(auto ret = ::GetEnhMetaFilePaletteEntries(hemf, nNumEntries, lpPaletteEntries); ret != GCP_ERROR, ret);
// GetEnhMetaFilePixelFormat
inline UINT GetEnhMetaFilePixelFormat(HENHMETAFILE hemf, UINT cbBuffer, PIXELFORMATDESCRIPTOR *ppfd)
	safe_ret_as(auto ret = ::GetEnhMetaFilePixelFormat(hemf, cbBuffer, ppfd), ret);
// GetWinMetaFileBits
inline UINT GetWinMetaFileBits(HENHMETAFILE hemf, UINT cbData16, LPBYTE pData16, INT iMapMode, HDC hdcRef)
	safe_ret_as(auto ret = ::GetWinMetaFileBits(hemf, cbData16, pData16, iMapMode, hdcRef), ret);
// PlayEnhMetaFile
inline void PlayEnhMetaFile(HDC hdc, HENHMETAFILE hmf, CONST RECT *lprect)
	safe_ret_as(::PlayEnhMetaFile(hdc, hmf, lprect));
// PlayEnhMetaFileRecord
inline void PlayEnhMetaFileRecord(HDC hdc, LPHANDLETABLE pht, CONST ENHMETARECORD *pmr, UINT cht)
	safe_ret_as(::PlayEnhMetaFileRecord(hdc, pht, pmr, cht));
// SetEnhMetaFileBits
inline HENHMETAFILE SetEnhMetaFileBits(UINT nSize, CONST BYTE *pb)
	safe_ret_as(auto ret = ::SetEnhMetaFileBits(nSize, pb), ret);
// SetWinMetaFileBits
inline HENHMETAFILE SetWinMetaFileBits(UINT nSize, CONST BYTE *lpMeta16Data, HDC hdcRef, CONST METAFILEPICT *lpMFP)
	safe_ret_as(auto ret = ::SetWinMetaFileBits(nSize, lpMeta16Data, hdcRef, lpMFP), ret);
// GdiComment
inline void GdiComment(HDC hdc, UINT nSize, CONST BYTE *lpData)
	safe_ret_as(::GdiComment(hdc, nSize, lpData));
// GetTextMetrics
#undef GetTextMetrics
inline void GetTextMetrics(HDC hdc, LPTEXTMETRICA lptm)
	safe_ret_as(::GetTextMetricsA(hdc, lptm));
inline void GetTextMetrics(HDC hdc, LPTEXTMETRICW lptm)
	safe_ret_as(::GetTextMetricsW(hdc, lptm));
// AngleArc
inline void AngleArc(HDC hdc, int x, int y, DWORD r, FLOAT StartAngle, FLOAT SweepAngle)
	safe_ret_as(::AngleArc(hdc, x, y, r, StartAngle, SweepAngle));
// PolyPolyline
inline void PolyPolyline(HDC hdc, CONST POINT *apt, CONST DWORD *asz, DWORD csz)
	safe_ret_as(::PolyPolyline(hdc, apt, asz, csz));
// GetWorldTransform
inline void GetWorldTransform(HDC hdc, LPXFORM lpxf)
	safe_ret_as(::GetWorldTransform(hdc, lpxf));
// SetWorldTransform
inline void SetWorldTransform(HDC hdc, CONST XFORM *lpxf)
	safe_ret_as(::SetWorldTransform(hdc, lpxf));
// ModifyWorldTransform
inline void ModifyWorldTransform(HDC hdc, CONST XFORM *lpxf, DWORD mode)
	safe_ret_as(::ModifyWorldTransform(hdc, lpxf, mode));
// CombineTransform
inline void CombineTransform(LPXFORM lpxfOut, CONST XFORM *lpxf1, CONST XFORM *lpxf2)
	safe_ret_as(::CombineTransform(lpxfOut, lpxf1, lpxf2));
// CreateDIBSection
inline HBITMAP CreateDIBSection(HDC hdc, CONST BITMAPINFO *pbmi, UINT usage, VOID **ppvBits, HANDLE hSection, DWORD offset)
	safe_ret_as(auto ret = ::CreateDIBSection(hdc, pbmi, usage, ppvBits, hSection, offset), ret);
// GetDIBColorTable
inline UINT GetDIBColorTable(HDC hdc, UINT iStart, UINT cEntries, RGBQUAD *prgbq)
	safe_ret_as(auto ret = ::GetDIBColorTable(hdc, iStart, cEntries, prgbq), ret);
// SetDIBColorTable
inline UINT SetDIBColorTable(HDC hdc, UINT iStart, UINT cEntries, CONST RGBQUAD *prgbq)
	safe_ret_as(auto ret = ::SetDIBColorTable(hdc, iStart, cEntries, prgbq), ret);
// SetColorAdjustment
inline void SetColorAdjustment(HDC hdc, CONST COLORADJUSTMENT *lpca)
	safe_ret_as(::SetColorAdjustment(hdc, lpca));
// GetColorAdjustment
inline void GetColorAdjustment(HDC hdc, LPCOLORADJUSTMENT lpca)
	safe_ret_as(::GetColorAdjustment(hdc, lpca));
// CreateHalftonePalette
inline HPALETTE CreateHalftonePalette(HDC hdc)
	safe_ret_as(auto ret = ::CreateHalftonePalette(hdc), ret);
// StartDoc
#undef StartDoc
inline int StartDoc(HDC hdc, CONST DOCINFOA *lpdi)
	safe_ret_as(auto ret = ::StartDocA(hdc, lpdi); ret > 0, ret);
inline int StartDoc(HDC hdc, CONST DOCINFOW *lpdi)
	safe_ret_as(auto ret = ::StartDocW(hdc, lpdi); ret > 0, ret);
// EndDoc
inline int EndDoc(HDC hdc)
	safe_ret_as(auto ret = ::EndDoc(hdc); ret > 0, ret);
// StartPage
inline int StartPage(HDC hdc)
	safe_ret_as(auto ret = ::StartPage(hdc); ret > 0, ret);
// EndPage
inline int EndPage(HDC hdc)
	safe_ret_as(auto ret = ::EndPage(hdc); ret > 0, ret);
// AbortDoc
inline int AbortDoc(HDC hdc)
	safe_ret_as(auto ret = ::AbortDoc(hdc); ret > 0, ret);
// SetAbortProc
inline int SetAbortProc(HDC hdc, ABORTPROC proc)
	safe_ret_as(auto ret = ::SetAbortProc(hdc, proc); ret > 0, ret);
// AbortPath
inline void AbortPath(HDC hdc)
	safe_ret_as(::AbortPath(hdc));
// ArcTo
inline void ArcTo(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2)
	safe_ret_as(::ArcTo(hdc, left, top, right, bottom, xr1, yr1, xr2, yr2));
// BeginPath
inline void BeginPath(HDC hdc)
	safe_ret_as(::BeginPath(hdc));
// CloseFigure
inline void CloseFigure(HDC hdc)
	safe_ret_as(::CloseFigure(hdc));
// EndPath
inline void EndPath(HDC hdc)
	safe_ret_as(::EndPath(hdc));
// FillPath
inline void FillPath(HDC hdc)
	safe_ret_as(::FillPath(hdc));
// FlattenPath
inline void FlattenPath(HDC hdc)
	safe_ret_as(::FlattenPath(hdc));
// GetPath
inline int GetPath(HDC hdc, LPPOINT apt, LPBYTE aj, int cpt)
	ret_as(::GetPath(hdc, apt, aj, cpt));
// PathToRegion
inline HRGN PathToRegion(HDC hdc)
	safe_ret_as(auto ret = ::PathToRegion(hdc), ret);
// PolyDraw
inline void PolyDraw(HDC hdc, CONST POINT *apt, CONST BYTE *aj, int cpt)
	safe_ret_as(::PolyDraw(hdc, apt, aj, cpt));
// SelectClipPath
inline void SelectClipPath(HDC hdc, int mode)
	safe_ret_as(::SelectClipPath(hdc, mode));
// SetArcDirection
inline int SetArcDirection(HDC hdc, int dir)
	safe_ret_as(auto ret = ::SetArcDirection(hdc, dir); ret > 0, ret);
// SetMiterLimit
inline void SetMiterLimit(HDC hdc, FLOAT limit, PFLOAT old)
	safe_ret_as(::SetMiterLimit(hdc, limit, old));
// StrokeAndFillPath
inline void StrokeAndFillPath(HDC hdc)
	safe_ret_as(::StrokeAndFillPath(hdc));
// StrokePath
inline void StrokePath(HDC hdc)
	safe_ret_as(::StrokePath(hdc));
// WidenPath
inline void WidenPath(HDC hdc)
	safe_ret_as(::WidenPath(hdc));
// ExtCreatePen
inline HPEN ExtCreatePen(DWORD iPenStyle, DWORD cWidth, CONST LOGBRUSH *plbrush, DWORD cStyle, CONST DWORD *pstyle)
	safe_ret_as(auto ret = ::ExtCreatePen(iPenStyle, cWidth, plbrush, cStyle, pstyle), ret);
// GetMiterLimit
inline void GetMiterLimit(HDC hdc, PFLOAT plimit)
	safe_ret_as(::GetMiterLimit(hdc, plimit));
// GetArcDirection
inline int GetArcDirection(HDC hdc)
	safe_ret_as(auto ret = ::GetArcDirection(hdc); ret > 0, ret);
// GetObject
#undef GetObject
template<bool IsUnicode = WX::IsUnicode>
inline int GetObject(HANDLE h, int c, LPVOID pv) {
	if_c (IsUnicode)
		 safe_ret_as(auto ret = ::GetObjectA(h, c, pv); ret > 0, ret)
	else safe_ret_as(auto ret = ::GetObjectW(h, c, pv); ret > 0, ret)
}
// MoveToEx
inline void MoveToEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::MoveToEx(hdc, x, y, lppt));
// TextOut
#undef TextOut
inline void TextOut(HDC hdc, int x, int y, LPCSTR lpString, int c)
	safe_ret_as(::TextOutA(hdc, x, y, lpString, c));
inline void TextOut(HDC hdc, int x, int y, LPCWSTR lpString, int c)
	safe_ret_as(::TextOutW(hdc, x, y, lpString, c));
// ExtTextOut
#undef ExtTextOut
inline void ExtTextOut(HDC hdc, int x, int y, UINT options, CONST RECT *lprect, LPCSTR lpString, UINT c, CONST INT *lpDx)
	safe_ret_as(::ExtTextOutA(hdc, x, y, options, lprect, lpString, c, lpDx));
inline void ExtTextOut(HDC hdc, int x, int y, UINT options, CONST RECT *lprect, LPCWSTR lpString, UINT c, CONST INT *lpDx)
	safe_ret_as(::ExtTextOutW(hdc, x, y, options, lprect, lpString, c, lpDx));
// PolyTextOut
#undef PolyTextOut
inline void PolyTextOut(HDC hdc, CONST POLYTEXTA *ppt, int nstrings)
	safe_ret_as(::PolyTextOutA(hdc, ppt, nstrings));
inline void PolyTextOut(HDC hdc, CONST POLYTEXTW *ppt, int nstrings)
	safe_ret_as(::PolyTextOutW(hdc, ppt, nstrings));
// CreatePolygonRgn
inline HRGN CreatePolygonRgn(CONST POINT *pptl, int cPoint, int iMode)
	safe_ret_as(auto ret = ::CreatePolygonRgn(pptl, cPoint, iMode), ret);
// DPtoLP
inline void DPtoLP(HDC hdc, LPPOINT lppt, int c)
	safe_ret_as(::DPtoLP(hdc, lppt, c));
// LPtoDP
inline void LPtoDP(HDC hdc, LPPOINT lppt, int c)
	safe_ret_as(::LPtoDP(hdc, lppt, c));
// Polygon
inline void Polygon(HDC hdc, CONST POINT *apt, int cpt)
	safe_ret_as(::Polygon(hdc, apt, cpt));
// Polyline
inline void Polyline(HDC hdc, CONST POINT *apt, int cpt)
	safe_ret_as(::Polyline(hdc, apt, cpt));
// PolyBezier
inline void PolyBezier(HDC hdc, CONST POINT *apt, DWORD cpt)
	safe_ret_as(::PolyBezier(hdc, apt, cpt));
// PolyBezierTo
inline void PolyBezierTo(HDC hdc, CONST POINT *apt, DWORD cpt)
	safe_ret_as(::PolyBezierTo(hdc, apt, cpt));
// PolylineTo
inline void PolylineTo(HDC hdc, CONST POINT *apt, DWORD cpt)
	safe_ret_as(::PolylineTo(hdc, apt, cpt));
// SetViewportExtEx
inline void SetViewportExtEx(HDC hdc, int x, int y, LPSIZE lpsz)
	safe_ret_as(::SetViewportExtEx(hdc, x, y, lpsz));
// SetViewportOrgEx
inline void SetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::SetViewportOrgEx(hdc, x, y, lppt));
// SetWindowExtEx
inline void SetWindowExtEx(HDC hdc, int x, int y, LPSIZE lpsz)
	safe_ret_as(::SetWindowExtEx(hdc, x, y, lpsz));
// SetWindowOrgEx
inline void SetWindowOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::SetWindowOrgEx(hdc, x, y, lppt));
// OffsetViewportOrgEx
inline void OffsetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::OffsetViewportOrgEx(hdc, x, y, lppt));
// OffsetWindowOrgEx
inline void OffsetWindowOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::OffsetWindowOrgEx(hdc, x, y, lppt));
// ScaleViewportExtEx
inline void ScaleViewportExtEx(HDC hdc, int xn, int dx, int yn, int yd, LPSIZE lpsz)
	safe_ret_as(::ScaleViewportExtEx(hdc, xn, dx, yn, yd, lpsz));
// ScaleWindowExtEx
inline void ScaleWindowExtEx(HDC hdc, int xn, int xd, int yn, int yd, LPSIZE lpsz)
	safe_ret_as(::ScaleWindowExtEx(hdc, xn, xd, yn, yd, lpsz));
// SetBitmapDimensionEx
inline void SetBitmapDimensionEx(HBITMAP hbm, int w, int h, LPSIZE lpsz)
	safe_ret_as(::SetBitmapDimensionEx(hbm, w, h, lpsz));
// SetBrushOrgEx
inline void SetBrushOrgEx(HDC hdc, int x, int y, LPPOINT lppt)
	safe_ret_as(::SetBrushOrgEx(hdc, x, y, lppt));
// GetTextFace
#undef GetTextFace
inline int GetTextFace(HDC hdc, int c, LPSTR lpName)
	safe_ret_as(auto ret = ::GetTextFaceA(hdc, c, lpName); ret > 0, ret);
inline int GetTextFace(HDC hdc, int c, LPWSTR lpName)
	safe_ret_as(auto ret = ::GetTextFaceW(hdc, c, lpName); ret > 0, ret);
// GetKerningPairs
#undef GetKerningPairs
template<bool IsUnicode = WX::IsUnicode>
inline DWORD GetKerningPairs(HDC hdc, DWORD nPairs, LPKERNINGPAIR lpKernPair) {
	if_c (IsUnicode)
		 safe_ret_as(auto ret = ::GetKerningPairsA(hdc, nPairs, lpKernPair), ret)
	else safe_ret_as(auto ret = ::GetKerningPairsW(hdc, nPairs, lpKernPair), ret)
}
// GetDCOrgEx
inline void GetDCOrgEx(HDC hdc, LPPOINT lppt)
	safe_ret_as(::GetDCOrgEx(hdc, lppt));
// FixBrushOrgEx - Undocument
// UnrealizeObject
inline void UnrealizeObject(HGDIOBJ h)
	safe_ret_as(::UnrealizeObject(h));
// GdiFlush
inline void GdiFlush()
	safe_ret_as(::GdiFlush());
// GdiSetBatchLimit
inline DWORD GdiSetBatchLimit(DWORD dw)
	safe_ret_as(auto ret = ::GdiSetBatchLimit(dw), ret);
// GdiGetBatchLimit
inline DWORD GdiGetBatchLimit()
	safe_ret_as(auto ret = ::GdiGetBatchLimit(), ret);
// SetICMMode
inline int SetICMMode(HDC hdc, int mode)
	safe_ret_as(auto ret = ::SetICMMode(hdc, mode); ret > 0, ret);
// CheckColorsInGamut
inline void CheckColorsInGamut(HDC hdc, LPRGBTRIPLE lpRGBTriple, LPVOID dlpBuffer, DWORD nCount)
	safe_ret_as(::CheckColorsInGamut(hdc, lpRGBTriple, dlpBuffer, nCount));
// GetColorSpace
inline HCOLORSPACE GetColorSpace(HDC hdc)
	safe_ret_as(auto ret = ::GetColorSpace(hdc), ret);
// GetLogColorSpace
#undef GetLogColorSpace
inline void GetLogColorSpace(HCOLORSPACE hColorSpace, LPLOGCOLORSPACEA lpBuffer, DWORD nSize)
	safe_ret_as(::GetLogColorSpaceA(hColorSpace, lpBuffer, nSize));
inline void GetLogColorSpace(HCOLORSPACE hColorSpace, LPLOGCOLORSPACEW lpBuffer, DWORD nSize)
	safe_ret_as(::GetLogColorSpaceW(hColorSpace, lpBuffer, nSize));
// CreateColorSpace
#undef CreateColorSpace
inline HCOLORSPACE CreateColorSpace(LPLOGCOLORSPACEA lplcs)
	safe_ret_as(auto ret = ::CreateColorSpaceA(lplcs), ret);
inline HCOLORSPACE CreateColorSpace(LPLOGCOLORSPACEW lplcs)
	safe_ret_as(auto ret = ::CreateColorSpaceW(lplcs), ret);
// SetColorSpace
inline HCOLORSPACE SetColorSpace(HDC hdc, HCOLORSPACE hcs)
	safe_ret_as(auto ret = ::SetColorSpace(hdc, hcs), ret);
// DeleteColorSpace
inline void DeleteColorSpace(HCOLORSPACE hcs)
	safe_ret_as(::DeleteColorSpace(hcs));
// GetICMProfile
#undef GetICMProfile
inline void GetICMProfile(HDC hdc, LPDWORD pBufSize, LPSTR pszFilename)
	safe_ret_as(::GetICMProfileA(hdc, pBufSize, pszFilename));
inline void GetICMProfile(HDC hdc, LPDWORD pBufSize, LPWSTR pszFilename)
	safe_ret_as(::GetICMProfileW(hdc, pBufSize, pszFilename));
// SetICMProfile
#undef SetICMProfile
inline void SetICMProfile(HDC hdc, LPSTR lpFileName)
	safe_ret_as(::SetICMProfileA(hdc, lpFileName));
inline void SetICMProfile(HDC hdc, LPWSTR lpFileName)
	safe_ret_as(::SetICMProfileW(hdc, lpFileName));
// GetDeviceGammaRamp
inline void GetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
	safe_ret_as(::GetDeviceGammaRamp(hdc, lpRamp));
// SetDeviceGammaRamp
inline void SetDeviceGammaRamp(HDC hdc, LPVOID lpRamp)
	safe_ret_as(::SetDeviceGammaRamp(hdc, lpRamp));
// ColorMatchToTarget
inline void ColorMatchToTarget(HDC hdc, HDC hdcTarget, DWORD action)
	safe_ret_as(::ColorMatchToTarget(hdc, hdcTarget, action));
// EnumICMProfiles
#undef EnumICMProfiles
inline int EnumICMProfiles(HDC hdc, ICMENUMPROCA proc, LPARAM param)
	ret_as(::EnumICMProfilesA(hdc, proc, param));
inline int EnumICMProfiles(HDC hdc, ICMENUMPROCW proc, LPARAM param)
	ret_as(::EnumICMProfilesW(hdc, proc, param));
// UpdateICMRegKey - Deprecated
// ColorCorrectPalette
inline void ColorCorrectPalette(HDC hdc, HPALETTE hPal, DWORD deFirst, DWORD num)
	safe_ret_as(::ColorCorrectPalette(hdc, hPal, deFirst, num));
#pragma endregion

}
#pragma endregion

export namespace WX {

#pragma region GObject
template<class AnyChild, class BaseHandle = HGDIOBJ>
class GObjectBase;
using GObject = GObjectBase<void>;
template<class AnyChild, class BaseHandle>
class GObjectBase : public ExtendShim<GObjectBase<AnyChild, BaseHandle>, AnyChild> {
	misuse_assert((std::is_convertible_v<BaseHandle, HGDIOBJ>),
				 "BaseHandle must can be converted to HANDLE");
public:
	using Child = Chain<GObjectBase, AnyChild>;
protected:
	friend_to_proxy(GObjectBase);
	mutable HGDIOBJ hobj = O;
	GObjectBase(HGDIOBJ h) : hobj(h) {}
	GObjectBase(const GObjectBase &h) : hobj(h.hobj) ret_to(h.hobj = O);
public:
	GObjectBase() {}
	GObjectBase(Nu) {}
	GObjectBase(GObjectBase &obj) : hobj(obj.hobj) { obj.hobj = O; }
	GObjectBase(GObjectBase &&obj) : hobj(obj.hobj) { obj.hobj = O; }
	~GObjectBase() ret_to(Delete());
public:
	inline void Delete() {
		if (hobj)
			WX::DeleteObject(hobj);
		hobj = O;
	}
public:
	inline operator BaseHandle() const ret_as(ref_cast<BaseHandle>(hobj));
	inline Child &operator=(Child &obj) ret_to_child(std::swap(obj.hobj, hobj));
	inline Child &operator=(Child &&obj) ret_to_child(std::swap(obj.hobj, hobj));
	inline const Child &operator=(const Child &obj) const ret_to_child(std::swap(obj.hobj, hobj));
public:
	static inline auto &Attach(BaseHandle &hObj) ret_as(ref_cast<AnyChild>(hObj));
	static inline const auto &Attach(const BaseHandle &hObj) ret_as(ref_cast<const AnyChild>(hObj));
	static inline void AutoDelete(BaseHandle &hObj) ret_to(if (hObj) (WX::DeleteObject(hObj), hObj = O));
};
using CGObject = ProxyView<GObject>;
#pragma endregion

#pragma region Bitmap
enum_class(BitmapCompressions , DWORD        ,
		   RGB                = BI_RGB       ,
		   RLE8               = BI_RLE8      ,
		   RLE4               = BI_RLE4      ,
		   BitFields          = BI_BITFIELDS ,
		   JPEG               = BI_JPEG      ,
		   PNG                = BI_PNG       );
#pragma pack(2)
class BitmapHeader : protected BITMAPFILEHEADER, protected BITMAPINFO {
public:
	BitmapHeader() : BITMAPFILEHEADER{ 0 }, BITMAPINFO{ { 0 } } {
		this->bfType = *(const WORD *)"BM";
		this->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		this->bmiHeader.biCompression = BI_RGB;
	}
public: // Property - PaletteSize
	/* W */ inline auto &PaletteSize(DWORD dwSize) ret_to_self(this->bfOffBits = dwSize + sizeof(*this) - 4);
	/* R */ inline DWORD PaletteSize() const ret_as(this->bfOffBits - sizeof(*this) - 4);
public: // Property - ColorsSize
	/* W */ inline auto &ColorsSize(DWORD dwSize) ret_to_self(this->bfSize = this->bfOffBits + dwSize);
	/* R */ inline DWORD ColorsSize() const ret_as(this->bfSize - this->bfOffBits);
public: // Property - FileSize
	/* R */ inline DWORD FileSize() const ret_as(this->bfSize);
public: // Property - Width
	/* W */ inline auto &Width(LONG biWidth) ret_to_self(this->bmiHeader.biWidth = biWidth);
	/* R */ inline LONG  Width() const ret_as(this->bmiHeader.biWidth);
public: // Property - Height
	/* W */ inline auto &Height(LONG biHeight) ret_to_self(this->bmiHeader.biHeight = biHeight);
	/* R */ inline LONG  Height() const ret_as(this->bmiHeader.biHeight);
public: // Property - Size
	/* W */ inline auto &Size(LSize sz) ret_to_self(bmiHeader.biWidth = sz.cx, bmiHeader.biHeight = sz.cy);
	/* R */ inline LSize Size() const ret_as({ bmiHeader.biWidth, bmiHeader.biHeight });
public: // Property - Compression
	/* W */ inline auto &Compression(BitmapCompressions biCompression) ret_to_self(this->bmiHeader.biCompression = biCompression.yield());
	/* R */ inline BitmapCompressions Compression() const ret_as(reuse_cast<BitmapCompressions>(this->bmiHeader.biCompression));
public: // Property - SizeImage
	/* R */ inline DWORD SizeImage() const ret_as(this->bmiHeader.biSizeImage);
public: // Property - PixelsPerMeter
	/* W */ inline auto &PixelsPerMeter(LSize sz) ret_to_self(bmiHeader.biXPelsPerMeter = sz.cx, bmiHeader.biYPelsPerMeter = sz.cy);
	/* R */ inline LSize PixelsPerMeter() const ret_as({ bmiHeader.biXPelsPerMeter, bmiHeader.biYPelsPerMeter });
public: // Property - Planes
	/* W */ inline auto &Planes(WORD biPlanes) ret_to_self(this->bmiHeader.biPlanes = biPlanes);
	/* R */ inline WORD  Planes() const ret_as(this->bmiHeader.biPlanes);
public: // Property - BitsPerPixel
	/* W */ inline auto &BitsPerPixel(WORD biBitCount) ret_to_self(this->bmiHeader.biBitCount = biBitCount);
	/* R */ inline WORD  BitsPerPixel() const ret_as(this->bmiHeader.biBitCount);
public: // Property - ColorUsed
	/* W */ inline auto &ColorUsed(DWORD biClrUsed) ret_to_self(this->bmiHeader.biClrUsed = biClrUsed);
	/* R */ inline DWORD ColorUsed() const ret_as(this->bmiHeader.biClrUsed);
public: // Property - ColorImportant
	/* W */ inline auto &ColorImportant(DWORD biClrImportant) ret_to_self(this->bmiHeader.biClrImportant = biClrImportant);
	/* R */ inline DWORD ColorImportant() const ret_as(this->bmiHeader.biClrImportant);
public: // Property - PaletteStart
	// /* W */ inline auto PaletteStart() ret_to_self(this->bmiColors);
	/* R */ inline auto PaletteStart() const ret_as(this->bmiColors);
public: // Property - Colors
	// /* W */ inline void *ColorsStart() ret_to_self(((Int8U *)PaletteStart()) + PaletteSize());
	/* R */ inline void *ColorsStart() const ret_as(((Int8U *)PaletteStart()) + PaletteSize());
public:
	inline operator LPBITMAPFILEHEADER() ret_as(this);
	inline operator const BITMAPFILEHEADER *() const ret_as(this);
	inline operator LPBITMAPINFO() ret_as(this);
	inline operator const BITMAPINFO *() const ret_as(this);
};
#pragma pack()
class BitmapLogic : public StructShim<BITMAP> {
public:
	using Super = StructShim<BITMAP>;
public:
	BitmapLogic() {}
	proxy_prop_sync(Width,bmWidth,LONG);
	proxy_prop_sync(Height,bmHeight,LONG);
public: // Property - Size
	/* W */ inline auto &Size(LSize sz) ret_to_self(self->bmWidth = sz.cx, self->bmHeight = sz.cy);
	/* R */ inline LSize Size() const ret_as({ self->bmWidth, self->bmHeight });
	proxy_prop_sync(WidthBytes,bmWidthBytes,LONG);
	proxy_prop_sync(Planes,bmPlanes,WORD);
	proxy_prop_sync(BitsPerPixel,bmBitsPixel,WORD);
	proxy_prop_sync(Colors,bmBits,LPVOID);
public:
	inline HBITMAP Create() const ret_as(WX::CreateBitmapIndirect(this));
	inline operator HBITMAP() const ret_as(Create());
};
class BaseOf_GDI(Bitmap, HBITMAP) {
public:
	using Header = BitmapHeader;
	using File = BitmapHeader;
	using Logic = BitmapLogic;
	using Super = GObjectBase<Bitmap, HBITMAP>;
protected:
	friend_to_proxy(Bitmap);
	Bitmap(HBITMAP h) : Super(h) {}
	Bitmap(const Bitmap & b) : Super(b) {}
public:
	Bitmap() {}
	Bitmap(Nu) {}
	Bitmap(Bitmap & b) : Super(b) {}
	Bitmap(Bitmap && b) : Super(b) {}
public:
	class CreateStruct {
		int nWidth, nHeight;
		UINT nPlanes = 1, nBitsPerPixel = 32;
		LPCVOID lpBits = O;
	public:
		CreateStruct(LSize s) : nWidth(s.cx), nHeight(s.cy) {}
	public: // Property - Width
		/* W */ inline auto &Width(LONG nWidth) ret_to_self(this->nWidth = nWidth);
		/* R */ inline LONG  Width() const ret_as(this->nWidth);
	public: // Property - Height
		/* W */ inline auto &Height(LONG nHeight) ret_to_self(this->nHeight = nHeight);
		/* R */ inline LONG  Height() const ret_as(this->nHeight);
	public: // Property - Size
		/* W */ inline auto &Size(LSize sz) ret_to_self(this->nWidth = sz.cx, this->nHeight = sz.cy);
		/* R */ inline LSize Size() const ret_as({ this->nWidth, this->nHeight });
	public: // Property - Planes
		/* W */ inline auto &Planes(UINT nPlanes) ret_to_self(this->nPlanes = nPlanes);
		/* R */ inline UINT  Planes() const ret_as(this->nPlanes);
	public: // Property - BitsPerPixel
		/* W */ inline auto &BitsPerPixel(UINT nBitsPerPixel) ret_to_self(this->nBitsPerPixel = nBitsPerPixel);
		/* R */ inline UINT  BitsPerPixel() const ret_as(this->nBitsPerPixel);
	public: // Property - Colors
		/* W */ inline auto &Colors(LPCVOID lpBits) ret_to_self(this->lpBits = lpBits);
		/* R */ inline LPCVOID Colors() const ret_as(this->lpBits);
	public:
		inline Bitmap Create() const ret_as(WX::CreateBitmap(nWidth, nHeight, nPlanes, nBitsPerPixel, lpBits));
		inline operator Bitmap() const ret_as(Create());
	};
	static inline CreateStruct Create(LSize s = 0) ret_as(s);
	static inline Bitmap Create(const BITMAPINFO * pbi, void **ppbits, HANDLE hSection = O, DWORD offset = 0) ret_as(WX::CreateDIBSection(O, pbi, DIB_RGB_COLORS, ppbits, hSection, offset));
	static inline Bitmap Create(const BITMAPINFO * pbi, HANDLE hSection = O, DWORD offset = 0) ret_as(WX::CreateDIBSection(O, pbi, DIB_RGB_COLORS, O, hSection, offset));
	static inline Bitmap From(HDC hDC, LSize s) ret_as(WX::CreateCompatibleBitmap(hDC, s.cx, s.cy));
public:
	//inline auto &Restretch(LSize sz) ret_to_self((Super::hobj = (HBITMAP)CopyImage(self, IMAGE_BITMAP, sz.cx, sz.cy, LR_DEFAULTSIZE)));
	//inline Bitmap StretchNew(LSize sz) const ret_as((HBITMAP)CopyImage(self, IMAGE_BITMAP, sz.cx, sz.cy, LR_DEFAULTCOLOR));
	//inline Bitmap Clone() const ret_as(StretchNew(Size()));
#pragma region Properties
public: // Property - Size
	/* R */ inline LSize Size() const ret_to(LSize sz, WX::GetBitmapDimensionEx(self, &sz), sz);
public: // Property - SizeBytes
	/* R */ inline SizeT SizeBytes() const {
		auto &&log = Log();
		return (((log.Width() * log.Planes() /* nPlanes */ * log.BitsPerPixel() /* nBitCount */ + 15) >> 4) << 1) * log.Height();
	}
public: // Property - Colors
	/* W */ inline auto &GetColors(void *lpBits, DWORD cb) const ret_to_self(WX::GetBitmapBits(self, cb, lpBits));
	/* R */ inline auto &SetColors(const void *lpBits, DWORD cb) ret_to_self(WX::SetBitmapBits(self, cb, lpBits));
public: // Property - Log
	inline Logic Log() const ret_to(Logic log, GetObject(self, sizeof(log), reinterpret_cast<LPSTR>(&log)), log);
#pragma endregion
public:
	using Super::operator=;
};
using CBitmap = ProxyView<Bitmap>;
#pragma endregion

#pragma region Font
enum_flags(FontType         , WORD                        ,
		   Simulated        = SIMULATED_FONTTYPE          ,
		   Printer          = PRINTER_FONTTYPE            ,
		   Screen           = SCREEN_FONTTYPE             ,
		   Bold             = BOLD_FONTTYPE               ,
		   Italic           = ITALIC_FONTTYPE             ,
		   Regular          = REGULAR_FONTTYPE          /*,
		   PS_OpenType      = PS_OPENTYPE_FONTTYPE        ,
		   TT_OpenType      = TT_OPENTYPE_FONTTYPE        ,
		   Type1            = TYPE1_FONTTYPE              ,
		   Symbol           = SYMBOL_FONTTYPE           */);
enum_class(CharSets         , BYTE                        ,
		   ANSI             = ANSI_CHARSET                ,
		   Default          = DEFAULT_CHARSET             ,
		   Symbol           = SYMBOL_CHARSET              ,
		   ShiftJIS         = SHIFTJIS_CHARSET            ,
		   Hangeul          = HANGEUL_CHARSET             ,
		   Hangul           = HANGUL_CHARSET              ,
		   GB2312           = GB2312_CHARSET              ,
		   ChineseBig5      = CHINESEBIG5_CHARSET         ,
		   OEM              = OEM_CHARSET                 ,
		   Johab            = JOHAB_CHARSET               ,
		   Hebrew           = HEBREW_CHARSET              ,
		   Arabic           = ARABIC_CHARSET              ,
		   Greek            = GREEK_CHARSET               ,
		   Turkish          = TURKISH_CHARSET             ,
		   Vietnamese       = VIETNAMESE_CHARSET          ,
		   Thai             = THAI_CHARSET                ,
		   EastEurope       = EASTEUROPE_CHARSET          ,
		   Russian          = RUSSIAN_CHARSET             ,
		   Mac              = MAC_CHARSET                 ,
		   Baltic           = BALTIC_CHARSET              );
enum_class(OutPrecis        , BYTE                        , 
		   Default          = OUT_DEFAULT_PRECIS          ,
		   String           = OUT_STRING_PRECIS           ,
		   Character        = OUT_CHARACTER_PRECIS        ,
		   Stroke           = OUT_STROKE_PRECIS           ,
		   TrueType         = OUT_TT_PRECIS               ,
		   Device           = OUT_DEVICE_PRECIS           ,
		   Raster           = OUT_RASTER_PRECIS           ,
		   TrueTypeOnly     = OUT_TT_ONLY_PRECIS          ,
		   Outline          = OUT_OUTLINE_PRECIS          ,
		   ScreenOutline    = OUT_SCREEN_OUTLINE_PRECIS   ,
		   PostScriptOnly   = OUT_PS_ONLY_PRECIS          );
enum_flags(ClipPrecis       , BYTE                        ,
		   Default          = CLIP_DEFAULT_PRECIS         ,
		   Character        = CLIP_CHARACTER_PRECIS       ,
		   Stroke           = CLIP_STROKE_PRECIS          ,
		   Mask             = CLIP_MASK                   ,
		   LH_Angles        = CLIP_LH_ANGLES              ,
		   TT_Always        = CLIP_TT_ALWAYS              ,
		   DFA_Disable      = CLIP_DFA_DISABLE            ,
		   Embedded         = CLIP_EMBEDDED               );
enum_class(Qualities        , BYTE                        ,
		   Default          = DEFAULT_QUALITY             ,
		   Draf             = DRAFT_QUALITY               ,
		   Proof            = PROOF_QUALITY               ,
		   NonAntiAliased   = NONANTIALIASED_QUALITY      ,
		   AntiAliased      = ANTIALIASED_QUALITY         ,
		   ClearType        = CLEARTYPE_QUALITY           ,
		   ClearTypeNatural = CLEARTYPE_NATURAL_QUALITY   );
enum_class(FontPitches      , BYTE                        ,
		   Default          = DEFAULT_PITCH               ,
		   Fixed            = FIXED_PITCH                 ,
		   Variable         = VARIABLE_PITCH              ,
		   Mono             = MONO_FONT                   );
enum_class(FontFamilies     , BYTE                        ,
		   DontCare         = FF_DONTCARE                 ,
		   Roman            = FF_ROMAN                    ,
		   Swiss            = FF_SWISS                    ,
		   Modern           = FF_MODERN                   ,
		   Script           = FF_SCRIPT                   ,
		   Decorative       = FF_DECORATIVE               );
template<bool IsUnicode>
class FontLogicX : public StructShim<structx(LOGFONT)> {
	using_structx(LOGFONT);
	using TCHAR = XCHAR<IsUnicode>;
	using String = StringBase<TCHAR>;
public:
	using Super = StructShim<LOGFONT>;
public:
	FontLogicX() {}
	FontLogicX(const LOGFONT &lf) : Super(lf) {}
public: // Properties - Height
proxy_prop_sync(Height,lfHeight,LONG);
public: // Properties - Width
proxy_prop_sync(Width,lfWidth,LONG);
public: // Properties - Escapement
proxy_prop_sync(Escapement,lfEscapement,LONG);
public: // Properties - Orientation
proxy_prop_sync(Orientation,lfOrientation,LONG);
public: // Properties - Weight
proxy_prop_sync(Weight,lfWeight,LONG);
public: // Properties - Italic
proxy_prop_sync(Italic,lfItalic,bool);
public: // Properties - Underline
proxy_prop_sync(Underline,lfUnderline,bool);
public: // Properties - StrikeOut
proxy_prop_sync(StrikeOut,lfStrikeOut,bool);
public: // Properties - CharSet
	proxy_prop_set(CharSet,lfCharSet,CharSets);
	/* R */ inline CharSets CharSet() const ret_as(reuse_cast<CharSets>(self->lfCharSet));
public: // Properties - OutPrecision
	proxy_prop_set(OutPrecision,lfOutPrecision,OutPrecis);
	/* R */ inline OutPrecis OutPrecision() const ret_as(reuse_cast<OutPrecis>(self->lfOutPrecision));
public: // Properties - ClipPrecision
	proxy_prop_set(ClipPrecision,lfClipPrecision,ClipPrecis);
	/* R */ inline ClipPrecis ClipPrecision() const ret_as(reuse_cast<ClipPrecis>(self->lfClipPrecision));
public: // Properties - Quality
	proxy_prop_set(Quality,lfQuality,Qualities);
	/* R */ inline Qualities Quality() const ret_as(reuse_cast<Qualities>(self->lfQuality));
public: // Properties - Pitch
	/* W */ inline auto&Pitch(FontPitches lfPitch) ret_to_self(self->lfPitchAndFamily &= 0xF0, self->lfPitchAndFamily |= lfPitch.yield());
	/* R */ inline FontPitches Pitch() const ret_as(reuse_cast<FontPitches>((BYTE)(self->lfPitchAndFamily & 0x0F)));
public: // Properties - Family
	/* W */ inline auto&Family(FontFamilies lfFamily) ret_to_self(self->lfPitchAndFamily &= 0x0F, self->lfPitchAndFamily |= lfFamily.yield());
	/* R */ inline FontFamilies Family() const ret_as(reuse_cast<FontFamilies>((BYTE)(self->lfPitchAndFamily & 0xF0)));
public: // Properties - FaceName
	/* W */ inline auto &FaceName(String name) ret_to_self(String(self->lfFaceName).Copy(name));
	/* R */ inline const String FaceName() const ret_as(CString(self->lfFaceName, LF_FACESIZE));
};
using FontLogic = FontLogicX<IsUnicode>;
using FontLogicA = FontLogicX<false>;
using FontLogicW = FontLogicX<true>;
using CFontLogic = ProxyView<FontLogic>;
using CFontLogicA = ProxyView<FontLogicA>;
using CFontLogicW = ProxyView<FontLogicW>;
using FontLog = FontLogic;
using FontLogA = FontLogicA;
using FontLogW = FontLogicW;
using CFontLog = CFontLogic;
using CFontLogA = CFontLogicA;
using CFontLogW = CFontLogicW;
using LogFont = FontLogic;
using LogFontA = FontLogicA;
using LogFontW = FontLogicW;
using CLogFont = CFontLogic;
using CLogFontA = CFontLogicA;
using CLogFontW = CFontLogicW;
class BaseOf_GDI(Font, HFONT) {
public:
	using Super = GObjectBase<Font, HFONT>;
	using Logic = FontLogic;
	using LogicA = FontLogicA;
	using LogicW = FontLogicW;
protected:
	friend_to_proxy(Font);
	Font(HFONT h) : Super(h) {}
	Font(const Font &f) : Super(f) {}
public:
	Font() {}
	Font(Nu) {}
	Font(Font &f) : Super(f) {}
	Font(Font &&f) : Super(f) {}
public:
	Font(const LogicA &LogFont) : Font(Create(LogFont)) {}
	Font(const LogicW &LogFont) : Font(Create(LogFont)) {}
public:
	static inline Font Create(const LogicA &LogFont) ret_as(WX::CreateFontIndirect(&LogFont));
	static inline Font Create(const LogicW &LogFont) ret_as(WX::CreateFontIndirect(&LogFont));
public:
	using Super::operator=;
};
using CFont = ProxyView<Font>;
#pragma endregion

#pragma region Pen
enum_flags(PenStyles    , int            ,
		   Solid        = PS_SOLID       ,
		   Dash         = PS_DASH        ,
		   Dot          = PS_DOT         ,
		   DashDot      = PS_DASHDOT     ,
		   DashDotDot   = PS_DASHDOTDOT  ,
		   Null         = PS_NULL        ,
		   InsideFrame  = PS_INSIDEFRAME ,
		   UserStyle    = PS_USERSTYLE   ,
		   Alternate    = PS_ALTERNATE   );
class PenLogic : public StructShim<LOGPEN> {
public:
	using Super = StructShim<LOGPEN>;
public:
	PenLogic() {}
public: // Property - Style
	proxy_prop_set(Style,lopnStyle,PenStyles);
	/* R */ inline PenStyles Style() const ret_as(reuse_cast<PenStyles>(self->lopnStyle));
public: // Property - Width
proxy_prop_set(Width, POINT, lopnWidth);
	/* R */ inline LPoint Width() const ret_as(reuse_cast<POINT>(self->lopnWidth));
public: // Property - Style
proxy_prop_set(Color, COLORREF, lopnColor);
	/* R */ inline COLORREF Color() const ret_as(reuse_cast<RGBColor>(self->lopnColor));
};
class BaseOf_GDI(Pen, HPEN) {
public:
	using Super = GObjectBase<Pen, HPEN>;
	using Styles = PenStyles;
	using Log = PenLogic;
protected:
	friend_to_proxy(Pen);
	Pen(HPEN h) : Super(h) {}
	Pen(const Pen &p) : Super(p) {}
public:
	Pen() {}
	Pen(Nu) {}
	Pen(Pen &p) : Super(p) {}
	Pen(Pen &&p) : Super(p) {}
	Pen(const PenLogic &log) : Super(Create(log)) {}
public:
	static inline Pen Create(const PenLogic &log) ret_as(WX::CreatePenIndirect(&log));
	static inline Pen Create(Styles styles, COLORREF rgb, int nWidth = 0) ret_as(WX::CreatePen(styles.yield(), nWidth, rgb));
	static inline Pen CreateSolid(COLORREF rgb, int nWidth = 0)       ret_as(WX::CreatePen(PS_SOLID, nWidth, rgb));
	static inline Pen CreateDash(COLORREF rgb, int nWidth = 0)        ret_as(WX::CreatePen(PS_DASH, nWidth, rgb));
	static inline Pen CreateDot(COLORREF rgb, int nWidth = 0)         ret_as(WX::CreatePen(PS_DOT, nWidth, rgb));
	static inline Pen CreateDashDot(COLORREF rgb, int nWidth = 0)     ret_as(WX::CreatePen(PS_DASHDOT, nWidth, rgb));
	static inline Pen CreateDashDotDot(COLORREF rgb, int nWidth = 0)  ret_as(WX::CreatePen(PS_DASHDOTDOT, nWidth, rgb));
	static inline Pen CreateNull(COLORREF rgb, int nWidth = 0)        ret_as(WX::CreatePen(PS_NULL, nWidth, rgb));
	static inline Pen CreateInsideFrame(COLORREF rgb, int nWidth = 0) ret_as(WX::CreatePen(PS_INSIDEFRAME, nWidth, rgb));
	static inline Pen CreateUserStyle(COLORREF rgb, int nWidth = 0)   ret_as(WX::CreatePen(PS_USERSTYLE, nWidth, rgb));
	static inline Pen CreateAlternate(COLORREF rgb, int nWidth = 0)   ret_as(WX::CreatePen(PS_ALTERNATE, nWidth, rgb));
public:
	static inline Pen White() ret_as((HPEN)WX::GetStockObject(WHITE_PEN));
	static inline Pen Black() ret_as((HPEN)WX::GetStockObject(BLACK_PEN));
	static inline Pen Nu()  ret_as((HPEN)WX::GetStockObject(NULL_PEN));
	static inline Pen DC()    ret_as((HPEN)WX::GetStockObject(DC_PEN));
public: // Property - Log
	/* R */
public:
	using Super::operator=;
};
using CPen = ProxyView<Pen>;
#pragma endregion

#pragma region Brush
enum_class(SysColor                 , IntP                          ,
		   ScrollBar                = COLOR_SCROLLBAR               ,
		   Background               = COLOR_BACKGROUND              ,
		   ActiveCaption            = COLOR_ACTIVECAPTION           ,
		   InactiveCaption          = COLOR_INACTIVECAPTION         ,
		   Menu                     = COLOR_MENU                    ,
		   Window                   = COLOR_WINDOW                  ,
		   WindowFrame              = COLOR_WINDOWFRAME             ,
		   MenuText                 = COLOR_MENUTEXT                ,
		   WindowText               = COLOR_WINDOWTEXT              ,
		   CaptionText              = COLOR_CAPTIONTEXT             ,
		   ActiveBorder             = COLOR_ACTIVEBORDER            ,
		   InactiveBorder           = COLOR_INACTIVEBORDER          ,
		   AppWorkspace             = COLOR_APPWORKSPACE            ,
		   HighLight                = COLOR_HIGHLIGHT               ,
		   HighLightText            = COLOR_HIGHLIGHTTEXT           ,
		   BtnFace                  = COLOR_BTNFACE                 ,
		   BtnShadow                = COLOR_BTNSHADOW               ,
		   GrayText                 = COLOR_GRAYTEXT                ,
		   BtnText                  = COLOR_BTNTEXT                 ,
		   InactiveCaptionText      = COLOR_INACTIVECAPTIONTEXT     ,
		   BtnHighlight             = COLOR_BTNHIGHLIGHT            ,
		   DkShadow3D               = COLOR_3DDKSHADOW              ,
		   Light3D                  = COLOR_3DLIGHT                 ,
		   InfoText                 = COLOR_INFOTEXT                ,
		   InfoBk                   = COLOR_INFOBK                  ,
		   HotLight                 = COLOR_HOTLIGHT                ,
		   GradientActiveCaption    = COLOR_GRADIENTACTIVECAPTION   ,
		   GradientInactiveCaption  = COLOR_GRADIENTINACTIVECAPTION ,
		   MenuHiLight              = COLOR_MENUHILIGHT             ,
		   MenuBar                  = COLOR_MENUBAR                 );
enum_class(HatchStyles , int           ,
		   Horizontal  = HS_HORIZONTAL ,   /* ----- */
		   Vertical    = HS_VERTICAL   ,   /* ||||| */
		   FDiagonal   = HS_FDIAGONAL  ,   /* \\\\\ */
		   BDiagonal   = HS_BDIAGONAL  ,   /* ///// */
		   Cross       = HS_CROSS      ,   /* +++++ */
		   DiagCross   = HS_DIAGCROSS  );  /* xxxxx */
class BaseOf_GDI(Brush, HBRUSH) {
public:
	using Super = GObjectBase<Brush, HBRUSH>;
protected:
	friend_to_proxy(Brush);
	Brush(HBRUSH h) : Super(h) {}
	Brush(const Brush &b) : Super(b) {}
public:
	Brush() {}
	Brush(Nu) {}
	Brush(Brush &b) : Super(b) {}
	Brush(Brush &&b) : Super(b) {}
	Brush(WX::SysColor sc) : Super(SysColor(sc)) {}
	Brush(COLORREF rgb) : Super(CreateSolid(rgb)) {}
	Brush(HBITMAP hbm) : Super(CreatePattern(hbm)) {}
	Brush(HatchStyles hs, COLORREF rgb) : Super(CreateHatch(rgb, hs)) {}
public:
	static inline Brush CreateSolid(COLORREF rgb)                ret_as(WX::CreateSolidBrush(rgb));
	static inline Brush CreatePattern(HBITMAP hbm)               ret_as(WX::CreatePatternBrush(hbm));
	static inline Brush CreateHatch(COLORREF rgb, HatchStyles hs) ret_as(WX::CreateHatchBrush(hs.yield(), rgb));
public:
	static inline Brush White()   ret_as((HBRUSH)WX::GetStockObject(WHITE_BRUSH));
	static inline Brush LitGray() ret_as((HBRUSH)WX::GetStockObject(LTGRAY_BRUSH));
	static inline Brush Gray()    ret_as((HBRUSH)WX::GetStockObject(GRAY_BRUSH));
	static inline Brush DkGray()  ret_as((HBRUSH)WX::GetStockObject(DKGRAY_BRUSH));
	static inline Brush Black()   ret_as((HBRUSH)WX::GetStockObject(BLACK_BRUSH));
	static inline Brush Nu()    ret_as((HBRUSH)WX::GetStockObject(NULL_BRUSH));
	static inline Brush DC()      ret_as((HBRUSH)WX::GetStockObject(DC_BRUSH));
public:
	static inline Brush SysColor(WX::SysColor sc) ret_as(WX::GetSysColorBrush((int)sc.yield()));
public:
	using Super::operator=;
};
using CBrush = ProxyView<Brush>;
#pragma endregion

#pragma region Palette
class PaletteEntry : public StructShim<PALETTEENTRY> {
public:
	using Super = StructShim<PALETTEENTRY>;
public:
	PaletteEntry() {}
	PaletteEntry(const PALETTEENTRY &entry) : Super(entry) {}
	PaletteEntry(BYTE r, BYTE g, BYTE b, BYTE f = 0) : Super(PALETTEENTRY{ r, g, b, f }) {}
	PaletteEntry(RGBColor rgb, BYTE f = 0) : PaletteEntry(rgb.Red(), rgb.Green(), rgb.Blue(), f) {}
	PaletteEntry(COLORREF rgb, BYTE f = 0) : PaletteEntry((RGBColor)rgb, f) {}
	proxy_prop_sync(Red,peRed,BYTE);
	proxy_prop_sync(Green,peGreen,BYTE);
	proxy_prop_sync(Blue,peBlue,BYTE);
public:
	inline operator RGBColor() const ret_as({ Red(), Green(), Blue() });
};
using PalEntry = PaletteEntry;
class BaseOf_GDI(Palette, HPALETTE) { //////////////
public:
	using Super = GObjectBase<Palette, HPALETTE>;
	using Entry = PaletteEntry;
protected:
	friend_to_proxy(Palette);
	Palette(HPALETTE h) : Super(h) {}
	Palette(const Palette &p) : Super(p) {}
public:
	Palette() {}
	Palette(Nu) {}
	Palette(Palette &p) : Super(p) {}
	Palette(Palette &&p) : Super(p) {}
public:
	Palette(const Entry *lpEntries, UINT nCount) {
		nt_assert(1 < nCount && nCount <= 256);
		HeapPointer<LOGPALETTE> hPal;
		hPal.Alloc(sizeof(LOGPALETTE) + (nCount - 1) * sizeof(Entry));
		auto pPal = &hPal;
		pPal->palVersion = 0x300;
		pPal->palNumEntries = (WORD)nCount;
		CopyMemory(&pPal->palPalEntry, lpEntries, sizeof(Entry) * nCount);
		this->hobj = WX::CreatePalette(pPal);
	}
	Palette(std::initializer_list<COLORREF> entries) : Palette((const Entry *)entries.begin(), (UINT)entries.size()) {}
	Palette(std::initializer_list<Entry> entries) : Palette(entries.begin(), (UINT)entries.size()) {}
	Palette(const std::vector<Entry> &entries) : Palette(entries.data(), (UINT)entries.size()) {}
public:
//	static inline Palette Create() ret_as();
	static inline Palette Default() ret_as((HPALETTE)WX::GetStockObject(DEFAULT_PALETTE));
public:
	inline auto &SetEntries(UINT iStart, const Entry *pPalEntries, UINT cEntries = 1) ret_to_self(WX::SetPaletteEntries(self, iStart, cEntries, (const PALETTEENTRY *)pPalEntries));
	inline auto &GetEntries(UINT iStart, Entry *pPalEntries, UINT cEntries = 1) const ret_to_self(WX::GetPaletteEntries(self, iStart, cEntries, (LPPALETTEENTRY)pPalEntries));
	inline UINT NearestIndex(COLORREF cr) const ret_as(WX::GetNearestPaletteIndex(self, cr));
#pragma region Properties
public: // Property - Entries
	/* W */ inline auto &Entries(std::vector<Entry> entries) {
		auto count = std::min((SizeT)Count(), entries.size());
		nt_assert(count <= 256);
		if (count > 0)
			SetEntries(0, entries.data(), (WORD)(count - 1));
		retself;
	}
	/* R */ inline std::vector<Entry> Entries() const {
		SizeT count = Count();
		std::vector<Entry> entries(count);
		if (count > 0)
			GetEntries(0, entries.data(), (WORD)count);
		return entries;
	}
public: // Property - NumEntries
	/* W */ inline auto &Count(WORD nNumEntries) ret_to_self(WX::ResizePalette(self, nNumEntries));
	/* R */ inline WORD  Count() const ret_to(WORD w = 0, WX::GetObject(self, sizeof(WORD), &w), w);
public: // Property - Size
	/* R */ inline SizeT Size() const ret_as(Count() * sizeof(Entry));
#pragma endregion
public:
	using Super::operator=;
	inline Entry operator[](SizeT ind) const ret_to(Entry entry; GetEntries((UINT)ind, (Entry *)&entry), entry);
};
using CPalette = ProxyView<Palette>;
#pragma endregion

#pragma region Region
enum_class(PolyFillModes , int         ,
		   Default       = 0           ,
		   Alternate     = ALTERNATE   ,
		   Winding       = WINDING     );
enum_class(BkModes       , int         ,
		   Default       = 0           ,
		   Transparent   = TRANSPARENT ,
		   Opaque        = OPAQUE      );
class BaseOf_GDI(Region, HRGN) {
public:
	using Super = GObjectBase<Region, HRGN>;
protected:
	friend_to_proxy(Region);
	Region(HRGN h) : Super(h) {}
	Region(const Region &r) : Super(r) {}
public:
	Region() {}
	Region(Nu) {}
	Region(Region &r) : Super(r) {}
	Region(Region &&r) : Super(r) {}
public:
//	static inline void Combine() { CombineRgn() }
public:
	static inline Region CreateRect(LRect rc) ret_as(WX::CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom));
	static inline Region CreateElliptic(LRect rc) ret_as(WX::CreateEllipticRgn(rc.left, rc.top, rc.right, rc.bottom));
	static inline Region CreateRound(LRect rc, LSize sz) ret_as(WX::CreateRoundRectRgn(rc.left, rc.top, rc.right, rc.bottom, sz.cx, sz.cy));
	static inline Region CreatePolygon(const POINT *ppt1, int cPoint, PolyFillModes mode = PolyFillModes::Winding) ret_as(WX::CreatePolygonRgn(ppt1, cPoint, mode.yield()));
	static inline Region CreatePolyPolygon(const POINT *ppt1, int cPoint, PolyFillModes mode = PolyFillModes::Winding) ret_as(WX::CreatePolygonRgn(ppt1, cPoint, mode.yield()));
public:
	inline bool Equal(HRGN hRgn) ret_as(WX::EqualRgn(self, hRgn));
	inline bool Has(LPoint pt) ret_as(WX::PtInRegion(self, pt.x, pt.y));
	inline bool Has(LRect rc) ret_as(WX::RectInRegion(self, &rc));
public:
	inline void And(HRGN hRgn) { WX::CombineRgn(self, self, hRgn, RGN_AND); }
	inline void And(HRGN hRgn1, HRGN hRgn2) { WX::CombineRgn(self, hRgn1, hRgn2, RGN_AND); }
	inline void Or(HRGN hRgn) { WX::CombineRgn(self, self, hRgn, RGN_OR); }
	inline void Or(HRGN hRgn1, HRGN hRgn2) { WX::CombineRgn(self, hRgn1, hRgn2, RGN_OR); }
	inline void Xor(HRGN hRgn) { WX::CombineRgn(self, self, hRgn, RGN_XOR); }
	inline void Xor(HRGN hRgn1, HRGN hRgn2) { WX::CombineRgn(self, hRgn1, hRgn2, RGN_XOR); }
	inline void Diff(HRGN hRgn) { WX::CombineRgn(self, self, hRgn, RGN_DIFF); }
	inline void Diff(HRGN hRgn1, HRGN hRgn2) { WX::CombineRgn(self, hRgn1, hRgn2, RGN_DIFF); }
	inline void Offset(LPoint off) { WX::OffsetRgn(self, off.x, off.y); }
public:
	inline auto &operator&(HRGN hRgn) ret_to_self(And(hRgn));
	inline auto &operator|(HRGN hRgn) ret_to_self(Or(hRgn));
	inline auto &operator^(HRGN hRgn) ret_to_self(Xor(hRgn));
	inline auto &operator-(HRGN hRgn) ret_to_self(Diff(hRgn));
};
using CRegion = ProxyView<Region>;
#pragma endregion

#pragma region MetaFile
class BaseOf_GDI(MetaFile, HMETAFILE) {
public:
	using Super = GObjectBase<MetaFile, HMETAFILE>;
protected:
	friend_to_proxy(Region);
	MetaFile(HMETAFILE h) : Super(h) {}
	MetaFile(const MetaFile &m) : Super(m) {}
public:
	MetaFile() {}
	MetaFile(Nu) {}
	MetaFile(MetaFile &m) : Super(m) {}
	MetaFile(MetaFile &&m) : Super(m) {}
	~MetaFile() ret_to(Delete());
public:

public:
	inline void Delete() {
		if (self)
			WX::DeleteMetaFile(self);
		this->hobj = O;
	}
};
using CMetaFile = ProxyView<MetaFile>;
#pragma endregion

#pragma region DevCap

#pragma region ColorSpace
enum_class(MapModes       , int            ,
		   Text           = MM_TEXT        ,
		   LoMetric       = MM_LOMETRIC    ,
		   HiMetric       = MM_HIMETRIC    ,
		   LoEnglish      = MM_LOENGLISH   ,
		   HiEnglish      = MM_HIENGLISH   ,
		   Twips          = MM_TWIPS       ,
		   Isotropic      = MM_ISOTROPIC   ,
		   Anisotropic    = MM_ANISOTROPIC );
enum_flags(Rop            , DWORD          ,
		   SrcCopy        = SRCCOPY        ,  /* dest = source                   */
		   SrcPaint       = SRCPAINT       ,  /* dest = source OR dest           */
		   SrcAnd         = SRCAND         ,  /* dest = source AND dest          */
		   SrcInvert      = SRCINVERT      ,  /* dest = source XOR dest          */
		   SrcErase       = SRCERASE       ,  /* dest = source AND (NOT dest )   */
		   SrcCopyNot     = NOTSRCCOPY     ,  /* dest = (NOT source)             */
		   SrcEraseNot    = NOTSRCERASE    ,  /* dest = (NOT src) AND (NOT dest) */
		   MergeCopy      = MERGECOPY      ,  /* dest = (source AND pattern)     */
		   MergePaint     = MERGEPAINT     ,  /* dest = (NOT source) OR dest     */
		   PatCopy        = PATCOPY        ,  /* dest = pattern                  */
		   PatPaint       = PATPAINT       ,  /* dest = DPSnoo                   */
		   PatInvert      = PATINVERT      ,  /* dest = pattern XOR dest         */
		   DstInvert      = DSTINVERT      ,  /* dest = (NOT dest)               */
		   Blackness      = BLACKNESS      ,  /* dest = BLACK                    */
		   Whiteness      = WHITENESS      ,  /* dest = WHITE                    */
		   NoMirrorBitmap = NOMIRRORBITMAP ,  /* Do not Mirror the bitmap in this call */
		   CaptureBlt     = CAPTUREBLT     ); /* Include layered windows              */
enum_flags(Rop2           , int            ,
		   Black          = R2_BLACK       ,
		   NotMergePen    = R2_NOTMERGEPEN ,
		   MaskNotPen     = R2_MASKNOTPEN  ,
		   NotCopyPen     = R2_NOTCOPYPEN  ,
		   MaskPenNot     = R2_MASKPENNOT  ,
		   Not            = R2_NOT         ,
		   XorPen         = R2_XORPEN      ,
		   NotMaskPen     = R2_NOTMASKPEN  ,
		   MaskPen        = R2_MASKPEN     ,
		   NotXorPen      = R2_NOTXORPEN   ,
		   Nop            = R2_NOP         ,
		   MergeNotPen    = R2_MERGENOTPEN ,
		   CopyPen        = R2_COPYPEN     ,
		   MergePenNot    = R2_MERGEPENNOT ,
		   MergePen       = R2_MERGEPEN    ,
		   White          = R2_WHITE       );
enum_class(StretcheModes  , int            ,
		   And            = BLACKONWHITE   ,
		   Or             = WHITEONBLACK   ,
		   Del            = COLORONCOLOR   ,
		   Half           = HALFTONE       );
enum_flags(TextAlign      , UINT           , 
		   NoUpDateCP     = TA_NOUPDATECP  ,
		   UpDateCP       = TA_UPDATECP    ,
		   Left           = TA_LEFT        ,
		   Right          = TA_RIGHT       ,
		   Center         = TA_CENTER      ,
		   Top            = TA_TOP         ,
		   Bottom         = TA_BOTTOM      ,
		   Baseline       = TA_BASELINE    ,
		   RTLReading     = TA_RTLREADING  );
enum_flags(Illuminants    , WORD                      ,
		   Default        = ILLUMINANT_DEVICE_DEFAULT ,
		   A              = ILLUMINANT_A              ,
		   B              = ILLUMINANT_B              ,
		   C              = ILLUMINANT_C              ,
		   D50            = ILLUMINANT_D50            ,
		   D55            = ILLUMINANT_D55            ,
		   D65            = ILLUMINANT_D65            ,
		   D75            = ILLUMINANT_D75            ,
		   F2             = ILLUMINANT_F2             ,
		   Tungsten       = ILLUMINANT_TUNGSTEN       ,
		   DayLight       = ILLUMINANT_DAYLIGHT       ,
		   Fluorescent    = ILLUMINANT_FLUORESCENT    ,
		   NTSC           = ILLUMINANT_NTSC           );
proxy_struct       (ColorAdjustment , COLORADJUSTMENT                  ) {
	ColorAdjustment() ret_to(self->caSize = sizeof(COLORADJUSTMENT));
	proxy_prop_sync(Illuminant      , caIlluminantIndex  , Illuminants );
	proxy_prop_sync(RedGamma        , caRedGamma         , WORD        );
	proxy_prop_sync(GreenGamma      , caGreenGamma       , WORD        );
	proxy_prop_sync(BlueGamma       , caBlueGamma        , WORD        );
	proxy_prop_sync(ReferenceBlack  , caReferenceBlack   , WORD        );
	proxy_prop_sync(ReferenceWhite  , caReferenceWhite   , WORD        );
	proxy_prop_sync(Contrast        , caContrast         , SHORT       );
	proxy_prop_sync(Brightness      , caBrightness       , SHORT       );
	proxy_prop_sync(Colorfulness    , caColorfulness     , SHORT       );
	proxy_prop_sync(RedGreenTint    , caRedGreenTint     , SHORT       );};
class RGBIndex : public StructShim<CIEXYZ> {
public:
	using Super = StructShim<CIEXYZ>;
public:
	RGBIndex() {}
	RGBIndex(const CIEXYZ &xyz) : Super(xyz) {}
	RGBIndex(FXPT2DOT30 ciexyzX, FXPT2DOT30 ciexyzY, FXPT2DOT30 ciexyzZ) : 
		Super(CIEXYZ{ ciexyzX, ciexyzY, ciexyzZ }) {}
	proxy_prop(X,ciexyzX,FXPT2DOT30,auto);
	proxy_prop(Y,ciexyzY,FXPT2DOT30,auto);
	proxy_prop(Z,ciexyzZ,FXPT2DOT30,auto);
};
class RGBTriple : public StructShim<CIEXYZTRIPLE> {
public:
	using Super = StructShim<CIEXYZTRIPLE>;
public:
	RGBTriple() {}
	RGBTriple(const CIEXYZTRIPLE &xyzTriple) : Super(xyzTriple) {}
	RGBTriple(CIEXYZ ciexyzR, CIEXYZ ciexyzG, CIEXYZ ciexyzB) : Super(CIEXYZTRIPLE{ ciexyzR, ciexyzG, ciexyzB }) {}
public: // Property - Red
	/* W */ inline auto&Red(RGBIndex ciexyzRed) ret_to_self(self->ciexyzRed = *ciexyzRed);
	proxy_prop_get(Red,ciexyzRed,RGBIndex);
public: // Property - Green
	/* W */ inline auto&Green(RGBIndex ciexyzGreen) ret_to_self(self->ciexyzGreen = *ciexyzGreen);
	proxy_prop_get(Green,ciexyzGreen,RGBIndex);
public: // Property - Blue
	/* W */ inline auto&Blue(RGBIndex ciexyzBlue) ret_to_self(self->ciexyzBlue = *ciexyzBlue);
	proxy_prop_get(Blue,ciexyzBlue,RGBIndex);
};
enum_flags(ColorType, LCSCSTYPE,
	CalibratedRGB     = LCS_CALIBRATED_RGB,
	sRGB              = LCS_sRGB,
	Default           = LCS_WINDOWS_COLOR_SPACE);
enum_flags(ColorIntents, DWORD,
	Perceptual        = LCS_GM_BUSINESS,
	Relative          = LCS_GM_GRAPHICS,
	Saturation        = LCS_GM_IMAGES,
	Absolute          = LCS_GM_ABS_COLORIMETRIC);
template<bool IsUnicode>
class ColorSpaceX : public StructShim<std::conditional_t<IsUnicode, LOGCOLORSPACEW, LOGCOLORSPACEA>> {
public:
	using LOGCOLORSPACE = std::conditional_t<IsUnicode, LOGCOLORSPACEW, LOGCOLORSPACEA>;
	using Super = StructShim<LOGCOLORSPACE>;
	using String = StringX<IsUnicode>;
public:
	ColorSpaceX() ret_to(self->lcsSize = sizeof(LOGCOLORSPACE);
							 self->lcsSignature = LCS_SIGNATURE;
							 self->lcsVersion = 0x400);
	ColorSpaceX(const LOGCOLORSPACE &cs) : Super(cs) {}
proxy_prop_sync(Type,lcsCSType,ColorType);
proxy_prop_sync(Intent,lcsIntent,ColorIntents);
public: // Property - Endpoints
	/* W */ inline auto&Endpoints(RGBTriple lcsEndpoints) ret_to_self(self->lcsEndpoints = *lcsEndpoints);
	proxy_prop_get(Endpoints,lcsEndpoints,RGBTriple);
public: // Property - GammaRed
	/* W */ inline auto&GammaRed(RGBIndex lcsGammaRed) ret_to_self(self->lcsGammaRed = *lcsGammaRed);
	proxy_prop_get(GammaRed,lcsGammaRed,RGBIndex);
public: // Property - GammaGreen
	/* W */ inline auto&GammaGreen(RGBIndex lcsGammaGreen) ret_to_self(self->lcsGammaGreen = *lcsGammaGreen);
	proxy_prop_get(GammaGreen,lcsGammaGreen,RGBIndex);
public: // Property - GammaBlue
	/* W */ inline auto &GammaBlue(RGBIndex lcsGammaBlue) ret_to_self(self->lcsGammaBlue = *lcsGammaBlue);
	proxy_prop_get(GammaBlue,lcsGammaBlue,RGBIndex);
public: // Property - Filename
	/* W */ inline auto &Filename(const String &strFilename) ret_to_self(strFilename.CopyTo(self->lcsFilename, MAX_PATH));
	/* R */ inline const String Filename() const ret_to(CString(MAX_PATH, self->lcsFilename));
};
using ColorSpace = ColorSpaceX<IsUnicode>;
using ColorSpaceA = ColorSpaceX<false>;
using ColorSpaceW = ColorSpaceX<true>;
#pragma endregion

class XForm : public StructShim<XFORM> {
public:
	using Super = StructShim<XFORM>;
public:
	XForm() {}
	XForm(const XFORM &xf) : Super(xf) {}
	XForm(FLOAT eM11, FLOAT eM12, FLOAT eM21, FLOAT eM22, FLOAT eDx = 0, FLOAT eDy = 0) :
		Super(XFORM{ eM11, eM12, eM21, eM22, eDx, eDy }) {}
	proxy_prop(M11,eM11,FLOAT,auto);
	proxy_prop(M12,eM12,FLOAT,auto);
	proxy_prop(M21,eM21,FLOAT,auto);
	proxy_prop(M22,eM22,FLOAT,auto);
	proxy_prop(Dx,eDx,FLOAT,auto);
	proxy_prop(Dy,eDy,FLOAT,auto);
//public: // Property - Offset
//	/* W */ inline auto&Offset(LPoint off) ret_to_self(self->eDx = off.x, self->eDy = off.y);
//	/* R */ inline auto Offset() const ret_as(LPoint{ self->eDx, self->eDy });
public:
	class IFloat {
		friend class XForm;
		FLOAT &f;
	private:
		IFloat(const IFloat &) = delete;
		IFloat(FLOAT &f) : f(f) {}
	public:
		IFloat(IFloat &&) = default;
	public:
		inline operator FLOAT&() const ret_as(f);
		inline operator FLOAT() const ret_as(f);
	};
	inline IFloat operator[](LPoint pt) {
		if (pt.x == 0 && pt.y == 0) return self->eM11;
		if (pt.x == 1 && pt.y == 0) return self->eM12;
		if (pt.x == 0 && pt.y == 1) return self->eM21;
		if (pt.x == 1 && pt.y == 1) return self->eM22;
		nt_assert(false);
	}
	inline FLOAT operator[](LPoint pt) const {
		if (pt.x == 0 && pt.y == 0) return self->eM11;
		if (pt.x == 1 && pt.y == 0) return self->eM12;
		if (pt.x == 0 && pt.y == 1) return self->eM21;
		if (pt.x == 1 && pt.y == 1) return self->eM22;
		nt_assert(false);
	}
};

#if(WINVER >= 0x0400)
#define DRAWTEXT_1 \
	, EditControl          = DT_EDITCONTROL   \
	, PathEllipsis         = DT_PATH_ELLIPSIS \
	, EndEllipsis          = DT_END_ELLIPSIS  \
	, ModifyString         = DT_MODIFYSTRING  \
	, RTLReading           = DT_RTLREADING    \
	, WordEllipsis         = DT_WORD_ELLIPSIS
#if(WINVER >= 0x0500)
#define DRAWTEXT_2 \
	, NoFullWidthCharBreak = DT_NOFULLWIDTHCHARBREAK
#if(_WIN32_WINNT >= 0x0500)
#define DRAWTEXT_3 \
	, HidePrefix           = DT_HIDEPREFIX \
	, PrefixOnly           = DT_PREFIXONLY
#endif
#endif
#endif

enum_flags(TextDraw, UINT,
	  Top               = DT_TOP
	, Left              = DT_LEFT
	, Center            = DT_CENTER
	, Right             = DT_RIGHT
	, VCenter           = DT_VCENTER
	, Bottom            = DT_BOTTOM
	, WordBreak         = DT_WORDBREAK
	, SingleLine        = DT_SINGLELINE
	, ExpandTabs        = DT_EXPANDTABS
	, TabStop           = DT_TABSTOP
	, NoClip            = DT_NOCLIP
	, ExternalLeading   = DT_EXTERNALLEADING
	, CalcRect          = DT_CALCRECT
	, NoPrefix          = DT_NOPREFIX
	, Internal          = DT_INTERNAL
	DRAWTEXT_1
	DRAWTEXT_2
	DRAWTEXT_3);

class BaseOf_GDI(DevCap, HDC) {
public:
	using Super = GObjectBase<DevCap, HDC>;
protected:
	friend_to_proxy(DevCap);
	DevCap(HDC h) : Super(h) {}
	DevCap(const DevCap &d) : Super(d) {}
public:
	DevCap() {}
	DevCap(Nu) {}
	DevCap(DevCap &d) : Super(d) {}
	DevCap(DevCap &&d) : Super(d) {}
	~DevCap() ret_to(Delete());
public:
	static inline DevCap CreateCompatible(HDC hdc = O) ret_as(WX::CreateCompatibleDC(hdc));
public:
	//inline void Delete() {
	//	if (self)
	//		nt_assert(DeleteDC(self));
	//	this->hobj = O;
	//}
	inline auto Release(HWND hWnd) ret_as(WX::ReleaseDC(hWnd, self));

	inline CGObject Select(HGDIOBJ ho) ret_as(::SelectObject(self, ho));
	inline CPalette Palette(HPALETTE hPal, bool bForceBkgd = false) ret_to(hPal = WX::SelectPalette(self, hPal, bForceBkgd), hPal);
	inline UINT PaletteRealize() const ret_as(WX::RealizePalette(self));

//	inline auto &BltStretch(LPoint dstStart, LSize dstSize, Rop rop = Rop::SrcCopy)
	inline auto &BltStretch(LPoint dstStart, LSize dstSize, HDC hdcSrc, LPoint srcStart, LSize srcSize, Rop rop = Rop::SrcCopy) ret_to_self(WX::StretchBlt(self, dstStart.x, dstStart.y, dstSize.cx, dstSize.cy, hdcSrc, srcStart.x, srcStart.y, srcSize.cx, srcSize.cy, rop.yield()));
	inline auto &BltStretch(LRect dst, HDC hdcSrc, LRect src, Rop rop = Rop::SrcCopy) ret_to_self(BltStretch(dst.left_top(), dst.size(), hdcSrc, src.left_top(), src.size(), rop));
	inline auto &BltBit(LPoint dstStart, LSize dstSize, HDC hdcSrc, LPoint srcStart = 0, Rop rop = Rop::SrcCopy) ret_to_self(WX::BitBlt(self, dstStart.x, dstStart.y, dstSize.cx, dstSize.cy, hdcSrc, srcStart.x, srcStart.y, rop.yield()));
	inline auto &BltBit(LRect rc, HDC hdcSrc, LPoint srcStart = 0, Rop rop = Rop::SrcCopy) ret_to_self(BltBit(rc.left_top(), rc.size(), hdcSrc, srcStart, rop));

	template<SizeT len>
	inline auto &DrawPolyline(const POINT(&pts)[len]) ret_to_self(WX::Polyline(self, &pts, len));
	template<SizeT len>
	inline auto &DrawPolyline(const LPoint(&pts)[len]) ret_to_self(WX::Polyline(self, (CONST POINT *)&pts, len));
	inline auto &DrawPolyline(const LPoint *pts, int len) ret_to_self(WX::Polyline(self, (CONST POINT *)pts, len));
	inline auto &DrawPolyline(const POINT *pts, int len) ret_to_self(WX::Polyline(self, pts, len));
	inline auto &DrawIcon(HICON hIcon, LPoint p = 0) ret_to_self(WX::DrawIcon(self, p.x, p.y, hIcon));
	inline int  DrawText(String text, LRect r = 0, TextDraw format = TextDraw::Left) ret_as(WX::DrawText(self, text, (int)text.Length(), r, format.yield()));
	inline auto &DrawPixel(COLORREF rgb, LPoint p) ret_to_self(WX::SetPixel(self, p.x, p.y, rgb));
	inline auto &DrawPie(LRect rc, LPoint start, LPoint end) ret_to_self(WX::Pie(self, rc.left, rc.top, rc.right, rc.bottom, start.x, start.y, end.x, end.y));
	inline auto &DrawEllipse(LRect rc) ret_to_self(Ellipse(self, rc.left, rc.top, rc.right, rc.bottom));
	inline auto &DrawFrame(LRect rc) ret_to_self(WX::InvertRect(self, rc));
	inline auto &DrawFocus(HBRUSH hbr, LRect rc) ret_to_self(WX::FrameRect(self, &rc, hbr));
	inline auto &Invert(LRect rc) ret_to_self(WX::InvertRect(self, rc));
	inline auto &Fill(HBRUSH hbr, LRect rc) ret_to_self(WX::FillRect(self, rc, hbr));
	inline auto &Fill(HBRUSH hbr) ret_as(Fill(hbr, Size()));
public:
	class IPixel {
		friend class DevCap;
		HDC hdc;
		POINT pt;
	private:
		IPixel(const IPixel &) = delete;
		IPixel(HDC hdc, POINT pt) : hdc(hdc), pt(pt) {}
	public:
		IPixel(IPixel &&) = default;
	public:
		inline operator RGBColor() const ret_as(WX::GetPixel(hdc, pt.x, pt.y));
		inline operator COLORREF() const ret_as(WX::GetPixel(hdc, pt.x, pt.y));
		inline void operator=(COLORREF clr) ret_to(WX::SetPixel(hdc, pt.x, pt.y, clr));
	};
	inline IPixel Pixel(LPoint pt) ret_as({ self, pt });
	inline const IPixel Pixel(LPoint pt) const ret_as({ self, pt });

#pragma region Properties
public: // Property - BkColor
	/* W */ inline auto&BkColor(COLORREF rgb) ret_to_self(WX::SetBkColor(self, rgb));
	/* R */ inline auto BkColor() const ret_as((RGBColor)WX::GetBkColor(self));
public: // Property - PenColor
	/* W */ inline auto&PenColor(COLORREF rgb) ret_to_self(WX::SetDCPenColor(self, rgb));
	/* R */ inline auto PenColor() const ret_as((RGBColor)WX::GetDCPenColor(self));
public: // Property - TextColor
	/* W */ inline auto&TextColor(COLORREF color) ret_to_self(SetTextColor(self, color));
	/* R */ inline auto TextColor() const ret_as((RGBColor)WX::GetTextColor(self));
public: // Property - BrushColor
	/* W */ inline auto&BrushColor(COLORREF rgb) ret_to_self(WX::SetDCBrushColor(self, rgb));
	/* R */ inline auto BrushColor() const ret_as((RGBColor)WX::GetDCBrushColor(self));
public: // Property - BrushOrg
	/* W */ inline auto&BrushOrg(LPoint pt) ret_to_self(WX::SetBrushOrgEx(self, pt.x, pt.y, O));
	/* R */ inline auto BrushOrg() const ret_to(LPoint pt, WX::GetBrushOrgEx(self, &pt), pt);
public: // Property - BkMode
public: // Property - ViewOrg
	/* W */ inline auto&ViewOrg(LPoint pt) ret_to_self(WX::SetViewportOrgEx(self, pt.x, pt.y, O));
	/* R */ inline auto ViewOrg() const ret_to(LPoint pt, WX::GetViewportOrgEx(self, &pt), pt);
public: // Property - ViewExt
	/* W */ inline auto&ViewExt(LSize sz) ret_to_self(WX::SetViewportExtEx(self, sz.cx, sz.cy, O));
	/* R */ inline auto ViewExt() const ret_to(LSize sz, WX::GetViewportExtEx(self, &sz), sz);
public: // Property - WindowOrg
	/* W */ inline auto&WindowOrg(LPoint pt) ret_to_self(WX::SetWindowOrgEx(self, pt.x, pt.y, O));
	/* R */ inline auto WindowOrg() const ret_to(LPoint pt, WX::GetWindowOrgEx(self, &pt), pt);
public: // Property - WindowExt
	/* W */ inline auto&WindowExt(LSize sz) ret_to_self(WX::SetWindowExtEx(self, sz.cx, sz.cy, O));
	/* R */ inline auto WindowExt() const ret_to(LSize sz, WX::GetWindowExtEx(self, &sz), sz);
public: // Property - Size
	/* R */ inline LSize Size() const ret_as({ WX::GetDeviceCaps(self, HORZRES), WX::GetDeviceCaps(self, VERTRES) });
public: // Property - WorldTransform
	/* W */ inline auto&WorldTransform(const XForm &xf) ret_to_self(WX::SetWorldTransform(self, &xf));
	/* R */ inline auto WorldTransform() const ret_to(XForm xf; WX::GetWorldTransform(self, &xf), xf);
public: // Property - MapMode
	/* W */ inline auto&MapMode(MapModes mode) ret_to_self(WX::SetMapMode(self, mode.yield()));
	/* R */ inline auto MapMode() const ret_as(reuse_cast<MapModes>(WX::GetMapMode(self)));
public: // Property - TextAligns
	/* W */ inline auto&TextAligns(TextAlign align) ret_to_self(WX::SetTextAlign(self, align.yield()));
	/* R */ inline auto TextAligns() const ret_as(reuse_cast<TextAlign>(WX::GetTextAlign(self)));
public: // Property - StretchMode
	/* W */ inline auto&StretchMode(StretcheModes mode) ret_to_self(WX::SetStretchBltMode(self, mode.yield()));
	/* R */ inline auto StretchMode() const ret_as(reuse_cast<StretcheModes>(WX::GetStretchBltMode(self)));
public: // Property - PolyFillMode
	/* W */ inline auto&PolyFillMode(PolyFillModes mode) ret_to_self(WX::SetPolyFillMode(self, mode.yield()));
	/* W */ inline auto PolyFillMode() const ret_as(reuse_cast<PolyFillModes>(WX::GetPolyFillMode(self)));
public: // Property - Rop2
	/* W */ inline auto&Rop2(WX::Rop2 rop2) ret_to_self(WX::SetROP2(self, rop2.yield()));
	/* R */ inline auto Rop2() const ret_as(reuse_cast<WX::Rop2>(WX::GetROP2(self)));
public: // Property - MiterLimit
	/* W */ inline auto&MiterLimit(FLOAT limit) ret_to_self(WX::SetMiterLimit(self, limit, O));
	/* R */ inline auto MiterLimit() const ret_to(FLOAT f = 0, WX::GetMiterLimit(self, &f), f);
public: // Property - ColorAdjustment
	/* W */ inline auto&ColorAdjustment(const WX::ColorAdjustment &ca) ret_to_self(WX::SetColorAdjustment(self, &ca));
	/* R */ inline auto ColorAdjustment() const ret_to(WX::ColorAdjustment ca; WX::GetColorAdjustment(self, &ca), ca);
public: // Property - ICMProfile
	/* W */ inline auto &ICMProfile(const StringA &str) ret_to_self(WX::SetICMProfile(self, const_cast<LPSTR>(str.c_str())));
	/* W */ inline auto &ICMProfile(const StringW &str) ret_to_self(WX::SetICMProfile(self, const_cast<LPWSTR>(str.c_str())));
	template<bool IsUnicode = WX::IsUnicode>
	/* R */ inline StringX<IsUnicode> ICMProfile() const {
		DWORD len = 0;
		WX::GetICMProfile(self, &len, (LPXSTR<IsUnicode>)O);
		StringX<IsUnicode> str((SizeT)len);
		WX::GetICMProfile(self, O, str);
		return right_hand_cast(str);
	}
#pragma endregion
public:
	using Super::operator=;
	inline auto&operator()(HGDIOBJ ho) ret_to_self(Select(ho));
	inline auto&operator()(Bitmap &ho) ret_to_self(Select(ho));
	inline auto&operator()(const Pen &ho) ret_to_self(Select(ho));
	inline auto&operator()(const Brush &ho) ret_to_self(Select(ho));
	inline auto&operator()(const WX::Palette hPal, bool bForceBkgd = false) ret_to_self(Palette(hPal, bForceBkgd));
};
using CDevCap = ProxyView<DevCap>;
using DC = DevCap;
using CDC = ProxyView<DevCap>;
#pragma endregion

}
