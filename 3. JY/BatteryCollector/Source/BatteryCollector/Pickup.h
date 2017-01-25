// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//픽업 메쉬 가져오기
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }


	/*
	BlueprintPure, BlueprintCallable 둘다 블루프린트에서 호출이 가능

	BlueprintPure : 
	- 기본적으로 값의 변경이 가능(그러나 일반적으로는 그렇게 하지 말것)
	- 계산이 빠르고 자주변경되는 값에 적합

	BlueprintCallable:
	- 실행순서 핀에서 실행신호가 입력되었을때에만 실행된다. 결과값을 아웃풋 핀에 저장
	- 결과 값이 자주 변경되지 않을 때에는 이걸 사용
	- 다른 클래스에서 안전하게 값을 변경
	*/
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newPickupState);

	//픽업된 물체를 습득했을때 실행되는 함수입니다.
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	//아이템이 사용가능하면 true
	bool bIsActive;

private:

	//설정 //함수가 아니므로 마지막에 ;를 붙이지 않는다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "pickup", meta = (AllowPrivateAccess = "true"))
	
	//메쉬 전방선언
	class UStaticMeshComponent* PickupMesh;
	
};
