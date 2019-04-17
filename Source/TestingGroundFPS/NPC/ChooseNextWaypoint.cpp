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

	PatrolPoints = PatrolRoute->GetPatrolPoints(); // TODO  ��ֹ�����ڴ˴�������TArryΪ�յ������
	if (0 == PatrolPoints.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has missed its patrol points."), *ControlledPawn->GetName());
		return;
	}
}

void UChooseNextWaypoint::SetPatrolPoints()
{
	BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[IndexValue]);
}

void UChooseNextWaypoint::CycleIndex()
{
	IndexValue++;
	auto NextIndex = IndexValue % PatrolPoints.Num(); // �ñ����洢���ô����߼������������ÿ��������֪�����Ǹ�ɶ
	BlackboardComp->SetValueAsInt(Index.SelectedKeyName, NextIndex);
}

