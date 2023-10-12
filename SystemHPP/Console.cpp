#include "Console.hpp"

#include"Convert.hpp"

#define esc '\x1b'

namespace Sys
{
	#pragma region class Console

	Color Console::textColor = Color::White;
	Color Console::backgroundColor = Color::Black;
	bool Console::cursorVisible = true;

	void Console::WriteLine()
	{
		std::cout << std::endl;
	}
	std::string Console::ReadLine()
	{
		std::string res;
		std::getline(std::cin, res);
		return res;
	}
	int Console::Read()
	{
		return _getch();
	}

	void Console::Write(float arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(double arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(long double arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(wchar_t arg)
	{
		std::wcout << arg;
	}
	void Console::Write(const wchar_t* arg)
	{
		std::wcout << arg;
	}
	void Console::Write(const std::wstring& arg)
	{
		std::wcout << arg;
	}
	void Console::Write(char16_t arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(const char16_t* arg)
	{
		std::cout << Convert::ToString(std::u16string(arg));
	}
	void Console::Write(const std::u16string& arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(char32_t arg)
	{
		std::cout << Convert::ToString(arg);
	}
	void Console::Write(const char32_t* arg)
	{
		std::cout << Convert::ToString(std::u32string(arg));
	}
	void Console::Write(const std::u32string& arg)
	{
		std::cout << Convert::ToString(arg);
	}

	void Console::SetBackgroundColor(Color color)
	{
		std::cout << esc << '[' << (int(color) + 40) << "m";
		backgroundColor = color;
	}
	void Console::SetColor(Color color)
	{
		std::cout << esc << '[' << (int(color) + 30) << "m";
		textColor = color;
	}
	void Console::SetStyle(Style style)
	{
		std::cout << esc << '[' << int(style) << "m";
	}
	void Console::InverseColor()
	{
		Color pr = textColor;
		textColor = backgroundColor;
		backgroundColor = pr;
		SetColor(textColor);
		SetBackgroundColor(backgroundColor);
	}
	void Console::ResetColors()
	{
		std::cout << esc << "[0m";
		textColor = Color::White;
		backgroundColor = Color::Black;
	}
	Color Console::GetColor()
	{
		return textColor;
	}
	Color Console::GetBackgroundColor()
	{
		return backgroundColor;
	}

	void Console::SetCursorPosition(unsigned int x, unsigned int y)
	{
		std::cout << esc << '[' << y << ";" << x << "H";
	}

	void Console::Clear()
	{
		std::cout << esc << "[2J" << esc << "[H";
	}
	void Console::ClearNextString()
	{
		std::cout << esc << "[K";
	}
	void Console::ClearUpChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << esc << "[A";
	}
	void Console::ClearDownChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << esc << "[B";
	}
	void Console::ClearRightChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << esc << "[C";
	}
	void Console::ClearLeftChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << esc << "[D";
	}

	void Console::Pause()
	{
		(void)_getch();
	}

	void Console::CursorHide()
	{
		std::cout << esc << "[?25l";
	}
	void Console::CursorShow()
	{
		std::cout << esc << "[?25h";
	}
	bool Console::CursorVisible()
	{
		return cursorVisible;
	}

	void Console::ToBeginGorizontLine()
	{
		std::cout << esc << "[G";
	}

	std::string Console::RusEdit(std::string txt)
	{
		for (size_t i = 0; i < txt.size(); i++)
			txt[i] = RusEdit(txt[i]);
		return txt;
	}
	std::string Console::RusEdit(const char* txt)
	{
		return RusEdit(std::string(txt));
	}
	char* Console::RusEdit(char* txt)
	{
		size_t size = std::strlen(txt);
		for (size_t i = 0; i < size; i++)
			txt[i] = RusEdit(txt[i]);
		return txt;
	}
	char Console::RusEdit(char c)
	{
		if (c >= 'À' && c <= 'ï')
			c -= 64;
		else if (c >= 'ð' && c <= 'ÿ')
			c -= 16;
		else if (c == '¨')
			c = -16;
		else if (c == '¸')
			c = -15;
		return c;
	}
#if defined(_WIN32) || defined(_WIN64)
	void Console::SetEncoding(unsigned code)
	{
		std::string res = "chcp " + std::to_string(code) + " > nul";
		system(res.c_str());
	}
#else
	void Console::SetEncoding(unsigned code)
	{
		std::string res = "setterm -encoding CP" + std::to_string(code) + " > /dev/null";
		system(res.c_str());
	}
#endif
	
	#pragma endregion
}