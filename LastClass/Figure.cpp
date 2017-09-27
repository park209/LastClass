//Figure.cpp

#include "Figure.h"
#include "Relation.h"

Figure::Figure() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->content = "";
	this->stringHeight = 18; // 현재 글자 크기에 따라서 값을 줘야하나
	this->stringWidth = 0;
}

Figure::Figure(Long x, Long y, Long width, Long height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->content = "";
	this->stringHeight = 18;
	this->stringWidth = 0;
}

Figure::Figure(Long x, Long y, Long width, Long height, string content) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->content = content;
	this->stringHeight = 18; // 입력받을 문자열에 맞게 값 줘야하는데
	this->stringWidth = 0;
}

Figure::Figure(const Figure& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->stringHeight = source.stringHeight;
	this->stringWidth = source.stringWidth;
}
Figure* Figure::Move(Long distanceX, Long distanceY) {
	this->x = this->x + distanceX;
	this->y = this->y + distanceY;
	if (dynamic_cast<Relation*>(this)) {
		this->width = this->width - distanceX;
		this->height = this->height - distanceY;
	}
	return this;
}
Figure *Figure::EndPointMove(Long distanceX, Long distanceY) {
	this->width = this->width + distanceX;
	this->height = this->height + distanceY;
	return this;
}

Figure* Figure::Modify(Long x, Long y, Long width, Long height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	return this;
}

Figure& Figure::operator = (const Figure& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->stringHeight = source.stringHeight;

	return *this;
}

Figure::~Figure() {
}


void Figure::ReplaceString(string content) {
	this->content = content;
}