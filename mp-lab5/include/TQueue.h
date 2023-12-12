#pragma once

using namespace std;
template<class size_t>
class TQueue
{
protected:
	size_t* data;
	int size;
	int start, end;
	int count;
public:
	TQueue(int _size = 10);          //����������� ������������� � �� ���������
	~TQueue() { delete[] data; size = 0; start = 0; end = 0; };       //����������
	TQueue(const TQueue<size_t>& p);      //����������� ����������� 
	bool IsEmpty() const noexcept;                  //�������� �� �������
	bool IsFull() const noexcept;                  //�������� �� �������
	int GetCoun();
	size_t Pull();                         //������� �������
	void Push(const size_t& a);           //�������� ������� � ����
	size_t Top(void) const;
	void Pop(void);
	size_t TopPop(void);
	void Free(void) noexcept;
};
template<class size_t>
inline TQueue<size_t>::TQueue(int _size)
{
	if (_size < 0) throw ("error");
	size = _size;
	start = 0;
	count = 0;
	end = 0;
	data = new size_t[size];
}
template<class size_t>
inline TQueue<size_t>::TQueue(const TQueue<size_t>& p)
{
	size = p.size;
	start = p.start;
	end = p.end;
	count = p.count;
	data = new size_t[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}
template<class size_t>
inline bool TQueue<size_t>::IsEmpty() const noexcept
{
	if (count == 0)
		return true;
	else return false;
}
template<class size_t>
inline bool TQueue<size_t>::IsFull() const noexcept
{
	if (count == size)
		return true;
	else return false;
}
template<class size_t>
inline int TQueue<size_t>::GetCoun()
{
	return (count);
}

template<class size_t>
inline void TQueue<size_t>::Push(const size_t& a)
{
	if (IsFull())
		throw "Err";
		data[end] = a;
		end++;
		end = (end < size) ? end : 0;
		count++;

}

template<typename size_t>
inline size_t TQueue<size_t>::Top(void) const
{
	if (IsEmpty())
		throw "Err";
	return data[start];
}

template<typename size_t>
inline void TQueue<size_t>::Pop(void)
{
	if (IsEmpty())
		throw "Err";
	start++;
	start = (start < size) ? start : 0;
	count--;
}

template<typename size_t>
inline size_t TQueue<size_t>::TopPop(void)
{
	size_t tmp = Top();
	Pop();
	return tmp;
}

template<typename T>
inline void TQueue<T>::Free(void) noexcept
{
	end = 0;
	start = 0;
	count = 0;
}