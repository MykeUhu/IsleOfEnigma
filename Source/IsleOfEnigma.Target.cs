// Copyright by MykeUhu

using UnrealBuildTool;
using System.Collections.Generic;

public class IsleOfEnigmaTarget : TargetRules
{
	public IsleOfEnigmaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "IsleOfEnigma" } );
	}
}
