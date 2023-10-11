#pragma once

#include<string>

namespace Sys
{
	class Convert
	{
	public:

		#pragma region ToString()

		static std::string ToString(unsigned long long int val);
		static std::string ToString(unsigned long int val);
		static std::string ToString(unsigned int val);
		static std::string ToString(unsigned short val);
		static std::string ToString(long long int val);
		static std::string ToString(long int val);
		static std::string ToString(int val);
		static std::string ToString(short val);
		static std::string ToString(bool val);

		static std::string ToString(float val);
		static std::string ToString(double val);
		static std::string ToString(long double val);

		static std::string ToString(char val);
		static std::string ToString(unsigned char val);
		static std::string ToString(wchar_t val);
		static std::string ToString(char16_t val);
		static std::string ToString(char32_t val);
		static std::string ToString(const std::wstring& val);
		static std::string ToString(const std::u16string& val);
		static std::string ToString(const std::u32string& val);

		#pragma endregion

		#pragma region ToWString()

		static std::wstring ToWString(unsigned long long int val);
		static std::wstring ToWString(unsigned long int val);
		static std::wstring ToWString(unsigned int val);
		static std::wstring ToWString(unsigned short val);
		static std::wstring ToWString(long long int val);
		static std::wstring ToWString(long int val);
		static std::wstring ToWString(int val);
		static std::wstring ToWString(short val);
		static std::wstring ToWString(bool val);

		static std::wstring ToWString(float val);
		static std::wstring ToWString(double val);
		static std::wstring ToWString(long double val);

		static std::wstring ToWString(char val);
		static std::wstring ToWString(unsigned char val);
		static std::wstring ToWString(wchar_t val);
		static std::wstring ToWString(char16_t val);
		static std::wstring ToWString(char32_t val);
		static std::wstring ToWString(const std::string& val);
		static std::wstring ToWString(const std::u16string& val);
		static std::wstring ToWString(const std::u32string& val);

		#pragma endregion

		#pragma region ToU16String()

		static std::u16string ToU16String(unsigned long long int val);
		static std::u16string ToU16String(unsigned long int val);
		static std::u16string ToU16String(unsigned int val);
		static std::u16string ToU16String(unsigned short val);
		static std::u16string ToU16String(long long int val);
		static std::u16string ToU16String(long int val);
		static std::u16string ToU16String(int val);
		static std::u16string ToU16String(short val);
		static std::u16string ToU16String(bool val);

		static std::u16string ToU16String(float val);
		static std::u16string ToU16String(double val);
		static std::u16string ToU16String(long double val);

		static std::u16string ToU16String(char val);
		static std::u16string ToU16String(unsigned char val);
		static std::u16string ToU16String(wchar_t val);
		static std::u16string ToU16String(char16_t val);
		static std::u16string ToU16String(char32_t val);
		static std::u16string ToU16String(const std::string& val);
		static std::u16string ToU16String(const std::wstring& val);
		static std::u16string ToU16String(const std::u32string& val);

		#pragma endregion

		#pragma region ToU32String()

		static std::u32string ToU32String(unsigned long long int val);
		static std::u32string ToU32String(unsigned long int val);
		static std::u32string ToU32String(unsigned int val);
		static std::u32string ToU32String(unsigned short val);
		static std::u32string ToU32String(long long int val);
		static std::u32string ToU32String(long int val);
		static std::u32string ToU32String(int val);
		static std::u32string ToU32String(short val);
		static std::u32string ToU32String(bool val);

		static std::u32string ToU32String(float val);
		static std::u32string ToU32String(double val);
		static std::u32string ToU32String(long double val);

		static std::u32string ToU32String(char val);
		static std::u32string ToU32String(unsigned char val);
		static std::u32string ToU32String(wchar_t val);
		static std::u32string ToU32String(char16_t val);
		static std::u32string ToU32String(char32_t val);
		static std::u32string ToU32String(const std::string& val);
		static std::u32string ToU32String(const std::wstring& val);
		static std::u32string ToU32String(const std::u16string& val);

		#pragma endregion

		#pragma region ToULLong()

		static unsigned long long int ToULLong(const std::string& val);
		static unsigned long long int ToULLong(const std::wstring& val);
		static unsigned long long int ToULLong(const std::u16string& val);
		static unsigned long long int ToULLong(const std::u32string& val);

		#pragma endregion

		#pragma region ToLLong()

		static long long int ToLLong(const std::string& val);
		static long long int ToLLong(const std::wstring& val);
		static long long int ToLLong(const std::u16string& val);
		static long long int ToLLong(const std::u32string& val);

		#pragma endregion

		#pragma region ToLDouble()

		static long double ToLDouble(const std::string& val);
		static long double ToLDouble(const std::wstring& val);
		static long double ToLDouble(const std::u16string& val);
		static long double ToLDouble(const std::u32string& val);

		#pragma endregion

	private:
	};
}