#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>
	void iter(T* arr, unsigned int len, Func func) {
		for (unsigned int i = 0; i < len; i++) {
			func(arr[i]);
		}
	}

#endif /* ITER_HPP */
