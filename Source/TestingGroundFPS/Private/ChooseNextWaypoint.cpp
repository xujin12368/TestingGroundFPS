// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Gameframework/Pawn.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Super::ExecuteTask(OwnerComp, NodeMemory); //是否需要这个呢
	UE_LOG(LogTemp, Warning, TEXT("C++ BTNode Runing."));
	

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

