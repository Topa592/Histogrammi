#include "RandomEintegerGenerator.h"

#include <random>

namespace Hist {
	EInteger RandomEintegerGenerator::operator()()
	{
		int random = std::rand();
		return EInteger(random % 5);
	}
}