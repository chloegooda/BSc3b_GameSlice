// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_Main.h"


void UGI_Main::AddItemToInventory(struct FItemInfo NewItem, TArray<FInventorySlot> Inventory) {
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, FString::Printf(TEXT("Picked Up +1 %s"), *NewItem.name));
	for (int i = 0; i < Inventory.Num(); i++) {
		if (Inventory[i].ItemName == NewItem.name) {
			Inventory[i].Stack++;
			return;
		}
	}
	Inventory.Add(FInventorySlot{ NewItem.name, NewItem.ID, 1 });
	return;
}

void UGI_Main::IncreasePlayerGold(int valueToAdd) {
	playerGold += valueToAdd;
	return;
}

void UGI_Main::RemoveItemFromInventory(struct FItemInfo ItemToRemove, TArray<FInventorySlot> Inventory) {
	for (int i = 0; i < Inventory.Num(); i++) {
		if (Inventory[i].ItemName == ItemToRemove.name) {
			Inventory[i].Stack -= 1;
			if (Inventory[i].Stack == 0) {
				Inventory.RemoveAt(i);
			}
			return;
		}
	}
	return;
}

/*
void UGI_Main::HasQuantity() {
	// This will possibly be used when using/discarding items from the inventory?
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("HasQuantity function")));
}

void UGI_Main::RemoveQuantity() {
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("RemoveQuantity function")));
}
*/