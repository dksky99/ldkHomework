#include "MyButton.h"

#include"MyInvenUI.h"


void UMyButton::SetCurIndex()
{
	widget->_curIndex = _curIndex;
	UE_LOG(LogTemp, Error, TEXT("CurIndex : %d"), _curIndex);
}
