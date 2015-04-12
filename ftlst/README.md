# ftlst
Simple tools around a generic doubly linked list written in ANSI C.

# Install
It's pretty obvious :
```sh
cd yourproject
git clone https://github.com/nsierra-/ftlst.git
make -C ftlst
gcc yourprojectfiles -L./ftlst -lftlst
```

# Usage
See `ftlst.h` for full documentation.
`ftlst_elem.h` is meant to be used only by `ftlst`. As `t_lstelem` is defined inside `ftlst.h`, you're able to write all the routines you want. `ftlst` uses the implementations linked with `ftlst_elem.h` to deal internally with its elements, but of course do as you want.

A simple use case :
```c
#include "ftlst.h"
#include <stdio.h>
#include <string.h>

void            print_lst(void *d1)
{
    char        *d1s;

    d1s = (char *)d1;
    printf(d1s);
}

int             cmp(void *d1, void *d2)
{
    return (strcmp((char *)d1, (char *)d2));
}

int             main(void)
{
    t_lst       *lst;
    t_lstelem   *cursor;
    char        *foo = "foo";
    char        *bar = "bar";
    char        *baz = "baz";

    /* CREATING LIST */
    lst = new_lst();

    /* ADDING DATA */
    lst_push_back(lst, bar);        /* Pushing bar at end of list */
    lst_push_front(lst, foo);       /* Pushing foo at the beggining */
    lst_insert(lst, baz, 1);        /* Inserting baz at second position */

    /* ACCESSING DATA */
    puts(lst_data_at(lst, 1));      /* Prints "baz" */
    puts(lst_data_back(lst));       /* Prints "bar" */
    
    /* ITERATION */
    it = new_lstiter(lst, decreasing);
    while (lst_iterator_next(it))
        puts(it->data);
    free(it);

    /* MODIFY LIST */
    lst_swap(lst, 1, 2);            /* Swapping second ("baz") and third ("bar") element */
    lst_remove(lst, 1);             /* Removing second element ("bar") */

    lst_print(lst, print_lst, 1);   /* Debug print (order is "foo, baz") */
    lst_bubble_sort(lst, cmp);      /* Bubble-sorting the list using cmp */
    lst_print(lst, print_lst, 0);   /* Order is now "baz, foo" */

    lst_clear(lst);                 /* Destroying list (but not the data !) */
    return (0);
}

```
