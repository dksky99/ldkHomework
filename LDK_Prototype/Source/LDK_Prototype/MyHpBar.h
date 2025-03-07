// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHpBar.generated.h"

/**
 * 
 */
UCLASS()
class LDK_PROTOTYPE_API UMyHpBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetHpBarValue(float ratio);
	void NativeTick(const struct FGeometry& myGeometry, float InDeltaTime);


private:
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_hpBar;



};
