// Copyright by MykeUhu


#include "Character/UhuEnemy.h"

#include "AbilitySystem/UhuAbilitySystemComponent.h"
#include "AbilitySystem/UhuAttributeSet.h"
#include "IsleOfEnigma/IsleOfEnigma.h"

AUhuEnemy::AUhuEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UUhuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	// Minimal because its AI
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UUhuAttributeSet>("AttributeSet");
}

void AUhuEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	// defined in IsleOfEnigma.h
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AUhuEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AUhuEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
