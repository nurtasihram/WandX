#include "wx_main"

using namespace WX;

template<char... ch>
constexpr auto operator ""_ls() { return LiStringA({ ch ... }); }

int WxMain() {
	Console.Write(Console.Title());
	Console.Write('\n');
	Console.Title("WX - Tests");
	//Console.Write(COMPILATION_INFO);
	constexpr auto str = 123_ls;
	return 0;
}
