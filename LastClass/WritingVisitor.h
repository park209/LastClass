#pragma once

//WritingVisitor.h

#ifndef _WRITINGVISITOR_H
#define _WRITINGVISITOR_H

#include "Visitor.h"

class SingleByteCharacter;
class DoubleByteCharacter;

class WritingVisitor : public Visitor {
public:
	WritingVisitor();
	~WritingVisitor();

	void Visit(Line *line, CDC* cPaintDc);
	void Visit(Class *object, CDC* cPaintDc);
	void Visit(SingleByteCharacter *singleByteCharacter, CDC* cPaintDc);
	void Visit(DoubleByteCharacter *doubleByteCharacter, CDC* cPaintDc);


	 void Visit(Generalization *generalization, CDC* cPaintDc) ;		//일반화

     void Visit(Realization * realization, CDC* cPaintDc);		//실체화

	 void Visit(Dependency *dependency, CDC* cPaintDc) ;		//의존

	 void Visit(Association *association, CDC* cPaintDc) ;		//연관화  , CDC* cPaintDc

	 void Visit(DirectedAssociation *directedAssociation, CDC* cPaintDc) ;		//직접연관

	 void Visit(Aggregation *aggregation, CDC* cPaintDc);		//집합

	 void Visit(Aggregations *aggregations, CDC* cPaintDc) ;		//집합연관

	 void Visit(Composition *composition, CDC* cPaintDc) ;		//합성

	 void Visit(Compositions *compositions, CDC* cPaintDc) ;		//복합연관

	 void Visit(Template *object, CDC *cPaintDc);

	 void Visit(MemoBox *memoBox, CDC *cPaintDc);

	   // CDC  *cPaintDc
};

#endif // _WRITINGVISITOR_H