module;

#include "wx"

export module wx.radix;

namespace WX {

constexpr bool RangeI(auto val, auto min, auto max) ret_as(min <= val && val <= max);
constexpr bool RangeO(auto val, auto min, auto max) ret_as(min >  val || val >  max);
constexpr bool RangeX(auto val, auto min, auto max) ret_as(min <= max ? RangeI(val, min, max) : RangeO(val, min, max));
constexpr bool RangeD(auto val, auto...vals) ret_as(((val == vals) || ...));
constexpr bool RangeA(auto val, auto *vals, SizeT count) {
	for (SizeT i = 0; i < count; ++i) 
		if (val == vals[i])
			return true;
	return false;
}
template<SizeT len, class AnyType>
constexpr bool RangeA(auto val, AnyType(&vals)[len]) ret_as(RangeA(val, vals, len));

constexpr auto IRangeI(auto org, auto val, auto min, auto max) ret_as(
	RangeI(val, min, max) ? val - min :
	org);
constexpr auto IRangeO(auto org, auto val, auto min, auto max) ret_as(
	val > max ? val - max :
	val < min ? val - min :
	org);
constexpr auto IRangeX(auto org, auto val, auto min, auto max) ret_as(min <= max ? IRangeI(org, val, min, max) : IRangeO(org, val, min, max));
constexpr SizeT IRangeD(auto val, auto val0) ret_as(val != val0);
template<SizeT idx = 0>
constexpr SizeT IRangeD(auto val, auto valX, auto...valN) ret_as(val == valX ? idx : IRangeD<idx + 1>(val, valN...));
constexpr SizeT IRangeA(auto val, auto *vals, SizeT count) {
	for (SizeT i = 0; i < count; ++i)
		if (val == vals[i])
			return i;
	return count;
}
template<SizeT len, class AnyType>
constexpr SizeT IRangeA(auto val, AnyType(&vals)[len]) ret_as(IRangeA(val, vals, len));

#pragma region StringViews

template<class Char> class LPString;
template<class Char> class HPString;

template<class Char>
class XPString {
	mutable Char *pStr = O;
	mutable SizeT len = 0;
public:
	constexpr XPString() {}
	constexpr XPString(Nu) {}
	constexpr XPString(XPString &&) = default;
	constexpr XPString(const XPString &) = default;
	constexpr XPString &operator=(XPString &&) = default;
	constexpr XPString &operator=(const XPString &) = default;
	constexpr XPString(Char *pStr, SizeT len) : pStr(pStr), len(len) {}
public:
	constexpr SizeT Length() const ret_as(len);
	constexpr Char *Data() const ret_as(pStr);
	constexpr void OffsetL(SizeT offset) {
		if (offset >= len) 
			offset  = len;
		pStr += offset;
		len  -= offset;
	}
	constexpr void OffsetH(SizeT offset) {
		if (offset >= len)
			offset  = len;
		pStr -= offset;
		len  -= offset;
	}
	constexpr void Cut() {
		if (pStr && len)
			pStr[len - 1] = 0;
	}
	constexpr void End() {
		if (pStr && len)
			pStr[0] = 0;
	}
public:
	constexpr operator bool() const ret_as(len);
	constexpr operator Char *() const ret_as(pStr);
	constexpr Char &operator*() const ret_as(*pStr);
	constexpr Char &operator[](SizeT ind) const ret_as(pStr[ind]);
public:
	constexpr bool operator==(Nu) const ret_as(!pStr);
	constexpr bool operator!=(Nu) const ret_as( pStr);
	constexpr bool operator==(const XPString &s) const ret_as(pStr == s.pStr);
	constexpr bool operator!=(const XPString &s) const ret_as(pStr != s.pStr);
	constexpr bool operator<=(const XPString &s) const ret_as(pStr <= s.pStr);
	constexpr bool operator>=(const XPString &s) const ret_as(pStr >= s.pStr);
	constexpr bool operator< (const XPString &s) const ret_as(pStr <  s.pStr);
	constexpr bool operator> (const XPString &s) const ret_as(pStr >  s.pStr);
public:
	constexpr Nu operator=(Nu) const ret_as(pStr = O, len = 0);
};
template<class Char>
class HPString : public XPString<Char> {
public:
	using Super = XPString<Char>;
public:
	constexpr HPString() {}
	constexpr HPString(Nu) {}
	constexpr HPString(HPString &&) = default;
	constexpr HPString(const HPString &) = default;
	constexpr HPString &operator=(HPString &&) = default;
	constexpr HPString &operator=(const HPString &) = default;
	constexpr HPString(Char *pStr, SizeT len) : Super(pStr, len) {}
public:
	using Super::Data;
	using Super::Length;
	void OffsetL(SizeT) = delete;
	void OffsetH(SizeT) = delete;
	constexpr void Offset(SizeT offset) ret_to(Super::OffsetH(offset));
public:
	constexpr Char *operator+(SizeT offset) const ret_as(Data() + offset);
public:
	constexpr HPString operator- (SizeT offset) const ret_as(HPString(self).Offset(offset));
	constexpr HPString&operator-=(SizeT offset) ret_to_self(Offset(offset));
public:
	constexpr HPString&operator--(   ) ret_to_self(Offset(1));
	constexpr HPString operator--(int) ret_to(auto old = self; Offset(1), old);
public:
	constexpr LPString<Char> operator-() ret_as({ Data() - Length(), Length() });
};
template<class Char>
class LPString : public XPString<Char> {
public:
	using Super = XPString<Char>;
public:
	constexpr LPString() {}
	constexpr LPString(Nu) {}
	constexpr LPString(LPString &&) = default;
	constexpr LPString(const LPString &) = default;
	constexpr LPString &operator=(LPString &&) = default;
	constexpr LPString &operator=(const LPString &) = default;
	constexpr LPString(Char *pStr, SizeT len) : Super(pStr, len) {}
public:
	using Super::Data;
	using Super::Length;
	void OffsetL(SizeT) = delete;
	void OffsetH(SizeT) = delete;
	constexpr void Offset(SizeT offset) ret_to(Super::OffsetL(offset));
public:
	constexpr Char *operator-(SizeT offset) const ret_as(Data() - offset);
public:
	constexpr LPString operator+ (SizeT offset) const ret_as(LPString(self).Offset(offset));
	constexpr LPString&operator+=(SizeT offset) ret_to_self(Offset(offset));
public:
	constexpr LPString&operator++(   ) ret_to_self(Offset(1));
	constexpr LPString operator++(int) ret_to(auto old = self; Offset(1), old);
public:
	constexpr HPString<Char> operator+() ret_as({ Data() + Length(), Length() });
	constexpr HPString<Char> HighOf(SizeT range) ret_as({ Data() + range, range <= Length() ? range : 0 });
	constexpr HPString<Char>  LowOf(SizeT range) ret_as({ Data() - range, range <= Length() ? range : 0 });
};

template<class Char>
constexpr LPString<Char> PString(Char *lpStr, SizeT len) ret_as({ lpStr, len });
template<class Char>
constexpr HPString<Char> PString(SizeT Len, Char *hpStr) ret_as({ hpStr, Len });
template<class Char, SizeT Len>
constexpr LPString<Char> PString(Char(&arr)[Len]) ret_as({ arr, Len - 1 });

#pragma endregion 

constexpr bool R_blank(auto ch) ret_as(RangeD(ch, ' ', '\t'));
constexpr bool R_alpha(auto ch) ret_as(RangeI(ch, 'a',  'z'));
constexpr bool R_ALPHA(auto ch) ret_as(RangeI(ch, 'A',  'Z'));
constexpr bool R_digit(auto ch) ret_as(RangeI(ch, '0',  '9'));
constexpr bool R_print(auto ch) ret_as(RangeI(ch, 0x20, 0x7E));
constexpr bool R_ASCII(auto ch) ret_as(RangeI(ch, 0x00, 0x7F));
constexpr bool R_Alpha(auto ch) ret_as(R_alpha(ch) || R_ALPHA(ch));
constexpr bool R_Alnum(auto ch) ret_as(R_Alpha(ch) || R_digit(ch));
constexpr bool R_names(auto ch) ret_as(R_Alnum(ch) || ch == '_');
constexpr bool R_invis(auto ch) ret_as(!R_print(ch));

template<class Char = char>
constexpr LPString<Char> InsertLine(SizeT lineIndex,
									LPString<const Char> str,
									LPString<const Char> line,
									LPString<Char> buffer) {
	if (!line || !buffer) return O;
	if (str.Length() + line.Length() + 1 > buffer.Length()) return O;
	Char lastChar = '\0';
	while (str) {
		if (*str == '\n') {
			if (!lineIndex)
				break;
			else --lineIndex;
		}
		lastChar = *buffer++ = *str++;
	}
	if (lineIndex && lastChar != '\n' && lastChar != '\0')
		*buffer++ = '\n';
	while (line)
		*buffer++ = *line++;
	while (str)
		*buffer++ = *str++;
	return buffer;
}

template<class Char = char>
constexpr LPString<Char> PageConcat(LPString<const Char> str1,
									LPString<const Char> str2,
									LPString<Char> buffer) {
	if (str1.Length() + str2.Length() > buffer.Length()) return O;
	do {
		while (str1)
			if (auto ch = *str1++; ch != '\n')
				*buffer++ = ch;
			else break;
		while (str2)
			if (auto ch = *str2++; ch != '\n')
				*buffer++ = ch;
			else break;
		*buffer++ = '\n';
	} while (str1 || str2);
	return buffer;
}

template<class Char = char, auto fnLenChar = O>
constexpr HPString<const Char> WidestLine(LPString<const Char> str) {
	SizeT nMaxLine = 0, nNowLine = 0;
	const Char *hpMaxLine = str;
	constexpr bool canLenChar = requires{ nNowLine += fnLenChar('\0'); };
	for (nMaxLine = 0, nNowLine = 0, hpMaxLine = str; str; ++str)
		if (auto ch = *str; ch == '\n') {
			if (nMaxLine < nNowLine)
				nMaxLine = nNowLine,
				hpMaxLine = str;
			nNowLine = 0;
		}
		elif_c (canLenChar)
			   nNowLine += fnLenChar(ch);
		else ++nNowLine;
	return{ hpMaxLine, nMaxLine };
}
template<class Char = char>
constexpr HPString<const Char> WidestLinePrint(LPString<const Char> str) ret_as(WidestLine<Char, R_print<Char>>(str));

template<class Char = char, auto fnLenChar = O>
constexpr LPString<Char> TabToSpace(LPString<const Char> str, SizeT tabSize, LPString<Char> buffer) {
	if (!str || !buffer) return O;
	if (tabSize == 0) return O;
	SizeT col = 0;
	constexpr bool canLenChar = requires{ col += fnLenChar('\0'); };
	while (str) {
		auto ch = *str++;
		if (ch == '\t') {
			auto spaces = tabSize - (col % tabSize);
			if (!spaces) spaces = tabSize;
			for (auto n = spaces; n; --n)
				*buffer++ = ' ';
			if_c (canLenChar)
				spaces *= fnLenChar(' ');
			col += spaces;
			continue;
		} elif (ch == '\n')
			col = 0;
		elif_c (canLenChar)
			   col += fnLenChar(ch);
		else ++col;
		*buffer++ = ch;
	}
	return buffer;
}
template<class Char = char>
constexpr LPString<Char> TabToSpacePrint(LPString<const Char> str, SizeT tabSize, LPString<Char> buffer) ret_as(TabToSpace<Char, R_print<Char>>(str, tabSize, buffer));

const char escapeAsciiKey[]{ "0abfnrtv" };
const char escapeAsciiVal[]{ "\0\a\b\f\n\r\t\v" };
template<class Char = char>
constexpr Char EscapeAscii(Char ch) {
	for (SizeT i = 0; i < sizeof(escapeAsciiKey) - 1; ++i)
		if (escapeAsciiKey[i] == ch)
			return escapeAsciiVal[i];
	return ch;
}
template<class Char = char>
constexpr Char UnescapeAscii(Char ch) {
	for (SizeT i = 0; i < sizeof(escapeAsciiVal) - 1; ++i)
		if (escapeAsciiVal[i] == ch)
			return escapeAsciiKey[i];
	return ch;
}

#pragma region FormatSpecifiers

enum class FmtSignVis   : Int8U  { Err = 0xFF, Implicit = 0, Explicit = 1 };

enum class FmtRadixType : Int8U  { Err = 0xFF, Default = 0,
	Dec = 1, Six = 2, Tri = 3, Hex = 4, Oct = 5, Qua = 6, Bin = 7 };
enum class FmtRadixCase : Int8U  { Err = 0xFF, Lower = 0, Upper = 1 };

enum class FmtAlign	    : Int8U  { Err = 0xFF, Default = 0, Left = 1, Right = 2, Center = 3 };
enum class FmtSignAlign : Int8U  { Err = 0xFF, Follow = 0, Left = 1};

const char digitsLower[]{ "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_." };
const char digitsUpper[]{ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_." };

// to_string
template<class Char = char>
constexpr Char FmtSignVisChar(FmtSignVis vis) {
	return	vis   == FmtSignVis  ::Explicit ? '+' :  '-';
}
template<class Char = char>
constexpr Char FmtRadixTypeChar(FmtRadixType type, FmtRadixCase rcase) {
	Char rad =	type == FmtRadixType::Dec      ? 'd' :
				type == FmtRadixType::Six      ? 's' :
				type == FmtRadixType::Tri      ? 't' :
				type == FmtRadixType::Hex      ? 'h' :
				type == FmtRadixType::Oct      ? 'o' :
				type == FmtRadixType::Qua      ? 'q' :
				type == FmtRadixType::Bin      ? 'b' : '\0';
	if (rcase == FmtRadixCase::Upper  && rad != '\0')
		rad += 'A' - 'a';
	return rad;
}
constexpr Int8U FmtRadixBase(FmtRadixType type) {
	return	type == FmtRadixType::Dec ? 10 :
			type == FmtRadixType::Six ? 64 :
			type == FmtRadixType::Tri ? 32 :
			type == FmtRadixType::Hex ? 16 :
			type == FmtRadixType::Oct ? 8  :
			type == FmtRadixType::Qua ? 4  :
			type == FmtRadixType::Bin ? 2  : 10;
}
template<class Char = char>
auto FmtRadixPushRight(IntPU &value, FmtRadixType type, FmtRadixCase rcase, HPString<Char> buffer) {
	auto digits = rcase == FmtRadixCase::Lower ? digitsLower : digitsUpper;
	auto base = FmtRadixBase(type);
	while (buffer) {
		auto div = value / base;
		*--buffer = digits[value - div * base];
		value = div;
		if (value == 0) break;
	}
	return buffer;
}
template<class Char = char>
auto FmtRadixPushLeft(IntPU &value, FmtRadixType type, FmtRadixCase rcase, LPString<Char> buffer) {
	auto hiBuffer = +buffer;
	auto loNum = FmtRadixPushRight(value, type, rcase, hiBuffer);
	while (buffer < hiBuffer)
		*loNum++ = *buffer++;
	return hiBuffer;
}

// from string
constexpr FmtSignVis FmtSignVisFromChar(auto ch) {
	return	ch == '+' ? FmtSignVis::Explicit :
			ch == '-' ? FmtSignVis::Implicit :
						FmtSignVis::Err;
}
constexpr FmtRadixType FmtRadixTypeFromChar(auto ch) {
	return	ch == 'd' ? FmtRadixType::Dec :
			ch == 's' ? FmtRadixType::Six :
			ch == 't' ? FmtRadixType::Tri :
			ch == 'h' ? FmtRadixType::Hex :
			ch == 'o' ? FmtRadixType::Oct :
			ch == 'q' ? FmtRadixType::Qua :
			ch == 'b' ? FmtRadixType::Bin :
						FmtRadixType::Err;
}
template<class Char = char>
constexpr auto FmtRadixFromString(IntPU &value, FmtRadixType type, FmtRadixCase rcase,
								  LPString<const Char> buffer) {
	auto(&digits)[65] = rcase == FmtRadixCase::Lower ? digitsLower : digitsUpper;
	auto base = FmtRadixBase(type);
	value = 0;
	while (buffer)
		if (auto bit = IRangeA(*buffer, digits); bit < base)
			if (auto val = value * base + bit; val >= value)
				value = val,
				++buffer;
			else break;
		else break;
	return buffer;
}

constexpr Int8U FmtRadixLength(IntPU value, FmtRadixType type) {
	Int8U len = 0;
	auto base = FmtRadixBase(type);
	do {
		value /= base;
		++len;
	} while (value);
	return len;
}

struct FmtPart {
	Int16U width : 15;
	Int16U p_def : 1;

	FmtSignVis   sign_vis : 1;
	FmtSignAlign sign_alg : 1;
	FmtAlign     alg      : 2;
	FmtRadixType rtype    : 3;
	FmtRadixCase rcase    : 1;

	char         fill;

public:
	constexpr FmtPart() :
		sign_vis(FmtSignVis::Implicit),
		rtype(FmtRadixType::Default), rcase(FmtRadixCase::Lower),
		// p_vis(FmtSignVis::Implicit),
		width(0), sign_alg(FmtSignAlign::Follow),
		alg(FmtAlign::Default), fill(0) {}
	constexpr FmtPart(Nu) : FmtPart() {}
public:
	template<class Char = char>
	constexpr auto from_string(LPString<const Char> str) {
		if (!str) return str;
		bool sign_def = false;
		if (auto sign_vis = FmtSignVisFromChar(*str); sign_vis != FmtSignVis::Err) {
			sign_def = true;
			this->sign_vis = sign_vis;
			this->sign_alg = FmtSignAlign::Left;
			if (!++str) return str;
		}
		if (auto ch = *str; RangeD(ch, ' ', '0', '/')) {
			if (ch == '/') {
				ch = *++str;
				if (!str) return str;
			}
			this->alg = FmtAlign::Right;
			this->fill = ch;
			if (!++str) return str;
		}
		if (auto sign_vis = FmtSignVisFromChar(*str); sign_vis != FmtSignVis::Err) {
			if (sign_def) return str;
			this->sign_vis = sign_vis;
			if (this->fill)
				this->sign_alg = FmtSignAlign::Follow;
			if (!++str) return str;
		}
		IntPU width = 0;
		if (auto strNext = FmtRadixFromString(width, FmtRadixType::Dec, FmtRadixCase::Lower, str); strNext > str) {
			this->width = (Int16U)width;
			str = strNext;
			if (!str) return str;
		}
		auto ch = *str;
		if (R_ALPHA(ch)) {
			this->rcase = FmtRadixCase::Upper;
			ch += 'a' - 'A';
		}
		if (auto rtype = FmtRadixTypeFromChar(ch); rtype != FmtRadixType::Err) {
			this->rtype = rtype;
			if (!++str) return str;
		}
		if (auto ch = *str; RangeD(ch, ' ', '/')) {
			if (ch == '/') {
				if (!++str) return str;
				ch = *str;
			}
			if (ch == this->fill) {
				if ( this->alg == FmtAlign::Right)
					 this->alg =  FmtAlign::Center;
				else this->alg =  FmtAlign::Left;
			} else this->fill = ch;
			++str;
		}
		return str;
	}
	template<class Char = char>
	constexpr LPString<Char> push(LPString<Char> buffer, IntPU i, Char sgn) const {
		auto width = this->width;
		auto numLen = FmtRadixLength(i, rtype);
		auto vsgn = sgn ? 1 : 0;
		if (width == 0) width = numLen + vsgn;
		if (width > buffer.Length()) return {};
		auto strStart = buffer;
		auto strMost = buffer.HighOf(width);
		if (width < numLen + vsgn) {
			while (buffer < strMost)
				*buffer++ = '#';
			return buffer;
		}
		auto fill = this->fill ? this->fill : ' ';
		auto lpNum = FmtRadixPushRight(i, rtype, rcase, strMost);
		auto lpNumPtr = lpNum.Data();
		auto pNumPtr = lpNumPtr;
		if (alg == FmtAlign::Right)
			while (buffer < lpNumPtr)
				*buffer++ = fill;
		elif (alg == FmtAlign::Center) {
			auto pad = width - numLen;
			if (sign_alg == FmtSignAlign::Follow)
				pad += vsgn;
			auto left = pad >> 1;
			auto right = pad - left;
			while (left--)
				*buffer++ = fill;
			pNumPtr = buffer;
			while (numLen--)
				*buffer++ = *lpNumPtr++;
			while (right--)
				*buffer++ = fill;
		} else {
			buffer += vsgn;
			while (numLen--)
				*buffer++ = *lpNumPtr++;
			while (buffer < strMost)
				*buffer++ = fill;
		}
		if (vsgn) {
			if (sign_alg == FmtSignAlign::Left)
				 *strStart = sgn;
			else *--pNumPtr = sgn;
		}
		return buffer;
	}
	template<class Char = char>
	constexpr auto push(LPString<Char> buffer, IntP i) const {
		IntPU uvalue = 0;
		char sgn = '\0';
		if (i) {
			if (i < 0) {
				sgn = '-';
				uvalue = (IntPU)(-i);
			}
			else {
				uvalue = (IntPU)(i);
				if (sign_vis == FmtSignVis::Explicit)
					sgn = '+';
			}
		}
		return push(buffer, uvalue, sgn);
	}
	template<class Char = char>
	constexpr LPString<Char> push(LPString<Char> buffer, LPString<const Char> str) const {
		
		return O;
	}
};

constexpr FmtPart operator""_fmti(const char *str, SizeT size) {
	auto loStr = PString(str, size);
	FmtPart part;
	auto strNext = part.from_string(loStr);
	if (strNext)
		return O;
	return part;
}

#pragma endregion

}

#if 0
void test1() {
	Console.Write("\n---Test 1---\n");
	auto &&f = "- 10h "_fmti;

	char buffer[32]{ 0 };

	f.push(PString(buffer, sizeof(buffer)), -255).End();
	Console.Format("%d '%s'\n", strlen(buffer), buffer);

	f.push(PString(buffer, sizeof(buffer)), 0).End();
	Console.Format("%d '%s'\n", strlen(buffer), buffer);
}
void test2() {
	Console.Write("\n---Test 2---\n");
	const char str[] =
		"Line1\n"
		"Line2\n"
		"Line3\n"
		"Line4\n";
	const char line[] = "-Inserted";

	char buffer[64]{ 0 };

	Console.Write("\nInsert 0 line:\n");
	InsertLine(0, PString(str), PString(line), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nInsert 2 line:\n");
	InsertLine(2, PString(str), PString(line), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nInsert 3 line:\n");
	InsertLine(3, PString(str), PString(line), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nInsert 5 line (beyond line count):\n");
   	InsertLine(5, PString(str), PString(line), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nInsert Null line:\n");
	InsertLine(2, {}, PString(line), PString(buffer)).End();
	Console.Format("%s\n", buffer);
}
void test3() {
	Console.Write("\n---Test 3---\n");
	const char str1[] =
		"Page1-Line1 \n"
		"Page1-Line2 \n"
		"Page1-Line3 \n";
	const char str2[] =
		"Page2-Line1 \n"
		"Page2-Line2 \n";
	const char str3[] =
		"Page3-Line ";
	char buffer[sizeof(str1) + sizeof(str2) ]{ 0 };

	Console.Write("\nConcat pages:\n");
	PageConcat(PString(str1), PString(str2), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nConcat pages:\n");
	PageConcat(PString(str2), PString(str1), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nConcat pages:\n");
	PageConcat(PString(str3), PString(str1), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nConcat pages:\n");
	PageConcat(PString(str1), PString(str3), PString(buffer)).End();
	Console.Format("%s", buffer);

	Console.Write("\nConcat with empty page:\n");
	PageConcat({}, PString(str2), PString(buffer)).End();
	Console.Format("%s", buffer);
}
void test4() {
	Console.Write("\n---Test 4---\n");
	const char str[] =
		"Line1\n"
		"Line2\n"
		"Longest Line3\n"
		"Line4\n";
	char buffer[64]{ 0 };

	Console.Write("\nLongest line:\n");
	auto longest = WidestLine(PString(str));
	Console.Write(-longest, (DWORD)longest.Length());
}
void test5() {
	Console.Write("\n---Test 5---\n");
	const char str[] =
"\
Line1	with tabs\n\
Line_2	with tabs\n\
Line__3	with tabs\n\
Line___4	with tabs\n\
Line____5	with tabs\n\
";
	char buffer[128]{ 0 };
	Console.Write("\nTab to space with tab size 4:\n");
	TabToSpacePrint(PString(str), 4, PString(buffer)).End();
	Console.Format("%s", buffer);
	Console.Write("\nTab to space with tab size 8:\n");
	TabToSpace(PString(str), 8, PString(buffer)).End();
	Console.Format("%s", buffer);

}
#endif
