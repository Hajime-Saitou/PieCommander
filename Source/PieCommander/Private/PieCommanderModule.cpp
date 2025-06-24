// PieCommander
// https://github.com/Hajime-Saitou/PieCommander
// Copyright(c) 2025 Hajime Saito
// MIT License

#include "PieCommanderModule.h"
#include "ISettingsModule.h"
#include "PieCommanderSettings.h"

#define LOCTEXT_NAMESPACE "FPieCommanderModule"

#define REGISTER_SETTINGS(FOnPIEEvent) FEditorDelegates::FOnPIEEvent.AddLambda([settings](bool bIsSimulated) { settings->ExecuteAllCommands(settings->FOnPIEEvent);})

void FPieCommanderModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings(
		"Editor", "PieCommander", "PieCommander",
		LOCTEXT("General", "General"),
		LOCTEXT("Specific Console Commands for PIE", "Specific Console Commands for PIE"),
		GetMutableDefault<UPieCommanderSettings>());

		UPieCommanderSettings* settings = GetMutableDefault<UPieCommanderSettings>();
		if (settings != nullptr)
		{
			REGISTER_SETTINGS(StartPIE);
			REGISTER_SETTINGS(PreBeginPIE);
			REGISTER_SETTINGS(BeginPIE);
			REGISTER_SETTINGS(PostPIEStarted);
			REGISTER_SETTINGS(PrePIEEnded);
			REGISTER_SETTINGS(EndPIE);
			REGISTER_SETTINGS(ShutdownPIE);
			REGISTER_SETTINGS(PausePIE);
			REGISTER_SETTINGS(ResumePIE);
			REGISTER_SETTINGS(SingleStepPIE);
			REGISTER_SETTINGS(OnPreSwitchBeginPIEAndSIE);
			REGISTER_SETTINGS(OnSwitchBeginPIEAndSIE);
		}
	}
}

void FPieCommanderModule::ShutdownModule()
{
ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Editor", "PieCommander", "PieCommander");
	}
}

bool FPieCommanderModule::OnModifiedSettings()
{
	UPieCommanderSettings* Settings = GetMutableDefault<UPieCommanderSettings>();
	Settings->SaveConfig();

	return true;
}

IMPLEMENT_MODULE(FPieCommanderModule, PieCommander)

#undef LOCTEXT_NAMESPACE
