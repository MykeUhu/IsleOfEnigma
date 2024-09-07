// Copyright MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "Character/UhuCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UhuEnemy.generated.h"

/**
 * 
 */
UCLASS()
class UHU_API AUhuEnemy : public AUhuCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AUhuEnemy();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end Enemy Interface */

protected:
	virtual void BeginPlay() override;
};
