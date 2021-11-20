template <class T>
class DllSampTemp
{
	public:
		T dat;

		void set (const T &v);
		T get ();
};

template <class T>
void DllSampTemp<T>::set (const T &v)
{
	this->dat = v;
}

template <class T>
T DllSampTemp<T>::get ()
{
	return this->dat;
}

