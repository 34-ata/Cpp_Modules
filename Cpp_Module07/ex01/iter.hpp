#ifndef ITER_HPP
#define ITER_HPP

#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET "\033[0m"

template <typename T>

void	iter(T *array, size_t arr_len, void (*foo)(T &))
{
	if (array == NULL || foo == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		foo(array[i]);
}

#endif