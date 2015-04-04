// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ROCClient : ModuleRules
{
	public ROCClient(TargetInfo Target)
	{
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Slate", "SlateCore", "HeadMountedDisplay", "RHI", "RenderCore" });
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.AddRange(new string[] {"F:/Libs/opencv/build/x64/vc12/lib/opencv_core2411.lib",
            "F:/Libs/opencv/build/x64/vc12/lib/opencv_highgui2411.lib",
            "F:/Libs/opencv/build/x64/vc12/lib/opencv_imgproc2411.lib",
            "F:/Libs/opencv/build/x64/vc12/lib/opencv_calib3d2411.lib"});
            PublicIncludePaths.AddRange(new string[] { "F:/Libs/opencv/build/include" });
        }
        PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
