# LIBFT | WITH PRINTF AND STACK | can you use Haki?

Implementation of some of the Standard C Library functions including some additional ones.

_If you need the 42 project without any upgrade switch on master branch_
**Makefile : CFLAGS = -Wall -Wextra -Werror -c -g** _(you can change -g)_

Verions may change with time on shinsekai branch.

Some of addition made to the 42 project useful for later projects : 

## PRINTF

- flags 0 - + ' '
- args  %s %c %d %i %u %x %X %p
- width
- precision
```c
int		ft_printf(const char *format, ...);
```

## STACK

- ### CREATION
```c
typedef struct s_stack
{
	int				length;
	int				current;
	t_stack_node	*head;
	t_stack_node	*bottom;
}	t_stack;

t_stack			*create_stack(void);
```
- ### FUNCTIONS
```c
bool			push(t_stack *stack, void *content);
void			*pop(t_stack *stack);
void			*peak(t_stack *stack);
int			*map_stack(t_stack *stack, int (*apply)(void *, int index));
bool		        for_each_s(t_stack *stack, void (*apply)(void *, int i));
```
- ### Specials
```c
// swap the first 2 elements at the top of stack (nothing if stack->length <= 1)
bool			swap(t_stack *stack);
// shift up by 1 all elements of the stack return true (false if errors)
bool			rotate(t_stack *stack);
// shift down by 1 all elements of the stack return true (false if errors)
bool			reverse_rotate(t_stack *stack);
```

## SIMPLE FUNCTIONS
```c
// atoi on base up to 0123456789ABCDEFGHIJK and check prefix 0b, 0B for base 2 and 0x, 0X for base 16
int		ft_atoi_base(const char *str, int base);
```

## ARRAYS
### Additions
```c
// ability to slice an array and recieve a copy
int		*ft_slice_int(const int original[], int begin, int end);

// check if int array is sorted asc, desc or not sorted
int		type_of_sort(int arr[], int n);
bool	is_sorted_asc(int arr[], int n);
bool	is_sorted_desc(int arr[], int n);
```
### Memory
```c
// ability to free splitted strings 
void		ft_free_splitted(char **arr);
void		free_array(void **array, size_t size);
void		free_stack(t_stack *stack);
```
