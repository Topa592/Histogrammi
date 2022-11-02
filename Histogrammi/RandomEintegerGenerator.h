#ifndef RANDOMEINTEGERGENERATOR_H

#define RANDOMEINTEGERGENERATOR_H

#include "HistogramBase.h"

namespace Hist {
	class RandomEintegerGenerator : public RandomEintegerGeneratorBase {
	public:
		// Return random EInteger between zero and four
		EInteger operator()() override;
	};
}


#endif