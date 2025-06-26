// PieCommander
// https://github.com/Hajime-Saitou/PieCommander
// Copyright(c) 2025 Hajime Saito
// MIT License

#pragma once

#include "Modules/ModuleManager.h"

class FPieCommanderModule final : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
