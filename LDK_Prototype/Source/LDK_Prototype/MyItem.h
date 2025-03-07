// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"



UENUM()
enum class MyItemType
{
	NONE,
	POTION
};


USTRUCT(BlueprintType)
struct FMyItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemID=-1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	MyItemType type=MyItemType::NONE;


};


UCLASS()
class LDK_PROTOTYPE_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Rotate(float DeltaTime);

	void Move(float DeltaTime);

	UFUNCTION()
	void OnlyCharacterOverlap( class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);

	virtual void ItemEffect(class AMyCharacter* user);

	const FMyItemInfo& GetInfo() { return _info; }

	void GetItem();
	void DropItem();
	void FindGround();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
	FMyItemInfo _info;

private:

	UPROPERTY(VisibleAnywhere, Category = "Loc")
	USceneComponent* _locationMarker;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* _mesh;

	UPROPERTY(VisibleAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;


	FVector _defaultLoc;
	float time=0;

	float _sinMove = 50.0f;
	float _defaultY = 100.0f;



};
