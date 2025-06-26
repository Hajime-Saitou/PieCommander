// PieCommander
// https://github.com/Hajime-Saitou/PieCommander
// Copyright(c) 2025 Hajime Saito
// MIT License

#include "PieCommanderModule.h"
#include "ISettingsModule.h"
#include "PieCommanderSettings.h"

#define LOCTEXT_NAMESPACE "FPieCommanderModule"

#define ADD_PIE_EVENT_DELEGATE(FOnPIEEvent) FEditorDelegates::FOnPIEEvent.AddLambda([Settings](bool bIsSimulated) { Settings->ExecuteAllCommands(Settings->FOnPIEEvent);})
#define REMOVE_PIE_EVENT_DELEGATE(FOnPIEEvent) FEditorDelegates::FOnPIEEvent.RemoveAll(this)

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

		UPieCommanderSettings* Settings = GetMutableDefault<UPieCommanderSettings>();
		if (Settings != nullptr)
		{
			ADD_PIE_EVENT_DELEGATE(StartPIE);
			ADD_PIE_EVENT_DELEGATE(PreBeginPIE);
			ADD_PIE_EVENT_DELEGATE(BeginPIE);
			ADD_PIE_EVENT_DELEGATE(PostPIEStarted);
			ADD_PIE_EVENT_DELEGATE(PrePIEEnded);
			ADD_PIE_EVENT_DELEGATE(EndPIE);
			ADD_PIE_EVENT_DELEGATE(ShutdownPIE);
			ADD_PIE_EVENT_DELEGATE(PausePIE);
			ADD_PIE_EVENT_DELEGATE(ResumePIE);
			ADD_PIE_EVENT_DELEGATE(SingleStepPIE);
			ADD_PIE_EVENT_DELEGATE(OnPreSwitchBeginPIEAndSIE);
			ADD_PIE_EVENT_DELEGATE(OnSwitchBeginPIEAndSIE);
		}
	}
}

void FPieCommanderModule::ShutdownModule()
{
ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		REMOVE_PIE_EVENT_DELEGATE(StartPIE);
		REMOVE_PIE_EVENT_DELEGATE(PreBeginPIE);
		REMOVE_PIE_EVENT_DELEGATE(BeginPIE);
		REMOVE_PIE_EVENT_DELEGATE(PostPIEStarted);
		REMOVE_PIE_EVENT_DELEGATE(PrePIEEnded);
		REMOVE_PIE_EVENT_DELEGATE(EndPIE);
		REMOVE_PIE_EVENT_DELEGATE(ShutdownPIE);
		REMOVE_PIE_EVENT_DELEGATE(PausePIE);
		REMOVE_PIE_EVENT_DELEGATE(ResumePIE);
		REMOVE_PIE_EVENT_DELEGATE(SingleStepPIE);
		REMOVE_PIE_EVENT_DELEGATE(OnPreSwitchBeginPIEAndSIE);
		REMOVE_PIE_EVENT_DELEGATE(OnSwitchBeginPIEAndSIE);

		SettingsModule->UnregisterSettings("Editor", "PieCommander", "PieCommander");
	}
}

IMPLEMENT_MODULE(FPieCommanderModule, PieCommander)

#undef LOCTEXT_NAMESPACE
