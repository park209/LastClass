#include "ClassMenuAction.h"
#include "LastClass.h"
#include "ClassDiagramForm.h"
#include "MouseLButton.h"
ClassMenuAction::ClassMenuAction() {
}
ClassMenuAction::~ClassMenuAction() {
}
void ClassMenuAction::MenuPress(LastClass* lastClass) {
	lastClass->classDiagramForm->mouseLButton->ChangeState(49);
}