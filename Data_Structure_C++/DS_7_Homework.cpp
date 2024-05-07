#include <iostream>

using namespace std;

template<typename T>
class Vector {
private:
	T* data;
	int rsize;
	int osize;
public:

	Vector() : data(NULL), rsize(0), osize(0) {}
	Vector(int n, const T& val = 0) : rsize(2 * n), osize(n) {
		data = (n > 0 ? new T[rsize] : NULL);
		for (int i = 0; i < n; i++) data[i] = val;
	}

	Vector(T* from, T* to) :data(NULL), rsize(0), osize(0) {
		for (T* ptr = from; ptr != to; ptr++) {
			push_back(*ptr);
		}
	}

	Vector(const Vector <T>& foo) {
		osize = foo.osize;
		rsize = foo.rsize;
		data = new T[rsize];
		for (int i = 0; i < osize; ++i) data[i] = foo.data[i];
	}

	Vector<T>& operator =(const Vector<T>& foo) {
		if (this == &foo)return *this;
		if (rsize != foo.rsize) {
			delete[] data;
			rsize = foo.rsize;
			osize = foo.osize;

			osize = foo.osize;
			for (int i = 0; i < osize; ++i) {
				data[i] = foo.data[i];
			}
		}
		else {
			delete[] data;
			rsize = foo.rsize;
			osize = foo.osize;
			data = new T[rsize];
			for (int i = 0; i < osize; ++i) {
				data[i] = foo.data[i];
			}
		}
	}

	~Vector() {
		delete[] data;
	}

	int size() const { return osize; }
	int czpacity() const { return rsize; }

	const T* begin() const { return data; }
	const T* end() const { return data + osize; }

	const T& front() const { return data[0]; }
	T& front() { return data[0]; }

	const T& back() const { return data[osize - 1]; }
	T& back() { return data[osize - 1]; }

	const T& operator [](int i)const { return data[i]; }
	T& operator [](int i) { return data[i]; }

	void pop_back() {
		if (osize > 0)osize--;
	}

	void push_back(const T& foo) {
		if (rsize == osize) {
			rsize = (rsize == 0 ? 1 : 2 * rsize);
			T* ptr = new T[rsize];
			for (int i = 0; i < osize; ++i)ptr[i] = data[i];
			ptr[osize] = foo;
			delete[]data;
			data = ptr;
		}
		else {
			data[osize] = foo;
		}
		osize++;
	}

	void insert(const int loc, T in) {
		if (osize == rsize) {
			rsize = 2 * rsize + 1;
			osize++;
			T* ptr = new T[rsize];
			for (int i = 0; i < loc; ++i)ptr[i] = data[i];
			ptr[loc] = in;
			for (int i = loc + 1; i < osize; ++i)ptr[i] = data[i];
			delete[]data;
			data = ptr;
		}
		else {
			osize++;
			for (int i = osize; i > loc; --i)data[i] = data[i - 1];
			data[loc] = in;
		}
	}

	void insert(const int loc, const Vector<T>& v) {
		using std::swap;
		if (osize + v.osize > rsize) {
			osize += v.osize;
			rsize = 2 * osize + 1;
			T* ptr = new T[rsize];
			for (int i = 0; i < loc; ++i) ptr[i] = data[i];
			for (int i = 0; i < v.osize; ++i)ptr[i + loc] = v.data[i];
			for (int i = v.osize + loc; i < osize; ++i) ptr[i] = data[i - v.osize];
			delete[]data;
			swap(ptr, data);
		}
		else {
			int n = osize - loc;
			osize += v.osize;
			rsize = 2 * rsize + 1;
			T* ptr = new T[n];
			for (int i = 0; i < n; ++i) ptr[i] = data[i + loc];
			for (int i = 0; i < v.osize; ++i)data[i + loc] = v.data[i];
			for (int i = 0; i < n; ++i) data[i + loc + v.osize] = ptr[i];
			delete[]ptr;
		}
	}

	void  swap(Vector<T>& vec) {
		using std::swap;
		swap(data, vec.data);
		swap(osize, vec.osize);
		swap(rsize, vec.rsize);
	}

	friend ostream& operator << (ostream& out, const Vector<T>& a) {
		for (int i = 0; i < a.osize; i++) {
			out << a.data[i] << " ";
		}
		return out;
	}
};

int main() {
	/*Vector<int>  a(5, 3);  // 3 3 3 3 3    rsize = 10
	a[2] = 5;             // 3 3 5 3 3
	a.insert(2, 6);        // rsize = 10
	cout << a << endl;    // 3 3 6 5 3 3

	a.insert(3, Vector<int>(6, 8));  // rsize = 20
	cout << a << endl;             // 3 3 6 8 8 8 8 8 8 5 3 3
	*/
	Vector<int> a(2, 3), b(4, 5);

	cout << a << " - " << b << endl;  // 3 3 - 5 5 5 5

	a.swap(b);

	cout << a << " - " << b << endl;  // 5 5 5 5 - 3 3
}