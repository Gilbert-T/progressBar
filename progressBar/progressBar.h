#pragma once
#include <iostream>
#include <iomanip>
class progressBar
{	
public:
	friend std::ostream& operator << (std::ostream& os, const progressBar& pb);
	using width_type = int;
	progressBar();
	progressBar(const float persentage, const width_type width = 80);
	progressBar(const progressBar& rhs);
	~progressBar() = default;
	
	progressBar& operator++();
	progressBar operator++(int);
	progressBar& operator+=(const float num);
	progressBar& operator+(const float num);
	bool operator==(const progressBar &rhs);
	bool operator==(const float flaot);
private:	
	float persentage_;	
	width_type width_;

};

