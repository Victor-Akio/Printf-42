# Printf-42

In 42, we produce our codes in C, to better develop the concept and the fundaments of programming skills.
We are not allowed to use a short list of functions to help this process. One of the things we are not suposed to us is the Printf();

###BUT !!!

Instead of being weary about not being able to use the function, we was allowed to reproduce the Printf function;
The following project consist recreating some of the proprieties of the Printf function;

This project can printf the following conversions
s, p, d, i, o, u, x, X and c;
Manage %%
Manage the minimum field-width
Manage the precision

There is other proprieties that the original printf has that is not present in this current version, although, it is already enough to easy the way.
Also, I am now able to use my version of printf inthe further projects.

##Using the project
To compile, run make. This will compile libftprintf.a. To use, include ft_printf.h (located inside includes directory) and use just like printf:

```
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %s!\n", "Hello", "world");
	return (0);
}
```

Then compile with a program:

make