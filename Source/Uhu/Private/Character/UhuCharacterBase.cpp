// Copyright MykeUhu


#include "Character/UhuCharacterBase.h"

AUhuCharacterBase::AUhuCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AUhuCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AUhuCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

