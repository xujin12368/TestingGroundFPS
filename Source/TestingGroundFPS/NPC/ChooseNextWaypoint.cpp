// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree//BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComp = OwnerComp.GetBlackboardComponent();
	IndexValue = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);
	
	ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (!ensure(ControlledPawn)) { return EBTNodeResult::Failed; }

	GetPatrolPoints();
	SetPatrolPoints();
	CycleIndex();

	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints()
{
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { return; }

	PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (0 == PatrolPoints.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has missed its patrol points."), *ControlledPawn->GetName());
	}
}

void UChooseNextWaypoint::SetPatrolPoints()
{
	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[IndexValue]);
}

void UChooseNextWaypoint::CycleIndex()
{
	IndexValue++;
	auto NextIndex = IndexValue % PatrolPoints.Num(); // 用变量存储会让代码逻辑更加清晰，让看代码的人知道这是个啥
	BlackboardComp->SetValueAsInt(Index.SelectedKeyName, NextIndex);
}

