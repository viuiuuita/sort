#pragma once
namespace utils {
	int read_int(const char* prompt, int min, int max);
	double read_double(const char* prompt, double min, double max);
	char read_char(const char* prompt);
}