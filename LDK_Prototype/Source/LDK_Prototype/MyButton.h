// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "MyButton.generated.h"

/**
 * 
 */
UCLASS()
class LDK_PROTOTYPE_API UMyButton : public UButton
{
	GENERATED_BODY()
	

public:

	UFUNCTION()
	void SetCurIndex();

	class UMyInvenUI* widget;
	int32 _curIndex;
private:


};
