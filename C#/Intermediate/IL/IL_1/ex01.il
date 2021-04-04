.assembly ex01 {} // if execute ex01.exe, there's need to assembly manifest in module


.method static void foo() cil managed
{
	// entry point should be declared, one time
	.entrypoint //  if there isn't this code, not found start point (C# -> Main())

	ret
}
