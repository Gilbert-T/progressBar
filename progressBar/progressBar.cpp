#include "progressBar.h"
progressBar::progressBar() :persentage_(0), width_(80){

}
progressBar::progressBar(const float percentage, const width_type width) : persentage_(percentage), width_(width) {

}
progressBar::progressBar(const progressBar& rhs) : persentage_(rhs.persentage_), width_(rhs.width_) {

}
progressBar& progressBar::operator=(const progressBar& rhs) {
	persentage_ = rhs.persentage_;
	width_ = rhs.width_;
	return *this;
}
progressBar& progressBar::operator=(const float percentage) {
	persentage_ = percentage;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const progressBar &pb) {
	const int  n = pb.persentage_ / 100 * pb.width_ ;
	//std::cout << "n = " << n << std::endl;
	std::string bar = std::string(n, '=');
	//std::cout << "bar " << bar << std::endl;
	std::string space = std::string(pb.width_ - n, ' ');
	os << "\r" <<"[" << bar << ">" <<  space << "]" << std::flush;
	os << std::setw(7) << std::setprecision(3) << pb.persentage_ << "%" << std::flush;
	return os;
}
progressBar& progressBar::operator++() {
	persentage_++;
	return *this;
}
progressBar progressBar::operator++(int) {
	progressBar temp(*this);
	persentage_++;
	return temp;
}
progressBar& progressBar::operator+=(const float num) {
	persentage_ += num;
	return *this;
}
progressBar& progressBar::operator+(const float num) {
	*this += num;
	return *this;
}
bool progressBar::operator==(const progressBar& rhs) {
	return persentage_ == rhs.persentage_ && width_ == rhs.width_;
}
bool progressBar::operator==(const float num) {
	return persentage_ == num ;
}