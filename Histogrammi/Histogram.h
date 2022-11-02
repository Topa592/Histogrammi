#ifndef HISTOGRAM_H

#define HISTOGRAM_H

#include "HistogramBase.h"
#include <vector>

namespace Hist {
	class Histogram : public HistogramBase {
    public:
        std::vector<EInteger> eIntegers;

        Histogram() = delete;

        Histogram(std::unique_ptr<Logger>);

        Histogram(const Histogram&);

        Histogram(Histogram&&);

        virtual ~Histogram();

        void add(EInteger) override;

        // Return the value that occurrs most often in the data set (I.e. there exists no other value that occurs more often than the return value)
        EInteger getMode() const override;

        // Return the smallest value in the data set, according to default ordering relation of integer numbers
        EInteger getMinValue() const override;

        // Return the largest value in the data set
        EInteger getMaxValue() const override;
	};
}

#endif