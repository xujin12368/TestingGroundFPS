// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDFPS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	void GetPatrolPoints();

	void SetPatrolPoints();

	void CycleIndex();

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Index;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Waypoint;

	UBlackboardComponent* BlackboardComp = nullptr;

	APawn* ControlledPawn = nullptr;

	TArray<AActor*> PatrolPoints;

	int32 IndexValue = 0;
	
};
