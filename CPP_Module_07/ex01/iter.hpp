#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T, typename F>
	void iter(T* arr, unsigned int len, void (*func)(F));

#endif /* WHATEVER_HPP */
