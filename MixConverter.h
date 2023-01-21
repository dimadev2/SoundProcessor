#pragma once
#include "BaseConverter.h"

class MixConverter : BaseConverter {
	MixConverter(Interval interval) : BaseConverter(interval) {}

	virtual Chunk process(const Context& context);
};
