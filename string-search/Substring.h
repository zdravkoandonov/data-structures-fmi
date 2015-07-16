#pragma once
struct Substring
{
	static const int DEFAULT_VAL = -2;
	int begin, end;
	Substring(int begin = DEFAULT_VAL, int end = DEFAULT_VAL) : begin(begin), end(end)
	{
	}

	~Substring()
	{
	}
};

