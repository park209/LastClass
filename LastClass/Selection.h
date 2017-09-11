#ifndef _SELECTION_H
#define _SELECTION_H
#include "FigureComposite.h"

class CRect;
class Diagram;
class Selection : public  FigureComposite{
public: 
	Selection(Long capacity = 256);
	Selection(const Selection& source);
	virtual ~Selection();
	Selection& operator = (const Selection& source);

	virtual Long Remove(Long index);
	virtual Long Add(Figure *figure);
	virtual Figure* GetAt(Long index);
	virtual Figure* Clone() const;
	void DeleteAllItems();

	void FindByArea(Diagram *diagram, CRect area);
	void FindByPoint(Diagram *diagram, Long x, Long y);


};

#endif // !_SELECTION_H
