// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyGriffon.h"

// Sets default values
AEnemyGriffon::AEnemyGriffon()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BodyAsset(TEXT("SkeletalMesh'/Game/QuadrapedCreatures/Griffon/Meshes/SK_Griffon.SK_Griffon'"));

	if (BodyAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(BodyAsset.Object);

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AEnemyGriffon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyGriffon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyGriffon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

