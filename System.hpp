#pragma once

#include <string>
#include <iostream>
#include <conio.h>

namespace Sys
{
	enum OS : unsigned short
	{
		Unknown,
		Linux,
		MacOS,
		Windows,
		Android
	};
	enum Color : unsigned short
	{
		Black = 0,
		Red,
		Green,
		Yellow,
		Blue,
		Purple,
		Cyan,
		White,
		Default = 9
	};
	enum Style : unsigned short
	{
		Defualt = 0,
		Bold = 1,
		Italic = 3,
		Underlined = 4,
		Hidden = 8,
		Strikethrough = 9
	};

#if defined(_WIN32) || defined(_WIN64)
	constexpr const OS os = Sys::OS::Windows;
#elif defined(__APPLE__)
	constexpr const OS os = OS::MacOS;
#elif defined(__linux__)
	constexpr const OS os = OS::Linux;
#elif defined(__ANDROID__)
	constexpr const OS os = OS::Android;
#else
	constexpr const OS os = OS::Unknown;
#endif

	class Console {
	public:
		#pragma region Write Read
		static void Write(wchar_t arg);
		static void Write(const wchar_t* arg);
		static void Write(const std::wstring& arg);
		template<typename Type>
		static void Write(Type arg)
		{
			std::cout << arg;
		}
		template<typename First, typename ... Types>
		static void Write(First arg, Types ... args)
		{
			Write(arg);
			Write(args...);
		}

		template<typename ... Types>
		static void WriteLine(const Types& ... args)
		{
			Write(args ...);
			std::cout << std::endl;
		}
		static void WriteLine();

		template<typename ... Types>
		static std::string ReadLine(const Types& ... args)
		{
			Write(args...);
			std::string res;
			std::getline(std::cin, res);
			return res;
		}
		static std::string ReadLine();

		template<typename ... Types>
		static int Read(const Types& ... args)
		{
			Write(args...);
			return _getch();
		}
		static int Read();

		#pragma endregion

		#pragma region Color

		static void SetBackgroundColor(Color color);
		static void SetColor(Color color);
		static void SetStyle(Style style);
		static void InverseColor();
		static void ResetColors();
		static Color GetColor();
		static Color GetBackgroundColor();

		#pragma endregion

		static void SetCursorPosition(unsigned int x, unsigned int y);

		#pragma region Clear

		static void Clear();
		static void ClearNextString();
		static void ClearUpChar(unsigned count = 1);
		static void ClearDownChar(unsigned count = 1);
		static void ClearRightChar(unsigned count = 1);
		static void ClearLeftChar(unsigned count = 1);

		#pragma endregion

		template<typename ... Types>
		static void Pause(const Types& ... args)
		{
			Write(args...);
			(void)_getch();
		}
		static void Pause();

		static void CursorHide();
		static void CursorShow();
		static bool CursorVisible();

		static void ToBeginGorizontLine();

		static std::string RusEdit(std::string txt);
		static std::string RusEdit(const char* txt);
		static char RusEdit(char c);
		static char* RusEdit(char* txt);

		static void SetEncoding(unsigned code);
	private:
		static Color textColor;
		static Color backgroundColor;
		static bool cursorVisible;
	};
}