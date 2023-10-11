#include "Convert.hpp"

#include <locale>
#include <codecvt>
#include <limits>
#include <cmath>
#include <exception>

std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converterW;
std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converterU16;
std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converterU32;

namespace Sys
{
	#pragma region ToString()

	std::string Convert::ToString(unsigned long long int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(unsigned long int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(unsigned int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(unsigned short val)
	{
		return std::to_string(static_cast<int>(val));
	}
	std::string Convert::ToString(long long int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(long int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(int val)
	{
		return std::to_string(val);
	}
	std::string Convert::ToString(short val)
	{
		return std::to_string(static_cast<int>(val));
	}
	std::string Convert::ToString(bool val)
	{
		return (val) ? ("1") : ("0");
	}

	std::string Convert::ToString(float val)
	{
		std::string res = std::to_string(val);
		res = res.erase(res.size() - 7);
		float pr; 
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<float>::digits10)));
		if (pr != 0)
			res += '.' + std::to_string(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri+1);
	}
	std::string Convert::ToString(double val)
	{
		std::string res = std::to_string(val);
		res = res.erase(res.size() - 7);
		double pr;
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<double>::digits10)));
		if (pr != 0)
			res += '.' + std::to_string(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri + 1);
	}
	std::string Convert::ToString(long double val)
	{
		std::string res = std::to_string(val);
		res = res.erase(res.size() - 7);
		long double pr;
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<long double>::digits10)));
		if (pr != 0)
			res += '.' + std::to_string(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri + 1);
	}

	std::string Convert::ToString(char val)
	{
		return std::string(1, val);
	}
	std::string Convert::ToString(unsigned char val)
	{
		return std::string(1, val);
	}
	std::string Convert::ToString(wchar_t val)
	{
		return converterW.to_bytes(val);
	}
	std::string Convert::ToString(char16_t val)
	{
		return converterU16.to_bytes(val);
	}
	std::string Convert::ToString(char32_t val)
	{
		return converterU32.to_bytes(val);
	}
	std::string Convert::ToString(const std::wstring& val)
	{
		return converterW.to_bytes(val);
	}
	std::string Convert::ToString(const std::u16string& val)
	{
		return converterU16.to_bytes(val);
	}
	std::string Convert::ToString(const std::u32string& val)
	{
		return converterU32.to_bytes(val);
	}

	#pragma endregion

	#pragma region ToWString()

	std::wstring Convert::ToWString(unsigned long long int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(unsigned long int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(unsigned int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(unsigned short val)
	{
		return std::to_wstring(static_cast<int>(val));
	}
	std::wstring Convert::ToWString(long long int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(long int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(int val)
	{
		return std::to_wstring(val);
	}
	std::wstring Convert::ToWString(short val)
	{
		return std::to_wstring(static_cast<int>(val));
	}
	std::wstring Convert::ToWString(bool val)
	{
		return (val) ? (L"1") : (L"0");
	}

	std::wstring Convert::ToWString(float val)
	{
		std::wstring res = std::to_wstring(val);
		res = res.erase(res.size() - 7);
		float pr;
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<float>::digits10)));
		if (pr != 0)
			res += L'.' + std::to_wstring(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri + 1);
	}
	std::wstring Convert::ToWString(double val)
	{
		std::wstring res = std::to_wstring(val);
		res = res.erase(res.size() - 7);
		double pr;
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<double>::digits10)));
		if (pr != 0)
			res += L'.' + std::to_wstring(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri + 1);
	}
	std::wstring Convert::ToWString(long double val)
	{
		std::wstring res = std::to_wstring(val);
		res = res.erase(res.size() - 7);
		long double pr;
		long long pri;
		pri = static_cast<long long>(abs(modf(val, &pr) * pow(10, std::numeric_limits<long double>::digits10)));
		if (pr != 0)
			res += L'.' + std::to_wstring(pri);
		for (pri = res.size() - 1; res[pri] == '0'; pri--) {}
		return res.erase(pri + 1);
	}

	std::wstring Convert::ToWString(char val)
	{
		return converterW.from_bytes(val);
	}
	std::wstring Convert::ToWString(unsigned char val)
	{
		return converterW.from_bytes(val);
	}
	std::wstring Convert::ToWString(wchar_t val)
	{
		return std::wstring(1, val);
	}
	std::wstring Convert::ToWString(char16_t val)
	{
		std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10FFFF, std::little_endian>, wchar_t> converter;
		std::wstring wideStr = converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
		return wideStr;
	}
	std::wstring Convert::ToWString(char32_t val)
	{
		std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10FFFF, std::little_endian>, wchar_t> converter;
		std::wstring wideStr = converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
		return wideStr;
	}
	std::wstring Convert::ToWString(const std::string& val)
	{
		return converterW.from_bytes(val);
	}
	std::wstring Convert::ToWString(const std::u16string& val)
	{
		std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10FFFF, std::little_endian>, wchar_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}
	std::wstring Convert::ToWString(const std::u32string& val)
	{
		std::wstring_convert<std::codecvt_utf16<wchar_t, 0x10FFFF, std::little_endian>, wchar_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}

	#pragma endregion

	#pragma region ToU16String()

	std::u16string Convert::ToU16String(unsigned long long int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(unsigned long int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(unsigned int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(unsigned short val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(long long int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(long int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(int val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(short val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(bool val)
	{
		return (val) ? (u"1") : (u"0");
	}

	std::u16string Convert::ToU16String(float val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(double val)
	{
		return ToU16String(ToString(val));
	}
	std::u16string Convert::ToU16String(long double val)
	{
		return ToU16String(ToString(val));
	}

	std::u16string Convert::ToU16String(char val)
	{
		return converterU16.from_bytes(val);
	}
	std::u16string Convert::ToU16String(unsigned char val)
	{
		return converterU16.from_bytes(val);
	}
	std::u16string Convert::ToU16String(wchar_t val)
	{
		std::wstring_convert<std::codecvt_utf16<char16_t, 0x10FFFF, std::little_endian>, char16_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
	}
	std::u16string Convert::ToU16String(char16_t val)
	{
		return std::u16string(1, val);
	}
	std::u16string Convert::ToU16String(char32_t val)
	{
		std::wstring_convert<std::codecvt_utf16<char16_t, 0x10FFFF, std::little_endian>, char16_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
	}
	std::u16string Convert::ToU16String(const std::string& val)
	{
		return converterU16.from_bytes(val);
	}
	std::u16string Convert::ToU16String(const std::wstring& val)
	{
		std::wstring_convert<std::codecvt_utf16<char16_t, 0x10FFFF, std::little_endian>, char16_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}
	std::u16string Convert::ToU16String(const std::u32string& val)
	{
		std::wstring_convert<std::codecvt_utf16<char16_t, 0x10FFFF, std::little_endian>, char16_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}

	#pragma endregion

	#pragma region ToU16String()

	std::u32string Convert::ToU32String(unsigned long long int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(unsigned long int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(unsigned int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(unsigned short val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(long long int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(long int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(int val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(short val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(bool val)
	{
		return (val) ? (U"1") : (U"0");
	}

	std::u32string Convert::ToU32String(float val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(double val)
	{
		return ToU32String(ToString(val));
	}
	std::u32string Convert::ToU32String(long double val)
	{
		return ToU32String(ToString(val));
	}

	std::u32string Convert::ToU32String(char val)
	{
		return converterU32.from_bytes(val);
	}
	std::u32string Convert::ToU32String(unsigned char val)
	{
		return converterU32.from_bytes(val);
	}
	std::u32string Convert::ToU32String(wchar_t val)
	{
		std::wstring_convert<std::codecvt_utf16<char32_t, 0x10FFFF, std::little_endian>, char32_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
	}
	std::u32string Convert::ToU32String(char16_t val)
	{
		std::wstring_convert<std::codecvt_utf16<char32_t, 0x10FFFF, std::little_endian>, char32_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(&val),
			reinterpret_cast<const char*>(&val + 1));
	}
	std::u32string Convert::ToU32String(char32_t val)
	{
		return std::u32string(1, val);
	}
	std::u32string Convert::ToU32String(const std::string& val)
	{
		return converterU32.from_bytes(val);
	}
	std::u32string Convert::ToU32String(const std::wstring& val)
	{
		std::wstring_convert<std::codecvt_utf16<char32_t, 0x10FFFF, std::little_endian>, char32_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}
	std::u32string Convert::ToU32String(const std::u16string& val)
	{
		std::wstring_convert<std::codecvt_utf16<char32_t, 0x10FFFF, std::little_endian>, char32_t> converter;
		return converter.from_bytes(reinterpret_cast<const char*>(val.c_str()),
			reinterpret_cast<const char*>(val.c_str() + val.length()));
	}

	#pragma endregion

	#pragma region ToULLong()

	unsigned long long int Convert::ToULLong(const std::string& val)
	{
		unsigned long long res;
		try
		{
			res = std::stoull(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	unsigned long long int Convert::ToULLong(const std::wstring& val)
	{
		unsigned long long res;
		try
		{
			res = std::stoull(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	unsigned long long int Convert::ToULLong(const std::u16string& val)
	{
		unsigned long long res;
		try
		{
			res = std::stoull(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	unsigned long long int Convert::ToULLong(const std::u32string& val)
	{
		unsigned long long res;
		try
		{
			res = std::stoull(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}

	#pragma endregion

	#pragma region ToLLong()

	long long int Convert::ToLLong(const std::string& val)
	{
		long long int res;
		try
		{
			res = std::stoll(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long long int Convert::ToLLong(const std::wstring& val)
	{
		long long int res;
		try
		{
			res = std::stoll(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long long int Convert::ToLLong(const std::u16string& val)
	{
		long long int res;
		try
		{
			res = std::stoll(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long long int Convert::ToLLong(const std::u32string& val)
	{
		long long int res;
		try
		{
			res = std::stoll(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}

	#pragma endregion

	#pragma region ToLDouble()

	long double Convert::ToLDouble(const std::string& val)
	{
		long double res;
		try
		{
			res = std::stold(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long double Convert::ToLDouble(const std::wstring& val)
	{
		long double res;
		try
		{
			res = std::stold(val);
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long double Convert::ToLDouble(const std::u16string& val)
	{
		long double res;
		try
		{
			res = std::stold(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}
	long double Convert::ToLDouble(const std::u32string& val)
	{
		long double res;
		try
		{
			res = std::stold(ToString(val));
		}
		catch (const std::exception& e)
		{
			res = 0;
		}
		return res;
	}

	#pragma endregion

}