Get-ChildItem -Recurse -Filter *.c |
	ForEach-Object { clang-format -i $_.FullName }
