// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "Character/UhuCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UhuEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ISLEOFENIGMA_API AUhuEnemy : public AUhuCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AUhuEnemy();

	/**
	 * Begin Enemy Interface
	 */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/**
	 * End Enemy Interface
	 */
protected:
	virtual void BeginPlay() override;
};
