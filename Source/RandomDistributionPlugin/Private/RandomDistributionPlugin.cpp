// Copyright 2012 - 2015 Project Kube. All Rights Reserved.

#include "RandomDistributionPluginPrivatePCH.h"

class FRandomDistributionPlugin : public IRandomDistributionPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// List of Generators
	TLinkedList<IGenerator> Generators = new TLinkedList<IGenerator>();

};

IMPLEMENT_MODULE(FRandomDistributionPlugin, RandomDistributionPlugin)



void FRandomDistributionPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FRandomDistributionPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}



