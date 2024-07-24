// Copyright by MykeUhu


#include "Actor/UhuEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/UhuAttributeSet.h"
#include "Components/SphereComponent.h"

AUhuEffectActor::AUhuEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	
	

}

// Needed for Actors that can overlap
void AUhuEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect! For now usig Const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UUhuAttributeSet* UhuAttributeSet = Cast<UUhuAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UUhuAttributeSet::StaticClass()));
		
		UUhuAttributeSet* MutableAttributeSet = const_cast<UUhuAttributeSet*>(UhuAttributeSet);
		MutableAttributeSet->SetHealth(UhuAttributeSet->GetHealth() + 25.f);

		Destroy();
	}
}

void AUhuEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void AUhuEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AUhuEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AUhuEffectActor::EndOverlap);
	
}

