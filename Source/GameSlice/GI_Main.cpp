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
	ItemList.Add(FInventorySlot{ NewItem.name, NewItem.ID, 1 });
	return;
}

void UGI_Main::IncreasePlayerGold(int valueToAdd) {
	playerGold += valueToAdd;
	return;
}

void UGI_Main::RemoveItemFromInventory(struct FItemInfo ItemToRemove) {
	for (int i = 0; i < ItemList.Num(); i++) {
		if (ItemList[i].ItemName == ItemToRemove.name) {
			ItemList[i].Stack -= 1;
			if (ItemList[i].Stack == 0) {
				ItemList.RemoveAt(i);
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