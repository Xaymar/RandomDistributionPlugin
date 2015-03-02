// Copyright 2012 - 2015 Project Kube. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class RandomDistributionPlugin : ModuleRules
	{
		public RandomDistributionPlugin(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
                    "RandomDistributionPlugin/Public",
					// ... add public include paths required here ...
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
					"RandomDistributionPlugin/Private",
					// ... add other private include paths required here ...
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
                    "Engine",
                    "CoreUObject",
					// ... add other public dependencies that you statically link with here ...
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
			);
		}
	}
}