// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"

#include "Kismet/KismetMathLibrary.h"
#include "Components/WidgetComponent.h"
#include "MyHpBar.h"
#include "MyStatComponent.h"

AMyEnemy::AMyEnemy()
{

	PrimaryActorTick.bCanEverTick = true;

	_hpBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBar"));
	_hpBarWidget->SetupAttachment(GetMesh());
	_hpBarWidget->SetWidgetSpace(EWidgetSpace::World);
	static ConstructorHelpers::FClassFinder<UMyHpBar> hpBar(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/BP_MyHpBar.BP_MyHpBar_C'"));
	if (hpBar.Succeeded())
	{
		_hpBarWidget->SetWidgetClass(hpBar.Class);
	}


}

void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();

	auto hpBar = Cast<UMyHpBar>(_hpBarWidget->GetWidget());
	if (hpBar)
	{
		_statComponent->_hpChanged.AddUObject(hpBar, &UMyHpBar::SetHpBarValue);

	}
}

void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto playerCameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	if (playerCameraManager)
	{
		//카메라 가져오는법.


		FRotator rot = UKismetMathLibrary::FindLookAtRotation(_hpBarWidget->GetComponentLocation(), playerCameraManager->GetCameraLocation());

		_hpBarWidget->SetWorldRotation(rot);

	}

}

void AMyEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}
