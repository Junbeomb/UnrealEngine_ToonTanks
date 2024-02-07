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
	//VisibleAnywhere : 볼 수 있지만 편집x
		//BlueprintReadWrite : 노드로 만들기 가능.
		//BluprintReadOnly : 노드로 읽기만 가능.
	//EditAnywhere : 편집도 가능.
	//VisibleInstanceOnly : 월드 아웃라이너에서 볼수 만 있음. 편집x.
	//VisibleDefaultsOnly : 블루프린트에서 볼수만 있음. 편집x.
	//EditDefaultsOnly : 블프에서만 편집가능.
	//EditInstanceOnly : 월드 아웃라이너 에서만 편집 가능.

	void HandleDestruction();



protected:
	
	void RotateTurret(FVector LookAtTarget);

	void Fire();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp; //class 를 쓰면 해당 객체만 포함시키기

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; //UStaticMeshCompoennt는 기본적으로 포함 Actor이면.
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
