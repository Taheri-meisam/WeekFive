// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
//Input component 
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
//UI
#include "Blueprint/UserWidget.h"
//camera 
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 800.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 0.2;
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (subsystem) {
			subsystem->AddMappingContext(IMCinput, 0);

		}
	}
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhanceInputCom = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhanceInputCom->BindAction(IA_One, ETriggerEvent::Started, this, &APlayerPawn::OnePressed);
		EnhanceInputCom->BindAction(IA_Pause, ETriggerEvent::Started, this, &APlayerPawn::PauseMenu);
		EnhanceInputCom->BindAction(IA_Forward, ETriggerEvent::Started, this, &APlayerPawn::MoveForward);
		EnhanceInputCom->BindAction(IA_Two, ETriggerEvent::Started, this, &APlayerPawn::TwoPressed);
	}
}

void APlayerPawn::OnePressed(const FInputActionValue& val)
{
	const bool value = val.Get<bool>();
	if (value) {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::FString("Key one is pressed !!!"));
		UE_LOG(LogTemp, Warning, TEXT("Key Pressed !!!"));
	}


}

void APlayerPawn::PauseMenu(const FInputActionValue& val)
{
	const bool value = val.Get<bool>();
	if (value) {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::FString("Del key is pressed !!!"));
		UE_LOG(LogTemp, Warning, TEXT("Del Pressed !!!"));
	}

}

void APlayerPawn::TwoPressed(const FInputActionValue& val)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::FString(" Two key is being pressed !!!"));
}

void APlayerPawn::MoveForward(const FInputActionValue& val) {
	//FVector2D moveVector = val.Get<FVector2d>();
	const float dirVal = val.Get<float>();
	if (dirVal) {
		//Mesh->MoveComponent()
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::FString("forward key is pressed !!!") + FString::SanitizeFloat(dirVal));
	}
}