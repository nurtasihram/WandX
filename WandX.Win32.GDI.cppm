module;

#include <Windows.h>

#define WANDX_CPPM_EXPORT_NATIVE
#include "WandX.Win32.GDI.h"

export module WandX.Realtime;

import WandX;
import WandX.Win32;

static constexpr auto ThisFile = WandX::LiString("WandX.Win32.GDI");

export namespace WandX {
namespace Native {

#pragma region WinUesr.h
wapi_ret_true(DrawEdge);
wapi_ret_true(DrawIcon);
// DrawText
inline int DrawText(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format)
safe_ret_as(auto h = ::DrawTextA(hdc, lpchText, cchText, lprc, format), h);
inline int DrawText(HDC hdc, LPCWSTR lpchText, int cchText, LPRECT lprc, UINT format)
safe_ret_as(auto h = ::DrawTextW(hdc, lpchText, cchText, lprc, format), h);
// DrawTextEx
inline int DrawTextEx(HDC hdc, LPSTR lpchText, int cchText, LPRECT lprc, UINT format, LPDRAWTEXTPARAMS lpdtp)
safe_ret_as(auto h = ::DrawTextExA(hdc, lpchText, cchText, lprc, format, lpdtp), h);
inline int DrawTextEx(HDC hdc, LPWSTR lpchText, int cchText, LPRECT lprc, UINT format, LPDRAWTEXTPARAMS lpdtp)
safe_ret_as(auto h = ::DrawTextExW(hdc, lpchText, cchText, lprc, format, lpdtp), h);
wapi_ret_true_WAT(GrayString);
wapi_ret_true_WAT(DrawState);
// TabbedTextOut
inline LONG TabbedTextOut(HDC hdc, int x, int y, LPCSTR lpString, int chCount, int nTabPositions, CONST INT *lpnTabStopPositions, int nTabOrigin)
safe_ret_as(auto h = ::TabbedTextOutA(hdc, x, y, lpString, chCount, nTabPositions, lpnTabStopPositions, nTabOrigin), h);
inline LONG TabbedTextOut(HDC hdc, int x, int y, LPCWSTR lpString, int chCount, int nTabPositions, CONST INT *lpnTabStopPositions, int nTabOrigin)
safe_ret_as(auto h = ::TabbedTextOutW(hdc, x, y, lpString, chCount, nTabPositions, lpnTabStopPositions, nTabOrigin), h);
wapi_ret_positive_WAO(GetTabbedTextExtent);
wapi_ret_true(PaintDesktop);
wapi_ret_direct(WindowFromDC);
// ExcludeUpdateRgn
inline int ExcludeUpdateRgn(HDC hDC, HWND hWnd)
safe_ret_as(auto h = ::ExcludeUpdateRgn(hDC, hWnd), h);
wapi_ret_true(ScrollDC);
wapi_ret_true(DrawFocusRect);
wapi_ret_true(FillRect);
wapi_ret_true(FrameRect);
wapi_ret_true(InvertRect);
wapi_ret_true(DrawIconEx);
#pragma endregion

#pragma region WinGDI.h
wapi_ret_positive_WAO(AddFontResource);
wapi_ret_true(AnimatePalette);
wapi_ret_true(Arc);
wapi_ret_true(BitBlt);
wapi_ret_true(CancelDC);
wapi_ret_true(Chord);
wapi_ret_positive(ChoosePixelFormat);
wapi_ret_notnull(CloseMetaFile);
// CombineRgn
inline int CombineRgn(HRGN hrgnDst, HRGN hrgnSrc1, HRGN hrgnSrc2, int iMode)
safe_ret_as(auto ret = ::CombineRgn(hrgnDst, hrgnSrc1, hrgnSrc2, iMode); ret != ERROR, ret);
wapi_ret_notnull_WAO(CopyMetaFile);
wapi_ret_notnull(CreateBitmap);
wapi_ret_notnull(CreateBitmapIndirect);
wapi_ret_notnull(CreateBrushIndirect);
wapi_ret_notnull(CreateCompatibleBitmap);
wapi_ret_notnull(CreateDiscardableBitmap);
wapi_ret_notnull(CreateCompatibleDC);
wapi_ret_notnull_WAO(CreateDC);
wapi_ret_notnull(CreateDIBitmap);
wapi_ret_notnull(CreateDIBPatternBrush);
wapi_ret_notnull(CreateDIBPatternBrushPt);
wapi_ret_notnull(CreateEllipticRgn);
wapi_ret_notnull(CreateEllipticRgnIndirect);
wapi_ret_notnull_WAO(CreateFontIndirect);
wapi_ret_notnull_WAO(CreateFont);
wapi_ret_notnull(CreateHatchBrush);
wapi_ret_notnull_WAO(CreateIC);
wapi_ret_notnull_WAO(CreateMetaFile);
wapi_ret_notnull(CreatePalette);
wapi_ret_notnull(CreatePen);
wapi_ret_notnull(CreatePenIndirect);
wapi_ret_notnull(CreatePolyPolygonRgn);
wapi_ret_notnull(CreatePatternBrush);
wapi_ret_notnull(CreateRectRgn);
wapi_ret_notnull(CreateRectRgnIndirect);
wapi_ret_notnull(CreateRoundRectRgn);
wapi_ret_true_WAO(CreateScalableFontResource);
wapi_ret_notnull(CreateSolidBrush);
wapi_ret_true(DeleteDC);
wapi_ret_true(DeleteMetaFile);
wapi_ret_true(DeleteObject);
wapi_ret_positive(DescribePixelFormat);
// DeviceCapabilities
inline int DeviceCapabilities(LPCSTR pDevice, LPCSTR pPort, WORD fwCapability, LPSTR pOutput, CONST DEVMODEA *pDevMode)
safe_ret_as(auto ret = ::DeviceCapabilitiesA(pDevice, pPort, fwCapability, pOutput, pDevMode); ret >= 0, ret);
inline int DeviceCapabilities(LPCWSTR pDevice, LPCWSTR pPort, WORD fwCapability, LPWSTR pOutput, CONST DEVMODEW *pDevMode)
safe_ret_as(auto ret = ::DeviceCapabilitiesW(pDevice, pPort, fwCapability, pOutput, pDevMode); ret >= 0, ret);
// DrawEscape
inline int DrawEscape(HDC hdc, int iEscape, int cjIn, LPCSTR lpIn)
safe_ret_as(auto ret = ::DrawEscape(hdc, iEscape, cjIn, lpIn); ret >= 0, ret);
wapi_ret_true(Ellipse);
wapi_ret_direct_WAO(EnumFontFamiliesEx);
wapi_ret_direct_WAO(EnumFontFamilies);
wapi_ret_direct_WAO(EnumFonts);
wapi_ret_direct(EnumObjects);
wapi_ret_direct(EqualRgn);
wapi_ret_positive(Escape);
wapi_ret_positive(ExtEscape);
// ExcludeClipRect
inline int ExcludeClipRect(HDC hdc, int left, int top, int right, int bottom)
safe_ret_as(auto ret = ::ExcludeClipRect(hdc, left, top, right, bottom); ret != ERROR, ret);
wapi_ret_notnull(ExtCreateRegion);
wapi_ret_true(ExtFloodFill);
wapi_ret_true(FillRgn);
wapi_ret_true(FloodFill);
wapi_ret_true(FrameRgn);
wapi_ret_positive(GetROP2);
wapi_ret_true(GetAspectRatioFilterEx);
wapi_ret_fault(GetBkColor, CLR_INVALID);
wapi_ret_fault(GetDCBrushColor, CLR_INVALID);
wapi_ret_fault(GetDCPenColor, CLR_INVALID);
wapi_ret_positive(GetBkMode);
// GetBitmapBits
inline LONG GetBitmapBits(HBITMAP hbit, LONG cb, LPVOID lpvBits)
safe_ret_as(auto ret = ::GetBitmapBits(hbit, cb, lpvBits), ret);
wapi_ret_true(GetBitmapDimensionEx);
wapi_ret_positive(GetBoundsRect);
wapi_ret_true(GetBrushOrgEx);
wapi_ret_true_WAT(GetCharWidth);
wapi_ret_true_WAT(GetCharWidth32);
wapi_ret_true_WAT(GetCharWidthFloat);
wapi_ret_true_WAT(GetCharABCWidths);
wapi_ret_true_WAT(GetCharABCWidthsFloat);
// GetClipBox
inline int GetClipBox(HDC hdc, LPRECT lprect)
safe_ret_as(auto ret = ::GetClipBox(hdc, lprect); ret != ERROR, ret);
wapi_ret_positive(GetClipRgn);
wapi_ret_positive(GetMetaRgn);
wapi_ret_notnull(GetCurrentObject);
wapi_ret_true(GetCurrentPositionEx);
wapi_ret_direct(GetDeviceCaps);
wapi_ret_positive(GetDIBits);
wapi_ret_fault(GetFontData, GDI_ERROR);
wapi_ret_direct_WAT(GetGlyphOutline);
wapi_ret_positive(GetGraphicsMode);
wapi_ret_positive(GetMapMode);
wapi_ret_positive(GetMetaFileBitsEx);
wapi_ret_notnull_WAO(GetMetaFile);
wapi_ret_fault(GetNearestColor, CLR_INVALID);
wapi_ret_fault(GetNearestPaletteIndex, CLR_INVALID);
wapi_ret_positive(GetObjectType);
wapi_ret_positive_WAO(GetOutlineTextMetrics);
wapi_ret_positive(GetPaletteEntries);
wapi_ret_fault(GetPixel, CLR_INVALID);
wapi_ret_positive(GetPixelFormat);
wapi_ret_positive(GetPolyFillMode);
wapi_ret_true(GetRasterizerCaps);
wapi_ret_positive(GetRandomRgn);
wapi_ret_positive(GetRegionData);
wapi_ret_positive(GetRgnBox);
wapi_ret_notnull(GetStockObject);
wapi_ret_positive(GetStretchBltMode);
wapi_ret_positive(GetSystemPaletteEntries);
// GetSystemPaletteUse
inline UINT GetSystemPaletteUse(HDC hdc)
safe_ret_as(auto ret = ::GetSystemPaletteUse(hdc); ret != SYSPAL_ERROR, ret);
// GetTextCharacterExtra
inline int GetTextCharacterExtra(HDC hdc)
safe_ret_as(auto ret = ::GetTextCharacterExtra(hdc); ret != 0x8000000, ret);
// GetTextAlign
inline UINT GetTextAlign(HDC hdc)
safe_ret_as(auto ret = ::GetTextAlign(hdc); ret != GCP_ERROR, ret);
wapi_ret_fault(GetTextColor, CLR_INVALID);
wapi_ret_true_WAO(GetTextExtentPoint);
wapi_ret_true_WAO(GetTextExtentPoint32);
wapi_ret_true_WAO(GetTextExtentExPoint);
wapi_ret_direct(GetTextCharset);
wapi_ret_direct(GetTextCharsetInfo);
wapi_ret_true(TranslateCharsetInfo);
// GetFontLanguageInfo
inline DWORD GetFontLanguageInfo(HDC hdc)
safe_ret_as(auto ret = ::GetFontLanguageInfo(hdc); ret != GCP_ERROR, ret);
wapi_ret_positive_WAO(GetCharacterPlacement);
wapi_ret_positive(GetFontUnicodeRanges);
// GetGlyphIndices
inline DWORD GetGlyphIndices(HDC hdc, LPCSTR lpstr, int c, LPWORD pgi, DWORD fl)
safe_ret_as(auto ret = ::GetGlyphIndicesA(hdc, lpstr, c, pgi, fl); ret != GCP_ERROR, ret);
inline DWORD GetGlyphIndices(HDC hdc, LPCWSTR lpstr, int c, LPWORD pgi, DWORD fl)
safe_ret_as(auto ret = ::GetGlyphIndicesW(hdc, lpstr, c, pgi, fl); ret != GCP_ERROR, ret);
wapi_ret_true(GetTextExtentPointI);
wapi_ret_true(GetTextExtentExPointI);
wapi_ret_true(GetCharWidthI);
wapi_ret_true(GetCharABCWidthsI);
wapi_ret_positive_WAO(AddFontResourceEx);
wapi_ret_true_WAO(RemoveFontResourceEx);
wapi_ret_notnull(AddFontMemResourceEx);
wapi_ret_true(RemoveFontMemResourceEx);
wapi_ret_true(GetViewportExtEx);
wapi_ret_true(GetViewportOrgEx);
wapi_ret_true(GetWindowExtEx);
wapi_ret_true(GetWindowOrgEx);
// IntersectClipRect
inline int IntersectClipRect(HDC hdc, int left, int top, int right, int bottom)
safe_ret_as(auto ret = ::IntersectClipRect(hdc, left, top, right, bottom); ret != ERROR, ret);
wapi_ret_true(InvertRgn);
wapi_ret_true(LineDDA);
wapi_ret_true(LineTo);
wapi_ret_true(MaskBlt);
wapi_ret_true(PlgBlt);
// OffsetClipRgn
inline int OffsetClipRgn(HDC hdc, int x, int y)
safe_ret_as(auto ret = ::OffsetClipRgn(hdc, x, y); ret != ERROR, ret);
// OffsetRgn
inline int OffsetRgn(HRGN hrgn, int x, int y)
safe_ret_as(auto ret = ::OffsetRgn(hrgn, x, y); ret != ERROR, ret);
wapi_ret_true(PatBlt);
wapi_ret_true(Pie);
wapi_ret_true(PlayMetaFile);
wapi_ret_true(PaintRgn);
wapi_ret_true(PolyPolygon);
wapi_ret_direct(PtInRegion);
// PtVisible
inline bool PtVisible(HDC hdc, int x, int y)
safe_ret_as(auto ret = ::PtVisible(hdc, x, y); ret >= 0, ret);
wapi_ret_direct(RectInRegion);
wapi_ret_direct(RectVisible);
wapi_ret_true(Rectangle);
wapi_ret_true(RestoreDC);
wapi_ret_notnull_WAO(ResetDC);
// RealizePalette
inline UINT RealizePalette(HDC hdc)
safe_ret_as(auto ret = ::RealizePalette(hdc); ret != GCP_ERROR, ret);
wapi_ret_true_WAO(RemoveFontResource);
wapi_ret_true(RoundRect);
wapi_ret_true(ResizePalette);
wapi_ret_positive(SaveDC);
// SelectClipRgn
inline int SelectClipRgn(HDC hdc, HRGN hrgn)
safe_ret_as(auto ret = ::SelectClipRgn(hdc, hrgn); ret != ERROR, ret);
// ExtSelectClipRgn
inline int ExtSelectClipRgn(HDC hdc, HRGN hrgn, int mode)
safe_ret_as(auto ret = ::ExtSelectClipRgn(hdc, hrgn, mode); ret != ERROR, ret);
// SetMetaRgn
inline int SetMetaRgn(HDC hdc)
safe_ret_as(auto ret = ::SetMetaRgn(hdc); ret != ERROR, ret);
//// SelectObject
//static inline HGDIOBJ SelectObject(HDC hdc, HGDIOBJ h)
//safe_ret_as(auto ret = ::SelectObject(hdc, h); ret != HGDI_ERROR, ret);
wapi_ret_notnull(SelectPalette);
wapi_ret_fault(SetBkColor, CLR_INVALID);
wapi_ret_fault(SetDCBrushColor, CLR_INVALID);
// SetDCPenColor
inline COLORREF SetDCPenColor(HDC hdc, COLORREF color)
safe_ret_as(auto ret = ::SetDCPenColor(hdc, color); ret != GCP_ERROR, ret);
wapi_ret_positive(SetBkMode);
// SetBitmapBits
inline LONG SetBitmapBits(HBITMAP hbm, DWORD cb, CONST VOID *pvBits)
safe_ret_as(auto ret = ::SetBitmapBits(hbm, cb, pvBits), ret);
wapi_ret_positive(SetBoundsRect);
wapi_ret_positive(SetDIBits);
wapi_ret_direct(SetDIBitsToDevice);
// SetMapperFlags
inline DWORD SetMapperFlags(HDC hdc, DWORD flags)
safe_ret_as(auto ret = ::SetMapperFlags(hdc, flags); ret != GCP_ERROR, ret);
wapi_ret_positive(SetGraphicsMode);
wapi_ret_positive(SetMapMode);
// SetLayout
inline DWORD SetLayout(HDC hdc, DWORD l)
safe_ret_as(auto ret = ::SetLayout(hdc, l); ret != GCP_ERROR, ret);
// GetLayout
inline DWORD GetLayout(HDC hdc)
safe_ret_as(auto ret = ::GetLayout(hdc); ret != GCP_ERROR, ret);
wapi_ret_notnull(SetMetaFileBitsEx);
wapi_ret_positive(SetPaletteEntries);
wapi_ret_fault(SetPixel, CLR_INVALID);
wapi_ret_true(SetPixelV);
wapi_ret_true(SetPixelFormat);
wapi_ret_positive(SetPolyFillMode);
wapi_ret_true(StretchBlt);
wapi_ret_true(SetRectRgn);
wapi_ret_direct(StretchDIBits);
wapi_ret_positive(SetROP2);
wapi_ret_positive(SetStretchBltMode);
// SetSystemPaletteUse
inline UINT SetSystemPaletteUse(HDC hdc, UINT use)
safe_ret_as(auto ret = ::SetSystemPaletteUse(hdc, use); ret != SYSPAL_ERROR, ret);
// SetTextCharacterExtra
inline int SetTextCharacterExtra(HDC hdc, int extra)
safe_ret_as(auto ret = ::SetTextCharacterExtra(hdc, extra); ret != 0x8000000, ret);
wapi_ret_fault(SetTextColor, CLR_INVALID);
// SetTextAlign
inline UINT SetTextAlign(HDC hdc, UINT align)
safe_ret_as(auto ret = ::SetTextAlign(hdc, align); ret != GCP_ERROR, ret);
wapi_ret_true(SetTextJustification);
wapi_ret_true(UpdateColors);
// GdiRegisterDdraw - Undocument
// GdiMarshalSize - Undocument
// GdiMarshal - Undocument
// GdiUnmarshal - Undocument
wapi_ret_true(AlphaBlend);
wapi_ret_true(TransparentBlt);
wapi_ret_true(GradientFill);
wapi_ret_true(GdiAlphaBlend);
wapi_ret_true(GdiTransparentBlt);
wapi_ret_true(GdiGradientFill);
wapi_ret_true(PlayMetaFileRecord);
wapi_ret_true(EnumMetaFile);
wapi_ret_notnull(CloseEnhMetaFile);
wapi_ret_notnull_WAO(CopyEnhMetaFile);
wapi_ret_notnull_WAO(CreateEnhMetaFile);
wapi_ret_true(DeleteEnhMetaFile);
wapi_ret_true(EnumEnhMetaFile);
wapi_ret_notnull_WAO(GetEnhMetaFile);
wapi_ret_positive(GetEnhMetaFileBits);
//wapi_ret_fault_WAO(GetEnhMetaFileDescription, GDI_ERROR);
wapi_ret_positive(GetEnhMetaFileHeader);
wapi_ret_fault(GetEnhMetaFilePaletteEntries, GDI_ERROR);
wapi_ret_positive(GetEnhMetaFilePixelFormat);
wapi_ret_positive(GetWinMetaFileBits);
wapi_ret_true(PlayEnhMetaFile);
wapi_ret_true(PlayEnhMetaFileRecord);
wapi_ret_notnull(SetEnhMetaFileBits);
wapi_ret_notnull(SetWinMetaFileBits);
wapi_ret_true(GdiComment);
wapi_ret_true_WAO(GetTextMetrics);
wapi_ret_true(AngleArc);
wapi_ret_true(PolyPolyline);
wapi_ret_true(GetWorldTransform);
wapi_ret_true(SetWorldTransform);
wapi_ret_true(ModifyWorldTransform);
wapi_ret_true(CombineTransform);
wapi_ret_notnull(CreateDIBSection);
wapi_ret_positive(GetDIBColorTable);
wapi_ret_positive(SetDIBColorTable);
wapi_ret_true(SetColorAdjustment);
wapi_ret_true(GetColorAdjustment);
wapi_ret_notnull(CreateHalftonePalette);
wapi_ret_positive_WAO(StartDoc);
wapi_ret_positive(EndDoc);
wapi_ret_positive(StartPage);
wapi_ret_positive(EndPage);
wapi_ret_positive(AbortDoc);
wapi_ret_positive(SetAbortProc);
wapi_ret_true(AbortPath);
wapi_ret_true(ArcTo);
wapi_ret_true(BeginPath);
wapi_ret_true(CloseFigure);
wapi_ret_true(EndPath);
wapi_ret_true(FillPath);
wapi_ret_true(FlattenPath);
wapi_ret_direct(GetPath);
wapi_ret_notnull(PathToRegion);
wapi_ret_true(PolyDraw);
wapi_ret_true(SelectClipPath);
wapi_ret_positive(SetArcDirection);
wapi_ret_true(SetMiterLimit);
wapi_ret_true(StrokeAndFillPath);
wapi_ret_true(StrokePath);
wapi_ret_true(WidenPath);
wapi_ret_notnull(ExtCreatePen);
wapi_ret_true(GetMiterLimit);
wapi_ret_positive(GetArcDirection);
wapi_ret_positive_WAT(GetObject);
wapi_ret_true(MoveToEx);
wapi_ret_true_WAO(TextOut);
wapi_ret_true_WAO(ExtTextOut);
wapi_ret_true_WAO(PolyTextOut);
wapi_ret_notnull(CreatePolygonRgn);
wapi_ret_true(DPtoLP);
wapi_ret_true(LPtoDP);
wapi_ret_true(Polygon);
wapi_ret_true(Polyline);
wapi_ret_true(PolyBezier);
wapi_ret_true(PolyBezierTo);
wapi_ret_true(PolylineTo);
wapi_ret_true(SetViewportExtEx);
wapi_ret_true(SetViewportOrgEx);
wapi_ret_true(SetWindowExtEx);
wapi_ret_true(SetWindowOrgEx);
wapi_ret_true(OffsetViewportOrgEx);
wapi_ret_true(OffsetWindowOrgEx);
wapi_ret_true(ScaleViewportExtEx);
wapi_ret_true(ScaleWindowExtEx);
wapi_ret_true(SetBitmapDimensionEx);
wapi_ret_true(SetBrushOrgEx);
wapi_ret_positive_WAO(GetTextFace);
wapi_ret_positive_WAT(GetKerningPairs);
wapi_ret_true(GetDCOrgEx);
// FixBrushOrgEx - Undocument
wapi_ret_true(UnrealizeObject);
wapi_ret_true(GdiFlush);
wapi_ret_positive(GdiSetBatchLimit);
wapi_ret_positive(GdiGetBatchLimit);
wapi_ret_positive(SetICMMode);
wapi_ret_true(CheckColorsInGamut);
wapi_ret_notnull(GetColorSpace);
wapi_ret_true_WAO(GetLogColorSpace);
wapi_ret_notnull_WAO(CreateColorSpace);
wapi_ret_notnull(SetColorSpace);
wapi_ret_true(DeleteColorSpace);
wapi_ret_true_WAO(GetICMProfile);
wapi_ret_true_WAO(SetICMProfile);
wapi_ret_true(GetDeviceGammaRamp);
wapi_ret_true(SetDeviceGammaRamp);
wapi_ret_true(ColorMatchToTarget);
wapi_ret_direct_WAO(EnumICMProfiles);
// UpdateICMRegKey - Deprecated
wapi_ret_true(ColorCorrectPalette);
#pragma endregion

}


}
