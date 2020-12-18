// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_Main.h"

void UGI_Main::AddItemToInventory(struct FItemInfo NewItem) {
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

void UGI_Main::HasQuantity_Implementation() {
	// This will possibly be used when using/discarding items from the inventory?
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("AddItemToInventory function")));
}

void UGI_Main::RemoveQuantity_Implementation() {
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("AddItemToInventory function")));
}