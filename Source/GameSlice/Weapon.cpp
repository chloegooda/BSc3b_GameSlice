// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"

// Sets default values
AWeapon::AWeapon()
{
 	// create static mesh component
	this->mesh_component = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	this->RootComponent = this->mesh_component;

	/*
	// create material component
	this->u_material = CreateDefaultSubobject<UMaterial>(TEXT("MaterialComponent"));
	*/

}
