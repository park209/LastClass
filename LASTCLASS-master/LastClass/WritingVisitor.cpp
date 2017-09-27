//WritingVIsitor.cpp

#include "WritingVisitor.h"
#include "Text.h"
#include "MemoBox.h"
#include "ClassName.h"
#include "Attribute.h"
#include "Method.h"
#include "Reception.h"
#include "Template.h"

#include <afxwin.h>

WritingVisitor::WritingVisitor() {
}
WritingVisitor::~WritingVisitor() {
}
void WritingVisitor::Visit(Diagram *diagram, Selection *selection, Long distanceX, Long distanceY) {
}
void WritingVisitor::Visit(Class *object, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Text* text, CDC* cPaintDc) {
	Long fontHeight = cPaintDc->GetTextExtent("아").cy; // rowHeight 구하는방법
	Long textWidth = text->MaxWidth(cPaintDc);
	CFont* cFont = cPaintDc->GetCurrentFont();

	CDC memDC;
	CBitmap *pOldBitmap;
	CBitmap bitmap;

	memDC.CreateCompatibleDC(cPaintDc);																		//MemoryDC를 만들때 dc를 포함시킨다
	bitmap.CreateCompatibleBitmap(cPaintDc, textWidth + 5, text->GetLength() * fontHeight + 5);				//dc가 호환되게 생성한다
	pOldBitmap = memDC.SelectObject(&bitmap);																//MemoryDC에 비트맵을 연결
	memDC.FillSolidRect(CRect(0, 0, textWidth + 5, text->GetLength() * fontHeight + 5), RGB(255, 255, 255));//흰색의 사각형을 준비
	memDC.SelectObject(cFont);																				//MemoryDC에 폰트를 연결
	RECT rt = { 0 , 0, textWidth + 5, text->GetLength() * fontHeight + 5 };									//사각형의 크기
	memDC.DrawText((CString)text->MakeText().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);						//MemoryDC에 적어둔다
	cPaintDc->BitBlt(5, 5, textWidth + 5, text->GetLength() * fontHeight + 5, &memDC, 0, 0, SRCCOPY);		//화면에 적어둔 MemoryDC를 출력한다

	memDC.SelectObject(pOldBitmap);
	bitmap.DeleteObject();
	memDC.SelectObject(cFont);
	cFont->DeleteObject();
	memDC.DeleteDC();
}
void WritingVisitor::Visit(MemoBox *memoBox, CDC *cPaintDc) { //접힌부분아래로 적히게
	RECT rt = { memoBox->GetX() + 5 , memoBox->GetY() + 25, memoBox->GetX() + 5 + memoBox->GetWidth(), memoBox->GetY() + 5 + memoBox->GetHeight() };
	cPaintDc->DrawText((CString)memoBox->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);
}
void WritingVisitor::Visit(Selection *selection, CDC *cPaintDc) {
}
void WritingVisitor::Visit(Template *object, CDC *cPaintDc) {
	RECT rt = { object->GetX() + 5 , object->GetY() + 5, object->GetX() + 5 + object->GetWidth(), object->GetY() + 5 + object->GetHeight() };
	cPaintDc->DrawText((CString)object->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);

}
void WritingVisitor::Visit(ClassName* className, CDC* cPaintDc) {
	RECT rt = { className->GetX() + 5 , className->GetY() + 5, className->GetX() + 5 + className->GetWidth(), className->GetY() + 5 + className->GetHeight() };
	cPaintDc->DrawText((CString)className->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);
}
void WritingVisitor::Visit(Attribute* attribute, CDC* cPaintDc) {
	RECT rt = { attribute->GetX() + 5 , attribute->GetY() + 5, attribute->GetX() + 5 + attribute->GetWidth(), attribute->GetY() + 5 + attribute->GetHeight() };
	cPaintDc->DrawText((CString)attribute->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);
}
void WritingVisitor::Visit(Method* method, CDC* cPaintDc) {
	RECT rt = { method->GetX() + 5 , method->GetY() + 5, method->GetX() + 5 + method->GetWidth(), method->GetY() + 5 + method->GetHeight() };
	cPaintDc->DrawText((CString)method->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);
}
void WritingVisitor::Visit(Reception* reception, CDC* cPaintDc) {
	RECT rt = { reception->GetX() + 5 , reception->GetY() + 5, reception->GetX() + 5 + reception->GetWidth(), reception->GetY() + 5 + reception->GetHeight() };
	cPaintDc->DrawText((CString)reception->GetContent().c_str(), &rt, DT_NOCLIP | DT_EXPANDTABS);
}
void WritingVisitor::Visit(Line *line, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Generalization *generalization, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Realization *realization, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Dependency *dependency, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Association *association, CDC* cPaintDc) {
}
void WritingVisitor::Visit(DirectedAssociation *directedAssociation, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Aggregation *aggregation, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Aggregations *aggregations, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Composition *composition, CDC* cPaintDc) {
}
void WritingVisitor::Visit(Compositions *compositions, CDC* cPaintDc) {
}
void WritingVisitor::Visit(MemoLine *memoLine, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfGeneralization *selfGeneralization, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfDependency *selfDependency, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfAggregation *selfAggregation, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfAssociation *selfAssociation, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfAggregations *selfAggregations, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfDirectedAssociation *selfDirectedAssociation, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfComposition *selfComposition, CDC *cPaintDc) {
}
void WritingVisitor::Visit(SelfCompositions *selfCompositions, CDC *cPaintDc) {
}
