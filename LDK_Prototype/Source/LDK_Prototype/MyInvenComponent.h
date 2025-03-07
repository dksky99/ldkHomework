// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItem.h"
#include "MyInvenComponent.generated.h"


DECLARE_MULTICAST_DELEGATE_TwoParams(FItemChange, int32, FMyItemInfo);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LDK_PROTOTYPE_API UMyInvenComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyInvenComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem( AMyItem* item);
	AMyItem* DropItem();
	AMyItem* DropItem(int32 index);
	void DropAllItem();

	FItemChange _itemChangeEvent;

	FMyItemInfo GetItemInfo_Index(int32 index);

private:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	TArray< AMyItem*> _items;


};
