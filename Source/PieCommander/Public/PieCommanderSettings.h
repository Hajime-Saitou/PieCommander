// PieCommander
// https://github.com/Hajime-Saitou/PieCommander
// Copyright(c) 2025 Hajime Saito
// MIT License

#pragma once

#include "Editor.h"
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PieCommanderSettings.generated.h"

USTRUCT()
struct FPieCommandInformation
{
	GENERATED_BODY()

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	bool Disabled;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	FString CommandLine;
};

UCLASS(Config=Editor, ProjectUserConfig)
class UPieCommanderSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> StartPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> PreBeginPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> BeginPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> PostPIEStarted;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> PrePIEEnded;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> EndPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> ShutdownPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> PausePIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> ResumePIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> SingleStepPIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> OnPreSwitchBeginPIEAndSIE;

	UPROPERTY(Config, EditAnywhere, Category="PieCommander")
	TArray<FPieCommandInformation> OnSwitchBeginPIEAndSIE;

	UPieCommanderSettings();

	UFUNCTION()
	void ExecuteAllCommands(TArray<FPieCommandInformation> PieCommandLineInformation);

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};
