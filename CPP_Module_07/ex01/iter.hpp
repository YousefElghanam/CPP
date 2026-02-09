#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
	void iter(T* arr, const unsigned long len, void (*func)(T&)) {
		for (unsigned long i = 0; i < len; i++) {
			func(arr[i]);
		}
	}

template <typename T>
	void iter(const T* arr, const unsigned long len, void (*func)(const T&)) {
		for (unsigned long i = 0; i < len; i++) {
			func(arr[i]);
		}
	}

#endif /* ITER_HPP */
