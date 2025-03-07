// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


#include "Components/CapsuleComponent.h"
#include "Components/Button.h"

#include "GameFramework/SpringArmComponent.h"

#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"

#include "Engine/DamageEvents.h"

#include "MyPlayerController.h"
#include "MyAnimInstance.h"
#include "MyItem.h"
#include "Blueprint/UserWidget.h"
#include "MyInvenUI.h"


#include "MyInvenComponent.h"


AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_InvenComponent = CreateDefaultSubobject<UMyInvenComponent>(TEXT("InvenComponent"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

	
	//Inventory
	static ConstructorHelpers::FClassFinder<UMyInvenUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/BP_MyInvenUI.BP_MyInvenUI_C'"));
	if (invenClass.Succeeded())
	{

		_invenWidget = CreateWidget<UUserWidget>(GetWorld(), invenClass.Class);
	}

}

void AMyPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	auto invenUI = Cast<UMyInvenUI>(_invenWidget);
	if (invenUI)
	{
		_InvenComponent->_itemChangeEvent.AddUObject(invenUI, &UMyInvenUI::SetItem_Index);
		invenUI->Drop->OnClicked.AddDynamic(this, &AMyPlayer::Drop);
		invenUI->_getInfo.BindUObject(_InvenComponent,&UMyInvenComponent::GetItemInfo_Index);
	}
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();


}

void AMyPlayer::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhancedInputComponent)
	{
		enhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPlayer::Move);
		enhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyPlayer::Look);
		enhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &AMyPlayer::TryJump);
		enhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyPlayer::Attack);
		enhancedInputComponent->BindAction(_itemDropAction, ETriggerEvent::Triggered, this, &AMyPlayer::DropItem);
		enhancedInputComponent->BindAction(_invenAction, ETriggerEvent::Triggered, this, &AMyPlayer::InvenOpen);
	}
}


void AMyPlayer::Move(const FInputActionValue& value)
{
	if (_isAttack || _isUnable)
		return;

	FVector2D moveVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		if (moveVector.Length() > 0.01f)
		{

			UpDown(moveVector.Y);
			RightLeft(moveVector.X);

		}
	}


}

void AMyPlayer::Look(const FInputActionValue& value)
{
	FVector2D lookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(-lookAxisVector.Y);
	}

}

void AMyPlayer::TryJump(const FInputActionValue& value)
{
	if (_isUnable)
		return;
	if (value.Get<bool>())
	{
		UE_LOG(LogTemp, Log, TEXT(" Jump Test"));
		Jump();
	}

}

void AMyPlayer::Attack(const FInputActionValue& value)
{

	if (_isAttack)
		return;

	if (_isUnable)
		return;
	bool isPress = value.Get<bool>();
	if (isPress)
	{


		_isAttack = true;
		UE_LOG(LogTemp, Log, TEXT(" curAttack %d"), _curAttackSection);
		if (_animInstance)
		{

			_animInstance->PlayAnimMontage();
			_curAttackSection = (_curAttackSection + 1) % 5;
			_animInstance->JumpToSection(_curAttackSection);
		}

	}
}

void AMyPlayer::AddItem(AMyItem* item)
{
	if (item && _InvenComponent)
		_InvenComponent->AddItem(item);
	

}

void AMyPlayer::DropItem(const FInputActionValue& value)
{
	AMyItem* temp=nullptr;
	if (_InvenComponent)
		temp=_InvenComponent->DropItem();
	if (temp)
	{

		UE_LOG(LogTemp, Log, TEXT("Drop Item ID %d"),temp->GetInfo().itemID);
	}
	else
	{

		UE_LOG(LogTemp, Log, TEXT("Drop Empty Space"));
	}
	
}

void AMyPlayer::InvenOpen(const FInputActionValue& value)
{
	bool isPress = value.Get<bool>();
	if (isPress)
	{

		auto con = Cast<AMyPlayerController>(GetController());
		if (_isInvenOpen)
		{
			if (con)
			{
				con->HideUI();

				if (_invenWidget)
					_invenWidget->RemoveFromViewport();
			}
		}
		else
		{

			if (con)
			{
				con->ShowUI();
				if (_invenWidget)
					_invenWidget->AddToViewport();
			}
		}
			_isInvenOpen =!_isInvenOpen;

	}
}

void AMyPlayer::Drop()
{
	AMyItem* temp=nullptr;
	auto inven = Cast<UMyInvenUI>(_invenWidget);
	if (inven == nullptr)
		return;


	if (_InvenComponent)
		temp = _InvenComponent->DropItem(inven->_curIndex);
	if (temp)
	{

		UE_LOG(LogTemp, Log, TEXT("Drop Item ID %d"), temp->GetInfo().itemID);
	}
	else
	{

		UE_LOG(LogTemp, Log, TEXT("Empty Space"));
	}


}
