// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "PlayerPawn.generated.h"

class USpringArmComponent;

UCLASS()
class WEEK5_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = Properties)
		void OnePressed(const FInputActionValue& val);
	UFUNCTION(BlueprintCallable, Category = Properties)
		void PauseMenu(const FInputActionValue& val);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputMappingContext* IMCinput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_Two;
	UFUNCTION(BlueprintCallable, Category = Functions)
	void TwoPressed(const FInputActionValue& val);





	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_One;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_Pause;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UInputAction* IA_Forward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InputSystem)
	class UUserWidget* MenuWidget;
	UFUNCTION(BlueprintCallable, Category = Properties)
		void MoveForward(const FInputActionValue& val);




public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnMesh)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnMesh)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnMesh)
	class UCameraComponent* MainCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnMesh)
	float speed;
	FVector NewLocation;



};
