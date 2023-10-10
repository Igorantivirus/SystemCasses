#include "System.hpp"

#include <cstdlib>

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

	void Console::SetBackgroundColor(Color color)
	{
		std::cout << "\x1b[" << (color + 40) << "m";
		backgroundColor = color;
	}
	void Console::SetColor(Color color)
	{
		std::cout << "\x1b[" << (color + 30) << "m";
		textColor = color;
	}
	void Console::SetStyle(Style style)
	{
		std::cout << "\x1b[" << style << "m";
	}
	void Console::InverseColor()
	{//std::cout << "\x1b[7m";
		Color pr = textColor;
		textColor = backgroundColor;
		backgroundColor = pr;
		SetColor(textColor);
		SetBackgroundColor(backgroundColor);
	}
	void Console::ResetColors()
	{
		std::cout << "\x1b[0m";
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
		std::cout << "\x1b[" << y << ";" << x << "H";
	}

	void Console::Clear()
	{
		std::cout << "\x1b[2J\x1b[H";
	}
	void Console::ClearNextString()
	{
		std::cout << "\x1b[K";
	}
	void Console::ClearUpChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << "\x1b[A";
	}
	void Console::ClearDownChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << "\x1b[B";
	}
	void Console::ClearRightChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << "\x1b[C";
	}
	void Console::ClearLeftChar(unsigned count)
	{
		for (unsigned i = 0; i < count; i++)
			std::cout << "\x1b[D";
	}

	void Console::Pause()
	{
		(void)_getch();
	}

	void Console::CursorHide()
	{
		std::cout << "\x1b[?25l";
	}
	void Console::CursorShow()
	{
		std::cout << "\x1b[?25h";
	}
	bool Console::CursorVisible()
	{
		return cursorVisible;
	}

	void Console::ToBeginGorizontLine()
	{
		std::cout << "\x1b[G";
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

	void Console::SetEncoding(unsigned code)
	{
		std::string res = "chcp " + std::to_string(code) + " > nul";
		system(res.c_str());
	}
	#pragma endregion
}