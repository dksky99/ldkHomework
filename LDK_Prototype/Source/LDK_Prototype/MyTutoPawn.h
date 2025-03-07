// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTutoPawn.generated.h"





class UInputAction;

struct FInputActionValue;

UCLASS()
class LDK_PROTOTYPE_API AMyTutoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTutoPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//입력관련해서 바인드를 설정하는 함수
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Revolution_Rotation(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void Temp();

	void UpDown(float value);
	void RightLeft(float value);
	

	void Move(const FInputActionValue& value);

private:

	UPROPERTY()
	USceneComponent* _locationMarker;
	UPROPERTY(VisibleAnywhere,Category="Mesh")
	UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere,Category="Speed")
	float _moveSpeed = 100;
	UPROPERTY(EditAnywhere,Category="Speed")
	float _rotSpeed = 10;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input",meta=(AllowPrivateAccess="true"))
	UInputAction* _moveAction;



};
