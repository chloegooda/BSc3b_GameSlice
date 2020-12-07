// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class Type : uint8 {
	Sword,
	Lance,
	Axe,
	Bow,
	ThrowingWeapon,
	Stave
};

UENUM(BlueprintType)
enum class Material : uint8 {
	Wood,
	Iron,
	Steel,
	Silver
};

UENUM(BlueprintType)
enum class Rank : uint8 {
	E,
	D,
	C,
	B,
	A,
	S
};

UCLASS()
class GAMESLICE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		Type type = Type::Sword;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		Material material = Material::Wood;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int durability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		Rank rank = Rank::E;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float attackPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int range;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UStaticMeshComponent * mesh_component;
	/*UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UMaterial * u_material;*/
};
