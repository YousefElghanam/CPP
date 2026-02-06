#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
	void iter(T* arr, unsigned int len, void (*func)(T&)) {
		for (unsigned int i = 0; i < len; i++) {
			func(arr[i]);
		}
	}

template <typename T>
	void iter(const T* arr, unsigned int len, void (*func)(const T&)) {
		for (unsigned int i = 0; i < len; i++) {
			func(arr[i]);
		}
	}

#endif /* ITER_HPP */
