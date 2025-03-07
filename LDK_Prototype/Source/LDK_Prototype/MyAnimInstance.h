

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"


//void(void)
DECLARE_DELEGATE(HitCallBack);
DECLARE_DELEGATE(DeadCallBack);
DECLARE_DELEGATE_RetVal_TwoParams(int32,TPDTest, int32, int32);

//다이나믹 붙은애는 블루프린트에서도 볼수있다.
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDMDTest);

UCLASS()
class LDK_PROTOTYPE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();


	virtual void NativeUpdateAnimation(float DeltaSeconds);

	UFUNCTION()
	void PlayAnimMontage();
	
	void JumpToSection(int32 sectionIndex);

	UFUNCTION()
	void AnimNotify_Fire();

	UFUNCTION()
	void AnimNotify_Dead();
	UFUNCTION()
	void DeadEvent();


	HitCallBack _hitCallBack;
	DeadCallBack _deadCallBack;
	TPDTest _tpd;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn",meta=(AllowPrivateAccess="true"))
	FDMDTest _dmd;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn",meta=(AllowPrivateAccess="true"))
	float _speed=0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn",meta=(AllowPrivateAccess="true"))
	bool _isFalling=false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimMontage",meta=(AllowPrivateAccess="true"))
	class UAnimMontage* _animMontage;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	float _vertical = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	float _horizontal = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn", meta = (AllowPrivateAccess = "true"))
	bool _isDead = false;


};
