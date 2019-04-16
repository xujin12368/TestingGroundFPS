// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusAtPoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree//BlackboardComponent.h"
#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

EBTNodeResult::Type UFocusAtPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	AAIController* Controller = OwnerComp.GetAIOwner();

	if (!ensure(BlackboardComp && Controller)) { return EBTNodeResult::Failed; }

	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	//Set
	BlackboardComp->SetValueAsVector(Point.SelectedKeyName, PlayerLocation);

	//Get
	FVector PointValue = BlackboardComp->GetValueAsVector(Point.SelectedKeyName);

	Controller->SetFocalPoint(PointValue);

	return EBTNodeResult::Succeeded;
}