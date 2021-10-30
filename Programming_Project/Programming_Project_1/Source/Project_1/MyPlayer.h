// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "MyPlayer.generated.h"

UCLASS()
class PROJECT_1_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

	UPROPERTY(EditDefaultsOnly, Category = pawn)
		UAnimMontage* AttackMeleeAnim;

	void AttackMelee();
	void AttackMeleeEnd();

	bool isDuringAttack;

	int AttackNum;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	USpringArmComponent* Arm;

	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void Turn(float value);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
