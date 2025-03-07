// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInvenUI.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MyButton.h"
#include "MyItem.h"
#include "MyInvenComponent.h"

bool UMyInvenUI::Initialize()
{

	Super::Initialize();

	auto array=Grid->GetAllChildren();

	for (auto widget : array)
	{
		auto btn = Cast<UMyButton>(widget);
		auto img = Cast<UImage>(btn->GetChildAt(0));
		if (btn&&img)
		{
			btn->widget = this;
			btn->_curIndex = _slotButton.Num();
			btn->OnClicked.AddDynamic(btn, &UMyButton::SetCurIndex);
			btn->OnClicked.AddDynamic(this, &UMyInvenUI::SetTextBox);

			_slotButton.Add(btn);
			
			_slotImages.Add(img);
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Image Size : %d"), _slotImages.Num());

	_potionTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_seeds_06.Tex_seeds_06'"));
	_defaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_Default.Tex_Default'"));

	return true;
}

void UMyInvenUI::SetItem_Index(int32 index, FMyItemInfo item)
{
	FMyItemInfo temp;

	if (item.itemID == temp.itemID && item.type ==temp.type)
		_slotImages[index]->SetBrushFromTexture(_defaultTexture);
	else if(item.itemID==0&&item.type==MyItemType::POTION)
		_slotImages[index]->SetBrushFromTexture(_potionTexture);
}

void UMyInvenUI::SetTextBox()
{
	if (_getInfo.IsBound()== false)
		return;
	FMyItemInfo temp = _getInfo.Execute(_curIndex);
	FString str = "";

	if (temp.itemID == -1)
	{
		ItemInfo->SetText(FText::FromString(TEXT("ItemType : None \n ItemID : -1")));
	}
	else
	{
		UEnum* EnumPtr = StaticEnum<MyItemType>();
		FString TypeString = EnumPtr ? EnumPtr->GetNameStringByIndex((int32)temp.type) : TEXT("Unknown");

		str = FString::Printf(TEXT("ItemType : %s \nItemID : %d"), *TypeString,temp.itemID);
		FName fn(*str);
		ItemInfo->SetText(FText::FromName(fn));

	}


}
