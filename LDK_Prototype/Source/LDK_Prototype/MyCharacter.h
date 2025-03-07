// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UInputAction;

struct FInputActionValue;
UCLASS()
class LDK_PROTOTYPE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	void UpDown(float value);
	void RightLeft(float value);
	


	
	UFUNCTION()
	void Dead();

	UFUNCTION()
	void DeadActionEnd();
	UFUNCTION()
	void TestDelegate();

	UFUNCTION()
	int32 TestDelegate2(int32 a, int32 b);
	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage,bool bInterrupted);

	float MyVertical() { return _vertical; }
	float MyHorizontal() { return _horizontal; }

	void AttackHit();
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void AddHp(int32 value);
	void AddExp(int32 value);

protected:
	
	//자주 가져와야할 클래스. 다이나믹캐스팅은 자주하면 해롭다. 자주 사용해야할 것이라면 한번만하고 가지고있자.
	UPROPERTY()
	class UMyAnimInstance* _animInstance;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "stat", meta = (AllowPrivateAccess = "true"))
	class UMyStatComponent* _statComponent;
	

	bool _isAttack=false;
	bool _isUnable=false;

	int32 _curAttackSection = 0;

	float _vertical = 0;
	float _horizontal = 0;
	


};
