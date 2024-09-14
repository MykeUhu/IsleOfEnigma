// Copyright MykeUhu

#include "Character/UhuCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/UhuAbilitySystemComponent.h"


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

FVector AUhuCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AUhuCharacterBase::InitAbilityActorInfo()
{
}

void AUhuCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AUhuCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void AUhuCharacterBase::AddCharacterAbilities()
{
	UUhuAbilitySystemComponent* UhuASC = CastChecked<UUhuAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	UhuASC->AddCharacterAbilities(StartupAbilities);
}

