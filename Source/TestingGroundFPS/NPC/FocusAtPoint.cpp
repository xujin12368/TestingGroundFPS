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

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerPawn)) { return EBTNodeResult::Failed; }

	// Controller->SetFocalPoint(PointValue);
	Controller->SetFocus(PlayerPawn);

	return EBTNodeResult::Succeeded;
}