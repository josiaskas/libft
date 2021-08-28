# LIBFT | WITH PRINTF AND STACK

Implementation of some  functions of the Standard C Library.
If you need the 42 project without any upgrade switch to master branch. 

## Verions may change with time on shinsekai branch
All version are done for 42 projects (norminette)
- tag v2.0 is just with PRINTF
- tag v3.0 is the current with printf and stacks implementation

## PRINTF

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
