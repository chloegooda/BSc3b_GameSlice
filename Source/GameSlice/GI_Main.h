// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSlice/BaseItem.h"
#include "Containers/Array.h"
#include "Engine/GameInstance.h"
#include "GI_Main.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Stack;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class GAMESLICE_API UGI_Main : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInventorySlot> ItemList;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AddItemToInventory(struct FItemInfo NewItem);
	virtual void AddItemToInventory_Implementation(struct FItemInfo NewItem) {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Picked Up +1 %s"), *NewItem.name));
		for (int i = 0; i < ItemList.Num(); i++) {
			if (ItemList[i].ItemName == NewItem.name) {
				ItemList[i].Stack++;
				return;
			}
		}
		ItemList.Add(FInventorySlot{ NewItem.name, 1 });
		return;
	}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void HasQuantity();
	virtual void HasQuantity_Implementation() {
		// This will possibly be used when using/discarding items from the inventory?
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("AddItemToInventory function")));
	}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void RemoveQuantity();
	virtual void RemoveQuantity_Implementation() {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("AddItemToInventory function")));
	}
};
