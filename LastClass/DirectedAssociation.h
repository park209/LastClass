#pragma once

//DirectedAssociation.h
// ��������

#ifndef _DIRECTEDASSOCIATION_H
#define _DIRECTEDASSOCIATION_H

#include "Relation.h"
#include "DrawingVisitor.h"

typedef signed long int Long;

class DirectedAssociation : public Relation {
public:
	DirectedAssociation();
	DirectedAssociation(Long x, Long y, Long width, Long height);
	DirectedAssociation(const DirectedAssociation& source);
	virtual ~DirectedAssociation();

	DirectedAssociation& operator = (const DirectedAssociation&  source);
	void Accept(Visitor& visitor, CDC *cPaintDc);
	Figure* Clone() const;

};
#endif // _DIRECTEDASSOCIATION_H