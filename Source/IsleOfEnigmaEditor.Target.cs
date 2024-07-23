// Copyright by MykeUhu

using UnrealBuildTool;
using System.Collections.Generic;

public class IsleOfEnigmaEditorTarget : TargetRules
{
	public IsleOfEnigmaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "IsleOfEnigma" } );
	}
}
