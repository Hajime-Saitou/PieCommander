// PieCommander
// https://github.com/Hajime-Saitou/PieCommander
// Copyright(c) 2025 Hajime Saito
// MIT License

#include "PieCommanderSettings.h"
#include "Kismet/KismetSystemLibrary.h"

#define LOCTEXT_NAMESPACE "PieCommanderSettings"

UPieCommanderSettings::UPieCommanderSettings()
{
}

void UPieCommanderSettings::ExecuteAllCommands(TArray<FPieCommandInformation> PieCommandLineInformation)
{
	for (auto item : PieCommandLineInformation)
	{
		if (item.Enabled)
		{
			UKismetSystemLibrary::ExecuteConsoleCommand(Super::GetWorld(), item.CommandLine);
		}
	}
}

void UPieCommanderSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig();
}


#undef LOCTEXT_NAMESPACE
