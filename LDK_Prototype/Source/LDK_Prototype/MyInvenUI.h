// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInvenUI.generated.h"




/**
 * 
 */


DECLARE_DELEGATE_RetVal_OneParam(FMyItemInfo,FGetItemInfo, int32);

UCLASS()
class LDK_PROTOTYPE_API UMyInvenUI : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual bool Initialize() override;

	void SetItem_Index(int32 index, FMyItemInfo item);

	UFUNCTION()
	void SetTextBox();



	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* Grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* Drop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UButton*> _slotButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UImage*> _slotImages;

	FGetItemInfo _getInfo;



	UPROPERTY()
	UTexture2D* _potionTexture;
	UPROPERTY()
	UTexture2D* _defaultTexture;

	

	int32 _curIndex = -1;


private:



};
