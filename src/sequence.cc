#include <sequence/sequence.h>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace SEQUENCE;
using namespace std;

SquareSequence::SquareSequence(int c) : c(c) {}

int SquareSequence::get_c() const {
	return c;
}

int SquareSequence::calculate_n(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	return n * n + c;
}

SequencePtr SquareSequence::clone() const {
	return make_shared<SquareSequence>(c);
}

bool SquareSequence::equals(SequencePtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<SquareSequence>(other);
	if (downcasted_other == nullptr) {
		return false;
	}

	return (c == downcasted_other->c);
}

void SquareSequence::print(ostream& out) const
{
	out << "(SQUARE, " << get_c() << ")" << endl;
}

FactSequence::FactSequence(){}

int FactSequence::calculate_n(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}

bool FactSequence::equals(SequencePtr other) const {
	return 1;
}

SequencePtr FactSequence::clone() const {
	return make_shared<FactSequence>();
}

void FactSequence::print(ostream& out) const
{
	out << "(FACTORIAL)" << endl;
}