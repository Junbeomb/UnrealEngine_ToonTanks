// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"


#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();
	//VisibleAnywhere : �� �� ������ ����x
		//BlueprintReadWrite : ���� ����� ����.
		//BluprintReadOnly : ���� �б⸸ ����.
	//EditAnywhere : ������ ����.
	//VisibleInstanceOnly : ���� �ƿ����̳ʿ��� ���� �� ����. ����x.
	//VisibleDefaultsOnly : �������Ʈ���� ������ ����. ����x.
	//EditDefaultsOnly : ���������� ��������.
	//EditInstanceOnly : ���� �ƿ����̳� ������ ���� ����.

	void HandleDestruction();



protected:
	
	void RotateTurret(FVector LookAtTarget);

	void Fire();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp; //class �� ���� �ش� ��ü�� ���Խ�Ű��

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; //UStaticMeshCompoennt�� �⺻������ ���� Actor�̸�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly,Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere,Category = "Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere,Category = "Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere,Category = "Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;

};
