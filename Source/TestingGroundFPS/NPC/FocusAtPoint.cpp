// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusAtPoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree//BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/PlayerController.h"

EBTNodeResult::Type UFocusAtPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	AAIController* Controller = OwnerComp.GetAIOwner();
	if (!ensure(BlackboardComp && Controller)) { return EBTNodeResult::Failed; }

	//APawn* EnemyPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//if (!ensure(EnemyPawn)) { return EBTNodeResult::Failed; }

	//// For MoveTo Task using.
	//BlackboardComp->SetValueAsObject(EnemyKey.SelectedKeyName, EnemyPawn);

	// Get BlackboardKey Value
	if (EnemyKey.IsSet())
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyKey is set."));

		APawn* Enemy = Cast<APawn>(BlackboardComp->GetValueAsObject(EnemyKey.SelectedKeyName));
		if (!Enemy)
		{
			UE_LOG(LogTemp, Warning, TEXT("Enemy is not null."));

			Controller->SetFocus(Enemy);
		}
	}

	return EBTNodeResult::Succeeded;
}