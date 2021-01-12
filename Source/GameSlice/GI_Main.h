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

	UFUNCTION(BlueprintCallable)
		void AddItemToInventory(struct FItemInfo NewItem);

	/*

	UFUNCTION(BlueprintCallable)
		void HasQuantity();

	UFUNCTION(BlueprintCallable)
		void RemoveQuantity();

		*/
};
