

#include "MyInvenComponent.h"


UMyInvenComponent::UMyInvenComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	_items.SetNum(9);



	// ...
}


// Called when the game starts
void UMyInvenComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInvenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyInvenComponent::AddItem(AMyItem* item)
{
	//비어있는 자리 찾기.
	auto target = _items.FindByPredicate([](AMyItem* item)->bool {
		if (item == nullptr)
			return true;
		return false;
		});
	if (target == nullptr)
		return;


	*target = item;
	UE_LOG(LogTemp, Error, TEXT("ID : %d"), (*target)->GetInfo().itemID);
	int32 targetIndex = 0;
	int64 t1 = (int64)target;
	int64 t2 = (int64)(&_items[0]);
	targetIndex=(t1-t2)/ sizeof(FMyItemInfo);

	if (_itemChangeEvent.IsBound())
		_itemChangeEvent.Broadcast(targetIndex, (*target)->GetInfo());

	
}

AMyItem* UMyInvenComponent::DropItem()
{

	auto target = _items.FindLastByPredicate([](AMyItem* item)->bool {
		if (item!=nullptr)
			return true;
		return false;
		});

	UE_LOG(LogTemp, Log, TEXT("find Item index %d"), target);
	if (target == -1)
		return nullptr;

	auto temp =DropItem(target);

	return temp;
}

AMyItem* UMyInvenComponent::DropItem(int32 index)
{
	if (index >= _items.Num() || index < 0)
		return nullptr;

	UE_LOG(LogTemp, Log, TEXT("drop Item index %d"), index);
	if (_items[index]==nullptr)
		return nullptr;

	int32 min_r = 100;
	int32 max_r = 200;

	FVector loc = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * FMath::RandRange(min_r, max_r);

	AMyItem* item = _items[index];
	item->SetActorLocation(loc);
	item->DropItem();

	_items[index] = nullptr;
	FMyItemInfo temp;
	if (_itemChangeEvent.IsBound())
		_itemChangeEvent.Broadcast(index, temp);
	return item;
}

void UMyInvenComponent::DropAllItem()
{
	AMyItem* temp=nullptr;
	while (true)
	{
		temp = DropItem();
		if (temp == nullptr)
			break;
	}
}

FMyItemInfo UMyInvenComponent::GetItemInfo_Index(int32 index)
{

	FMyItemInfo temp;

	if (index < 0 || index >= _items.Num())
		return temp;
	if (_items[index])
		temp = _items[index]->GetInfo();

	return temp;
}

