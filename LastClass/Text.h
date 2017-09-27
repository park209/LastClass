//Text.h

#ifndef _TEXT_H
#define _TEXT_H

#include "TextComposite.h"
#include <afxwin.h>
#include <string>

typedef signed long int Long;

using namespace std;

class Row;
class TextComponent;
class Visitor;
class Text : public TextComposite {
public:
	Text(Long capacity = 64);
	Text(const Text& source);
	virtual ~Text();

	Long Add(Row *row);
	virtual Long Add(TextComponent *textComponent);
	virtual Long Remove(Long index);

	string MakeText();

	virtual Long Insert(Long index, TextComponent *textComponent);
	void SprayString(string str);
	Long MaxWidth(CDC* cPaintDc);
	Row* GetAt(Long index);
	
	virtual TextComponent* Clone() const;
	void Accept(Visitor& visitor, CDC* cPaintDc);

	Text& operator = (const Text& source);
	Row* operator [] (Long index);

	Long GetWidth() const;
	Long GetHeight() const;
private:
	Long width;
	Long height;
};

inline Long Text::GetWidth() const {
	return this->width;
}
inline Long Text::GetHeight() const {
	return this->height;
}

#endif // _TEXT_H