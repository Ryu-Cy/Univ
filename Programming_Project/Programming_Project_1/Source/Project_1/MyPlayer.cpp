// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BodyAsset(TEXT("SkeletalMesh'/Game/ParagonAurora/Characters/Heroes/Aurora/Meshes/Aurora.Aurora'"));

	if (BodyAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(BodyAsset.Object);

	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	Arm->SetupAttachment(RootComponent);
	Arm->bUsePawnControlRotation = true;
	Arm->TargetArmLength = 500.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Arm, USpringArmComponent::SocketName);

	GetCharacterMovement()->bOrientRotationToMovement = true;

}

void AMyPlayer::AttackMelee() {
	if ((AttackNum < 3) && (!isDuringAttack)) {
		FString PlaySection = "Attack" + FString::FromInt(AttackNum + 1);
		PlayAnimMontage(AttackMeleeAnim, 1.0f, FName(*PlaySection));
		AttackNum++;
		isDuringAttack = true;
	}
	else {
		AttackNum = 0;
	}

	FTimerHandle THAttackEnd;
	GetWorldTimerManager().SetTimer(THAttackEnd, this, &AMyPlayer::AttackMeleeEnd, 0.7f, false);
}

void AMyPlayer::AttackMeleeEnd() {
	isDuringAttack = false;
}

void AMyPlayer::MoveForward(float value) {
	if ((Controller != NULL) && (value != 0.0f) && (!isDuringAttack)) {
		AttackNum = 0;
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0.0f, Rot.Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}

}

void AMyPlayer::MoveRight(float value) {
	if ((Controller != NULL) && (value != 0.0f) && (!isDuringAttack)) {
		AttackNum = 0;
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0.0f, Rot.Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}

}

void AMyPlayer::LookUp(float value) {
	AddControllerPitchInput(value);
}

void AMyPlayer::Turn(float value) {
	AddControllerYawInput(value);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyPlayer::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AMyPlayer::Turn);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMyPlayer::AttackMelee);

}

