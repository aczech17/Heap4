#include <utility>
#include <vector>
#include <iostream>

template<typename KeyType, typename ValueType>
class Heap4
{
	std::vector<std::pair<KeyType, ValueType>> vec;
	size_t count;
  public:
    using KeyValueType = std::pair<const KeyType, ValueType>;

	Heap4()
	{
		count = 0;
	}

	bool empty() const noexcept
	{
		return count == 0;
	}

	void insert(KeyType const & key, ValueType const & value)
	{
		std::pair <KeyType, ValueType> p(key, value);
		insert(p);
	}

	void insert(KeyValueType const & key_value)
	{
		vec.push_back(key_value);
		count++;
		size_t i = count - 1;
		while (i > 0 && vec[i].first < vec[(i - 1) / 4].first)
		{
			swap(vec[i], vec[(i - 1) / 4]);
			i = (i - 1) / 4;
		}//while
	}

	KeyValueType const & peek() const noexcept
	{
		if (count == 0)
		{
			throw(std::logic_error("HEAP EMPTY")); // NO I KURDE W£AŒNIE NIE WIEM CZY TO JEST DOBRZE :/
			exit(EXIT_FAILURE);
		}
		return vec[0];
	}

	KeyValueType pop() noexcept
	{
		KeyValueType result = vec[0];
		std::swap(vec[0], vec[--count]);
		vec.pop_back();
		size_t i = 0;
		while (i < count)
		{
			size_t minnext = 4 * i + 1;
			if (minnext >= count)
				break;
			for (size_t j = 4 * i + 2; j <= 4 * i + 4 && j < count; j++)
			{
				if (vec[j].first < vec[minnext].first)
					minnext = j;
			}//for
			
			if(vec[minnext].first < vec[i].first)
				std::swap(vec[i], vec[minnext]);
			i = minnext;
		}//while
		return result;
	}

	size_t size() const noexcept
	{
		return count;
	}

	////// DO ZROBIENIA ////////
	template<typename StreamType>
	void print(StreamType& stream) const
	{
		;
	}
};
