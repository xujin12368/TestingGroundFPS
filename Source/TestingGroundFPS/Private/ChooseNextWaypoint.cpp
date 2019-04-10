// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree//BlackboardComponent.h"
#include "AIController.h"
#include "TP_ThirdPerson/PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComp = OwnerComp.GetBlackboardComponent();
	IndexValue = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);
	
	auto AIController = OwnerComp.GetAIOwner();
	ControlledPawn = AIController->GetPawn();
	if (!ensure(ControlledPawn)) { return EBTNodeResult::Failed; }

	GetPatrolPoints();
	SetPatrolPoints();
	CycleIndex();


	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints()
{
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	PatrolPoints = PatrollingGuard->PatrolPoints;
}

void UChooseNextWaypoint::SetPatrolPoints()
{
	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[IndexValue]);
}

void UChooseNextWaypoint::CycleIndex()
{
	IndexValue++;
	BlackboardComp->SetValueAsInt(Index.SelectedKeyName, IndexValue % PatrolPoints.Num());
}

