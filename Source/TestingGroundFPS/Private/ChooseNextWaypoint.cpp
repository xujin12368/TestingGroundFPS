// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree//BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto IndexValue = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);


	UE_LOG(LogTemp, Warning, TEXT("C++ BTNode Runing. %i"),IndexValue);

	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints()
{

}

int32 UChooseNextWaypoint::SetPatrolPoints()
{
	return 0;
}

void UChooseNextWaypoint::CycleIndex(int32 Index)
{

}

