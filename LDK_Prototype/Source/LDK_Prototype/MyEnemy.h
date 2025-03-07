// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "MyEnemy.generated.h"

/**
 * 
 */
UCLASS()
class LDK_PROTOTYPE_API AMyEnemy : public AMyCharacter
{
	GENERATED_BODY()
public:
	AMyEnemy();

	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* _hpBarWidget;

};
