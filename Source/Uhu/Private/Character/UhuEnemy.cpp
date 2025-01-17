// Copyright MykeUhu


#include "Character/UhuEnemy.h"
#include "AbilitySystem/UhuAbilitySystemComponent.h"
#include "AbilitySystem/UhuAttributeSet.h"
#include "Uhu/Uhu.h"

AUhuEnemy::AUhuEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UUhuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UUhuAttributeSet>("AttributeSet");
}
void AUhuEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AUhuEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 AUhuEnemy::GetPlayerLevel()
{
	return Level;
}

void AUhuEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AUhuEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UUhuAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}