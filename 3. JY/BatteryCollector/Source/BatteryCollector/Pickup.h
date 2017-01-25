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

	//�Ⱦ� �޽� ��������
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }


	/*
	BlueprintPure, BlueprintCallable �Ѵ� �������Ʈ���� ȣ���� ����

	BlueprintPure : 
	- �⺻������ ���� ������ ����(�׷��� �Ϲ������δ� �׷��� ���� ����)
	- ����� ������ ���ֺ���Ǵ� ���� ����

	BlueprintCallable:
	- ������� �ɿ��� �����ȣ�� �ԷµǾ��������� ����ȴ�. ������� �ƿ�ǲ �ɿ� ����
	- ��� ���� ���� ������� ���� ������ �̰� ���
	- �ٸ� Ŭ�������� �����ϰ� ���� ����
	*/
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newPickupState);

	//�Ⱦ��� ��ü�� ���������� ����Ǵ� �Լ��Դϴ�.
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

protected:

	//�������� ��밡���ϸ� true
	bool bIsActive;

private:

	//���� //�Լ��� �ƴϹǷ� �������� ;�� ������ �ʴ´�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "pickup", meta = (AllowPrivateAccess = "true"))
	
	//�޽� ���漱��
	class UStaticMeshComponent* PickupMesh;
	
};
