// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UENUM(Blueprintable)
enum class ItemType : uint8 {
	Weapon,
	Potion
};

USTRUCT(Blueprintable)
struct FItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ItemType itemType = ItemType::Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float power;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int range;
};

UCLASS()
class GAMESLICE_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FItemInfo ItemInfo;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;
};
