#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
namespace SEQUENCE
{

	enum SequenceType
	{
		SQUARE,
		FACTORIAL,
	};

	class Sequence;
	using SequencePtr = std::shared_ptr<Sequence>;

	class Sequence
	{
	public:
		virtual int calculate_n(int n) const = 0;
		virtual SequencePtr clone() const = 0;
		virtual bool equals(SequencePtr other) const = 0;
		virtual ~Sequence() = default;
		virtual void print(std::ostream& stream) const = 0;
	protected:
		Sequence() = default;
		Sequence(const Sequence&) = default;
		Sequence& operator=(const Sequence&) = default;
	};

	class SquareSequence : public Sequence {
		int c;
	public:
		SquareSequence(int c);
		int get_c() const;
		int calculate_n(int n) const override;
		SequencePtr clone() const override;
		bool equals(SequencePtr other) const override;
		void print(std::ostream& stream) const override;
	};

	class FactSequence : public Sequence {
	public:
		FactSequence();
		int calculate_n(int n) const override;
		SequencePtr clone() const override;
		bool equals(SequencePtr other) const override;
		void print(std::ostream& stream) const override;
	};

	class SequenceList
	{
		std::vector<SequencePtr> _sequences;
	public:
		SequenceList() = default;
		SequenceList(const SequenceList& list);
		int size() const;
		void swap(SequenceList& list) noexcept;
		SequenceList& operator=(const SequenceList& list);
		SequencePtr operator[](int index) const;
		void add(SequencePtr item);
		void insert(SequencePtr item, int index);
		void erase_index(int index);
	};

	int search(const SequenceList& list, const int n);
}