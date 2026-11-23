# outshell's Coding Standards

- Use tabs over spaces that a 8 spaces wide.
- Use consistent and descriptive names for your variables, functions, parameters, structs, and files/directories.
- Use DRY where appropriate.
- Document all functions, somewhat like google style docstrings in python.
- When writting documentation, get to the point as quick as possible.
- Do not nest code at all.
- User privacy is a priority.
- All .md files should be all upder-case following cammel case for all multi-name files. Eg: EXAMPLE_ONE.md  
- Use cammel case for multi-name functions, structs, files/directories, parameters, variables, etc. Eg: char *foo;
- Ai is allowed, but should be avoided because you don't know who owns the code.
- 80 character limit.
- Pointer alignment to the right.
- Return types should be on a seperate line comparted function. Eg:
```c
int
foo (int foo1, int foo2)
{
        return foo1 + foo2;
}
```

# Pull Requests

1) Fork/clone the repository
2) Create a branch for your changes
3) Proofread your changes
4) Open a pull request explaining:  
    - What did you change?  
    - Why you changed what you changed?  
    - How will this improve outshell?  
    - Will this help users have a better experience with outshell?  
